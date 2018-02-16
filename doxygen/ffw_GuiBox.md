GuiBox
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guibox.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiBox::Style](ffw_GuiBox_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiBox](#72438e37) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_, [GuiOrientation](ffw.html#32795b74) _orient_)  |
|  virtual  | [~GuiBox](#48164fb4) ()  |
|  virtual void | [eventRender](#359e8bc4) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _contentoffset_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _contentsize_)  |
|  [GuiLayout](ffw_GuiLayout.html) * | [getInner](#599687fd) ()  |
|  const [GuiLayout](ffw_GuiLayout.html) * | [getInner](#66fde131) () const  |
|  void | [setLabel](#ce715e14) (const std::string & _label_)  |
|  const std::string & | [getLabel](#e030ad33) () const  |
|  [GuiLabel](ffw_GuiLabel.html) * | [getLabelWidget](#3aa5dc69) ()  |
|  const [GuiLabel](ffw_GuiLabel.html) * | [getLabelWidget](#98a785a0) () const  |
|  virtual void | [eventSize](#ca871d44) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_)  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#6e0ebd26) ()  |
|  void | [setStyle](#28fdb6ec) (const [GuiBox::Style](ffw_GuiBox_Style.html) * _style_, bool _defaults_ = false)  |


## Public Functions Documentation

### _function_ <a id="72438e37" href="#72438e37">GuiBox</a>

```cpp
 GuiBox (
    GuiWindow * context,
    const std::string & label,
    GuiOrientation orient
) 
```



### _function_ <a id="48164fb4" href="#48164fb4">~GuiBox</a>

```cpp
virtual  ~GuiBox () 
```



### _function_ <a id="359e8bc4" href="#359e8bc4">eventRender</a>

```cpp
virtual void eventRender (
    const ffw::Vec2f & contentoffset,
    const ffw::Vec2f & contentsize
) 
```



**Overrides:** [eventRender](/doxygen/ffw_GuiWidget.md#3b53d9f9) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="599687fd" href="#599687fd">getInner</a>

```cpp
inline GuiLayout * getInner () 
```



### _function_ <a id="66fde131" href="#66fde131">getInner</a>

```cpp
inline const GuiLayout * getInner () const 
```



### _function_ <a id="ce715e14" href="#ce715e14">setLabel</a>

```cpp
inline void setLabel (
    const std::string & label
) 
```



### _function_ <a id="e030ad33" href="#e030ad33">getLabel</a>

```cpp
inline const std::string & getLabel () const 
```



### _function_ <a id="3aa5dc69" href="#3aa5dc69">getLabelWidget</a>

```cpp
inline GuiLabel * getLabelWidget () 
```



### _function_ <a id="98a785a0" href="#98a785a0">getLabelWidget</a>

```cpp
inline const GuiLabel * getLabelWidget () const 
```



### _function_ <a id="ca871d44" href="#ca871d44">eventSize</a>

```cpp
virtual void eventSize (
    const ffw::Vec2f & size
) 
```



**Overrides:** [eventSize](/doxygen/ffw_GuiWidget.md#1fa5fcdc) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="6e0ebd26" href="#6e0ebd26">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```



**Overrides:** [getMinimumWrapSize](/doxygen/ffw_GuiWidget.md#c12efa3f) from class [GuiWidget](/doxygen/ffw_GuiWidget.md)

### _function_ <a id="28fdb6ec" href="#28fdb6ec">setStyle</a>

```cpp
void setStyle (
    const GuiBox::Style * style,
    bool defaults = false
) 
```





