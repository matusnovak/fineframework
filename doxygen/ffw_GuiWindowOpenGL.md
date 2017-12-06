GuiWindowOpenGL
===================================


**Inherits from:** [ffw::GuiWindow](ffw_GuiWindow.html)

**Implemented by:** [ffw::GuiWindowOpenGLFBO](ffw_GuiWindowOpenGLFBO.html)

The documentation for this class was generated from: `include/ffw/gui/guiwindowopengl.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  [RenderContext](ffw_RenderContext.html) * | [context](#fb88419e) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiWindowOpenGL](#f73e7d3b) ()  |
|  virtual  | [~GuiWindowOpenGL](#97d85d49) ()  |
|  virtual bool | [create](#c7df1c0d) ([RenderContext](ffw_RenderContext.html) * _ctx_)  |
|  virtual void | [destroy](#69b35170) ()  |
|  virtual void | [resize](#b42ac84e) (int _width_, int _height_)  |
|  virtual void | [drawRectangle](#740b1c05) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _s_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [drawRectangleRounded](#a86419f1) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _s_, const [ffw::Color](ffw_Color.html) & _color_, float _tl_, float _tr_, float _br_, float _bl_) const  |
|  virtual void | [drawLine](#0167e18d) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _start_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _end_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [drawCircle](#0f6445d1) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, float _radius_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [drawArc](#8391bc95) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, float _inner_, float _outer_, float _start_, float _end_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [drawQuad](#c4029e51) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p0_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p1_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p2_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p3_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [drawString](#14cf8c41) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, const [ffw::GuiFont](ffw_GuiFont.html) * _font_, const std::wstring::value_type * _str_, size_t _length_, const [ffw::Color](ffw_Color.html) & _color_, float _lineHeight_ = 1.25f) const  |
|  virtual void | [drawTriangle](#18183d03) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p0_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p1_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p2_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [drawImage](#bbb8269f) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _s_, const [GuiImage](ffw_GuiImage.html) * _image_, const [ffw::Vec4i](ffw.html#fd5627df) & _sub_, bool _mirrorX_, bool _mirrorY_, const [ffw::Color](ffw_Color.html) & _color_) const  |
|  virtual void | [startRender](#0ebe5781) ()  |
|  virtual void | [endRender](#d5a627e1) ()  |
|  virtual void | [setScissors](#6aefac1e) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _s_) const  |
|  virtual void | [clearWithColor](#dc8b72a5) (const [ffw::Color](ffw_Color.html) & _color_) const  |


## Protected Attributes Documentation

### _variable_ <a id="fb88419e" href="#fb88419e">context</a>

```cpp
RenderContext * context
```





## Public Functions Documentation

### _function_ <a id="f73e7d3b" href="#f73e7d3b">GuiWindowOpenGL</a>

```cpp
inline  GuiWindowOpenGL () 
```



### _function_ <a id="97d85d49" href="#97d85d49">~GuiWindowOpenGL</a>

```cpp
inline virtual  ~GuiWindowOpenGL () 
```



### _function_ <a id="c7df1c0d" href="#c7df1c0d">create</a>

```cpp
inline virtual bool create (
    RenderContext * ctx
) 
```



### _function_ <a id="69b35170" href="#69b35170">destroy</a>

```cpp
inline virtual void destroy () 
```



### _function_ <a id="b42ac84e" href="#b42ac84e">resize</a>

```cpp
inline virtual void resize (
    int width,
    int height
) 
```



**Overrides:** [resize](/doxygen/ffw_GuiBackend.md#be8428b8) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="740b1c05" href="#740b1c05">drawRectangle</a>

```cpp
inline virtual void drawRectangle (
    const ffw::Vec2f & p,
    const ffw::Vec2f & s,
    const ffw::Color & color
) const 
```



**Overrides:** [drawRectangle](/doxygen/ffw_GuiBackend.md#233aa74d) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="a86419f1" href="#a86419f1">drawRectangleRounded</a>

```cpp
inline virtual void drawRectangleRounded (
    const ffw::Vec2f & p,
    const ffw::Vec2f & s,
    const ffw::Color & color,
    float tl,
    float tr,
    float br,
    float bl
) const 
```



**Overrides:** [drawRectangleRounded](/doxygen/ffw_GuiBackend.md#ea95818a) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="0167e18d" href="#0167e18d">drawLine</a>

```cpp
inline virtual void drawLine (
    const ffw::Vec2f & start,
    const ffw::Vec2f & end,
    const ffw::Color & color
) const 
```



**Overrides:** [drawLine](/doxygen/ffw_GuiBackend.md#f7ca2b3e) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="0f6445d1" href="#0f6445d1">drawCircle</a>

```cpp
inline virtual void drawCircle (
    const ffw::Vec2f & p,
    float radius,
    const ffw::Color & color
) const 
```



**Overrides:** [drawCircle](/doxygen/ffw_GuiBackend.md#e0694f55) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="8391bc95" href="#8391bc95">drawArc</a>

```cpp
inline virtual void drawArc (
    const ffw::Vec2f & p,
    float inner,
    float outer,
    float start,
    float end,
    const ffw::Color & color
) const 
```



**Overrides:** [drawArc](/doxygen/ffw_GuiBackend.md#5b118ea9) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="c4029e51" href="#c4029e51">drawQuad</a>

```cpp
inline virtual void drawQuad (
    const ffw::Vec2f & p0,
    const ffw::Vec2f & p1,
    const ffw::Vec2f & p2,
    const ffw::Vec2f & p3,
    const ffw::Color & color
) const 
```



**Overrides:** [drawQuad](/doxygen/ffw_GuiBackend.md#58486aa1) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="14cf8c41" href="#14cf8c41">drawString</a>

```cpp
inline virtual void drawString (
    const ffw::Vec2f & p,
    const ffw::GuiFont * font,
    const std::wstring::value_type * str,
    size_t length,
    const ffw::Color & color,
    float lineHeight = 1.25f
) const 
```



**Overrides:** [drawString](/doxygen/ffw_GuiBackend.md#a9bb7183) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="18183d03" href="#18183d03">drawTriangle</a>

```cpp
inline virtual void drawTriangle (
    const ffw::Vec2f & p0,
    const ffw::Vec2f & p1,
    const ffw::Vec2f & p2,
    const ffw::Color & color
) const 
```



**Overrides:** [drawTriangle](/doxygen/ffw_GuiBackend.md#9c057eb2) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="bbb8269f" href="#bbb8269f">drawImage</a>

```cpp
inline virtual void drawImage (
    const ffw::Vec2f & p,
    const ffw::Vec2f & s,
    const GuiImage * image,
    const ffw::Vec4i & sub,
    bool mirrorX,
    bool mirrorY,
    const ffw::Color & color
) const 
```



**Overrides:** [drawImage](/doxygen/ffw_GuiBackend.md#ab89aa8e) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="0ebe5781" href="#0ebe5781">startRender</a>

```cpp
inline virtual void startRender () 
```



**Overrides:** [startRender](/doxygen/ffw_GuiBackend.md#5df1f915) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="d5a627e1" href="#d5a627e1">endRender</a>

```cpp
inline virtual void endRender () 
```



**Overrides:** [endRender](/doxygen/ffw_GuiBackend.md#588f911f) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="6aefac1e" href="#6aefac1e">setScissors</a>

```cpp
inline virtual void setScissors (
    const ffw::Vec2f & p,
    const ffw::Vec2f & s
) const 
```



**Overrides:** [setScissors](/doxygen/ffw_GuiBackend.md#d7bd7eac) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)

### _function_ <a id="dc8b72a5" href="#dc8b72a5">clearWithColor</a>

```cpp
inline virtual void clearWithColor (
    const ffw::Color & color
) const 
```



**Overrides:** [clearWithColor](/doxygen/ffw_GuiBackend.md#6ea57df9) from class [GuiBackend](/doxygen/ffw_GuiBackend.md)



