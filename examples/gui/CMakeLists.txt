cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

file(COPY FreeSans.ttf DESTINATION ${CMAKE_BINARY_DIR})
file(COPY FreeSans.ttf DESTINATION ${CMAKE_BINARY_DIR}/examples/gui)

# All examples
add_executable(ExampleGuiOpenGL openglgui.cpp)

set(GRAPHICS_EXAMPLES ExampleGuiOpenGL)

# Dependencies
foreach(exmpl ${GRAPHICS_EXAMPLES})
  if(APPLE)
    #target_link_libraries(${exmpl})
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemath${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
    target_link_libraries(${exmpl} optimized finegraphics optimized finemath optimized finegui)
  elseif(UNIX)
    target_link_libraries(${exmpl} GL X11 Xrandr Xi Xxf86vm Xcursor Xinerama)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemath${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finemath optimized finegui)
  else()
    target_link_libraries(${exmpl} opengl32)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemath${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finemath optimized finegui)
	if(MSVC)
	  set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
	endif()
  endif()
endforeach(exmpl)