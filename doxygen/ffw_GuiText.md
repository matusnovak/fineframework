GuiText
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guitext.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiText::Paragraph](ffw_GuiText_Paragraph.html) |
| struct [ffw::GuiText::Style](ffw_GuiText_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiText](#72755c81) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiText](#f5c34f9a) ()  |
|  [Paragraph](ffw_GuiText_Paragraph.html) * | [addParagraph](#e3df018a) (const std::string & _text_)  |
|  [Paragraph](ffw_GuiText_Paragraph.html) * | [addParagraph](#1861efd7) (const std::string & _text_, const [Color](ffw_Color.html) & _color_, const [GuiFont](ffw_GuiFont.html) * _font_)  |
|  const std::list< [Paragraph](ffw_GuiText_Paragraph.html) > & | [getParagraphs](#8f461d01) () const  |
|  void | [setStyle](#dd5c78be) (const [GuiText::Style](ffw_GuiText_Style.html) * _style_, bool _defaults_ = false)  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#129878ff) ()  |


## Public Functions Documentation

### _function_ <a id="72755c81" href="#72755c81">GuiText</a>

```cpp
 GuiText (
    GuiWindow * context
) 
```



### _function_ <a id="f5c34f9a" href="#f5c34f9a">~GuiText</a>

```cpp
virtual  ~GuiText () 
```



### _function_ <a id="e3df018a" href="#e3df018a">addParagraph</a>

```cpp
Paragraph * addParagraph (
    const std::string & text
) 
```



### _function_ <a id="1861efd7" href="#1861efd7">addParagraph</a>

```cpp
Paragraph * addParagraph (
    const std::string & text,
    const Color & color,
    const GuiFont * font
) 
```



### _function_ <a id="8f461d01" href="#8f461d01">getParagraphs</a>

```cpp
inline const std::list< Paragraph > & getParagraphs () const 
```



### _function_ <a id="dd5c78be" href="#dd5c78be">setStyle</a>

```cpp
void setStyle (
    const GuiText::Style * style,
    bool defaults = false
) 
```



### _function_ <a id="129878ff" href="#129878ff">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)



