# Download

Pre-compiled binaries can be found on **[Latest GitHub Release](https://github.com/matusnovak/fineframework/releases/latest)** and download the correct ZIP file depending on your compiler and OS. All of the binaries have been compiled against master on [AppVeyor](https://ci.appveyor.com/project/matusnovak/fineframework/branch/master) and [Travis-ci](https://travis-ci.org/matusnovak/fineframework/branches) The release contains the following zip files for specific system and compiler:

| File name | Operating System | Compiler |
|-----------|------------------|----------|
| ffw-mingw.zip                        | Windows  | MinGW (32-bit)              |
| ffw-i686-w64-mingw32.zip             | Windows  | MinGW-w64 i686 (32-bit)     |
| ffw-x86\_64-w64-mingw32.zip          | Windows  | MinGW-w64 x86_64 (64-bit)   |
| ffw-win32-vc12.zip                   | Windows  | Visual Studio 2013 (32-bit) |
| ffw-win64-vc12.zip                   | Windows  | Visual Studio 2013 (64-bit) |
| ffw-win32-vc14.zip                   | Windows  | Visual Studio 2015 (32-bit) |
| ffw-win64-vc14.zip                   | Windows  | Visual Studio 2015 (64-bit) |
| ffw-win32-vc15.zip                   | Windows  | Visual Studio 2017 (32-bit) |
| ffw-win64-vc14.zip                   | Windows  | Visual Studio 2017 (64-bit) |
| ffw-x86_64-linux-gnu.zip             | Linux    | GCC (64-bit)                |
| ffw-x86_64-apple-darwin.zip          | OS X     | Apple Clang++ (64-bit)      |

All windows and OSX versions have been compiled with statically linked third party libraries.

## Instructions

Don't know what to do? Browse [tutorials located here](installation/installation.html)

## Linux builds

Linux binary distribution may not work out of the box, I highly recommend checking out the tutorials and compiling FineFramework from source. However, if you wish to download the pre-built binaries from github release, you will need to install the following dependencies: 

```
sudo apt-get install apt-get install xorg-dev libgl1-mesa-glx libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

## Source Code

[Download as ZIP](https://github.com/matusnovak/fineframework/archive/master.zip) or as [TAR.GZ](https://github.com/matusnovak/fineframework/archive/master.tar.gz)

Use Git or checkout `https://github.com/matusnovak/fineframework.git`
