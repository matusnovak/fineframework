GuiFont
===================================


**Implemented by:** [ffw::GuiFontOpenGL](ffw_GuiFontOpenGL.html), 

The documentation for this class was generated from: `include/ffw/gui/guifont.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual bool | [isCreated](#b7a982fd) () const = 0  |
|  virtual void | [destroy](#da36910c) () = 0  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#6a839d84) (const std::wstring & _str_, float _lineHeight_ = 1.25) const = 0  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#239d33f2) (const std::string & _str_, float _lineHeight_ = 1.25) const = 0  |
|  virtual float | [getCharAdvance](#1f5e756b) (wchar_t _c_) const = 0  |
|  virtual int | [getSizeInPixels](#96e35353) () const = 0  |


## Public Functions Documentation

### _function_ <a id="b7a982fd" href="#b7a982fd">isCreated</a>

```cpp
virtual bool isCreated () const = 0 
```



### _function_ <a id="da36910c" href="#da36910c">destroy</a>

```cpp
virtual void destroy () = 0 
```



### _function_ <a id="6a839d84" href="#6a839d84">getStringSize</a>

```cpp
virtual ffw::Vec2f getStringSize (
    const std::wstring & str,
    float lineHeight = 1.25
) const = 0 
```



### _function_ <a id="239d33f2" href="#239d33f2">getStringSize</a>

```cpp
virtual ffw::Vec2f getStringSize (
    const std::string & str,
    float lineHeight = 1.25
) const = 0 
```



### _function_ <a id="1f5e756b" href="#1f5e756b">getCharAdvance</a>

```cpp
virtual float getCharAdvance (
    wchar_t c
) const = 0 
```



### _function_ <a id="96e35353" href="#96e35353">getSizeInPixels</a>

```cpp
virtual int getSizeInPixels () const = 0 
```





