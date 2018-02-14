GuiWidget
===================================


**Implemented by:** [ffw::GuiBox](ffw_GuiBox.html), [ffw::GuiButton](ffw_GuiButton.html), [ffw::GuiCheckbox](ffw_GuiCheckbox.html), [ffw::GuiCheckbox::Button](ffw_GuiCheckbox_Button.html), [ffw::GuiImageViewer](ffw_GuiImageViewer.html), [ffw::GuiLabel](ffw_GuiLabel.html), [ffw::GuiLayout](ffw_GuiLayout.html), [ffw::GuiList::Item](ffw_GuiList_Item.html), [ffw::GuiProgressBar](ffw_GuiProgressBar.html), [ffw::GuiProgressCircle](ffw_GuiProgressCircle.html), [ffw::GuiRadio](ffw_GuiRadio.html), [ffw::GuiRadio::Button](ffw_GuiRadio_Button.html), [ffw::GuiScrollable](ffw_GuiScrollable.html), [ffw::GuiScrollBar](ffw_GuiScrollBar.html), [ffw::GuiSlider](ffw_GuiSlider.html), [ffw::GuiSwitch](ffw_GuiSwitch.html), [ffw::GuiTabs](ffw_GuiTabs.html), [ffw::GuiText](ffw_GuiText.html), [ffw::GuiTextInput](ffw_GuiTextInput.html), 

