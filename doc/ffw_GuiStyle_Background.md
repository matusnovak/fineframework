Background
===================================


The documentation for this class was generated from: `include/ffw/gui/guitheme.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Type](#213e4cfd) |
| typedef [Attribute](ffw_GuiStyle_Attribute.html)< float > | [Radius](#5dc897ce) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  [Attribute](ffw_GuiStyle_Attribute.html)< float > | [radius](#d2b0f38c) |
|  [ffw::Color](ffw_Color.html) | [color](#372cf837) |
|  [Type](ffw_GuiStyle_Background.html#213e4cfd) | [type](#0c55f475) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Background](#4a7f8b52) ()  |
|   | [Background](#acaf001b) (const [Attribute](ffw_GuiStyle_Attribute.html)< float > & _r_, const [ffw::Color](ffw_Color.html) & _c_, [Type](ffw_GuiStyle_Background.html#213e4cfd) _t_)  |
|   | [operator bool](#e36fa437) () const  |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="213e4cfd" href="#213e4cfd">Type</a>

```cpp
enum Type {
    NONE,
    SIMPLE,
}
```



### <span style="opacity:0.5;">typedef</span> <a id="5dc897ce" href="#5dc897ce">Radius</a>

```cpp
Attribute< float > Radius
```





## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="d2b0f38c" href="#d2b0f38c">radius</a>

```cpp
Attribute< float > radius
```



### <span style="opacity:0.5;">variable</span> <a id="372cf837" href="#372cf837">color</a>

```cpp
ffw::Color color
```



### <span style="opacity:0.5;">variable</span> <a id="0c55f475" href="#0c55f475">type</a>

```cpp
Type type
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="4a7f8b52" href="#4a7f8b52">Background</a>

```cpp
inline  Background () 
```



### <span style="opacity:0.5;">function</span> <a id="acaf001b" href="#acaf001b">Background</a>

```cpp
inline  Background (
    const Attribute< float > & r,
    const ffw::Color & c,
    Type t
) 
```



### <span style="opacity:0.5;">function</span> <a id="e36fa437" href="#e36fa437">operator bool</a>

```cpp
inline  operator bool () const 
```





