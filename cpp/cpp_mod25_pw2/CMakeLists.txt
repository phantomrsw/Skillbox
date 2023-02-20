cmake_minimum_required(VERSION 3.23)
project(cpp_mod25_pw2
        VERSION 0.1
        DESCRIPTION "Program number 2 from module 25 of the Skillbox course"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

set(PRJ_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)

#add_executable(cpp_mod25_pw2 main.cpp src/ram.cpp inc/ram.h)
#target_include_directories(cpp_mod25_pw2 PUBLIC inc)
add_subdirectory(src)
#add_subdirectory(inc)

