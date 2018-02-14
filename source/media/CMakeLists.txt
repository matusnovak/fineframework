cmake_minimum_required(VERSION 3.0)
project (finemedia)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/media/*.h)

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "fineframework/libs") 
  
# Dependencies
if(APPLE)
  target_link_libraries(${PROJECT_NAME} ${LIBPNG_LIBRARY} ${LIBJPEG_LIBRARY} ${LIBTIFF_LIBRARY} ${ZLIB_LIBRARY})
elseif(UNIX)
  target_link_libraries(${PROJECT_NAME} ${LIBPNG_LIBRARY} ${LIBJPEG_LIBRARY} ${LIBTIFF_LIBRARY} ${ZLIB_LIBRARY} lzma jbig)
elseif(MSVC)
  target_link_libraries(${PROJECT_NAME} ${LIBPNG_LIBRARY} ${LIBJPEG_LIBRARY} ${LIBTIFF_LIBRARY} ${ZLIB_LIBRARY})
else()
  target_link_libraries(${PROJECT_NAME} ${LIBPNG_LIBRARY} ${LIBJPEG_LIBRARY} ${LIBTIFF_LIBRARY} ${ZLIB_LIBRARY})
endif()

include_directories(${PROJECT_NAME} PUBLIC ${LIBPNG_INCLUDE_DIR} ${LIBJPEG_INCLUDE_DIR} ${LIBTIFF_INCLUDE_DIR})

# Compile with static stdlib ?
if(STATIC_STDLIB)
  target_link_libraries(${PROJECT_NAME} -static-libgcc -static-libstdc++)
endif(STATIC_STDLIB)
  
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
  
if(BUILD_INSTALL)
  if(MSVC)
    INSTALL(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}> DESTINATION bin OPTIONAL)
  endif()
  INSTALL(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin COMPONENT library)
endif()
