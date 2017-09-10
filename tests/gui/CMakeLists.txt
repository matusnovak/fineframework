cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

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
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
endforeach(exmpl)

add_test(NAME TestsGui COMMAND TestsGui)