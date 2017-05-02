**I want to use only one module (for example finegraphics), do I need link all of them?**

> No. All modules (graphics, data, gui, media) are not dependent on each other. However, they all use math module which is header only library, therefore no extra linking is needed.

**Where can I download pre-built binary files?**

> [Here!](md_markdown_download.html)

**Can I extract a piece of code from a source file and use it in my own project?**

> Yes. Go for it.

**What license does FFW use?**

> MIT License.

**What does the MIT license mean for me and my project?**

> You can re-use the code freely for your own use, for non-commercial and commercial, in binary or source form. You can do whatever you want, except: reselling the original software, claiming authorship, or attacking the author.

**How do I add this library/libraries to my project?**

> I highly recommend reading "Getting started" section in [tutorials page](md_markdown_tutorials.html). 
>
> You will need to let your compiler know where the header files are located by adding `-I/path/to/fineframework/include` Next, you will also need to add a folder where the library binaries are located by adding `-L/path/to/fineframework/include` into the linker. Now your compiler knows where the header files are located and your linker also knows about the binary files. You will also need to add `-lfinegrapgics` or `-lfinemedia` depending on what module are you using. Lastly, add `#include <ffw/graphics.h>` or `#include <ffw/media.h>` into your project source files, depending on what you need. For more info read [this guide](http://www.network-theory.co.uk/docs/gccintro/gccintro_17.html). Or, if you are using Visual Studio, read [this guide instead.](https://en.wikibooks.org/wiki/C%2B%2B_Programming/Compiler/Linker/Libraries/Configuring_Visual_Studio) 

**When I launch my application I get an error that fineframework *.DLL files were not found (Windows)**

> If you are using Visual Studio, this is a common issue. Copy paste the necessary fineframework DLLs into the folder where your application executable is located. If you are using GCC, usually an IDE solves this problem for you. If not, copy paste the necessary DLLs as stated previously.

**When I launch my application I get an error that fineframework *.so files were not found (Linux)**

> Copy the necessary *.so files next to your project's executable. If you are building FFW with CMake, did you forget to run `sudo make install` ? For more information read [this tutorial](md_markdown_tutorial-linux.html). 

**undefined reference to 'pthread_create'**

> You need to link pthread library by adding "-lpthread" to the linker at the end of the command line. This is not needed unless you are using ffw::Thread class. 

**glfwSetWindowIcon was not declared in this scope**

> You have an older version of GLFW. You need GLFW 3.2 or newer. Either delete old version and [install a newer one](http://www.glfw.org/docs/latest/compile.html), or download one using apt-get. Note that downloading GLFW using apt-get on Ubuntu 14 of older might download GLFW 3.1 and not v3.2.

**relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC**

> If you are building with CMake on Linux, the configuration files will look for static version of the libraries first, then dynamic versions. Your static library is not compiled with '-fPIC' flag. If you wish to compile with dynamic version of the library, run cmake again with -DPREFER_STATIC_OVER_DYNAMIC=OFF This will look up libraries using default settings. If set to ON, the cmake will try to first search for *.a in /usr/local/lib