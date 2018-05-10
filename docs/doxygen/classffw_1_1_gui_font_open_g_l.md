---
search: false
---

# class ffw::GuiFontOpenGL



Inherits the following classes: **[ffw::GuiFont](classffw_1_1_gui_font.md)**, **[ffw::TrueTypeFont](classffw_1_1_true_type_font.md)**

## Public Functions

|Type|Name|
|-----|-----|
|virtual bool|[**isCreated**](classffw_1_1_gui_font_open_g_l.md#1ab0ea35993ccfd3547145918453dd7c02) () override const |
|virtual void|[**destroy**](classffw_1_1_gui_font_open_g_l.md#1a69e5a193b921c81902cd6458e4b5be65) () override |
|virtual **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)**|[**getStringSize**](classffw_1_1_gui_font_open_g_l.md#1af080b882f313368580d4ccdaddd5eda2) (const std::string & str, float maxWidth, float lineHeight = 1.25) override const |
|virtual float|[**getCharAdvance**](classffw_1_1_gui_font_open_g_l.md#1aad1aea06a7039a8e9afe3c79b3b01354) (wchar\_t c) override const |
|virtual int|[**getSizeInPixels**](classffw_1_1_gui_font_open_g_l.md#1acb253cd4bc64858adfb0aaf28c39d904) () override const |


#### Public Functions inherited from [ffw::TrueTypeFont](classffw_1_1_true_type_font.md)

|Type|Name|
|-----|-----|
||[**TrueTypeFont**](classffw_1_1_true_type_font.md#1a9639e40abe8941382c95a926f4e4976e) () |
||[**TrueTypeFont**](classffw_1_1_true_type_font.md#1a9f77af27f585ae8112e3f694ec056981) (const **[TrueTypeFont](classffw_1_1_true_type_font.md)** & other) = delete |
||[**TrueTypeFont**](classffw_1_1_true_type_font.md#1ab2eb52bb1fa064a72b8150078a30632d) (**[TrueTypeFont](classffw_1_1_true_type_font.md)** && other) |
|virtual |[**~TrueTypeFont**](classffw_1_1_true_type_font.md#1a8ead1e22271b4c2f5f3d4a6f6c3e905f) () |
|bool|[**createFromData**](classffw_1_1_true_type_font.md#1ab8c1de804c19c76659c7feb343ec3dcb) (const unsigned char \* buffer, size\_t length, int points, int dpi, int start = 0x00, int end = 0x7F) |
|bool|[**createFromFile**](classffw_1_1_true_type_font.md#1a730593a7fc8c49f24b4569b5bdaf537d) (const std::string & path, int points, int dpi, int start = 0x00, int end = 0x7F) |
|void|[**destroy**](classffw_1_1_true_type_font.md#1a11d8c26d7b1a363a2a19bffc333bfb96) () |
|virtual const Char &|[**getChar**](classffw_1_1_true_type_font.md#1a8abb44942dbaa86a6f335892e5e8b131) (unsigned int chr) override const |
|virtual int|[**getCharIndex**](classffw_1_1_true_type_font.md#1a27409a8751badfe444a58bf1fd98d6b6) (unsigned int chr) override const |
|**[TrueTypeFont](classffw_1_1_true_type_font.md)** &|[**operator=**](classffw_1_1_true_type_font.md#1ab70f5f87c8361a556e63b6add22f6242) (const **[TrueTypeFont](classffw_1_1_true_type_font.md)** & other) = delete |
|**[TrueTypeFont](classffw_1_1_true_type_font.md)** &|[**operator=**](classffw_1_1_true_type_font.md#1a9416bb2b0185110752b030f12f8d4f51) (**[TrueTypeFont](classffw_1_1_true_type_font.md)** && other) |
|void|[**swap**](classffw_1_1_true_type_font.md#1a59cd6a95a18ed791e95a7e601fb9d79a) (**[TrueTypeFont](classffw_1_1_true_type_font.md)** & other) |


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

### function <a id="1ab0ea35993ccfd3547145918453dd7c02" href="#1ab0ea35993ccfd3547145918453dd7c02">isCreated</a>

```cpp
virtual bool ffw::GuiFontOpenGL::isCreated () const
```

Overrides **[GuiFont::isCreated](classffw_1_1_gui_font.md#1af55e6480532d46355a0da6351e7e7e27)**


### function <a id="1a69e5a193b921c81902cd6458e4b5be65" href="#1a69e5a193b921c81902cd6458e4b5be65">destroy</a>

```cpp
virtual void ffw::GuiFontOpenGL::destroy ()
```

Overrides **[GuiFont::destroy](classffw_1_1_gui_font.md#1a369b27c53668d94f73e99e6d528ef9a4)**


### function <a id="1af080b882f313368580d4ccdaddd5eda2" href="#1af080b882f313368580d4ccdaddd5eda2">getStringSize</a>

```cpp
virtual ffw::Vec2f ffw::GuiFontOpenGL::getStringSize (
    const std::string & str
    float maxWidth
    float lineHeight = 1.25
) const
```

Overrides **[GuiFont::getStringSize](classffw_1_1_gui_font.md#1ac4955cb629df503570e6d22a166c7f1b)**


### function <a id="1aad1aea06a7039a8e9afe3c79b3b01354" href="#1aad1aea06a7039a8e9afe3c79b3b01354">getCharAdvance</a>

```cpp
virtual float ffw::GuiFontOpenGL::getCharAdvance (
    wchar_t c
) const
```

Overrides **[GuiFont::getCharAdvance](classffw_1_1_gui_font.md#1a3b91b6c66b8fc115a634970e54145a30)**


### function <a id="1acb253cd4bc64858adfb0aaf28c39d904" href="#1acb253cd4bc64858adfb0aaf28c39d904">getSizeInPixels</a>

```cpp
virtual int ffw::GuiFontOpenGL::getSizeInPixels () const
```

Overrides **[GuiFont::getSizeInPixels](classffw_1_1_gui_font.md#1a93adad7aee3477a606c1f81012db8b46)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guifontopengl.h`
