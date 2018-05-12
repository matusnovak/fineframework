---
search: false
---

# class ffw::GuiFont



Inherited by the following classes: **[ffw::GuiFontOpenGL](classffw_1_1_gui_font_open_g_l.md)**

## Public Functions

|Type|Name|
|-----|-----|
|virtual bool|[**isCreated**](classffw_1_1_gui_font.md#1af55e6480532d46355a0da6351e7e7e27) () const = 0|
|virtual void|[**destroy**](classffw_1_1_gui_font.md#1a369b27c53668d94f73e99e6d528ef9a4) () = 0|
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSize**](classffw_1_1_gui_font.md#1ac4955cb629df503570e6d22a166c7f1b) (const std::string & str, float maxWidth, float lineHeight = 1.25) const = 0|
|virtual float|[**getCharAdvance**](classffw_1_1_gui_font.md#1a3b91b6c66b8fc115a634970e54145a30) (wchar\_t c) const = 0|
|virtual int|[**getSizeInPixels**](classffw_1_1_gui_font.md#1a93adad7aee3477a606c1f81012db8b46) () const = 0|


## Public Functions Documentation

### function <a id="1af55e6480532d46355a0da6351e7e7e27" href="#1af55e6480532d46355a0da6351e7e7e27">isCreated</a>

```cpp
virtual bool ffw::GuiFont::isCreated () const = 0
```



### function <a id="1a369b27c53668d94f73e99e6d528ef9a4" href="#1a369b27c53668d94f73e99e6d528ef9a4">destroy</a>

```cpp
virtual void ffw::GuiFont::destroy () = 0
```



### function <a id="1ac4955cb629df503570e6d22a166c7f1b" href="#1ac4955cb629df503570e6d22a166c7f1b">getStringSize</a>

```cpp
virtual ffw::Vec2f ffw::GuiFont::getStringSize (
    const std::string & str,
    float maxWidth,
    float lineHeight = 1.25
) const = 0
```



### function <a id="1a3b91b6c66b8fc115a634970e54145a30" href="#1a3b91b6c66b8fc115a634970e54145a30">getCharAdvance</a>

```cpp
virtual float ffw::GuiFont::getCharAdvance (
    wchar_t c
) const = 0
```



### function <a id="1a93adad7aee3477a606c1f81012db8b46" href="#1a93adad7aee3477a606c1f81012db8b46">getSizeInPixels</a>

```cpp
virtual int ffw::GuiFont::getSizeInPixels () const = 0
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guifont.h`
