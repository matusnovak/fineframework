BitmapFont
===================================


**Inherits from:** [ffw::Font](ffw_Font.html)

The documentation for this class was generated from: `include/ffw/graphics/bitmapfont.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [BitmapFont](#546cd6a8) ()  |
|   | [BitmapFont](#7530436b) (const [BitmapFont](ffw_BitmapFont.html) & _other_) = delete  |
|   | [BitmapFont](#adf8c444) ([BitmapFont](ffw_BitmapFont.html) && _other_)  |
|  virtual  | [~BitmapFont](#0ee20c93) ()  |
|  bool | [createFromData](#9f1fd0ef) (const void * _pixels_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _format_, int _points_, int _dpi_, int _start_ = 0x00, int _end_ = 0x7F)  |
|  bool | [createFromBuffer](#6bf4aa85) (const [ImageBuffer](ffw_ImageBuffer.html) & _buffer_, int _points_, int _dpi_, int _start_ = 0x00, int _end_ = 0x7F)  |
|  virtual void | [destroy](#26f48bba) ()  |
|  virtual const [Font::Char](ffw_Font_Char.html) & | [getChar](#ba912469) (wchar_t _chr_) const  |
|  virtual int | [getCharIndex](#ea093966) (wchar_t _chr_) const  |
|  void | [setCharData](#2e468b1a) (wchar_t _chr_, [Font::Char](ffw_Font_Char.html) & _data_)  |
|  bool | [updateBuffer](#1d9678d1) ()  |
|  [BitmapFont](ffw_BitmapFont.html) & | [operator=](#19702695) (const [BitmapFont](ffw_BitmapFont.html) & _other_) = delete  |
|  [BitmapFont](ffw_BitmapFont.html) & | [operator=](#5aed97c9) ([BitmapFont](ffw_BitmapFont.html) && _other_)  |
|  void | [swap](#8a5925cd) ([BitmapFont](ffw_BitmapFont.html) & _other_)  |


## Public Functions Documentation

### _function_ <a id="546cd6a8" href="#546cd6a8">BitmapFont</a>

```cpp
 BitmapFont () 
```



### _function_ <a id="7530436b" href="#7530436b">BitmapFont</a>

```cpp
 BitmapFont (
    const BitmapFont & other
) = delete 
```



### _function_ <a id="adf8c444" href="#adf8c444">BitmapFont</a>

```cpp
 BitmapFont (
    BitmapFont && other
) 
```



### _function_ <a id="0ee20c93" href="#0ee20c93">~BitmapFont</a>

```cpp
virtual  ~BitmapFont () 
```



### _function_ <a id="9f1fd0ef" href="#9f1fd0ef">createFromData</a>

```cpp
bool createFromData (
    const void * pixels,
    int width,
    int height,
    ffw::ImageType format,
    int points,
    int dpi,
    int start = 0x00,
    int end = 0x7F
) 
```



### _function_ <a id="6bf4aa85" href="#6bf4aa85">createFromBuffer</a>

```cpp
bool createFromBuffer (
    const ImageBuffer & buffer,
    int points,
    int dpi,
    int start = 0x00,
    int end = 0x7F
) 
```



### _function_ <a id="26f48bba" href="#26f48bba">destroy</a>

```cpp
virtual void destroy () 
```



**Overrides:** [destroy](/doxygen/ffw_Font.md#ad63e5d2) from class [Font](/doxygen/ffw_Font.md)

### _function_ <a id="ba912469" href="#ba912469">getChar</a>

```cpp
virtual const Font::Char & getChar (
    wchar_t chr
) const 
```



**Overrides:** [getChar](/doxygen/ffw_Font.md#d843f542) from class [Font](/doxygen/ffw_Font.md)

### _function_ <a id="ea093966" href="#ea093966">getCharIndex</a>

```cpp
virtual int getCharIndex (
    wchar_t chr
) const 
```



**Overrides:** [getCharIndex](/doxygen/ffw_Font.md#8a9e6bda) from class [Font](/doxygen/ffw_Font.md)

### _function_ <a id="2e468b1a" href="#2e468b1a">setCharData</a>

```cpp
void setCharData (
    wchar_t chr,
    Font::Char & data
) 
```



### _function_ <a id="1d9678d1" href="#1d9678d1">updateBuffer</a>

```cpp
bool updateBuffer () 
```



### _function_ <a id="19702695" href="#19702695">operator=</a>

```cpp
BitmapFont & operator= (
    const BitmapFont & other
) = delete 
```



### _function_ <a id="5aed97c9" href="#5aed97c9">operator=</a>

```cpp
BitmapFont & operator= (
    BitmapFont && other
) 
```



### _function_ <a id="8a5925cd" href="#8a5925cd">swap</a>

```cpp
void swap (
    BitmapFont & other
) 
```





