GuiLabel
===================================


**Inherits from:** [ffw::GuiWidget](ffw_GuiWidget.html)

The documentation for this class was generated from: `include/ffw/gui/guilabel.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiLabel](#7818ed71) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::string & _label_)  |
|   | [GuiLabel](#00e9d4c8) ([GuiWindow](ffw_GuiWindow.html) * _context_, const std::wstring & _label_)  |
|  virtual  | [~GuiLabel](#c1358785) ()  |
|  void | [setLabel](#c081da82) (const std::wstring & _label_)  |
|  const std::wstring & | [getLabel](#261dddb0) () const  |
|  virtual [ffw::Vec2f](ffw.html#fcfaa6c5) | [getMinimumWrapSize](#84fc7ddb) ()  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="7818ed71" href="#7818ed71">GuiLabel</a>

```cpp
 GuiLabel (
    GuiWindow * context,
    const std::string & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="00e9d4c8" href="#00e9d4c8">GuiLabel</a>

```cpp
 GuiLabel (
    GuiWindow * context,
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="c1358785" href="#c1358785">~GuiLabel</a>

```cpp
virtual  ~GuiLabel () 
```



### <span style="opacity:0.5;">function</span> <a id="c081da82" href="#c081da82">setLabel</a>

```cpp
void setLabel (
    const std::wstring & label
) 
```



### <span style="opacity:0.5;">function</span> <a id="261dddb0" href="#261dddb0">getLabel</a>

```cpp
const std::wstring & getLabel () const 
```



### <span style="opacity:0.5;">function</span> <a id="84fc7ddb" href="#84fc7ddb">getMinimumWrapSize</a>

```cpp
virtual ffw::Vec2f getMinimumWrapSize () 
```





