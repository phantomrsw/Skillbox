cmake_minimum_required(VERSION 3.23)
project(cpp_mod34_pw1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.12\\5.12.12\\mingw73_64\\lib\\cmake")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(cpp_mod34_pw1 main.cpp)

target_link_libraries(cpp_mod34_pw1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)