The documentation for this class was generated from: `include/ffw/gui/guiwidget.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiWidget::Flags](ffw_GuiWidget_Flags.html) |
| struct [ffw::GuiWidget::Style](ffw_GuiWidget_Style.html) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  [GuiWindow](ffw_GuiWindow.html) * | [context](#a4fd6a8b) |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [widgetStyle](#adbf017e) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiWidget](#effff205) ([GuiWindow](ffw_GuiWindow.html) * _context_)  |
|   | [GuiWidget](#84f2e0c8) (const [GuiWidget](ffw_GuiWidget.html) & _other_) = delete  |
|   | [GuiWidget](#a717ecce) ([GuiWidget](ffw_GuiWidget.html) && _other_)  |
|  void | [swap](#0863f905) ([GuiWidget](ffw_GuiWidget.html) & _other_)  |
|  virtual  | [~GuiWidget](#9b4afe51) ()  |
|  void | [setSize](#2f88ed2c) ([GuiUnits](ffw_GuiUnits.html) _width_, [GuiUnits](ffw_GuiUnits.html) _height_)  |
|  void | [setSize](#e6a2e8d3) (const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & _s_)  |
|  void | [setPos](#73cab019) ([GuiUnits](ffw_GuiUnits.html) _posx_, [GuiUnits](ffw_GuiUnits.html) _posy_)  |
|  const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & | [getPos](#472a3695) () const  |
|  const [ffw::Vec2](ffw_Vec2.html)< [GuiUnits](ffw_GuiUnits.html) > & | [getSize](#7806b9eb) () const  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getVisibleContentSize](#e56fd225) () const  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getVisibleContentPos](#c91ad3e7) () const  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getInnerContentSize](#62ca3682) () const  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getInnerContentPos](#7e841405) () const  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getAbsolutePos](#3cb9fee9) () const  |
|  void | [setOffset](#bc101f1f) (const [ffw::Vec2f](ffw.html#fcfaa6c5) _off_)  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getOffset](#ff20ff5a) () const  |
|  void | [setPadding](#13ce72b1) ([GuiUnits](ffw_GuiUnits.html) _top_, [GuiUnits](ffw_GuiUnits.html) _right_, [GuiUnits](ffw_GuiUnits.html) _bottom_, [GuiUnits](ffw_GuiUnits.html) _left_)  |
|  void | [setPadding](#f112d22b) ([GuiUnits](ffw_GuiUnits.html) _all_)  |
|  void | [setPadding](#db0e4126) (const [GuiStyle::Padding](ffw_GuiStyle.html#82b7d280) & _pad_)  |
|  void | [setMargin](#1f3a476d) ([GuiUnits](ffw_GuiUnits.html) _top_, [GuiUnits](ffw_GuiUnits.html) _right_, [GuiUnits](ffw_GuiUnits.html) _bottom_, [GuiUnits](ffw_GuiUnits.html) _left_)  |
|  void | [setMargin](#724880b1) ([GuiUnits](ffw_GuiUnits.html) _all_)  |
|  void | [setMargin](#06da917d) (const [GuiStyle::Margin](ffw_GuiStyle.html#77df323f) & _mar_)  |
|  const [GuiStyle::Padding](ffw_GuiStyle.html#82b7d280) & | [getPadding](#a56204bc) () const  |
|  const [GuiStyle::Margin](ffw_GuiStyle.html#77df323f) & | [getMargin](#7060f34d) () const  |
|  [GuiUnits](ffw_GuiUnits.html) | [getPadding](#ba0319d8) (int _side_) const  |
|  [GuiUnits](ffw_GuiUnits.html) | [getMargin](#2361d746) (int _side_) const  |
|  void | [setMarginTop](#5e9de0ba) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setMarginRight](#c355b0a1) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setMarginBottom](#6a6c9965) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setMarginLeft](#1ab76ffe) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setPaddingTop](#74b1c375) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setPaddingRight](#a70b5a3d) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setPaddingBottom](#2254e26e) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  void | [setPaddingLeft](#f4b9befe) ([GuiUnits](ffw_GuiUnits.html) _val_)  |
|  float | [getPaddingInPixels](#11adb516) (int _side_) const  |
|  float | [getMarginInPixels](#edb20435) (int _side_) const  |
|  void | [setAlign](#ebc65e50) ([GuiAlign](ffw.html#38e5cadb) _align_)  |
|  [GuiAlign](ffw.html#38e5cadb) | [getAlign](#15a1c07a) () const  |
|  void | [setWrap](#bace6600) (bool _wrap_)  |
|  bool | [getWrap](#d9effebd) () const  |
|  void | [setID](#c8d9ab43) (unsigned long _id_)  |
|  unsigned long | [getID](#a074ad79) () const  |
|  void | [update](#ace13146) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _parentpos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _parentsize_, const [GuiUserInput](ffw_GuiUserInput.html) & _input_, [ffw::Vec2f](ffw.html#fcfaa6c5) _mousepos_, bool _mouseout_)  |
|  void | [render](#6ca314de) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _clippos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _clipsize_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _off_, bool _clear_)  |
|  bool | [shouldRedraw](#077c72ca) () const  |
|  void | [redraw](#b5a27de2) ()  |
|  void | [invalidate](#15d551cb) ()  |
|  void | [setParent](#ebe0662a) ([GuiWidget](ffw_GuiWidget.html) * _parent_)  |
|  const [GuiWidget](ffw_GuiWidget.html) * | [getParent](#fffe352d) () const  |
|  bool | [hasHover](#e6b9f459) () const  |
|  bool | [hasFocus](#cd2a2032) () const  |
|  void | [setFocus](#07e1703c) (bool _f_)  |
|  void | [setHover](#894527ec) (bool _h_)  |
|  void | [setDisabled](#34acd985) (bool _d_)  |
|  void | [setHidden](#9d9b97c0) (bool _h_)  |
|  void | [setIgnoreUserInput](#c63468c9) (bool _d_)  |
|  void | [hide](#98ed3d7f) ()  |
|  void | [show](#72adbc6e) ()  |
|  bool | [isHidden](#163d8039) () const  |
|  bool | [isDisabled](#76b4f3dd) () const  |
|  void | [setFont](#8a441607) (const [GuiFont](ffw_GuiFont.html) * _font_)  |
|  const [GuiFont](ffw_GuiFont.html) * | [getFont](#2d8e5f24) () const  |
|  const [GuiFont](ffw_GuiFont.html) * | [getCurrentFont](#688c5dc2) () const  |
|  const [ffw::Vec2i](ffw.html#e4e07ebe) | [getMousePos](#2fac9a68) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#c12efa3f) () = 0  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getOuterWrapSize](#784acd2e) ()  |
|  T * | [findByID](#2a8bac7d) (unsigned long _id__)  |
|  void | [addEventCallback](#394796b8) (void(T::*)([GuiEvent](ffw_GuiEvent.html)) _memfuncptr_, T * _instance_, [GuiEventType](ffw.html#8b540a94) _type_ = [GuiEventType::ALL](ffw_GuiEventType.html#1644ef86), bool _now_ = false)  |
|  void | [addEventCallback](#9cc87462) (const std::function< void([GuiEvent](ffw_GuiEvent.html))> & _function_, [GuiEventType](ffw.html#8b540a94) _type_ = [GuiEventType::ALL](ffw_GuiEventType.html#1644ef86), bool _now_ = false)  |
|  void | [addEventCallback](#7f26a334) (const F & _lambda_, [GuiEventType](ffw.html#8b540a94) _type_ = [GuiEventType::ALL](ffw_GuiEventType.html#1644ef86), bool _now_ = false)  |
|  void | [setTheme](#c54fe35f) (const [GuiTheme](ffw_GuiTheme.html) * _theme_, bool _defaults_ = false)  |
|  void | [setStyleGroup](#e0d35216) (const [GuiWidget::Style](ffw_GuiWidget_Style.html) * _style_)  |
|  const [GuiWidget::Style](ffw_GuiWidget_Style.html) * | [getStyleGroup](#a9564c9a) ()  |
|  const [ffw::GuiStyle](ffw_GuiStyle.html) * | [getCurrentStyle](#29480ee7) () const  |
|  const [ffw::GuiStyle](ffw_GuiStyle.html) * | [getCurrentStyle](#bab37307) (const [GuiWidget::Style](ffw_GuiWidget_Style.html) * _group_) const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getRealSize](#4f2b8235) () const  |
|  [ffw::Vec2f](ffw.html#fcfaa6c5) | [getRealSizeWithMargin](#9490320b) () const  |
|  const [ffw::Vec2f](ffw.html#fcfaa6c5) & | [getRealPos](#c7936745) () const  |
|  void | [setLineHeight](#7fd26b07) (float _height_)  |
|  float | [getLineHeight](#81f6f9eb) () const  |
|  void | [setDefaults](#f66f774f) (const [ffw::GuiDefaults](ffw_GuiDefaults.html) * _def_)  |
|  [GuiWindow](ffw_GuiWindow.html) * | [getWindow](#4b15b476) ()  |
|  const [GuiWindow](ffw_GuiWindow.html) * | [getWindow](#d0bc83be) () const  |
|  void | [setToggleFocus](#8ee39d66) ()  |
|  void | [setStickyFocus](#14899218) ()  |
|  void | [setDropFocus](#15d13c40) ()  |
|  void | [setDefaultFocus](#7bebdfe7) ()  |
|  [GuiFocusType](ffw.html#ccd58d43) | [getFocusType](#01de8da0) () const  |
|  const std::vector< [GuiWidget](ffw_GuiWidget.html) * > & | [getAllWidgets](#6aac45b2) () const  |
|  void | [pushEvent](#f264c51e) ([GuiEventType](ffw.html#8b540a94) _type_, [GuiEvent::Data](ffw_GuiEvent_Data.html) _data_)  |
|  [GuiWidget](ffw_GuiWidget.html) & | [operator=](#65a717ad) (const [GuiWidget](ffw_GuiWidget.html) & _other_) = delete  |
|  [GuiWidget](ffw_GuiWidget.html) & | [operator=](#36d95005) ([GuiWidget](ffw_GuiWidget.html) && _other_)  |


## Protected Functions

| Type | Name |
| -------: | :------- |
|  void | [traverseBackground](#f7412e3e) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetInternal](#9f307c00) ([GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetAfterInternal](#f6b84d3a) (const [GuiWidget](ffw_GuiWidget.html) * _previous_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [addWidgetBeforeInternal](#e4c841b7) (const [GuiWidget](ffw_GuiWidget.html) * _next_, [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [deleteWidgetsInternal](#e9681a70) ()  |
|  bool | [deleteSingleWidgetInternal](#a0480cd5) (const [GuiWidget](ffw_GuiWidget.html) * _widget_)  |
|  void | [setOrientationInternal](#0f06ebee) ([GuiOrientation](ffw.html#32795b74) _orientation_)  |
|  void | [recalculatePos](#86cd28ab) ()  |
|  void | [recalculateSize](#ff0d162b) ([GuiWidget](ffw_GuiWidget.html) * _ptr_ = NULL)  |
|  void | [renderComponent](#725ccfce) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_, const [ffw::GuiStyle](ffw_GuiStyle.html) * _group_)  |
|  virtual void | [eventRender](#3b53d9f9) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _contentoffset_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _contentsize_) = 0  |
|  virtual void | [eventPos](#24c7f1da) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _pos_)  |
|  virtual void | [eventSize](#1fa5fcdc) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _size_)  |
|  virtual void | [eventHover](#79239e64) (bool _gained_)  |
|  virtual void | [eventFocus](#810fea1a) (bool _gained_)  |
|  virtual void | [eventMouse](#c5e3f7fc) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _mousePos_)  |
|  virtual bool | [eventScroll](#a35f7a9a) (const [ffw::Vec2f](ffw.html#fcfaa6c5) & _scroll_)  |
|  virtual void | [eventMouseButton](#b83a5017) ([ffw::MouseButton](ffw.html#f80e46cc) _button_, [ffw::Mode](ffw.html#e03b52d5) _mode_)  |
|  virtual void | [eventText](#7441865b) (uint32_t _chr_)  |
|  virtual void | [eventKey](#4cbf1170) ([ffw::Key](ffw.html#23661d50) _key_, [ffw::Mode](ffw.html#e03b52d5) _mode_)  |
|  virtual void | [eventDisabled](#87c70e45) (bool _disabled_)  |
|  virtual void | [eventThemeChanged](#b47461e7) (const [GuiTheme](ffw_GuiTheme.html) * _theme_, bool _defaults_ = false) = 0  |
|  const [Flags](ffw_GuiWidget_Flags.html) & | [getFlags](#a3e68c52) () const  |


## Protected Attributes Documentation

### _variable_ <a id="a4fd6a8b" href="#a4fd6a8b">context</a>

```cpp
GuiWindow * context
```



### _variable_ <a id="adbf017e" href="#adbf017e">widgetStyle</a>

```cpp
const GuiWidget::Style * widgetStyle
```





## Public Functions Documentation

### _function_ <a id="effff205" href="#effff205">GuiWidget</a>

```cpp
 GuiWidget (
    GuiWindow * context
) 
```



### _function_ <a id="84f2e0c8" href="#84f2e0c8">GuiWidget</a>

```cpp
 GuiWidget (
    const GuiWidget & other
) = delete 
```



### _function_ <a id="a717ecce" href="#a717ecce">GuiWidget</a>

```cpp
 GuiWidget (
    GuiWidget && other
) 
```



### _function_ <a id="0863f905" href="#0863f905">swap</a>

```cpp
void swap (
    GuiWidget & other
) 
```



### _function_ <a id="9b4afe51" href="#9b4afe51">~GuiWidget</a>

```cpp
virtual  ~GuiWidget () 
```



### _function_ <a id="2f88ed2c" href="#2f88ed2c">setSize</a>

```cpp
inline void setSize (
    GuiUnits width,
    GuiUnits height
) 
```



### _function_ <a id="e6a2e8d3" href="#e6a2e8d3">setSize</a>

```cpp
void setSize (
    const ffw::Vec2< GuiUnits > & s
) 
```



### _function_ <a id="73cab019" href="#73cab019">setPos</a>

```cpp
void setPos (
    GuiUnits posx,
    GuiUnits posy
) 
```



### _function_ <a id="472a3695" href="#472a3695">getPos</a>

```cpp
const ffw::Vec2< GuiUnits > & getPos () const 
```



### _function_ <a id="7806b9eb" href="#7806b9eb">getSize</a>

```cpp
const ffw::Vec2< GuiUnits > & getSize () const 
```



### _function_ <a id="e56fd225" href="#e56fd225">getVisibleContentSize</a>

```cpp
ffw::Vec2f getVisibleContentSize () const 
```



### _function_ <a id="c91ad3e7" href="#c91ad3e7">getVisibleContentPos</a>

```cpp
ffw::Vec2f getVisibleContentPos () const 
```



### _function_ <a id="62ca3682" href="#62ca3682">getInnerContentSize</a>

```cpp
inline ffw::Vec2f getInnerContentSize () const 
```



### _function_ <a id="7e841405" href="#7e841405">getInnerContentPos</a>

```cpp
inline ffw::Vec2f getInnerContentPos () const 
```



### _function_ <a id="3cb9fee9" href="#3cb9fee9">getAbsolutePos</a>

```cpp
ffw::Vec2f getAbsolutePos () const 
```



### _function_ <a id="bc101f1f" href="#bc101f1f">setOffset</a>

```cpp
void setOffset (
    const ffw::Vec2f off
) 
```



### _function_ <a id="ff20ff5a" href="#ff20ff5a">getOffset</a>

```cpp
const ffw::Vec2f & getOffset () const 
```



### _function_ <a id="13ce72b1" href="#13ce72b1">setPadding</a>

```cpp
void setPadding (
    GuiUnits top,
    GuiUnits right,
    GuiUnits bottom,
    GuiUnits left
) 
```



### _function_ <a id="f112d22b" href="#f112d22b">setPadding</a>

```cpp
inline void setPadding (
    GuiUnits all
) 
```



### _function_ <a id="db0e4126" href="#db0e4126">setPadding</a>

```cpp
inline void setPadding (
    const GuiStyle::Padding & pad
) 
```



### _function_ <a id="1f3a476d" href="#1f3a476d">setMargin</a>

```cpp
void setMargin (
    GuiUnits top,
    GuiUnits right,
    GuiUnits bottom,
    GuiUnits left
) 
```



### _function_ <a id="724880b1" href="#724880b1">setMargin</a>

```cpp
inline void setMargin (
    GuiUnits all
) 
```



### _function_ <a id="06da917d" href="#06da917d">setMargin</a>

```cpp
inline void setMargin (
    const GuiStyle::Margin & mar
) 
```



### _function_ <a id="a56204bc" href="#a56204bc">getPadding</a>

```cpp
inline const GuiStyle::Padding & getPadding () const 
```



### _function_ <a id="7060f34d" href="#7060f34d">getMargin</a>

```cpp
inline const GuiStyle::Margin & getMargin () const 
```



### _function_ <a id="ba0319d8" href="#ba0319d8">getPadding</a>

```cpp
inline GuiUnits getPadding (
    int side
) const 
```



### _function_ <a id="2361d746" href="#2361d746">getMargin</a>

```cpp
inline GuiUnits getMargin (
    int side
) const 
```



### _function_ <a id="5e9de0ba" href="#5e9de0ba">setMarginTop</a>

```cpp
inline void setMarginTop (
    GuiUnits val
) 
```



### _function_ <a id="c355b0a1" href="#c355b0a1">setMarginRight</a>

```cpp
inline void setMarginRight (
    GuiUnits val
) 
```



### _function_ <a id="6a6c9965" href="#6a6c9965">setMarginBottom</a>

```cpp
inline void setMarginBottom (
    GuiUnits val
) 
```



### _function_ <a id="1ab76ffe" href="#1ab76ffe">setMarginLeft</a>

```cpp
inline void setMarginLeft (
    GuiUnits val
) 
```



### _function_ <a id="74b1c375" href="#74b1c375">setPaddingTop</a>

```cpp
inline void setPaddingTop (
    GuiUnits val
) 
```



### _function_ <a id="a70b5a3d" href="#a70b5a3d">setPaddingRight</a>

```cpp
inline void setPaddingRight (
    GuiUnits val
) 
```



### _function_ <a id="2254e26e" href="#2254e26e">setPaddingBottom</a>

```cpp
inline void setPaddingBottom (
    GuiUnits val
) 
```



### _function_ <a id="f4b9befe" href="#f4b9befe">setPaddingLeft</a>

```cpp
inline void setPaddingLeft (
    GuiUnits val
) 
```



### _function_ <a id="11adb516" href="#11adb516">getPaddingInPixels</a>

```cpp
float getPaddingInPixels (
    int side
) const 
```



### _function_ <a id="edb20435" href="#edb20435">getMarginInPixels</a>

```cpp
float getMarginInPixels (
    int side
) const 
```



### _function_ <a id="ebc65e50" href="#ebc65e50">setAlign</a>

```cpp
void setAlign (
    GuiAlign align
) 
```



### _function_ <a id="15a1c07a" href="#15a1c07a">getAlign</a>

```cpp
GuiAlign getAlign () const 
```



### _function_ <a id="bace6600" href="#bace6600">setWrap</a>

```cpp
void setWrap (
    bool wrap
) 
```



### _function_ <a id="d9effebd" href="#d9effebd">getWrap</a>

```cpp
inline bool getWrap () const 
```



### _function_ <a id="c8d9ab43" href="#c8d9ab43">setID</a>

```cpp
void setID (
    unsigned long id
) 
```



### _function_ <a id="a074ad79" href="#a074ad79">getID</a>

```cpp
unsigned long getID () const 
```



### _function_ <a id="ace13146" href="#ace13146">update</a>

```cpp
void update (
    const ffw::Vec2f & parentpos,
    const ffw::Vec2f & parentsize,
    const GuiUserInput & input,
    ffw::Vec2f mousepos,
    bool mouseout
) 
```



### _function_ <a id="6ca314de" href="#6ca314de">render</a>

```cpp
void render (
    const ffw::Vec2f & clippos,
    const ffw::Vec2f & clipsize,
    const ffw::Vec2f & off,
    bool clear
) 
```



### _function_ <a id="077c72ca" href="#077c72ca">shouldRedraw</a>

```cpp
bool shouldRedraw () const 
```



### _function_ <a id="b5a27de2" href="#b5a27de2">redraw</a>

```cpp
void redraw () 
```



### _function_ <a id="15d551cb" href="#15d551cb">invalidate</a>

```cpp
void invalidate () 
```



### _function_ <a id="ebe0662a" href="#ebe0662a">setParent</a>

```cpp
void setParent (
    GuiWidget * parent
) 
```



### _function_ <a id="fffe352d" href="#fffe352d">getParent</a>

```cpp
const GuiWidget * getParent () const 
```



### _function_ <a id="e6b9f459" href="#e6b9f459">hasHover</a>

```cpp
inline bool hasHover () const 
```



### _function_ <a id="cd2a2032" href="#cd2a2032">hasFocus</a>

```cpp
inline bool hasFocus () const 
```



### _function_ <a id="07e1703c" href="#07e1703c">setFocus</a>

```cpp
void setFocus (
    bool f
) 
```



### _function_ <a id="894527ec" href="#894527ec">setHover</a>

```cpp
void setHover (
    bool h
) 
```



### _function_ <a id="34acd985" href="#34acd985">setDisabled</a>

```cpp
void setDisabled (
    bool d
) 
```



### _function_ <a id="9d9b97c0" href="#9d9b97c0">setHidden</a>

```cpp
void setHidden (
    bool h
) 
```



### _function_ <a id="c63468c9" href="#c63468c9">setIgnoreUserInput</a>

```cpp
void setIgnoreUserInput (
    bool d
) 
```



### _function_ <a id="98ed3d7f" href="#98ed3d7f">hide</a>

```cpp
inline void hide () 
```



### _function_ <a id="72adbc6e" href="#72adbc6e">show</a>

```cpp
inline void show () 
```



### _function_ <a id="163d8039" href="#163d8039">isHidden</a>

```cpp
inline bool isHidden () const 
```



### _function_ <a id="76b4f3dd" href="#76b4f3dd">isDisabled</a>

```cpp
inline bool isDisabled () const 
```



### _function_ <a id="8a441607" href="#8a441607">setFont</a>

```cpp
void setFont (
    const GuiFont * font
) 
```



### _function_ <a id="2d8e5f24" href="#2d8e5f24">getFont</a>

```cpp
const GuiFont * getFont () const 
```



### _function_ <a id="688c5dc2" href="#688c5dc2">getCurrentFont</a>

```cpp
const GuiFont * getCurrentFont () const 
```



### _function_ <a id="2fac9a68" href="#2fac9a68">getMousePos</a>

```cpp
inline const ffw::Vec2i getMousePos () const 
```



### _function_ <a id="c12efa3f" href="#c12efa3f">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () = 0 
```



