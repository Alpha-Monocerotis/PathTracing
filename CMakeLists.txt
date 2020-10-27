cmake_minimum_required (VERSION 2.8)

set(CXX_FLAGS
    -std=c++11
    -Wall 
    -Wno-unused-function
    )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D_GLIBCXX_USE_C99=1)

project (PathTracing)

aux_source_directory(. DIR_SOURCE)

add_executable(main ${DIR_SOURCE})