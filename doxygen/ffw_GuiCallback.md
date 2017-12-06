GuiCallback
===================================


The documentation for this class was generated from: `include/ffw/gui/guiwidget.h`



## Classes

| Name |
|:-----|
| class [ffw::GuiCallback::Data](ffw_GuiCallback_Data.html) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::vector< [Data](ffw_GuiCallback_Data.html) > | [callbacks](#5beb0dd2) |


## Public Functions

| Type | Name |
| -------: | :------- |
|  void | [add](#e2d18be8) (void(T::*)([GuiEvent](ffw_GuiEvent.html)) _memfuncptr_, T * _instance_, bool _instant_)  |
|  void | [add](#9dc24048) (const std::function< void([GuiEvent](ffw_GuiEvent.html))> & _function_, bool _instant_)  |


## Public Attributes Documentation

### _variable_ <a id="5beb0dd2" href="#5beb0dd2">callbacks</a>

```cpp
std::vector< Data > callbacks
```





## Public Functions Documentation

### _function_ <a id="e2d18be8" href="#e2d18be8">add</a>

```cpp
inline void add (
    void(T::*)(GuiEvent) memfuncptr,
    T * instance,
    bool instant
) 
```



### _function_ <a id="9dc24048" href="#9dc24048">add</a>

```cpp
inline void add (
    const std::function< void(GuiEvent)> & function,
    bool instant
) 
```