### _function_ <a id="784acd2e" href="#784acd2e">getOuterWrapSize</a>

```cpp
inline ffw::Vec2f getOuterWrapSize () 
```



### _function_ <a id="2a8bac7d" href="#2a8bac7d">findByID</a>

```cpp
inline T * findByID (
    unsigned long id_
) 
```



### _function_ <a id="394796b8" href="#394796b8">addEventCallback</a>

```cpp
inline void addEventCallback (
    void(T::*)(GuiEvent) memfuncptr,
    T * instance,
    GuiEventType type = GuiEventType::ALL,
    bool now = false
) 
```



### _function_ <a id="9cc87462" href="#9cc87462">addEventCallback</a>

```cpp
inline void addEventCallback (
    const std::function< void(GuiEvent)> & function,
    GuiEventType type = GuiEventType::ALL,
    bool now = false
) 
```



### _function_ <a id="7f26a334" href="#7f26a334">addEventCallback</a>

```cpp
inline void addEventCallback (
    const F & lambda,
    GuiEventType type = GuiEventType::ALL,
    bool now = false
) 
```



### _function_ <a id="c54fe35f" href="#c54fe35f">setTheme</a>

```cpp
void setTheme (
    const GuiTheme * theme,
    bool defaults = false
) 
```



### _function_ <a id="e0d35216" href="#e0d35216">setStyleGroup</a>

