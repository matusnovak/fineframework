GuiCheckbox
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guicheckbox.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiCheckbox::Button](ffw_GuiCheckbox_Button.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiCheckbox](#1d9985e7) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|   | [GuiCheckbox](#ff6184bc) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::wstring & _label_)  |
|  virtual  | [~GuiCheckbox](#2d9ccddc) ()  |
|  void | [setLabel](#7ade9272) (const std::wstring & _label_)  |
|  const std::wstring & | [getLabel](#358f8b8c) () const  |
|  void | [setValue](#5bb938ef) (bool _value_)  |
|  bool | [getValue](#d7c2cb6d) () const  |
|  const [GuiCheckbox::Button](ffw_GuiCheckbox_Button.html) * | [getButton](#dadc07df) () const  |
|  [GuiCheckbox::Button](ffw_GuiCheckbox_Button.html) * | [getButton](#310aecbb) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#6569bd5d) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="1d9985e7" href="#1d9985e7">GuiCheckbox</a>

```cpp
 GuiCheckbox (
    GuiWindow * context,
    const std::string & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="ff6184bc" href="#ff6184bc">GuiCheckbox</a>

```cpp
 GuiCheckbox (
    GuiWindow * context,
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="2d9ccddc" href="#2d9ccddc">~GuiCheckbox</a>

```cpp
virtual  ~GuiCheckbox () 
```



### <span style="opacity:0.5;">function</span> <a id="7ade9272" href="#7ade9272">setLabel</a>

```cpp
void setLabel (
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="358f8b8c" href="#358f8b8c">getLabel</a>

```cpp
const std::wstring & getLabel () const 
```



### <span style="opacity:0.5;">function</span> <a id="5bb938ef" href="#5bb938ef">setValue</a>

```cpp
void setValue (
    bool value
) 
```



### <span style="opacity:0.5;">function</span> <a id="d7c2cb6d" href="#d7c2cb6d">getValue</a>

```cpp
bool getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="dadc07df" href="#dadc07df">getButton</a>

```cpp
inline const GuiCheckbox::Button * getButton () const 
```



### <span style="opacity:0.5;">function</span> <a id="310aecbb" href="#310aecbb">getButton</a>

```cpp
inline GuiCheckbox::Button * getButton () 
```



### <span style="opacity:0.5;">function</span> <a id="6569bd5d" href="#6569bd5d">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doc/ffw_GuiWidget.md)



