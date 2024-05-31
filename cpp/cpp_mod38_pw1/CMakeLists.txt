cmake_minimum_required(VERSION 3.23)
project(cpp_mod38_pw1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        MultimediaWidgets
        REQUIRED)

add_executable(cpp_mod38_pw1 main.cpp MagicButton.cpp MagicButton.h)
target_link_libraries(cpp_mod38_pw1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets
        )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/btn_up.png ${CMAKE_CURRENT_BINARY_DIR}/btn_up.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/btn_down.png ${CMAKE_CURRENT_BINARY_DIR}/btn_down.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/sound.mp3 ${CMAKE_CURRENT_BINARY_DIR}/sound.mp3 COPYONLY)
