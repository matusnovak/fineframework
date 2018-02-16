Button
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guicheckbox.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiCheckbox::Button::Style](ffw_GuiCheckbox_Button_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Button](#cbe50d77) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~Button](#722af5bc) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#b8a3ca77) ()  |
|  void | [setStyle](#19565aa4) (const [Button::Style](ffw_GuiCheckbox_Button_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="cbe50d77" href="#cbe50d77">Button</a>

```cpp
 Button (
    GuiWindow * context
) 
```



### _function_ <a id="722af5bc" href="#722af5bc">~Button</a>

```cpp
virtual  ~Button () 
```



### _function_ <a id="b8a3ca77" href="#b8a3ca77">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="19565aa4" href="#19565aa4">setStyle</a>

```cpp
void setStyle (
    const Button::Style * style,
    bool defaults = false
) 
```





