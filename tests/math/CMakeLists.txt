cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)
link_directories(${CMAKE_BINARY_DIR})

# All examples
add_executable(TestsMath math.cpp)

set(MATH_TESTS TestsMath)

# Dependencies
foreach(exmpl ${MATH_TESTS})
  # target_link_libraries(${exmpl} )

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
endforeach(exmpl)

add_test(NAME TestsMath COMMAND TestsMath)