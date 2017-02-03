FineFramework
-------------

FineFramework (FFW) is an open source framework written in C++ designed for developing applications. This framework provides basic simple structure to write things easily with less code. Anyone can use this framework without greater knowledge of programming. This framework provides functions which can be used as a building blocks for applications of any kind. The core functions should provide sufficient exploitation for the most of problems.

FineFramework contains several modules, each module has a specific use and is compiled separately. If you wish to use only one module, you don't need to compile and link them all, except for the math module which is needed by all modules.

* **[Graphics Module](group__graphics.html) - OpenGL drawing.**
Contains functions for drawing various shapes with OpenGL, including Window management and user input event handling. Uses third party library [GLFW](http://www.glfw.org/) and [FreeType](https://www.freetype.org/)

* **[GUI Module](group__gui.html) - Graphical User Interface.**
This module allows creation of user interfaces (GUIs). It takes care of widget layout, automatic spacing when resized, spacing, callbacks, etc. This module provides several widgets (buttons, check boxes, text edits, radios, sliders, etc..) however, has a functionality to add custom made widgets. All widgets can be arranged in linear layouts, similarly how HTML works and can be also styled. *This GUI is not directly linked to OpenGL or any other rendering engine! Instead, it can use any backend with any renderer you wish to use. However, an OpenGL backend is provided by default and is only enabled when this module is used alongside with Graphics Module. This module will not work on it's own, unless a backend (rendering engine) is provided.* 

* **[Data Module](group__data.html) - XML and JSON loaders.**
Provides a way to load and save XML and JSON data files. Uses third party library [tinyxml-2](https://github.com/leethomason/tinyxml2)

* **[Math Module](group__math.html) - Math functions and types.**
This module is header only (meaning, it does not need to be compiled) and is used by all modules listed here. Contains various math functions (calculating angles, creating model-view-projection matrices, colour management, UTF-8 to wide string conversion) and also provides several new types (2D, 3D, and 4D vectors, matrices, ring buffers, quaternions, and more).

The following modules will be added in upcoming release:

* **Media Module - Audio and Image loading.**
Provides functions and classes to load audio and image files. Uses following third party libraries: [libjpeg](http://www.ijg.org/), [libogg](https://xiph.org/ogg/), [libpng](http://www.libpng.org/pub/png/libpng.html), [libtiff](http://www.libtiff.org/), [libvorbis](https://xiph.org/vorbis/), and [libz](http://www.zlib.net/)

* **Audio Module - Audio playing and manipulation.**
The Audio module provides functionality to play sound files including streaming option. Sounds can be loaded into buffers and played through streams which can accept multiple buffers at once and has a functionality to edit pitch or speed of the sound using re-sampler. This module uses third party library [RtAudio](https://www.music.mcgill.ca/~gary/rtaudio/)

