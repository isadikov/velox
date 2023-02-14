import os
import queue
import shutil
import subprocess
import sys

DSDGEN_COMBINED_HPP = "dsdgen_combined.hpp"
DSDGEN_COMBINED_CPP = "dsdgen_combined.cpp"

# List of files that are required for TPC-DS data generation.
# This is orthogonal to DuckDB code.
DSDGEN_C_FILES = [
    # Header files.
    "dsdgen/include/dsdgen-c/mathops.h",
    "dsdgen/include/dsdgen-c/constants.h",
    "dsdgen/include/dsdgen-c/tables.h",
    "dsdgen/include/dsdgen-c/columns.h",
    "dsdgen/include/dsdgen-c/init.h",
    "dsdgen/include/dsdgen-c/config.h",
    "dsdgen/include/dsdgen-c/porting.h",
    "dsdgen/include/dsdgen-c/w_catalog_page.h",
    "dsdgen/include/dsdgen-c/w_web_page.h",
    "dsdgen/include/dsdgen-c/w_household_demographics.h",
    "dsdgen/include/dsdgen-c/StringBuffer.h",
    "dsdgen/include/dsdgen-c/parallel.h",
    "dsdgen/include/dsdgen-c/scaling.h",
    "dsdgen/include/dsdgen-c/misc.h",
    "dsdgen/include/dsdgen-c/grammar_support.h",
    "dsdgen/include/dsdgen-c/w_reason.h",
    "dsdgen/include/dsdgen-c/load.h",
    "dsdgen/include/dsdgen-c/dbgen_version.h",
    "dsdgen/include/dsdgen-c/release.h",
    "dsdgen/include/dsdgen-c/r_params.h",
    "dsdgen/include/dsdgen-c/dist.h",
    "dsdgen/include/dsdgen-c/address.h",
    "dsdgen/include/dsdgen-c/tdef_functions.h",
    "dsdgen/include/dsdgen-c/tpcds.idx.h",
    "dsdgen/include/dsdgen-c/skip_days.h",
    "dsdgen/include/dsdgen-c/error_msg.h",
    "dsdgen/include/dsdgen-c/w_customer.h",
    "dsdgen/include/dsdgen-c/w_datetbl.h",
    "dsdgen/include/dsdgen-c/grammar.h",
    "dsdgen/include/dsdgen-c/w_income_band.h",
    "dsdgen/include/dsdgen-c/decimal.h",
    "dsdgen/include/dsdgen-c/date.h",
    "dsdgen/include/dsdgen-c/sparse.h",
    "dsdgen/include/dsdgen-c/nulls.h",
    "dsdgen/include/dsdgen-c/permute.h",
    "dsdgen/include/dsdgen-c/w_customer_demographics.h",
    "dsdgen/include/dsdgen-c/w_timetbl.h",
    "dsdgen/include/dsdgen-c/w_ship_mode.h",
    "dsdgen/include/dsdgen-c/w_inventory.h",
    "dsdgen/include/dsdgen-c/w_warehouse.h",
    "dsdgen/include/dsdgen-c/w_customer_address.h",
    "dsdgen/include/dsdgen-c/tdefs.h",
    "dsdgen/include/dsdgen-c/dcomp.h",
    "dsdgen/include/dsdgen-c/w_web_site.h",
    "dsdgen/include/dsdgen-c/w_item.h",
    "dsdgen/include/dsdgen-c/w_promotion.h",
    "dsdgen/include/dsdgen-c/scd.h",
    "dsdgen/include/dsdgen-c/pricing.h",
    "dsdgen/include/dsdgen-c/append_info.h",
    "dsdgen/include/dsdgen-c/w_store.h",
    "dsdgen/include/dsdgen-c/genrand.h",
    "dsdgen/include/dsdgen-c/w_tdefs.h",
    "dsdgen/include/dsdgen-c/s_tdefs.h",
    "dsdgen/include/dsdgen-c/w_call_center.h",
    "dsdgen/include/dsdgen-c/w_catalog_sales.h",
    "dsdgen/include/dsdgen-c/w_store_sales.h",
    "dsdgen/include/dsdgen-c/w_web_returns.h",
    "dsdgen/include/dsdgen-c/build_support.h",
    "dsdgen/include/dsdgen-c/w_web_sales.h",
    "dsdgen/include/dsdgen-c/w_store_returns.h",
    "dsdgen/include/dsdgen-c/w_catalog_returns.h",
    "dsdgen/include/dsdgen-c/streams.h",
    "dsdgen/include/dsdgen-c/params.h",

    # C/C++ files.
    "dsdgen/dsdgen-c/init.cpp",
    "dsdgen/dsdgen-c/load.cpp",
    "dsdgen/dsdgen-c/StringBuffer.cpp",
    "dsdgen/dsdgen-c/release.cpp",
    "dsdgen/dsdgen-c/error_msg.cpp",
    "dsdgen/dsdgen-c/decimal.cpp",
    "dsdgen/dsdgen-c/skip_days.cpp",
    "dsdgen/dsdgen-c/date.cpp",
    "dsdgen/dsdgen-c/r_params.cpp",
    "dsdgen/dsdgen-c/nulls.cpp",
    "dsdgen/dsdgen-c/misc.cpp",
    "dsdgen/dsdgen-c/address.cpp",
    "dsdgen/dsdgen-c/permute.cpp",
    "dsdgen/dsdgen-c/text.cpp",
    "dsdgen/dsdgen-c/parallel.cpp",
    "dsdgen/dsdgen-c/sparse.cpp",
    "dsdgen/dsdgen-c/scaling.cpp",
    "dsdgen/dsdgen-c/dist.cpp",
    "dsdgen/dsdgen-c/tdefs.cpp",
    "dsdgen/dsdgen-c/w_warehouse.cpp",
    "dsdgen/dsdgen-c/build_support.cpp",
    "dsdgen/dsdgen-c/w_customer.cpp",
    "dsdgen/dsdgen-c/w_web_site.cpp",
    "dsdgen/dsdgen-c/w_reason.cpp",
    "dsdgen/dsdgen-c/w_timetbl.cpp",
    "dsdgen/dsdgen-c/w_inventory.cpp",
    "dsdgen/dsdgen-c/w_household_demographics.cpp",
    "dsdgen/dsdgen-c/w_promotion.cpp",
    "dsdgen/dsdgen-c/w_customer_demographics.cpp",
    "dsdgen/dsdgen-c/w_customer_address.cpp",
    "dsdgen/dsdgen-c/w_income_band.cpp",
    "dsdgen/dsdgen-c/w_store.cpp",
    "dsdgen/dsdgen-c/w_datetbl.cpp",
    "dsdgen/dsdgen-c/w_web_page.cpp",
    "dsdgen/dsdgen-c/dbgen_version.cpp",
    "dsdgen/dsdgen-c/w_catalog_page.cpp",
    "dsdgen/dsdgen-c/w_ship_mode.cpp",
    "dsdgen/dsdgen-c/w_call_center.cpp",
    "dsdgen/dsdgen-c/w_item.cpp",
    "dsdgen/dsdgen-c/w_web_sales.cpp",
    "dsdgen/dsdgen-c/pricing.cpp",
    "dsdgen/dsdgen-c/w_web_returns.cpp",
    "dsdgen/dsdgen-c/join.cpp",
    "dsdgen/dsdgen-c/w_store_sales.cpp",
    "dsdgen/dsdgen-c/w_store_returns.cpp",
    "dsdgen/dsdgen-c/tdef_functions.cpp",
    "dsdgen/dsdgen-c/w_catalog_returns.cpp",
    "dsdgen/dsdgen-c/scd.cpp",
    "dsdgen/dsdgen-c/genrand.cpp",
    "dsdgen/dsdgen-c/w_catalog_sales.cpp",
]

