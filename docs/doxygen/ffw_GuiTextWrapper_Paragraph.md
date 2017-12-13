Paragraph
===================================


The documentation for this class was generated from: `include/ffw/gui/guitextwrapper.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  std::wstring | [text](#2305525d) |
|  std::vector< [Section](ffw_GuiTextWrapper_Section.html) > | [sections](#cd396617) |
|  std::vector< std::pair< size_t, int > > | [tokens](#297b82d6) |
|  int | [totalHeight](#3ee9e627) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Paragraph](#c65882a6) ()  |
|  virtual  | [~Paragraph](#e27479a3) ()  |
|  const std::wstring & | [getText](#6e76c5ce) () const  |
|  const std::vector< [Section](ffw_GuiTextWrapper_Section.html) > & | [getSections](#3f9eb80d) () const  |
|  const std::vector< std::pair< size_t, int > > & | [getTokens](#3bd33546) () const  |
|  int | [getTotalHeight](#26ce249b) () const  |
|  void | [append](#7d077407) (const std::wstring & _str_)  |
|  void | [section](#54707169) (const [ffw::Color](ffw_Color.html) & _color_, const [ffw::GuiFont](ffw_GuiFont.html) * _font_)  |
|  void | [recalculate](#6f306d76) (float _width_)  |


## Protected Attributes Documentation

### _variable_ <a id="2305525d" href="#2305525d">text</a>

```cpp
std::wstring text
```



### _variable_ <a id="cd396617" href="#cd396617">sections</a>

```cpp
std::vector< Section > sections
```



### _variable_ <a id="297b82d6" href="#297b82d6">tokens</a>

```cpp
std::vector< std::pair< size_t, int > > tokens
```



### _variable_ <a id="3ee9e627" href="#3ee9e627">totalHeight</a>

```cpp
int totalHeight
```





## Public Functions Documentation

### _function_ <a id="c65882a6" href="#c65882a6">Paragraph</a>

```cpp
 Paragraph () 
```



### _function_ <a id="e27479a3" href="#e27479a3">~Paragraph</a>

```cpp
virtual  ~Paragraph () 
```



### _function_ <a id="6e76c5ce" href="#6e76c5ce">getText</a>

```cpp
inline const std::wstring & getText () const 
```



### _function_ <a id="3f9eb80d" href="#3f9eb80d">getSections</a>

```cpp
inline const std::vector< Section > & getSections () const 
```



### _function_ <a id="3bd33546" href="#3bd33546">getTokens</a>

```cpp
inline const std::vector< std::pair< size_t, int > > & getTokens () const 
```



### _function_ <a id="26ce249b" href="#26ce249b">getTotalHeight</a>

```cpp
inline int getTotalHeight () const 
```



### _function_ <a id="7d077407" href="#7d077407">append</a>

```cpp
void append (
    const std::wstring & str
) 
```



### _function_ <a id="54707169" href="#54707169">section</a>

```cpp
void section (
    const ffw::Color & color,
    const ffw::GuiFont * font
) 
```



### _function_ <a id="6f306d76" href="#6f306d76">recalculate</a>

```cpp
void recalculate (
    float width
) 
```





