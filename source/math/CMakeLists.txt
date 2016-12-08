cmake_minimum_required(VERSION 3.0)

project (finemath)

FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/math/*.h)
FILE(GLOB INLINES ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/math/*.inl)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${INLINES} ${INLINES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)