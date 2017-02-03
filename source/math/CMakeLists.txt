cmake_minimum_required(VERSION 3.0)
project (finemath)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/math/*.h)

if(BUILD_SHARED_LIBS)
  set(BUILD_TYPE SHARED)
else()
  set(BUILD_TYPE STATIC)
endif()

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} ${BUILD_TYPE} ${SOURCES} ${HEADERS})
  
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
  
if(BUILD_INSTALL)
  INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin COMPONENT library)
endif()