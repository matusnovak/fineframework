---
search:
    keywords: ['ffw::RenderContext', 'position', 'rgbMixer', 'color', 'proj', 'uvpos', 'tex', 'offset', 'view', 'RenderContext', '~RenderContext', 'getGlextFunc', 'isGlextExtSupported', 'initDrawing', 'beginFrame', 'endFrame', 'moveTo', 'setDrawColor', 'setFillColor', 'setStrokeColor', 'setFillPaint', 'setStrokePaint', 'createLinearGradient', 'createBoxGradient', 'createRadialGradient', 'drawQuad', 'drawRectangle', 'drawRectangleRounded', 'drawRectangleRounded', 'drawTriangle', 'drawTexture2D', 'drawTexture2DMirror', 'drawTexture2DSub', 'drawTexture2DSubMirror', 'drawArc', 'drawCircle', 'drawLine', 'drawString', 'drawString', 'drawString', 'drawString', 'drawStringBox', 'drawStringBox', 'drawStringBox', 'drawStringBox', 'drawBezier', 'setDrawMode', 'setFillMode', 'setStrokeMode', 'setFillAndStrokeMode', 'setShapeAntiAlis', 'setStrokeSize', 'setStrokeMiterLimit', 'setLineCap', 'setLineJoin', 'setScissor', 'setIntersectScissor', 'resetScissor', 'beginPath', 'drawLineTo', 'drawBezierTo', 'drawQuadTo', 'drawArcTo', 'closePath', 'fillPath', 'strokePath', 'setPathWinding', 'saveDrawState', 'restoreDrawState', 'resetDrawState', 'resetTransform', 'transformMove', 'transformRotate', 'transformSkewX', 'transformSkewY', 'transformScale', 'transform', 'getTransform', 'getOpenGLTransform']
---

# class ffw::RenderContext

Basic render context which can be used to draw shapes using nanovg on the screen. 


Inherited by the following classes: **[ffw::GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)**

## Public Attributes

