# Linux with GCC

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! 

## Installing dependencies

First, you will need to install GCC and other build files by running: 

```
$ sudo apt-get update
$ sudo apt-get install build-essential git curl
```

To test if you have GCC 4.9.2 or newer, simply run:

```
$ gcc --version
```

You will need the following install the third party libraries. Graphics module also needs GLFW v3.2 library. Downloading GLFW with sudo apt-get install libglfw3-dev might download older version!

To install the libary, simply run `sudo apt-get install <package-name>` To install all of the libraries, run the following commands:

```
$ sudo apt-get install curl xorg-dev libgl1-mesa-glx libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev mesa-common-dev libfreetype6-dev libpng12-dev libjpeg8-dev libtiff5-dev zlib1g-dev libglfw3-dev
```

Note: On Debian the `libjpeg8-dev` package might be renamed as `libjpeg-dev`

Next, you will need to update glext.h to the newest version. If you are running latest Linux, for example Ubuntu 16.04 or newer, this is not needed. Run the following command, this will download official `glect.h` and puts it at the right place:

```
$ sudo curl -o /usr/include/GL/glext.h https://www.khronos.org/registry/OpenGL/api/GL/glext.h
```

If you **need to install glfw3.2 or newer** because your package manager downloads the old version, run the following commands:

```
$ cd ~ # Go to the home directory
$ git clone https://github.com/glfw/glfw # Will create a "glfw" directory
$ mkdir glfw/build
$ cd glfw/build
$ cmake .. -G "Unix Makefiles"
$ make 
$ sudo make install
```

If you are on Ubuntu system, instead of building GLFW v3.2 from source, you can use the following package directly from launchpad repository:

```
# Source: https://launchpad.net/ubuntu/+source/glfw3/3.2.1-1

wget http://launchpadlibrarian.net/279734097/libglfw3_3.2.1-1_amd64.deb
sudo dpkg -i libglfw3_3.2.1-1_amd64.deb
sudo apt-get install -f

wget http://launchpadlibrarian.net/279734093/libglfw3-dev_3.2.1-1_amd64.deb
sudo dpkg -i libglfw3-dev_3.2.1-1_amd64.deb
sudo apt-get install -f
```

## Installing FFW (building from source code)

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

**Note:** If you do not have those dependencies, you can download them in binary form from <https://github.com/matusnovak/fineframework/releases/tag/v0.2.5-deps> (search for `x86_64-linux-gnu.zip` file)

* If you have problems locating the libraries, you can add `-DCMAKE_LIBRARY_PATH="/usr/local/lib"` into the cmake command. If you need more than one directory separated by space.
* You can also add additional include directories by adding `-DINCLUDE_DIRECTORIES="/usr/local/include"`
* If you wish to link against static stdlib, add `-DSTATIC_STDLIB=ON` at the end of the cmake command.
* To change the install directory, add `-DCMAKE_INSTALL_PREFIX:PATH=/path/to/install/dir`

Lastly, compile and install:

```
$ make all
$ sudo make install
```

That's it!

## Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:

[import, lang:"c_cpp"](../../examples/graphics/empty.cpp)

Now compile it using g++

```
$ g++ -c example.cpp -o example.o -std=c++11
$ g++ -o example example.o -lfinegraphics
$ ./example
```

If you want your executable to be portable (for example, distributing it on other systems) you might want to add <code>-Wl,-rpath '-Wl,$ORIGIN'</code> to the linker and copy necessary FFW *.so files into the executable's folder. This will make sure that the executable looks for its dependencies inside its folder.