Tutorial: GCC on Linux
----------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! 

### Installing dependencies

First, you will need to install GCC and other build files by running: 

```
$ sudo apt-get update
$ sudo apt-get install build-essential git curl
```

To test if you have GCC 4.9.2 or newer, simply run:

```
$ gcc --version
```

You will need the following install the third party libraries.

> *Note:* Graphics module also needs GLFW v3.2 library. Downloading GLFW with sudo apt-get install libglfw3-dev might download older version! However, the precompiled version of the finegraphics.so has statically linked GLFW3, so there is no need to download it.

To install the libary, simply run `sudo apt-get install <package-name>` To install all of the libraries, run the following commands:

```
$ sudo apt-get install curl xorg-dev libgl1-mesa-glx libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev mesa-common-dev libfreetype6-dev libpng12-dev libjpeg8-dev libtiff5-dev zlib1g-dev
```

Next, you will need to update glext.h to the newest version. If you are running latest Linux, for example Ubuntu 16.04 or newer, this is not needed. Run the following command, this will download official `glect.h` and puts it at the right place:

```
$ sudo curl -o /usr/include/GL/glext.h https://www.khronos.org/registry/OpenGL/api/GL/glext.h
```

lastly, you **need to install glfw3.2 or newer**. Note that installing libglfw3-dev package **might give you glfw version 3.1!** To get the latest version, run the following commands:

```
$ cd ~ # Go to the home directory
$ git clone https://github.com/glfw/glfw # Will create a "glfw" directory
$ mkdir glfw/build
$ cd glfw/build
$ cmake .. -G "Unix Makefiles"
$ make 
$ sudo make install
```

### Installing FFW (building from source code)

Clone (or download as zip or tar file) and run cmake by running the following commands:

```
$ cd ~ # Go to the home directory
$ git clone https://github.com/matusnovak/fineframework.git # Will create a "fineframework" directory
$ mkdir fineframework/build
$ cd fineframework/build
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
```

Make sure that the dependencies (third party libraries) are found and C++11 is supported. The `LIBRARY-NOTFOUND` will be displayed if the given library was not found.

```
# The following output will be printed by cmake 
-- Performing Test COMPILER_SUPPORTS_CXX11
-- Performing Test COMPILER_SUPPORTS_CXX11 - Success
-- 1
-- glfw3 library path: /usr/local/lib/libglfw3.a
-- freetype library path: /usr/lib/x86_64-linux-gnu/libfreetype.so
-- png library path: /usr/lib/x86_64-linux-gnu/libpng.so
-- jpeg library path: /usr/lib/x86_64-linux-gnu/libjpeg.so
-- tiff library path: /usr/lib/x86_64-linux-gnu/libtiff.so
-- zlib library path: /usr/lib/x86_64-linux-gnu/libz.so
-- Looking for include file pthread.h
-- Looking for include file pthread.h - found
```

* If you wish to link against static dependencies, add `-DPREFER_STATIC_OVER_DYNAMIC=ON` at the end of the cmake command.
* If you wish to link against static stdlib, add `-DSTATIC_STDLIB=ON` at the end of the cmake command.
* To change the install directory, add `-DCMAKE_INSTALL_PREFIX:PATH=/path/to/install/dir`

Lastly, compile and install:

```
$ make all
$ sudo make install
```

That's it!

### Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:

@include ../examples/graphics/empty.cpp

Now compile it using g++

```
$ g++ -c example.cpp -o example.o -std=c++11
$ g++ -o example example.o -lfinegraphics
$ ./example
```

If you want your executable to be portable (for example, distributing it on other systems) you might want to add <code>-Wl,-rpath '-Wl,$ORIGIN'</code> to the linker and copy necessary FFW *.so files into the executable's folder. This will make sure that the executable looks for its dependencies inside its folder.