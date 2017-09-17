GuiRichText
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guirichtext.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiRichText](#3e622a9c) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiRichText](#ae943a17) ()  |
|  void | [setText](#13799227) (const std::wstring & _label_)  |
|  const std::wstring | [getText](#8d86e4c7) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#7d355fe5) ()  |
|  void | [addParagraph](#985715d0) ()  |
|  void | [addSection](#7945c21e) (const [ffw::Color](ffw_Color.html) & _color_, [ffw::GuiFont](ffw_GuiFont.html) * _font_ = NULL)  |
|  void | [addSection](#0f78533b) ([ffw::GuiFont](ffw_GuiFont.html) * _font_)  |
|  void | [addSectionDefault](#b216151a) ()  |
|  void | [addText](#49ca9b5e) (const std::wstring & _str_)  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="3e622a9c" href="#3e622a9c">GuiRichText</a>

```cpp
 GuiRichText (
    GuiWindow * context
) 
```



### <span style="opacity:0.5;">function</span> <a id="ae943a17" href="#ae943a17">~GuiRichText</a>

```cpp
virtual  ~GuiRichText () 
```



### <span style="opacity:0.5;">function</span> <a id="13799227" href="#13799227">setText</a>

```cpp
void setText (
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="8d86e4c7" href="#8d86e4c7">getText</a>

```cpp
const std::wstring getText () const 
```



### <span style="opacity:0.5;">function</span> <a id="7d355fe5" href="#7d355fe5">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doc/ffw_GuiWidget.md)

### <span style="opacity:0.5;">function</span> <a id="985715d0" href="#985715d0">addParagraph</a>

```cpp
void addParagraph () 
```



### <span style="opacity:0.5;">function</span> <a id="7945c21e" href="#7945c21e">addSection</a>

```cpp
void addSection (
    const ffw::Color & color,
    ffw::GuiFont * font = NULL
) 
```



### <span style="opacity:0.5;">function</span> <a id="0f78533b" href="#0f78533b">addSection</a>

```cpp
void addSection (
    ffw::GuiFont * font
) 
```



### <span style="opacity:0.5;">function</span> <a id="b216151a" href="#b216151a">addSectionDefault</a>

```cpp
void addSectionDefault () 
```



### <span style="opacity:0.5;">function</span> <a id="49ca9b5e" href="#49ca9b5e">addText</a>

```cpp
void addText (
    const std::wstring & str
) 
```





