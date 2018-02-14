GuiTextInput
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiScrollableTextInput::Inner](ffw_GuiScrollableTextInput_Inner.html)

The documentation for this class was generated from: `include/ffw/gui/guitextedit.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiTextInput::Line](ffw_GuiTextInput_Line.html) |
| struct [ffw::GuiTextInput::Style](ffw_GuiTextInput_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTextInput](#8d8e59f2) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _multiline_ = true, bool _editable_ = true)  |
|  virtual  | [~GuiTextInput](#3e70202b) ()  |
|  void | [setValue](#b781742f) (const std::string & _str_)  |
|  std::string | [getValue](#e821a4ff) () const  |
|  void | [appendValue](#74d14a5f) (const std::string & _str_)  |
|  bool | [setCursorIndex](#10cc05ab) (size_t _strOffset_, size_t _lineNum_)  |
|  const std::regex & | [getMatch](#5ec9d98b) () const  |
|  void | [setMatch](#fbb03c62) (const std::regex & _r_)  |
|  void | [setMatch](#03597d18) (const std::string & _r_)  |
|  const std::vector< [Line](ffw_GuiTextInput_Line.html) > & | [getLines](#07ac18c8) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#897c7db6) ()  |
|  bool | [isEmpty](#f72ee70f) () const  |
|  void | [setStyle](#f39cfdc6) (const [GuiTextInput::Style](ffw_GuiTextInput_Style.html) * _style_, bool _defaults_ = false)  |
|  const [ffw::Vec2](ffw_Vec2.html)< size_t > & | [getCursorIndex](#c80870fa) () const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getCursorPos](#e847ba07) () const  |
|  void | [insertAtCursor](#282e1606) (const std::string & _str_)  |
|  void | [removeAtCursor](#7c9260ae) (bool _forward_)  |
|  void | [moveCursor](#69f5dfc9) (bool _forward_)  |
|  void | [splitLineAtCursor](#e50b11d9) ()  |
|  void | [resetSelection](#39024739) ()  |
|  void | [moveCursorToEnd](#03e5fc6d) ()  |
|  void | [moveCursorToStart](#3a5bc0a6) ()  |
|  void | [deleteSelection](#85f13778) ()  |
|  bool | [hasSelection](#936fde57) () const  |


## Public Functions Documentation

### _function_ <a id="8d8e59f2" href="#8d8e59f2">GuiTextInput</a>

```cpp
 GuiTextInput (
    GuiWindow * context,
    bool multiline = true,
    bool editable = true
) 
```



### _function_ <a id="3e70202b" href="#3e70202b">~GuiTextInput</a>

```cpp
virtual  ~GuiTextInput () 
```



### _function_ <a id="b781742f" href="#b781742f">setValue</a>

```cpp
void setValue (
    const std::string & str
) 
```



### _function_ <a id="e821a4ff" href="#e821a4ff">getValue</a>

```cpp
std::string getValue () const 
```



### _function_ <a id="74d14a5f" href="#74d14a5f">appendValue</a>

```cpp
void appendValue (
    const std::string & str
) 
```



### _function_ <a id="10cc05ab" href="#10cc05ab">setCursorIndex</a>

```cpp
bool setCursorIndex (
    size_t strOffset,
    size_t lineNum
) 
```



### _function_ <a id="5ec9d98b" href="#5ec9d98b">getMatch</a>

```cpp
inline const std::regex & getMatch () const 
```



### _function_ <a id="fbb03c62" href="#fbb03c62">setMatch</a>

```cpp
inline void setMatch (
    const std::regex & r
) 
```



### _function_ <a id="03597d18" href="#03597d18">setMatch</a>

```cpp
inline void setMatch (
    const std::string & r
) 
```



### _function_ <a id="07ac18c8" href="#07ac18c8">getLines</a>

```cpp
inline const std::vector< Line > & getLines () const 
```



### _function_ <a id="897c7db6" href="#897c7db6">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="f72ee70f" href="#f72ee70f">isEmpty</a>

```cpp
inline bool isEmpty () const 
```



### _function_ <a id="f39cfdc6" href="#f39cfdc6">setStyle</a>

```cpp
void setStyle (
    const GuiTextInput::Style * style,
    bool defaults = false
) 
```



### _function_ <a id="c80870fa" href="#c80870fa">getCursorIndex</a>

```cpp
inline const ffw::Vec2< size_t > & getCursorIndex () const 
```



### _function_ <a id="e847ba07" href="#e847ba07">getCursorPos</a>

```cpp
inline const ffw::Vec2f & getCursorPos () const 
```



### _function_ <a id="282e1606" href="#282e1606">insertAtCursor</a>

```cpp
void insertAtCursor (
    const std::string & str
) 
```



### _function_ <a id="7c9260ae" href="#7c9260ae">removeAtCursor</a>

```cpp
void removeAtCursor (
    bool forward
) 
```



### _function_ <a id="69f5dfc9" href="#69f5dfc9">moveCursor</a>

```cpp
void moveCursor (
    bool forward
) 
```



### _function_ <a id="e50b11d9" href="#e50b11d9">splitLineAtCursor</a>

```cpp
void splitLineAtCursor () 
```



### _function_ <a id="39024739" href="#39024739">resetSelection</a>

```cpp
void resetSelection () 
```



### _function_ <a id="03e5fc6d" href="#03e5fc6d">moveCursorToEnd</a>

```cpp
void moveCursorToEnd () 
```



### _function_ <a id="3a5bc0a6" href="#3a5bc0a6">moveCursorToStart</a>

```cpp
void moveCursorToStart () 
```



### _function_ <a id="85f13778" href="#85f13778">deleteSelection</a>

```cpp
void deleteSelection () 
```



### _function_ <a id="936fde57" href="#936fde57">hasSelection</a>

```cpp
inline bool hasSelection () const 
```





