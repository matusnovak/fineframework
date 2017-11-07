Clang on OSX
----------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need Clang++ compiler 3.7 or newer!  You will also need to install [Homebrew](https://brew.sh/)

### Installing dependencies

First, you will need to install Clang++ compiler (alias GCC) by running [Homebrew](https://brew.sh/):

```
$ brew install --with-clang llvm
$ brew install cmake
```

To test if you have Clang++ 3.7 or newer, simply run:

```
$ clang++ --version
```

You will need the following install the following libraries via [Homebrew](https://brew.sh/):

```
$ brew install freetype libpng libjpeg libtiff zlib glfw
```

You can check if they are all present by executing `ls /usr/local/lib`

### Installing FFW (building from source code)

Clone (or download as zip or tar file) and run cmake by running the following commands:

```
$ cd ~ # Go to the home directory
$ git clone https://github.com/matusnovak/fineframework.git # Will create a "fineframework" directory
$ mkdir fineframework/build
$ cd fineframework/build
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
```

Make sure that the dependencies (third party libraries) are found. The `LIBRARY-NOTFOUND` will be displayed if the given library was not found.

```
# The following output will be printed by cmake 
-- glfw3 library path: /usr/local/lib/libglfw.dylib
-- freetype library path: /usr/local/lib/libfreetype.dylib
-- png library path: /usr/local/lib/libpng.dylib
-- jpeg library path: /usr/local/lib/libjpeg.dylib
-- tiff library path: /usr/local/lib/libtiff.dylib
-- zlib library path: /usr/lib/libz.dylib
-- gz2 library path: /usr/local/lib/libbz2.dylib 
```

**Note:** If you do not have those dependencies, you can download them in binary form from <https://github.com/matusnovak/fineframework/releases/tag/v0.2.5-deps> (search for `x86_64-apple-darwin.zip` file)

* If you have problems locating the libraries, you can add `-DCMAKE_LIBRARY_PATH="/usr/local/lib"` into the cmake command. If you need more than one directory, you can append them with collon: `-DCMAKE_LIBRARY_PATH="/usr/local/lib:/home/test/libs"` or with semicollon on windows. If that does not work, use spaces.
* You can also add additional include directories by adding `-DINCLUDE_DIRECTORIES="/usr/local/include"`
* If you wish to link against static stdlib, add `-DSTATIC_STDLIB=ON` at the end of the cmake command.
* To change the install directory, add `-DCMAKE_INSTALL_PREFIX:PATH=/path/to/install/dir`

Lastly, compile and install:

```
$ make all
$ make install
```

That's it!

### Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:

@include ../examples/graphics/empty.cpp

Now compile it using g++

```
$ clang++ -c example.cpp -o example.o -std=c++11 -I/usr/local/include
$ clang++ -o example example.o -lfinegraphics -L/usr/local/lib
$ ./example
```

Don't forget to point to `-I/usr/local/include` for header files and `-L/usr/local/lib` for library files!