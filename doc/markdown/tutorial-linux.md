FFW with GCC on Linux
-----------------------------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! You can check your GCC version by typing `gcc --version` If you don't have GCC, you can install one by executing `sudo apt-get install build-essentials`

### Installing FFW

First, you will need to install `xorg`, `libglu1-mesa`, `mesa-common`, and `freetype` into your linux. The third party libraries needed are already installed on most linux distributions as shared objects (*.so). However to use them in a C++ project, we need header files as well. To get them, execute the following code:

```
sudo apt-get update
sudo apt-get install build-essentials xorg-dev libglu1-mesa-dev mesa-common-dev libfreetype-dev
```

There are two options to install FineFramework:

* **Download precompiled library files** - Tested and working with Ubuntu and Debian.
* **Compile it by yourself** - Requires more work but ensures that the FFW will work best on your linux distribution.

In this tutorial, we will follow the first option.

Next, download the pre-built FineFramework *.so files and headers from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **ffw-x86_64-linux-gnu.zip** zip file! You do not need to download the source code!

* **include** - Header files needed by the compiler.
* **lib** - *.so files also needed by the by the linker.

You will need to extract the contents of the zip file (folders: **include** and **lib**) somewhere on your linux. For the purpose of this tutorial, we will extract the zip file into our home directory: `/home/username` so we get: `/home/username/ffw-x86_64-linux-gnu/lib` and `/home/username/ffw-x86_64-linux-gnu/include` You might need to ensure that the library files are executable and visible to the compiler. You can do that by executing the following code:

```
cd /home/username/ffw-x86_64-linux-gnu/

sudo chmod -v a+x lib/libfinegraphics.so
sudo chmod -v a+x lib/libfinegui.so
sudo chmod -v a+x lib/libfinedata.so

sudo chmod -v a+r lib/libfinegraphics.so
sudo chmod -v a+r lib/libfinegui.so
sudo chmod -v a+r lib/libfinedata.so

dir="$PWD"
sudo echo "$dir/lib" > /etc/ld.so.conf.d/ffw.conf
sudo ldconfig
```

The last three lines will ensure that the ldconfig expands its search path to `/home/username/ffw-x86_64-linux-gnu/lib` and executing `sudo ldconfig` will rebuild its cache. You can check if the libraries are visible to the compiler and executables by running `ldconfig -v | grep fine` If no FFW libraries are listed, there was an error.

### Your first code

Your installation is done, now test the project to make sure everything works. Copy paste the following example into an empty cpp file:

@include ../examples/graphics/empty.cpp

Compile and execute with:

```
g++ -c example.cpp -o example.o -std=c++11 -I/home/username/ffw-x86_64-linux-gnu/include
g++ -o example example.o -lfinegraphics -L/home/username/ffw-x86_64-linux-gnu/lib
./example
```

If you wish to make the executable more portable (lets say you are trying to deploy your project) you can add <code>-Wl,-rpath '-Wl,$ORIGIN'</code> to the linker, for example: <code>g++ -o example example.o -Wl,-rpath '-Wl,$ORIGIN' -lfinegraphics -L/home/username/ffw-x86_64-linux-gnu/lib</code> This makes sure that the libraries are also searched inside the folder, where the executable is located. This way you can copy all necessary FFW modules (*.so files) into the executable's folder and not worry about portability.
