FineFramework
-------------

## Status

| Service | Compiler | Master | Devel |
| ------- | -------- | ------ | ----- |
| AppVeyor | Visual Studio 2013, 2015, 2017 + MinGW | [![Build status](https://ci.appveyor.com/api/projects/status/skag9h1m8pthm4bp/branch/master?svg=true)](https://ci.appveyor.com/project/matusnovak/fineframework/branch/master) | [![Build status](https://ci.appveyor.com/api/projects/status/skag9h1m8pthm4bp/branch/devel?svg=true)](https://ci.appveyor.com/project/matusnovak/fineframework/branch/devel) |
| Travis CI | Linux GCC 5 + Clang 3.7 | [![Build Status](https://travis-ci.org/matusnovak/fineframework.svg?branch=master)](https://travis-ci.org/matusnovak/fineframework) | [![Build Status](https://travis-ci.org/matusnovak/fineframework.svg?branch=devel)](https://travis-ci.org/matusnovak/fineframework) |
| CircleCI | Linux GCC 5.5 + Linux GCC 6.4 + Linux GCC 7.2 | [![CircleCI](https://circleci.com/gh/matusnovak/fineframework/tree/master.svg?style=svg)](https://circleci.com/gh/matusnovak/fineframework/tree/master) | [![CircleCI](https://circleci.com/gh/matusnovak/fineframework/tree/devel.svg?style=svg)](https://circleci.com/gh/matusnovak/fineframework/tree/devel) |
| Codacy | | [![Codacy Badge](https://api.codacy.com/project/badge/Grade/5f3cdd8363c64a9ab7fb3904cb56cf00)](https://www.codacy.com/app/matus.novak/fineframework?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=matusnovak/fineframework&amp;utm_campaign=Badge_Grade) | [![Codacy Badge](https://api.codacy.com/project/badge/Grade/5f3cdd8363c64a9ab7fb3904cb56cf00)](https://www.codacy.com/app/matus.novak/fineframework?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=matusnovak/fineframework&amp;utm_campaign=Badge_Grade) |

## Introduction

FineFramework (FFW) is an open source framework written in C++ designed for developing applications. This framework provides basic simple structure to write things easily with less code. Anyone can use this framework without greater knowledge of programming. This framework provides functions which can be used as a building blocks for applications of any kind. The core functions should provide sufficient exploitation for the most of problems.

FineFramework contains several modules, each module has a specific use and is compiled separately. If you wish to use only one module, you don't need to compile and link them all, except for the math module which is needed by all modules. **[The API documentation can be found here](/doxygen/modules.md)**.

To get started, please read [How to install FineFramework tutorials](/installation/installation.md) where you can find instructions for Visual Studio, MinGW, Linux using GCC, and OSX using Clang.

## Third party libraries

This framework uses the following third party libraries:

* [libjpeg](http://www.ijg.org/)
* [libpng](http://www.libpng.org/pub/png/libpng.html)
* [libtiff](http://www.libtiff.org/)
* [libz](http://www.zlib.net/)
* [GLFW](http://www.glfw.org/)
* [nanovg](https://github.com/memononen/nanovg)
* [FreeType](https://www.freetype.org/)
* [bzip2](https://github.com/enthought/bzip2-1.0.6)
* [utfcpp](https://github.com/nemtrif/utfcpp)
* [tinyxml-2](https://github.com/leethomason/tinyxml2)

Please note that all of the necessary third party libraries are included as a submodule and linked through CMake statically. You do not need to download them at all. On Linux, other libraries (such as X11) are needed by the operating system. You can find out more by visiting the [How to install FineFramework tutorials](/installation/installation.md) section.

## License

The MIT License (MIT)

Copyright (c) 2017 Matus Novak

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
