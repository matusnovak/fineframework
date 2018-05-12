cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

# All examples
FILE(GLOB SOURCES *.cpp *.c)
add_executable(TestsGraphics ${SOURCES})

# Dependencies
target_link_libraries(TestsGraphics debug finegraphics${CMAKE_DEBUG_POSTFIX})
target_link_libraries(TestsGraphics optimized finegraphics)

if(MSVC)
  set_target_properties(TestsGraphics PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif()

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(TestsGraphics -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)

add_test(NAME TestsGraphics COMMAND TestsGraphics)
set_property(TARGET TestsGraphics PROPERTY FOLDER "fineframework/tests")
