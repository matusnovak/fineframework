cmake_minimum_required(VERSION 3.0)
project (finegraphics)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/graphics/*.h)

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
  
# Dependencies
if(APPLE)
  target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY} ${COREVIDEO_LIBRARY} ${GLFW3_LIBRARY} ${FREETYPE_LIBRARY} ${ZLIB_LIBRARY} ${BZ2_LIBRARY})
  include_directories(${PROJECT_NAME} /usr/local/include/freetype2)
elseif(UNIX)
  target_link_libraries(${PROJECT_NAME} GL GLU ${GLFW3_LIBRARY} Xi X11 Xxf86vm Xrandr Xcursor Xinerama ${FREETYPE_LIBRARY})
  include_directories(${PROJECT_NAME} /usr/include/freetype2)
else()
  target_link_libraries(${PROJECT_NAME} glfw3 opengl32 freetype)
endif()

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
