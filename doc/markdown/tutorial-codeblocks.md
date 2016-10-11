FFW with CodeBlocks and MinGW
-----------------------------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need Code::Blocks which comes in two versions, with MinGW compiler and without it. It is highly recommended to use MinGW-w64 which supports much more features than original MinGW. MinGW-w64 can be downloaded from <https://sourceforge.net/projects/mingw-w64/> and download CodeBlocks **without MinGW** from <http://www.codeblocks.org/downloads/26>

### Installing MinGW-w64

When installing MinGW-w64, make sure you use **i686** architecture and not x86\_64. FFW is not fully supported on x86\_64 architecture. (i686 = 32-bit and x86_64 = 64-bit)

The version of the compiler must be **4.9.3 or newer!**

![Alt](images/tutorial-cb-01.png)

Next, when you install CodeBlocks, run it and go to **Settings (main top menu bar) -> Compiler -> Toolchain Executables** and set the compiler installation directory to the compiler's bin path. For example: `C:\mingw-w64\i686-4.9.2-posix-dwarf-rt_v3-rev1\mingw32\bin`

![Alt](images/tutorial-cb-02.png)

### Installing FFW

First, you will need to download glext.h (this is only necessary if using Graphics Module). Glext is an OpenGL extension header file which is updated regularly several times per year and can be downloaded from: <https://www.opengl.org/registry/api/GL/glext.h> The easiest way for MinGW to know about the glext header is to put it into `C:\mingw-w64\i686-x.x.x-posix-dwarf-rt_vxxx-revxxx\mingw32\i686-w64-mingw32\include\GL` The folder might already contain an old glext.h file!

Next, download the pre-built FineFramework DLLs from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **ffw-i686-w64-mingw32.zip** zip file! You do not need to download the source code! You can unpack the zip wherever you like, it does not matter.

The zip contains the following folders:

* **bin** - You can find DLLs files here, they are needed when running your C++ project executable. When distributing your executable, you must also include these DLLs next to your exe file!
* **include** - Header files needed by the compiler.
* **lib** - A-files also needed by the compiler, more precisely, needed by the linker.

### Configuring FFW project

Create a CodeBlocks console application project. You will need to let the compiler know where to find FFW headers and library files. The DLLs are not needed for the compiler itself,  instead the DLLs must be copied into the folder where your executable is, we will get into that later.

In the Project Workspace, right click on your project name and select **Build Options**. Next, add the following properties listed below to **both Release and Debug** configuration.

Go to **Compiler Settings -> Compiler Flags** and enable **Have g++ follow the C++11 ISO** alternatively, go to #defines and add -std=c++11 flag.

![Alt](images/tutorial-cb-03.png)

Now, go to **Search Directories -> Compiler** and add a new path to include folder of your downloaded copy of pre-build FFW, for example: `C:\ffw-i686-w64-mingw32\include`

![Alt](images/tutorial-cb-04.png)

For the library files, go to **Search Directories -> Linker** and add a new path to `C:\ffw-i686-w64-mingw32\lib`

![Alt](images/tutorial-cb-05.png)

Now, go to the **Linker Settings** and add the following libraries to the **Link libraries** window on the left side: `opengl32`, `finegraphics`, `finegui`, and `finedata`. (You don't need to include all modules if you are not going to use them in your project).

*Note that OpenGL library is needed only when using Graphics Module!*

![Alt](images/tutorial-cb-06.png)

### Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example:

@include ../examples/graphics/empty.cpp

Now compile it and run it! You might see the following message:

![Alt](images/tutorial-cb-07.png)

This is where DLL files comes...

Simply copy all DLLs files from `C:\path\to\ffw-i686-w64-mingw32\bin` into `C:\path\to\your\codeblocks\project\bin\Debug` as well into Release folder. (this folder contains your executable file!)

Alternatively (not recommended!) you can put all DLLs into your MinGW bin folder. The folder is the same folder listed in the compiler's bin path located in: Settings (main top menu bar) -> Compiler -> Toolchain Executables.

When done, try to run the example again. This should show up:

![Alt](images/tutorial-cb-08.png)