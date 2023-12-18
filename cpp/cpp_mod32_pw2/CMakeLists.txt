cmake_minimum_required(VERSION 3.23)
project(cpp_mod32_pw2)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(cpp_mod32_pw2 main.cpp)

target_link_libraries(cpp_mod32_pw2 PRIVATE nlohmann_json::nlohmann_json)
