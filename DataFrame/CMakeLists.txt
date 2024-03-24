cmake_minimum_required(VERSION 3.8)

project(DataFrameLib VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DataFrameLib
    DataFrame.cpp
    include/DataFrame.h
)

add_executable(DataFrameMain
    main.cpp
)

target_link_libraries(DataFrameMain DataFrameLib)

