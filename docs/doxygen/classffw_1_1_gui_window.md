---
search: false
---

# class ffw::GuiWindow



Inherits the following classes: **[ffw::GuiBackend](classffw_1_1_gui_backend.md)**



Inherited by the following classes: **[ffw::GuiWindowOpenGL](classffw_1_1_gui_window_open_g_l.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**GuiWindow**](classffw_1_1_gui_window.md#1a33f0672a19ac459522cc198a0ed05bcf) () |
|virtual |[**~GuiWindow**](classffw_1_1_gui_window.md#1a0c5d8302fb98730c5ebd26ddbcaf85d6) () |
|void|[**setSize**](classffw_1_1_gui_window.md#1ae939277a4fca55bfd8719b94304b1a60) (float width, float height) |
|void|[**setPos**](classffw_1_1_gui_window.md#1a0002ea7af0f448ce52c84c913dd64914) (float posx, float posy) |
|const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** &|[**getSize**](classffw_1_1_gui_window.md#1ab69439c244429adfe9c6f71c5cebcfcb) () const |
|const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** &|[**getPos**](classffw_1_1_gui_window.md#1aced41be727dad090db7b6fbc74da466a) () const |
|void|[**setDefaultFont**](classffw_1_1_gui_window.md#1a69b119695e954f116b457e4e8e899eb7) (const **[GuiFont](classffw_1_1_gui_font.md)** \* font) |
|const **[GuiFont](classffw_1_1_gui_font.md)** \*|[**getDefaultFont**](classffw_1_1_gui_window.md#1a32e798f41516173f54e2393005f3bb5c) () const |
|void|[**injectMousePos**](classffw_1_1_gui_window.md#1a6cda8e7293efe9c3bc88b913e1eaf62d) (float posx, float posy) |
|void|[**injectScroll**](classffw_1_1_gui_window.md#1ae6ea4f8221a1a90279ad8ed274bbf1cd) (float posx, float posy) |
|void|[**injectMouseButton**](classffw_1_1_gui_window.md#1a81f96d5659ad48d2dd536c69214f8fa0) (**[ffw::MouseButton](namespaceffw.md#1a27b70bbb6a1b35235c34a999d7420b25)** button, **[ffw::Mode](namespaceffw.md#1a7c343296bbf3216a2b78bd49ae015373)** mode) |
|void|[**injectText**](classffw_1_1_gui_window.md#1aac5f10d6d9aeb5ac0f317b582dd21144) (wchar\_t chr) |
|void|[**injectKey**](classffw_1_1_gui_window.md#1a2fe6644296bbf01eddc768bf2be6f89e) (**[ffw::Key](namespaceffw.md#1a4194e8f0528edf866a3fdfbc1ecba254)** key, **[ffw::Mode](namespaceffw.md#1a7c343296bbf3216a2b78bd49ae015373)** mode) |
|void|[**update**](classffw_1_1_gui_window.md#1ab18d22e0fd5b091a65d1288ba932008a) () |
|void|[**poolEvents**](classffw_1_1_gui_window.md#1a8da3d62196780f6ddfc3b68e1605266c) () |
|void|[**render**](classffw_1_1_gui_window.md#1a2689dd22c2f7b1bf7d13b70669ac6791) () |
|void|[**redraw**](classffw_1_1_gui_window.md#1ae29ef50209d69699ebda93dc28f7f5e3) () |
|void|[**invalidate**](classffw_1_1_gui_window.md#1a6ef636499869258a5d3f1a0fdab905bd) () |
|**[GuiBody](classffw_1_1_gui_body.md)** \*|[**getLayout**](classffw_1_1_gui_window.md#1a99c9061abf18c13778aec315ae18a6a0) () |
|const **[GuiBody](classffw_1_1_gui_body.md)** \*|[**getLayout**](classffw_1_1_gui_window.md#1a28a5b55550bee62dfcf44f11a99e4697) () const |
|void|[**pushEvent**](classffw_1_1_gui_window.md#1aa2e4a6fa0e54aa629e16a5144599ec62) (std::vector< **[GuiCallback](structffw_1_1_gui_callback.md)** > & callbacks, **[GuiEvent](classffw_1_1_gui_event.md)** e) |
|void|[**setTheme**](classffw_1_1_gui_window.md#1a2ff9c29d017fb246cbe5c0f01b8ef026) (const **[GuiTheme](classffw_1_1_gui_theme.md)** \* thm, bool defaults = false) |
|const **[GuiTheme](classffw_1_1_gui_theme.md)** \*|[**getTheme**](classffw_1_1_gui_window.md#1acc9bd90424bc561c38d2b6bb447f58cc) () const |
|T \*|[**findByID**](classffw_1_1_gui_window.md#1aa3acf616ea9b1d53a24e00cf52dcc259) (unsigned long id) |


#### Public Functions inherited from [ffw::GuiBackend](classffw_1_1_gui_backend.md)

|Type|Name|
|-----|-----|
|virtual void|[**resize**](classffw_1_1_gui_backend.md#1af2497bddcba3d8ff994bbfe2ad4e5e10) (int width, int height) = 0|
|virtual void|[**startRender**](classffw_1_1_gui_backend.md#1a7a10d3b391690aced9ff03b553d94a44) () = 0|
|virtual void|[**endRender**](classffw_1_1_gui_backend.md#1a26d844c1babfeadc631dc45df723dc37) () = 0|
|virtual void|[**setScissors**](classffw_1_1_gui_backend.md#1aa835cc230789a8458487295a98022df6) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size) const = 0|
|virtual void|[**clearWithColor**](classffw_1_1_gui_backend.md#1a4f3ce651bfa2ed17b43f018b6d96362d) (const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawRectangle**](classffw_1_1_gui_backend.md#1ac0e6c85a64919688c98921078db355c7) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawRectangleRounded**](classffw_1_1_gui_backend.md#1aa38eea352be83acdb80c82f3a4f04167) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::Color](structffw_1_1_color.md)** & color, float tl, float tr, float br, float bl) const = 0|
|virtual void|[**drawLine**](classffw_1_1_gui_backend.md#1a35a502ee6bfc87ce536e0607e74ef864) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & start, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & end, const **[ffw::Color](structffw_1_1_color.md)** & color, float width = 1.0f) const = 0|
|virtual void|[**drawCircle**](classffw_1_1_gui_backend.md#1a5f9716be2ca6c0c5dc9dd12bf97c105c) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, float radius, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawArc**](classffw_1_1_gui_backend.md#1a0972ad84af1761a984a21d19ebb152d2) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, float inner, float outer, float start, float end, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawQuad**](classffw_1_1_gui_backend.md#1a085e50da7e2417c71706a69098fbed0f) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p0, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p1, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p2, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p3, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawString**](classffw_1_1_gui_backend.md#1a4131f21a340d055f3b44ab4b8f45fe73) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, const std::string::value\_type \* str, size\_t length, const **[ffw::Color](structffw_1_1_color.md)** & color, float lineHeight = 1.25f) const = 0|
|virtual void|[**drawTriangle**](classffw_1_1_gui_backend.md#1a8c4e05f163ca039a822268e6210fa413) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p0, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p1, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p2, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawImage**](classffw_1_1_gui_backend.md#1acacdb5a3d602c0ff919a9e87f65d3aa9) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[GuiImage](classffw_1_1_gui_image.md)** \* image, const **[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)** & sub, bool mirrorX, bool mirrorY, const **[ffw::Color](structffw_1_1_color.md)** & color) const = 0|
|virtual void|[**drawBackground**](classffw_1_1_gui_backend.md#1a2263692d05a3ac835df270d8f9667e83) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle::Background](classffw_1_1_gui_style_1_1_background.md)** & background, bool ignore = false) const = 0|
|virtual void|[**drawBorder**](classffw_1_1_gui_backend.md#1ac27fbd05605bf02fb28140af882b5934) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle::Border](classffw_1_1_gui_style_1_1_border.md)** & border) const = 0|
|virtual void|[**drawStringAligned**](classffw_1_1_gui_backend.md#1a2866be02e4afb2b1e1ac529ff4ca4f54) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, **[ffw::GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** align, const std::string & str, const **[ffw::GuiStyle::Text](classffw_1_1_gui_style_1_1_text.md)** & text, float lineHeight = 1.25f) const |


## Public Functions Documentation

### function <a id="1a33f0672a19ac459522cc198a0ed05bcf" href="#1a33f0672a19ac459522cc198a0ed05bcf">GuiWindow</a>

```cpp
ffw::GuiWindow::GuiWindow ()
```



### function <a id="1a0c5d8302fb98730c5ebd26ddbcaf85d6" href="#1a0c5d8302fb98730c5ebd26ddbcaf85d6">~GuiWindow</a>

```cpp
virtual ffw::GuiWindow::~GuiWindow ()
```



### function <a id="1ae939277a4fca55bfd8719b94304b1a60" href="#1ae939277a4fca55bfd8719b94304b1a60">setSize</a>

```cpp
void ffw::GuiWindow::setSize (
    float width
    float height
)
```



### function <a id="1a0002ea7af0f448ce52c84c913dd64914" href="#1a0002ea7af0f448ce52c84c913dd64914">setPos</a>

```cpp
void ffw::GuiWindow::setPos (
    float posx
    float posy
)
```



### function <a id="1ab69439c244429adfe9c6f71c5cebcfcb" href="#1ab69439c244429adfe9c6f71c5cebcfcb">getSize</a>

```cpp
const ffw::Vec2f & ffw::GuiWindow::getSize () const
```



### function <a id="1aced41be727dad090db7b6fbc74da466a" href="#1aced41be727dad090db7b6fbc74da466a">getPos</a>

```cpp
const ffw::Vec2f & ffw::GuiWindow::getPos () const
```



### function <a id="1a69b119695e954f116b457e4e8e899eb7" href="#1a69b119695e954f116b457e4e8e899eb7">setDefaultFont</a>

```cpp
void ffw::GuiWindow::setDefaultFont (
    const GuiFont * font
)
```



### function <a id="1a32e798f41516173f54e2393005f3bb5c" href="#1a32e798f41516173f54e2393005f3bb5c">getDefaultFont</a>

```cpp
const GuiFont * ffw::GuiWindow::getDefaultFont () const
```



### function <a id="1a6cda8e7293efe9c3bc88b913e1eaf62d" href="#1a6cda8e7293efe9c3bc88b913e1eaf62d">injectMousePos</a>

```cpp
void ffw::GuiWindow::injectMousePos (
    float posx
    float posy
)
```



### function <a id="1ae6ea4f8221a1a90279ad8ed274bbf1cd" href="#1ae6ea4f8221a1a90279ad8ed274bbf1cd">injectScroll</a>

```cpp
void ffw::GuiWindow::injectScroll (
    float posx
    float posy
)
```



### function <a id="1a81f96d5659ad48d2dd536c69214f8fa0" href="#1a81f96d5659ad48d2dd536c69214f8fa0">injectMouseButton</a>

```cpp
void ffw::GuiWindow::injectMouseButton (
    ffw::MouseButton button
    ffw::Mode mode
)
```



### function <a id="1aac5f10d6d9aeb5ac0f317b582dd21144" href="#1aac5f10d6d9aeb5ac0f317b582dd21144">injectText</a>

```cpp
void ffw::GuiWindow::injectText (
    wchar_t chr
)
```



### function <a id="1a2fe6644296bbf01eddc768bf2be6f89e" href="#1a2fe6644296bbf01eddc768bf2be6f89e">injectKey</a>

```cpp
void ffw::GuiWindow::injectKey (
    ffw::Key key
    ffw::Mode mode
)
```



### function <a id="1ab18d22e0fd5b091a65d1288ba932008a" href="#1ab18d22e0fd5b091a65d1288ba932008a">update</a>

```cpp
void ffw::GuiWindow::update ()
```



### function <a id="1a8da3d62196780f6ddfc3b68e1605266c" href="#1a8da3d62196780f6ddfc3b68e1605266c">poolEvents</a>

```cpp
void ffw::GuiWindow::poolEvents ()
```



### function <a id="1a2689dd22c2f7b1bf7d13b70669ac6791" href="#1a2689dd22c2f7b1bf7d13b70669ac6791">render</a>

```cpp
void ffw::GuiWindow::render ()
```



### function <a id="1ae29ef50209d69699ebda93dc28f7f5e3" href="#1ae29ef50209d69699ebda93dc28f7f5e3">redraw</a>

```cpp
void ffw::GuiWindow::redraw ()
```



### function <a id="1a6ef636499869258a5d3f1a0fdab905bd" href="#1a6ef636499869258a5d3f1a0fdab905bd">invalidate</a>

```cpp
void ffw::GuiWindow::invalidate ()
```



### function <a id="1a99c9061abf18c13778aec315ae18a6a0" href="#1a99c9061abf18c13778aec315ae18a6a0">getLayout</a>

```cpp
GuiBody * ffw::GuiWindow::getLayout ()
```



### function <a id="1a28a5b55550bee62dfcf44f11a99e4697" href="#1a28a5b55550bee62dfcf44f11a99e4697">getLayout</a>

```cpp
const GuiBody * ffw::GuiWindow::getLayout () const
```



### function <a id="1aa2e4a6fa0e54aa629e16a5144599ec62" href="#1aa2e4a6fa0e54aa629e16a5144599ec62">pushEvent</a>

```cpp
void ffw::GuiWindow::pushEvent (
    std::vector< GuiCallback > & callbacks
    GuiEvent e
)
```



### function <a id="1a2ff9c29d017fb246cbe5c0f01b8ef026" href="#1a2ff9c29d017fb246cbe5c0f01b8ef026">setTheme</a>

```cpp
void ffw::GuiWindow::setTheme (
    const GuiTheme * thm
    bool defaults = false
)
```



### function <a id="1acc9bd90424bc561c38d2b6bb447f58cc" href="#1acc9bd90424bc561c38d2b6bb447f58cc">getTheme</a>

```cpp
const GuiTheme * ffw::GuiWindow::getTheme () const
```



### function <a id="1aa3acf616ea9b1d53a24e00cf52dcc259" href="#1aa3acf616ea9b1d53a24e00cf52dcc259">findByID</a>

```cpp
T * ffw::GuiWindow::findByID (
    unsigned long id
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guiwindow.h`