```cpp
void setStyleGroup (
    const GuiWidget::Style * style
) 
```



### _function_ <a id="a9564c9a" href="#a9564c9a">getStyleGroup</a>

```cpp
inline const GuiWidget::Style * getStyleGroup () 
```



### _function_ <a id="29480ee7" href="#29480ee7">getCurrentStyle</a>

```cpp
inline const ffw::GuiStyle * getCurrentStyle () const 
```



### _function_ <a id="bab37307" href="#bab37307">getCurrentStyle</a>

```cpp
const ffw::GuiStyle * getCurrentStyle (
    const GuiWidget::Style * group
) const 
```



### _function_ <a id="4f2b8235" href="#4f2b8235">getRealSize</a>

```cpp
inline const ffw::Vec2f & getRealSize () const 
```



### _function_ <a id="9490320b" href="#9490320b">getRealSizeWithMargin</a>

```cpp
inline ffw::Vec2f getRealSizeWithMargin () const 
```



### _function_ <a id="c7936745" href="#c7936745">getRealPos</a>

```cpp
inline const ffw::Vec2f & getRealPos () const 
```



### _function_ <a id="7fd26b07" href="#7fd26b07">setLineHeight</a>

```cpp
inline void setLineHeight (
    float height
) 
```



### _function_ <a id="81f6f9eb" href="#81f6f9eb">getLineHeight</a>

