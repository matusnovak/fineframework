cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

file(COPY sample.csv MOCK_DATA.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY sample.csv MOCK_DATA.json DESTINATION ${CMAKE_BINARY_DIR}/tests/data)

# All examples
FILE(GLOB SOURCES *.cpp *.c)
add_executable(TestsData ${SOURCES})

# Dependencies
target_link_libraries(TestsData optimized finedata )
target_link_libraries(TestsData debug finedata${CMAKE_DEBUG_POSTFIX})

if(MSVC)
  set_target_properties(TestsData PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
endif(MSVC)

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(TestsData -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)

add_test(NAME TestsData COMMAND TestsData)
set_property(TARGET TestsData PROPERTY FOLDER "fineframework/tests") 