|Type|Name|
|-----|-----|
|int|[**position**](classffw_1_1_render_context.md#1aa5d6a095405936c3099100292b7a695c)|
|int|[**rgbMixer**](classffw_1_1_render_context.md#1a0ab38700f2f823e4f71a5de722126456)|
|int|[**color**](classffw_1_1_render_context.md#1a33c36ed9aacb6d5eba6f1edcbd344508)|
|int|[**proj**](classffw_1_1_render_context.md#1a3606b93fd845c8754c79af5a374214fe)|
|int|[**uvpos**](classffw_1_1_render_context.md#1a42491f65f6ee96509cd26139b636a7fc)|
|int|[**tex**](classffw_1_1_render_context.md#1a349be8c4a1cb3e9592906aa755ea0b67)|
|int|[**offset**](classffw_1_1_render_context.md#1a843ef524a272618624cddc6d5c3e3c5a)|
|int|[**view**](classffw_1_1_render_context.md#1a5ef7b6813536bdce194008c2cad0273d)|


## Public Functions

|Type|Name|
|-----|-----|
||[**RenderContext**](classffw_1_1_render_context.md#1add23aa7b649ed9d361a16f2b5d840800) () |
|virtual |[**~RenderContext**](classffw_1_1_render_context.md#1ac693a01e5da7e7b29be9cc53ef34d9f5) () |
|virtual void \*|[**getGlextFunc**](classffw_1_1_render_context.md#1add007968b520cde93577b6b858f029a9) (const std::string & name) const = 0<br>Retuns the address of the GL extension function. |
|virtual bool|[**isGlextExtSupported**](classffw_1_1_render_context.md#1a3e75b86b22be32db52bd370ad435fd34) (const std::string & name) const = 0<br>Returns true if the GL extension is suported. |
|bool|[**initDrawing**](classffw_1_1_render_context.md#1a3d4d4cd24fdeecae5ac99d4e5d8ee8ef) () <br>Initializes drawing functions. |
|void|[**beginFrame**](classffw_1_1_render_context.md#1a4313201325e2740731edfcd42b89bf95) () const <br>Begins the render frame and makes this context ready to be used with drawing function. |
|void|[**endFrame**](classffw_1_1_render_context.md#1add44f5f9ed7181b06c8b58b0f91c4d57) () const <br>Ends the render frame. |
|void|[**moveTo**](classffw_1_1_render_context.md#1ad4b9cd96927c73eb85e7f6f4986b4d71) (float x, float y) const |
|void|[**setDrawColor**](classffw_1_1_render_context.md#1aa135f5034cd376c7443ba28ddd5ceab1) (const **[ffw::Color](structffw_1_1_color.md)** & color) const <br>Sets the color of the next draw commands (fill and stroke color) |
|void|[**setFillColor**](classffw_1_1_render_context.md#1ac6520c2a5245ce98f7952e6878c5af40) (const **[ffw::Color](structffw_1_1_color.md)** & color) const <br>Sets the color of the next draw commands (fill only) |
|void|[**setStrokeColor**](classffw_1_1_render_context.md#1a95a0587b0cdeaa896a47c3fbecf749c5) (const **[ffw::Color](structffw_1_1_color.md)** & color) const <br>Sets the color of the next draw commands (stroke only) |
|void|[**setFillPaint**](classffw_1_1_render_context.md#1a7cbb9bf1186e9a5515092d4ea9cf2dbf) (const **[DrawPaint](structffw_1_1_draw_paint.md)** & paint) const <br>Sets current fill style to a paint, which can be a one of the gradients. |
|void|[**setStrokePaint**](classffw_1_1_render_context.md#1a73f3cbe5519dd5d6aba4c5be2301a171) (const **[DrawPaint](structffw_1_1_draw_paint.md)** & paint) const <br>Sets current stroke style to a paint, which can be a one of the gradients. |
|**[DrawPaint](structffw_1_1_draw_paint.md)**|[**createLinearGradient**](classffw_1_1_render_context.md#1a8874bea53615783f90fb59dda89bf273) (float sx, float sy, float ex, float ey, const **[ffw::Color](structffw_1_1_color.md)** & icol, const **[ffw::Color](structffw_1_1_color.md)** & ocol) const <br>Creates and returns a linear gradient, a wrapper around nvgLinearGradient. |
|**[DrawPaint](structffw_1_1_draw_paint.md)**|[**createBoxGradient**](classffw_1_1_render_context.md#1a3648c35243426cc22f2b8109d1699cfa) (float x, float y, float w, float h, float r, float f, const **[ffw::Color](structffw_1_1_color.md)** & icol, const **[ffw::Color](structffw_1_1_color.md)** & ocol) const <br>Creates and returns a box gradient, a wrapper around nvgBoxGradient. |
|**[DrawPaint](structffw_1_1_draw_paint.md)**|[**createRadialGradient**](classffw_1_1_render_context.md#1ae67ef80fb5c0644612e1411e6ec01767) (float cx, float cy, float inr, float outr, const **[ffw::Color](structffw_1_1_color.md)** & icol, const **[ffw::Color](structffw_1_1_color.md)** & ocol) const <br>Creates and returns a radial gradient, a wrapper around nvgRadialGradient. |
|void|[**drawQuad**](classffw_1_1_render_context.md#1a92d639f1ddfae67e5f623d2bbc49541c) (float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y) const <br>Draws a quad composing of 4 points. |
|void|[**drawRectangle**](classffw_1_1_render_context.md#1a4a7e2e5da4d6ea47ec630774990ad044) (float posx, float posy, float width, float height) const <br>Draws a simple rectangle. |
|void|[**drawRectangleRounded**](classffw_1_1_render_context.md#1a04c7ea0e82f9bc0f5c78d240bee3baab) (float posx, float posy, float width, float height, float corners) const <br>Draws a rectangle with rounded corners. |
|void|[**drawRectangleRounded**](classffw_1_1_render_context.md#1a337746aef8e7915eb3bf81d2fbafae0e) (float posx, float posy, float width, float height, float leftTop, float rightTop, float bottomRight, float bottomLeft) const <br>Draws a rectangle with rounded corners. |
|void|[**drawTriangle**](classffw_1_1_render_context.md#1a5f44dc8abcfdd0d100f7972073cafee7) (float p0x, float p0y, float p1x, float p1y, float p2x, float p2y) const <br>Draws a simple triangle. |
|void|[**drawTexture2D**](classffw_1_1_render_context.md#1ae533edaed5eb0bc3687060377107d68a) (float posx, float posy, float width, float height, const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture) const <br>Draws a 2D texture. |
|void|[**drawTexture2DMirror**](classffw_1_1_render_context.md#1a6ba1ac7c307d93064f3f65e1d9fe3255) (float posx, float posy, float width, float height, const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, bool mirrorx, bool mirrory) const <br>Draws a 2D texture that can be mirrored. |
|void|[**drawTexture2DSub**](classffw_1_1_render_context.md#1a4a9abb637c006db624dd26933c1f1e6e) (float posx, float posy, float width, float height, const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, int subx, int suby, int subw, int subh) const <br>Draws a rectangular subsection of the texture. |
|void|[**drawTexture2DSubMirror**](classffw_1_1_render_context.md#1a4c130eec1494dfc88c534fab83b8a48b) (float posx, float posy, float width, float height, const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, int subx, int suby, int subw, int subh, bool mirrorx, bool mirrory) const <br>Draws a mirrored rectangular subsection of the texture. |
|void|[**drawArc**](classffw_1_1_render_context.md#1ad2ff86d63992a805a40c3060e6626303) (float posx, float posy, float innerradius, float outerradius, double startangle, double endangle) const <br>Draws an arc using starting and ending angle. |
|void|[**drawCircle**](classffw_1_1_render_context.md#1a9db201a8e6d8e8d351b248aed2f6cd2a) (float posx, float posy, float radius) const <br>Draws a simple circle. |
|void|[**drawLine**](classffw_1_1_render_context.md#1a0eb73e2b8292a0b9cdb2bb1f7a364231) (float startx, float starty, float endx, float edny) const <br>Draws a line from point A to point B. |
|void|[**drawString**](classffw_1_1_render_context.md#1a9d4723eaf76ca55e9d4f6a18694524ac) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const std::string & str, float lineHeight = 1.25f) const <br>Draws a UTF-8 string. |
|void|[**drawString**](classffw_1_1_render_context.md#1a7dfb861d3f5f51339b7e1c6bee9131a8) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const std::wstring & str, float lineHeight = 1.25f) const <br>Draws a multi-byte string. |
|void|[**drawString**](classffw_1_1_render_context.md#1a3a6d28b72d70902aa44b7ad925b77ac5) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const char \* str, size\_t length, float lineHeight = 1.25f) const <br>Draws a UTF-8 string. |
|void|[**drawString**](classffw_1_1_render_context.md#1ac7a1f92543db28815bdea506effe805d) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const wchar\_t \* str, size\_t length, float lineHeight = 1.25f) const <br>Draws a wide string. |
|void|[**drawStringBox**](classffw_1_1_render_context.md#1aca5673fbacb63dfd251810fb89eedfa8) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const std::string & str, float maxWidth, float lineHeight = 1.25f) const <br>Draws a UTF-8 string wrapped inside a box with specified width. |
|void|[**drawStringBox**](classffw_1_1_render_context.md#1a3f0e2b15650e75e039c775e6ebaacedb) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const std::wstring & str, float maxWidth, float lineHeight = 1.25f) const <br>Draws a UTF-8 string wrapped inside a box with specified width. |
|void|[**drawStringBox**](classffw_1_1_render_context.md#1a4ef6e9e82d98b598d1c3e63fa73b91d5) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const char \* str, size\_t length, float maxWidth, float lineHeight = 1.25f) const <br>Draws a multi-byte string wrapped inside a box with specified width. |
|void|[**drawStringBox**](classffw_1_1_render_context.md#1a602972d20a0a6a2206b457e46bed784c) (float posx, float posy, const **[Font](classffw_1_1_font.md)** \* font, const wchar\_t \* str, size\_t length, float maxWidth, float lineHeight = 1.25f) const <br>Draws a multi-byte string wrapped inside a box with specified width. |
|void|[**drawBezier**](classffw_1_1_render_context.md#1ad0c6aea239ff9eff374fd14b54cbe4b7) (float startx, float starty, float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const <br>Draws a quadratic bezier curve. |
|void|[**setDrawMode**](classffw_1_1_render_context.md#1a1bb042c5ee6119200a76e20be41baa5a) (**[DrawMode](group__graphics_.md#ga1c8deb51ce3a6e135e17a8b792ae3d0e)** type) const <br>Sets the mode of the next draw calls. |
|void|[**setFillMode**](classffw_1_1_render_context.md#1abeaf4c2ab37bd07ab7fb589fdfce06ff) () const <br>Sets the mode of the next draw calls to be filled. |
|void|[**setStrokeMode**](classffw_1_1_render_context.md#1aae1778a3c4877ff5570b3c8045ba2e11) () const <br>Sets the mode of the next draw calls to be stroked. |
|void|[**setFillAndStrokeMode**](classffw_1_1_render_context.md#1a09506a3b69157d157eb666791895e465) () const <br>Sets the mode of the next draw calls to be filled and stroked. |
|void|[**setShapeAntiAlis**](classffw_1_1_render_context.md#1a4d2543134ead0160392d8c1c1151c1dd) (bool enabled) const <br>Sets whether to draw antialias for filling and stroke. |
|void|[**setStrokeSize**](classffw_1_1_render_context.md#1a2a346cf9fe4583948453ff925402edd7) (float width) const <br>Sets the thickness of the stroke. |
|void|[**setStrokeMiterLimit**](classffw_1_1_render_context.md#1a9186aa83f0287bdbee8dc2c962cd1c56) (float limit) const <br>Sets the miter limit of the stroke style. |
|void|[**setLineCap**](classffw_1_1_render_context.md#1ad20dc77cf701f6838a67caa390ff2c9a) (**[LineCap](group__graphics_.md#ga5c58b43b0202f2b4f86c635acaacc7ae)** type) const <br>Sets how the end of the line (cap) is drawn. |
|void|[**setLineJoin**](classffw_1_1_render_context.md#1adaca1cf54d8f535c879da46a97c1c82f) (**[LineCap](group__graphics_.md#ga5c58b43b0202f2b4f86c635acaacc7ae)** type) const <br>Sets how sharp path corners are drawn. |
|void|[**setScissor**](classffw_1_1_render_context.md#1a180cbb07b49086c885a763124669c0d1) (float posx, float posy, float width, float height) const <br>Sets the current scissor rectangle. |
|void|[**setIntersectScissor**](classffw_1_1_render_context.md#1a92ebe84a46e18f1e1a29d49bf9aae8f7) (float posx, float posy, float width, float height) const <br>Intersects current scissor rectangle with the specified rectangle. |
|void|[**resetScissor**](classffw_1_1_render_context.md#1aaede6e17bd70a7777adf1f8fd21eb62d) () const <br>Reset and disables scissoring. |
|void|[**beginPath**](classffw_1_1_render_context.md#1aa8bc36c43507d54bf8d90ad29b1e0bee) (float x, float y) const <br>Clears the current path and sub-paths and moves to position [x, y]. |
|void|[**drawLineTo**](classffw_1_1_render_context.md#1a85b5b7b39c8288b49a978d5c4a767c78) (float x, float y) const <br>Adds line segment from the last point in the path to the specified point. |
|void|[**drawBezierTo**](classffw_1_1_render_context.md#1a510155c8f9c2eeda3af299f95d909520) (float cp0x, float cp0y, float cp1x, float cp1y, float endx, float endy) const <br>Adds cubic bezier segment from last point in the path via two control points to the specified point. |
|void|[**drawQuadTo**](classffw_1_1_render_context.md#1a64eaa9fd40cdb949e4da219347e6c330) (float cpx, float cpy, float endx, float endy) const <br>Adds quadratic bezier segment from last point in the path via a control point to the specified point. |
|void|[**drawArcTo**](classffw_1_1_render_context.md#1af9f9832a6d5bade0e7856a39bedee520) (float startx, float starty, float endx, float endy, float radius) const <br>Adds an arc segment at the corner defined by the last path point, and two specified points. |
|void|[**closePath**](classffw_1_1_render_context.md#1a9e8c47cf75781ab5ee5feee0c4c2e651) () const <br>Closes current sub-path with a line segment. |
|void|[**fillPath**](classffw_1_1_render_context.md#1ad8250f8e6a5cb988826cf3c39ff30b07) () const <br>Fills the current path with current fill style. |
|void|[**strokePath**](classffw_1_1_render_context.md#1a24ce80814d51dd244327811ad8cd9773) () const <br>Fills the current path with current stroke style. |
|void|[**setPathWinding**](classffw_1_1_render_context.md#1a515fa0ad94c69661801c8f6639f2dee9) (**[DrawPathWinding](group__graphics_.md#gafa76fb6b139dd190d432bfc0740f6e3f)** winding) const <br>Sets the current sub-path winding. |
|void|[**saveDrawState**](classffw_1_1_render_context.md#1adf3af0fe90d02c51b09737eed57e8b5b) () const <br>Pushes and saves the current render state into a state stack. |
|void|[**restoreDrawState**](classffw_1_1_render_context.md#1a207006986eba7cf2f56ce30c1723fdf5) () const <br>Pops and restores current render state. |
|void|[**resetDrawState**](classffw_1_1_render_context.md#1aa069390f072a9db231bd738a7bb9f50d) () const <br>Resets current render state to default values. |
|void|[**resetTransform**](classffw_1_1_render_context.md#1aeb89e821460fdad5bac55db324f2fa9f) () const <br>Resets current transform to a identity matrix. |
|void|[**transformMove**](classffw_1_1_render_context.md#1a38884577b5d18846d59a4414ad5bc9cb) (float x, float y) const <br>Translates current coordinate system. |
|void|[**transformRotate**](classffw_1_1_render_context.md#1a3f0f3c5dc21822790958c0bf7bc4061b) (float degrees) const <br>Rotates current coordinate system in degrees. |
|void|[**transformSkewX**](classffw_1_1_render_context.md#1a98ad56bc36afb3cc7d796ef3f7324640) (float degrees) const <br>Skews the current coordinate system along X axis in degrees. |
|void|[**transformSkewY**](classffw_1_1_render_context.md#1a9f7314db09be246e85fff4194f206b75) (float degrees) const <br>Skews the current coordinate system along Y axis in degrees. |
|void|[**transformScale**](classffw_1_1_render_context.md#1aa317084ae178f1b6f8b685dc4a88586d) (float x, float y) const <br>Scales the current coordinate system. |
|void|[**transform**](classffw_1_1_render_context.md#1a3c9e1bfbd19e3a5bbede6d28dd15d947) (float a, float b, float c, float d, float e, float f) const <br>Translates current coordinate system. |
|void|[**getTransform**](classffw_1_1_render_context.md#1a554bc4a546be7755529ea905edad75b1) (float \* arr) const <br>Stores the transform matrix into the buffer provided. |
|void|[**getOpenGLTransform**](classffw_1_1_render_context.md#1a2cdcbf4b76f4f76fdc752b7f0675dd87) (float \* arr) const <br>Stores the transform matrix as OpenGL matrix into the buffer provided. |


## Public Attributes Documentation

### variable <a id="1aa5d6a095405936c3099100292b7a695c" href="#1aa5d6a095405936c3099100292b7a695c">position</a>

```cpp
int ffw::RenderContext::position;
```



### variable <a id="1a0ab38700f2f823e4f71a5de722126456" href="#1a0ab38700f2f823e4f71a5de722126456">rgbMixer</a>

```cpp
int ffw::RenderContext::rgbMixer;
```



### variable <a id="1a33c36ed9aacb6d5eba6f1edcbd344508" href="#1a33c36ed9aacb6d5eba6f1edcbd344508">color</a>

```cpp
int ffw::RenderContext::color;
```



### variable <a id="1a3606b93fd845c8754c79af5a374214fe" href="#1a3606b93fd845c8754c79af5a374214fe">proj</a>

```cpp
int ffw::RenderContext::proj;
```



### variable <a id="1a42491f65f6ee96509cd26139b636a7fc" href="#1a42491f65f6ee96509cd26139b636a7fc">uvpos</a>

```cpp
int ffw::RenderContext::uvpos;
```



### variable <a id="1a349be8c4a1cb3e9592906aa755ea0b67" href="#1a349be8c4a1cb3e9592906aa755ea0b67">tex</a>

```cpp
int ffw::RenderContext::tex;
```



### variable <a id="1a843ef524a272618624cddc6d5c3e3c5a" href="#1a843ef524a272618624cddc6d5c3e3c5a">offset</a>

```cpp
int ffw::RenderContext::offset;
```



### variable <a id="1a5ef7b6813536bdce194008c2cad0273d" href="#1a5ef7b6813536bdce194008c2cad0273d">view</a>

```cpp
int ffw::RenderContext::view;
```



## Public Functions Documentation

### function <a id="1add23aa7b649ed9d361a16f2b5d840800" href="#1add23aa7b649ed9d361a16f2b5d840800">RenderContext</a>

```cpp
ffw::RenderContext::RenderContext ()
```



### function <a id="1ac693a01e5da7e7b29be9cc53ef34d9f5" href="#1ac693a01e5da7e7b29be9cc53ef34d9f5">~RenderContext</a>

```cpp
virtual ffw::RenderContext::~RenderContext ()
```



### function <a id="1add007968b520cde93577b6b858f029a9" href="#1add007968b520cde93577b6b858f029a9">getGlextFunc</a>

```cpp
virtual void * ffw::RenderContext::getGlextFunc (
    const std::string & name
) const = 0
```

Retuns the address of the GL extension function. 

The pointer to the GL extension function may not be the same on different GL contexts! 

### function <a id="1a3e75b86b22be32db52bd370ad435fd34" href="#1a3e75b86b22be32db52bd370ad435fd34">isGlextExtSupported</a>

```cpp
virtual bool ffw::RenderContext::isGlextExtSupported (
    const std::string & name
) const = 0
```

Returns true if the GL extension is suported. 

Checks if an GLEXT extension is supported, for example "GL\_ARB\_debug\_output" 

### function <a id="1a3d4d4cd24fdeecae5ac99d4e5d8ee8ef" href="#1a3d4d4cd24fdeecae5ac99d4e5d8ee8ef">initDrawing</a>

```cpp
bool ffw::RenderContext::initDrawing ()
```

Initializes drawing functions. 


### function <a id="1a4313201325e2740731edfcd42b89bf95" href="#1a4313201325e2740731edfcd42b89bf95">beginFrame</a>

```cpp
void ffw::RenderContext::beginFrame () const
```

Begins the render frame and makes this context ready to be used with drawing function. 



**Note:**

This function must be called before every draw call 
```cpp
// class MyRenderWindow extends ffw::GLFWRenderWindow
void MyRenderWindow::render(){
    this->beginFrame();
    this->setDrawColor(ffw::rgb(0xFF0000));
    this->drawRectangle(50, 50, 200, 100);
    this->endFrame();
}
```

 




### function <a id="1add44f5f9ed7181b06c8b58b0f91c4d57" href="#1add44f5f9ed7181b06c8b58b0f91c4d57">endFrame</a>

```cpp
void ffw::RenderContext::endFrame () const
```

Ends the render frame. 



**Note:**

This function must be called at the end of each render 
```cpp
// class MyRenderWindow extends ffw::GLFWRenderWindow
void MyRenderWindow::render(){
    this->beginFrame();
    this->setDrawColor(ffw::rgb(0xFF0000));
    this->drawRectangle(50, 50, 200, 100);
    this->endFrame();
}
```

 




### function <a id="1ad4b9cd96927c73eb85e7f6f4986b4d71" href="#1ad4b9cd96927c73eb85e7f6f4986b4d71">moveTo</a>

```cpp
void ffw::RenderContext::moveTo (
    float x
    float y
) const
```



### function <a id="1aa135f5034cd376c7443ba28ddd5ceab1" href="#1aa135f5034cd376c7443ba28ddd5ceab1">setDrawColor</a>

```cpp
void ffw::RenderContext::setDrawColor (
    const ffw::Color & color
) const
```

Sets the color of the next draw commands (fill and stroke color) 


### function <a id="1ac6520c2a5245ce98f7952e6878c5af40" href="#1ac6520c2a5245ce98f7952e6878c5af40">setFillColor</a>

```cpp
void ffw::RenderContext::setFillColor (
    const ffw::Color & color
) const
```

Sets the color of the next draw commands (fill only) 


### function <a id="1a95a0587b0cdeaa896a47c3fbecf749c5" href="#1a95a0587b0cdeaa896a47c3fbecf749c5">setStrokeColor</a>

```cpp
void ffw::RenderContext::setStrokeColor (
    const ffw::Color & color
) const
```

Sets the color of the next draw commands (stroke only) 


### function <a id="1a7cbb9bf1186e9a5515092d4ea9cf2dbf" href="#1a7cbb9bf1186e9a5515092d4ea9cf2dbf">setFillPaint</a>

```cpp
void ffw::RenderContext::setFillPaint (
    const DrawPaint & paint
) const
```

Sets current fill style to a paint, which can be a one of the gradients. 


### function <a id="1a73f3cbe5519dd5d6aba4c5be2301a171" href="#1a73f3cbe5519dd5d6aba4c5be2301a171">setStrokePaint</a>

```cpp
void ffw::RenderContext::setStrokePaint (
    const DrawPaint & paint
) const
```

Sets current stroke style to a paint, which can be a one of the gradients. 


### function <a id="1a8874bea53615783f90fb59dda89bf273" href="#1a8874bea53615783f90fb59dda89bf273">createLinearGradient</a>

```cpp
DrawPaint ffw::RenderContext::createLinearGradient (
    float sx
    float sy
    float ex
    float ey
    const ffw::Color & icol
    const ffw::Color & ocol
) const
```

Creates and returns a linear gradient, a wrapper around nvgLinearGradient. 

Parameters (sx,sy)-(ex,ey) specify the start and end coordinates of the linear gradient, icol specifies the start color and ocol the end color. The gradient is transformed by the current transform when it is passed to **[setFillPaint()](classffw_1_1_render_context.md#1a7cbb9bf1186e9a5515092d4ea9cf2dbf)** or **[setStrokePaint()](classffw_1_1_render_context.md#1a73f3cbe5519dd5d6aba4c5be2301a171)**. 

### function <a id="1a3648c35243426cc22f2b8109d1699cfa" href="#1a3648c35243426cc22f2b8109d1699cfa">createBoxGradient</a>

```cpp
DrawPaint ffw::RenderContext::createBoxGradient (
    float x
    float y
    float w
    float h
    float r
    float f
    const ffw::Color & icol
    const ffw::Color & ocol
) const
```

Creates and returns a box gradient, a wrapper around nvgBoxGradient. 

Box gradient is a feathered rounded rectangle, it is useful for rendering drop shadows or highlights for boxes. Parameters (x,y) define the top-left corner of the rectangle, (w,h) define the size of the rectangle, r defines the corner radius, and f feather. Feather defines how blurry the border of the rectangle is. Parameter icol specifies the inner color and ocol the outer color of the gradient. The gradient is transformed by the current transform when it is passed to **[setFillPaint()](classffw_1_1_render_context.md#1a7cbb9bf1186e9a5515092d4ea9cf2dbf)** or **[setStrokePaint()](classffw_1_1_render_context.md#1a73f3cbe5519dd5d6aba4c5be2301a171)**. 

### function <a id="1ae67ef80fb5c0644612e1411e6ec01767" href="#1ae67ef80fb5c0644612e1411e6ec01767">createRadialGradient</a>

```cpp
DrawPaint ffw::RenderContext::createRadialGradient (
    float cx
    float cy
    float inr
    float outr
    const ffw::Color & icol
    const ffw::Color & ocol
) const
```

Creates and returns a radial gradient, a wrapper around nvgRadialGradient. 

Parameters (cx,cy) specify the center, inr and outr specify the inner and outer radius of the gradient, icol specifies the start color and ocol the end color. The gradient is transformed by the current transform when it is passed to **[setFillPaint()](classffw_1_1_render_context.md#1a7cbb9bf1186e9a5515092d4ea9cf2dbf)** or **[setStrokePaint()](classffw_1_1_render_context.md#1a73f3cbe5519dd5d6aba4c5be2301a171)**. 

### function <a id="1a92d639f1ddfae67e5f623d2bbc49541c" href="#1a92d639f1ddfae67e5f623d2bbc49541c">drawQuad</a>

```cpp
void ffw::RenderContext::drawQuad (
    float p0x
    float p0y
    float p1x
    float p1y
    float p2x
    float p2y
    float p3x
    float p3y
) const
```

Draws a quad composing of 4 points. 


### function <a id="1a4a7e2e5da4d6ea47ec630774990ad044" href="#1a4a7e2e5da4d6ea47ec630774990ad044">drawRectangle</a>

```cpp
void ffw::RenderContext::drawRectangle (
    float posx
    float posy
    float width
    float height
) const
```

Draws a simple rectangle. 


### function <a id="1a04c7ea0e82f9bc0f5c78d240bee3baab" href="#1a04c7ea0e82f9bc0f5c78d240bee3baab">drawRectangleRounded</a>

```cpp
void ffw::RenderContext::drawRectangleRounded (
    float posx
    float posy
    float width
    float height
    float corners
) const
```

Draws a rectangle with rounded corners. 


### function <a id="1a337746aef8e7915eb3bf81d2fbafae0e" href="#1a337746aef8e7915eb3bf81d2fbafae0e">drawRectangleRounded</a>

```cpp
void ffw::RenderContext::drawRectangleRounded (
    float posx
    float posy
    float width
    float height
    float leftTop
    float rightTop
    float bottomRight
    float bottomLeft
) const
```

Draws a rectangle with rounded corners. 


### function <a id="1a5f44dc8abcfdd0d100f7972073cafee7" href="#1a5f44dc8abcfdd0d100f7972073cafee7">drawTriangle</a>

```cpp
void ffw::RenderContext::drawTriangle (
    float p0x
    float p0y
    float p1x
    float p1y
    float p2x
    float p2y
) const
```

Draws a simple triangle. 


### function <a id="1ae533edaed5eb0bc3687060377107d68a" href="#1ae533edaed5eb0bc3687060377107d68a">drawTexture2D</a>

```cpp
void ffw::RenderContext::drawTexture2D (
    float posx
    float posy
    float width
    float height
    const ffw::Texture2D * texture
) const
```

Draws a 2D texture. 


### function <a id="1a6ba1ac7c307d93064f3f65e1d9fe3255" href="#1a6ba1ac7c307d93064f3f65e1d9fe3255">drawTexture2DMirror</a>

```cpp
void ffw::RenderContext::drawTexture2DMirror (
    float posx
    float posy
    float width
    float height
    const ffw::Texture2D * texture
    bool mirrorx
    bool mirrory
) const
```

Draws a 2D texture that can be mirrored. 


### function <a id="1a4a9abb637c006db624dd26933c1f1e6e" href="#1a4a9abb637c006db624dd26933c1f1e6e">drawTexture2DSub</a>

```cpp
void ffw::RenderContext::drawTexture2DSub (
    float posx
    float posy
    float width
    float height
    const ffw::Texture2D * texture
    int subx
    int suby
    int subw
    int subh
) const
```

Draws a rectangular subsection of the texture. 

The subsection coordinates are in pixels. 

### function <a id="1a4c130eec1494dfc88c534fab83b8a48b" href="#1a4c130eec1494dfc88c534fab83b8a48b">drawTexture2DSubMirror</a>

```cpp
void ffw::RenderContext::drawTexture2DSubMirror (
    float posx
    float posy
    float width
    float height
    const ffw::Texture2D * texture
    int subx
    int suby
    int subw
    int subh
    bool mirrorx
    bool mirrory
) const
```

Draws a mirrored rectangular subsection of the texture. 

The subsection coordinates are in pixels and the mirroring affects the result subsection. 

### function <a id="1ad2ff86d63992a805a40c3060e6626303" href="#1ad2ff86d63992a805a40c3060e6626303">drawArc</a>

```cpp
void ffw::RenderContext::drawArc (
    float posx
    float posy
    float innerradius
    float outerradius
    double startangle
    double endangle
) const
```

Draws an arc using starting and ending angle. 


### function <a id="1a9db201a8e6d8e8d351b248aed2f6cd2a" href="#1a9db201a8e6d8e8d351b248aed2f6cd2a">drawCircle</a>

```cpp
void ffw::RenderContext::drawCircle (
    float posx
    float posy
    float radius
) const
```

Draws a simple circle. 


### function <a id="1a0eb73e2b8292a0b9cdb2bb1f7a364231" href="#1a0eb73e2b8292a0b9cdb2bb1f7a364231">drawLine</a>

```cpp
void ffw::RenderContext::drawLine (
    float startx
    float starty
    float endx
    float edny
) const
```

Draws a line from point A to point B. 


### function <a id="1a9d4723eaf76ca55e9d4f6a18694524ac" href="#1a9d4723eaf76ca55e9d4f6a18694524ac">drawString</a>

```cpp
void ffw::RenderContext::drawString (
    float posx
    float posy
    const Font * font
    const std::string & str
    float lineHeight = 1.25f
) const
```

Draws a UTF-8 string. 


### function <a id="1a7dfb861d3f5f51339b7e1c6bee9131a8" href="#1a7dfb861d3f5f51339b7e1c6bee9131a8">drawString</a>

```cpp
void ffw::RenderContext::drawString (
    float posx
    float posy
    const Font * font
    const std::wstring & str
    float lineHeight = 1.25f
) const
```

Draws a multi-byte string. 


### function <a id="1a3a6d28b72d70902aa44b7ad925b77ac5" href="#1a3a6d28b72d70902aa44b7ad925b77ac5">drawString</a>

```cpp
void ffw::RenderContext::drawString (
    float posx
    float posy
    const Font * font
    const char * str
    size_t length
    float lineHeight = 1.25f
) const
```

Draws a UTF-8 string. 


### function <a id="1ac7a1f92543db28815bdea506effe805d" href="#1ac7a1f92543db28815bdea506effe805d">drawString</a>

```cpp
void ffw::RenderContext::drawString (
    float posx
    float posy
    const Font * font
    const wchar_t * str
    size_t length
    float lineHeight = 1.25f
) const
```

Draws a wide string. 


### function <a id="1aca5673fbacb63dfd251810fb89eedfa8" href="#1aca5673fbacb63dfd251810fb89eedfa8">drawStringBox</a>

```cpp
void ffw::RenderContext::drawStringBox (
    float posx
    float posy
    const Font * font
    const std::string & str
    float maxWidth
    float lineHeight = 1.25f
) const
```

Draws a UTF-8 string wrapped inside a box with specified width. 


### function <a id="1a3f0e2b15650e75e039c775e6ebaacedb" href="#1a3f0e2b15650e75e039c775e6ebaacedb">drawStringBox</a>

```cpp
void ffw::RenderContext::drawStringBox (
    float posx
    float posy
    const Font * font
    const std::wstring & str
    float maxWidth
    float lineHeight = 1.25f
) const
```

Draws a UTF-8 string wrapped inside a box with specified width. 


### function <a id="1a4ef6e9e82d98b598d1c3e63fa73b91d5" href="#1a4ef6e9e82d98b598d1c3e63fa73b91d5">drawStringBox</a>

```cpp
void ffw::RenderContext::drawStringBox (
    float posx
    float posy
    const Font * font
    const char * str
    size_t length
    float maxWidth
    float lineHeight = 1.25f
) const
```

Draws a multi-byte string wrapped inside a box with specified width. 


### function <a id="1a602972d20a0a6a2206b457e46bed784c" href="#1a602972d20a0a6a2206b457e46bed784c">drawStringBox</a>

```cpp
void ffw::RenderContext::drawStringBox (
    float posx
    float posy
    const Font * font
    const wchar_t * str
    size_t length
    float maxWidth
    float lineHeight = 1.25f
) const
```

Draws a multi-byte string wrapped inside a box with specified width. 


### function <a id="1ad0c6aea239ff9eff374fd14b54cbe4b7" href="#1ad0c6aea239ff9eff374fd14b54cbe4b7">drawBezier</a>

```cpp
void ffw::RenderContext::drawBezier (
    float startx
    float starty
    float cp0x
    float cp0y
    float cp1x
    float cp1y
    float endx
    float endy
) const
```

Draws a quadratic bezier curve. 


### function <a id="1a1bb042c5ee6119200a76e20be41baa5a" href="#1a1bb042c5ee6119200a76e20be41baa5a">setDrawMode</a>

```cpp
void ffw::RenderContext::setDrawMode (
    DrawMode type
) const
```

Sets the mode of the next draw calls. 


### function <a id="1abeaf4c2ab37bd07ab7fb589fdfce06ff" href="#1abeaf4c2ab37bd07ab7fb589fdfce06ff">setFillMode</a>

```cpp
void ffw::RenderContext::setFillMode () const
```

Sets the mode of the next draw calls to be filled. 


### function <a id="1aae1778a3c4877ff5570b3c8045ba2e11" href="#1aae1778a3c4877ff5570b3c8045ba2e11">setStrokeMode</a>

```cpp
void ffw::RenderContext::setStrokeMode () const
```

Sets the mode of the next draw calls to be stroked. 


### function <a id="1a09506a3b69157d157eb666791895e465" href="#1a09506a3b69157d157eb666791895e465">setFillAndStrokeMode</a>

```cpp
void ffw::RenderContext::setFillAndStrokeMode () const
```

Sets the mode of the next draw calls to be filled and stroked. 


### function <a id="1a4d2543134ead0160392d8c1c1151c1dd" href="#1a4d2543134ead0160392d8c1c1151c1dd">setShapeAntiAlis</a>

```cpp
void ffw::RenderContext::setShapeAntiAlis (
    bool enabled
) const
```

Sets whether to draw antialias for filling and stroke. 

It's enabled by default. 

**Note:**

Performs nvgShapeAntiAlias from nanovg 




### function <a id="1a2a346cf9fe4583948453ff925402edd7" href="#1a2a346cf9fe4583948453ff925402edd7">setStrokeSize</a>

```cpp
void ffw::RenderContext::setStrokeSize (
    float width
) const
```

Sets the thickness of the stroke. 


### function <a id="1a9186aa83f0287bdbee8dc2c962cd1c56" href="#1a9186aa83f0287bdbee8dc2c962cd1c56">setStrokeMiterLimit</a>

```cpp
void ffw::RenderContext::setStrokeMiterLimit (
    float limit
) const
```

Sets the miter limit of the stroke style. 

Miter limit controls when a sharp corner is beveled 

### function <a id="1ad20dc77cf701f6838a67caa390ff2c9a" href="#1ad20dc77cf701f6838a67caa390ff2c9a">setLineCap</a>

```cpp
void ffw::RenderContext::setLineCap (
    LineCap type
) const
```

Sets how the end of the line (cap) is drawn. 


### function <a id="1adaca1cf54d8f535c879da46a97c1c82f" href="#1adaca1cf54d8f535c879da46a97c1c82f">setLineJoin</a>

```cpp
void ffw::RenderContext::setLineJoin (
    LineCap type
) const
```

Sets how sharp path corners are drawn. 


### function <a id="1a180cbb07b49086c885a763124669c0d1" href="#1a180cbb07b49086c885a763124669c0d1">setScissor</a>

```cpp
void ffw::RenderContext::setScissor (
    float posx
    float posy
    float width
    float height
) const
```

Sets the current scissor rectangle. 

Scissoring allows you to clip the rendering into a rectangle. The scissor rectangle is transformed by the current transform. 

**Note:**

Acts same as nvgScissor from nanovg 




### function <a id="1a92ebe84a46e18f1e1a29d49bf9aae8f7" href="#1a92ebe84a46e18f1e1a29d49bf9aae8f7">setIntersectScissor</a>

```cpp
void ffw::RenderContext::setIntersectScissor (
    float posx
    float posy
    float width
    float height
) const
```

Intersects current scissor rectangle with the specified rectangle. 

The scissor rectangle is transformed by the current transform. In case the rotation of previous scissor rect differs from the current one, the intersection will be done between the specified rectangle and the previous scissor rectangle transformed in the current transform space. The resulting shape is always rectangle. 

**Note:**

Acts same as nvgIntersectScissor from nanovg 




### function <a id="1aaede6e17bd70a7777adf1f8fd21eb62d" href="#1aaede6e17bd70a7777adf1f8fd21eb62d">resetScissor</a>

```cpp
void ffw::RenderContext::resetScissor () const
```

Reset and disables scissoring. 



**Note:**

Acts same as nvgResetScissor from nanovg 




### function <a id="1aa8bc36c43507d54bf8d90ad29b1e0bee" href="#1aa8bc36c43507d54bf8d90ad29b1e0bee">beginPath</a>

```cpp
void ffw::RenderContext::beginPath (
    float x
    float y
) const
```

Clears the current path and sub-paths and moves to position [x, y]. 



**Note:**

Performs nvgBeginPath and nvgMoveTo from nanovg 




### function <a id="1a85b5b7b39c8288b49a978d5c4a767c78" href="#1a85b5b7b39c8288b49a978d5c4a767c78">drawLineTo</a>

```cpp
void ffw::RenderContext::drawLineTo (
    float x
    float y
) const
```

Adds line segment from the last point in the path to the specified point. 



**Note:**

Performs nvgLineTo from nanovg 




### function <a id="1a510155c8f9c2eeda3af299f95d909520" href="#1a510155c8f9c2eeda3af299f95d909520">drawBezierTo</a>

```cpp
void ffw::RenderContext::drawBezierTo (
    float cp0x
    float cp0y
    float cp1x
    float cp1y
    float endx
    float endy
) const
```

Adds cubic bezier segment from last point in the path via two control points to the specified point. 



**Note:**

Performs nvgBezierTo from nanovg 




### function <a id="1a64eaa9fd40cdb949e4da219347e6c330" href="#1a64eaa9fd40cdb949e4da219347e6c330">drawQuadTo</a>

```cpp
void ffw::RenderContext::drawQuadTo (
    float cpx
    float cpy
    float endx
    float endy
) const
```

Adds quadratic bezier segment from last point in the path via a control point to the specified point. 



**Note:**

Performs nvgQuadTo from nanovg 




### function <a id="1af9f9832a6d5bade0e7856a39bedee520" href="#1af9f9832a6d5bade0e7856a39bedee520">drawArcTo</a>

```cpp
void ffw::RenderContext::drawArcTo (
    float startx
    float starty
    float endx
    float endy
    float radius
) const
```

Adds an arc segment at the corner defined by the last path point, and two specified points. 



**Note:**

Performs nvgArcTo from nanovg 




### function <a id="1a9e8c47cf75781ab5ee5feee0c4c2e651" href="#1a9e8c47cf75781ab5ee5feee0c4c2e651">closePath</a>

```cpp
void ffw::RenderContext::closePath () const
```

Closes current sub-path with a line segment. 



**Note:**

Performs nvgClosePath 




### function <a id="1ad8250f8e6a5cb988826cf3c39ff30b07" href="#1ad8250f8e6a5cb988826cf3c39ff30b07">fillPath</a>

```cpp
void ffw::RenderContext::fillPath () const
```

Fills the current path with current fill style. 



**Note:**

Performs nvgFill from nanovg 




### function <a id="1a24ce80814d51dd244327811ad8cd9773" href="#1a24ce80814d51dd244327811ad8cd9773">strokePath</a>

```cpp
void ffw::RenderContext::strokePath () const
```

Fills the current path with current stroke style. 



**Note:**

Performs nvgStroke from nanovg 




### function <a id="1a515fa0ad94c69661801c8f6639f2dee9" href="#1a515fa0ad94c69661801c8f6639f2dee9">setPathWinding</a>

```cpp
void ffw::RenderContext::setPathWinding (
    DrawPathWinding winding
) const
```

Sets the current sub-path winding. 



**Note:**

Performs nvgPathWinding from nanovg 




### function <a id="1adf3af0fe90d02c51b09737eed57e8b5b" href="#1adf3af0fe90d02c51b09737eed57e8b5b">saveDrawState</a>

```cpp
void ffw::RenderContext::saveDrawState () const
```

Pushes and saves the current render state into a state stack. 



**Note:**

Performs nvgStroke from nanovg 




### function <a id="1a207006986eba7cf2f56ce30c1723fdf5" href="#1a207006986eba7cf2f56ce30c1723fdf5">restoreDrawState</a>

```cpp
void ffw::RenderContext::restoreDrawState () const
```

Pops and restores current render state. 



**Note:**

Performs nvgStroke from nanovg 




### function <a id="1aa069390f072a9db231bd738a7bb9f50d" href="#1aa069390f072a9db231bd738a7bb9f50d">resetDrawState</a>

```cpp
void ffw::RenderContext::resetDrawState () const
```

Resets current render state to default values. 



**Note:**

Performs nvgStroke from nanovg 




### function <a id="1aeb89e821460fdad5bac55db324f2fa9f" href="#1aeb89e821460fdad5bac55db324f2fa9f">resetTransform</a>

```cpp
void ffw::RenderContext::resetTransform () const
```

Resets current transform to a identity matrix. 



**Note:**

Performs nvgStroke from nanovg 




### function <a id="1a38884577b5d18846d59a4414ad5bc9cb" href="#1a38884577b5d18846d59a4414ad5bc9cb">transformMove</a>

```cpp
void ffw::RenderContext::transformMove (
    float x
    float y
) const
```

Translates current coordinate system. 



**Note:**

Performs nvgTranslate from nanovg 




### function <a id="1a3f0f3c5dc21822790958c0bf7bc4061b" href="#1a3f0f3c5dc21822790958c0bf7bc4061b">transformRotate</a>

```cpp
void ffw::RenderContext::transformRotate (
    float degrees
) const
```

Rotates current coordinate system in degrees. 



**Note:**

Performs nvgRotate from nanovg 




### function <a id="1a98ad56bc36afb3cc7d796ef3f7324640" href="#1a98ad56bc36afb3cc7d796ef3f7324640">transformSkewX</a>

```cpp
void ffw::RenderContext::transformSkewX (
    float degrees
) const
```

Skews the current coordinate system along X axis in degrees. 



**Note:**

Performs nvgSkewX from nanovg 




### function <a id="1a9f7314db09be246e85fff4194f206b75" href="#1a9f7314db09be246e85fff4194f206b75">transformSkewY</a>

```cpp
void ffw::RenderContext::transformSkewY (
    float degrees
) const
```

Skews the current coordinate system along Y axis in degrees. 



**Note:**

Performs nvgSkewY from nanovg 




### function <a id="1aa317084ae178f1b6f8b685dc4a88586d" href="#1aa317084ae178f1b6f8b685dc4a88586d">transformScale</a>

```cpp
void ffw::RenderContext::transformScale (
    float x
    float y
) const
```

Scales the current coordinate system. 



**Note:**

Performs nvgScale from nanovg 




### function <a id="1a3c9e1bfbd19e3a5bbede6d28dd15d947" href="#1a3c9e1bfbd19e3a5bbede6d28dd15d947">transform</a>

```cpp
void ffw::RenderContext::transform (
    float a
    float b
    float c
    float d
    float e
    float f
) const
```

Translates current coordinate system. 

The parameters are interpreted as matrix as follows First row: [a c e] Second row: [b d f] Third row: [0 0 1] 

**Note:**

Performs nvgTransform from nanovg 




### function <a id="1a554bc4a546be7755529ea905edad75b1" href="#1a554bc4a546be7755529ea905edad75b1">getTransform</a>

```cpp
void ffw::RenderContext::getTransform (
    float * arr
) const
```

Stores the transform matrix into the buffer provided. 

Stores the top part (a-f) of the current transformation matrix in to the specified buffer. There should be space for 6 floats in the return buffer for the values a-f. 
```cpp
// | a c e |
// | b d f |
// | 0 0 1 |
```

 

**Note:**

Performs nvgCurrentTransform from nanovg 




### function <a id="1a2cdcbf4b76f4f76fdc752b7f0675dd87" href="#1a2cdcbf4b76f4f76fdc752b7f0675dd87">getOpenGLTransform</a>

```cpp
void ffw::RenderContext::getOpenGLTransform (
    float * arr
) const
```

Stores the transform matrix as OpenGL matrix into the buffer provided. 

Similar to **[getTransform()](classffw_1_1_render_context.md#1a554bc4a546be7755529ea905edad75b1)** but this function returns OpenGL matrix that can be used within shaders. The function expects an array of 9 floats. 



----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/rendercontext.h`
