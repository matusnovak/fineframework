Button
===================================


**Inherits from:** [ffw::GuiButtonToggle](ffw_GuiButtonToggle.html)

The documentation for this class was generated from: `include/ffw/gui/guitab.h`



## Classes

| Name |
|:-----|
| struct [ffw::GuiTabs::Button::Style](ffw_GuiTabs_Button_Style.html) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Button](#016139ad) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_, [GuiWidget](ffw_GuiWidget.html) * _targetWidget_)  |
|  virtual  | [~Button](#49660edc) ()  |
|  void | [setStyle](#ae8a55f2) (const [Button::Style](ffw_GuiTabs_Button_Style.html) * _style_, bool _defaults_ = false)  |
|  [GuiWidget](ffw_GuiWidget.html) * | [getTargetWidget](#9f3ac083) () const  |


## Public Functions Documentation

### _function_ <a id="016139ad" href="#016139ad">Button</a>

```cpp
 Button (
    GuiWindow * context,
    const std::string & label,
    GuiWidget * targetWidget
) 
```



### _function_ <a id="49660edc" href="#49660edc">~Button</a>

```cpp
virtual  ~Button () 
```



### _function_ <a id="ae8a55f2" href="#ae8a55f2">setStyle</a>

```cpp
void setStyle (
    const Button::Style * style,
    bool defaults = false
) 
```



### _function_ <a id="9f3ac083" href="#9f3ac083">getTargetWidget</a>

```cpp
inline GuiWidget * getTargetWidget () const 
```





