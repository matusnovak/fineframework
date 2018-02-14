GuiCallback
===================================


The documentation for this struct was generated from: `include/ffw/gui/guiwidget.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::function< void([GuiEvent](ffw_GuiEvent.html))> | [func](#b4a8c322) |
|  bool | [now](#78dee68b) |
|  [GuiEventType](ffw.html#8b540a94) | [type](#feec5dcf) |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  [GuiCallback](ffw_GuiCallback.html) | [make](#570410f4) (void(T::*)([GuiEvent](ffw_GuiEvent.html)) _memfuncptr_, T * _instance_, [GuiEventType](ffw.html#8b540a94) _type_ = [GuiEventType::ALL](ffw_GuiEventType.html#1644ef86), bool _instant_ = false)  |
|  [GuiCallback](ffw_GuiCallback.html) | [make](#42378cf2) (const std::function< void([GuiEvent](ffw_GuiEvent.html))> & _function_, [GuiEventType](ffw.html#8b540a94) _type_ = [GuiEventType::ALL](ffw_GuiEventType.html#1644ef86), bool _instant_ = false)  |
|  [GuiCallback](ffw_GuiCallback.html) | [make](#743f75b0) (const F & _lambda_, [GuiEventType](ffw.html#8b540a94) _type_ = [GuiEventType::ALL](ffw_GuiEventType.html#1644ef86), bool _instant_ = false)  |


## Public Attributes Documentation

### _variable_ <a id="b4a8c322" href="#b4a8c322">func</a>

```cpp
std::function< void(GuiEvent)> func
```



### _variable_ <a id="78dee68b" href="#78dee68b">now</a>

```cpp
bool now
```



### _variable_ <a id="feec5dcf" href="#feec5dcf">type</a>

```cpp
GuiEventType type
```





## Public Static Functions Documentation

### _function_ <a id="570410f4" href="#570410f4">make</a>

```cpp
static inline GuiCallback make (
    void(T::*)(GuiEvent) memfuncptr,
    T * instance,
    GuiEventType type = GuiEventType::ALL,
    bool instant = false
) 
```



### _function_ <a id="42378cf2" href="#42378cf2">make</a>

```cpp
static inline GuiCallback make (
    const std::function< void(GuiEvent)> & function,
    GuiEventType type = GuiEventType::ALL,
    bool instant = false
) 
```



### _function_ <a id="743f75b0" href="#743f75b0">make</a>

```cpp
static inline GuiCallback make (
    const F & lambda,
    GuiEventType type = GuiEventType::ALL,
    bool instant = false
) 
```





