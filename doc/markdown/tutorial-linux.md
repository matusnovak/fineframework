FFW with GCC on Linux
-----------------------------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need GCC compiler 4.9.2 or newer! You can check your GCC version by typing `gcc --version` If you don't have GCC, you can install one by executing `sudo apt-get install build-essentials`

### Installing FFW

First, you will need to install GCC and other build files by running: 

```
$ sudo apt-get update
$ sudo apt-get install build-essential
```

You will need the following install few libraries, depending on the module you wish to use.

| Module | Libraries | Library name as a package |
|--------|-----------|----------|
| [Data](group__data.html) | None | None |
| [Graphics](group__graphics.html) | GL GLU glfw3 Xi X11 Xxf86vm Xrandr Xcursor Xinerama freetype GLFW3 | xorg-dev libglu1-mesa-dev mesa-common-dev libfreetype6-dev |
| [Gui](group__gui.html) | None | None |
| [Math](group__math.html) | None | None |
| [Media](group__media.html) | png jpeg tiff z | libpng12-dev libjpeg8-dev libtiff5-dev zlib1g-dev |

> *Note:* Graphics module also needs GLFW v3.2 library. Downloading GLFW with sudo apt-get install libglfw3-dev might download older version! However, the precompiled version of the finegraphics.so has statically linked GLFW3, so there is no need to download it.

To install the libary, simply run `sudo apt-get install <package-name>` To install all of the libraries, run the following commands:

```
sudo apt-get install xorg-dev libglu1-mesa-dev mesa-common-dev libfreetype6-dev libpng12-dev libjpeg8-dev libtiff5-dev zlib1g-dev
```

### There are two options to install FineFramework

You can either download precompiled library files from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **ffw-x86_64-linux-gnu.zip** zip file! All necessary third party **static libraries** were linked, therefore there is no need to download them (such as GLFW3).

Or, you can download the source code and build it by yourself.

### Installing FFW using precompiled library files

> Note: This method is highly not recommended! You should compile the fineframework manually. This method may invoke random "undefined reference" errors due to the different OS libraries.

Download the most recent **ffw-x86_64-linux-gnu.zip** zip file from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases) and extract it anywhere in your system.

Now, you will need to copy contents of the `lib` folder inside the extracted zip file into `/usr/local/lib` and contents of the `include` folder into `/usr/local/include`

The easiest way to do it is to run GUI File Manager as root, you can do that by executing `gksu nautilus` or `sudo -i nautilus`. **Don't forget to check permissions** of `/usr/local/include/ffw` folder that everyone can access and read files inside it. The same goes for all FFW *.so files inside `/usr/local/lib`. 

You can also fix all permissions problems by running (Not recommended! Use on your own risk):

```
find /usr/local/include -type d -exec chmod 644 {} \;
find /usr/local/lib -type d -exec chmod 755 {} \;
```

If you don't set the permissions for everyone to read the file, g++ will complain that the necessary header file or \*.so file was not found.

When done, run `sudo ldconfig` which will rebuild its cache. You can check if FFW \*.so files were found by ldconfig by typing `ldconfig -v | grep fine` which will list all \*.so files with "fine" in their file name.

Normally, when compiling a library from source using makefile, it offers you an option `sudo make install` which will do all the necessary steps for you.

### Installing FFW by building it from the source code

Compiling the source code requires third party libraries. On Linux, most of the libraries are dynamicaly linked. However, the [Graphics Module](group__graphics.html) needs GLFW version 3.2 or newer. Installing GLFW by `sudo apt-get install libglfw3-dev` **will install older version!** I highly recommend downloading the source code and compiling it manually (via CMake). Or, download pre-built dependencies from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases) (Look for x86_64-linux-gnu.zip with "dependencies" title) and use the `lib/libglfw3.a` (and header files `include/GLFW`) provided. 

You will also need the all of the libraries (dependencies) listed above (look for a table)! Downloading the libraries via `sudo apt-get` will result in installing a dynamic version (*.so file) of the library. If you wish you statically link all the libraries, compile them yourself or grab pre-built dependencies from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases) (Look for x86_64-linux-gnu.zip with "dependencies" title)

Download source code from [GitHub as ZIP](https://github.com/matusnovak/fineframework/archive/master.zip) and extract it anywhere in your system. Use CMake to cofigure the project and then compile it using make. To install it, simply run `sudo make install` Don't forget to use `sudo` when installing, the `/usr/local` folder requires sudo permissions.

```
cd /path/to/fineframework
mkdir build
cd build
cmake ..
make all
sudo make install
```

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