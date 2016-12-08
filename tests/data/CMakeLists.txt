cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

file(COPY sample.csv DESTINATION ${CMAKE_BINARY_DIR})
file(COPY sample.csv DESTINATION ${CMAKE_BINARY_DIR}/tests/data)

# All examples
add_executable(TestsData data.cpp)

set(DATA_TESTS TestsData)

# Dependencies
foreach(exmpl ${DATA_TESTS})
  target_link_libraries(${exmpl} optimized finedata)
  target_link_libraries(${exmpl} debug finedata${CMAKE_DEBUG_POSTFIX})

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)
endforeach(exmpl)