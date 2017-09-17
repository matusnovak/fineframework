Download
=================

Pre-compiled binaries can be found on **[Latest GitHub Release](https://github.com/matusnovak/fineframework/releases/latest)** and download the correct ZIP file depending on your compiler and OS. All of the binaries have been compiled against master on [AppVeyor](https://ci.appveyor.com/project/matusnovak/fineframework/branch/master) and [Travis-ci](https://travis-ci.org/matusnovak/fineframework/branches) The release contains the following zip files for specific system and compiler:


| File name | Operating System | Compiler   |
|------|------|------|
| ffw-mingw.zip | Windows | MinGW (32-bit)  |
| ffw-i686-w64-mingw32.zip | Windows | MinGW-w64 i686 (32-bit)  |
| ffw-x86_64-w64-mingw32.zip | Windows | MinGW-w64 x86_64 (64-bit)  |
| ffw-win32-vc12.zip | Windows | Visual Studio 2013 (32-bit)  |
| ffw-win64-vc12.zip | Windows | Visual Studio 2013 (64-bit)  |
| ffw-win32-vc14.zip | Windows | Visual Studio 2015 (32-bit)  |
| ffw-win64-vc14.zip | Windows | Visual Studio 2015 (64-bit)  |
| ffw-win32-vc15.zip | Windows | Visual Studio 2017 (32-bit)  |
| ffw-win64-vc14.zip | Windows | Visual Studio 2017 (64-bit)  |
| ffw-x86_64-linux-gnu.zip | Linux | GCC (64-bit)  |
| ffw-x86_64-apple-darwin.zip | OS X | Apple Clang++ (64-bit)  |


All windows and OSX versions have been compiled with statically linked third party libraries. Linux binary distribution may not work out of the box, as you will need to install the following dependencies:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">sudo apt-get install apt-get install xorg-dev libgl1-mesa-glx libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev mesa-common-dev</span>
</div></pre>



And the following libraries:


<pre><div class="lang-cpp" style="white-space: nowrap;"><span class="hljs-normal">sudo apt-get install libfreetype6-dev libpng12-dev libjpeg8-dev libtiff5-dev zlib1g-dev libglfw3-dev</span>
</div></pre>



Also, please make sure that your `glext.h` located in `/usr/local/include/GL` is updated with the latest release: [https://www.khronos.org/registry/OpenGL/api/GL/glext.h](https://www.khronos.org/registry/OpenGL/api/GL/glext.h)

### Instructions


Don't know what to do? Look into [tutorials located here](md_doc_markdown_tutorial-install.html)

### Source Code


[Download as ZIP](https://github.com/matusnovak/fineframework/archive/master.zip) or as [TAR.GZ](https://github.com/matusnovak/fineframework/archive/master.tar.gz)

Use Git or checkout with SVN using: `[https://github.com/matusnovak/fineframework.git](https://github.com/matusnovak/fineframework.git)` 

