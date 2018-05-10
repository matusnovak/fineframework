---
search: false
---

# class ffw::GuiDefaults

## Public Attributes

|Type|Name|
|-----|-----|
|**[GuiStyle::Margin](classffw_1_1_gui_style.md#1ae98f782a8de9d8eb37fc727ba8110ba1)**|[**margin**](classffw_1_1_gui_defaults.md#1aca078b07987e273872a173ad0fbf448c)|
|**[GuiStyle::Padding](classffw_1_1_gui_style.md#1a5f3ab2ae1509566f6558defc0ba1be6f)**|[**padding**](classffw_1_1_gui_defaults.md#1a8cfb2342ed7604da7ad2c3c93b2dfa43)|
|**[GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)**|[**align**](classffw_1_1_gui_defaults.md#1a5f5e9362544ee604727916d2caf98358)|
|**[GuiUnits2D](classffw_1_1_gui_units2_d.md)**|[**size**](classffw_1_1_gui_defaults.md#1aba00481843e8f3473810348ac038616e)|


## Public Functions

|Type|Name|
|-----|-----|
||[**GuiDefaults**](classffw_1_1_gui_defaults.md#1ada508ba6b38e32f4aa1fa1c22fe9abf4) () |
||[**GuiDefaults**](classffw_1_1_gui_defaults.md#1a304a7b93632487d79fdd450dc77d10e0) (const **[GuiStyle::Margin](classffw_1_1_gui_style.md#1ae98f782a8de9d8eb37fc727ba8110ba1)** & m, const **[GuiStyle::Padding](classffw_1_1_gui_style.md#1a5f3ab2ae1509566f6558defc0ba1be6f)** & p, **[GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** a, const **[GuiUnits2D](classffw_1_1_gui_units2_d.md)** & s) |
||[**GuiDefaults**](classffw_1_1_gui_defaults.md#1acf90878c58e9eadadf5e598be11403f9) (float m, float p, **[GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** a, const **[GuiUnits2D](classffw_1_1_gui_units2_d.md)** & s) |


## Public Attributes Documentation

### variable <a id="1aca078b07987e273872a173ad0fbf448c" href="#1aca078b07987e273872a173ad0fbf448c">margin</a>

```cpp
GuiStyle::Margin ffw::GuiDefaults::margin;
```



### variable <a id="1a8cfb2342ed7604da7ad2c3c93b2dfa43" href="#1a8cfb2342ed7604da7ad2c3c93b2dfa43">padding</a>

```cpp
GuiStyle::Padding ffw::GuiDefaults::padding;
```



### variable <a id="1a5f5e9362544ee604727916d2caf98358" href="#1a5f5e9362544ee604727916d2caf98358">align</a>

```cpp
GuiAlign ffw::GuiDefaults::align;
```



### variable <a id="1aba00481843e8f3473810348ac038616e" href="#1aba00481843e8f3473810348ac038616e">size</a>

```cpp
GuiUnits2D ffw::GuiDefaults::size;
```



## Public Functions Documentation

### function <a id="1ada508ba6b38e32f4aa1fa1c22fe9abf4" href="#1ada508ba6b38e32f4aa1fa1c22fe9abf4">GuiDefaults</a>

```cpp
ffw::GuiDefaults::GuiDefaults ()
```



### function <a id="1a304a7b93632487d79fdd450dc77d10e0" href="#1a304a7b93632487d79fdd450dc77d10e0">GuiDefaults</a>

```cpp
ffw::GuiDefaults::GuiDefaults (
    const GuiStyle::Margin & m
    const GuiStyle::Padding & p
    GuiAlign a
    const GuiUnits2D & s
)
```



### function <a id="1acf90878c58e9eadadf5e598be11403f9" href="#1acf90878c58e9eadadf5e598be11403f9">GuiDefaults</a>

```cpp
ffw::GuiDefaults::GuiDefaults (
    float m
    float p
    GuiAlign a
    const GuiUnits2D & s
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guistyle.h`
