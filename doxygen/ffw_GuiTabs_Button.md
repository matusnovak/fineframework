Button
===================================


**Inherits from:** [ffw::GuiButtonToggle](ffw_GuiButtonToggle.html)

The documentation for this class was generated from: `include/ffw/gui/guitab.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Button](#acdd36a0) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|   | [Button](#b16c9def) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::wstring & _label_)  |
|  virtual  | [~Button](#86312667) ()  |
|  virtual void | [eventThemeChanged](#b0d5764b) (const [GuiTheme](ffw_GuiTheme.html) * _theme_)  |


## Public Functions Documentation

### _function_ <a id="acdd36a0" href="#acdd36a0">Button</a>

```cpp
 Button (
    GuiWindow * context,
    const std::string & label
) 
```



### _function_ <a id="b16c9def" href="#b16c9def">Button</a>

```cpp
 Button (
    GuiWindow * context,
    const std::wstring & label
) 
```



### _function_ <a id="86312667" href="#86312667">~Button</a>

```cpp
virtual  ~Button () 
```



### _function_ <a id="b0d5764b" href="#b0d5764b">eventThemeChanged</a>

```cpp
virtual void eventThemeChanged (
    const GuiTheme * theme
) 
```



**Overrides:** [eventThemeChanged](/doxygen/ffw_GuiButton.md#e9b0ba14) from class [GuiButton](/doxygen/ffw_GuiButton.md)



