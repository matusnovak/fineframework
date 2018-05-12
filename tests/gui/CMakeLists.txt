cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

# All examples
FILE(GLOB SOURCES *.cpp *.c)
add_executable(TestsGui ${SOURCES})

# Dependencies
target_link_libraries(TestsGui debug finegui${CMAKE_DEBUG_POSTFIX})
target_link_libraries(TestsGui  optimized finegui)

if(MSVC)
  set_target_properties(TestsGui PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif()

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(TestsGui -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)

add_test(NAME TestsGui COMMAND TestsGui)
set_property(TARGET TestsGui PROPERTY FOLDER "fineframework/tests") 
