GuiFontOpenGL
===================================


**Inherits from:** [ffw::GuiFont](ffw_GuiFont.html), [ffw::TrueTypeFont](ffw_TrueTypeFont.html)

The documentation for this class was generated from: `include/ffw/gui/guifontopengl.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual bool | [isCreated](#a4e95e92) () const  |
|  virtual void | [destroy](#536e36a5) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#9aa95559) (const std::wstring & _str_, float _lineHeight_ = 1.25) const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#2483ef1f) (const std::string & _str_, float _lineHeight_ = 1.25) const  |
|  virtual float | [getCharAdvance](#494c07f4) (wchar_t _c_) const  |
|  virtual int | [getSizeInPixels](#2371dfb9) () const  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="a4e95e92" href="#a4e95e92">isCreated</a>

```cpp
inline virtual bool isCreated () const 
```



### <span style="opacity:0.5;">function</span> <a id="536e36a5" href="#536e36a5">destroy</a>

```cpp
inline virtual void destroy () 
```



### <span style="opacity:0.5;">function</span> <a id="9aa95559" href="#9aa95559">getStringSize</a>

```cpp
inline virtual ffw::Vec2f getStringSize (
    const std::wstring & str,
    float lineHeight = 1.25
) const 
```



### <span style="opacity:0.5;">function</span> <a id="2483ef1f" href="#2483ef1f">getStringSize</a>

```cpp
inline virtual ffw::Vec2f getStringSize (
    const std::string & str,
    float lineHeight = 1.25
) const 
```



### <span style="opacity:0.5;">function</span> <a id="494c07f4" href="#494c07f4">getCharAdvance</a>

```cpp
inline virtual float getCharAdvance (
    wchar_t c
) const 
```



### <span style="opacity:0.5;">function</span> <a id="2371dfb9" href="#2371dfb9">getSizeInPixels</a>

```cpp
inline virtual int getSizeInPixels () const 
```





