include_directories(include)
include_directories(dsdgen-c/include)
add_subdirectory(dsdgen-c)

add_library(dsdgen STATIC dsdgen.cpp append_info-c.cpp dsdgen_helpers.cpp)
target_link_libraries(dsdgen dsdgen_c)
