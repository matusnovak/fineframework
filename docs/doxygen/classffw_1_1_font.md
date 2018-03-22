---
search:
    keywords: ['ffw::Font', 'Char', 'texture', 'vbo', 'sizePoints', 'sizePixels', 'sizeDpi', 'loaded', 'alphaOnlyFlag', 'Font', '~Font', 'destroy', 'getChar', 'getCharIndex', 'getStringSize', 'getStringSize', 'getCharAdvance', 'getSizePt', 'getSizePixels', 'getDpi', 'getTexture', 'getVbo', 'isCreated', 'getCharVerticalOffset', 'isAlphaOnly', 'getStringSizeFunc']
---

# class ffw::Font



Inherited by the following classes: **[ffw::BitmapFont](classffw_1_1_bitmap_font.md)**, **[ffw::TrueTypeFont](classffw_1_1_true_type_font.md)**

## Classes

|Type|Name|
|-----|-----|
|struct|[**Char**](structffw_1_1_font_1_1_char.md)|


## Protected Attributes

|Type|Name|
|-----|-----|
|**[ffw::Texture2D](classffw_1_1_texture2_d.md)**|[**texture**](classffw_1_1_font.md#1a96a1030319180307da5322396d4e8e60)|
|**[ffw::Vbo](classffw_1_1_vbo.md)**|[**vbo**](classffw_1_1_font.md#1aba21fcc25aa3b5c32c0ae29830050d63)|
|int|[**sizePoints**](classffw_1_1_font.md#1aac80550ace3764960015b74adec74b81)|
|int|[**sizePixels**](classffw_1_1_font.md#1a1e5b3dfe80eb10fa1eb57e70c7e21a20)|
|int|[**sizeDpi**](classffw_1_1_font.md#1aaefb97b6ca7379f96004ad65fffe82ca)|
|bool|[**loaded**](classffw_1_1_font.md#1a65171077ae4df6cfb81613fc6ad2fdc0)|
|bool|[**alphaOnlyFlag**](classffw_1_1_font.md#1a2d4f2fd91ed5a903723e31a8a6ef9f98)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Font**](classffw_1_1_font.md#1a61607295e4f95fba5cf189f0bf46e972) () |
|virtual |[**~Font**](classffw_1_1_font.md#1a232e75baded001562f4aa1ba3c270490) () |
|virtual void|[**destroy**](classffw_1_1_font.md#1a7c097bfaf58c965bdd49727bcca734c5) () = 0|
|virtual const **[Char](structffw_1_1_font_1_1_char.md)** &|[**getChar**](classffw_1_1_font.md#1a18f6eba85473c37a0606b91d8601c323) (wchar\_t chr) const = 0|
|virtual int|[**getCharIndex**](classffw_1_1_font.md#1a3f420f3d7a5f7ad6014bb3f08aaa0493) (wchar\_t chr) const = 0|
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSize**](classffw_1_1_font.md#1a954e31facabcb58c18608283156390ee) (const std::string & str, float maxWidth = -1.0f, float lineHeight = 1.25f) const |
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSize**](classffw_1_1_font.md#1a447d1fb84909315000d1d568e2561b86) (const std::wstring & str, float maxWidth = -1.0f, float lineHeight = 1.25f) const |
|float|[**getCharAdvance**](classffw_1_1_font.md#1a2ce2045030c495ace3edaab3c6ea6852) (wchar\_t chr) const |
|int|[**getSizePt**](classffw_1_1_font.md#1a1444b58cd884fcfb51258bebfe44a66c) () const |
|int|[**getSizePixels**](classffw_1_1_font.md#1a546770fa3a6e1f7283aac00b517663bb) () const |
|int|[**getDpi**](classffw_1_1_font.md#1a1a54d225c828f3002d968be8029fe4e7) () const |
|const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \*|[**getTexture**](classffw_1_1_font.md#1a41d4bdf18626cdf0966604f374cb82ca) () const |
|const **[ffw::Vbo](classffw_1_1_vbo.md)** \*|[**getVbo**](classffw_1_1_font.md#1a01e39c0120f78fd4d02a23b5cf3be8f3) () const |
|bool|[**isCreated**](classffw_1_1_font.md#1a2acdf7da8b48924b2217b63cc9938159) () const |
|float|[**getCharVerticalOffset**](classffw_1_1_font.md#1a7a3dbb693585c2d93d250825d54b39ce) (const **[Font::Char](structffw_1_1_font_1_1_char.md)** & data) const |
|bool|[**isAlphaOnly**](classffw_1_1_font.md#1a6d9a0f5530f479c867b7551feb237dd1) () const |


## Protected Functions

|Type|Name|
|-----|-----|
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSizeFunc**](classffw_1_1_font.md#1a3508a473bb23d35064d8e8f18df8a438) (const std::basic\_string< T > & str, float maxWidth = -1.0f, float lineHeight = 1.25f) const |


## Protected Attributes Documentation

### variable <a id="1a96a1030319180307da5322396d4e8e60" href="#1a96a1030319180307da5322396d4e8e60">texture</a>

```cpp
ffw::Texture2D ffw::Font::texture;
```



### variable <a id="1aba21fcc25aa3b5c32c0ae29830050d63" href="#1aba21fcc25aa3b5c32c0ae29830050d63">vbo</a>

```cpp
ffw::Vbo ffw::Font::vbo;
```



### variable <a id="1aac80550ace3764960015b74adec74b81" href="#1aac80550ace3764960015b74adec74b81">sizePoints</a>

```cpp
int ffw::Font::sizePoints;
```



### variable <a id="1a1e5b3dfe80eb10fa1eb57e70c7e21a20" href="#1a1e5b3dfe80eb10fa1eb57e70c7e21a20">sizePixels</a>

```cpp
int ffw::Font::sizePixels;
```



### variable <a id="1aaefb97b6ca7379f96004ad65fffe82ca" href="#1aaefb97b6ca7379f96004ad65fffe82ca">sizeDpi</a>

```cpp
int ffw::Font::sizeDpi;
```



### variable <a id="1a65171077ae4df6cfb81613fc6ad2fdc0" href="#1a65171077ae4df6cfb81613fc6ad2fdc0">loaded</a>

```cpp
bool ffw::Font::loaded;
```



### variable <a id="1a2d4f2fd91ed5a903723e31a8a6ef9f98" href="#1a2d4f2fd91ed5a903723e31a8a6ef9f98">alphaOnlyFlag</a>

```cpp
bool ffw::Font::alphaOnlyFlag;
```



## Public Functions Documentation

### function <a id="1a61607295e4f95fba5cf189f0bf46e972" href="#1a61607295e4f95fba5cf189f0bf46e972">Font</a>

```cpp
ffw::Font::Font ()
```



### function <a id="1a232e75baded001562f4aa1ba3c270490" href="#1a232e75baded001562f4aa1ba3c270490">~Font</a>

```cpp
virtual ffw::Font::~Font ()
```



### function <a id="1a7c097bfaf58c965bdd49727bcca734c5" href="#1a7c097bfaf58c965bdd49727bcca734c5">destroy</a>

```cpp
virtual void ffw::Font::destroy () = 0
```



### function <a id="1a18f6eba85473c37a0606b91d8601c323" href="#1a18f6eba85473c37a0606b91d8601c323">getChar</a>

```cpp
virtual const Char & ffw::Font::getChar (
    wchar_t chr
) const = 0
```



### function <a id="1a3f420f3d7a5f7ad6014bb3f08aaa0493" href="#1a3f420f3d7a5f7ad6014bb3f08aaa0493">getCharIndex</a>

```cpp
virtual int ffw::Font::getCharIndex (
    wchar_t chr
) const = 0
```



### function <a id="1a954e31facabcb58c18608283156390ee" href="#1a954e31facabcb58c18608283156390ee">getStringSize</a>

```cpp
virtual ffw::Vec2f ffw::Font::getStringSize (
    const std::string & str
    float maxWidth = -1.0f
    float lineHeight = 1.25f
) const
```



### function <a id="1a447d1fb84909315000d1d568e2561b86" href="#1a447d1fb84909315000d1d568e2561b86">getStringSize</a>

```cpp
virtual ffw::Vec2f ffw::Font::getStringSize (
    const std::wstring & str
    float maxWidth = -1.0f
    float lineHeight = 1.25f
) const
```



### function <a id="1a2ce2045030c495ace3edaab3c6ea6852" href="#1a2ce2045030c495ace3edaab3c6ea6852">getCharAdvance</a>

```cpp
float ffw::Font::getCharAdvance (
    wchar_t chr
) const
```



### function <a id="1a1444b58cd884fcfb51258bebfe44a66c" href="#1a1444b58cd884fcfb51258bebfe44a66c">getSizePt</a>

```cpp
int ffw::Font::getSizePt () const
```



### function <a id="1a546770fa3a6e1f7283aac00b517663bb" href="#1a546770fa3a6e1f7283aac00b517663bb">getSizePixels</a>

```cpp
int ffw::Font::getSizePixels () const
```



### function <a id="1a1a54d225c828f3002d968be8029fe4e7" href="#1a1a54d225c828f3002d968be8029fe4e7">getDpi</a>

```cpp
int ffw::Font::getDpi () const
```



### function <a id="1a41d4bdf18626cdf0966604f374cb82ca" href="#1a41d4bdf18626cdf0966604f374cb82ca">getTexture</a>

```cpp
const ffw::Texture2D * ffw::Font::getTexture () const
```



### function <a id="1a01e39c0120f78fd4d02a23b5cf3be8f3" href="#1a01e39c0120f78fd4d02a23b5cf3be8f3">getVbo</a>

```cpp
const ffw::Vbo * ffw::Font::getVbo () const
```



### function <a id="1a2acdf7da8b48924b2217b63cc9938159" href="#1a2acdf7da8b48924b2217b63cc9938159">isCreated</a>

```cpp
bool ffw::Font::isCreated () const
```



### function <a id="1a7a3dbb693585c2d93d250825d54b39ce" href="#1a7a3dbb693585c2d93d250825d54b39ce">getCharVerticalOffset</a>

```cpp
float ffw::Font::getCharVerticalOffset (
    const Font::Char & data
) const
```



### function <a id="1a6d9a0f5530f479c867b7551feb237dd1" href="#1a6d9a0f5530f479c867b7551feb237dd1">isAlphaOnly</a>

```cpp
bool ffw::Font::isAlphaOnly () const
```



## Protected Functions Documentation

### function <a id="1a3508a473bb23d35064d8e8f18df8a438" href="#1a3508a473bb23d35064d8e8f18df8a438">getStringSizeFunc</a>

```cpp
ffw::Vec2f ffw::Font::getStringSizeFunc (
    const std::basic_string< T > & str
    float maxWidth = -1.0f
    float lineHeight = 1.25f
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/font.h`
