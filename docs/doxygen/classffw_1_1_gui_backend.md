---
search:
    keywords: ['ffw::GuiBackend', 'resize', 'startRender', 'endRender', 'setScissors', 'clearWithColor', 'drawRectangle', 'drawRectangleRounded', 'drawLine', 'drawCircle', 'drawArc', 'drawQuad', 'drawString', 'drawTriangle', 'drawImage', 'drawBackground', 'drawBorder', 'drawStringAligned']
---

# class ffw::GuiBackend



Inherited by the following classes: **[ffw::GuiWindow](classffw_1_1_gui_window.md)**

## Public Functions

|Type|Name|
|-----|-----|
|virtual void|[**resize**](classffw_1_1_gui_backend.md#1af2497bddcba3d8ff994bbfe2ad4e5e10) (int width, int height) = 0|
|virtual void|[**startRender**](classffw_1_1_gui_backend.md#1a7a10d3b391690aced9ff03b553d94a44) () = 0|
|virtual void|[**endRender**](classffw_1_1_gui_backend.md#1a26d844c1babfeadc631dc45df723dc37) () = 0|
|virtual void|[**setScissors**](classffw_1_1_gui_backend.md#1aa835cc230789a8458487295a98022df6) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size) const = 0|
|virtual void|[**clearWithColor**](classffw_1_1_gui_backend.md#1a4f3ce651bfa2ed17b43f018b6d96362d) (const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawRectangle**](classffw_1_1_gui_backend.md#1ac0e6c85a64919688c98921078db355c7) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawRectangleRounded**](classffw_1_1_gui_backend.md#1aa38eea352be83acdb80c82f3a4f04167) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::Color](structffw_1_1_color.md)** & color, float tl, float tr, float br, float bl) const = 0|
|virtual void|[**drawLine**](classffw_1_1_gui_backend.md#1a35a502ee6bfc87ce536e0607e74ef864) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & start, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & end, const **[ffw::Color](structffw_1_1_color.md)** & color, float width = 1.0f) const = 0|
|virtual void|[**drawCircle**](classffw_1_1_gui_backend.md#1a5f9716be2ca6c0c5dc9dd12bf97c105c) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, float radius, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawArc**](classffw_1_1_gui_backend.md#1a0972ad84af1761a984a21d19ebb152d2) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, float inner, float outer, float start, float end, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawQuad**](classffw_1_1_gui_backend.md#1a085e50da7e2417c71706a69098fbed0f) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p0, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p1, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p2, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p3, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawString**](classffw_1_1_gui_backend.md#1a4131f21a340d055f3b44ab4b8f45fe73) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, const std::string::value\_type \* str, size\_t length, const **[ffw::Color](structffw_1_1_color.md)** & color, float lineHeight = 1.25f) const = 0|
|virtual void|[**drawTriangle**](classffw_1_1_gui_backend.md#1a8c4e05f163ca039a822268e6210fa413) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p0, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p1, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p2, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawImage**](classffw_1_1_gui_backend.md#1acacdb5a3d602c0ff919a9e87f65d3aa9) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[GuiImage](classffw_1_1_gui_image.md)** \* image, const **[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)** & sub, bool mirrorX, bool mirrorY, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawBackground**](classffw_1_1_gui_backend.md#1a2263692d05a3ac835df270d8f9667e83) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle::Background](classffw_1_1_gui_style_1_1_background.md)** & background, bool ignore = false) const = 0|
|virtual void|[**drawBorder**](classffw_1_1_gui_backend.md#1ac27fbd05605bf02fb28140af882b5934) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle::Border](classffw_1_1_gui_style_1_1_border.md)** & border) const = 0|
|virtual void|[**drawStringAligned**](classffw_1_1_gui_backend.md#1a2866be02e4afb2b1e1ac529ff4ca4f54) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, **[ffw::GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** align, const std::string & str, const **[ffw::GuiStyle::Text](classffw_1_1_gui_style_1_1_text.md)** & text, float lineHeight = 1.25f) const |


## Public Functions Documentation

### function <a id="1af2497bddcba3d8ff994bbfe2ad4e5e10" href="#1af2497bddcba3d8ff994bbfe2ad4e5e10">resize</a>

```cpp
virtual void ffw::GuiBackend::resize (
    int width
    int height
) = 0
```



### function <a id="1a7a10d3b391690aced9ff03b553d94a44" href="#1a7a10d3b391690aced9ff03b553d94a44">startRender</a>

```cpp
virtual void ffw::GuiBackend::startRender () = 0
```



### function <a id="1a26d844c1babfeadc631dc45df723dc37" href="#1a26d844c1babfeadc631dc45df723dc37">endRender</a>

```cpp
virtual void ffw::GuiBackend::endRender () = 0
```



### function <a id="1aa835cc230789a8458487295a98022df6" href="#1aa835cc230789a8458487295a98022df6">setScissors</a>

```cpp
virtual void ffw::GuiBackend::setScissors (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
) const = 0
```



### function <a id="1a4f3ce651bfa2ed17b43f018b6d96362d" href="#1a4f3ce651bfa2ed17b43f018b6d96362d">clearWithColor</a>

```cpp
virtual void ffw::GuiBackend::clearWithColor (
    const ffw::Color & color
) const = 0
```



### function <a id="1ac0e6c85a64919688c98921078db355c7" href="#1ac0e6c85a64919688c98921078db355c7">drawRectangle</a>

```cpp
virtual void ffw::GuiBackend::drawRectangle (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::Color & color
) const = 0
```



### function <a id="1aa38eea352be83acdb80c82f3a4f04167" href="#1aa38eea352be83acdb80c82f3a4f04167">drawRectangleRounded</a>

```cpp
virtual void ffw::GuiBackend::drawRectangleRounded (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::Color & color
    float tl
    float tr
    float br
    float bl
) const = 0
```



### function <a id="1a35a502ee6bfc87ce536e0607e74ef864" href="#1a35a502ee6bfc87ce536e0607e74ef864">drawLine</a>

```cpp
virtual void ffw::GuiBackend::drawLine (
    const ffw::Vec2f & start
    const ffw::Vec2f & end
    const ffw::Color & color
    float width = 1.0f
) const = 0
```



### function <a id="1a5f9716be2ca6c0c5dc9dd12bf97c105c" href="#1a5f9716be2ca6c0c5dc9dd12bf97c105c">drawCircle</a>

```cpp
virtual void ffw::GuiBackend::drawCircle (
    const ffw::Vec2f & pos
    float radius
    const ffw::Color & color
) const = 0
```



### function <a id="1a0972ad84af1761a984a21d19ebb152d2" href="#1a0972ad84af1761a984a21d19ebb152d2">drawArc</a>

```cpp
virtual void ffw::GuiBackend::drawArc (
    const ffw::Vec2f & pos
    float inner
    float outer
    float start
    float end
    const ffw::Color & color
) const = 0
```



### function <a id="1a085e50da7e2417c71706a69098fbed0f" href="#1a085e50da7e2417c71706a69098fbed0f">drawQuad</a>

```cpp
virtual void ffw::GuiBackend::drawQuad (
    const ffw::Vec2f & p0
    const ffw::Vec2f & p1
    const ffw::Vec2f & p2
    const ffw::Vec2f & p3
    const ffw::Color & color
) const = 0
```



### function <a id="1a4131f21a340d055f3b44ab4b8f45fe73" href="#1a4131f21a340d055f3b44ab4b8f45fe73">drawString</a>

```cpp
virtual void ffw::GuiBackend::drawString (
    const ffw::Vec2f & pos
    const ffw::GuiFont * font
    const std::string::value_type * str
    size_t length
    const ffw::Color & color
    float lineHeight = 1.25f
) const = 0
```



### function <a id="1a8c4e05f163ca039a822268e6210fa413" href="#1a8c4e05f163ca039a822268e6210fa413">drawTriangle</a>

```cpp
virtual void ffw::GuiBackend::drawTriangle (
    const ffw::Vec2f & p0
    const ffw::Vec2f & p1
    const ffw::Vec2f & p2
    const ffw::Color & color
) const = 0
```



### function <a id="1acacdb5a3d602c0ff919a9e87f65d3aa9" href="#1acacdb5a3d602c0ff919a9e87f65d3aa9">drawImage</a>

```cpp
virtual void ffw::GuiBackend::drawImage (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const GuiImage * image
    const ffw::Vec4i & sub
    bool mirrorX
    bool mirrorY
    const ffw::Color & color
) const = 0
```



### function <a id="1a2263692d05a3ac835df270d8f9667e83" href="#1a2263692d05a3ac835df270d8f9667e83">drawBackground</a>

```cpp
virtual void ffw::GuiBackend::drawBackground (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::GuiStyle::Background & background
    bool ignore = false
) const = 0
```



### function <a id="1ac27fbd05605bf02fb28140af882b5934" href="#1ac27fbd05605bf02fb28140af882b5934">drawBorder</a>

```cpp
virtual void ffw::GuiBackend::drawBorder (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::GuiStyle::Border & border
) const = 0
```



### function <a id="1a2866be02e4afb2b1e1ac529ff4ca4f54" href="#1a2866be02e4afb2b1e1ac529ff4ca4f54">drawStringAligned</a>

```cpp
virtual void ffw::GuiBackend::drawStringAligned (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::GuiFont * font
    ffw::GuiAlign align
    const std::string & str
    const ffw::GuiStyle::Text & text
    float lineHeight = 1.25f
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guibackend.h`
