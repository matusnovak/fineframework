GuiTextInput
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiTextArea::Inner](ffw_GuiTextArea_Inner.html)

The documentation for this class was generated from: `include/ffw/gui/guitextedit.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiTextInput::TextLine](ffw_GuiTextInput_TextLine.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTextInput](#c41081d7) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _multiline_ = false, bool _editable_ = true)  |
|  virtual  | [~GuiTextInput](#affb5aeb) ()  |
|  void | [setValue](#059c3d8f) (const std::wstring & _str_)  |
|  std::wstring | [getValue](#358623b9) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#897c7db6) ()  |
|  bool | [isEmpty](#f72ee70f) () const  |
|  void | [setMatch](#cdc0ecc1) (const std::wstring & _match_)  |
|  const std::wstring & | [getMatch](#13a07b17) () const  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="c41081d7" href="#c41081d7">GuiTextInput</a>

```cpp
 GuiTextInput (
    GuiWindow * context,
    bool multiline = false,
    bool editable = true
) 
```



### <span style="opacity:0.5;">function</span> <a id="affb5aeb" href="#affb5aeb">~GuiTextInput</a>

```cpp
virtual  ~GuiTextInput () 
```



### <span style="opacity:0.5;">function</span> <a id="059c3d8f" href="#059c3d8f">setValue</a>

```cpp
void setValue (
    const std::wstring & str
) 
```



### <span style="opacity:0.5;">function</span> <a id="358623b9" href="#358623b9">getValue</a>

```cpp
std::wstring getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="897c7db6" href="#897c7db6">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f)

### <span style="opacity:0.5;">function</span> <a id="f72ee70f" href="#f72ee70f">isEmpty</a>

```cpp
bool isEmpty () const 
```



### <span style="opacity:0.5;">function</span> <a id="cdc0ecc1" href="#cdc0ecc1">setMatch</a>

```cpp
inline void setMatch (
    const std::wstring & match
) 
```



### <span style="opacity:0.5;">function</span> <a id="13a07b17" href="#13a07b17">getMatch</a>

```cpp
inline const std::wstring & getMatch () const 
```





