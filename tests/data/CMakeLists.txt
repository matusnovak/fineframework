cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)
link_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_BINARY_DIR}/libraries/include)
link_directories(${CMAKE_BINARY_DIR}/libraries/lib)

file(COPY sample.csv MOCK_DATA.json DESTINATION ${CMAKE_BINARY_DIR})
file(COPY sample.csv MOCK_DATA.json DESTINATION ${CMAKE_BINARY_DIR}/tests/data)

# All examples
add_executable(TestsDataCsv data_csv.cpp)
add_executable(TestsDataJson data_json.cpp)
add_executable(TestsDataXml data_xml.cpp)

set(DATA_TESTS TestsDataCsv TestsDataJson TestsDataXml)

# Dependencies
foreach(exmpl ${DATA_TESTS})
  target_link_libraries(${exmpl} optimized finedata )
  target_link_libraries(${exmpl} debug finedata${CMAKE_DEBUG_POSTFIX})

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
  
  add_test(NAME ${exmpl} COMMAND ${exmpl})
endforeach(exmpl)
