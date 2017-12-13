GuiTabs
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guitab.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiTabs::Button](ffw_GuiTabs_Button.html) |
| class [ffw::GuiTabs::Content](ffw_GuiTabs_Content.html) |
| class [ffw::GuiTabs::TopBar](ffw_GuiTabs_TopBar.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTabs](#5c77c5c9) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiTabs](#019aaccd) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#01f7bcfe) ()  |
|  std::pair< [GuiButtonToggle](ffw_GuiButtonToggle.html) *, [GuiWidget](ffw_GuiWidget.html) * > | [addTab](#6ffa5184) ([GuiButtonToggle](ffw_GuiButtonToggle.html) * _button_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  std::pair< [GuiButtonToggle](ffw_GuiButtonToggle.html) *, [GuiWidget](ffw_GuiWidget.html) * > | [addTab](#54f7098b) (const std::string & _label_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  std::pair< [GuiButtonToggle](ffw_GuiButtonToggle.html) *, [GuiWidget](ffw_GuiWidget.html) * > | [addTab](#28b7db76) (const std::wstring & _label_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [showTabByIndex](#2b07bbf7) (size_t _index_)  |
|  void | [showTabByWidget](#a278bdb3) (const [GuiWidget](ffw_GuiWidget.html) * _widget_)  |


## Public Functions Documentation

### _function_ <a id="5c77c5c9" href="#5c77c5c9">GuiTabs</a>

```cpp
 GuiTabs (
    GuiWindow * context
) 
```



### _function_ <a id="019aaccd" href="#019aaccd">~GuiTabs</a>

```cpp
virtual  ~GuiTabs () 
```



### _function_ <a id="01f7bcfe" href="#01f7bcfe">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="6ffa5184" href="#6ffa5184">addTab</a>

```cpp
std::pair< GuiButtonToggle *, GuiWidget * > addTab (
    GuiButtonToggle * button,
    GuiWidget * widget
) 
```



### _function_ <a id="54f7098b" href="#54f7098b">addTab</a>

```cpp
std::pair< GuiButtonToggle *, GuiWidget * > addTab (
    const std::string & label,
    GuiWidget * widget
) 
```



### _function_ <a id="28b7db76" href="#28b7db76">addTab</a>

```cpp
std::pair< GuiButtonToggle *, GuiWidget * > addTab (
    const std::wstring & label,
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





