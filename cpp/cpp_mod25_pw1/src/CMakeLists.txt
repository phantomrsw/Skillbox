cmake_minimum_required(VERSION 3.23)

add_executable(cpp_mod25_pw1
                main.cpp
                ${PRJ_INCLUDE_DIR}/main.h)

target_include_directories(cpp_mod25_pw1 PUBLIC ${PRJ_INCLUDE_DIR})