```cpp
inline float getLineHeight () const 
```



### _function_ <a id="f66f774f" href="#f66f774f">setDefaults</a>

```cpp
inline void setDefaults (
    const ffw::GuiDefaults * def
) 
```



### _function_ <a id="4b15b476" href="#4b15b476">getWindow</a>

```cpp
inline GuiWindow * getWindow () 
```



### _function_ <a id="d0bc83be" href="#d0bc83be">getWindow</a>

```cpp
inline const GuiWindow * getWindow () const 
```



### _function_ <a id="8ee39d66" href="#8ee39d66">setToggleFocus</a>

```cpp
inline void setToggleFocus () 
```



### _function_ <a id="14899218" href="#14899218">setStickyFocus</a>

```cpp
inline void setStickyFocus () 
```



### _function_ <a id="15d13c40" href="#15d13c40">setDropFocus</a>

```cpp
inline void setDropFocus () 
```



### _function_ <a id="7bebdfe7" href="#7bebdfe7">setDefaultFocus</a>

```cpp
inline void setDefaultFocus () 
```



### _function_ <a id="01de8da0" href="#01de8da0">getFocusType</a>

```cpp
inline GuiFocusType getFocusType () const 
```



### _function_ <a id="6aac45b2" href="#6aac45b2">getAllWidgets</a>

