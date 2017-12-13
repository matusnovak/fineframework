GuiScrollable
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

**Implemented by:** [ffw::GuiScrollableLayout](ffw_GuiScrollableLayout.html)[ffw::GuiTextArea](ffw_GuiTextArea.html), 

The documentation for this class was generated from: `include/ffw/gui/guiscrollable.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollable](#9da48fbd) ([GuiWindow](ffw_GuiWindow.html) * _context_, [GuiWidget](ffw_GuiWidget.html) * _widget_, bool _hori_, bool _vert_)  |
|  virtual  | [~GuiScrollable](#6c487500) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#58fd9b8a) ()  |
|  void | [setScrollbarThickness](#9d03fe74) (float _px_)  |
|  void | [setScrollValues](#d66b1e98) (float _hori_, float _vert_)  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getScrollValues](#8f957bd8) () const  |
|  float | [getScrollbarThickness](#d5abfdc3) () const  |
|  [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getVscroll](#a14e4906) ()  |
|  const [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getVscroll](#9e4eb2e6) () const  |
|  [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getHscroll](#0f65bc66) ()  |
|  const [ffw::GuiScrollBar](ffw_GuiScrollBar.html) * | [getHscroll](#9482fb26) () const  |
|  void | [setScrollIncrements](#c988a879) (float _inc_)  |
|  float | [getScrollIncrements](#368ce45e) () const  |


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



### _function_ <a id="6c487500" href="#6c487500">~GuiScrollable</a>

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
inline ffw::Vec2f getScrollValues () const 
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



### _function_ <a id="c988a879" href="#c988a879">setScrollIncrements</a>

```cpp
inline void setScrollIncrements (
    float inc
) 
```



### _function_ <a id="368ce45e" href="#368ce45e">getScrollIncrements</a>

```cpp
inline float getScrollIncrements () const 
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





