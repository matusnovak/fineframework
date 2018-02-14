cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

# All tests
add_executable(TestsGraphics graphics.cpp)

set(GRAPHICS_TESTS TestsGraphics)

# Dependencies
foreach(exmpl ${GRAPHICS_TESTS})
  target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX})
  target_link_libraries(${exmpl} optimized finegraphics)
  
  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif()
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)

  set_property(TARGET ${exmpl} PROPERTY FOLDER "fineframework/tests") 
endforeach(exmpl)

add_test(NAME TestsGraphics COMMAND TestsGraphics)