cmake_minimum_required(VERSION 3.23)
project(cpp_mod32_pw1)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(cpp_mod32_pw1 main.cpp)

target_link_libraries(cpp_mod32_pw1 PRIVATE nlohmann_json::nlohmann_json)
