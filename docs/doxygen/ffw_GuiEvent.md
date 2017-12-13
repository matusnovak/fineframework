GuiEvent
===================================


The documentation for this class was generated from: `include/ffw/gui/guiwidget.h`



## Classes

| Name |
|:-----|
| union [ffw::GuiEvent::Data](ffw_GuiEvent_Data.html) |


## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Type](#d7001c09) |


## Public Attributes

| Type | Name |
| -------: | :------- |
|  [GuiWidget](ffw_GuiWidget.html) * | [widget](#85c7e3ea) |
|  [Type](ffw_GuiEvent.html#d7001c09) | [type](#2209b284) |
|  [Data](ffw_GuiEvent_Data.html) | [data](#66edf752) |


## Public Types Documentation

### _enum_ <a id="d7001c09" href="#d7001c09">Type</a>

```cpp
enum Type {
    CLICKED,
    SELECTED,
    CHANGED,
    SLIDED,
    SIZE,
    INNER,
    POSITION,
    HOVER,
    FOCUS,
    STATE,
    INPUT,
    KEY,
    MOUSEBTN,
}
```





## Public Attributes Documentation

### _variable_ <a id="85c7e3ea" href="#85c7e3ea">widget</a>

```cpp
GuiWidget * widget
```



### _variable_ <a id="2209b284" href="#2209b284">type</a>

```cpp
Type type
```



### _variable_ <a id="66edf752" href="#66edf752">data</a>

```cpp
Data data
```





