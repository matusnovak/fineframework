---
search:
    keywords: ['ffw::GuiEvent', 'Data', 'widget', 'type', 'data', 'GuiEvent']
---

# class ffw::GuiEvent

## Classes

|Type|Name|
|-----|-----|
|class|[**Data**](unionffw_1_1_gui_event_1_1_data.md)|


## Public Attributes

|Type|Name|
|-----|-----|
|**[GuiWidget](classffw_1_1_gui_widget.md)** \*|[**widget**](classffw_1_1_gui_event.md#1a3b573df8ec40924305851e6550345697)|
|**[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)**|[**type**](classffw_1_1_gui_event.md#1afdeaf199372ed6043a7b4b85b10aa642)|
|**[Data](.md#unionffw_1_1_gui_event_1_1_data)**|[**data**](classffw_1_1_gui_event.md#1ad278e0e82315b1b87ff31f2457eec7b0)|


## Public Functions

|Type|Name|
|-----|-----|
||[**GuiEvent**](classffw_1_1_gui_event.md#1a96c6ed771f9530402f8993615ee06f9e) (**[GuiWidget](classffw_1_1_gui_widget.md)** \* widget, **[GuiEventType](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0)** type, **[Data](.md#unionffw_1_1_gui_event_1_1_data)** data) |


## Public Attributes Documentation

### variable <a id="1a3b573df8ec40924305851e6550345697" href="#1a3b573df8ec40924305851e6550345697">widget</a>

```cpp
GuiWidget* ffw::GuiEvent::widget;
```



### variable <a id="1afdeaf199372ed6043a7b4b85b10aa642" href="#1afdeaf199372ed6043a7b4b85b10aa642">type</a>

```cpp
GuiEventType ffw::GuiEvent::type;
```



### variable <a id="1ad278e0e82315b1b87ff31f2457eec7b0" href="#1ad278e0e82315b1b87ff31f2457eec7b0">data</a>

```cpp
Data ffw::GuiEvent::data;
```



## Public Functions Documentation

### function <a id="1a96c6ed771f9530402f8993615ee06f9e" href="#1a96c6ed771f9530402f8993615ee06f9e">GuiEvent</a>

```cpp
ffw::GuiEvent::GuiEvent (
    GuiWidget * widget
    GuiEventType type
    Data data
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guiwidget.h`
