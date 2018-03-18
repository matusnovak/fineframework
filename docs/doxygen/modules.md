Modules
=======

Here is a list of all modules:

### [data - XML, CSV, and JSON loaders](/doxygen/group__data.md)

Encode and decode XML, CSV, or JSON structures. 

Provides a way to load and save XML, CSV, and JSON data files. Uses third party library [tinyxml-2](https://github.com/leethomason/tinyxml2) 

### [graphics - OpenGL drawing and window handling](/doxygen/group__graphics.md)

Basic graphical functionality via OpenGL. 

This module contains the basic API wrappers around OpenGL (such as textures, framebuffers, renderbuffers), Window management and user input handling in easy to follow wrapper class using GLFW as the backend. This module also contains basic drawing API based on nanovg library, for drawing bitmap fonts, true type fonts, shapes, and textures. Uses the following third party libraries: [GLFW](http://www.glfw.org/), [nanovg](https://github.com/memononen/nanovg), [FreeType](https://www.freetype.org/), [libpng](http://www.libpng.org/pub/png/libpng.html), and [libz](http://www.zlib.net/) 

### [gui - Graphical User Interface](/doxygen/group__gui.md)

Render engine independent graphic user interface. 

This module allows creation of user interfaces (GUIs). It takes care of widget layout, automatic spacing when resized, spacing, callbacks, etc. This module provides several widgets (buttons, check boxes, text edits, radios, sliders, etc..) however, has a functionality to add custom widgets as well. All widgets can be arranged in linear layouts, similarly how HTML works, and can be also styled. This GUI is not directly linked to the OpenGL, or any other rendering engine! Instead, it can use any backend with any renderer you wish to use. However, an OpenGL backend is provided by default, if the user wishes to use. The entire module is UTF-8 enabled. 

### [math - Math functions and data types](/doxygen/group__math.md)

From basic up to advanced math function and additional data types such as vectors, matrices, and more. 

This module is header only, it does not need to be compiled, and is used by all modules listed here. Contains various math functions (calculating angles, creating model-view-projection matrices, colour management, UTF-8 to wide string conversion and back) and also provides several new types (2D, 3D, and 4D vectors, matrices, ring buffers, quaternions, and more). Uses third party library [utfcpp](https://github.com/nemtrif/utfcpp) 

### [media - Image and 3D object file load/write](/doxygen/group__media.md)

Provides classes for reading and writing image files and loading of 3D OBJ files. 

Uses the following third party libraries: [libjpeg](http://www.ijg.org/), [libpng](http://www.libpng.org/pub/png/libpng.html), [libtiff](http://www.libtiff.org/), and [libz](http://www.zlib.net/) 

