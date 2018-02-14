GuiProgressBar
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guiprogressbar.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiProgressBar::Style](ffw_GuiProgressBar_Style.html) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [innerStyle](#981bdf6f) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiProgressBar](#18ef4ac5) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|  virtual  | [~GuiProgressBar](#4a8a05f6) ()  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#f7d3b074) ()  |
|  void | [setValue](#530ef1fe) (const float _value_)  |
|  float | [getValue](#94910938) () const  |
|  void | [setInnerStyleGroup](#bcdcd097) (const [GuiWidget::Style](ffw_GuiWidget_Style.html) * _style_)  |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [getInnerStyleGroup](#a94e5f02) () const  |
|  void | [setStyle](#2b98cc61) (const [GuiProgressBar::Style](ffw_GuiProgressBar_Style.html) * _style_, bool _defaults_ = false)  |


## Protected Attributes Documentation

### _variable_ <a id="981bdf6f" href="#981bdf6f">innerStyle</a>

```cpp
const GuiWidget::Style * innerStyle
```





## Public Functions Documentation

### _function_ <a id="18ef4ac5" href="#18ef4ac5">GuiProgressBar</a>

```cpp
 GuiProgressBar (
    GuiWindow * context
) 
```



### _function_ <a id="4a8a05f6" href="#4a8a05f6">~GuiProgressBar</a>

```cpp
virtual  ~GuiProgressBar () 
```



### _function_ <a id="f7d3b074" href="#f7d3b074">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="530ef1fe" href="#530ef1fe">setValue</a>

```cpp
void setValue (
    const float value
) 
```



### _function_ <a id="94910938" href="#94910938">getValue</a>

```cpp
inline float getValue () const 
```



### _function_ <a id="bcdcd097" href="#bcdcd097">setInnerStyleGroup</a>

```cpp
void setInnerStyleGroup (
    const GuiWidget::Style * style
) 
```



### _function_ <a id="a94e5f02" href="#a94e5f02">getInnerStyleGroup</a>

```cpp
inline const GuiWidget::Style * getInnerStyleGroup () const 
```



### _function_ <a id="2b98cc61" href="#2b98cc61">setStyle</a>

```cpp
void setStyle (
    const GuiProgressBar::Style * style,
    bool defaults = false
) 
```





