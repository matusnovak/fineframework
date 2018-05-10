---
search: false
---

# class ffw::BitmapFont



Inherits the following classes: **[ffw::Font](classffw_1_1_font.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**BitmapFont**](classffw_1_1_bitmap_font.md#1ad0907f3ba510c9e515dfa636c7f1d4ad) () |
||[**BitmapFont**](classffw_1_1_bitmap_font.md#1a4d41c66bfb70dc247ec709471836e0f9) (const **[BitmapFont](classffw_1_1_bitmap_font.md)** & other) = delete |
||[**BitmapFont**](classffw_1_1_bitmap_font.md#1a98008c5f211aeb6c9a374fca15576f62) (**[BitmapFont](classffw_1_1_bitmap_font.md)** && other) |
|virtual |[**~BitmapFont**](classffw_1_1_bitmap_font.md#1a3fc686a3f4f3c33ce58a87cae5bd80a1) () |
|bool|[**createFromData**](classffw_1_1_bitmap_font.md#1af55375606c317f92f4423dd18f9c307d) (const void \* pixels, int width, int height, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** format, int points, int dpi, int start = 0x00, int end = 0x7F) <br>Creates a bitmap font from raw pixels of data. |
|bool|[**createFromBuffer**](classffw_1_1_bitmap_font.md#1a811b27e1ebce4ec73cb3b0449ecc51f0) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & buffer, int points, int dpi, int start = 0x00, int end = 0x7F) <br>Creates a bitmap font from raw pixels using **[ImageBuffer](classffw_1_1_image_buffer.md)**. |
|void|[**destroy**](classffw_1_1_bitmap_font.md#1a5094d5e65e0fda707ff6b17f1381662e) () <br>Releases all resources. |
|virtual const **[Font::Char](structffw_1_1_font_1_1_char.md)** &|[**getChar**](classffw_1_1_bitmap_font.md#1a0785ff6eee3e85c5501e5c85df74f72a) (unsigned int chr) override const |
|virtual int|[**getCharIndex**](classffw_1_1_bitmap_font.md#1ab897a764b7b18180a24f8e1cae0931ed) (unsigned int chr) override const |
|void|[**setCharData**](classffw_1_1_bitmap_font.md#1a14884030d06c4d5a184b849363715ef6) (unsigned int chr, const **[Font::Char](structffw_1_1_font_1_1_char.md)** & data) |
|bool|[**updateBuffer**](classffw_1_1_bitmap_font.md#1a00aa0bda3fa051d03e4828fb8cff941c) () |
|**[BitmapFont](classffw_1_1_bitmap_font.md)** &|[**operator=**](classffw_1_1_bitmap_font.md#1a2ec5a588263487c8300501c6d3ae7d04) (const **[BitmapFont](classffw_1_1_bitmap_font.md)** & other) = delete |
|**[BitmapFont](classffw_1_1_bitmap_font.md)** &|[**operator=**](classffw_1_1_bitmap_font.md#1a42dfd5bfbdd748aa381db7f7e2fd3d1b) (**[BitmapFont](classffw_1_1_bitmap_font.md)** && other) |
|void|[**swap**](classffw_1_1_bitmap_font.md#1a8d4c1e075a9a23b6b79f1d135a2a3d05) (**[BitmapFont](classffw_1_1_bitmap_font.md)** & other) |


#### Public Functions inherited from [ffw::Font](classffw_1_1_font.md)

|Type|Name|
|-----|-----|
||[**Font**](classffw_1_1_font.md#1a61607295e4f95fba5cf189f0bf46e972) () |
||[**Font**](classffw_1_1_font.md#1a625968999be1f55607ba2c241e99c2bb) (const **[Font](classffw_1_1_font.md)** & other) = delete |
||[**Font**](classffw_1_1_font.md#1a7b07abd846095b2b3211e1d1e41775c5) (**[Font](classffw_1_1_font.md)** && other) = default |
|**[Font](classffw_1_1_font.md)** &|[**operator=**](classffw_1_1_font.md#1a1506af1c9de421dac45dad7a9d1b0e26) (const **[Font](classffw_1_1_font.md)** & other) = delete |
|**[Font](classffw_1_1_font.md)** &|[**operator=**](classffw_1_1_font.md#1adc829453376092c01873ccf869e3b905) (**[Font](classffw_1_1_font.md)** && other) = default |
|virtual |[**~Font**](classffw_1_1_font.md#1af64aa991e6e53e3b55105a2eb0239ea4) () = default |
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSize**](classffw_1_1_font.md#1a954e31facabcb58c18608283156390ee) (const std::string & str, float maxWidth = -1.0f, float lineHeight = 1.25f) const |
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSize**](classffw_1_1_font.md#1a447d1fb84909315000d1d568e2561b86) (const std::wstring & str, float maxWidth = -1.0f, float lineHeight = 1.25f) const |
|float|[**getCharAdvance**](classffw_1_1_font.md#1ab41de9dad062dd9c58ddc360c8acc32b) (const unsigned int chr) const |
|int|[**getSizePt**](classffw_1_1_font.md#1a1444b58cd884fcfb51258bebfe44a66c) () const |
|int|[**getSizePixels**](classffw_1_1_font.md#1a546770fa3a6e1f7283aac00b517663bb) () const |
|int|[**getDpi**](classffw_1_1_font.md#1a1a54d225c828f3002d968be8029fe4e7) () const |
|const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \*|[**getTexture**](classffw_1_1_font.md#1a41d4bdf18626cdf0966604f374cb82ca) () const |
|const **[ffw::Vbo](classffw_1_1_vbo.md)** \*|[**getVbo**](classffw_1_1_font.md#1a01e39c0120f78fd4d02a23b5cf3be8f3) () const |
|bool|[**isCreated**](classffw_1_1_font.md#1a2acdf7da8b48924b2217b63cc9938159) () const |
|float|[**getCharVerticalOffset**](classffw_1_1_font.md#1a7a3dbb693585c2d93d250825d54b39ce) (const **[Font::Char](structffw_1_1_font_1_1_char.md)** & data) const |
|bool|[**isAlphaOnly**](classffw_1_1_font.md#1a6d9a0f5530f479c867b7551feb237dd1) () const |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::Font](classffw_1_1_font.md)

|Type|Name|
|-----|-----|
|**[ffw::Texture2D](classffw_1_1_texture2_d.md)**|[**texture**](classffw_1_1_font.md#1a96a1030319180307da5322396d4e8e60)|
|**[ffw::Vbo](classffw_1_1_vbo.md)**|[**vbo**](classffw_1_1_font.md#1aba21fcc25aa3b5c32c0ae29830050d63)|
|int|[**sizePoints**](classffw_1_1_font.md#1aac80550ace3764960015b74adec74b81)|
|int|[**sizePixels**](classffw_1_1_font.md#1a1e5b3dfe80eb10fa1eb57e70c7e21a20)|
|int|[**sizeDpi**](classffw_1_1_font.md#1aaefb97b6ca7379f96004ad65fffe82ca)|
|bool|[**loaded**](classffw_1_1_font.md#1a65171077ae4df6cfb81613fc6ad2fdc0)|
|bool|[**alphaOnlyFlag**](classffw_1_1_font.md#1a2d4f2fd91ed5a903723e31a8a6ef9f98)|


#### Protected Functions inherited from [ffw::Font](classffw_1_1_font.md)

|Type|Name|
|-----|-----|
|**[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSizeFunc**](classffw_1_1_font.md#1a3508a473bb23d35064d8e8f18df8a438) (const std::basic\_string< T > & str, float maxWidth = -1.0f, float lineHeight = 1.25f) const |


## Public Functions Documentation

### function <a id="1ad0907f3ba510c9e515dfa636c7f1d4ad" href="#1ad0907f3ba510c9e515dfa636c7f1d4ad">BitmapFont</a>

```cpp
ffw::BitmapFont::BitmapFont ()
```



### function <a id="1a4d41c66bfb70dc247ec709471836e0f9" href="#1a4d41c66bfb70dc247ec709471836e0f9">BitmapFont</a>

```cpp
ffw::BitmapFont::BitmapFont (
    const BitmapFont & other
) = delete
```



### function <a id="1a98008c5f211aeb6c9a374fca15576f62" href="#1a98008c5f211aeb6c9a374fca15576f62">BitmapFont</a>

```cpp
ffw::BitmapFont::BitmapFont (
    BitmapFont && other
)
```



### function <a id="1a3fc686a3f4f3c33ce58a87cae5bd80a1" href="#1a3fc686a3f4f3c33ce58a87cae5bd80a1">~BitmapFont</a>

```cpp
virtual ffw::BitmapFont::~BitmapFont ()
```



### function <a id="1af55375606c317f92f4423dd18f9c307d" href="#1af55375606c317f92f4423dd18f9c307d">createFromData</a>

```cpp
bool ffw::BitmapFont::createFromData (
    const void * pixels
    int width
    int height
    ffw::ImageType format
    int points
    int dpi
    int start = 0x00
    int end = 0x7F
)
```

Creates a bitmap font from raw pixels of data. 


### function <a id="1a811b27e1ebce4ec73cb3b0449ecc51f0" href="#1a811b27e1ebce4ec73cb3b0449ecc51f0">createFromBuffer</a>

```cpp
bool ffw::BitmapFont::createFromBuffer (
    const ImageBuffer & buffer
    int points
    int dpi
    int start = 0x00
    int end = 0x7F
)
```

Creates a bitmap font from raw pixels using **[ImageBuffer](classffw_1_1_image_buffer.md)**. 


### function <a id="1a5094d5e65e0fda707ff6b17f1381662e" href="#1a5094d5e65e0fda707ff6b17f1381662e">destroy</a>

```cpp
void ffw::BitmapFont::destroy ()
```

Releases all resources. 


### function <a id="1a0785ff6eee3e85c5501e5c85df74f72a" href="#1a0785ff6eee3e85c5501e5c85df74f72a">getChar</a>

```cpp
virtual const Font::Char & ffw::BitmapFont::getChar (
    unsigned int chr
) const
```

Overrides **[Font::getChar](classffw_1_1_font.md#1ac377ea34f700ab2c2281e66a93610a75)**


### function <a id="1ab897a764b7b18180a24f8e1cae0931ed" href="#1ab897a764b7b18180a24f8e1cae0931ed">getCharIndex</a>

```cpp
virtual int ffw::BitmapFont::getCharIndex (
    unsigned int chr
) const
```

Overrides **[Font::getCharIndex](classffw_1_1_font.md#1ac41292d33971a660fe9bed10ea39504e)**


### function <a id="1a14884030d06c4d5a184b849363715ef6" href="#1a14884030d06c4d5a184b849363715ef6">setCharData</a>

```cpp
void ffw::BitmapFont::setCharData (
    unsigned int chr
    const Font::Char & data
)
```



### function <a id="1a00aa0bda3fa051d03e4828fb8cff941c" href="#1a00aa0bda3fa051d03e4828fb8cff941c">updateBuffer</a>

```cpp
bool ffw::BitmapFont::updateBuffer ()
```



### function <a id="1a2ec5a588263487c8300501c6d3ae7d04" href="#1a2ec5a588263487c8300501c6d3ae7d04">operator=</a>

```cpp
BitmapFont & ffw::BitmapFont::operator= (
    const BitmapFont & other
) = delete
```



### function <a id="1a42dfd5bfbdd748aa381db7f7e2fd3d1b" href="#1a42dfd5bfbdd748aa381db7f7e2fd3d1b">operator=</a>

```cpp
BitmapFont & ffw::BitmapFont::operator= (
    BitmapFont && other
)
```



### function <a id="1a8d4c1e075a9a23b6b79f1d135a2a3d05" href="#1a8d4c1e075a9a23b6b79f1d135a2a3d05">swap</a>

```cpp
void ffw::BitmapFont::swap (
    BitmapFont & other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/bitmapfont.h`
