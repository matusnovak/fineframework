---
search:
    keywords: ['ffw::GuiWindowOpenGL', 'context', 'scissors', 'GuiWindowOpenGL', '~GuiWindowOpenGL', 'create', 'destroy', 'resize', 'drawBackground', 'drawBorder', 'drawRectangle', 'drawRectangleRounded', 'drawLine', 'drawCircle', 'drawArc', 'drawQuad', 'drawString', 'drawTriangle', 'drawImage', 'startRender', 'endRender', 'setScissors', 'clearWithColor', 'GuiWindow', '~GuiWindow', 'setSize', 'setPos', 'getSize', 'getPos', 'setDefaultFont', 'getDefaultFont', 'injectMousePos', 'injectScroll', 'injectMouseButton', 'injectText', 'injectKey', 'update', 'poolEvents', 'render', 'redraw', 'invalidate', 'getLayout', 'getLayout', 'pushEvent', 'setTheme', 'getTheme', 'findByID', 'resize', 'startRender', 'endRender', 'setScissors', 'clearWithColor', 'drawRectangle', 'drawRectangleRounded', 'drawLine', 'drawCircle', 'drawArc', 'drawQuad', 'drawString', 'drawTriangle', 'drawImage', 'drawBackground', 'drawBorder', 'drawStringAligned']
---

# class ffw::GuiWindowOpenGL



Inherits the following classes: **[ffw::GuiWindow](classffw_1_1_gui_window.md)**



Inherited by the following classes: **[ffw::GuiWindowOpenGLFBO](classffw_1_1_gui_window_open_g_l_f_b_o.md)**

## Protected Attributes

