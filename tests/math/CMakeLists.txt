cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

# All examples
add_executable(TestsMath math.cpp)

set(MATH_TESTS TestsMath)

# Dependencies
foreach(exmpl ${MATH_TESTS})
  target_link_libraries(${exmpl} optimized finemath)
  target_link_libraries(${exmpl} debug finemath${CMAKE_DEBUG_POSTFIX})

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)
endforeach(exmpl)