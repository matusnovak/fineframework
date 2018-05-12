cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

# All examples
FILE(GLOB SOURCES *.cpp *.c)
add_executable(TestsMath ${SOURCES})

if(MSVC)
  set_target_properties(TestsMath PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif(MSVC)

if(NOT MSVC AND NOT APPLE)
  target_link_libraries(TestsMath Threads::Threads)
endif()

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(TestsMath -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)

add_test(NAME TestsMath COMMAND TestsMath)
set_property(TARGET TestsMath PROPERTY FOLDER "fineframework/tests") 
