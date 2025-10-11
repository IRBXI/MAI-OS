project(Math)

set(SOURCES point.cpp approximate_circle_area.cpp)
set(HEADERS point.hpp approximate_circle_area.hpp)
add_library(math ${SOURCES} ${HEADERS})

target_link_libraries(math PRIVATE os)

target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../os)
