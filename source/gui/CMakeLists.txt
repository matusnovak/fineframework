cmake_minimum_required(VERSION 3.0)
project (finegui)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/gui/*.h)

if(BUILD_SHARED_LIBS)
  set(BUILD_TYPE SHARED)
else()
  set(BUILD_TYPE STATIC)
endif()

add_definitions(-DFFW_EXPORTS)

if(BUILD_MODULE_GUI_OPENGL)
add_definitions(-DFFW_GUI_BACKEND_OPENGL)
endif(BUILD_MODULE_GUI_OPENGL)

if(BUILD_MODULE_GUI_OPENGL3)
add_definitions(-DFFW_GUI_BACKEND_OPENGL3)
endif(BUILD_MODULE_GUI_OPENGL3)

add_library(${PROJECT_NAME} ${BUILD_TYPE} ${SOURCES} ${HEADERS})
  
# Dependencies
if(UNIX OR APPLE)
  #target_link_libraries(${PROJECT_NAME})
else()
  #target_link_libraries(${PROJECT_NAME})
endif()
  
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
  
INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib LIBRARY DESTINATION lib COMPONENT library)