```cpp
inline const std::vector< GuiWidget * > & getAllWidgets () const 
```



### _function_ <a id="f264c51e" href="#f264c51e">pushEvent</a>

```cpp
void pushEvent (
    GuiEventType type,
    GuiEvent::Data data
) 
```



### _function_ <a id="65a717ad" href="#65a717ad">operator=</a>

```cpp
GuiWidget & operator= (
    const GuiWidget & other
) = delete 
```



### _function_ <a id="36d95005" href="#36d95005">operator=</a>

```cpp
GuiWidget & operator= (
    GuiWidget && other
) 
```





## Protected Functions Documentation

### _function_ <a id="f7412e3e" href="#f7412e3e">traverseBackground</a>

```cpp
void traverseBackground (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size
) 
```



### _function_ <a id="9f307c00" href="#9f307c00">addWidgetInternal</a>

```cpp
GuiWidget * addWidgetInternal (
    GuiWidget * widget
) 
```



### _function_ <a id="f6b84d3a" href="#f6b84d3a">addWidgetAfterInternal</a>

```cpp
GuiWidget * addWidgetAfterInternal (
    const GuiWidget * previous,
    GuiWidget * widget
) 
```



### _function_ <a id="e4c841b7" href="#e4c841b7">addWidgetBeforeInternal</a>

