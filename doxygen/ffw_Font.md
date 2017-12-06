Font
===================================


**Implemented by:** [ffw::BitmapFont](ffw_BitmapFont.html), [ffw::TrueTypeFont](ffw_TrueTypeFont.html), 

The documentation for this class was generated from: `include/ffw/graphics/font.h`



## Classes

| Name |
|:-----|
| struct [ffw::Font::Char](ffw_Font_Char.html) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  [ffw::Texture2D](ffw_Texture2D.html) | [texture](#e7cda937) |
|  int | [sizePoints](#db4ac3b4) |
|  int | [sizePixels](#f4da172b) |
|  int | [sizeDpi](#a1399e72) |
|  bool | [loaded](#e776a077) |
|  bool | [alphaOnlyFlag](#6966e978) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Font](#7774a231) ()  |
|  virtual  | [~Font](#b5601d30) ()  |
|  virtual void | [destroy](#ad63e5d2) () = 0  |
|  virtual const [Char](ffw_Font_Char.html) & | [getChar](#d843f542) (wchar_t _chr_) const = 0  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#9dcbaeb3) (const std::string & _str_, float _lineHeight_ = 1.25f) const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSize](#ee16826e) (const std::wstring & _str_, float _lineHeight_ = 1.25f) const  |
|  int | [getSizePt](#222e6a2a) () const  |
|  int | [getSizePixels](#c73bf9f3) () const  |
|  int | [getDpi](#741652a0) () const  |
|  const [ffw::Texture2D](ffw_Texture2D.html) * | [getTexture](#64226aa5) () const  |
|  bool | [isCreated](#65a9b796) () const  |
|  float | [getCharVerticalOffset](#3a58ee86) (const [Font::Char](ffw_Font_Char.html) & _data_) const  |
|  bool | [isAlphaOnly](#67cedb06) () const  |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#2107f8ab) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Protected Functions

| Type | Name |
| -------: | :------- |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getStringSizeFunc](#067f8cc6) (const std::basic_string< T > & _str_, float _lineHeight_) const  |


## Protected Attributes Documentation

### _variable_ <a id="e7cda937" href="#e7cda937">texture</a>

```cpp
ffw::Texture2D texture
```



### _variable_ <a id="db4ac3b4" href="#db4ac3b4">sizePoints</a>

```cpp
int sizePoints
```



### _variable_ <a id="f4da172b" href="#f4da172b">sizePixels</a>

```cpp
int sizePixels
```



### _variable_ <a id="a1399e72" href="#a1399e72">sizeDpi</a>

```cpp
int sizeDpi
```



### _variable_ <a id="e776a077" href="#e776a077">loaded</a>

```cpp
bool loaded
```



### _variable_ <a id="6966e978" href="#6966e978">alphaOnlyFlag</a>

```cpp
bool alphaOnlyFlag
```





## Public Functions Documentation

### _function_ <a id="7774a231" href="#7774a231">Font</a>

```cpp
 Font () 
```



### _function_ <a id="b5601d30" href="#b5601d30">~Font</a>

```cpp
virtual  ~Font () 
```



### _function_ <a id="ad63e5d2" href="#ad63e5d2">destroy</a>

```cpp
virtual void destroy () = 0 
```



### _function_ <a id="d843f542" href="#d843f542">getChar</a>

```cpp
virtual const Char & getChar (
    wchar_t chr
) const = 0 
```



### _function_ <a id="9dcbaeb3" href="#9dcbaeb3">getStringSize</a>

```cpp
virtual ffw::Vec2f getStringSize (
    const std::string & str,
    float lineHeight = 1.25f
) const 
```



### _function_ <a id="ee16826e" href="#ee16826e">getStringSize</a>

```cpp
virtual ffw::Vec2f getStringSize (
    const std::wstring & str,
    float lineHeight = 1.25f
) const 
```



### _function_ <a id="222e6a2a" href="#222e6a2a">getSizePt</a>

```cpp
inline int getSizePt () const 
```



### _function_ <a id="c73bf9f3" href="#c73bf9f3">getSizePixels</a>

```cpp
inline int getSizePixels () const 
```



### _function_ <a id="741652a0" href="#741652a0">getDpi</a>

```cpp
inline int getDpi () const 
```



### _function_ <a id="64226aa5" href="#64226aa5">getTexture</a>

```cpp
inline const ffw::Texture2D * getTexture () const 
```



### _function_ <a id="65a9b796" href="#65a9b796">isCreated</a>

```cpp
inline bool isCreated () const 
```



### _function_ <a id="3a58ee86" href="#3a58ee86">getCharVerticalOffset</a>

```cpp
inline float getCharVerticalOffset (
    const Font::Char & data
) const 
```



### _function_ <a id="67cedb06" href="#67cedb06">isAlphaOnly</a>

```cpp
inline bool isAlphaOnly () const 
```





## Public Static Functions Documentation

### _function_ <a id="2107f8ab" href="#2107f8ab">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Protected Functions Documentation

### _function_ <a id="067f8cc6" href="#067f8cc6">getStringSizeFunc</a>

```cpp
ffw::Vec2f getStringSizeFunc (
    const std::basic_string< T > & str,
    float lineHeight
) const 
```





