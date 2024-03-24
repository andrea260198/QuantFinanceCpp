cmake_minimum_required(VERSION 3.1.0)

project(QuantFinanceGui VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(tasks)

qt_add_executable(GuiApp
    main.cpp
	Gui.h
    Gui.cpp
)

target_link_libraries(GuiApp PRIVATE 
	Qt6::Widgets
)
