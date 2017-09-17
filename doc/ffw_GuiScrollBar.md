GuiScrollBar
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiscrollbar.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiScrollBar::ButtonFirst](ffw_GuiScrollBar_ButtonFirst.html) |
| class [ffw::GuiScrollBar::ButtonSecond](ffw_GuiScrollBar_ButtonSecond.html) |
| class [ffw::GuiScrollBar::Scroll](ffw_GuiScrollBar_Scroll.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollBar](#4e5cf84b) ([GuiWindow](ffw_GuiWindow.html) * _context_, bool _vertical_)  |
|  bool | [isVertical](#e0ecbca6) () const  |
|  [GuiButton](ffw_GuiButton.html) * | [getButtonFirst](#7904b802) ()  |
|  const [GuiButton](ffw_GuiButton.html) * | [getButtonFirst](#89599fef) () const  |
|  [GuiButton](ffw_GuiButton.html) * | [getButtonSecond](#0eeb5329) ()  |
|  const [GuiButton](ffw_GuiButton.html) * | [getButtonSecond](#69bef788) () const  |
|  [GuiSlider](ffw_GuiSlider.html) * | [getSlider](#4c3087c2) ()  |
|  const [GuiSlider](ffw_GuiSlider.html) * | [getSlider](#15fb371a) () const  |
|  void | [setValue](#f27ee129) (float _val_)  |
|  float | [getValue](#a01847a2) () const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getRange](#5a9bbc62) () const  |
|  void | [setRange](#234c17f2) (float _min_, float _max_)  |
|  void | [setInversed](#7af1078a) (bool _inversed_)  |
|  bool | [getInversed](#be2d8168) () const  |
|  void | [setIncrements](#49c0afe9) (float _inc_)  |
|  float | [getIncrements](#96dd6fd0) () const  |
|  void | [setButtonLength](#32013a28) ([GuiUnits](ffw_GuiUnits.html) _length_)  |
|  [GuiUnits](ffw_GuiUnits.html) | [getButtonLength](#15695a30) () const  |
|  virtual  | [~GuiScrollBar](#009ece11) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#fe8a0917) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="4e5cf84b" href="#4e5cf84b">GuiScrollBar</a>

```cpp
 GuiScrollBar (
    GuiWindow * context,
    bool vertical
) 
```



### <span style="opacity:0.5;">function</span> <a id="e0ecbca6" href="#e0ecbca6">isVertical</a>

```cpp
inline bool isVertical () const 
```



### <span style="opacity:0.5;">function</span> <a id="7904b802" href="#7904b802">getButtonFirst</a>

```cpp
inline GuiButton * getButtonFirst () 
```



### <span style="opacity:0.5;">function</span> <a id="89599fef" href="#89599fef">getButtonFirst</a>

```cpp
inline const GuiButton * getButtonFirst () const 
```



### <span style="opacity:0.5;">function</span> <a id="0eeb5329" href="#0eeb5329">getButtonSecond</a>

```cpp
inline GuiButton * getButtonSecond () 
```



### <span style="opacity:0.5;">function</span> <a id="69bef788" href="#69bef788">getButtonSecond</a>

```cpp
inline const GuiButton * getButtonSecond () const 
```



### <span style="opacity:0.5;">function</span> <a id="4c3087c2" href="#4c3087c2">getSlider</a>

```cpp
inline GuiSlider * getSlider () 
```



### <span style="opacity:0.5;">function</span> <a id="15fb371a" href="#15fb371a">getSlider</a>

```cpp
inline const GuiSlider * getSlider () const 
```



### <span style="opacity:0.5;">function</span> <a id="f27ee129" href="#f27ee129">setValue</a>

```cpp
inline void setValue (
    float val
) 
```



### <span style="opacity:0.5;">function</span> <a id="a01847a2" href="#a01847a2">getValue</a>

```cpp
inline float getValue () const 
```



### <span style="opacity:0.5;">function</span> <a id="5a9bbc62" href="#5a9bbc62">getRange</a>

```cpp
inline const ffw::Vec2f & getRange () const 
```



### <span style="opacity:0.5;">function</span> <a id="234c17f2" href="#234c17f2">setRange</a>

```cpp
inline void setRange (
    float min,
    float max
) 
```



### <span style="opacity:0.5;">function</span> <a id="7af1078a" href="#7af1078a">setInversed</a>

```cpp
inline void setInversed (
    bool inversed
) 
```



### <span style="opacity:0.5;">function</span> <a id="be2d8168" href="#be2d8168">getInversed</a>

```cpp
inline bool getInversed () const 
```



### <span style="opacity:0.5;">function</span> <a id="49c0afe9" href="#49c0afe9">setIncrements</a>

```cpp
inline void setIncrements (
    float inc
) 
```



### <span style="opacity:0.5;">function</span> <a id="96dd6fd0" href="#96dd6fd0">getIncrements</a>

```cpp
inline float getIncrements () const 
```



### <span style="opacity:0.5;">function</span> <a id="32013a28" href="#32013a28">setButtonLength</a>

```cpp
void setButtonLength (
    GuiUnits length
) 
```



### <span style="opacity:0.5;">function</span> <a id="15695a30" href="#15695a30">getButtonLength</a>

```cpp
inline GuiUnits getButtonLength () const 
```



### <span style="opacity:0.5;">function</span> <a id="009ece11" href="#009ece11">~GuiScrollBar</a>

```cpp
virtual  ~GuiScrollBar () 
```



### <span style="opacity:0.5;">function</span> <a id="fe8a0917" href="#fe8a0917">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doc/ffw_GuiWidget.md#c12efa3f)



