FreeTypeLoader
===================================


The documentation for this class was generated from: `include/ffw/graphics/freetypeloader.h`



## Classes

| Name |
|:-----|
| class [ffw::FreeTypeLoader::CharData](ffw_FreeTypeLoader_CharData.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [FreeTypeLoader](#2b616df1) ()  |
|   | [FreeTypeLoader](#dd126386) (const [FreeTypeLoader](ffw_FreeTypeLoader.html) & _other_) = delete  |
|   | [FreeTypeLoader](#8987484d) ([FreeTypeLoader](ffw_FreeTypeLoader.html) && _other_)  |
|  virtual  | [~FreeTypeLoader](#c23613a4) ()  |
|  bool | [createFromData](#5398a68e) (const unsigned char * _buffer_, size_t _length_)  |
|  bool | [createFromFile](#ef1a1b0a) (const std::string & _path_)  |
|  bool | [setSize](#d63ff035) (int _points_, int _dpi_)  |
|  bool | [findGlyph](#7d8c365a) (int _unicode_)  |
|  bool | [findErrorGlyph](#fac77fd2) ()  |
|  bool | [getGlyphData](#619a93a0) ([CharData](ffw_FreeTypeLoader_CharData.html) * _data_)  |
|  int | [getSizePixels](#1a61374f) () const  |
|  bool | [isCreated](#f4c0cdc5) () const  |
|  void | [destroy](#e8128175) ()  |
|  void | [swap](#31ccb3ae) ([FreeTypeLoader](ffw_FreeTypeLoader.html) & _other_)  |
|  [FreeTypeLoader](ffw_FreeTypeLoader.html) & | [operator=](#491c7eb4) (const [FreeTypeLoader](ffw_FreeTypeLoader.html) & _other_) = delete  |
|  [FreeTypeLoader](ffw_FreeTypeLoader.html) & | [operator=](#63357b73) ([FreeTypeLoader](ffw_FreeTypeLoader.html) && _other_)  |


## Public Functions Documentation

### _function_ <a id="2b616df1" href="#2b616df1">FreeTypeLoader</a>

```cpp
 FreeTypeLoader () 
```



### _function_ <a id="dd126386" href="#dd126386">FreeTypeLoader</a>

```cpp
 FreeTypeLoader (
    const FreeTypeLoader & other
) = delete 
```



### _function_ <a id="8987484d" href="#8987484d">FreeTypeLoader</a>

```cpp
 FreeTypeLoader (
    FreeTypeLoader && other
) 
```



### _function_ <a id="c23613a4" href="#c23613a4">~FreeTypeLoader</a>

```cpp
virtual  ~FreeTypeLoader () 
```



### _function_ <a id="5398a68e" href="#5398a68e">createFromData</a>

```cpp
bool createFromData (
    const unsigned char * buffer,
    size_t length
) 
```



### _function_ <a id="ef1a1b0a" href="#ef1a1b0a">createFromFile</a>

```cpp
bool createFromFile (
    const std::string & path
) 
```



### _function_ <a id="d63ff035" href="#d63ff035">setSize</a>

```cpp
bool setSize (
    int points,
    int dpi
) 
```



### _function_ <a id="7d8c365a" href="#7d8c365a">findGlyph</a>

```cpp
bool findGlyph (
    int unicode
) 
```



### _function_ <a id="fac77fd2" href="#fac77fd2">findErrorGlyph</a>

```cpp
bool findErrorGlyph () 
```



### _function_ <a id="619a93a0" href="#619a93a0">getGlyphData</a>

```cpp
bool getGlyphData (
    CharData * data
) 
```



### _function_ <a id="1a61374f" href="#1a61374f">getSizePixels</a>

```cpp
inline int getSizePixels () const 
```



### _function_ <a id="f4c0cdc5" href="#f4c0cdc5">isCreated</a>

```cpp
inline bool isCreated () const 
```



### _function_ <a id="e8128175" href="#e8128175">destroy</a>

```cpp
void destroy () 
```



### _function_ <a id="31ccb3ae" href="#31ccb3ae">swap</a>

```cpp
void swap (
    FreeTypeLoader & other
) 
```



### _function_ <a id="491c7eb4" href="#491c7eb4">operator=</a>

```cpp
FreeTypeLoader & operator= (
    const FreeTypeLoader & other
) = delete 
```



### _function_ <a id="63357b73" href="#63357b73">operator=</a>

```cpp
FreeTypeLoader & operator= (
    FreeTypeLoader && other
) 
```





