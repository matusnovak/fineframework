cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

# All examples
add_executable(ExampleGuiOpenGL openglgui.cpp)

# External files needed by examples
file(COPY FreeSans.ttf DESTINATION ${CMAKE_BINARY_DIR})

set(GRAPHICS_EXAMPLES ExampleGuiOpenGL)

# Dependencies
foreach(exmpl ${GRAPHICS_EXAMPLES})
  #set_target_properties(${exmpl} PROPERTIES FOLDER "${PROJECT_NAME}")

  if(UNIX)
    target_link_libraries(${exmpl} GL X11 Xrandr Xi Xxf86vm Xcursor Xinerama)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finegui)
  elseif(APPLE)
    target_link_libraries(${exmpl} gl)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finegui)
  else()
    target_link_libraries(${exmpl} opengl32)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finegui${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics optimized finegui)
  endif()

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)

  #target_compile_features(${exmpl} PRIVATE cxx_range_for)
endforeach(exmpl)