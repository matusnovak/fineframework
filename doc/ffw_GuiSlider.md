GuiSlider
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiScrollBar::Scroll](ffw_GuiScrollBar_Scroll.html)

The documentation for this class was generated from: `include/ffw/gui/guislider.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [styleButton](#2e44fd50) |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [styleBar](#b62f702b) |
|  [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > | [buttonSize](#824cf044) |
|  [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > | [barSize](#6fe843a0) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiSlider](#82dc0131) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _vertical_)  |
|  virtual  | [~GuiSlider](#9551a553) ()  |
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
|  void | [setBarStyleGroup](#c1c637e7) (const [GuiStyleGroup](ffw_GuiStyleGroup.html) * _style_)  |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [getBarStyleGroup](#57c7411b) () const  |
|  void | [setButtonStyleGroup](#c0ebf3ec) (const [GuiStyleGroup](ffw_GuiStyleGroup.html) * _style_)  |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [getButtonStyleGroup](#afa9e340) () const  |


## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="2e44fd50" href="#2e44fd50">styleButton</a>

```cpp
const GuiStyleGroup * styleButton
```



### <span style="opacity:0.5;">variable</span> <a id="b62f702b" href="#b62f702b">styleBar</a>

```cpp
const GuiStyleGroup * styleBar
```



### <span style="opacity:0.5;">variable</span> <a id="824cf044" href="#824cf044">buttonSize</a>

```cpp
ffw::Vec2< GuiUnits > buttonSize
```



### <span style="opacity:0.5;">variable</span> <a id="6fe843a0" href="#6fe843a0">barSize</a>

```cpp
ffw::Vec2< GuiUnits > barSize
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="82dc0131" href="#82dc0131">GuiSlider</a>

```cpp
 GuiSlider (
    GuiWindow * context,
    bool vertical
) 
```



### <span style="opacity:0.5;">function</span> <a id="9551a553" href="#9551a553">~GuiSlider</a>

```cpp
virtual  ~GuiSlider () 
```



### <span style="opacity:0.5;">function</span> <a id="d9ff4155" href="#d9ff4155">isVertical</a>

```cpp
bool isVertical () const 
```



### <span style="opacity:0.5;">function</span> <a id="a849b991" href="#a849b991">setValue</a>

```cpp
void setValue (
    float val
) 
```



### <span style="opacity:0.5;">function</span> <a id="59fbe0d1" href="#59fbe0d1">getValue</a>

```cpp
float getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="825c6d49" href="#825c6d49">setBarSize</a>

```cpp
void setBarSize (
    const ffw::Vec2< GuiUnits > & s
) 
```



### <span style="opacity:0.5;">function</span> <a id="65146c10" href="#65146c10">getBarSize</a>

```cpp
inline const ffw::Vec2< GuiUnits > & getBarSize () const 
```



### <span style="opacity:0.5;">function</span> <a id="d433aaa8" href="#d433aaa8">getRange</a>

```cpp
const ffw::Vec2f & getRange () const 
```



### <span style="opacity:0.5;">function</span> <a id="7c0115b8" href="#7c0115b8">setRange</a>

```cpp
void setRange (
    float min,
    float max
) 
```



### <span style="opacity:0.5;">function</span> <a id="831067e8" href="#831067e8">setButtonSize</a>

```cpp
void setButtonSize (
    const ffw::Vec2< GuiUnits > & s
) 
```



### <span style="opacity:0.5;">function</span> <a id="6a1b55ef" href="#6a1b55ef">getButtonSize</a>

```cpp
inline const ffw::Vec2< GuiUnits > & getButtonSize () const 
```



### <span style="opacity:0.5;">function</span> <a id="4c378fbb" href="#4c378fbb">setInversed</a>

```cpp
void setInversed (
    bool inversed
) 
```



### <span style="opacity:0.5;">function</span> <a id="f0ab2684" href="#f0ab2684">getInversed</a>

```cpp
bool getInversed () const 
```



### <span style="opacity:0.5;">function</span> <a id="5e6a579a" href="#5e6a579a">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doc/ffw_GuiWidget.md)

### <span style="opacity:0.5;">function</span> <a id="c1c637e7" href="#c1c637e7">setBarStyleGroup</a>

```cpp
inline void setBarStyleGroup (
    const GuiStyleGroup * style
) 
```



### <span style="opacity:0.5;">function</span> <a id="57c7411b" href="#57c7411b">getBarStyleGroup</a>

```cpp
inline const GuiStyleGroup * getBarStyleGroup () const 
```



### <span style="opacity:0.5;">function</span> <a id="c0ebf3ec" href="#c0ebf3ec">setButtonStyleGroup</a>

```cpp
inline void setButtonStyleGroup (
    const GuiStyleGroup * style
) 
```



### <span style="opacity:0.5;">function</span> <a id="afa9e340" href="#afa9e340">getButtonStyleGroup</a>

```cpp
inline const GuiStyleGroup * getButtonStyleGroup () const 
```





