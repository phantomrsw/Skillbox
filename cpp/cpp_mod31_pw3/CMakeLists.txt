#[[cmake_minimum_required(VERSION 3.23)
project(cpp_mod31_pw3)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_mod31_pw3 main.cpp inc/IGraph.h inc/MatrixGraph.h src/MatrixGraph.cpp)]]


cmake_minimum_required(VERSION 3.23)
project(cpp_mod31_pw3
        VERSION 0.1
        DESCRIPTION "Program number 3 from module 31"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)
add_subdirectory(src)