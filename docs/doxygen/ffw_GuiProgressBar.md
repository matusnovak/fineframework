GuiProgressBar
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiprogressbar.h`



## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [innerStyle](#2088ea0c) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiProgressBar](#18ef4ac5) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiProgressBar](#1cab6210) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#f7d3b074) ()  |
|  void | [setValue](#c0ac5c32) (float _value_)  |
|  float | [getValue](#94910938) () const  |
|  void | [setInnerStyleGroup](#e9d69b0b) (const [GuiStyleGroup](ffw_GuiStyleGroup.html) * _style_)  |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) * | [getInnerStyleGroup](#54530f35) () const  |


## Protected Attributes Documentation

### _variable_ <a id="2088ea0c" href="#2088ea0c">innerStyle</a>

```cpp
const GuiStyleGroup * innerStyle
```





## Public Functions Documentation

### _function_ <a id="18ef4ac5" href="#18ef4ac5">GuiProgressBar</a>

```cpp
 GuiProgressBar (
    GuiWindow * context
) 
```



### _function_ <a id="1cab6210" href="#1cab6210">~GuiProgressBar</a>

```cpp
virtual  ~GuiProgressBar () 
```



### _function_ <a id="f7d3b074" href="#f7d3b074">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="c0ac5c32" href="#c0ac5c32">setValue</a>

```cpp
inline void setValue (
    float value
) 
```



### _function_ <a id="94910938" href="#94910938">getValue</a>

```cpp
inline float getValue () const 
```



### _function_ <a id="e9d69b0b" href="#e9d69b0b">setInnerStyleGroup</a>

```cpp
inline void setInnerStyleGroup (
    const GuiStyleGroup * style
) 
```



### _function_ <a id="54530f35" href="#54530f35">getInnerStyleGroup</a>

```cpp
inline const GuiStyleGroup * getInnerStyleGroup () const 
```





