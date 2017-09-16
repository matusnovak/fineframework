TextLine
===================================


The documentation for this class was generated from: `include/ffw/gui/guitextedit.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [TextLine](#12fc5be9) (const std::wstring & _s_)  |
|  const std::wstring & | [get](#dc40f6ef) () const  |
|  const std::vector< size_t > & | [Tokens](#86cbbb00) () const  |
|  void | [setText](#8e10e562) (const std::wstring & _s_)  |
|  void | [recalculate](#6814a691) (const [ffw::GuiFont](ffw_GuiFont.html) * _font_, float _width_, bool _ignore_)  |
|  void | [insertAt](#5d0658ea) (size_t _pos_, wchar_t _chr_)  |
|  void | [removeAt](#575dfd68) (size_t _pos_)  |
|  void | [append](#35544ef7) (const std::wstring & _str_)  |
|  size_t | [getNumOfTokens](#625d1cd5) () const  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="12fc5be9" href="#12fc5be9">TextLine</a>

```cpp
 TextLine (
    const std::wstring & s
) 
```



### <span style="opacity:0.5;">function</span> <a id="dc40f6ef" href="#dc40f6ef">get</a>

```cpp
const std::wstring & get () const 
```



### <span style="opacity:0.5;">function</span> <a id="86cbbb00" href="#86cbbb00">Tokens</a>

```cpp
const std::vector< size_t > & Tokens () const 
```



### <span style="opacity:0.5;">function</span> <a id="8e10e562" href="#8e10e562">setText</a>

```cpp
void setText (
    const std::wstring & s
) 
```



### <span style="opacity:0.5;">function</span> <a id="6814a691" href="#6814a691">recalculate</a>

```cpp
void recalculate (
    const ffw::GuiFont * font,
    float width,
    bool ignore
) 
```



### <span style="opacity:0.5;">function</span> <a id="5d0658ea" href="#5d0658ea">insertAt</a>

```cpp
void insertAt (
    size_t pos,
    wchar_t chr
) 
```



### <span style="opacity:0.5;">function</span> <a id="575dfd68" href="#575dfd68">removeAt</a>

```cpp
void removeAt (
    size_t pos
) 
```



### <span style="opacity:0.5;">function</span> <a id="35544ef7" href="#35544ef7">append</a>

```cpp
void append (
    const std::wstring & str
) 
```



### <span style="opacity:0.5;">function</span> <a id="625d1cd5" href="#625d1cd5">getNumOfTokens</a>

```cpp
inline size_t getNumOfTokens () const 
```





