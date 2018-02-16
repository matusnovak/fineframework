GuiBackend
===================================


**Implemented by:** [ffw::GuiWindow](ffw_GuiWindow.html), 

The documentation for this class was generated from: `include/ffw/gui/guibackend.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual void | [resize](#be8428b8) (int _width_, int _height_) = 0  |
|  virtual void | [startRender](#5df1f915) () = 0  |
|  virtual void | [endRender](#588f911f) () = 0  |
|  virtual void | [setScissors](#d7bd7eac) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_) const = 0  |
|  virtual void | [clearWithColor](#6ea57df9) (const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawRectangle](#233aa74d) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawRectangleRounded](#ea95818a) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [ffw::Color](ffw_Color.html) & _color_, float _tl_, float _tr_, float _br_, float _bl_) const = 0  |
|  virtual void | [drawLine](#f7ca2b3e) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _start_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _end_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawCircle](#e0694f55) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, float _radius_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawArc](#5b118ea9) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, float _inner_, float _outer_, float _start_, float _end_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawQuad](#58486aa1) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p0_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p1_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p2_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p3_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawString](#03f1116b) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::GuiFont](ffw_GuiFont.html) * _font_, const std::string::value_type * _str_, size_t _length_, const [ffw::Color](ffw_Color.html) & _color_, float _lineHeight_ = 1.25f) const = 0  |
|  virtual void | [drawTriangle](#9c057eb2) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p0_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p1_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _p2_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawImage](#ab89aa8e) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [GuiImage](ffw_GuiImage.html) * _image_, const [ffw::Vec4i](ffw.html#fd5627df) & _sub_, bool _mirrorX_, bool _mirrorY_, const [ffw::Color](ffw_Color.html) & _color_) const = 0  |
|  virtual void | [drawBackground](#405392f1) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [ffw::GuiStyle::Background](ffw_GuiStyle_Background.html) & _background_, bool _ignore_ = false) const  |
|  virtual void | [drawBorder](#c175e2f0) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [ffw::GuiStyle::Border](ffw_GuiStyle_Border.html) & _border_) const  |
|  virtual void | [drawStringAligned](#64cfb491) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [ffw::GuiFont](ffw_GuiFont.html) * _font_, [ffw::GuiAlign](ffw.html#38e5cadb) _align_, const std::string & _str_, const [ffw::GuiStyle::Text](ffw_GuiStyle_Text.html) & _text_, float _lineHeight_ = 1.25f) const  |


## Public Functions Documentation

### _function_ <a id="be8428b8" href="#be8428b8">resize</a>

```cpp
virtual void resize (
    int width,
    int height
) = 0 
```



### _function_ <a id="5df1f915" href="#5df1f915">startRender</a>

```cpp
virtual void startRender () = 0 
```



### _function_ <a id="588f911f" href="#588f911f">endRender</a>

```cpp
virtual void endRender () = 0 
```



### _function_ <a id="d7bd7eac" href="#d7bd7eac">setScissors</a>

```cpp
virtual void setScissors (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size
) const = 0 
```



### _function_ <a id="6ea57df9" href="#6ea57df9">clearWithColor</a>

```cpp
virtual void clearWithColor (
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="233aa74d" href="#233aa74d">drawRectangle</a>

```cpp
virtual void drawRectangle (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="ea95818a" href="#ea95818a">drawRectangleRounded</a>

```cpp
virtual void drawRectangleRounded (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const ffw::Color & color,
    float tl,
    float tr,
    float br,
    float bl
) const = 0 
```



### _function_ <a id="f7ca2b3e" href="#f7ca2b3e">drawLine</a>

```cpp
virtual void drawLine (
    const ffw::Vec2f & start,
    const ffw::Vec2f & end,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="e0694f55" href="#e0694f55">drawCircle</a>

```cpp
virtual void drawCircle (
    const ffw::Vec2f & pos,
    float radius,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="5b118ea9" href="#5b118ea9">drawArc</a>

```cpp
virtual void drawArc (
    const ffw::Vec2f & pos,
    float inner,
    float outer,
    float start,
    float end,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="58486aa1" href="#58486aa1">drawQuad</a>

```cpp
virtual void drawQuad (
    const ffw::Vec2f & p0,
    const ffw::Vec2f & p1,
    const ffw::Vec2f & p2,
    const ffw::Vec2f & p3,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="03f1116b" href="#03f1116b">drawString</a>

```cpp
virtual void drawString (
    const ffw::Vec2f & pos,
    const ffw::GuiFont * font,
    const std::string::value_type * str,
    size_t length,
    const ffw::Color & color,
    float lineHeight = 1.25f
) const = 0 
```



### _function_ <a id="9c057eb2" href="#9c057eb2">drawTriangle</a>

```cpp
virtual void drawTriangle (
    const ffw::Vec2f & p0,
    const ffw::Vec2f & p1,
    const ffw::Vec2f & p2,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="ab89aa8e" href="#ab89aa8e">drawImage</a>

```cpp
virtual void drawImage (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const GuiImage * image,
    const ffw::Vec4i & sub,
    bool mirrorX,
    bool mirrorY,
    const ffw::Color & color
) const = 0 
```



### _function_ <a id="405392f1" href="#405392f1">drawBackground</a>

```cpp
virtual void drawBackground (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const ffw::GuiStyle::Background & background,
    bool ignore = false
) const 
```



### _function_ <a id="c175e2f0" href="#c175e2f0">drawBorder</a>

```cpp
virtual void drawBorder (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const ffw::GuiStyle::Border & border
) const 
```



### _function_ <a id="64cfb491" href="#64cfb491">drawStringAligned</a>

```cpp
virtual void drawStringAligned (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const ffw::GuiFont * font,
    ffw::GuiAlign align,
    const std::string & str,
    const ffw::GuiStyle::Text & text,
    float lineHeight = 1.25f
) const 
```





