cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)
link_directories(${CMAKE_BINARY_DIR})
include_directories(${EXTRA_LIBRARY_DIR}/include)
link_directories(${EXTRA_LIBRARY_DIR}/lib)

file(COPY imgs cube.mtl cube.obj cylinder.mtl cylinder.obj plane.mtl plane.obj planes.mtl planes.obj DESTINATION ${CMAKE_BINARY_DIR})
file(COPY imgs cube.mtl cube.obj cylinder.mtl cylinder.obj plane.mtl plane.obj planes.mtl planes.obj DESTINATION ${CMAKE_BINARY_DIR}/tests/media)

# All examples
add_executable(TestsMedia media.cpp)

set(MEDIA_TESTS TestsMedia)

# Dependencies
foreach(exmpl ${MEDIA_TESTS})
  target_link_libraries(${exmpl} optimized finemedia )
  target_link_libraries(${exmpl} debug finemedia${CMAKE_DEBUG_POSTFIX})

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
endforeach(exmpl)

add_test(NAME TestsMedia COMMAND TestsMedia)