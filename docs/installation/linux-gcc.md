# Linux with GCC

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! 

## Installing dependencies

First, you will need to install GCC and other build files by running: 

```
$ sudo apt-get update
$ sudo apt-get install build-essential git cmake
```

You need GCC 4.9.2 or newer, you can check the version by running:

```
$ gcc --version
```

You also need cmake 3.0 or newer, you can verify it by running:

```
$ cmake --version
```

You will need the following install the third party libraries:

```
$ sudo apt-get install xorg-dev libgl1-mesa-glx libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

## Installing FFW (building from source code)

Clone (or download as zip or tar file) and run cmake by running the following commands:

```
$ cd ~ # Go to the home directory
$ git clone https://github.com/matusnovak/fineframework.git # Will create a "fineframework" directory
$ mkdir fineframework/build
$ cd fineframework/build
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=MinSizeRel -DCMAKE_INSTALL_PREFIX=/usr/local
```

All third party libraries are included within the cmake configuration via git submodules. **All of the required libraries included from fineframework/libs are statically included in the final fineframework library.**

Lastly, compile and install:

```
$ make all
$ sudo make install
```

That's it! All of the necessary header files will be located in `/usr/local/include` under the folder `ffw` and all of the binaries (the `*.so` objects) will be located in `/usr/local/lib`. If you prefer to use different folder, modify the `-DCMAKE_INSTALL_PREFIX=/usr/local` argument during `cmake` configuration.

If you are still not sure, check out CircleCI: <https://circleci.com/gh/matusnovak/workflows/fineframework/tree/master> which contains builds every time the master branch is updated. The build logs will show you all the commands used to produce the output library. Alternatively, checkout out master in Travis CI: <https://travis-ci.org/matusnovak/fineframework/branches>

## Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:

[import, lang:"c_cpp"](../../examples/graphics/empty.cpp)

Now compile it using g++

```
$ g++ -c example.cpp -o example.o -std=c++11 -I/usr/local/include
$ g++ -o example example.o -L/usr/local/lib -lGL -lX11 -lXrandr -lXi -lXxf86vm -lXcursor -lXinerama -lfinegraphics
$ ./example
```

If you want your executable to be portable (for example, distributing it on other systems) you might want to add <code>-Wl,-rpath '-Wl,$ORIGIN'</code> to the linker and copy necessary FFW *.so files into the executable's folder. This will make sure that the executable looks for its dependencies inside its folder.