DSDGEN_C_EXPLICIT_DEPS = {
    "dbgen_version.h": ["porting.h"],
    "nulls.h": ["porting.h"],
    "parallel.h": ["porting.h"],
    "permute.h": ["porting.h"],
    "scaling.h": ["porting.h"],
    "sparse.h": ["porting.h"],
    "streams.h": ["genrand.h"],
    "tdef_functions.h": ["porting.h"],
    "s_tdefs.h": ["tdefs.h"],
    "w_tdefs.h": ["tdefs.h"],
    "w_web_returns.h": ["porting.h", "pricing.h"],
}

# These files are required for TPC-DS to run with DuckDB.
DUCK_DB_DSDGEN_FILES = [
    "dsdgen/append_info-c.cpp",
    "dsdgen/dsdgen.cpp",
    "dsdgen/dsdgen_helpers.cpp",
    "dsdgen/include/append_info-c.hpp",
    "dsdgen/include/dsdgen.hpp",
    "dsdgen/include/dsdgen_helpers.hpp",
    "dsdgen/include/dsdgen_schema.hpp",
    "dsdgen/include/tpcds_constants.hpp",
    "dsdgen/include/tpcds_idx.hpp",
    "include/tpcds-extension.hpp",
    "tpcds-extension.cpp",
]

def is_header(file):
    return file.endswith(".h") or file.endswith(".hpp")

def is_source(file):
    return file.endswith(".c") or file.endswith(".cpp")

def is_dsdgen_import(line):
    include = line.strip().split(" ")[-1].strip("\"")
    return include in [os.path.basename(path) for path in DSDGEN_C_FILES]

def get_namespace(file):
    file_name = os.path.basename(file)
    file_namespace = os.path.splitext(file_name)[0]
    return "__" + file_namespace.replace(".", "_") + "__"

