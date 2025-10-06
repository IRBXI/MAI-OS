project(Math)

set(SOURCES prime.cpp)
set(HEADERS prime.hpp)
add_library(math ${SOURCES} ${HEADERS})
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
