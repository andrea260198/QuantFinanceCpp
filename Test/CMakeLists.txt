cmake_minimum_required(VERSION 3.8)

project(InterestRatesLib VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(googletest-1.14.0)


if(BUILD_TESTING)
    add_executable(InterestRatesTest interest_rates_test.cpp)

    target_include_directories(InterestRatesTest PUBLIC ../DataFrame/include)
    target_include_directories(InterestRatesTest PUBLIC ../InterestRates/include)

    target_link_libraries(InterestRatesTest PUBLIC
        InterestRatesLib
        DataFrameLib
        GTest::gtest_main
    )

    include(GoogleTest)

    gtest_discover_tests(InterestRatesTest)
endif()
