FFW with GCC on Linux
-----------------------------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! You can check your GCC version by typing `gcc --version` If you don't have GCC, you can install one by executing `sudo apt-get install build-essentials`

### Installing FFW

First, you will need to install X11, OpenGL development files into your linux. You can do that by executing the following code:

```
$ sudo apt-get update
$ sudo apt-get install build-essentials xorg-dev libglu1-mesa-dev mesa-common-dev
```

**There are two options to install FineFramework:**

You can either download precompiled library files from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **ffw-x86_64-linux-gnu.zip** zip file! All necessary third party libraries were statically linked, therefore there is no need to download them.

(recommended) Or, you can download the source code and build it by yourself.

### Installing FFW using precompiled library files

Download the most recent **ffw-x86_64-linux-gnu.zip** zip file from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases) and extract it anywhere in your system.

Now, you will need to copy contents of the `lib` folder inside the extracted zip file into `/usr/local/lib` and contents of the `include` folder into `/usr/local/include`

The easiest way to do it is to run GUI File Manager as root, you can do that by executing `gksu nautilus` or `sudo -i nautilus`. **Don't forget to check permissions** of `/usr/local/include/ffw` folder that everyone can access and read files inside it. The same goes for all FFW *.so files inside `/usr/local/lib`. 

If you don't set the permissions for everyone to read the file, g++ will complain that the necessary header file or \*.so file was not found.

When done, run `sudo ldconfig` which will rebuild its cache. You can check if FFW \*.so files were found by ldconfig by typing `ldconfig -v | grep fine` which will list all \*.so files with "fine" in their file name.

Normally, when compiling a library from source using makefile, it offers you an option `sudo make install` which will do all the necessary steps for you.

### Installing FFW by building it from the source code

Compiling the source code requires third party libraries (dependencies). You can either compile them by yourself or you can download them if your linux allows it by typing:

```
$ sudo apt-get install libglfw3-dev libfreetype6-dev
```

Note that the library names might differ depending on your linux distribution.

Download source code from [GitHub as ZIP](https://github.com/matusnovak/fineframework/archive/master.zip) and extract it anywhere in your system. Use CMake to cofigure the project and then compile it using make. To install it, simply run `sudo make install` Don't forget to use `sudo` when installing, the `/usr/local` folder requires sudo permissions.

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