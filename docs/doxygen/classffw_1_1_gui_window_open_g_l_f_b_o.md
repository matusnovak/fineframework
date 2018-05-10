---
search: false
---

# class ffw::GuiWindowOpenGLFBO



Inherits the following classes: **[ffw::GuiWindowOpenGL](classffw_1_1_gui_window_open_g_l.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**GuiWindowOpenGLFBO**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1aec6ceba8405c27c1593263734467875f) () |
|virtual |[**~GuiWindowOpenGLFBO**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1aaead8b37fcdaf18c3d73f384920a441c) () |
|virtual bool|[**create**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1a6d70edeef18d29d923095f60bb2745f9) (**[RenderContext](classffw_1_1_render_context.md)** \* ctx) override |
|virtual void|[**destroy**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1a0b80973b108c23ffa03e50df37780798) () override |
|virtual void|[**resize**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1aef162043c1201e6f06458e7728958c76) (int width, int height) override |
|virtual void|[**startRender**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1a9c8b33daa398d2161ac6f50314ef70d2) () override |
|virtual void|[**endRender**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1ae307a22a51c78481dde54323a31cdcd2) () override |
|const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \*|[**getFboTexture**](classffw_1_1_gui_window_open_g_l_f_b_o.md#1aa62d95defa7655593e0a2cf06cc8a4fc) () const |


#### Public Functions inherited from [ffw::GuiWindowOpenGL](classffw_1_1_gui_window_open_g_l.md)

|Type|Name|
|-----|-----|
||[**GuiWindowOpenGL**](classffw_1_1_gui_window_open_g_l.md#1af0023b9d5fbcd03f89bfcf5201a00399) () |
|virtual |[**~GuiWindowOpenGL**](classffw_1_1_gui_window_open_g_l.md#1a2bf3dbb74d24832107c38de839791922) () |
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
|virtual void|[**resize**](classffw_1_1_gui_backend.md#1af2497bddcba3d8ff994bbfe2ad4e5e10) (int width, int height) = 0|
|virtual void|[**startRender**](classffw_1_1_gui_backend.md#1a7a10d3b391690aced9ff03b553d94a44) () = 0|
|virtual void|[**endRender**](classffw_1_1_gui_backend.md#1a26d844c1babfeadc631dc45df723dc37) () = 0|
|virtual void|[**drawStringAligned**](classffw_1_1_gui_backend.md#1a2866be02e4afb2b1e1ac529ff4ca4f54) (const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & pos, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & size, const **[ffw::GuiFont](classffw_1_1_gui_font.md)** \* font, **[ffw::GuiAlign](group__gui_.md#ga98e6ace67ac3624f040ae5de12b2ca32)** align, const std::string & str, const **[ffw::GuiStyle::Text](classffw_1_1_gui_style_1_1_text.md)** & text, float lineHeight = 1.25f) const |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::GuiWindowOpenGL](classffw_1_1_gui_window_open_g_l.md)

|Type|Name|
|-----|-----|
|**[RenderContext](classffw_1_1_render_context.md)** \*|[**context**](classffw_1_1_gui_window_open_g_l.md#1ade228e3f1d7cdfcf0a0e91ccc279f314)|
|**[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)**|[**scissors**](classffw_1_1_gui_window_open_g_l.md#1afcae9161fbaa59bcb099955b71f66032)|


## Public Functions Documentation

### function <a id="1aec6ceba8405c27c1593263734467875f" href="#1aec6ceba8405c27c1593263734467875f">GuiWindowOpenGLFBO</a>

```cpp
ffw::GuiWindowOpenGLFBO::GuiWindowOpenGLFBO ()
```



### function <a id="1aaead8b37fcdaf18c3d73f384920a441c" href="#1aaead8b37fcdaf18c3d73f384920a441c">~GuiWindowOpenGLFBO</a>

```cpp
virtual ffw::GuiWindowOpenGLFBO::~GuiWindowOpenGLFBO ()
```



### function <a id="1a6d70edeef18d29d923095f60bb2745f9" href="#1a6d70edeef18d29d923095f60bb2745f9">create</a>

```cpp
virtual bool ffw::GuiWindowOpenGLFBO::create (
    RenderContext * ctx
)
```

Overrides **[GuiWindowOpenGL::create](classffw_1_1_gui_window_open_g_l.md#1a21e6fb9cea28830d2c3b62982aaf1055)**


### function <a id="1a0b80973b108c23ffa03e50df37780798" href="#1a0b80973b108c23ffa03e50df37780798">destroy</a>

```cpp
virtual void ffw::GuiWindowOpenGLFBO::destroy ()
```

Overrides **[GuiWindowOpenGL::destroy](classffw_1_1_gui_window_open_g_l.md#1a3d04a93ed23822f66999dc5229b2d072)**


### function <a id="1aef162043c1201e6f06458e7728958c76" href="#1aef162043c1201e6f06458e7728958c76">resize</a>

```cpp
virtual void ffw::GuiWindowOpenGLFBO::resize (
    int width
    int height
)
```

Overrides **[GuiWindowOpenGL::resize](classffw_1_1_gui_window_open_g_l.md#1a0ce86a092485c3373a2f26154ba74f84)**


### function <a id="1a9c8b33daa398d2161ac6f50314ef70d2" href="#1a9c8b33daa398d2161ac6f50314ef70d2">startRender</a>

```cpp
virtual void ffw::GuiWindowOpenGLFBO::startRender ()
```

Overrides **[GuiWindowOpenGL::startRender](classffw_1_1_gui_window_open_g_l.md#1ab2ae76582cb0c701db24f89971270b54)**


### function <a id="1ae307a22a51c78481dde54323a31cdcd2" href="#1ae307a22a51c78481dde54323a31cdcd2">endRender</a>

```cpp
virtual void ffw::GuiWindowOpenGLFBO::endRender ()
```

Overrides **[GuiWindowOpenGL::endRender](classffw_1_1_gui_window_open_g_l.md#1a62f18367492912cd799f7613cacf3974)**


### function <a id="1aa62d95defa7655593e0a2cf06cc8a4fc" href="#1aa62d95defa7655593e0a2cf06cc8a4fc">getFboTexture</a>

```cpp
const ffw::Texture2D * ffw::GuiWindowOpenGLFBO::getFboTexture () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/gui/guiwindowopengl.h`
