GuiEvent
===================================


The documentation for this class was generated from: `include/ffw/gui/guiwidget.h`



## Classes

| Name |
|:-----|
| union [ffw::GuiEvent::Data](ffw_GuiEvent_Data.html) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  [GuiWidget](ffw_GuiWidget.html) * | [widget](#85c7e3ea) |
|  [GuiEventType](ffw.html#8b540a94) | [type](#fe01b4da) |
|  [Data](ffw_GuiEvent_Data.html) | [data](#66edf752) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiEvent](#1d824147) ([GuiWidget](ffw_GuiWidget.html) * _widget_, [GuiEventType](ffw.html#8b540a94) _type_, [Data](ffw_GuiEvent_Data.html) _data_)  |


## Public Attributes Documentation

### _variable_ <a id="85c7e3ea" href="#85c7e3ea">widget</a>

```cpp
GuiWidget * widget
```



### _variable_ <a id="fe01b4da" href="#fe01b4da">type</a>

```cpp
GuiEventType type
```



### _variable_ <a id="66edf752" href="#66edf752">data</a>

```cpp
Data data
```





## Public Functions Documentation

### _function_ <a id="1d824147" href="#1d824147">GuiEvent</a>

```cpp
inline  GuiEvent (
    GuiWidget * widget,
    GuiEventType type,
    Data data
) 
```





