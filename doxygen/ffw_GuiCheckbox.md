GuiCheckbox
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guicheckbox.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiCheckbox::Button](ffw_GuiCheckbox_Button.html) |
| struct [ffw::GuiCheckbox::Style](ffw_GuiCheckbox_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiCheckbox](#1d9985e7) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|  virtual  | [~GuiCheckbox](#2682e1ea) ()  |
|  void | [setLabel](#a1842d55) (const std::string & _label_)  |
|  const std::string & | [getLabel](#aa71a486) () const  |
|  void | [setValue](#5bb938ef) (bool _value_)  |
|  bool | [getValue](#d7c2cb6d) () const  |
|  const [GuiCheckbox::Button](ffw_GuiCheckbox_Button.html) * | [getButton](#dadc07df) () const  |
|  [GuiCheckbox::Button](ffw_GuiCheckbox_Button.html) * | [getButton](#310aecbb) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#6569bd5d) ()  |
|  void | [setStyle](#f766d555) (const [GuiCheckbox::Style](ffw_GuiCheckbox_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="1d9985e7" href="#1d9985e7">GuiCheckbox</a>

```cpp
 GuiCheckbox (
    GuiWindow * context,
    const std::string & label
) 
```



### _function_ <a id="2682e1ea" href="#2682e1ea">~GuiCheckbox</a>

```cpp
virtual  ~GuiCheckbox () 
```



### _function_ <a id="a1842d55" href="#a1842d55">setLabel</a>

```cpp
void setLabel (
    const std::string & label
) 
```



### _function_ <a id="aa71a486" href="#aa71a486">getLabel</a>

```cpp
const std::string & getLabel () const 
```



### _function_ <a id="5bb938ef" href="#5bb938ef">setValue</a>

```cpp
void setValue (
    bool value
) 
```



### _function_ <a id="d7c2cb6d" href="#d7c2cb6d">getValue</a>

```cpp
bool getValue () const 
```



### _function_ <a id="dadc07df" href="#dadc07df">getButton</a>

```cpp
inline const GuiCheckbox::Button * getButton () const 
```



### _function_ <a id="310aecbb" href="#310aecbb">getButton</a>

```cpp
inline GuiCheckbox::Button * getButton () 
```



### _function_ <a id="6569bd5d" href="#6569bd5d">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="f766d555" href="#f766d555">setStyle</a>

```cpp
void setStyle (
    const GuiCheckbox::Style * style,
    bool defaults = false
) 
```





