cmake_minimum_required(VERSION 3.0.0)
cmake_policy(SET CMP0063 NEW)

project(TPCDSExtension)

include_directories(include)
include_directories(..)

add_library(tpcds_extension STATIC tpcds-extension.cpp include/tpcds-extension.hpp)
