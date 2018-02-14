Button
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiradio.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiRadio::Button::Style](ffw_GuiRadio_Button_Style.html) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  [GuiRadio::Value](ffw_GuiRadio_Value.html) * | [group](#9c27c888) |
|  [GuiRadio](ffw_GuiRadio.html) * | [parentradio](#0681ebf9) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Button](#bf6dcfa3) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~Button](#655c734d) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#fef6bf2b) ()  |
|  void | [setStyle](#d5617a55) (const [Button::Style](ffw_GuiRadio_Button_Style.html) * _style_, bool _defaults_ = false)  |


## Public Attributes Documentation

### _variable_ <a id="9c27c888" href="#9c27c888">group</a>

```cpp
GuiRadio::Value * group
```



### _variable_ <a id="0681ebf9" href="#0681ebf9">parentradio</a>

```cpp
GuiRadio * parentradio
```





## Public Functions Documentation

### _function_ <a id="bf6dcfa3" href="#bf6dcfa3">Button</a>

```cpp
 Button (
    GuiWindow * context
) 
```



### _function_ <a id="655c734d" href="#655c734d">~Button</a>

```cpp
virtual  ~Button () 
```



### _function_ <a id="fef6bf2b" href="#fef6bf2b">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="d5617a55" href="#d5617a55">setStyle</a>

```cpp
void setStyle (
    const Button::Style * style,
    bool defaults = false
) 
```





