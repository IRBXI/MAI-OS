project(Os)

set(SOURCES process.cpp pipe.cpp)
set(HEADERS process.hpp pipe.hpp)
add_library(os ${SOURCES} ${HEADERS})
target_include_directories(os PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
