cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

file(COPY FreeSans.ttf DESTINATION ${CMAKE_BINARY_DIR})
file(COPY FreeSans.ttf DESTINATION ${CMAKE_BINARY_DIR}/examples/graphics)

# All examples
add_executable(ExampleEmpty empty.cpp)
add_executable(ExampleFont font.cpp)

set(GRAPHICS_EXAMPLES ExampleEmpty ExampleFont)

# Dependencies
foreach(exmpl ${GRAPHICS_EXAMPLES})
  if(APPLE)
    #target_link_libraries(${exmpl})
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemath${CMAKE_DEBUG_POSTFIX})
    target_link_libraries(${exmpl} optimized finegraphics optimized finemath)
  elseif(UNIX)
    target_link_libraries(${exmpl} GL X11 Xrandr Xi Xxf86vm Xcursor Xinerama)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemath${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finemath)
  else()
    target_link_libraries(${exmpl} opengl32)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemath${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finemath)
	if(MSVC)
	  set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
	endif()
  endif()
endforeach(exmpl)