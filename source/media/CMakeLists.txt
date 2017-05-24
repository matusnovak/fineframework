cmake_minimum_required(VERSION 3.0)
project (finemedia)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../include)
link_directories(${CMAKE_BINARY_DIR}/Debug)
link_directories(${CMAKE_BINARY_DIR}/Release)
include_directories(${EXTRA_LIBRARY_DIR}/include)
link_directories(${EXTRA_LIBRARY_DIR}/lib)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/media/*.h)

if(BUILD_SHARED_LIBS)
  set(BUILD_TYPE SHARED)
else()
  set(BUILD_TYPE STATIC)
endif()

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} ${BUILD_TYPE} ${SOURCES} ${HEADERS})
  
# Dependencies
if(APPLE)
  target_link_libraries(${PROJECT_NAME} png jpeg tiff z)
elseif(UNIX)
  target_link_libraries(${PROJECT_NAME} ${PNG_LIBRARY} ${JPEG_LIBRARY} ${TIFF_LIBRARY} ${ZLIB_LIBRARY} lzma jbig)
else()
  if(MSVC)
    target_link_libraries(${PROJECT_NAME} png jpeg debug tiffd optimized tiff z)
  else(MSVC)
    target_link_libraries(${PROJECT_NAME} png jpeg tiff z)
  endif(MSVC)
endif()

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(${PROJECT_NAME} -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)
  
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
  
if(BUILD_INSTALL)
  INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin COMPONENT library)
endif()
