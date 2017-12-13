cmake_minimum_required(VERSION 3.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif()
link_directories(${CMAKE_BINARY_DIR})

# All examples
add_executable(TestsMathFileInfo math_fileinfo.cpp)
add_executable(TestsMathFunctions math_functions.cpp)
add_executable(TestsMathRingBuffer math_ringbuffer.cpp)
add_executable(TestsMathUnicode math_unicode.cpp)
add_executable(TestsMathVar math_var.cpp)
add_executable(TestsMathVectors math_vectors.cpp)
add_executable(TestsMathPromise math_promise.cpp)

set(MATH_TESTS TestsMathFileInfo TestsMathFunctions TestsMathRingBuffer TestsMathUnicode TestsMathVar TestsMathVectors TestsMathPromise)

# Dependencies
foreach(exmpl ${MATH_TESTS})
  # target_link_libraries(${exmpl} )

  if(MSVC)
    set_target_properties(${exmpl} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
  endif(MSVC)
  
  if(NOT MSVC AND NOT APPLE)
    target_link_libraries(${exmpl} Threads::Threads)
  endif()
  
  # Compile with static stdlib ?
  if(STATIC_STDLIB)
    target_link_libraries(${exmpl} -static-libgcc -static-libstdc++)
  endif(STATIC_STDLIB)
  
  add_test(NAME ${exmpl} COMMAND ${exmpl})
endforeach(exmpl)
