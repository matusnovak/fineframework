GuiTabs
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guitab.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiTabs::Button](ffw_GuiTabs_Button.html) |
| class [ffw::GuiTabs::Content](ffw_GuiTabs_Content.html) |
| struct [ffw::GuiTabs::Style](ffw_GuiTabs_Style.html) |
| class [ffw::GuiTabs::TopBar](ffw_GuiTabs_TopBar.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTabs](#5c77c5c9) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiTabs](#ce79634e) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#01f7bcfe) ()  |
|  [GuiTabs::Button](ffw_GuiTabs_Button.html) * | [addTab](#e6fdbb1b) ([GuiTabs::Button](ffw_GuiTabs_Button.html) * _button_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiTabs::Button](ffw_GuiTabs_Button.html) * | [addTab](#c0dd7923) (const std::string & _label_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [showTabByIndex](#2b07bbf7) (size_t _index_)  |
|  void | [showTabByWidget](#a278bdb3) (const [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [setStyle](#ca8fe06f) (const [GuiTabs::Style](ffw_GuiTabs_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="5c77c5c9" href="#5c77c5c9">GuiTabs</a>

```cpp
 GuiTabs (
    GuiWindow * context
) 
```



### _function_ <a id="ce79634e" href="#ce79634e">~GuiTabs</a>

```cpp
virtual  ~GuiTabs () 
```



### _function_ <a id="01f7bcfe" href="#01f7bcfe">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="e6fdbb1b" href="#e6fdbb1b">addTab</a>

```cpp
GuiTabs::Button * addTab (
    GuiTabs::Button * button,
    GuiWidget * widget
) 
```



### _function_ <a id="c0dd7923" href="#c0dd7923">addTab</a>

```cpp
GuiTabs::Button * addTab (
    const std::string & label,
    GuiWidget * widget
) 
```



### _function_ <a id="2b07bbf7" href="#2b07bbf7">showTabByIndex</a>

```cpp
void showTabByIndex (
    size_t index
) 
```



### _function_ <a id="a278bdb3" href="#a278bdb3">showTabByWidget</a>

```cpp
void showTabByWidget (
    const GuiWidget * widget
) 
```



### _function_ <a id="ca8fe06f" href="#ca8fe06f">setStyle</a>

```cpp
void setStyle (
    const GuiTabs::Style * style,
    bool defaults = false
) 
```





