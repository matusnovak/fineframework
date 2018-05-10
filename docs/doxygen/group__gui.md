---
search: false
---

# group gui

Render engine independent graphic user interface. [More...](#detailed-description)
## Classes

|Type|Name|
|-----|-----|
|class|[**ffw::GuiBackend**](classffw_1_1_gui_backend.md)|
|class|[**ffw::GuiBody**](classffw_1_1_gui_body.md)|
|class|[**ffw::GuiBox**](classffw_1_1_gui_box.md)|
|class|[**ffw::GuiButton**](classffw_1_1_gui_button.md)|
|class|[**ffw::GuiButtonPrimary**](classffw_1_1_gui_button_primary.md)|
|class|[**ffw::GuiButtonToggle**](classffw_1_1_gui_button_toggle.md)|
|class|[**ffw::GuiButtonTogglePrimary**](classffw_1_1_gui_button_toggle_primary.md)|
|class|[**ffw::GuiCheckbox**](classffw_1_1_gui_checkbox.md)|
|class|[**ffw::GuiFont**](classffw_1_1_gui_font.md)|
|class|[**ffw::GuiFontOpenGL**](classffw_1_1_gui_font_open_g_l.md)|
|class|[**ffw::GuiImage**](classffw_1_1_gui_image.md)|
|class|[**ffw::GuiImageOpenGL**](classffw_1_1_gui_image_open_g_l.md)|
|class|[**ffw::GuiImageViewer**](classffw_1_1_gui_image_viewer.md)|
|class|[**ffw::GuiLabel**](classffw_1_1_gui_label.md)|
|class|[**ffw::GuiLayout**](classffw_1_1_gui_layout.md)|
|class|[**ffw::GuiVerticalLayout**](classffw_1_1_gui_vertical_layout.md)|
|class|[**ffw::GuiHorizontalLayout**](classffw_1_1_gui_horizontal_layout.md)|
|class|[**ffw::GuiFixedLayout**](classffw_1_1_gui_fixed_layout.md)|
|class|[**ffw::GuiList**](classffw_1_1_gui_list.md)|
|class|[**ffw::GuiProgressBar**](classffw_1_1_gui_progress_bar.md)|
|class|[**ffw::GuiProgressCircle**](classffw_1_1_gui_progress_circle.md)|
|class|[**ffw::GuiRadio**](classffw_1_1_gui_radio.md)|
|class|[**ffw::GuiScrollable**](classffw_1_1_gui_scrollable.md)|
|class|[**ffw::GuiScrollableLayout**](classffw_1_1_gui_scrollable_layout.md)|
|class|[**ffw::GuiScrollBar**](classffw_1_1_gui_scroll_bar.md)|
|class|[**ffw::GuiSlider**](classffw_1_1_gui_slider.md)|
|class|[**ffw::GuiUnits**](classffw_1_1_gui_units.md)|
|class|[**ffw::GuiUnits2D**](classffw_1_1_gui_units2_d.md)|
|class|[**ffw::GuiStyle**](classffw_1_1_gui_style.md)|
|class|[**ffw::GuiDefaults**](classffw_1_1_gui_defaults.md)|
|class|[**ffw::GuiSwitch**](classffw_1_1_gui_switch.md)|
|class|[**ffw::GuiTabs**](classffw_1_1_gui_tabs.md)|
|class|[**ffw::GuiText**](classffw_1_1_gui_text.md)|
|class|[**ffw::GuiTextInput**](classffw_1_1_gui_text_input.md)|
|class|[**ffw::GuiScrollableTextInput**](classffw_1_1_gui_scrollable_text_input.md)|
|class|[**ffw::GuiTheme**](classffw_1_1_gui_theme.md)|
|class|[**ffw::GuiThemeSimpleLight**](classffw_1_1_gui_theme_simple_light.md)|
|class|[**ffw::GuiThemeSimpleDark**](classffw_1_1_gui_theme_simple_dark.md)|
|class|[**ffw::GuiThemeFlatLight**](classffw_1_1_gui_theme_flat_light.md)|
|class|[**ffw::GuiThemeFlatDark**](classffw_1_1_gui_theme_flat_dark.md)|
|struct|[**ffw::GuiCallback**](structffw_1_1_gui_callback.md)|
|class|[**ffw::GuiUserInput**](classffw_1_1_gui_user_input.md)|
|class|[**ffw::GuiWidget**](classffw_1_1_gui_widget.md)|
|class|[**ffw::GuiWindow**](classffw_1_1_gui_window.md)|
|class|[**ffw::GuiWindowOpenGL**](classffw_1_1_gui_window_open_g_l.md)|
|class|[**ffw::GuiWindowOpenGLFBO**](classffw_1_1_gui_window_open_g_l_f_b_o.md)|


## Enums

|Type|Name|
|-----|-----|
|enum|[**GuiAlign**](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32) { **LEFT** = 0, **CENTER**, **RIGHT**, **TOP\_LEFT**, **TOP\_CENTER**, **TOP\_RIGHT**, **BOTTOM\_LEFT**, **BOTTOM\_CENTER**, **BOTTOM\_RIGHT** } |
|enum|[**GuiEventType**](group__gui_.md#ga1e47d35cdb8925a93ca0dec3f77be4f0) { **ACTION** = 0x1, **SIZE** = 0x10, **INNER** = 0x20, **POSITION** = 0x40, **HOVER** = 0x80, **FOCUS** = 0x100, **STATE** = 0x200, **INPUT** = 0x400, **KEY** = 0x800, **MOUSEBTN** = 0x1000, **ALL** = 0x7FFFFFFF } |


## Functions

|Type|Name|
|-----|-----|
|GuiUnits|[**guiPixels**](group__gui_.md#ga1fd1232e97a1171a626b50316fa79c03) (float pixels) |
|GuiUnits|[**guiPercent**](group__gui_.md#ga156aa094262db4a7900176e3366b714c) (float percent) |
|GuiUnits|[**guiWrap**](group__gui_.md#gae5db716b2fdf7133b3590a09575081ef) () |


## Detailed Description

This module allows creation of user interfaces (GUIs). It takes care of widget layout, automatic spacing when resized, spacing, callbacks, etc. This module provides several widgets (buttons, check boxes, text edits, radios, sliders, etc..) however, has a functionality to add custom widgets as well. All widgets can be arranged in linear layouts, similarly how HTML works, and can be also styled. This GUI is not directly linked to the OpenGL, or any other rendering engine! Instead, it can use any backend with any renderer you wish to use. However, an OpenGL backend is provided by default, if the user wishes to use. The entire module is UTF-8 enabled. 
## Enums Documentation

### enum <a id="ga98e6ace67ac3624f040ae5de12b2ca32" href="#ga98e6ace67ac3624f040ae5de12b2ca32">GuiAlign</a>

```cpp
enum gui::GuiAlign {
    LEFT = 0,
    CENTER,
    RIGHT,
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
};
```



### enum <a id="ga1e47d35cdb8925a93ca0dec3f77be4f0" href="#ga1e47d35cdb8925a93ca0dec3f77be4f0">GuiEventType</a>

```cpp
enum gui::GuiEventType {
    ACTION = 0x1,
    SIZE = 0x10,
    INNER = 0x20,
    POSITION = 0x40,
    HOVER = 0x80,
    FOCUS = 0x100,
    STATE = 0x200,
    INPUT = 0x400,
    KEY = 0x800,
    MOUSEBTN = 0x1000,
    ALL = 0x7FFFFFFF,
};
```



## Functions Documentation

### function <a id="ga1fd1232e97a1171a626b50316fa79c03" href="#ga1fd1232e97a1171a626b50316fa79c03">guiPixels</a>

```cpp
GuiUnits gui::guiPixels (
    float pixels
)
```



### function <a id="ga156aa094262db4a7900176e3366b714c" href="#ga156aa094262db4a7900176e3366b714c">guiPercent</a>

```cpp
GuiUnits gui::guiPercent (
    float percent
)
```



### function <a id="gae5db716b2fdf7133b3590a09575081ef" href="#gae5db716b2fdf7133b3590a09575081ef">guiWrap</a>

```cpp
GuiUnits gui::guiWrap ()
```



