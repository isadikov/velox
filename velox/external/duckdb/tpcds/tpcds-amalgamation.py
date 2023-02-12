import os
import queue
import shutil
import subprocess
import sys

current_dir = os.path.dirname(os.path.realpath(__file__))

root = "extension/tpcds"
output_header = "tpcds-extension.hpp"
output_source = "tpcds-extension.cpp"

def is_header(file):
    return file.endswith(".h") or file.endswith(".hpp")

def is_source(file):
    return file.endswith(".c") or file.endswith(".cpp")

def find_files(root):
    output = []
    for root, dirs, files in os.walk(root):
        for file in files:
            if is_header(file) or is_source(file):
                output.append(os.path.join(root, file))
    return output

def dep_tree(file):
    # res = subprocess.check_output([
    #     "g++",
    #     "-MM",
    #     "-E",
    #     "-Iextension/tpcds/include",
    #     "-I/Users/ivansadikov/velox/velox/external/duckdb",
    #     "-Iextension/tpcds/dsdgen/include",
    #     "-Iextension/tpcds/dsdgen/include/dsdgen-c",
    #     file
    # ], stderr=subprocess.STDOUT)
    # res = [x.strip("\\ ") for x in res.decode("utf-8").strip().split("\n")]
    # # Skip invalid paths or duckdb imports - we will include those separately.
    # return [x for x in res if os.path.exists(x) and "duckdb" not in x]

    deps = []
    with open(file, "r") as f:
        for line in f:
            line = line.strip()
            if line.startswith("#include \"") and line.endswith("\"") and "duckdb" not in line:
                deps.append(line.split("#include")[-1].strip("\" "))
    return deps

def patch(nodes, edges):
    # We need to write the following files first, before we can proceed.
    required = [
        "init.h",
        "config.h",
        "porting.h",
        "constants.h",
        "columns.h",
        "tables.h",
        "mathops.h"
    ]

    for node in required:
        if node not in nodes:
            raise ValueError("Required file %s is not found" % node)

    for node in edges:
        if node not in required:
            edges[node].update(required)

    # Exclusions.
    exclusions = [
        "tpcds_constants.hpp", # will be added separately
        "tpcds_idx.hpp", # will be added separately
        "template.h", # not needed and references non-existing dependencies
    ]
    for exclusion in exclusions:
        del nodes[exclusion]
        del edges[exclusion]
        for node in edges:
            edges[node].discard(exclusion)

    # Patches.
    edges["s_tdefs.h"].add("tdefs.h")
    edges["w_tdefs.h"].add("tdefs.h")
    edges["w_web_returns.h"].add("pricing.h")
    edges["streams.h"].add("genrand.h")

def build_graph(root):
    # Map of {file name -> full path}.
    nodes = {}
    # Map of {file name -> [list of dependencies as file names]}.
    edges = {}

    for file in find_files(root):
        file_name = os.path.basename(file)
        if file_name in nodes:
            raise ValueError("Duplicate file name: %s, files: %s" % (file_name, [node[file_name], file]))
        nodes[file_name] = file
        edges[file_name] = set([])

    def add_edge(node, dep):
        if node != dep:
            edges[node].add(dep)

    # Resolve dependencies between the files.
    tmp_arr = list(nodes.items())
    # Exclusions in the case of failures.
    failed_nodes = []

    for node, node_path in tmp_arr:
        print("+", node)
        deps = []
        try:
            deps = dep_tree(node_path)
        except BaseException as err:
            print("ERROR: Could not resolve dependencies for the path", node_path, "due to the error: ", err)
            print("ERROR: The file", node, "will be removed from the resolution")
            failed_nodes.append(node)
        else:
            for dep_node in deps:
                if dep_node in nodes:
                    # Must be a file import that we have, link as the edge.
                    add_edge(node, dep_node)
                else:
                    # This branch means that the referenced file does not exist
                    # so we cannot resolve this dependency.
                    nodes[dep_node] = None
                    edges[dep_node] = set([]) # for the downstream code to work
                    add_edge(node, dep_node)
                    print("  [UNRESOLVED]", dep_node)

    # Remove failed nodes and their edges.
    for failed_node in failed_nodes:
        print("- removing", failed_node)
        if failed_node in nodes:
            del nodes[failed_node]
        for node in edges:
            edges[node].discard(failed_node)
        if failed_node in edges:
            del edges[failed_node]

    return nodes, edges

def sort(nodes, edges):
    current = queue.Queue()
    inverted_edges = {}
    inverted_counts = {}

    for node, deps in edges.items():
        # Update counts.
        inverted_counts[node] = len(deps)
        # Safety check: add an empty set to the roots.
        if node not in inverted_edges:
            inverted_edges[node] = set([])
        # Update the inversed dependencies.
        if len(deps) == 0:
            current.put(node) # Leaves are added to the queue right away.
        else:
            for dep in deps:
                if dep not in inverted_edges:
                    inverted_edges[dep] = set([])
                inverted_edges[dep].add(node)

    order = []
    while not current.empty():
        node = current.get()
        order.append(node)
        for edge in inverted_edges[node]:
            inverted_counts[edge] -= 1
            if inverted_counts[edge] == 0:
                current.put(edge)

    for key, value in inverted_counts.items():
        if value != 0:
            raise ValueError("A cycle is detected in the graph: %s" % key)

    return order

