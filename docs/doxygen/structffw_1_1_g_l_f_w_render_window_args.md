---
search: false
---

# struct ffw::GLFWRenderWindowArgs

## Public Attributes

|Type|Name|
|-----|-----|
|**[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**pos**](structffw_1_1_g_l_f_w_render_window_args.md#1acad25219d1d1f980766b8c2a1092670c)<br>Position of the window, set to [-1, -1] for the OS to decide. |
|**[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**size**](structffw_1_1_g_l_f_w_render_window_args.md#1a0d149e540bd88d8e1ae8fe0a0ecb2d22)<br>Size of the window. |
|std::string|[**title**](structffw_1_1_g_l_f_w_render_window_args.md#1aa0fa8d1411dbf4f2857007e279738236)<br>UTF-8 encoded title. |
|const **[ImageBuffer](classffw_1_1_image_buffer.md)** \*|[**icon**](structffw_1_1_g_l_f_w_render_window_args.md#1a17e8e3939897bffb6f43936921cec7e3)<br>Pointer to an icon image buffer. |
|bool|[**resizable**](structffw_1_1_g_l_f_w_render_window_args.md#1a4a5164795268f43956664282d052896a)<br>Can the user resize the window? |
|bool|[**border**](structffw_1_1_g_l_f_w_render_window_args.md#1a80ee2aa17bdee47bec40edb5c13a2b08)<br>Does the window have a border? |
|bool|[**maximize**](structffw_1_1_g_l_f_w_render_window_args.md#1a550651a3f34ea5539ad8c9cf30467829)<br>Can the user maximize the window? |
|bool|[**floating**](structffw_1_1_g_l_f_w_render_window_args.md#1a4454b2c5b25bb3a2b38f3fdc6e87b63c)<br>Should the window be always on top? |
|bool|[**focused**](structffw_1_1_g_l_f_w_render_window_args.md#1a6823297fc6a1e37d66834e0c62511a2c)<br>Should the window be automatically focused on creation? |
|bool|[**visible**](structffw_1_1_g_l_f_w_render_window_args.md#1ab36a3ad2d1f0ebf6f7f989a2663432be)<br>Should the window be visible? |
|int|[**samples**](structffw_1_1_g_l_f_w_render_window_args.md#1a0a590ebba21f105c1a17012e92e37095)<br>Antialiasing samples, has to be in power of two. |
|bool|[**initDrawing**](structffw_1_1_g_l_f_w_render_window_args.md#1aeb218f9d45c1b5966a9f1f2f61e18bcf)<br>Should the window initialize drawing API? |


## Public Attributes Documentation

### variable <a id="1acad25219d1d1f980766b8c2a1092670c" href="#1acad25219d1d1f980766b8c2a1092670c">pos</a>

```cpp
ffw::Vec2i ffw::GLFWRenderWindowArgs::pos;
```

Position of the window, set to [-1, -1] for the OS to decide. 


### variable <a id="1a0d149e540bd88d8e1ae8fe0a0ecb2d22" href="#1a0d149e540bd88d8e1ae8fe0a0ecb2d22">size</a>

```cpp
ffw::Vec2i ffw::GLFWRenderWindowArgs::size;
```

Size of the window. 


### variable <a id="1aa0fa8d1411dbf4f2857007e279738236" href="#1aa0fa8d1411dbf4f2857007e279738236">title</a>

```cpp
std::string ffw::GLFWRenderWindowArgs::title;
```

UTF-8 encoded title. 


### variable <a id="1a17e8e3939897bffb6f43936921cec7e3" href="#1a17e8e3939897bffb6f43936921cec7e3">icon</a>

```cpp
const ImageBuffer* ffw::GLFWRenderWindowArgs::icon;
```

Pointer to an icon image buffer. 


### variable <a id="1a4a5164795268f43956664282d052896a" href="#1a4a5164795268f43956664282d052896a">resizable</a>

```cpp
bool ffw::GLFWRenderWindowArgs::resizable;
```

Can the user resize the window? 


### variable <a id="1a80ee2aa17bdee47bec40edb5c13a2b08" href="#1a80ee2aa17bdee47bec40edb5c13a2b08">border</a>

```cpp
bool ffw::GLFWRenderWindowArgs::border;
```

Does the window have a border? 


### variable <a id="1a550651a3f34ea5539ad8c9cf30467829" href="#1a550651a3f34ea5539ad8c9cf30467829">maximize</a>

```cpp
bool ffw::GLFWRenderWindowArgs::maximize;
```

Can the user maximize the window? 


### variable <a id="1a4454b2c5b25bb3a2b38f3fdc6e87b63c" href="#1a4454b2c5b25bb3a2b38f3fdc6e87b63c">floating</a>

```cpp
bool ffw::GLFWRenderWindowArgs::floating;
```

Should the window be always on top? 


### variable <a id="1a6823297fc6a1e37d66834e0c62511a2c" href="#1a6823297fc6a1e37d66834e0c62511a2c">focused</a>

```cpp
bool ffw::GLFWRenderWindowArgs::focused;
```

Should the window be automatically focused on creation? 


### variable <a id="1ab36a3ad2d1f0ebf6f7f989a2663432be" href="#1ab36a3ad2d1f0ebf6f7f989a2663432be">visible</a>

```cpp
bool ffw::GLFWRenderWindowArgs::visible;
```

Should the window be visible? 


### variable <a id="1a0a590ebba21f105c1a17012e92e37095" href="#1a0a590ebba21f105c1a17012e92e37095">samples</a>

```cpp
int ffw::GLFWRenderWindowArgs::samples;
```

Antialiasing samples, has to be in power of two. 


### variable <a id="1aeb218f9d45c1b5966a9f1f2f61e18bcf" href="#1aeb218f9d45c1b5966a9f1f2f61e18bcf">initDrawing</a>

```cpp
bool ffw::GLFWRenderWindowArgs::initDrawing;
```

Should the window initialize drawing API? 




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/glfwrenderwindow.h`
