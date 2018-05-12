cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

file(COPY imgs cube.mtl cube.obj cylinder.mtl cylinder.obj plane.mtl plane.obj planes.mtl planes.obj DESTINATION ${CMAKE_BINARY_DIR})
file(COPY imgs cube.mtl cube.obj cylinder.mtl cylinder.obj plane.mtl plane.obj planes.mtl planes.obj DESTINATION ${CMAKE_BINARY_DIR}/tests/media)

# All examples
FILE(GLOB SOURCES *.cpp *.c)
add_executable(TestsMedia ${SOURCES})

# Dependencies
target_link_libraries(TestsMedia optimized finemedia )
target_link_libraries(TestsMedia debug finemedia${CMAKE_DEBUG_POSTFIX})

if(MSVC)
  set_target_properties(TestsMedia PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif(MSVC)

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(TestsMedia -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)

add_test(NAME TestsMedia COMMAND TestsMedia)
set_property(TARGET TestsMedia PROPERTY FOLDER "fineframework/tests") 
