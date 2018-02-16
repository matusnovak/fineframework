GuiStyle
===================================


The documentation for this class was generated from: `include/ffw/gui/guistyle.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiStyle::Attribute](ffw_GuiStyle_Attribute.html) |
| class [ffw::GuiStyle::Background](ffw_GuiStyle_Background.html) |
| class [ffw::GuiStyle::Border](ffw_GuiStyle_Border.html) |
| class [ffw::GuiStyle::Function](ffw_GuiStyle_Function.html) |
| class [ffw::GuiStyle::Text](ffw_GuiStyle_Text.html) |


## Public Types

| Type | Name |
| -------: | :------- |
| typedef [Border](ffw_GuiStyle_Border.html) | [Outline](#45875f08) |
| typedef [GuiStyle::Attribute](ffw_GuiStyle_Attribute.html)< [GuiUnits](ffw_GuiUnits.html) > | [Padding](#82b7d280) |
| typedef [GuiStyle::Attribute](ffw_GuiStyle_Attribute.html)< [GuiUnits](ffw_GuiUnits.html) > | [Margin](#77df323f) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  [Background](ffw_GuiStyle_Background.html) | [background](#17e70e6d) |
|  [Border](ffw_GuiStyle_Border.html) | [border](#ac67ee1d) |
|  [Outline](ffw_GuiStyle.html#45875f08) | [outline](#fd9cf55f) |
|  [Text](ffw_GuiStyle_Text.html) | [text](#95de247d) |
|  [Function](ffw_GuiStyle_Function.html) | [function](#3001baa5) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiStyle](#919fc827) ()  |
|   | [GuiStyle](#cccebe00) (const [Background](ffw_GuiStyle_Background.html) & _b_, const [Border](ffw_GuiStyle_Border.html) & _br_, const [Outline](ffw_GuiStyle.html#45875f08) & _ou_, const [Text](ffw_GuiStyle_Text.html) & _t_, const [Function](ffw_GuiStyle_Function.html) & _f_)  |


## Public Types Documentation

### _typedef_ <a id="45875f08" href="#45875f08">Outline</a>

```cpp
Border Outline
```



### _typedef_ <a id="82b7d280" href="#82b7d280">Padding</a>

```cpp
GuiStyle::Attribute< GuiUnits > Padding
```



### _typedef_ <a id="77df323f" href="#77df323f">Margin</a>

```cpp
GuiStyle::Attribute< GuiUnits > Margin
```





## Public Attributes Documentation

### _variable_ <a id="17e70e6d" href="#17e70e6d">background</a>

```cpp
Background background
```



### _variable_ <a id="ac67ee1d" href="#ac67ee1d">border</a>

```cpp
Border border
```



### _variable_ <a id="fd9cf55f" href="#fd9cf55f">outline</a>

```cpp
Outline outline
```



### _variable_ <a id="95de247d" href="#95de247d">text</a>

```cpp
Text text
```



### _variable_ <a id="3001baa5" href="#3001baa5">function</a>

```cpp
Function function
```





## Public Functions Documentation

### _function_ <a id="919fc827" href="#919fc827">GuiStyle</a>

```cpp
inline  GuiStyle () 
```



### _function_ <a id="cccebe00" href="#cccebe00">GuiStyle</a>

```cpp
inline  GuiStyle (
    const Background & b,
    const Border & br,
    const Outline & ou,
    const Text & t,
    const Function & f
) 
```





