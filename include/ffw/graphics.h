/**
 * @defgroup graphics graphics - OpenGL drawing and window handling
 * @brief Basic graphical functionality via OpenGL
 * @details Contains functions for drawing various shapes with OpenGL, 
 * including Window management and user input event handling. Uses 
 * third party library 
 * [GLFW](http://www.glfw.org/) 
 * and [FreeType](https://www.freetype.org/)
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