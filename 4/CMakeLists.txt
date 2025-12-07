cmake_minimum_required(VERSION 3.11)
project(Lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)

add_executable(static_linking static_main.cpp)
target_link_libraries(static_linking PRIVATE static_math)

add_executable(dynamic_linking dynamic_main.cpp)
target_link_libraries(dynamic_linking PRIVATE os)
