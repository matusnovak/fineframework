---
search:
    keywords: ['ffw::GuiStyle::Attribute', 'val', 'Attribute', 'Attribute', 'Attribute', 'Attribute', 'Attribute', 'operator=', 'operator[]', 'operator[]', 'operator==', 'operator!=', 'operator<<']
---

# class ffw::GuiStyle::Attribute

## Public Attributes

|Type|Name|
|-----|-----|
|T|[**val**](classffw_1_1_gui_style_1_1_attribute.md#1abe7fb2d2be5f024398e5c5e4259e8833)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Attribute**](classffw_1_1_gui_style_1_1_attribute.md#1a443ec600321e1e7cba553f1b9ad251f5) () |
||[**Attribute**](classffw_1_1_gui_style_1_1_attribute.md#1aa7940fcec85e9d1665f52b74c3eb22b8) (T v) |
||[**Attribute**](classffw_1_1_gui_style_1_1_attribute.md#1a01962aff54b88d1398b58d3a90111f58) (T top, T right, T bottom, T left) |
||[**Attribute**](classffw_1_1_gui_style_1_1_attribute.md#1a456c2fe1df825a5c34eac719bcf72a2f) (const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)** & other) |
||[**Attribute**](classffw_1_1_gui_style_1_1_attribute.md#1a5c155cf8398785532fd8b88f8f21a0d4) (const std::initializer\_list< float > & list) |
|**[Attribute](classffw_1_1_gui_style_1_1_attribute.md)** &|[**operator=**](classffw_1_1_gui_style_1_1_attribute.md#1a84677fa193c3183734985d40fb90443e) (const T & value) |
|T &|[**operator[]**](classffw_1_1_gui_style_1_1_attribute.md#1a25137c134dc92c41b4c556e2abe5722a) (size\_t i) |
|const T &|[**operator[]**](classffw_1_1_gui_style_1_1_attribute.md#1aa2d7962f8c271386d8cc6ed56f924f53) (size\_t i) const |
|bool|[**operator==**](classffw_1_1_gui_style_1_1_attribute.md#1a6778ec05027c29c15a4725894e054aba) (const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)** & other) const |
|bool|[**operator!=**](classffw_1_1_gui_style_1_1_attribute.md#1a7b86e807b8e3165a75e4d38fff2bb3dd) (const **[Attribute](classffw_1_1_gui_style_1_1_attribute.md)** & other) const |


## Friends

|Type|Name|
|-----|-----|
|friend std::ostream &|[**operator<<**](classffw_1_1_gui_style_1_1_attribute.md#1ae68123214ba0a685f03d19d31c8b3bc1)|


## Public Attributes Documentation

### variable <a id="1abe7fb2d2be5f024398e5c5e4259e8833" href="#1abe7fb2d2be5f024398e5c5e4259e8833">val</a>

```cpp
T ffw::GuiStyle::Attribute< T >::val[4];
```



## Public Functions Documentation

### function <a id="1a443ec600321e1e7cba553f1b9ad251f5" href="#1a443ec600321e1e7cba553f1b9ad251f5">Attribute</a>

```cpp
ffw::GuiStyle::Attribute::Attribute ()
```



### function <a id="1aa7940fcec85e9d1665f52b74c3eb22b8" href="#1aa7940fcec85e9d1665f52b74c3eb22b8">Attribute</a>

```cpp
ffw::GuiStyle::Attribute::Attribute (
    T v
)
```



### function <a id="1a01962aff54b88d1398b58d3a90111f58" href="#1a01962aff54b88d1398b58d3a90111f58">Attribute</a>

```cpp
ffw::GuiStyle::Attribute::Attribute (
    T top
    T right
    T bottom
    T left
)
```



### function <a id="1a456c2fe1df825a5c34eac719bcf72a2f" href="#1a456c2fe1df825a5c34eac719bcf72a2f">Attribute</a>

```cpp
ffw::GuiStyle::Attribute::Attribute (
    const Attribute & other
)
```



### function <a id="1a5c155cf8398785532fd8b88f8f21a0d4" href="#1a5c155cf8398785532fd8b88f8f21a0d4">Attribute</a>

```cpp
ffw::GuiStyle::Attribute::Attribute (
    const std::initializer_list< float > & list
)
```



### function <a id="1a84677fa193c3183734985d40fb90443e" href="#1a84677fa193c3183734985d40fb90443e">operator=</a>

```cpp
Attribute & ffw::GuiStyle::Attribute::operator= (
    const T & value
)
```



### function <a id="1a25137c134dc92c41b4c556e2abe5722a" href="#1a25137c134dc92c41b4c556e2abe5722a">operator[]</a>

```cpp
T & ffw::GuiStyle::Attribute::operator[] (
    size_t i
)
```



### function <a id="1aa2d7962f8c271386d8cc6ed56f924f53" href="#1aa2d7962f8c271386d8cc6ed56f924f53">operator[]</a>

```cpp
const T & ffw::GuiStyle::Attribute::operator[] (
    size_t i
) const
```



### function <a id="1a6778ec05027c29c15a4725894e054aba" href="#1a6778ec05027c29c15a4725894e054aba">operator==</a>

```cpp
bool ffw::GuiStyle::Attribute::operator== (
    const Attribute & other
) const
```



### function <a id="1a7b86e807b8e3165a75e4d38fff2bb3dd" href="#1a7b86e807b8e3165a75e4d38fff2bb3dd">operator!=</a>

```cpp
bool ffw::GuiStyle::Attribute::operator!= (
    const Attribute & other
) const
```



## Friends Documentation

### friend <a id="1ae68123214ba0a685f03d19d31c8b3bc1" href="#1ae68123214ba0a685f03d19d31c8b3bc1">operator<<</a>

```cpp
friend std::ostream & operator<< (
    std::ostream & os
    const Attribute & a
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guistyle.h`