|Type|Name|
|-----|-----|
|**[RenderContext](classffw_1_1_render_context.md)** \*|[**context**](classffw_1_1_gui_window_open_g_l.md#1ade228e3f1d7cdfcf0a0e91ccc279f314)|
|**[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)**|[**scissors**](classffw_1_1_gui_window_open_g_l.md#1afcae9161fbaa59bcb099955b71f66032)|


## Public Functions

|Type|Name|
|-----|-----|
||[**GuiWindowOpenGL**](classffw_1_1_gui_window_open_g_l.md#1af0023b9d5fbcd03f89bfcf5201a00399) () |
|virtual |[**~GuiWindowOpenGL**](classffw_1_1_gui_window_open_g_l.md#1a2bf3dbb74d24832107c38de839791922) () |
|virtual bool|[**create**](classffw_1_1_gui_window_open_g_l.md#1a21e6fb9cea28830d2c3b62982aaf1055) (**[RenderContext](classffw_1_1_render_context.md)** \* ctx) |
|virtual void|[**destroy**](classffw_1_1_gui_window_open_g_l.md#1a3d04a93ed23822f66999dc5229b2d072) () |
|virtual void|[**resize**](classffw_1_1_gui_window_open_g_l.md#1a0ce86a092485c3373a2f26154ba74f84) (int width, int height) override |
|virtual void|[**drawBackground**](classffw_1_1_gui_window_open_g_l.md#1afb5c6ee94821c3591c9db83495ccdd18) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle::Background](classffw_1_1_gui_style_1_1_background.md)** & background, bool ignore) override const |
|virtual void|[**drawBorder**](classffw_1_1_gui_window_open_g_l.md#1aaa05af1c8039d02a66f5c225ecc94511) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiStyle::Border](classffw_1_1_gui_style_1_1_border.md)** & border) override const |
|virtual void|[**drawRectangle**](classffw_1_1_gui_window_open_g_l.md#1a3f2fb3e82fded26079d5ec92fa5e5334) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & s, const **[ffw::Color](structffw_1_1_color.md)** & color) override const |
|virtual void|[**drawRectangleRounded**](classffw_1_1_gui_window_open_g_l.md#1ad796eca8aba7e364ae3cb33b076cbcc3) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & s, const **[ffw::Color](structffw_1_1_color.md)** & color, float tl, float tr, float br, float bl) override const |
|virtual void|[**drawLine**](classffw_1_1_gui_window_open_g_l.md#1a8f34c82ed6f877d437abdb45b2eb3fc1) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & start, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & end, const **[ffw::Color](structffw_1_1_color.md)** & color, float width) override const |
|virtual void|[**drawCircle**](classffw_1_1_gui_window_open_g_l.md#1ac68892aac06ced595ad1de8d958f1f82) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, float radius, const **[ffw::Color](structffw_1_1_color.md)** & color) override const |
|virtual void|[**drawArc**](classffw_1_1_gui_window_open_g_l.md#1acd4be81d1dbe04c34d6caaf591fd83f2) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, float inner, float outer, float start, float end, const **[ffw::Color](structffw_1_1_color.md)** & color) override const |
|virtual void|[**drawQuad**](classffw_1_1_gui_window_open_g_l.md#1a920d4b2c4ad8f3454b4eb13a5d4de320) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p0, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p1, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p2, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p3, const **[ffw::Color](structffw_1_1_color.md)** & color) override const |
|virtual void|[**drawString**](classffw_1_1_gui_window_open_g_l.md#1a4993ce0c8aeba70ba71692d3a818a66b) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, const std::string::value\_type \* str, size\_t length, const **[ffw::Color](structffw_1_1_color.md)** & color, float lineHeight = 1.25f) override const |
|virtual void|[**drawTriangle**](classffw_1_1_gui_window_open_g_l.md#1a59accdbfd9706b610283f59e65dfb811) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p0, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p1, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p2, const **[ffw::Color](structffw_1_1_color.md)** & color) override const |
|virtual void|[**drawImage**](classffw_1_1_gui_window_open_g_l.md#1a074f26b6e5b18411f6c1051fb64dac11) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & s, const **[GuiImage](classffw_1_1_gui_image.md)** \* image, const **[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)** & sub, bool mirrorX, bool mirrorY, const **[ffw::Color](structffw_1_1_color.md)** & color) override const |
|virtual void|[**startRender**](classffw_1_1_gui_window_open_g_l.md#1ab2ae76582cb0c701db24f89971270b54) () override |
|virtual void|[**endRender**](classffw_1_1_gui_window_open_g_l.md#1a62f18367492912cd799f7613cacf3974) () override |
|virtual void|[**setScissors**](classffw_1_1_gui_window_open_g_l.md#1a7a6e49fcfac8b5d0f24333492df2aeaa) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & p, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & s) override const |
|virtual void|[**clearWithColor**](classffw_1_1_gui_window_open_g_l.md#1a11a0b29eb3a71681464055b9a24c06bd) (const **[ffw::Color](structffw_1_1_color.md)** & color) override const |


#### Public Functions inherited from [ffw::GuiWindow](classffw_1_1_gui_window.md)

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
|virtual void|[**drawStringAligned**](classffw_1_1_gui_backend.md#1a2866be02e4afb2b1e1ac529ff4ca4f54) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, **[ffw::GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** align, const std::string & str, const **[ffw::GuiStyle::Text](classffw_1_1_gui_style_1_1_text.md)** & text, float lineHeight = 1.25f) const |


## Protected Attributes Documentation

### variable <a id="1ade228e3f1d7cdfcf0a0e91ccc279f314" href="#1ade228e3f1d7cdfcf0a0e91ccc279f314">context</a>

```cpp
RenderContext* ffw::GuiWindowOpenGL::context;
```



### variable <a id="1afcae9161fbaa59bcb099955b71f66032" href="#1afcae9161fbaa59bcb099955b71f66032">scissors</a>

```cpp
ffw::Vec4i ffw::GuiWindowOpenGL::scissors;
```



## Public Functions Documentation

### function <a id="1af0023b9d5fbcd03f89bfcf5201a00399" href="#1af0023b9d5fbcd03f89bfcf5201a00399">GuiWindowOpenGL</a>

```cpp
ffw::GuiWindowOpenGL::GuiWindowOpenGL ()
```



### function <a id="1a2bf3dbb74d24832107c38de839791922" href="#1a2bf3dbb74d24832107c38de839791922">~GuiWindowOpenGL</a>

```cpp
virtual ffw::GuiWindowOpenGL::~GuiWindowOpenGL ()
```



### function <a id="1a21e6fb9cea28830d2c3b62982aaf1055" href="#1a21e6fb9cea28830d2c3b62982aaf1055">create</a>

```cpp
virtual bool ffw::GuiWindowOpenGL::create (
    RenderContext * ctx
)
```



### function <a id="1a3d04a93ed23822f66999dc5229b2d072" href="#1a3d04a93ed23822f66999dc5229b2d072">destroy</a>

```cpp
virtual void ffw::GuiWindowOpenGL::destroy ()
```



### function <a id="1a0ce86a092485c3373a2f26154ba74f84" href="#1a0ce86a092485c3373a2f26154ba74f84">resize</a>

```cpp
virtual void ffw::GuiWindowOpenGL::resize (
    int width
    int height
)
```

Overrides **[GuiBackend::resize](classffw_1_1_gui_backend.md#1af2497bddcba3d8ff994bbfe2ad4e5e10)**


### function <a id="1afb5c6ee94821c3591c9db83495ccdd18" href="#1afb5c6ee94821c3591c9db83495ccdd18">drawBackground</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawBackground (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::GuiStyle::Background & background
    bool ignore
) const
```

Overrides **[GuiBackend::drawBackground](classffw_1_1_gui_backend.md#1a2263692d05a3ac835df270d8f9667e83)**


### function <a id="1aaa05af1c8039d02a66f5c225ecc94511" href="#1aaa05af1c8039d02a66f5c225ecc94511">drawBorder</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawBorder (
    const ffw::Vec2f & pos
    const ffw::Vec2f & size
    const ffw::GuiStyle::Border & border
) const
```

Overrides **[GuiBackend::drawBorder](classffw_1_1_gui_backend.md#1ac27fbd05605bf02fb28140af882b5934)**


### function <a id="1a3f2fb3e82fded26079d5ec92fa5e5334" href="#1a3f2fb3e82fded26079d5ec92fa5e5334">drawRectangle</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawRectangle (
    const ffw::Vec2f & p
    const ffw::Vec2f & s
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::drawRectangle](classffw_1_1_gui_backend.md#1ac0e6c85a64919688c98921078db355c7)**


### function <a id="1ad796eca8aba7e364ae3cb33b076cbcc3" href="#1ad796eca8aba7e364ae3cb33b076cbcc3">drawRectangleRounded</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawRectangleRounded (
    const ffw::Vec2f & p
    const ffw::Vec2f & s
    const ffw::Color & color
    float tl
    float tr
    float br
    float bl
) const
```

Overrides **[GuiBackend::drawRectangleRounded](classffw_1_1_gui_backend.md#1aa38eea352be83acdb80c82f3a4f04167)**


### function <a id="1a8f34c82ed6f877d437abdb45b2eb3fc1" href="#1a8f34c82ed6f877d437abdb45b2eb3fc1">drawLine</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawLine (
    const ffw::Vec2f & start
    const ffw::Vec2f & end
    const ffw::Color & color
    float width
) const
```

Overrides **[GuiBackend::drawLine](classffw_1_1_gui_backend.md#1a35a502ee6bfc87ce536e0607e74ef864)**


### function <a id="1ac68892aac06ced595ad1de8d958f1f82" href="#1ac68892aac06ced595ad1de8d958f1f82">drawCircle</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawCircle (
    const ffw::Vec2f & p
    float radius
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::drawCircle](classffw_1_1_gui_backend.md#1a5f9716be2ca6c0c5dc9dd12bf97c105c)**


### function <a id="1acd4be81d1dbe04c34d6caaf591fd83f2" href="#1acd4be81d1dbe04c34d6caaf591fd83f2">drawArc</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawArc (
    const ffw::Vec2f & p
    float inner
    float outer
    float start
    float end
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::drawArc](classffw_1_1_gui_backend.md#1a0972ad84af1761a984a21d19ebb152d2)**


### function <a id="1a920d4b2c4ad8f3454b4eb13a5d4de320" href="#1a920d4b2c4ad8f3454b4eb13a5d4de320">drawQuad</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawQuad (
    const ffw::Vec2f & p0
    const ffw::Vec2f & p1
    const ffw::Vec2f & p2
    const ffw::Vec2f & p3
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::drawQuad](classffw_1_1_gui_backend.md#1a085e50da7e2417c71706a69098fbed0f)**


### function <a id="1a4993ce0c8aeba70ba71692d3a818a66b" href="#1a4993ce0c8aeba70ba71692d3a818a66b">drawString</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawString (
    const ffw::Vec2f & p
    const ffw::GuiFont * font
    const std::string::value_type * str
    size_t length
    const ffw::Color & color
    float lineHeight = 1.25f
) const
```

Overrides **[GuiBackend::drawString](classffw_1_1_gui_backend.md#1a4131f21a340d055f3b44ab4b8f45fe73)**


### function <a id="1a59accdbfd9706b610283f59e65dfb811" href="#1a59accdbfd9706b610283f59e65dfb811">drawTriangle</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawTriangle (
    const ffw::Vec2f & p0
    const ffw::Vec2f & p1
    const ffw::Vec2f & p2
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::drawTriangle](classffw_1_1_gui_backend.md#1a8c4e05f163ca039a822268e6210fa413)**


### function <a id="1a074f26b6e5b18411f6c1051fb64dac11" href="#1a074f26b6e5b18411f6c1051fb64dac11">drawImage</a>

```cpp
virtual void ffw::GuiWindowOpenGL::drawImage (
    const ffw::Vec2f & p
    const ffw::Vec2f & s
    const GuiImage * image
    const ffw::Vec4i & sub
    bool mirrorX
    bool mirrorY
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::drawImage](classffw_1_1_gui_backend.md#1acacdb5a3d602c0ff919a9e87f65d3aa9)**


### function <a id="1ab2ae76582cb0c701db24f89971270b54" href="#1ab2ae76582cb0c701db24f89971270b54">startRender</a>

```cpp
virtual void ffw::GuiWindowOpenGL::startRender ()
```

Overrides **[GuiBackend::startRender](classffw_1_1_gui_backend.md#1a7a10d3b391690aced9ff03b553d94a44)**


### function <a id="1a62f18367492912cd799f7613cacf3974" href="#1a62f18367492912cd799f7613cacf3974">endRender</a>

```cpp
virtual void ffw::GuiWindowOpenGL::endRender ()
```

Overrides **[GuiBackend::endRender](classffw_1_1_gui_backend.md#1a26d844c1babfeadc631dc45df723dc37)**


### function <a id="1a7a6e49fcfac8b5d0f24333492df2aeaa" href="#1a7a6e49fcfac8b5d0f24333492df2aeaa">setScissors</a>

```cpp
virtual void ffw::GuiWindowOpenGL::setScissors (
    const ffw::Vec2f & p
    const ffw::Vec2f & s
) const
```

Overrides **[GuiBackend::setScissors](classffw_1_1_gui_backend.md#1aa835cc230789a8458487295a98022df6)**


### function <a id="1a11a0b29eb3a71681464055b9a24c06bd" href="#1a11a0b29eb3a71681464055b9a24c06bd">clearWithColor</a>

```cpp
virtual void ffw::GuiWindowOpenGL::clearWithColor (
    const ffw::Color & color
) const
```

Overrides **[GuiBackend::clearWithColor](classffw_1_1_gui_backend.md#1a4f3ce651bfa2ed17b43f018b6d96362d)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guiwindowopengl.h`
