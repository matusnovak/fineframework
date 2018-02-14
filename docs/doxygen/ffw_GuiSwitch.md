GuiSwitch
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiswitch.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiSwitch::Style](ffw_GuiSwitch_Style.html) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [styleButton](#5cbf5534) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiSwitch](#04bab948) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiSwitch](#dce6b533) ()  |
|  void | [setValue](#561f3a03) (bool _value_)  |
|  bool | [getValue](#1c90a8e7) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#73a4ffeb) ()  |
|  void | [setStyle](#653cef87) (const [GuiSwitch::Style](ffw_GuiSwitch_Style.html) * _style_, bool _defaults_ = false)  |


## Protected Attributes Documentation

### _variable_ <a id="5cbf5534" href="#5cbf5534">styleButton</a>

```cpp
const GuiWidget::Style * styleButton
```





## Public Functions Documentation

### _function_ <a id="04bab948" href="#04bab948">GuiSwitch</a>

```cpp
 GuiSwitch (
    GuiWindow * context
) 
```



### _function_ <a id="dce6b533" href="#dce6b533">~GuiSwitch</a>

```cpp
virtual  ~GuiSwitch () 
```



### _function_ <a id="561f3a03" href="#561f3a03">setValue</a>

```cpp
void setValue (
    bool value
) 
```



### _function_ <a id="1c90a8e7" href="#1c90a8e7">getValue</a>

```cpp
bool getValue () const 
```



### _function_ <a id="73a4ffeb" href="#73a4ffeb">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="653cef87" href="#653cef87">setStyle</a>

```cpp
void setStyle (
    const GuiSwitch::Style * style,
    bool defaults = false
) 
```





