GuiFontOpenGL
===================================


**Inherits from:** [ffw::GuiFont](ffw_GuiFont.html), [ffw::TrueTypeFont](ffw_TrueTypeFont.html)

The documentation for this class was generated from: `include/ffw/gui/guifontopengl.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual bool | [isCreated](#a4e95e92) () const  |
|  virtual void | [destroy](#536e36a5) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#5a79ff54) (const std::string & _str_, float _maxWidth_, float _lineHeight_ = 1.25) const  |
|  virtual float | [getCharAdvance](#494c07f4) (wchar_t _c_) const  |
|  virtual int | [getSizeInPixels](#2371dfb9) () const  |


## Public Functions Documentation

### _function_ <a id="a4e95e92" href="#a4e95e92">isCreated</a>

```cpp
inline virtual bool isCreated () const 
```



**Overrides:** [isCreated](/doxygen/ffw_GuiFont.md#b7a982fd) from class [GuiFont](/doxygen/ffw_GuiFont.md)

### _function_ <a id="536e36a5" href="#536e36a5">destroy</a>

```cpp
inline virtual void destroy () 
```



**Overrides:** [destroy](/doxygen/ffw_TrueTypeFont.md#334df3a6) from class [TrueTypeFont](/doxygen/ffw_TrueTypeFont.md)

### _function_ <a id="5a79ff54" href="#5a79ff54">getStringSize</a>

```cpp
inline virtual ffw::Vec2f getStringSize (
    const std::string & str,
    float maxWidth,
    float lineHeight = 1.25
) const 
```



**Overrides:** [getStringSize](/doxygen/ffw_GuiFont.md#ba404fac) from class [GuiFont](/doxygen/ffw_GuiFont.md)

### _function_ <a id="494c07f4" href="#494c07f4">getCharAdvance</a>

```cpp
inline virtual float getCharAdvance (
    wchar_t c
) const 
```



**Overrides:** [getCharAdvance](/doxygen/ffw_GuiFont.md#1f5e756b) from class [GuiFont](/doxygen/ffw_GuiFont.md)

### _function_ <a id="2371dfb9" href="#2371dfb9">getSizeInPixels</a>

```cpp
inline virtual int getSizeInPixels () const 
```



**Overrides:** [getSizeInPixels](/doxygen/ffw_GuiFont.md#96e35353) from class [GuiFont](/doxygen/ffw_GuiFont.md)



