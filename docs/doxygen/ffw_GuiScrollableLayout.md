GuiScrollableLayout
===================================


**Inherits from:** [ffw::GuiScrollable](ffw_GuiScrollable.html)

**Implemented by:** [ffw::GuiList](ffw_GuiList.html)

The documentation for this class was generated from: `include/ffw/gui/guiscrollable.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiScrollableLayout](#d926488f) ([GuiWindow](ffw_GuiWindow.html) * _context_, [GuiLayout::Orientation](ffw_GuiWidget.html#47f53876) _orientation_, bool _hori_, bool _vert_)  |
|  virtual  | [~GuiScrollableLayout](#16a1b83e) ()  |
|  [GuiLayout](ffw_GuiLayout.html) * | [getInner](#79b46f8e) ()  |
|  const [GuiLayout](ffw_GuiLayout.html) * | [getInner](#b0f84706) () const  |


## Public Functions Documentation

### _function_ <a id="d926488f" href="#d926488f">GuiScrollableLayout</a>

```cpp
 GuiScrollableLayout (
    GuiWindow * context,
    GuiLayout::Orientation orientation,
    bool hori,
    bool vert
) 
```



### _function_ <a id="16a1b83e" href="#16a1b83e">~GuiScrollableLayout</a>

```cpp
virtual  ~GuiScrollableLayout () 
```



### _function_ <a id="79b46f8e" href="#79b46f8e">getInner</a>

```cpp
inline GuiLayout * getInner () 
```



### _function_ <a id="b0f84706" href="#b0f84706">getInner</a>

```cpp
inline const GuiLayout * getInner () const 
```





