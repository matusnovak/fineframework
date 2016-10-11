cmake_minimum_required(VERSION 3.0)
project (finegraphics)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/graphics/*.h)

if(BUILD_SHARED_LIBS)
  set(BUILD_TYPE SHARED)
else()
  set(BUILD_TYPE STATIC)
endif()

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} ${BUILD_TYPE} ${SOURCES} ${HEADERS})
  
# Dependencies
if(UNIX)
  target_link_libraries(${PROJECT_NAME} GL GLU glfw3 X11 Xxf86vm Xrandr Xcursor Xinerama freetype)
  include_directories(${PROJECT_NAME} /usr/include/freetype2)
elseif(APPLE)
  target_link_libraries(${PROJECT_NAME} glfw3 gl freetype)
else()
  target_link_libraries(${PROJECT_NAME} glfw3 opengl32 freetype)
endif()
  
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
#target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)
  
INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib LIBRARY DESTINATION lib COMPONENT library)