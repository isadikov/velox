include_directories(include)
include_directories(include/dsdgen-c)
add_subdirectory(dsdgen-c)

add_library(dsdgen STATIC dsdgen.cpp append_info-c.cpp dsdgen_helpers.cpp)
target_link_libraries(dsdgen dsdgen_c)