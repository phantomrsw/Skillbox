cmake_minimum_required(VERSION 3.23)
project(cpp_mod25_pw1
        VERSION 0.0.1
        DESCRIPTION "Program number 1 from module 25 of the Skillbox course"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

#add_executable(cpp_mod25_pw1 main.cpp)

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)