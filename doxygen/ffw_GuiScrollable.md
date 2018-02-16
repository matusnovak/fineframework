GuiScrollable
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiScrollableLayout](ffw_GuiScrollableLayout.html)[ffw::GuiScrollableTextInput](ffw_GuiScrollableTextInput.html), 

The documentation for this class was generated from: `include/ffw/gui/guiscrollable.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiScrollable::Style](ffw_GuiScrollable_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollable](#9da48fbd) ([GuiWindow](ffw_GuiWindow.html) * _context_, [GuiWidget](ffw_GuiWidget.html) * _widget_, bool _hori_, bool _vert_)  |
|  virtual  | [~GuiScrollable](#5be95f84) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#58fd9b8a) ()  |
|  void | [setScrollbarThickness](#9d03fe74) (float _px_)  |
|  void | [setScrollValues](#d66b1e98) (float _hori_, float _vert_)  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getScrollValues](#8f957bd8) () const  |
|  float | [getScrollbarThickness](#d5abfdc3) () const  |
|  [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getVscroll](#a14e4906) ()  |
|  const [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getVscroll](#9e4eb2e6) () const  |
|  [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getHscroll](#0f65bc66) ()  |
|  const [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getHscroll](#9482fb26) () const  |
|  void | [setScrollIncrements](#9af68e78) (const float _inc_)  |
|  float | [getScrollIncrements](#368ce45e) () const  |
|  void | [setStyle](#97e8826c) (const [GuiScrollable::Style](ffw_GuiScrollable_Style.html) * _style_, bool _defaults_ = false)  |


## Protected Functions

| Type | Name |
| -------: | :------- |
|  [ffw::GuiWidget](ffw_GuiWidget.html) * | [getInnerAsWidget](#a4ed7453) ()  |
|  const [ffw::GuiWidget](ffw_GuiWidget.html) * | [getInnerAsWidget](#dbe6de5f) () const  |


## Public Functions Documentation

### _function_ <a id="9da48fbd" href="#9da48fbd">GuiScrollable</a>

```cpp
 GuiScrollable (
    GuiWindow * context,
    GuiWidget * widget,
    bool hori,
    bool vert
) 
```



### _function_ <a id="5be95f84" href="#5be95f84">~GuiScrollable</a>

```cpp
virtual  ~GuiScrollable () 
```



### _function_ <a id="58fd9b8a" href="#58fd9b8a">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="9d03fe74" href="#9d03fe74">setScrollbarThickness</a>

```cpp
void setScrollbarThickness (
    float px
) 
```



### _function_ <a id="d66b1e98" href="#d66b1e98">setScrollValues</a>

```cpp
void setScrollValues (
    float hori,
    float vert
) 
```



### _function_ <a id="8f957bd8" href="#8f957bd8">getScrollValues</a>

```cpp
ffw::Vec2f getScrollValues () const 
```



### _function_ <a id="d5abfdc3" href="#d5abfdc3">getScrollbarThickness</a>

```cpp
inline float getScrollbarThickness () const 
```



### _function_ <a id="a14e4906" href="#a14e4906">getVscroll</a>

```cpp
inline ffw::GuiScrollBar * getVscroll () 
```



### _function_ <a id="9e4eb2e6" href="#9e4eb2e6">getVscroll</a>

```cpp
inline const ffw::GuiScrollBar * getVscroll () const 
```



### _function_ <a id="0f65bc66" href="#0f65bc66">getHscroll</a>

```cpp
inline ffw::GuiScrollBar * getHscroll () 
```



### _function_ <a id="9482fb26" href="#9482fb26">getHscroll</a>

```cpp
inline const ffw::GuiScrollBar * getHscroll () const 
```



### _function_ <a id="9af68e78" href="#9af68e78">setScrollIncrements</a>

```cpp
inline void setScrollIncrements (
    const float inc
) 
```



### _function_ <a id="368ce45e" href="#368ce45e">getScrollIncrements</a>

```cpp
inline float getScrollIncrements () const 
```



### _function_ <a id="97e8826c" href="#97e8826c">setStyle</a>

```cpp
void setStyle (
    const GuiScrollable::Style * style,
    bool defaults = false
) 
```





## Protected Functions Documentation

### _function_ <a id="a4ed7453" href="#a4ed7453">getInnerAsWidget</a>

```cpp
inline ffw::GuiWidget * getInnerAsWidget () 
```



### _function_ <a id="dbe6de5f" href="#dbe6de5f">getInnerAsWidget</a>

```cpp
inline const ffw::GuiWidget * getInnerAsWidget () const 
```





