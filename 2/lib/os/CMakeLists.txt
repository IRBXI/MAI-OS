project(Os)

set(SOURCES thread.cpp mutex.cpp lock_guard.cpp)
set(HEADERS thread.hpp mutex.hpp lock_guard.hpp)
add_library(os ${SOURCES} ${HEADERS})
target_include_directories(os PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
