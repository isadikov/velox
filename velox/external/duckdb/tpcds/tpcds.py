import os
import json
import shutil
import subprocess
import sys
import uuid
from datetime import datetime

DUCKDB_REPO = "https://github.com/duckdb/duckdb.git"
DUCKDB_COMMIT = "82810801b42516b43ff01f270c4f19f7e0d6f462"
STATUS_INFO = "status_info.txt"

def exec_cmd(cmd, cwd=None):
    return subprocess.check_output(cmd, cwd=cwd, stderr=subprocess.STDOUT)

# Creates a repository and checks out the commit.
def git_checkout(repo, path):
    exec_cmd(["git", "init"], cwd=path)
    exec_cmd(["git", "remote", "add", "origin", DUCKDB_REPO], cwd=path)
    exec_cmd(["git", "fetch", "--depth=1", DUCKDB_REPO, DUCKDB_COMMIT], cwd=path)
    exec_cmd(["git", "checkout", DUCKDB_COMMIT], cwd=path)

def list_files(root):
    output = []
    for root, dirs, files in os.walk(root):
        for file in files:
            output.append(os.path.join(root, file))
    return output

# Returns True if the file should always be copied and overwritten.
def should_always_reload(path):
    # We always reload dsdgen-c.
    if "dsdgen/dsdgen-c" in path:
        return True
    if "dsdgen/include/dsdgen-c" in path:
        return True
    if "dsdgen/include/tpcds_constants.hpp" in path:
        # This is a massive file, we don't check it in.
        return True
    if "dsdgen/include/tpcds_idx.hpp" in path:
        # This is a massive file, we don't check it in.
        return True
    return False

# Copies individual file preserving the directory structure.
def cp_file(file, from_dir, to_dir):
    if not os.path.isfile(file):
        raise ValueError("%s must be a file" % file)
    if not os.path.isdir(to_dir):
        raise ValueError("%s must be a directory" % to_dir)
    to_file = os.path.join(to_dir, file.split(from_dir)[-1].strip("/"))
    to_file_dir = os.path.dirname(to_file)

    if to_file_dir:
        os.makedirs(to_file_dir, exist_ok=True)

    add_duckdb_import = True
    add_duckdb_internal_import = True

    with open(file, "r") as f_in:
        with open(to_file, "w") as f_out:
            for line in f_in:
                if line.startswith("#include") and "duckdb/parser" in line:
                    if add_duckdb_internal_import:
                        f_out.write("#include \"duckdb-internal.hpp\"\n")
                        add_duckdb_internal_import = False
                    else:
                        continue # Skip as we will have written the import.
                elif line.startswith("#include") and "duckdb" in line:
                    if add_duckdb_import:
                        f_out.write("#include \"duckdb.hpp\"\n")
                        add_duckdb_import = False
                    else:
                        continue # Skip as we will have written the import.
                else:
                    f_out.write(line)

# Copies relevant files.
def cp_files(from_dir, to_dir, reload_fully):
    for path in list_files(from_dir):
        if "dsdgen/answers/" in path:
            continue # Not needed.
        elif "dsdgen/queries/" in path:
            continue # Not needed.
        elif "dsdgen/schema/" in path:
            continue # Not needed.
        elif "CMakeLists.txt" in path:
            continue # We will generate our own CMakeLists.txt files.
        elif "tpcds_config.py" in path:
            continue # Not needed.
        elif os.path.basename(path) == "tpcds.idx":
            continue # Not needed.
        elif not reload_fully and not should_always_reload(path):
            continue # Skip, we don't need to reload it.
        else:
            cp_file(path, from_dir, to_dir)

def write_file(path, content):
    with open(path, "w") as f:
        f.write(content)

def new_tmp_path():
    tmp_dir = None
    try:
        import tempfile
        tmp_dir = tempfile.mkdtemp()
    except:
        tmp_dir = os.path.join("/tmp", "tpcds_tmp_files__%s" % uuid.uuid4())
        os.makedirs(tmp_dir, exist_ok=False)
    return tmp_dir

