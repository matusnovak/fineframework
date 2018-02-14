cmake_minimum_required(VERSION 3.0)
project (finemath)

FILE(GLOB SOURCES *.cpp)
FILE(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/math/*.h ${CMAKE_CURRENT_SOURCE_DIR}/../../include/ffw/math/third_party/utfcpp/*.h)

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER "fineframework/libs") 
