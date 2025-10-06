cmake_minimum_required(VERSION 3.11)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib)

add_executable(parent parent_process.cpp)
target_link_libraries(parent PRIVATE os)

add_executable(child child_process.cpp)
target_link_libraries(child PRIVATE math)
