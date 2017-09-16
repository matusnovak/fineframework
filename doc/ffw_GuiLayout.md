GuiLayout
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiFixedLayout](ffw_GuiFixedLayout.html)[ffw::GuiHorizontalLayout](ffw_GuiHorizontalLayout.html), [ffw::GuiTabs::Content](ffw_GuiTabs_Content.html), [ffw::GuiTabs::TopBar](ffw_GuiTabs_TopBar.html), [ffw::GuiVerticalLayout](ffw_GuiVerticalLayout.html), [ffw::GuiWindow::GuiBody](ffw_GuiWindow_GuiBody.html), 

The documentation for this class was generated from: `include/ffw/gui/guilayout.h`



## Public Types

| Type | Name |
| -------: | :------- |
| typedef [GuiWidget::Orientation](ffw_GuiWidget.html#47f53876) | [Orientation](#f43fd4a4) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiLayout](#39058991) ([GuiWindow](ffw_GuiWindow.html) * _context_, [Orientation](ffw_GuiWidget.html#47f53876) _orientation_)  |
|  virtual  | [~GuiLayout](#cef04790) ()  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidget](#34aa50c1) ([GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetAfter](#524bcbab) (const [GuiWidget](ffw_GuiWidget.html) * _previous_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetBefore](#7ae67ff2) (const [GuiWidget](ffw_GuiWidget.html) * _next_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [deleteWidgets](#93db9dce) ()  |
|  bool | [deleteSingleWidget](#7a7246b4) (const [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [setOrientation](#6013d2d8) ([Orientation](ffw_GuiWidget.html#47f53876) _orient_)  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#26772cfd) ()  |


## Public Types Documentation

### <span style="opacity:0.5;">typedef</span> <a id="f43fd4a4" href="#f43fd4a4">Orientation</a>

```cpp
GuiWidget::Orientation Orientation
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="39058991" href="#39058991">GuiLayout</a>

```cpp
 GuiLayout (
    GuiWindow * context,
    Orientation orientation
) 
```



### <span style="opacity:0.5;">function</span> <a id="cef04790" href="#cef04790">~GuiLayout</a>

```cpp
virtual  ~GuiLayout () 
```



### <span style="opacity:0.5;">function</span> <a id="34aa50c1" href="#34aa50c1">addWidget</a>

```cpp
GuiWidget * addWidget (
    GuiWidget * widget
) 
```



### <span style="opacity:0.5;">function</span> <a id="524bcbab" href="#524bcbab">addWidgetAfter</a>

```cpp
GuiWidget * addWidgetAfter (
    const GuiWidget * previous,
    GuiWidget * widget
) 
```



### <span style="opacity:0.5;">function</span> <a id="7ae67ff2" href="#7ae67ff2">addWidgetBefore</a>

```cpp
GuiWidget * addWidgetBefore (
    const GuiWidget * next,
    GuiWidget * widget
) 
```



### <span style="opacity:0.5;">function</span> <a id="93db9dce" href="#93db9dce">deleteWidgets</a>

```cpp
void deleteWidgets () 
```



### <span style="opacity:0.5;">function</span> <a id="7a7246b4" href="#7a7246b4">deleteSingleWidget</a>

```cpp
bool deleteSingleWidget (
    const GuiWidget * widget
) 
```



### <span style="opacity:0.5;">function</span> <a id="6013d2d8" href="#6013d2d8">setOrientation</a>

```cpp
void setOrientation (
    Orientation orient
) 
```



### <span style="opacity:0.5;">function</span> <a id="26772cfd" href="#26772cfd">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```





