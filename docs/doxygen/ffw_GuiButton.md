GuiButton
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiButtonPrimary](ffw_GuiButtonPrimary.html)[ffw::GuiButtonToggle](ffw_GuiButtonToggle.html), [ffw::GuiScrollBar::ButtonBottom](ffw_GuiScrollBar_ButtonBottom.html), [ffw::GuiScrollBar::ButtonLeft](ffw_GuiScrollBar_ButtonLeft.html), [ffw::GuiScrollBar::ButtonRight](ffw_GuiScrollBar_ButtonRight.html), [ffw::GuiScrollBar::ButtonTop](ffw_GuiScrollBar_ButtonTop.html), 

The documentation for this class was generated from: `include/ffw/gui/guibutton.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiButton::Style](ffw_GuiButton_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiButton](#c3dd01da) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|  virtual  | [~GuiButton](#ff078370) ()  |
|  void | [setLabel](#1b7ab665) (const std::string & _label_)  |
|  const std::string & | [getLabel](#dde44fd6) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#5aef96c3) ()  |
|  void | [setStyle](#c68f3759) (const [GuiButton::Style](ffw_GuiButton_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="c3dd01da" href="#c3dd01da">GuiButton</a>

```cpp
 GuiButton (
    GuiWindow * context,
    const std::string & label
) 
```



### _function_ <a id="ff078370" href="#ff078370">~GuiButton</a>

```cpp
virtual  ~GuiButton () 
```



### _function_ <a id="1b7ab665" href="#1b7ab665">setLabel</a>

```cpp
void setLabel (
    const std::string & label
) 
```



### _function_ <a id="dde44fd6" href="#dde44fd6">getLabel</a>

```cpp
const std::string & getLabel () const 
```



### _function_ <a id="5aef96c3" href="#5aef96c3">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="c68f3759" href="#c68f3759">setStyle</a>

```cpp
void setStyle (
    const GuiButton::Style * style,
    bool defaults = false
) 
```





