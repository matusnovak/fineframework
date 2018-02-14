GLFWRenderWindowArgs
===================================


The documentation for this struct was generated from: `include/ffw/graphics/glfwrenderwindow.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  [ffw::Vec2i](ffw.html#e4e07ebe) | [pos](#f2c4a0f4) _Position of the window, set to [-1, -1] for the OS to decide._ |
|  [ffw::Vec2i](ffw.html#e4e07ebe) | [size](#427706b8) _Size of the window._ |
|  std::string | [title](#b1b7d616) _UTF-8 encoded title._ |
|  const [ImageBuffer](ffw_ImageBuffer.html) * | [icon](#80b1f19d) _Pointer to an icon image buffer._ |
|  bool | [resizable](#e7e998cc) _Can the user resize the window?_ |
|  bool | [border](#57ee20b0) _Does the window have a border?_ |
|  bool | [maximize](#17286d5d) _Can the user maximize the window?_ |
|  bool | [floating](#455965fc) _Should the window be always on top?_ |
|  bool | [focused](#f1d28cf8) _Should the window be automatically focused on creation?_ |
|  bool | [visible](#7978feef) _Should the window be visible?_ |
|  int | [samples](#17443f00) _Antialiasing samples, has to be in power of two._ |
|  bool | [initDrawing](#73c075e9) _Should the window initialize drawing API?_ |


## Public Attributes Documentation

### _variable_ <a id="f2c4a0f4" href="#f2c4a0f4">pos</a>

```cpp
ffw::Vec2i pos
```

Position of the window, set to [-1, -1] for the OS to decide. 

### _variable_ <a id="427706b8" href="#427706b8">size</a>

```cpp
ffw::Vec2i size
```

Size of the window. 

### _variable_ <a id="b1b7d616" href="#b1b7d616">title</a>

```cpp
std::string title
```

UTF-8 encoded title. 

### _variable_ <a id="80b1f19d" href="#80b1f19d">icon</a>

```cpp
const ImageBuffer * icon
```

Pointer to an icon image buffer. 

### _variable_ <a id="e7e998cc" href="#e7e998cc">resizable</a>

```cpp
bool resizable
```

Can the user resize the window? 

### _variable_ <a id="57ee20b0" href="#57ee20b0">border</a>

```cpp
bool border
```

Does the window have a border? 

### _variable_ <a id="17286d5d" href="#17286d5d">maximize</a>

```cpp
bool maximize
```

Can the user maximize the window? 

### _variable_ <a id="455965fc" href="#455965fc">floating</a>

```cpp
bool floating
```

Should the window be always on top? 

### _variable_ <a id="f1d28cf8" href="#f1d28cf8">focused</a>

```cpp
bool focused
```

Should the window be automatically focused on creation? 

### _variable_ <a id="7978feef" href="#7978feef">visible</a>

```cpp
bool visible
```

Should the window be visible? 

### _variable_ <a id="17443f00" href="#17443f00">samples</a>

```cpp
int samples
```

Antialiasing samples, has to be in power of two. 

### _variable_ <a id="73c075e9" href="#73c075e9">initDrawing</a>

```cpp
bool initDrawing
```

Should the window initialize drawing API? 



