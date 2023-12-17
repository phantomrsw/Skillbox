cmake_minimum_required(VERSION 3.23)

add_executable(cpp_mod31_pw3
        main.cpp
        MatrixGraph.cpp
        ListGraph.cpp
        ${PRJ_INCLUDE_DIR}/IGraph.h
        ${PRJ_INCLUDE_DIR}/MatrixGraph.h
        ${PRJ_INCLUDE_DIR}/ListGraph.h)

target_include_directories(cpp_mod31_pw3 PUBLIC ${PRJ_INCLUDE_DIR})