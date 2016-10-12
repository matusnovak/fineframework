FFW with GCC on OSX
-----------------------------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! You can check your GCC version by typing `gcc --version` GCC is no part of OSX by default, you will need to download and install XCode.

### Installing FFW

**There are two options to install FineFramework:**

(recommended) You can either download precompiled library files from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **ffw-x86_64-osx-clang.zip** zip file! All necessary third party libraries were statically linked, therefore there is no need to download them.

Or, you can download the source code and build it by yourself.

### Installing FFW using precompiled library files

Download the most recent **ffw-x86_64-osx-clang.zip** zip file from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases) and extract it anywhere in your system.

Now, you will need to copy contents of the `lib` folder inside the extracted zip file into `/usr/local/lib` and contents of the `include` folder into `/usr/local/include`

Normally, when compiling a library from source using makefile, it offers you an option `sudo make install` which will do all the necessary steps for you.

### Installing FFW by building it from the source code

Compiling the source code requires third party libraries (dependencies). You can either compile them by yourself or you can download them from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases) Look for "Dependencies" and download **x86_64-osx-clang.zip** the zip file contains `include` and `lib` folder. Extract the contents of the `include` folder into `/usr/local/include` and contents of the `lib` folder into `/usr/local/lib`

Next, download source code from [GitHub as ZIP](https://github.com/matusnovak/fineframework/archive/master.zip) and extract it anywhere in your system. Use CMake to cofigure the project and then compile it using make. To install it, simply run `sudo make install` Don't forget to use `sudo` when installing, the `/usr/local` folder requires sudo permissions.

### Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example into empty cpp file:

@include ../examples/graphics/empty.cpp

Now compile it using g++

```
$ g++ -c example.cpp -o example.o -std=c++11 -I/usr/local/include
$ g++ -o example example.o -lfinegraphics -L/usr/local/lib
$ ./example
```

Don't forget to point to `-I/usr/local/include` for header files and `-L/usr/local/lib` for library files!