def include_to_using(line):
    include = line.strip().split(" ")[-1].strip("\"")
    return "using namespace %s;" % get_namespace(include)

def find_files(root):
    output = []
    for root, dirs, files in os.walk(root):
        for file in files:
            if is_header(file) or is_source(file):
                output.append(os.path.join(root, file))
    return output

# Updates the file to only include duckdb.hpp.
# All other duckdb imports will be removed.
def rewrite_file_with_duckdb_include(path):
    lines = []
    with open(path, "r") as f:
        for line in f:
            lines.append(line)

    # Replace imports.
    out = []
    add_duckdb_internal_import = True
    add_duckdb_import = True
    add_dsdgen_import = True

    for i in range(len(lines)):
        if "#include" in lines[i] and "duckdb" in lines[i]:
            if "duckdb/parser" in lines[i]:
                if add_duckdb_internal_import:
                    # Replace the import with our own.
                    out.append("#include \"duckdb-internal.hpp\"\n")
                    add_duckdb_internal_import = False
                else:
                    continue # Ignore the import.
            else:
                if add_duckdb_import:
                    # Replace the import with our own.
                    out.append("#include \"duckdb.hpp\"\n")
                    add_duckdb_import = False
                else:
                    continue # Ignore the import.
        elif "#include" in lines[i] and is_dsdgen_import(lines[i]):
            if add_dsdgen_import:
                # Replace the import with our own.
                out.append("#include \"%s\"\n" % DSDGEN_COMBINED_HPP)
                add_dsdgen_import = False
        else:
            out.append(lines[i])

    # Update the file.
    with open(path, "w") as f:
        for line in out:
            f.write(line)

def write_cpp_file(path, out):
    file_name = os.path.basename(path)
    file_namespace = get_namespace(path)

    with open(path, "r") as f:
        out.write("namespace %s {\n" % file_namespace)
        out.write("\n")

        # Unfortunately, some files need manual patching due to undeclared
        # dependencies.
        if file_name in DSDGEN_C_EXPLICIT_DEPS:
            for dep in DSDGEN_C_EXPLICIT_DEPS[file_name]:
                out.write(include_to_using(dep))
                out.write("\n")

        # If we are rewriting a C++ file, link its own header file.
        if is_source(file_name):
            out.write(include_to_using(file_name))
            out.write("\n")

        for line in f:
            if "#include" in line and is_dsdgen_import(line):
                out.write(include_to_using(line))
                out.write("\n")
            else:
                out.write(line)
        out.write("\n")
        out.write("} // %s\n" % file_namespace)

def merge_dsdgen_files(files, out_header_path, out_source_path):
    # Write the header.
    with open(out_header_path, "w") as f:
        for path in files:
            if is_header(path):
                f.write("\n")
                f.write("// %s\n" % os.path.basename(path))
                f.write("\n")
                write_cpp_file(path, f)
                f.write("\n")
    # Write the source.
    with open(out_source_path, "w") as f:
        f.write("#include \"%s\"" % DSDGEN_COMBINED_HPP)
        f.write("\n")
        for path in files:
            if is_source(path):
                f.write("\n")
                f.write("// %s\n" % os.path.basename(path))
                f.write("\n")
                write_cpp_file(path, f)
                f.write("\n")


if __name__ == "__main__":
    # Path to duckdb git repository.
    duckdb_path = sys.argv[1]
    if not os.path.isdir(duckdb_path):
        raise ValueError("DuckDB repository %s is invaild" % duckdb_path)

    current_dir = os.path.dirname(os.path.realpath(__file__))

    tpcds_root_path = os.path.join(duckdb_path, "extension/tpcds")

    if not os.path.isdir(tpcds_root_path):
        raise ValueError("Cannot find TPC-DS extension directory in DuckDB repository")

    # 1. Copy DuckDB-related files as they are:
    # for path in DUCK_DB_DSDGEN_FILES:
    #     full_path = os.path.join(current_dir, path)
    #     base_dir = os.path.dirname(full_path)
    #     if base_dir:
    #         os.makedirs(base_dir, exist_ok=True)
    #     shutil.copy2(os.path.join(tpcds_root_path, path), base_dir)
    #     rewrite_file_with_duckdb_include(full_path)

    # 2. Create the folders for the dsdgen combined files.
    out_header_path = os.path.join(current_dir, "dsdgen/dsdgen-c/include", DSDGEN_COMBINED_HPP)
    out_source_path = os.path.join(current_dir, "dsdgen/dsdgen-c", DSDGEN_COMBINED_CPP)

    os.makedirs(os.path.dirname(out_header_path), exist_ok=True)
    os.makedirs(os.path.dirname(out_source_path), exist_ok=True)

    # 3. Combine dsdgen-c files into a single source.
    merge_dsdgen_files(
        [os.path.join(tpcds_root_path, path) for path in DSDGEN_C_FILES],
        out_header_path,
        out_source_path
    )
