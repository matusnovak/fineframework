GLFWRenderWindowArgs
===================================


The documentation for this struct was generated from: `include/ffw/graphics/glfwrenderwindow.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  [ffw::Vec2i](ffw.html#e4e07ebe) | [pos](#f2c4a0f4)<div style="opacity:0.8;">Position of the window, set to [-1, -1] for the OS to decide. </div> |
|  [ffw::Vec2i](ffw.html#e4e07ebe) | [size](#427706b8)<div style="opacity:0.8;">Size of the window. </div> |
|  std::string | [title](#b1b7d616)<div style="opacity:0.8;">UTF-8 encoded title. </div> |
|  const [ImageBuffer](ffw_ImageBuffer.html) * | [icon](#80b1f19d)<div style="opacity:0.8;">Pointer to an icon image buffer. </div> |
|  bool | [resizable](#e7e998cc)<div style="opacity:0.8;">Can the user resize the window? </div> |
|  bool | [border](#57ee20b0)<div style="opacity:0.8;">Does the window have a border? </div> |
|  bool | [maximize](#17286d5d)<div style="opacity:0.8;">Can the user maximize the window? </div> |
|  bool | [floating](#455965fc)<div style="opacity:0.8;">Should the window be always on top? </div> |
|  bool | [focused](#f1d28cf8)<div style="opacity:0.8;">Should the window be automatically focused on creation? </div> |
|  bool | [visible](#7978feef)<div style="opacity:0.8;">Should the window be visible? </div> |
|  int | [samples](#17443f00)<div style="opacity:0.8;">Antialiasing samples, has to be in power of two. </div> |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="f2c4a0f4" href="#f2c4a0f4">pos</a>

```cpp
ffw::Vec2i pos
```

Position of the window, set to [-1, -1] for the OS to decide. 

### <span style="opacity:0.5;">variable</span> <a id="427706b8" href="#427706b8">size</a>

```cpp
ffw::Vec2i size
```

Size of the window. 

### <span style="opacity:0.5;">variable</span> <a id="b1b7d616" href="#b1b7d616">title</a>

```cpp
std::string title
```

UTF-8 encoded title. 

### <span style="opacity:0.5;">variable</span> <a id="80b1f19d" href="#80b1f19d">icon</a>

```cpp
const ImageBuffer * icon
```

Pointer to an icon image buffer. 

### <span style="opacity:0.5;">variable</span> <a id="e7e998cc" href="#e7e998cc">resizable</a>

```cpp
bool resizable
```

Can the user resize the window? 

### <span style="opacity:0.5;">variable</span> <a id="57ee20b0" href="#57ee20b0">border</a>

```cpp
bool border
```

Does the window have a border? 

### <span style="opacity:0.5;">variable</span> <a id="17286d5d" href="#17286d5d">maximize</a>

```cpp
bool maximize
```

Can the user maximize the window? 

### <span style="opacity:0.5;">variable</span> <a id="455965fc" href="#455965fc">floating</a>

```cpp
bool floating
```

Should the window be always on top? 

### <span style="opacity:0.5;">variable</span> <a id="f1d28cf8" href="#f1d28cf8">focused</a>

```cpp
bool focused
```

Should the window be automatically focused on creation? 

### <span style="opacity:0.5;">variable</span> <a id="7978feef" href="#7978feef">visible</a>

```cpp
bool visible
```

Should the window be visible? 

### <span style="opacity:0.5;">variable</span> <a id="17443f00" href="#17443f00">samples</a>

```cpp
int samples
```

Antialiasing samples, has to be in power of two. 



