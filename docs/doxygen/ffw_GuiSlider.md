GuiSlider
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiScrollBar::Scroll](ffw_GuiScrollBar_Scroll.html)

The documentation for this class was generated from: `include/ffw/gui/guislider.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiSlider::Style](ffw_GuiSlider_Style.html) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [styleButton](#b2ffbd70) |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [styleBar](#f3291468) |
|  [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > | [buttonSize](#824cf044) |
|  [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > | [barSize](#6fe843a0) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiSlider](#82dc0131) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _vertical_)  |
|  virtual  | [~GuiSlider](#b43da7db) ()  |
|  bool | [isVertical](#d9ff4155) () const  |
|  void | [setValue](#a849b991) (float _val_)  |
|  float | [getValue](#59fbe0d1) () const  |
|  void | [setBarSize](#825c6d49) (const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & _s_)  |
|  const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & | [getBarSize](#65146c10) () const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getRange](#d433aaa8) () const  |
|  void | [setRange](#7c0115b8) (float _min_, float _max_)  |
|  void | [setButtonSize](#831067e8) (const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & _s_)  |
|  const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & | [getButtonSize](#6a1b55ef) () const  |
|  void | [setInversed](#4c378fbb) (bool _inversed_)  |
|  bool | [getInversed](#f0ab2684) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#5e6a579a) ()  |
|  void | [setBarStyleGroup](#2f0e3bed) (const [GuiWidget::Style](ffw_GuiWidget_Style.html) * _style_)  |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [getBarStyleGroup](#dd2a6ba3) () const  |
|  void | [setButtonStyleGroup](#0f2af480) (const [GuiWidget::Style](ffw_GuiWidget_Style.html) * _style_)  |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [getButtonStyleGroup](#dd4cedff) () const  |
|  void | [setStyle](#1db6e6c8) (const [GuiSlider::Style](ffw_GuiSlider_Style.html) * _style_, bool _defaults_ = false)  |


## Protected Attributes Documentation

### _variable_ <a id="b2ffbd70" href="#b2ffbd70">styleButton</a>

```cpp
const GuiWidget::Style * styleButton
```



### _variable_ <a id="f3291468" href="#f3291468">styleBar</a>

```cpp
const GuiWidget::Style * styleBar
```



### _variable_ <a id="824cf044" href="#824cf044">buttonSize</a>

```cpp
ffw::Vec2< GuiUnits > buttonSize
```



### _variable_ <a id="6fe843a0" href="#6fe843a0">barSize</a>

```cpp
ffw::Vec2< GuiUnits > barSize
```





## Public Functions Documentation

### _function_ <a id="82dc0131" href="#82dc0131">GuiSlider</a>

```cpp
 GuiSlider (
    GuiWindow * context,
    bool vertical
) 
```



### _function_ <a id="b43da7db" href="#b43da7db">~GuiSlider</a>

```cpp
virtual  ~GuiSlider () 
```



### _function_ <a id="d9ff4155" href="#d9ff4155">isVertical</a>

```cpp
bool isVertical () const 
```



### _function_ <a id="a849b991" href="#a849b991">setValue</a>

```cpp
void setValue (
    float val
) 
```



### _function_ <a id="59fbe0d1" href="#59fbe0d1">getValue</a>

```cpp
float getValue () const 
```



### _function_ <a id="825c6d49" href="#825c6d49">setBarSize</a>

```cpp
void setBarSize (
    const ffw::Vec2< GuiUnits > & s
) 
```



### _function_ <a id="65146c10" href="#65146c10">getBarSize</a>

```cpp
inline const ffw::Vec2< GuiUnits > & getBarSize () const 
```



### _function_ <a id="d433aaa8" href="#d433aaa8">getRange</a>

```cpp
const ffw::Vec2f & getRange () const 
```



### _function_ <a id="7c0115b8" href="#7c0115b8">setRange</a>

```cpp
void setRange (
    float min,
    float max
) 
```



### _function_ <a id="831067e8" href="#831067e8">setButtonSize</a>

```cpp
void setButtonSize (
    const ffw::Vec2< GuiUnits > & s
) 
```



### _function_ <a id="6a1b55ef" href="#6a1b55ef">getButtonSize</a>

```cpp
inline const ffw::Vec2< GuiUnits > & getButtonSize () const 
```



### _function_ <a id="4c378fbb" href="#4c378fbb">setInversed</a>

```cpp
void setInversed (
    bool inversed
) 
```



### _function_ <a id="f0ab2684" href="#f0ab2684">getInversed</a>

```cpp
bool getInversed () const 
```



### _function_ <a id="5e6a579a" href="#5e6a579a">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="2f0e3bed" href="#2f0e3bed">setBarStyleGroup</a>

```cpp
void setBarStyleGroup (
    const GuiWidget::Style * style
) 
```



### _function_ <a id="dd2a6ba3" href="#dd2a6ba3">getBarStyleGroup</a>

```cpp
inline const GuiWidget::Style * getBarStyleGroup () const 
```



### _function_ <a id="0f2af480" href="#0f2af480">setButtonStyleGroup</a>

```cpp
void setButtonStyleGroup (
    const GuiWidget::Style * style
) 
```



### _function_ <a id="dd4cedff" href="#dd4cedff">getButtonStyleGroup</a>

```cpp
inline const GuiWidget::Style * getButtonStyleGroup () const 
```



### _function_ <a id="1db6e6c8" href="#1db6e6c8">setStyle</a>

```cpp
void setStyle (
    const GuiSlider::Style * style,
    bool defaults = false
) 
```





