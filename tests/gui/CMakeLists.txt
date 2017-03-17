cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

# All tests
add_executable(TestsGui gui.cpp nullrenderer.h nullstyles.h)

set(GUI_TESTS TestsGui)

# Dependencies
foreach(exmpl ${GUI_TESTS})
  target_link_libraries(${exmpl} debug finegui${CMAKE_DEBUG_POSTFIX})
  target_link_libraries(${exmpl}  optimized finegui)
  
  if(MSVC)
	set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
endforeach(exmpl)

add_test(NAME TestsGui COMMAND TestsGui)