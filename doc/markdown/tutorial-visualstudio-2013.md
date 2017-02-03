FFW with Visual Studio 2013
-----------------------------------------

This tutorial will explain how to include any FFW module into your C++ project. You will need Visual Studio 2013 which can be downloaded from <https://www.visualstudio.com/en-us/news/releasenotes/vs2013-community-vs>.

### Installing FFW

First, you will need to download glext.h (this is only necessary if using Graphics Module). Glext is an OpenGL extension header file which is updated regularly several times per year and can be downloaded from: <https://www.opengl.org/registry/api/GL/glext.h> The easiest way for Visual Studio to know about the glext header is to put it into `C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include\GL` folder.


Next, download the pre-built FineFramework DLLs from [GitHub Release Page](https://github.com/matusnovak/fineframework/releases). Look for the most recent release and download the **win32-vc12.zip** zip file! (vc12 = VS 2013) You do not need to download the source code! You can unpack the zip wherever you like, it does not matter.

The zip contains the following folders:
 - **bin** - You can find DLLs files here, they are needed when running your C++ project executable. When distributing your executable, you must also include these DLLs next to your exe file!
 - **include** - Header files needed by the compiler.
 - **lib** - LIB files also needed by the compiler, more precisely, needed by the linker.

### Configuring FFW project

Create a Visual Studio project (either console application or win32 application), you will need to let the compiler know where to find FFW header and library files. The DDLs are not needed for the compiler itself, instead the DLLs must be copied into the folder where your executable is, we will get into that later.

In the Solution Explorer (usually on the left side) right click on your project name and select **properties**. Alternatively select Project -> Properties at the top menu bar. Next, add the following properties listed below to **both Release and Debug** configuration.

Next, go to **Configuration Properties -> C/C++ -> Additional Include Directories** and add a new path to include folder of your downloaded copy of pre-built FFW, for example: `C:\path\to\ffw-win32-vc12\include`

![Alt](images/tutorial-vs12-01.png)

For the library files, go to **Configuration Properties -> Linker -> General -> Additional Library Directories** and add a new path to `C:\path\to\ffw-win32-vc12\lib`

![Alt](images/tutorial-vs12-02.png)

In the same category, go to **Input -> Additional Dependencies** and add `opengl32.lib`, `finegraphics.lib`, `finedata.lib`, `finemedia.lib`, `finegui.lib`, and `finemath.lib` (You don't need to include all modules if you are not going to use them in your project).

Note that you should use the debug version of FFW when using debug configuration, simply, add `finegraphics_d.lib`, `finedata_d.lib`, `finemedia_d.lib`, `finegui_d.lib`, and `finemath_d.lib`  into Additional Dependencies in Debug configutation. (Note the `_d` suffix in the library names!)

*Note that OpenGL library is needed only when using Graphics Module!*

![Alt](images/tutorial-vs12-03.png)

### Your first code

Your configuration is done, now test the project to make sure everything works. Copy paste the following example:

@include ../examples/graphics/empty.cpp

Now compile it and run it! You might see the following message:

![Alt](images/tutorial-vs12-04.png)

This is where DLL files comes... 

For the Debug, simply copy all DLL and PDB files with '_d' suffix from `C:\path\to\ffw-win32-vc12\bin` into `C:\Path\To\Your\Project Folder\Debug` (this folder contains your executable file!)

For the Release, simply copy all DLL (with NO '_d' suffix!) from `C:\path\to\ffw-win32-vc12\bin` into `C:\Path\To\Your\Project Folder\Release` (this folder contains your executable file!)

Alternatively (not recommended!) you can put all DLLs and PDBs files (Debug and Release) into your Visual Studio bin folder located here: `C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin` In this case, you won't need to copy DLLs every time you create a new FFW project, unless you are running your application outside of Visual Studio.

When done, try to run the example again. This should show up:

![Alt](images/tutorial-vs12-05.png)