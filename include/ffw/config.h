/*** This file is part of FineFramework project ***/
#ifndef FFW_CONFIG
#define FFW_CONFIG
/*
#if __cplusplus < 201103L
#error This library needs at least a C++11 compliant compiler
#endif
*/
// Use multi byte strings, needed by windows.h
#define UNICODE 1
// Using Visual Studio
#ifdef _MSC_VER
#define FFW_WINDOWS_MSVC 1
#define FFW_WINDOWS 1
#pragma warning( disable: 4251 )
#define FFW_USE_STD_THREADS 1
#endif
// Using MinGW
#ifdef __MINGW32__
#define FFW_WINDOWS_MINGW 1
#define FFW_WINDOWS 1
#define FFW_USE_PTHREADS 1
#endif
// Using Linux GCC
#ifdef __linux__
#define FFW_LINUX_GCC 1
#define FFW_LINUX 1
#define FFW_USE_PTHREADS 1
#endif
/*// Using Android NDK
#ifdef __ANDROID__
#define FFW_ANDROID_NDK 1
#define FFW_ANDROID 1
#endif*/
// Using MAX OS X
#if defined(__APPLE__) && defined(__MACH__)
#define FFW_OSX_CLANG 1
#define FFW_OSX 1
#define FFW_USE_PTHREADS 1
#endif
#if !defined(FFW_WINDOWS_MSVC) && !defined(FFW_WINDOWS_MINGW) && !defined(FFW_LINUX_GCC) && !defined(FFW_OSX_CLANG)
#error Please use Visual Studio, MinGW, Linux GCC, or OS X Clang to compile FineFramework!
#endif
#if !defined(FFW_WINDOWS) && !defined(FFW_LINUX) && !defined(FFW_OSX)
#error Target platform not selected!
#endif
// FineFramework export for Windows
#if defined(FFW_WINDOWS)
#ifdef FFW_EXPORTS
#define FFW_API __declspec(dllexport)
#else
#define FFW_API __declspec(dllimport)
#endif
#else
#define FFW_API
#endif
#if !defined(FFW_API)
#error FFW_API dllexport not defined!
#endif
#include "constants.h"
#include <iostream>
#endif
