cmake_minimum_required(VERSION 3.0)
project (finedata)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/data/*.h)

add_definitions(-DFFW_EXPORTS)
add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
  
# Dependencies
if(UNIX OR APPLE)
  #target_link_libraries(${PROJECT_NAME})
else()
  #target_link_libraries(${PROJECT_NAME})
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