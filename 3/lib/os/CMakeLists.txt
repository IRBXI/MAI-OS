project(Os)

set(SOURCES process.cpp memory_map.hpp shared_memory_resource.cpp)
add_library(os ${SOURCES})
target_include_directories(os PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
