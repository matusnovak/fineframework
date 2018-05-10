---
search: false
---

# class ffw::GuiStyle

## Classes

|Type|Name|
|-----|-----|
|class|[**Attribute**](classffw_1_1_gui_style_1_1_attribute.md)|
|class|[**Background**](classffw_1_1_gui_style_1_1_background.md)|
|class|[**Border**](classffw_1_1_gui_style_1_1_border.md)|
|class|[**Function**](classffw_1_1_gui_style_1_1_function.md)|
|class|[**Text**](classffw_1_1_gui_style_1_1_text.md)|


## Public Types

|Type|Name|
|-----|-----|
|typedef **[Border](classffw_1_1_gui_style_1_1_border.md)**|[**Outline**](classffw_1_1_gui_style.md#1ad4ae59a5a7942fbe9e963e05104dc194)|
|typedef **[GuiStyle::Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< **[GuiUnits](classffw_1_1_gui_units.md)** >|[**Padding**](classffw_1_1_gui_style.md#1a5f3ab2ae1509566f6558defc0ba1be6f)|
|typedef **[GuiStyle::Attribute](classffw_1_1_gui_style_1_1_attribute.md)**< **[GuiUnits](classffw_1_1_gui_units.md)** >|[**Margin**](classffw_1_1_gui_style.md#1ae98f782a8de9d8eb37fc727ba8110ba1)|


## Public Attributes

|Type|Name|
|-----|-----|
|**[Background](classffw_1_1_gui_style_1_1_background.md)**|[**background**](classffw_1_1_gui_style.md#1a0856c2848a26acbf2246ce4569624f82)|
|**[Border](classffw_1_1_gui_style_1_1_border.md)**|[**border**](classffw_1_1_gui_style.md#1a599408f7b604cf161c96616b7adb0525)|
|**[Outline](classffw_1_1_gui_style.md#1ad4ae59a5a7942fbe9e963e05104dc194)**|[**outline**](classffw_1_1_gui_style.md#1a909b1fa63f729c6dab2c82638b1651f4)|
|**[Text](classffw_1_1_gui_style_1_1_text.md)**|[**text**](classffw_1_1_gui_style.md#1a92d7e637e725613ed25b804bec6b1001)|
|**[Function](classffw_1_1_gui_style_1_1_function.md)**|[**function**](classffw_1_1_gui_style.md#1a6ebad086e25d098ecca826436e2f10fc)|


## Public Functions

|Type|Name|
|-----|-----|
||[**GuiStyle**](classffw_1_1_gui_style.md#1a331bed75c64f851540c5bf0c5c1efabc) () |
||[**GuiStyle**](classffw_1_1_gui_style.md#1acd7f88d2f20333bfefda9296d883a7db) (const **[Background](classffw_1_1_gui_style_1_1_background.md)** & b, const **[Border](classffw_1_1_gui_style_1_1_border.md)** & br, const **[Outline](classffw_1_1_gui_style.md#1ad4ae59a5a7942fbe9e963e05104dc194)** & ou, const **[Text](classffw_1_1_gui_style_1_1_text.md)** & t, const **[Function](classffw_1_1_gui_style_1_1_function.md)** & f) |


## Public Types Documentation

### typedef <a id="1ad4ae59a5a7942fbe9e963e05104dc194" href="#1ad4ae59a5a7942fbe9e963e05104dc194">Outline</a>

```cpp
typedef Border ffw::GuiStyle::Outline;
```



### typedef <a id="1a5f3ab2ae1509566f6558defc0ba1be6f" href="#1a5f3ab2ae1509566f6558defc0ba1be6f">Padding</a>

```cpp
typedef GuiStyle::Attribute<GuiUnits> ffw::GuiStyle::Padding;
```



### typedef <a id="1ae98f782a8de9d8eb37fc727ba8110ba1" href="#1ae98f782a8de9d8eb37fc727ba8110ba1">Margin</a>

```cpp
typedef GuiStyle::Attribute<GuiUnits> ffw::GuiStyle::Margin;
```



## Public Attributes Documentation

### variable <a id="1a0856c2848a26acbf2246ce4569624f82" href="#1a0856c2848a26acbf2246ce4569624f82">background</a>

```cpp
Background ffw::GuiStyle::background;
```



### variable <a id="1a599408f7b604cf161c96616b7adb0525" href="#1a599408f7b604cf161c96616b7adb0525">border</a>

```cpp
Border ffw::GuiStyle::border;
```



### variable <a id="1a909b1fa63f729c6dab2c82638b1651f4" href="#1a909b1fa63f729c6dab2c82638b1651f4">outline</a>

```cpp
Outline ffw::GuiStyle::outline;
```



### variable <a id="1a92d7e637e725613ed25b804bec6b1001" href="#1a92d7e637e725613ed25b804bec6b1001">text</a>

```cpp
Text ffw::GuiStyle::text;
```



### variable <a id="1a6ebad086e25d098ecca826436e2f10fc" href="#1a6ebad086e25d098ecca826436e2f10fc">function</a>

```cpp
Function ffw::GuiStyle::function;
```



## Public Functions Documentation

### function <a id="1a331bed75c64f851540c5bf0c5c1efabc" href="#1a331bed75c64f851540c5bf0c5c1efabc">GuiStyle</a>

```cpp
ffw::GuiStyle::GuiStyle ()
```



### function <a id="1acd7f88d2f20333bfefda9296d883a7db" href="#1acd7f88d2f20333bfefda9296d883a7db">GuiStyle</a>

```cpp
ffw::GuiStyle::GuiStyle (
    const Background & b
    const Border & br
    const Outline & ou
    const Text & t
    const Function & f
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guistyle.h`
