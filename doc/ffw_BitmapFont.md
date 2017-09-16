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
|  bool | [createFromData](#ba7618f3) (const [RenderContext](ffw_RenderContext.html) * _renderer_, const void * _pixels_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _format_, int _points_, int _dpi_, int _start_ = 0x00, int _end_ = 0x7F)  |
|  bool | [createFromBuffer](#e262df3e) (const [RenderContext](ffw_RenderContext.html) * _renderer_, const [ImageBuffer](ffw_ImageBuffer.html) & _buffer_, int _points_, int _dpi_, int _start_ = 0x00, int _end_ = 0x7F)  |
|  virtual void | [destroy](#26f48bba) ()  |
|  virtual const [Font::Char](ffw_Font_Char.html) & | [getChar](#ba912469) (wchar_t _chr_) const  |
|  [Font::Char](ffw_Font_Char.html) & | [setCharData](#f39e79f6) (wchar_t _chr_)  |
|  [BitmapFont](ffw_BitmapFont.html) & | [operator=](#19702695) (const [BitmapFont](ffw_BitmapFont.html) & _other_) = delete  |
|  [BitmapFont](ffw_BitmapFont.html) & | [operator=](#5aed97c9) ([BitmapFont](ffw_BitmapFont.html) && _other_)  |
|  void | [swap](#8a5925cd) ([BitmapFont](ffw_BitmapFont.html) & _other_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="546cd6a8" href="#546cd6a8">BitmapFont</a>

```cpp
 BitmapFont () 
```



### <span style="opacity:0.5;">function</span> <a id="7530436b" href="#7530436b">BitmapFont</a>

```cpp
 BitmapFont (
    const BitmapFont & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="adf8c444" href="#adf8c444">BitmapFont</a>

```cpp
 BitmapFont (
    BitmapFont && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="0ee20c93" href="#0ee20c93">~BitmapFont</a>

```cpp
virtual  ~BitmapFont () 
```



### <span style="opacity:0.5;">function</span> <a id="ba7618f3" href="#ba7618f3">createFromData</a>

```cpp
bool createFromData (
    const RenderContext * renderer,
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



### <span style="opacity:0.5;">function</span> <a id="e262df3e" href="#e262df3e">createFromBuffer</a>

```cpp
bool createFromBuffer (
    const RenderContext * renderer,
    const ImageBuffer & buffer,
    int points,
    int dpi,
    int start = 0x00,
    int end = 0x7F
) 
```



### <span style="opacity:0.5;">function</span> <a id="26f48bba" href="#26f48bba">destroy</a>

```cpp
virtual void destroy () 
```



### <span style="opacity:0.5;">function</span> <a id="ba912469" href="#ba912469">getChar</a>

```cpp
virtual const Font::Char & getChar (
    wchar_t chr
) const 
```



### <span style="opacity:0.5;">function</span> <a id="f39e79f6" href="#f39e79f6">setCharData</a>

```cpp
Font::Char & setCharData (
    wchar_t chr
) 
```



### <span style="opacity:0.5;">function</span> <a id="19702695" href="#19702695">operator=</a>

```cpp
BitmapFont & operator= (
    const BitmapFont & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="5aed97c9" href="#5aed97c9">operator=</a>

```cpp
BitmapFont & operator= (
    BitmapFont && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="8a5925cd" href="#8a5925cd">swap</a>

```cpp
void swap (
    BitmapFont & other
) 
```





