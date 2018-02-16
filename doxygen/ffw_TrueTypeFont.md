TrueTypeFont
===================================


**Inherits from:** [ffw::Font](ffw_Font.html)

**Implemented by:** [ffw::GuiFontOpenGL](ffw_GuiFontOpenGL.html)

The documentation for this class was generated from: `include/ffw/graphics/truetypefont.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TrueTypeFont](#d5c7436a) ()  |
|   | [TrueTypeFont](#1bf4d6c5) (const [TrueTypeFont](ffw_TrueTypeFont.html) & _other_) = delete  |
|   | [TrueTypeFont](#de6b4424) ([TrueTypeFont](ffw_TrueTypeFont.html) && _other_)  |
|  virtual  | [~TrueTypeFont](#d020eb76) ()  |
|  bool | [createFromData](#77522242) (const unsigned char * _buffer_, size_t _length_, int _points_, int _dpi_, int _start_ = 0x00, int _end_ = 0x7F)  |
|  bool | [createFromFile](#4cea694e) (const std::string & _path_, int _points_, int _dpi_, int _start_ = 0x00, int _end_ = 0x7F)  |
|  virtual void | [destroy](#334df3a6) ()  |
|  virtual const Char & | [getChar](#28bdd97d) (wchar_t _chr_) const  |
|  virtual int | [getCharIndex](#e3b72864) (wchar_t _chr_) const  |
|  [TrueTypeFont](ffw_TrueTypeFont.html) & | [operator=](#9a698e6e) (const [TrueTypeFont](ffw_TrueTypeFont.html) & _other_) = delete  |
|  [TrueTypeFont](ffw_TrueTypeFont.html) & | [operator=](#8055e987) ([TrueTypeFont](ffw_TrueTypeFont.html) && _other_)  |
|  void | [swap](#cc1a0984) ([TrueTypeFont](ffw_TrueTypeFont.html) & _other_)  |


## Public Functions Documentation

### _function_ <a id="d5c7436a" href="#d5c7436a">TrueTypeFont</a>

```cpp
 TrueTypeFont () 
```



### _function_ <a id="1bf4d6c5" href="#1bf4d6c5">TrueTypeFont</a>

```cpp
 TrueTypeFont (
    const TrueTypeFont & other
) = delete 
```



### _function_ <a id="de6b4424" href="#de6b4424">TrueTypeFont</a>

```cpp
 TrueTypeFont (
    TrueTypeFont && other
) 
```



### _function_ <a id="d020eb76" href="#d020eb76">~TrueTypeFont</a>

```cpp
virtual  ~TrueTypeFont () 
```



### _function_ <a id="77522242" href="#77522242">createFromData</a>

```cpp
bool createFromData (
    const unsigned char * buffer,
    size_t length,
    int points,
    int dpi,
    int start = 0x00,
    int end = 0x7F
) 
```



### _function_ <a id="4cea694e" href="#4cea694e">createFromFile</a>

```cpp
bool createFromFile (
    const std::string & path,
    int points,
    int dpi,
    int start = 0x00,
    int end = 0x7F
) 
```



### _function_ <a id="334df3a6" href="#334df3a6">destroy</a>

```cpp
virtual void destroy () 
```



**Overrides:** [destroy](/doxygen/ffw_Font.md#ad63e5d2) from class [Font](/doxygen/ffw_Font.md)

### _function_ <a id="28bdd97d" href="#28bdd97d">getChar</a>

```cpp
virtual const Char & getChar (
    wchar_t chr
) const 
```



**Overrides:** [getChar](/doxygen/ffw_Font.md#d843f542) from class [Font](/doxygen/ffw_Font.md)

### _function_ <a id="e3b72864" href="#e3b72864">getCharIndex</a>

```cpp
virtual int getCharIndex (
    wchar_t chr
) const 
```



**Overrides:** [getCharIndex](/doxygen/ffw_Font.md#8a9e6bda) from class [Font](/doxygen/ffw_Font.md)

### _function_ <a id="9a698e6e" href="#9a698e6e">operator=</a>

```cpp
TrueTypeFont & operator= (
    const TrueTypeFont & other
) = delete 
```



### _function_ <a id="8055e987" href="#8055e987">operator=</a>

```cpp
TrueTypeFont & operator= (
    TrueTypeFont && other
) 
```



### _function_ <a id="cc1a0984" href="#cc1a0984">swap</a>

```cpp
void swap (
    TrueTypeFont & other
) 
```