def dsdgen_c_cmake():
    return (
        "add_library(\n"
        "  dsdgen_c STATIC\n"
        "  skip_days.cpp\n"
        "  address.cpp\n"
        "  build_support.cpp\n"
        "  date.cpp\n"
        "  dbgen_version.cpp\n"
        "  decimal.cpp\n"
        "  dist.cpp\n"
        "  error_msg.cpp\n"
        "  genrand.cpp\n"
        "  init.cpp\n"
        "  join.cpp\n"
        "  list.cpp\n"
        "  load.cpp\n"
        "  misc.cpp\n"
        "  nulls.cpp\n"
        "  parallel.cpp\n"
        "  permute.cpp\n"
        "  pricing.cpp\n"
        "  r_params.cpp\n"
        "  release.cpp\n"
        "  scaling.cpp\n"
        "  scd.cpp\n"
        "  sparse.cpp\n"
        "  StringBuffer.cpp\n"
        "  tdef_functions.cpp\n"
        "  tdefs.cpp\n"
        "  text.cpp\n"
        "  w_call_center.cpp\n"
        "  w_catalog_page.cpp\n"
        "  w_catalog_returns.cpp\n"
        "  w_catalog_sales.cpp\n"
        "  w_customer.cpp\n"
        "  w_customer_address.cpp\n"
        "  w_customer_demographics.cpp\n"
        "  w_datetbl.cpp\n"
        "  w_household_demographics.cpp\n"
        "  w_income_band.cpp\n"
        "  w_inventory.cpp\n"
        "  w_item.cpp\n"
        "  w_promotion.cpp\n"
        "  w_reason.cpp\n"
        "  w_ship_mode.cpp\n"
        "  w_store.cpp\n"
        "  w_store_returns.cpp\n"
        "  w_store_sales.cpp\n"
        "  w_timetbl.cpp\n"
        "  w_warehouse.cpp\n"
        "  w_web_page.cpp\n"
        "  w_web_returns.cpp\n"
        "  w_web_sales.cpp\n"
        "  w_web_site.cpp)\n"
    )

def dsdgen_cmake():
    return (
        "include_directories(include)\n"
        "include_directories(include/dsdgen-c)\n"
        "add_subdirectory(dsdgen-c)\n"
        "\n"
        "add_library(dsdgen STATIC dsdgen.cpp append_info-c.cpp dsdgen_helpers.cpp)\n"
        "target_link_libraries(dsdgen dsdgen_c)\n"
    )

def root_cmake():
    return (
        "cmake_minimum_required(VERSION 3.0.0)\n"
        "cmake_policy(SET CMP0063 NEW)\n"
        "\n"
        "project(TPCDSExtension)\n"
        "\n"
        "include_directories(include)\n"
        "include_directories(dsdgen/include)\n"
        "include_directories(..)\n"
        "add_subdirectory(dsdgen)\n"
        "\n"
        "add_library(tpcds_extension STATIC tpcds-extension.cpp)\n"
        "target_link_libraries(tpcds_extension dsdgen)\n"
    )

# Creates status info with the commit.
def write_status_info(path, commit):
    status = {
        "commit": commit,
        "date": str(datetime.utcnow()),
    }

    with open(os.path.join(path, STATUS_INFO), "w") as f:
        f.write(json.dumps(status))
        f.write("\n")

# Returns the commit currently stored in the status file.
def get_status_info(path):
    path = os.path.join(path, STATUS_INFO)
    if os.path.isfile(path):
        try:
            with open(path, "r") as f:
                return json.load(f)
        except:
            return None

def main():
    # Path to duckdb git repository.
    working_dir = sys.argv[1]
    reload_fully = bool(sys.argv[2]) if len(sys.argv) > 2 else False
    print("-- Configuring TPC-DS dataset in: %s (full reload %s)" % (working_dir, reload_fully))

    status = get_status_info(working_dir)
    if status and status.get("commit") == DUCKDB_COMMIT:
        print(
            "   Nothing to do, '%s' file is up to date. "
            "If you would like to reload TPC-DS dsdgen, "
            "change the content of the file or remove it" % STATUS_INFO)
        return

    tmp_dir = new_tmp_path()

    try:
        git_checkout(DUCKDB_REPO, tmp_dir)

        # Copy files.
        from_path = os.path.join(tmp_dir, "extension", "tpcds")
        to_path = os.path.join(working_dir)
        cp_files(from_path, to_path, reload_fully)

        # Generate CMakeLists.txt files.
        write_file(
            os.path.join(to_path, "dsdgen", "dsdgen-c", "CMakeLists.txt"),
            dsdgen_c_cmake()
        )

        if reload_fully:
            write_file(
                os.path.join(to_path, "dsdgen", "CMakeLists.txt"),
                dsdgen_cmake()
            )
            write_file(
                os.path.join(to_path, "CMakeLists.txt"),
                root_cmake()
            )

        write_status_info(working_dir, DUCKDB_COMMIT)
    finally:
        if tmp_dir and os.path.isdir(tmp_dir):
            shutil.rmtree(tmp_dir)

if __name__ == "__main__":
    main()
