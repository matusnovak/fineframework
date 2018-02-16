GuiScrollableLayout
===================================


**Inherits from:** [ffw::GuiScrollable](ffw_GuiScrollable.html)

**Implemented by:** [ffw::GuiList](ffw_GuiList.html)

The documentation for this class was generated from: `include/ffw/gui/guiscrollable.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiScrollableLayout::Style](ffw_GuiScrollableLayout_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollableLayout](#ccbe1450) ([GuiWindow](ffw_GuiWindow.html) * _context_, [GuiOrientation](ffw.html#32795b74) _orientation_, bool _hori_, bool _vert_)  |
|  virtual  | [~GuiScrollableLayout](#676cde1d) ()  |
|  [GuiLayout](ffw_GuiLayout.html) * | [getInner](#79b46f8e) ()  |
|  const [GuiLayout](ffw_GuiLayout.html) * | [getInner](#b0f84706) () const  |
|  virtual void | [eventThemeChanged](#d8849fc4) (const [GuiTheme](ffw_GuiTheme.html) * _theme_, bool _defaults_)  |
|  void | [setStyle](#69780acf) (const [GuiScrollableLayout::Style](ffw_GuiScrollableLayout_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="ccbe1450" href="#ccbe1450">GuiScrollableLayout</a>

```cpp
 GuiScrollableLayout (
    GuiWindow * context,
    GuiOrientation orientation,
    bool hori,
    bool vert
) 
```



### _function_ <a id="676cde1d" href="#676cde1d">~GuiScrollableLayout</a>

```cpp
virtual  ~GuiScrollableLayout () 
```



### _function_ <a id="79b46f8e" href="#79b46f8e">getInner</a>

```cpp
inline GuiLayout * getInner () 
```



### _function_ <a id="b0f84706" href="#b0f84706">getInner</a>

```cpp
inline const GuiLayout * getInner () const 
```



### _function_ <a id="d8849fc4" href="#d8849fc4">eventThemeChanged</a>

```cpp
virtual void eventThemeChanged (
    const GuiTheme * theme,
    bool defaults
) 
```



**Overrides:** [eventThemeChanged](/doxygen/ffw_GuiScrollable.md#d5c03d3f) from class [GuiScrollable](/doxygen/ffw_GuiScrollable.md)

### _function_ <a id="69780acf" href="#69780acf">setStyle</a>

```cpp
void setStyle (
    const GuiScrollableLayout::Style * style,
    bool defaults = false
) 
```





