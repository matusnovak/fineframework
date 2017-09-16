GuiTextWrapper
===================================


The documentation for this class was generated from: `include/ffw/gui/guitextwrapper.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiTextWrapper::Paragraph](ffw_GuiTextWrapper_Paragraph.html) |
| struct [ffw::GuiTextWrapper::Section](ffw_GuiTextWrapper_Section.html) |
| class [ffw::GuiTextWrapper::Stepper](ffw_GuiTextWrapper_Stepper.html) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  std::vector< [Paragraph](ffw_GuiTextWrapper_Paragraph.html) > | [paragraphs](#0d2271b1) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTextWrapper](#9373b7a4) ()  |
|  virtual  | [~GuiTextWrapper](#d2201896) ()  |
|  void | [setValue](#2b91ab96) (const std::wstring & _str_, const [ffw::Color](ffw_Color.html) & _color_, const [ffw::GuiFont](ffw_GuiFont.html) * _font_)  |
|  const std::wstring | [getValue](#cf4c71bd) () const  |
|  void | [addParagraph](#9b61ff64) ()  |
|  void | [recalculate](#bee3785d) (float _width_)  |
|  void | [append](#065aa25d) (const std::wstring & _str_)  |
|  void | [section](#c5ff18b4) (const [ffw::Color](ffw_Color.html) & _color_, const [ffw::GuiFont](ffw_GuiFont.html) * _font_)  |
|  const std::vector< [Paragraph](ffw_GuiTextWrapper_Paragraph.html) > & | [getParagraphs](#f2a46c5b) () const  |
|  std::vector< [Paragraph](ffw_GuiTextWrapper_Paragraph.html) > & | [getParagraphs](#60cde84b) ()  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="0d2271b1" href="#0d2271b1">paragraphs</a>

```cpp
std::vector< Paragraph > paragraphs
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="9373b7a4" href="#9373b7a4">GuiTextWrapper</a>

```cpp
 GuiTextWrapper () 
```



### <span style="opacity:0.5;">function</span> <a id="d2201896" href="#d2201896">~GuiTextWrapper</a>

```cpp
virtual  ~GuiTextWrapper () 
```



### <span style="opacity:0.5;">function</span> <a id="2b91ab96" href="#2b91ab96">setValue</a>

```cpp
void setValue (
    const std::wstring & str,
    const ffw::Color & color,
    const ffw::GuiFont * font
) 
```



### <span style="opacity:0.5;">function</span> <a id="cf4c71bd" href="#cf4c71bd">getValue</a>

```cpp
const std::wstring getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="9b61ff64" href="#9b61ff64">addParagraph</a>

```cpp
inline void addParagraph () 
```



### <span style="opacity:0.5;">function</span> <a id="bee3785d" href="#bee3785d">recalculate</a>

```cpp
void recalculate (
    float width
) 
```



### <span style="opacity:0.5;">function</span> <a id="065aa25d" href="#065aa25d">append</a>

```cpp
inline void append (
    const std::wstring & str
) 
```



### <span style="opacity:0.5;">function</span> <a id="c5ff18b4" href="#c5ff18b4">section</a>

```cpp
inline void section (
    const ffw::Color & color,
    const ffw::GuiFont * font
) 
```



### <span style="opacity:0.5;">function</span> <a id="f2a46c5b" href="#f2a46c5b">getParagraphs</a>

```cpp
inline const std::vector< Paragraph > & getParagraphs () const 
```



### <span style="opacity:0.5;">function</span> <a id="60cde84b" href="#60cde84b">getParagraphs</a>

```cpp
inline std::vector< Paragraph > & getParagraphs () 
```





