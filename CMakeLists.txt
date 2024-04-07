cmake_minimum_required(VERSION 3.8)

project(QuantFinanceCpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(CTest)

# Include sub-projects.
add_subdirectory(InterestRates)
add_subdirectory(DataFrame)
#add_subdirectory(Gui)
add_subdirectory(Test)
add_subdirectory(External/googletest)
