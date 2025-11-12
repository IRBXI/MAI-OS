project(Math)

set(SOURCES prime.cpp)
add_library(math ${SOURCES})
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
