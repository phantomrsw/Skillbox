cmake_minimum_required(VERSION 3.23)

project(cpp_mod38_pw2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        WebEngineCore
        WebEngineWidgets
        REQUIRED)

add_executable(cpp_mod38_pw2 main.cpp)
target_link_libraries(cpp_mod38_pw2
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::WebEngineCore
        Qt5::WebEngineWidgets
        )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/example.html
        ${CMAKE_CURRENT_BINARY_DIR}/Debug/example.html COPYONLY)