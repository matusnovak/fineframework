cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

file(COPY file.csv DESTINATION ${CMAKE_BINARY_DIR})
file(COPY file.csv DESTINATION ${CMAKE_BINARY_DIR}/examples/data)

# All examples
add_executable(ExampleCsvSimple csv_simple.cpp)
add_executable(ExampleCsvAdvanced csv_advanced.cpp)
add_executable(ExampleJsonSimple json_simple.cpp)
add_executable(ExampleJsonAdvanced json_advanced.cpp)
add_executable(ExampleXmlSimple xml_simple.cpp)
add_executable(ExampleXmlAdvanced xml_advanced.cpp)

set(DATA_EXAMPLES ExampleCsvSimple ExampleCsvAdvanced ExampleJsonSimple ExampleJsonAdvanced ExampleXmlSimple ExampleXmlAdvanced)

# Dependencies
foreach(exmpl ${DATA_EXAMPLES})
  if(APPLE)
    target_link_libraries(${exmpl} debug finedata${CMAKE_DEBUG_POSTFIX})
    target_link_libraries(${exmpl} optimized finedata )
  elseif(UNIX)
    target_link_libraries(${exmpl} debug finedata${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finedata )
  else()
    target_link_libraries(${exmpl} debug finedata${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finedata )
	if(MSVC)
	  set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
	endif()
  endif()
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
endforeach(exmpl)

add_test(NAME ExampleCsvSimple COMMAND ExampleCsvSimple)
add_test(NAME ExampleCsvAdvanced COMMAND ExampleCsvAdvanced)
add_test(NAME ExampleJsonSimple COMMAND ExampleJsonSimple)
add_test(NAME ExampleJsonAdvanced COMMAND ExampleJsonAdvanced)
add_test(NAME ExampleXmlSimple COMMAND ExampleXmlSimple)
add_test(NAME ExampleXmlAdvanced COMMAND ExampleXmlAdvanced)
