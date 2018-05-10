---
search: false
---

# class ffw::RenderWindow



Inherited by the following classes: **[ffw::GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)**

## Public Functions

|Type|Name|
|-----|-----|
|virtual |[**~RenderWindow**](classffw_1_1_render_window.md#1a0c1ec1126da519d82a2281cbf9c8736a) () = default |
|virtual void|[**setPos**](classffw_1_1_render_window.md#1a555c078b31cabb0093fe2775949617a1) (int posx, int posy) = 0<br>Sets the position of the window. |
|virtual void|[**setSize**](classffw_1_1_render_window.md#1a5e8e8ff90cc10668fd094f014a1d4443) (int width, int height) = 0<br>Sets the size of the window. |
|virtual **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**getPos**](classffw_1_1_render_window.md#1aa315da9361cd782570780a3cc2c774af) () const = 0|
|virtual **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**getSize**](classffw_1_1_render_window.md#1a595588b6d95c29495cd0928e8af747ca) () const = 0|
|virtual void|[**destroy**](classffw_1_1_render_window.md#1aa2da20ab3804b6087420b48c8eb18736) () = 0|
|virtual bool|[**shouldRender**](classffw_1_1_render_window.md#1a1ebad2106b42ec4f771a69bc3a3fb082) () const = 0<br>Returns true if the window is not closed. |
|virtual void|[**renderFrame**](classffw_1_1_render_window.md#1adca1e202f3dc76ab2423090551676a3c) () = 0<br>Renders a frame. |
|virtual void|[**poolEvents**](classffw_1_1_render_window.md#1ab804b9ad96a1c7c1b21d90860f01e01c) () = 0<br>Pools all user input events, if any. |
|virtual void|[**waitForEvents**](classffw_1_1_render_window.md#1ae421509ca35010cbd7db71f8c11946ca) () = 0<br>Pools all user input events and waits if there is none. |
|virtual bool|[**isInitialized**](classffw_1_1_render_window.md#1a72fc237b45f777dd7f4dbeb014b0b616) () const = 0<br>Returns true if the window is initialized. |
|virtual void|[**shouldClose**](classffw_1_1_render_window.md#1a8aa07a645357b06812e23fa06bee8076) (bool close) = 0<br>Set whether the window should close or stay alive. |
|virtual void|[**show**](classffw_1_1_render_window.md#1ab8eb2be9cfb3aefc8dffdb1228482d6a) () = 0<br>Shows the window if the window has been hidden. |
|virtual void|[**hide**](classffw_1_1_render_window.md#1ae2a8b392e2537be361ee7c1eea547e31) () = 0<br>Hides the window if the window is visible. |
|virtual void|[**iconify**](classffw_1_1_render_window.md#1a7544a3014cddfcce5a51b44a82efaa73) () = 0<br>Minimizes the window into the task bar. |
|virtual void|[**restore**](classffw_1_1_render_window.md#1a5d09d206980971cf8640360ac331730d) () = 0<br>Restores minimized window into a visible window. |
|virtual void|[**maximize**](classffw_1_1_render_window.md#1aed21fdd74781cf3cc44fd11c7da0c17a) () = 0<br>Maximizes the window in order to utilize whole screen. |
|virtual void|[**setSingleBufferMode**](classffw_1_1_render_window.md#1aaf2199e736ae4006c75d1564d8dcb402) (bool enabled) = 0<br>Sets whether the window should operate using two buffets (back and front) or only in one. |


## Public Functions Documentation

### function <a id="1a0c1ec1126da519d82a2281cbf9c8736a" href="#1a0c1ec1126da519d82a2281cbf9c8736a">~RenderWindow</a>

```cpp
virtual ffw::RenderWindow::~RenderWindow () = default
```



### function <a id="1a555c078b31cabb0093fe2775949617a1" href="#1a555c078b31cabb0093fe2775949617a1">setPos</a>

```cpp
virtual void ffw::RenderWindow::setPos (
    int posx
    int posy
) = 0
```

Sets the position of the window. 


### function <a id="1a5e8e8ff90cc10668fd094f014a1d4443" href="#1a5e8e8ff90cc10668fd094f014a1d4443">setSize</a>

```cpp
virtual void ffw::RenderWindow::setSize (
    int width
    int height
) = 0
```

Sets the size of the window. 


### function <a id="1aa315da9361cd782570780a3cc2c774af" href="#1aa315da9361cd782570780a3cc2c774af">getPos</a>

```cpp
virtual ffw::Vec2i ffw::RenderWindow::getPos () const = 0
```



### function <a id="1a595588b6d95c29495cd0928e8af747ca" href="#1a595588b6d95c29495cd0928e8af747ca">getSize</a>

```cpp
virtual ffw::Vec2i ffw::RenderWindow::getSize () const = 0
```



### function <a id="1aa2da20ab3804b6087420b48c8eb18736" href="#1aa2da20ab3804b6087420b48c8eb18736">destroy</a>

```cpp
virtual void ffw::RenderWindow::destroy () = 0
```



### function <a id="1a1ebad2106b42ec4f771a69bc3a3fb082" href="#1a1ebad2106b42ec4f771a69bc3a3fb082">shouldRender</a>

```cpp
virtual bool ffw::RenderWindow::shouldRender () const = 0
```

Returns true if the window is not closed. 

When **[shouldClose()](classffw_1_1_render_window.md#1a8aa07a645357b06812e23fa06bee8076)** is called with a 'true' boolean value, this function will then return false 

### function <a id="1adca1e202f3dc76ab2423090551676a3c" href="#1adca1e202f3dc76ab2423090551676a3c">renderFrame</a>

```cpp
virtual void ffw::RenderWindow::renderFrame () = 0
```

Renders a frame. 


### function <a id="1ab804b9ad96a1c7c1b21d90860f01e01c" href="#1ab804b9ad96a1c7c1b21d90860f01e01c">poolEvents</a>

```cpp
virtual void ffw::RenderWindow::poolEvents () = 0
```

Pools all user input events, if any. 

This is blocking function that will return whenever there are any events in the queue. If you wish to wait for the user first, see **[waitForEvents()](classffw_1_1_render_window.md#1ae421509ca35010cbd7db71f8c11946ca)** 

### function <a id="1ae421509ca35010cbd7db71f8c11946ca" href="#1ae421509ca35010cbd7db71f8c11946ca">waitForEvents</a>

```cpp
virtual void ffw::RenderWindow::waitForEvents () = 0
```

Pools all user input events and waits if there is none. 

This is blocking function that will not return unless there is at least one user event. If you wish to have continuous rendering, even if there are no user events, use **[poolEvents()](classffw_1_1_render_window.md#1ab804b9ad96a1c7c1b21d90860f01e01c)** 

### function <a id="1a72fc237b45f777dd7f4dbeb014b0b616" href="#1a72fc237b45f777dd7f4dbeb014b0b616">isInitialized</a>

```cpp
virtual bool ffw::RenderWindow::isInitialized () const = 0
```

Returns true if the window is initialized. 


### function <a id="1a8aa07a645357b06812e23fa06bee8076" href="#1a8aa07a645357b06812e23fa06bee8076">shouldClose</a>

```cpp
virtual void ffw::RenderWindow::shouldClose (
    bool close
) = 0
```

Set whether the window should close or stay alive. 


### function <a id="1ab8eb2be9cfb3aefc8dffdb1228482d6a" href="#1ab8eb2be9cfb3aefc8dffdb1228482d6a">show</a>

```cpp
virtual void ffw::RenderWindow::show () = 0
```

Shows the window if the window has been hidden. 


### function <a id="1ae2a8b392e2537be361ee7c1eea547e31" href="#1ae2a8b392e2537be361ee7c1eea547e31">hide</a>

```cpp
virtual void ffw::RenderWindow::hide () = 0
```

Hides the window if the window is visible. 


### function <a id="1a7544a3014cddfcce5a51b44a82efaa73" href="#1a7544a3014cddfcce5a51b44a82efaa73">iconify</a>

```cpp
virtual void ffw::RenderWindow::iconify () = 0
```

Minimizes the window into the task bar. 


### function <a id="1a5d09d206980971cf8640360ac331730d" href="#1a5d09d206980971cf8640360ac331730d">restore</a>

```cpp
virtual void ffw::RenderWindow::restore () = 0
```

Restores minimized window into a visible window. 


### function <a id="1aed21fdd74781cf3cc44fd11c7da0c17a" href="#1aed21fdd74781cf3cc44fd11c7da0c17a">maximize</a>

```cpp
virtual void ffw::RenderWindow::maximize () = 0
```

Maximizes the window in order to utilize whole screen. 

This is not the same as full screen mode! 

### function <a id="1aaf2199e736ae4006c75d1564d8dcb402" href="#1aaf2199e736ae4006c75d1564d8dcb402">setSingleBufferMode</a>

```cpp
virtual void ffw::RenderWindow::setSingleBufferMode (
    bool enabled
) = 0
```

Sets whether the window should operate using two buffets (back and front) or only in one. 




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/renderwindow.h`
