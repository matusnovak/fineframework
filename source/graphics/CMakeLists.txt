cmake_minimum_required(VERSION 3.0)
project (finegraphics)

FILE(GLOB_RECURSE SOURCES *.cpp *.c)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/graphics/*.h)

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "fineframework/libs") 
  
# Dependencies
if(APPLE)
  target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} ${GLFW3_LIBRARY} ${FREETYPE2_LIBRARY} ${LIBPNG_LIBRARY} ${ZLIB_LIBRARY} ${BZIP2_LIBRARY})
elseif(UNIX)
  target_link_libraries(${PROJECT_NAME} GL GLU ${GLFW3_LIBRARY} Xi X11 Xxf86vm Xrandr Xcursor Xinerama ${FREETYPE2_LIBRARY} ${LIBPNG_LIBRARY} ${ZLIB_LIBRARY} ${BZIP2_LIBRARY})
elseif(MSVC)
  target_link_libraries(${PROJECT_NAME} ${GLFW3_LIBRARY} opengl32 ${FREETYPE2_LIBRARY} ${LIBPNG_LIBRARY} ${ZLIB_LIBRARY})
else()
  target_link_libraries(${PROJECT_NAME} ${GLFW3_LIBRARY} opengl32 ${FREETYPE2_LIBRARY} ${LIBPNG_LIBRARY} ${ZLIB_LIBRARY})
endif()

include_directories(${PROJECT_NAME} PUBLIC ${GLFW3_INCLUDE_DIR} ${FREETYPE2_INCLUDE_DIR} ${LIBPNG_INCLUDE_DIR})

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
