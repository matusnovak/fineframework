---
search: false
---

# class ffw::GuiStyle::Border

## Public Types

|Type|Name|
|-----|-----|
|typedef **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float >|[**Size**](classffw_1_1_gui_style_1_1_border.md#1abe92204bd0ec9d4fdd011d3e2a5d0da4)|
|typedef **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float >|[**Radius**](classffw_1_1_gui_style_1_1_border.md#1abc22ae131e99e7664fb8c4a7a16fe5c4)|
|typedef **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< **[ffw::Color](structffw_1_1_color.md)** >|[**Color**](classffw_1_1_gui_style_1_1_border.md#1a2572bc34b6910cd4437ca8316f738ecb)|


## Public Attributes

|Type|Name|
|-----|-----|
|**[Size](classffw_1_1_gui_style_1_1_border.md#1abe92204bd0ec9d4fdd011d3e2a5d0da4)**|[**size**](classffw_1_1_gui_style_1_1_border.md#1aeea08fbe69e016be45036d5f8956a0e8)|
|**[Radius](classffw_1_1_gui_style_1_1_border.md#1abc22ae131e99e7664fb8c4a7a16fe5c4)**|[**radius**](classffw_1_1_gui_style_1_1_border.md#1ab7c8bc465898b4523e3b7369b0718d8a)|
|**[Color](classffw_1_1_gui_style_1_1_border.md#1a2572bc34b6910cd4437ca8316f738ecb)**|[**color**](classffw_1_1_gui_style_1_1_border.md#1aeade2cd7aee787cd042d2233cb50227c)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Border**](classffw_1_1_gui_style_1_1_border.md#1a48027a09205fc9da22101542e367da8a) () |
||[**Border**](classffw_1_1_gui_style_1_1_border.md#1a4171b9edd8dadf8c0a1bcf4d005c2fa9) (const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float > & s, const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< float > & r, const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< **[ffw::Color](structffw_1_1_color.md)** > & c) |
||[**operator bool**](classffw_1_1_gui_style_1_1_border.md#1af7162dc6bfde6212718e0d028bbf6ddf) () const |


## Public Types Documentation

### typedef <a id="1abe92204bd0ec9d4fdd011d3e2a5d0da4" href="#1abe92204bd0ec9d4fdd011d3e2a5d0da4">Size</a>

```cpp
typedef Attribute<float> ffw::GuiStyle::Border::Size;
```



### typedef <a id="1abc22ae131e99e7664fb8c4a7a16fe5c4" href="#1abc22ae131e99e7664fb8c4a7a16fe5c4">Radius</a>

```cpp
typedef Attribute<float> ffw::GuiStyle::Border::Radius;
```



### typedef <a id="1a2572bc34b6910cd4437ca8316f738ecb" href="#1a2572bc34b6910cd4437ca8316f738ecb">Color</a>

```cpp
typedef Attribute<ffw::Color> ffw::GuiStyle::Border::Color;
```



## Public Attributes Documentation

### variable <a id="1aeea08fbe69e016be45036d5f8956a0e8" href="#1aeea08fbe69e016be45036d5f8956a0e8">size</a>

```cpp
Size ffw::GuiStyle::Border::size;
```



### variable <a id="1ab7c8bc465898b4523e3b7369b0718d8a" href="#1ab7c8bc465898b4523e3b7369b0718d8a">radius</a>

```cpp
Radius ffw::GuiStyle::Border::radius;
```



### variable <a id="1aeade2cd7aee787cd042d2233cb50227c" href="#1aeade2cd7aee787cd042d2233cb50227c">color</a>

```cpp
Color ffw::GuiStyle::Border::color;
```



## Public Functions Documentation

### function <a id="1a48027a09205fc9da22101542e367da8a" href="#1a48027a09205fc9da22101542e367da8a">Border</a>

```cpp
ffw::GuiStyle::Border::Border ()
```



### function <a id="1a4171b9edd8dadf8c0a1bcf4d005c2fa9" href="#1a4171b9edd8dadf8c0a1bcf4d005c2fa9">Border</a>

```cpp
ffw::GuiStyle::Border::Border (
    const Attribute< float > & s,
    const Attribute< float > & r,
    const Attribute< ffw::Color > & c
)
```



### function <a id="1af7162dc6bfde6212718e0d028bbf6ddf" href="#1af7162dc6bfde6212718e0d028bbf6ddf">operator bool</a>

```cpp
ffw::GuiStyle::Border::operator bool () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guistyle.h`
