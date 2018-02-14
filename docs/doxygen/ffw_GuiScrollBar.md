GuiScrollBar
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiscrollbar.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiScrollBar::ButtonBottom](ffw_GuiScrollBar_ButtonBottom.html) |
| class [ffw::GuiScrollBar::ButtonLeft](ffw_GuiScrollBar_ButtonLeft.html) |
| class [ffw::GuiScrollBar::ButtonRight](ffw_GuiScrollBar_ButtonRight.html) |
| class [ffw::GuiScrollBar::ButtonTop](ffw_GuiScrollBar_ButtonTop.html) |
| class [ffw::GuiScrollBar::Scroll](ffw_GuiScrollBar_Scroll.html) |
| struct [ffw::GuiScrollBar::Style](ffw_GuiScrollBar_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollBar](#4e5cf84b) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _vertical_)  |
|  virtual  | [~GuiScrollBar](#258c608b) ()  |
|  bool | [isVertical](#e0ecbca6) () const  |
|  [GuiButton](ffw_GuiButton.html) * | [getButtonFirst](#7904b802) ()  |
|  const [GuiButton](ffw_GuiButton.html) * | [getButtonFirst](#89599fef) () const  |
|  [GuiButton](ffw_GuiButton.html) * | [getButtonSecond](#0eeb5329) ()  |
|  const [GuiButton](ffw_GuiButton.html) * | [getButtonSecond](#69bef788) () const  |
|  [GuiSlider](ffw_GuiSlider.html) * | [getSlider](#4c3087c2) ()  |
|  const [GuiSlider](ffw_GuiSlider.html) * | [getSlider](#15fb371a) () const  |
|  void | [setValue](#7729262d) (const float _val_)  |
|  float | [getValue](#a01847a2) () const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getRange](#5a9bbc62) () const  |
|  void | [setRange](#771325c2) (const float _min_, const float _max_)  |
|  void | [setInversed](#1ab36503) (const bool _inversed_)  |
|  bool | [getInversed](#be2d8168) () const  |
|  void | [setIncrements](#49c0afe9) (float _inc_)  |
|  float | [getIncrements](#96dd6fd0) () const  |
|  void | [setButtonLength](#32013a28) ([GuiUnits](ffw_GuiUnits.html) _length_)  |
|  [GuiUnits](ffw_GuiUnits.html) | [getButtonLength](#15695a30) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#fe8a0917) ()  |
|  void | [setStyle](#e1632a1e) (const [GuiScrollBar::Style](ffw_GuiScrollBar_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="4e5cf84b" href="#4e5cf84b">GuiScrollBar</a>

```cpp
 GuiScrollBar (
    GuiWindow * context,
    bool vertical
) 
```



### _function_ <a id="258c608b" href="#258c608b">~GuiScrollBar</a>

```cpp
virtual  ~GuiScrollBar () 
```



### _function_ <a id="e0ecbca6" href="#e0ecbca6">isVertical</a>

```cpp
inline bool isVertical () const 
```



### _function_ <a id="7904b802" href="#7904b802">getButtonFirst</a>

```cpp
inline GuiButton * getButtonFirst () 
```



### _function_ <a id="89599fef" href="#89599fef">getButtonFirst</a>

```cpp
inline const GuiButton * getButtonFirst () const 
```



### _function_ <a id="0eeb5329" href="#0eeb5329">getButtonSecond</a>

```cpp
inline GuiButton * getButtonSecond () 
```



### _function_ <a id="69bef788" href="#69bef788">getButtonSecond</a>

```cpp
inline const GuiButton * getButtonSecond () const 
```



### _function_ <a id="4c3087c2" href="#4c3087c2">getSlider</a>

```cpp
inline GuiSlider * getSlider () 
```



### _function_ <a id="15fb371a" href="#15fb371a">getSlider</a>

```cpp
inline const GuiSlider * getSlider () const 
```



### _function_ <a id="7729262d" href="#7729262d">setValue</a>

```cpp
inline void setValue (
    const float val
) 
```



### _function_ <a id="a01847a2" href="#a01847a2">getValue</a>

```cpp
inline float getValue () const 
```



### _function_ <a id="5a9bbc62" href="#5a9bbc62">getRange</a>

```cpp
inline const ffw::Vec2f & getRange () const 
```



### _function_ <a id="771325c2" href="#771325c2">setRange</a>

```cpp
inline void setRange (
    const float min,
    const float max
) 
```



### _function_ <a id="1ab36503" href="#1ab36503">setInversed</a>

```cpp
inline void setInversed (
    const bool inversed
) 
```



### _function_ <a id="be2d8168" href="#be2d8168">getInversed</a>

```cpp
inline bool getInversed () const 
```



### _function_ <a id="49c0afe9" href="#49c0afe9">setIncrements</a>

```cpp
inline void setIncrements (
    float inc
) 
```



### _function_ <a id="96dd6fd0" href="#96dd6fd0">getIncrements</a>

```cpp
inline float getIncrements () const 
```



### _function_ <a id="32013a28" href="#32013a28">setButtonLength</a>

```cpp
void setButtonLength (
    GuiUnits length
) 
```



### _function_ <a id="15695a30" href="#15695a30">getButtonLength</a>

```cpp
inline GuiUnits getButtonLength () const 
```



### _function_ <a id="fe8a0917" href="#fe8a0917">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="e1632a1e" href="#e1632a1e">setStyle</a>

```cpp
void setStyle (
    const GuiScrollBar::Style * style,
    bool defaults = false
) 
```