```cpp
GuiWidget * addWidgetBeforeInternal (
    const GuiWidget * next,
    GuiWidget * widget
) 
```



### _function_ <a id="e9681a70" href="#e9681a70">deleteWidgetsInternal</a>

```cpp
void deleteWidgetsInternal () 
```



### _function_ <a id="a0480cd5" href="#a0480cd5">deleteSingleWidgetInternal</a>

```cpp
bool deleteSingleWidgetInternal (
    const GuiWidget * widget
) 
```



### _function_ <a id="0f06ebee" href="#0f06ebee">setOrientationInternal</a>

```cpp
void setOrientationInternal (
    GuiOrientation orientation
) 
```



### _function_ <a id="86cd28ab" href="#86cd28ab">recalculatePos</a>

```cpp
void recalculatePos () 
```



### _function_ <a id="ff0d162b" href="#ff0d162b">recalculateSize</a>

```cpp
void recalculateSize (
    GuiWidget * ptr = NULL
) 
```



### _function_ <a id="725ccfce" href="#725ccfce">renderComponent</a>

```cpp
void renderComponent (
    const ffw::Vec2f & pos,
    const ffw::Vec2f & size,
    const ffw::GuiStyle * group
) 
```



### _function_ <a id="3b53d9f9" href="#3b53d9f9">eventRender</a>

