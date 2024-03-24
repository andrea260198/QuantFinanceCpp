cmake_minimum_required(VERSION 3.8)

project(InterestRatesLib VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(InterestRatesMain main.cpp)

target_include_directories(InterestRatesMain PUBLIC ../DataFrame/include)

add_library(InterestRatesLib
    Bond.cpp
    include/Bond.h
    include/ShortRateModels.h
)

target_link_libraries(InterestRatesMain PUBLIC
    InterestRatesLib
    DataFrameLib
)

