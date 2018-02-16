GuiLayout
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiBody](ffw_GuiBody.html)[ffw::GuiFixedLayout](ffw_GuiFixedLayout.html), [ffw::GuiHorizontalLayout](ffw_GuiHorizontalLayout.html), [ffw::GuiTabs::Content](ffw_GuiTabs_Content.html), [ffw::GuiTabs::TopBar](ffw_GuiTabs_TopBar.html), [ffw::GuiVerticalLayout](ffw_GuiVerticalLayout.html), 

The documentation for this class was generated from: `include/ffw/gui/guilayout.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiLayout::Style](ffw_GuiLayout_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiLayout](#a44666ac) ([GuiWindow](ffw_GuiWindow.html) * _context_, [GuiOrientation](ffw.html#32795b74) _orientation_)  |
|  virtual  | [~GuiLayout](#cef04790) ()  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidget](#34aa50c1) ([GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetAfter](#524bcbab) (const [GuiWidget](ffw_GuiWidget.html) * _previous_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetBefore](#7ae67ff2) (const [GuiWidget](ffw_GuiWidget.html) * _next_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [deleteWidgets](#93db9dce) ()  |
|  bool | [deleteSingleWidget](#7a7246b4) (const [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [setOrientation](#59fd5c3d) ([GuiOrientation](ffw.html#32795b74) _orient_)  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#26772cfd) ()  |
|  void | [setStyle](#21253e06) (const [GuiLayout::Style](ffw_GuiLayout_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="a44666ac" href="#a44666ac">GuiLayout</a>

```cpp
 GuiLayout (
    GuiWindow * context,
    GuiOrientation orientation
) 
```



### _function_ <a id="cef04790" href="#cef04790">~GuiLayout</a>

```cpp
virtual  ~GuiLayout () 
```



### _function_ <a id="34aa50c1" href="#34aa50c1">addWidget</a>

```cpp
GuiWidget * addWidget (
    GuiWidget * widget
) 
```



### _function_ <a id="524bcbab" href="#524bcbab">addWidgetAfter</a>

```cpp
GuiWidget * addWidgetAfter (
    const GuiWidget * previous,
    GuiWidget * widget
) 
```



### _function_ <a id="7ae67ff2" href="#7ae67ff2">addWidgetBefore</a>

```cpp
GuiWidget * addWidgetBefore (
    const GuiWidget * next,
    GuiWidget * widget
) 
```



### _function_ <a id="93db9dce" href="#93db9dce">deleteWidgets</a>

```cpp
void deleteWidgets () 
```



### _function_ <a id="7a7246b4" href="#7a7246b4">deleteSingleWidget</a>

```cpp
bool deleteSingleWidget (
    const GuiWidget * widget
) 
```



### _function_ <a id="59fd5c3d" href="#59fd5c3d">setOrientation</a>

```cpp
void setOrientation (
    GuiOrientation orient
) 
```



### _function_ <a id="26772cfd" href="#26772cfd">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="21253e06" href="#21253e06">setStyle</a>

```cpp
void setStyle (
    const GuiLayout::Style * style,
    bool defaults = false
) 
```





