Background
===================================


The documentation for this class was generated from: `include/ffw/gui/guistyle.h`



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
|   | [Background](#5a0dd7b3) (const [ffw::Color](ffw_Color.html) & _c_)  |
|   | [Background](#d82b954a) (const [Attribute](ffw_GuiStyle_Attribute.html)< float > & _r_, const [ffw::Color](ffw_Color.html) & _c_)  |
|   | [operator bool](#e36fa437) () const  |


## Public Types Documentation

### _enum_ <a id="213e4cfd" href="#213e4cfd">Type</a>

```cpp
enum Type {
    NONE,
    SIMPLE,
}
```



### _typedef_ <a id="5dc897ce" href="#5dc897ce">Radius</a>

```cpp
Attribute< float > Radius
```





## Public Attributes Documentation

### _variable_ <a id="d2b0f38c" href="#d2b0f38c">radius</a>

```cpp
Attribute< float > radius
```



### _variable_ <a id="372cf837" href="#372cf837">color</a>

```cpp
ffw::Color color
```



### _variable_ <a id="0c55f475" href="#0c55f475">type</a>

```cpp
Type type
```





## Public Functions Documentation

### _function_ <a id="4a7f8b52" href="#4a7f8b52">Background</a>

```cpp
inline  Background () 
```



### _function_ <a id="5a0dd7b3" href="#5a0dd7b3">Background</a>

```cpp
inline  Background (
    const ffw::Color & c
) 
```



### _function_ <a id="d82b954a" href="#d82b954a">Background</a>

```cpp
inline  Background (
    const Attribute< float > & r,
    const ffw::Color & c
) 
```



### _function_ <a id="e36fa437" href="#e36fa437">operator bool</a>

```cpp
inline  operator bool () const 
```





