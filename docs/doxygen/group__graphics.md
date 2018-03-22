---
search:
    keywords: ['graphics', 'ffw::BitmapFont', 'ffw::BufferObject', 'ffw::Vbo', 'ffw::Ibo', 'ffw::Font', 'ffw::Framebuffer', 'ffw::FreeTypeLoader', 'ffw::GLFWRenderWindow', 'ffw::OpenGLImageType', 'ffw::Monitor', 'ffw::Renderbuffer', 'ffw::Renderbuffer2D', 'ffw::Renderbuffer2DMS', 'ffw::DrawPaint', 'ffw::RenderContext', 'ffw::RenderWindow', 'ffw::Shader', 'ffw::Texture', 'ffw::Texture1D', 'ffw::Texture1DArray', 'ffw::Texture2D', 'ffw::Texture2DArray', 'ffw::Texture2DArrayMS', 'ffw::Texture2DMS', 'ffw::Texture3D', 'ffw::TextureCubemap', 'ffw::TrueTypeFont', 'DrawMode', 'DrawPathWinding', 'LineCap', 'getOpenGLImageType', 'loadGlCoreArb']
---

# group graphics

Basic graphical functionality via OpenGL. [More...](#detailed-description)
## Classes

|Type|Name|
|-----|-----|
|class|[**ffw::BitmapFont**](classffw_1_1_bitmap_font.md)|
|class|[**ffw::BufferObject**](classffw_1_1_buffer_object.md)|
|class|[**ffw::Vbo**](classffw_1_1_vbo.md)|
|class|[**ffw::Ibo**](classffw_1_1_ibo.md)|
|class|[**ffw::Font**](classffw_1_1_font.md)|
|class|[**ffw::Framebuffer**](classffw_1_1_framebuffer.md)|
|class|[**ffw::FreeTypeLoader**](classffw_1_1_free_type_loader.md)|
|class|[**ffw::GLFWRenderWindow**](classffw_1_1_g_l_f_w_render_window.md)|
|class|[**ffw::OpenGLImageType**](classffw_1_1_open_g_l_image_type.md)|
|struct|[**ffw::Monitor**](structffw_1_1_monitor.md)|
|class|[**ffw::Renderbuffer**](classffw_1_1_renderbuffer.md)|
|class|[**ffw::Renderbuffer2D**](classffw_1_1_renderbuffer2_d.md)|
|class|[**ffw::Renderbuffer2DMS**](classffw_1_1_renderbuffer2_d_m_s.md)|
|struct|[**ffw::DrawPaint**](structffw_1_1_draw_paint.md)|
|class|[**ffw::RenderContext**](classffw_1_1_render_context.md)|
|class|[**ffw::RenderWindow**](classffw_1_1_render_window.md)|
|class|[**ffw::Shader**](classffw_1_1_shader.md)|
|class|[**ffw::Texture**](classffw_1_1_texture.md)|
|class|[**ffw::Texture1D**](classffw_1_1_texture1_d.md)|
|class|[**ffw::Texture1DArray**](classffw_1_1_texture1_d_array.md)|
|class|[**ffw::Texture2D**](classffw_1_1_texture2_d.md)|
|class|[**ffw::Texture2DArray**](classffw_1_1_texture2_d_array.md)|
|class|[**ffw::Texture2DArrayMS**](classffw_1_1_texture2_d_array_m_s.md)|
|class|[**ffw::Texture2DMS**](classffw_1_1_texture2_d_m_s.md)|
|class|[**ffw::Texture3D**](classffw_1_1_texture3_d.md)|
|class|[**ffw::TextureCubemap**](classffw_1_1_texture_cubemap.md)|
|class|[**ffw::TrueTypeFont**](classffw_1_1_true_type_font.md)|


## Enums

|Type|Name|
|-----|-----|
|enum|[**DrawMode**](group__graphics_.md#ga1c8deb51ce3a6e135e17a8b792ae3d0e) { **FILL** = 0, **STROKE**, **FILL\_AND\_STROKE** } |
|enum|[**DrawPathWinding**](group__graphics_.md#gafa76fb6b139dd190d432bfc0740f6e3f) { **CCW** = 1, **CW** = 2 } |
|enum|[**LineCap**](group__graphics_.md#ga5c58b43b0202f2b4f86c635acaacc7ae) { **BUTT**, **ROUND**, **SQUARE**, **BEVEL**, **MITER** } |


## Functions

|Type|Name|
|-----|-----|
|**[ffw::OpenGLImageType](classffw_1_1_open_g_l_image_type.md)**|[**getOpenGLImageType**](group__graphics_.md#gaa52fc9272c6011e3c7530cc801a66d93) (**[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** type) |
|void|[**loadGlCoreArb**](group__graphics_.md#ga13289c8bd52b81f97ab29d4895a34810) (void \*(\*)(const char \*) glextLoader) |


## Detailed Description

This module contains the basic API wrappers around OpenGL (such as textures, framebuffers, renderbuffers), Window management and user input handling in easy to follow wrapper class using GLFW as the backend. This module also contains basic drawing API based on nanovg library, for drawing bitmap fonts, true type fonts, shapes, and textures. Uses the following third party libraries: [GLFW](http://www.glfw.org/), [nanovg](https://github.com/memononen/nanovg), [FreeType](https://www.freetype.org/), [libpng](http://www.libpng.org/pub/png/libpng.html), and [libz](http://www.zlib.net/) 
## Enums Documentation

### enum <a id="ga1c8deb51ce3a6e135e17a8b792ae3d0e" href="#ga1c8deb51ce3a6e135e17a8b792ae3d0e">DrawMode</a>

```cpp
enum graphics::DrawMode {
    FILL = 0,
    STROKE,
    FILL_AND_STROKE,
};
```



### enum <a id="gafa76fb6b139dd190d432bfc0740f6e3f" href="#gafa76fb6b139dd190d432bfc0740f6e3f">DrawPathWinding</a>

```cpp
enum graphics::DrawPathWinding {
    CCW = 1,
    CW = 2,
};
```



### enum <a id="ga5c58b43b0202f2b4f86c635acaacc7ae" href="#ga5c58b43b0202f2b4f86c635acaacc7ae">LineCap</a>

```cpp
enum graphics::LineCap {
    BUTT,
    ROUND,
    SQUARE,
    BEVEL,
    MITER,
};
```



## Functions Documentation

### function <a id="gaa52fc9272c6011e3c7530cc801a66d93" href="#gaa52fc9272c6011e3c7530cc801a66d93">getOpenGLImageType</a>

```cpp
ffw::OpenGLImageType graphics::getOpenGLImageType (
    ffw::ImageType type
)
```



### function <a id="ga13289c8bd52b81f97ab29d4895a34810" href="#ga13289c8bd52b81f97ab29d4895a34810">loadGlCoreArb</a>

```cpp
void graphics::loadGlCoreArb (
    void *(*)(const char *) glextLoader
)
```



