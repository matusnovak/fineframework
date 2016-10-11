cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

# All examples
add_executable(TestsMath math_tests.cpp)

set(MATH_TESTS TestsMath)

# Dependencies
foreach(exmpl ${MATH_TESTS})
  #set_target_properties(${exmpl} PROPERTIES FOLDER "${PROJECT_NAME}/tests")

  if(UNIX OR APPLE)
    #target_link_libraries(${exmpl} optimized finegraphics gl)
    #target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} gl)
  else(UNIX OR APPLE)
    #target_link_libraries(${exmpl} optimized finegraphics opengl32)
    #target_link_libraries(${exmpl} debug finegraphics${CMAKE_DEBUG_POSTFIX} opengl32)
  endif(UNIX OR APPLE)

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)

  #target_compile_features(${exmpl} PRIVATE cxx_range_for)
endforeach(exmpl)