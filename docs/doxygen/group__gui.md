gui - Graphical User Interface
===================================

Render engine independent graphic user interface. 

## Detailed description

This module allows creation of user interfaces (GUIs). It takes care of widget layout, automatic spacing when resized, spacing, callbacks, etc. This module provides several widgets (buttons, check boxes, text edits, radios, sliders, etc..) however, has a functionality to add custom widgets as well. All widgets can be arranged in linear layouts, similarly how HTML works and can be also styled. This GUI is not directly linked to OpenGL or any other rendering engine! Instead, it can use any backend with any renderer you wish to use. However, an OpenGL backend is provided by default, if the user wishes to use. 


## Classes

| Name |
|:-----|
| class [ffw::GuiBackend](ffw_GuiBackend.html) |
| class [ffw::GuiBody](ffw_GuiBody.html) |
| class [ffw::GuiBox](ffw_GuiBox.html) |
| class [ffw::GuiButton](ffw_GuiButton.html) |
| class [ffw::GuiButtonPrimary](ffw_GuiButtonPrimary.html) |
| class [ffw::GuiButtonToggle](ffw_GuiButtonToggle.html) |
| class [ffw::GuiButtonTogglePrimary](ffw_GuiButtonTogglePrimary.html) |
| class [ffw::GuiCheckbox](ffw_GuiCheckbox.html) |
| class [ffw::GuiFont](ffw_GuiFont.html) |
| class [ffw::GuiFontOpenGL](ffw_GuiFontOpenGL.html) |
| class [ffw::GuiImage](ffw_GuiImage.html) |
| class [ffw::GuiImageOpenGL](ffw_GuiImageOpenGL.html) |
| class [ffw::GuiImageViewer](ffw_GuiImageViewer.html) |
| class [ffw::GuiLabel](ffw_GuiLabel.html) |
| class [ffw::GuiLayout](ffw_GuiLayout.html) |
| class [ffw::GuiVerticalLayout](ffw_GuiVerticalLayout.html) |
| class [ffw::GuiHorizontalLayout](ffw_GuiHorizontalLayout.html) |
| class [ffw::GuiFixedLayout](ffw_GuiFixedLayout.html) |
| class [ffw::GuiList](ffw_GuiList.html) |
| class [ffw::GuiProgressBar](ffw_GuiProgressBar.html) |
| class [ffw::GuiProgressCircle](ffw_GuiProgressCircle.html) |
| class [ffw::GuiRadio](ffw_GuiRadio.html) |
| class [ffw::GuiScrollable](ffw_GuiScrollable.html) |
| class [ffw::GuiScrollableLayout](ffw_GuiScrollableLayout.html) |
| class [ffw::GuiScrollBar](ffw_GuiScrollBar.html) |
| class [ffw::GuiSlider](ffw_GuiSlider.html) |
| class [ffw::GuiUnits](ffw_GuiUnits.html) |
| class [ffw::GuiUnits2D](ffw_GuiUnits2D.html) |
| class [ffw::GuiStyle](ffw_GuiStyle.html) |
| class [ffw::GuiDefaults](ffw_GuiDefaults.html) |
| class [ffw::GuiSwitch](ffw_GuiSwitch.html) |
| class [ffw::GuiTabs](ffw_GuiTabs.html) |
| class [ffw::GuiText](ffw_GuiText.html) |
| class [ffw::GuiTextInput](ffw_GuiTextInput.html) |
| class [ffw::GuiScrollableTextInput](ffw_GuiScrollableTextInput.html) |
| class [ffw::GuiTheme](ffw_GuiTheme.html) |
| class [ffw::GuiThemeSimpleLight](ffw_GuiThemeSimpleLight.html) |
| class [ffw::GuiThemeSimpleDark](ffw_GuiThemeSimpleDark.html) |
| class [ffw::GuiThemeFlatLight](ffw_GuiThemeFlatLight.html) |
| class [ffw::GuiThemeFlatDark](ffw_GuiThemeFlatDark.html) |
| struct [ffw::GuiCallback](ffw_GuiCallback.html) |
| class [ffw::GuiUserInput](ffw_GuiUserInput.html) |
| class [ffw::GuiWidget](ffw_GuiWidget.html) |
| class [ffw::GuiWindow](ffw_GuiWindow.html) |
| class [ffw::GuiWindowOpenGL](ffw_GuiWindowOpenGL.html) |
| class [ffw::GuiWindowOpenGLFBO](ffw_GuiWindowOpenGLFBO.html) |


## Enums

| Type | Name |
| -------: | :------- |
| enum | [GuiAlign](#38e5cadb) |
| enum | [GuiEventType](#8b540a94) |


## Functions

| Type | Name |
| -------: | :------- |
|  GuiUnits | [guiPixels](#66baed55) (float _pixels_)  |
|  GuiUnits | [guiPercent](#3107a022) (float _percent_)  |
|  GuiUnits | [guiWrap](#9eb691c9) ()  |


## Enums Documentation

### _enum_ <a id="38e5cadb" href="#38e5cadb">GuiAlign</a>

```cpp
enum GuiAlign {
    LEFT,
    CENTER,
    RIGHT,
    TOP_LEFT,
    TOP_CENTER,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_CENTER,
    BOTTOM_RIGHT,
}
```



### _enum_ <a id="8b540a94" href="#8b540a94">GuiEventType</a>

```cpp
enum GuiEventType {
    ACTION,
    SIZE,
    INNER,
    POSITION,
    HOVER,
    FOCUS,
    STATE,
    INPUT,
    KEY,
    MOUSEBTN,
    ALL,
}
```





## Functions Documentation

### _function_ <a id="66baed55" href="#66baed55">guiPixels</a>

```cpp
inline GuiUnits guiPixels (
    float pixels
) 
```



### _function_ <a id="3107a022" href="#3107a022">guiPercent</a>

```cpp
inline GuiUnits guiPercent (
    float percent
) 
```



### _function_ <a id="9eb691c9" href="#9eb691c9">guiWrap</a>

```cpp
inline GuiUnits guiWrap () 
```





