cmake_minimum_required (VERSION 2.8)

set(CXX_FLAGS
    -std=c++11
    -Wall 
    -Wno-unused-function
    )

project (PathTracing)

aux_source_directory(. DIR_SOURCE)

add_executable(main ${DIR_SOURCE})