def write_cleaned_up_file(out, path):
    header_mode = 0
    with open(path, "r") as f:
        for line in f:
            if line.strip() == "/*" and header_mode == 0:
                header_mode = 1
            elif line.strip() == "*/" and header_mode == 1:
                header_mode = 2
            elif line.strip().startswith("#include") and "duckdb" in line:
                continue # Skip duckdb import, we will include duckdb.hpp
            elif line.strip().startswith("#include") and "<" not in line and ">" not in line:
                continue # Skip include files.
            elif "#pragma once" in line:
                continue # Skip this, we will add it for the file.
            elif "using namespace" in line:
                continue # Clean up namespaces, we will add them separately.
            elif header_mode == 1:
                continue # Skip the header.
            else:
                out.write(line)

def write_cleaned_up_hpp_file(out, node, path):
    out.write("// %s\n" % node)
    write_cleaned_up_file(out, path)

def write_cleaned_up_cpp_file(out, node, path):
    out.write("// %s\n" % node)

    namespace_required = {
        "w_call_center.cpp": "w_call_center",
        "w_item.cpp": "w_item",
        "w_web_site.cpp": "w_web_site",
        "w_store.cpp": "w_store",
        "w_web_sales.cpp": "w_web_sales",
        "w_catalog_sales.cpp": "w_catalog_sales",
    }

    # Add optional namespace to avoid variable redefinition conflicts.
    if node in namespace_required:
        out.write("namespace ")
        out.write(namespace_required[node])
        out.write(" {\n")
    write_cleaned_up_file(out, path)

    if node in namespace_required:
        out.write("}\n")

if __name__ == "__main__":
    # Path to duckdb git repository.
    duckdb_path = sys.argv[1]
    if not os.path.isdir(duckdb_path):
        raise ValueError("DuckDB repository %s is invaild" % duckdb_path)

    tpcds_root_path = os.path.join(duckdb_path, root)

    if not os.path.isdir(tpcds_root_path):
        raise ValueError("Cannot find TPC-DS extension directory in DuckDB repository")

    nodes, edges = build_graph(tpcds_root_path)
    # This is required as we don't know how to resolve dependencies in a few instances.
    patch(nodes, edges)
    order = sort(nodes, edges)

    current_include_dir = os.path.join(current_dir, "include")
    os.makedirs(current_include_dir, exist_ok=True)

    # Write the header file first.
    with open(os.path.join(current_include_dir, output_header), "w") as out:
        out.write("//===----------------------------------------------------------------------===//\n")
        out.write("//                         DuckDB                                               \n")
        out.write("//                                                                              \n")
        out.write("// TPC-DS amalgamation file                                                     \n")
        out.write("//                                                                              \n")
        out.write("//                                                                              \n")
        out.write("//===----------------------------------------------------------------------===//\n")
        out.write("\n")
        out.write("#pragma once\n")
        out.write("\n")
        # Import duckdb code.
        out.write("#include \"duckdb.hpp\"\n")
        out.write("\n")

        for node in order:
            if is_header(node):
                path = nodes[node]
                if path:
                    write_cleaned_up_hpp_file(out, node, path)
                    out.write("\n")
                else:
                    print("WARN: Ignored %s as it is unresolved" % node)

    # Write the cpp file.
    with open(os.path.join(current_dir, output_source), "w") as out:
        out.write("//===----------------------------------------------------------------------===//\n")
        out.write("//                         DuckDB                                               \n")
        out.write("//                                                                              \n")
        out.write("// TPC-DS amalgamation file                                                     \n")
        out.write("//                                                                              \n")
        out.write("//                                                                              \n")
        out.write("//===----------------------------------------------------------------------===//\n")
        out.write("\n")
        out.write("\n")
        # Import duckdb code.
        out.write("#include \"duckdb.hpp\"\n")
        out.write("#include \"duckdb-internal.hpp\"\n")
        out.write("#include \"%s\"\n" % output_header)
        out.write("#include \"tpcds_constants.hpp\"\n")
        out.write("#include \"tpcds_idx.hpp\"\n")
        out.write("\n")
        out.write("using namespace std;\n")
        out.write("using namespace tpcds;\n")
        out.write("\n")

        for node in order:
            if is_source(node):
                path = nodes[node]
                if path:
                    write_cleaned_up_cpp_file(out, node, path)
                    out.write("\n")
                else:
                    print("WARN: Ignored %s as it is unresolved" % node)

    # We need to add the remaining dependencies that are not inlined.
    shutil.copy2(os.path.join(tpcds_root_path, "dsdgen/include/tpcds_constants.hpp"), current_include_dir)
    shutil.copy2(os.path.join(tpcds_root_path, "dsdgen/include/tpcds_idx.hpp"), current_include_dir)
