GuiButton
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiButtonPrimary](ffw_GuiButtonPrimary.html)[ffw::GuiButtonToggle](ffw_GuiButtonToggle.html), [ffw::GuiButtonTogglePrimary](ffw_GuiButtonTogglePrimary.html), [ffw::GuiScrollBar::ButtonFirst](ffw_GuiScrollBar_ButtonFirst.html), [ffw::GuiScrollBar::ButtonSecond](ffw_GuiScrollBar_ButtonSecond.html), 

The documentation for this class was generated from: `include/ffw/gui/guibutton.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiButton](#c3dd01da) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|   | [GuiButton](#721de8cc) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::wstring & _label_)  |
|  virtual  | [~GuiButton](#9609e427) ()  |
|  void | [setLabel](#1e40bfd6) (const std::wstring & _label_)  |
|  const std::wstring & | [getLabel](#5ece1537) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#5aef96c3) ()  |


## Public Functions Documentation

### _function_ <a id="c3dd01da" href="#c3dd01da">GuiButton</a>

```cpp
 GuiButton (
    GuiWindow * context,
    const std::string & label
) 
```



### _function_ <a id="721de8cc" href="#721de8cc">GuiButton</a>

```cpp
 GuiButton (
    GuiWindow * context,
    const std::wstring & label
) 
```



### _function_ <a id="9609e427" href="#9609e427">~GuiButton</a>

```cpp
virtual  ~GuiButton () 
```



### _function_ <a id="1e40bfd6" href="#1e40bfd6">setLabel</a>

```cpp
void setLabel (
    const std::wstring & label
) 
```



### _function_ <a id="5ece1537" href="#5ece1537">getLabel</a>

```cpp
const std::wstring & getLabel () const 
```



### _function_ <a id="5aef96c3" href="#5aef96c3">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)



