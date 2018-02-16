# OSX with Clang

This tutorial will explain how to include any FFW module into your C++ project. You will need Clang++ compiler 3.7 or newer!  You will also need to install [Homebrew](https://brew.sh/)

## Installing dependencies

First, you will need to install Clang++ compiler (alias GCC) by running [Homebrew](https://brew.sh/):

```
$ brew install --with-clang llvm
$ brew install cmake
```

To test if you have Clang++ 3.7 or newer, simply run:

```
$ clang++ --version
```

You also need cmake 3.0 or newer, you can verify it by running:

```
$ cmake --version
```

## Installing FFW (building from source code)

Clone (or download as zip or tar file) and run cmake by running the following commands:

```
$ cd ~ # Go to the home directory
$ git clone https://github.com/matusnovak/fineframework.git # Will create a "fineframework" directory
$ mkdir fineframework/build
$ cd fineframework/build
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local
```

All third party libraries are included within the cmake configuration via git submodules. **All of the required libraries included from fineframework/libs are statically included in the final fineframework library.**

Lastly, compile and install:

```
$ make all
$ make install
```

That's it! All of the necessary header files will be located in `/usr/local/include` under the folder `ffw` and all of the binaries (the `*.so` objects) will be located in `/usr/local/lib`. If you prefer to use different folder, modify the `-DCMAKE_INSTALL_PREFIX=/usr/local` argument during `cmake` configuration.

If you are still not sure, check out CircleCI: <https://circleci.com/gh/matusnovak/workflows/fineframework/tree/master> which contains builds every time the master branch is updated. The build logs will show you all the commands used to produce the output library. Alternatively, checkout out master in Travis CI: <https://travis-ci.org/matusnovak/fineframework/branches>

## Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:

[import, lang:"c_cpp"](../../examples/graphics/empty.cpp)

Now compile it using g++

```
$ clang++ -c example.cpp -o example.o -std=c++11 -I/usr/local/include
$ clang++ -o example example.o -L/System/Library/Frameworks -L/usr/local/lib -framework OpenGL -lfinegraphics 
$ ./example
```

Don't forget to point to `-I/usr/local/include` for header files and `-L/usr/local/lib` for library files!