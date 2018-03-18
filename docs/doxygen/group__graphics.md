graphics - OpenGL drawing and window handling
===================================

Basic graphical functionality via OpenGL. 

## Detailed description

This module contains the basic API wrappers around OpenGL (such as textures, framebuffers, renderbuffers), Window management and user input handling in easy to follow wrapper class using GLFW as the backend. This module also contains basic drawing API based on nanovg library, for drawing bitmap fonts, true type fonts, shapes, and textures. Uses the following third party libraries: [GLFW](http://www.glfw.org/), [nanovg](https://github.com/memononen/nanovg), [FreeType](https://www.freetype.org/), [libpng](http://www.libpng.org/pub/png/libpng.html), and [libz](http://www.zlib.net/) 


## Classes

| Name |
|:-----|
| class [ffw::BitmapFont](ffw_BitmapFont.html) |
| class [ffw::BufferObject](ffw_BufferObject.html) |
| class [ffw::Vbo](ffw_Vbo.html) |
| class [ffw::Ibo](ffw_Ibo.html) |
| class [ffw::Font](ffw_Font.html) |
| class [ffw::Framebuffer](ffw_Framebuffer.html) |
| class [ffw::FreeTypeLoader](ffw_FreeTypeLoader.html) |
| class [ffw::GLFWRenderWindow](ffw_GLFWRenderWindow.html) |
| class [ffw::OpenGLImageType](ffw_OpenGLImageType.html) |
| struct [ffw::Monitor](ffw_Monitor.html) |
| class [ffw::Renderbuffer](ffw_Renderbuffer.html) |
| class [ffw::Renderbuffer2D](ffw_Renderbuffer2D.html) |
| class [ffw::Renderbuffer2DMS](ffw_Renderbuffer2DMS.html) |
| struct [ffw::DrawPaint](ffw_DrawPaint.html) |
| class [ffw::RenderContext](ffw_RenderContext.html) <span style="opacity:0.8;">Basic render context which can be used to draw shapes using nanovg on the screen. </span> |
| class [ffw::RenderWindow](ffw_RenderWindow.html) |
| class [ffw::Shader](ffw_Shader.html) |
| class [ffw::Texture](ffw_Texture.html) <span style="opacity:0.8;">Base class for all texture types. </span> |
| class [ffw::Texture1D](ffw_Texture1D.html) |
| class [ffw::Texture1DArray](ffw_Texture1DArray.html) |
| class [ffw::Texture2D](ffw_Texture2D.html) |
| class [ffw::Texture2DArray](ffw_Texture2DArray.html) |
| class [ffw::Texture2DArrayMS](ffw_Texture2DArrayMS.html) |
| class [ffw::Texture2DMS](ffw_Texture2DMS.html) |
| class [ffw::Texture3D](ffw_Texture3D.html) |
| class [ffw::TextureCubemap](ffw_TextureCubemap.html) |
| class [ffw::TrueTypeFont](ffw_TrueTypeFont.html) |


## Enums

| Type | Name |
| -------: | :------- |
| enum | [DrawMode](#642b0610) |
| enum | [DrawPathWinding](#5ed40213) |
| enum | [LineCap](#795eeb36) |


## Functions

| Type | Name |
| -------: | :------- |
|  [ffw::OpenGLImageType](ffw_OpenGLImageType.html) | [getOpenGLImageType](#ed9106f9) ([ffw::ImageType](ffw.html#fa711f90) _type_)  |
|  void | [loadGlCoreArb](#92805e56) (void *(*)(const char *) _glextLoader_)  |


## Enums Documentation

### _enum_ <a id="642b0610" href="#642b0610">DrawMode</a>

```cpp
enum DrawMode {
    FILL,
    STROKE,
    FILL_AND_STROKE,
}
```



### _enum_ <a id="5ed40213" href="#5ed40213">DrawPathWinding</a>

```cpp
enum DrawPathWinding {
    CCW,
    CW,
}
```



### _enum_ <a id="795eeb36" href="#795eeb36">LineCap</a>

```cpp
enum LineCap {
    BUTT,
    ROUND,
    SQUARE,
    BEVEL,
    MITER,
}
```





## Functions Documentation

### _function_ <a id="ed9106f9" href="#ed9106f9">getOpenGLImageType</a>

```cpp
ffw::OpenGLImageType getOpenGLImageType (
    ffw::ImageType type
) 
```



### _function_ <a id="92805e56" href="#92805e56">loadGlCoreArb</a>

```cpp
void loadGlCoreArb (
    void *(*)(const char *) glextLoader
) 
```





