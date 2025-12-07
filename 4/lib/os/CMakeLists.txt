project(Os)

set(SOURCES library_loader.cpp)

add_library(os STATIC ${SOURCES})
target_include_directories(os PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
