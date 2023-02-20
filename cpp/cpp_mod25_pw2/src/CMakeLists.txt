cmake_minimum_required(VERSION 3.23)

add_executable(cpp_mod25_pw2
                main.cpp
                ram.cpp
                cpu.cpp
                gpu.cpp
                kbd.cpp
                disk.cpp
                ${PRJ_INCLUDE_DIR}/ram.h
                ${PRJ_INCLUDE_DIR}/cpu.h
                ${PRJ_INCLUDE_DIR}/gpu.h
                ${PRJ_INCLUDE_DIR}/kbd.h
                ${PRJ_INCLUDE_DIR}/disk.h)

target_include_directories(cpp_mod25_pw2 PUBLIC ${PRJ_INCLUDE_DIR})
#add_executable(cpp_mod25_pw2 main.cpp ram.cpp)