```cpp
virtual void eventRender (
    const ffw::Vec2f & contentoffset,
    const ffw::Vec2f & contentsize
) = 0 
```



### _function_ <a id="24c7f1da" href="#24c7f1da">eventPos</a>

```cpp
virtual void eventPos (
    const ffw::Vec2f & pos
) 
```



### _function_ <a id="1fa5fcdc" href="#1fa5fcdc">eventSize</a>

```cpp
virtual void eventSize (
    const ffw::Vec2f & size
) 
```



### _function_ <a id="79239e64" href="#79239e64">eventHover</a>

```cpp
virtual void eventHover (
    bool gained
) 
```



### _function_ <a id="810fea1a" href="#810fea1a">eventFocus</a>

```cpp
virtual void eventFocus (
    bool gained
) 
```



### _function_ <a id="c5e3f7fc" href="#c5e3f7fc">eventMouse</a>

```cpp
virtual void eventMouse (
    const ffw::Vec2f & mousePos
) 
```



### _function_ <a id="a35f7a9a" href="#a35f7a9a">eventScroll</a>

```cpp
virtual bool eventScroll (
    const ffw::Vec2f & scroll
) 
```



### _function_ <a id="b83a5017" href="#b83a5017">eventMouseButton</a>

```cpp
virtual void eventMouseButton (
    ffw::MouseButton button,
    ffw::Mode mode
) 
```



### _function_ <a id="7441865b" href="#7441865b">eventText</a>

```cpp
virtual void eventText (
    uint32_t chr
) 
```



### _function_ <a id="4cbf1170" href="#4cbf1170">eventKey</a>

```cpp
virtual void eventKey (
    ffw::Key key,
    ffw::Mode mode
) 
```



### _function_ <a id="87c70e45" href="#87c70e45">eventDisabled</a>

```cpp
virtual void eventDisabled (
    bool disabled
) 
```



### _function_ <a id="b47461e7" href="#b47461e7">eventThemeChanged</a>

```cpp
virtual void eventThemeChanged (
    const GuiTheme * theme,
    bool defaults = false
) = 0 
```



### _function_ <a id="a3e68c52" href="#a3e68c52">getFlags</a>

```cpp
inline const Flags & getFlags () const 
```





