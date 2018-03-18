/**
 * @defgroup graphics graphics - OpenGL drawing and window handling
 * @brief Basic graphical functionality via OpenGL
 * @details This module contains the basic API wrappers around OpenGL
 * (such as textures, framebuffers, renderbuffers), Window management and user
 * input handling in easy to follow wrapper class using GLFW as the backend.
 * This module also contains basic drawing API based on nanovg library, for drawing
 * bitmap fonts, true type fonts, shapes, and textures.
 * Uses the following third party libraries: 
 * [GLFW](http://www.glfw.org/),
 * [nanovg](https://github.com/memononen/nanovg),
 * [FreeType](https://www.freetype.org/),
 * [libpng](http://www.libpng.org/pub/png/libpng.html),
 * and [libz](http://www.zlib.net/)
 */
#ifndef FFW_GRAPHICS_MODULE
#define FFW_GRAPHICS_MODULE
#include "graphics/bitmapfont.h"
#include "graphics/bufferobject.h"
#include "graphics/font.h"
#include "graphics/framebuffer.h"
#include "graphics/graphics.h"
#include "graphics/renderbuffer.h"
#include "graphics/renderbuffer2d.h"
#include "graphics/renderbuffer2dms.h"
#include "graphics/shader.h"
#include "graphics/texture.h"
#include "graphics/texture1d.h"
#include "graphics/texture1darray.h"
#include "graphics/texture2d.h"
#include "graphics/texture2darray.h"
#include "graphics/texture2darrayms.h"
#include "graphics/texture2dms.h"
#include "graphics/texture3d.h"
#include "graphics/texturecubemap.h"
#include "graphics/glfwrenderwindow.h"
#include "graphics/truetypefont.h"
#include "graphics/freetypeloader.h"
#endif