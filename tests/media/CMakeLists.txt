cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

file(COPY imgs cube.mtl cube.obj cylinder.mtl cylinder.obj plane.mtl plane.obj planes.mtl planes.obj DESTINATION ${CMAKE_BINARY_DIR})
file(COPY imgs cube.mtl cube.obj cylinder.mtl cylinder.obj plane.mtl plane.obj planes.mtl planes.obj DESTINATION ${CMAKE_BINARY_DIR}/tests/media)

# All examples
add_executable(TestsMediaImages media_images.cpp)
add_executable(TestsMediaObj media_obj.cpp)
add_executable(TestsMediaAudio media_audio.cpp)

set(MEDIA_TESTS TestsMediaImages TestsMediaObj TestsMediaAudio)

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
  
  add_test(NAME ${exmpl} COMMAND ${exmpl})
  set_property(TARGET ${exmpl} PROPERTY FOLDER "fineframework/tests") 
endforeach(exmpl)
