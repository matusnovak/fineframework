cmake_minimum_required(VERSION 3.1)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
project (fineframework)

if(UNITX OR APPLE)
  if (NOT ${CMAKE_LIBRARY_PATH})
    set(CMAKE_LIBRARY_PATH "/usr/local/lib")
  endif()
  if (NOT ${INCLUDE_DIRECTORIES})
    set(INCLUDE_DIRECTORIES "/usr/local/include")
  endif()
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Select build type")
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")

include_directories(${CMAKE_SOURCE_DIR}/include)
if(MSVC)
  link_directories(${CMAKE_BINARY_DIR}/Debug)
  link_directories(${CMAKE_BINARY_DIR}/Release)
endif(MSVC)
  
if(UNIX OR APPLE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,$ORIGIN")
endif()

# Add third party libraries
ExternalProject_Add(GLFW3
  DOWNLOAD_COMMAND ""
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/glfw
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DGLFW_INSTALL=OFF -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF
  BUILD_COMMAND cmake --build . --config MinSizeRel
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

if(MSVC)
  set(GLFW3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/glfw/include)
  set(GLFW3_LIBRARY ${CMAKE_BINARY_DIR}/GLFW3-prefix/src/GLFW3-build/src/MinSizeRel/glfw3.lib)
else(MSVC)
  set(GLFW3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/glfw/include)
  set(GLFW3_LIBRARY ${CMAKE_BINARY_DIR}/GLFW3-prefix/src/GLFW3-build/src/libglfw3.a)
endif(MSVC)

ExternalProject_Add(ZLIB
  DOWNLOAD_COMMAND ""
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/zlib
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
  BUILD_COMMAND cmake --build . --target zlibstatic --config MinSizeRel
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

if(MSVC)
  set(ZLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/zlib)
  set(ZLIB_LIBRARY ${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/MinSizeRel/zlibstatic.lib)
elseif(MINGW)
  set(ZLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/zlib)
  set(ZLIB_LIBRARY ${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/libzlibstatic.a)
else()
  set(ZLIB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/zlib)
  set(ZLIB_LIBRARY ${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/libz.a)
endif()

if(MSVC)
  ExternalProject_Add(LIBPNG
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/libpng
    CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DPNG_FRAMEWORK=OFF -DPNG_SHARED=OFF -DPNG_STATIC=ON -DPNG_TESTS=OFF -DZLIB_INCLUDE_DIR=${CMAKE_SOURCE_DIR}/libs/zlib -DCMAKE_INCLUDE_PATH=${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build -DZLIB_LIBRARY=${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/MinSizeRel/zlibstatic
    BUILD_COMMAND cmake -E copy ${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/zconf.h ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build && cmake --build . --config MinSizeRel
    INSTALL_COMMAND ""
    TEST_COMMAND ""
  )
  add_dependencies(LIBPNG ZLIB)
elseif(MINGW)
  ExternalProject_Add(LIBPNG
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/libpng
    CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DPNG_FRAMEWORK=OFF -DPNG_SHARED=OFF -DPNG_STATIC=ON -DPNG_TESTS=OFF -DZLIB_INCLUDE_DIR=${CMAKE_SOURCE_DIR}/libs/zlib -DZLIB_LIBRARY=${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/libzlibstatic.a
    BUILD_COMMAND cmake -E copy ${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/zconf.h ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build && cmake --build . --config MinSizeRel
    INSTALL_COMMAND ""
    TEST_COMMAND ""
  )
  add_dependencies(LIBPNG ZLIB)
else()
  ExternalProject_Add(LIBPNG
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/libpng
    CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DPNG_FRAMEWORK=OFF -DPNG_SHARED=OFF -DPNG_STATIC=ON -DPNG_TESTS=OFF -DZLIB_INCLUDE_DIR=${CMAKE_SOURCE_DIR}/libs/zlib -DZLIB_LIBRARY=${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/libz.a -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
    BUILD_COMMAND cmake -E copy ${CMAKE_BINARY_DIR}/ZLIB-prefix/src/ZLIB-build/zconf.h ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build && cmake --build . --config MinSizeRel
    INSTALL_COMMAND ""
    TEST_COMMAND ""
  )
  add_dependencies(LIBPNG ZLIB)
endif()

if(MSVC)
  set(LIBPNG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/libpng ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build)
  set(LIBPNG_LIBRARY ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build/MinSizeRel/libpng16_static.lib)
else(MSVC)
  set(LIBPNG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/libpng ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build)
  set(LIBPNG_LIBRARY ${CMAKE_BINARY_DIR}/LIBPNG-prefix/src/LIBPNG-build/libpng16.a)
endif(MSVC)

ExternalProject_Add(FREETYPE2
  DOWNLOAD_COMMAND ""
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/freetype2
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
  BUILD_COMMAND cmake --build . --config MinSizeRel
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)
add_dependencies(FREETYPE2 LIBPNG)

if(MSVC)
  set(FREETYPE2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/freetype2/include)
  set(FREETYPE2_LIBRARY ${CMAKE_BINARY_DIR}/FREETYPE2-prefix/src/FREETYPE2-build/MinSizeRel/freetype.lib)
else(MSVC)
  set(FREETYPE2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/freetype2/include)
  set(FREETYPE2_LIBRARY ${CMAKE_BINARY_DIR}/FREETYPE2-prefix/src/FREETYPE2-build/libfreetype.a)
endif(MSVC)

ExternalProject_Add(LIBTIFF
  DOWNLOAD_COMMAND ""
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/libtiff
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true -Djpeg:BOOL=false -Djbig:BOOL=false -Djpeg12:BOOL=false
  BUILD_COMMAND cmake --build . --target tiff --config MinSizeRel && cmake --build . --target tiff --config Debug
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

if(MSVC)
  set(LIBTIFF_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/libtiff/libtiff ${CMAKE_BINARY_DIR}/LIBTIFF-prefix/src/LIBTIFF-build/libtiff)
  set(LIBTIFF_LIBRARY optimized ${CMAKE_BINARY_DIR}/LIBTIFF-prefix/src/LIBTIFF-build/libtiff/MinSizeRel/tiff.lib debug ${CMAKE_BINARY_DIR}/LIBTIFF-prefix/src/LIBTIFF-build/libtiff/Debug/tiffd.lib)
else(MSVC)
  set(LIBTIFF_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/libtiff/libtiff ${CMAKE_BINARY_DIR}/LIBTIFF-prefix/src/LIBTIFF-build/libtiff)
  set(LIBTIFF_LIBRARY ${CMAKE_BINARY_DIR}/LIBTIFF-prefix/src/LIBTIFF-build/libtiff/libtiff.a)
endif(MSVC)

ExternalProject_Add(LIBJPEG
  DOWNLOAD_COMMAND ""
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/libjpeg
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC=ON -DBUILD_TESTS=OFF -DBUILD_EXECUTABLES=OFF -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
  BUILD_COMMAND cmake --build . --config MinSizeRel
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

if(MSVC)
  set(LIBJPEG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/libjpeg ${CMAKE_BINARY_DIR}/LIBJPEG-prefix/src/LIBJPEG-build)
  set(LIBJPEG_LIBRARY ${CMAKE_BINARY_DIR}/LIBJPEG-prefix/src/LIBJPEG-build/MinSizeRel/jpeg.lib)
else(MSVC)
  set(LIBJPEG_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/libjpeg ${CMAKE_BINARY_DIR}/LIBJPEG-prefix/src/LIBJPEG-build)
  set(LIBJPEG_LIBRARY ${CMAKE_BINARY_DIR}/LIBJPEG-prefix/src/LIBJPEG-build/libjpeg.a)
endif(MSVC)

ExternalProject_Add(TINYXML2
  DOWNLOAD_COMMAND ""
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/tinyxml2
  CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF -DBUILD_STATIC_LIBS=ON -DBUILD_TESTS=OFF -DBUILD_TESTING=OFF -DCMAKE_POSITION_INDEPENDENT_CODE:BOOL=true
  BUILD_COMMAND cmake --build . --config MinSizeRel && cmake --build . --config Debug
  INSTALL_COMMAND ""
  TEST_COMMAND ""
)

if(MSVC)
  set(TINYXML2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/tinyxml2)
  set(TINYXML2_LIBRARY optimized ${CMAKE_BINARY_DIR}/TINYXML2-prefix/src/TINYXML2-build/MinSizeRel/tinyxml2.lib debug ${CMAKE_BINARY_DIR}/TINYXML2-prefix/src/TINYXML2-build/Debug/tinyxml2d.lib)
else(MSVC)
  set(TINYXML2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/tinyxml2)
  set(TINYXML2_LIBRARY ${CMAKE_BINARY_DIR}/TINYXML2-prefix/src/TINYXML2-build/libtinyxml2.a)
endif(MSVC)

if(UNIX OR APPLE)
  ExternalProject_Add(BZIP2
    DOWNLOAD_COMMAND ""
    SOURCE_DIR ${CMAKE_SOURCE_DIR}/libs/bzip2-1.0.6
    CONFIGURE_COMMAND ""
    BUILD_COMMAND cd ${CMAKE_SOURCE_DIR}/libs && chmod +x ./make_bzip2.sh && ./make_bzip2.sh ${CMAKE_BINARY_DIR}/BZIP2-prefix/src/BZIP2-build
    INSTALL_COMMAND ""
    TEST_COMMAND ""
  )

  set(BZIP2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/bzip2-1.0.6)
  set(BZIP2_LIBRARY ${CMAKE_BINARY_DIR}/BZIP2-prefix/src/BZIP2-build/libbz2.a)
endif()

if(NOT MSVC)
  find_package(Threads REQUIRED)
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_DEBUG_POSTFIX _d CACHE STRING "Postfix added to debug version of the library")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

option(BUILD_MODULE_MATH "Build math module (Must stay ON!)" ON)
option(BUILD_MODULE_GRAPHICS "Build OpenGL graphics module" ON)
option(BUILD_MODULE_DATA "Build Data module" ON)
option(BUILD_MODULE_GUI "Build GUI module" ON)
option(BUILD_MODULE_MEDIA "Build Media module" ON)
option(BUILD_EXAMPLES "Build examples" ON)
option(BUILD_TESTS "Build tests" ON)
option(BUILD_INSTALL "Install library" ON)
option(STATIC_STDLIB "Link against static stdlib" OFF)

if(APPLE)
  find_library(OPENGL_LIBRARY OpenGL)
  find_library(COCOA_LIBRARY Cocoa)
  find_library(IOKIT_LIBRARY IOKit)
  find_library(COREVIDEO_LIBRARY CoreVideo)
endif()

if(BUILD_TESTS)
  enable_testing ()
endif()

function(add_modulesubdirs MODULE)
  add_subdirectory(source/${MODULE})
  if(BUILD_EXAMPLES)
    add_subdirectory(examples/${MODULE})
  endif()
  if(BUILD_TESTS)
    add_subdirectory(tests/${MODULE})
  endif()
endfunction(add_modulesubdirs)

if(BUILD_MODULE_MATH)
  add_modulesubdirs(math)
endif()

if(BUILD_MODULE_GRAPHICS)
  add_modulesubdirs(graphics)
  add_dependencies(finegraphics GLFW3)
  add_dependencies(finegraphics FREETYPE2)
  if(UNIX OR APPLE)
    add_dependencies(finegraphics BZIP2)
  endif()
endif()

if(BUILD_MODULE_DATA)
  add_modulesubdirs(data)
  add_dependencies(finedata TINYXML2)
endif()

if(BUILD_MODULE_GUI)
  add_modulesubdirs(gui)
endif()

if(BUILD_MODULE_MEDIA)
  add_modulesubdirs(media)
  add_dependencies(finemedia LIBJPEG)
  add_dependencies(finemedia LIBPNG)
  add_dependencies(finemedia LIBTIFF)
  add_dependencies(finemedia ZLIB)
endif()

if(BUILD_INSTALL)
  install(DIRECTORY include/ffw DESTINATION include)
endif()
