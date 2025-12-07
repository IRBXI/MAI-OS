project(Math)

set(SOURCES derivative1.cpp area_rectangle.cpp)

add_library(static_math STATIC ${SOURCES})
target_include_directories(static_math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(dynamic_math1 SHARED area_rectangle.cpp derivative1.cpp)
target_include_directories(dynamic_math1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_library(dynamic_math2 SHARED area_triangle.cpp derivative2.cpp)
target_include_directories(dynamic_math2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
