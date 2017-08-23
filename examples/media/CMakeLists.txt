cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)
link_directories(${CMAKE_BINARY_DIR})
include_directories(${EXTRA_LIBRARY_DIR}/include)
link_directories(${EXTRA_LIBRARY_DIR}/lib)

file(COPY monkey.obj DESTINATION ${CMAKE_BINARY_DIR})
file(COPY monkey.obj DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY uvgrid.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY uvgrid.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY skybox_back.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY skybox_back.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY skybox_bottom.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY skybox_bottom.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY skybox_front.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY skybox_front.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY skybox_left.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY skybox_left.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY skybox_right.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY skybox_right.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY skybox_top.png DESTINATION ${CMAKE_BINARY_DIR})
file(COPY skybox_top.png DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY monkeyshader.frag DESTINATION ${CMAKE_BINARY_DIR})
file(COPY monkeyshader.frag DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

file(COPY monkeyshader.vert DESTINATION ${CMAKE_BINARY_DIR})
file(COPY monkeyshader.vert DESTINATION ${CMAKE_BINARY_DIR}/examples/media)

# All examples
add_executable(ExampleShowImage showimage.cpp)
add_executable(Example3DMonkey 3dmonkey.cpp)
add_executable(ExampleCubemap cubemap.cpp)

set(MEDIA_EXAMPLES ExampleShowImage Example3DMonkey ExampleCubemap)

# Dependencies
foreach(exmpl ${MEDIA_EXAMPLES})
  if(APPLE)
    #target_link_libraries(${exmpl})
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemedia${CMAKE_DEBUG_POSTFIX})
    target_link_libraries(${exmpl} optimized finegraphics  optimized finemedia)
  elseif(UNIX)
    target_link_libraries(${exmpl} GL X11 Xrandr Xi Xxf86vm Xcursor Xinerama)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemedia${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics  optimized finemedia)
  else()
    target_link_libraries(${exmpl} opengl32)
    target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} debug finemedia${CMAKE_DEBUG_POSTFIX})
	target_link_libraries(${exmpl} optimized finegraphics  optimized finemedia)
	if(MSVC)
	  set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
	endif()
  endif()
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
endforeach(exmpl)