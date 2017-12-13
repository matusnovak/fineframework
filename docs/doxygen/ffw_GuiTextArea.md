GuiTextArea
===================================


**Inherits from:** [ffw::GuiScrollable](ffw_GuiScrollable.html)

The documentation for this class was generated from: `include/ffw/gui/guitextedit.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiTextArea::Inner](ffw_GuiTextArea_Inner.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTextArea](#f15b6eaa) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _editable_ = true)  |
|  virtual  | [~GuiTextArea](#6497f923) ()  |
|  void | [setValue](#4df72a17) (const std::wstring & _str_)  |
|  std::wstring | [getValue](#8753932e) () const  |
|  virtual void | [eventThemeChanged](#9b2994f9) (const [GuiTheme](ffw_GuiTheme.html) * _theme_)  |


## Public Functions Documentation

### _function_ <a id="f15b6eaa" href="#f15b6eaa">GuiTextArea</a>

```cpp
 GuiTextArea (
    GuiWindow * context,
    bool editable = true
) 
```



### _function_ <a id="6497f923" href="#6497f923">~GuiTextArea</a>

```cpp
virtual  ~GuiTextArea () 
```



### _function_ <a id="4df72a17" href="#4df72a17">setValue</a>

```cpp
inline void setValue (
    const std::wstring & str
) 
```



### _function_ <a id="8753932e" href="#8753932e">getValue</a>

```cpp
inline std::wstring getValue () const 
```



### _function_ <a id="9b2994f9" href="#9b2994f9">eventThemeChanged</a>

```cpp
virtual void eventThemeChanged (
    const GuiTheme * theme
) 
```



**Overrides:** [eventThemeChanged](/doxygen/ffw_GuiScrollable.md#9c82e7fd) from class [GuiScrollable](/doxygen/ffw_GuiScrollable.md)



