---
search:
    keywords: ['ffw::GLFWRenderWindow', 'windowCallback', 'getMonitors', 'getPrimaryMonitor', 'getMonitorModes', 'GLFWRenderWindow', '~GLFWRenderWindow', 'setPos', 'setSize', 'getPos', 'getSize', 'create', 'setWindowedMode', 'setWindowedMode', 'setFullscreen', 'destroy', 'shouldRender', 'renderFrame', 'poolEvents', 'waitForEvents', 'isInitialized', 'getGlextFunc', 'isGlextExtSupported', 'setSwapInterval', 'shouldClose', 'show', 'hide', 'iconify', 'restore', 'maximize', 'setSingleBufferMode', 'operator=', 'GLFWRenderWindow', 'GLFWRenderWindow', 'operator=', 'setPos', 'setSize', 'getPos', 'getSize', 'destroy', 'shouldRender', 'renderFrame', 'poolEvents', 'waitForEvents', 'isInitialized', 'shouldClose', 'show', 'hide', 'iconify', 'restore', 'maximize', 'setSingleBufferMode', 'RenderContext', '~RenderContext', 'getGlextFunc', 'isGlextExtSupported', 'initDrawing', 'beginFrame', 'endFrame', 'moveTo', 'setDrawColor', 'setFillColor', 'setStrokeColor', 'setFillPaint', 'setStrokePaint', 'createLinearGradient', 'createBoxGradient', 'createRadialGradient', 'drawQuad', 'drawRectangle', 'drawRectangleRounded', 'drawRectangleRounded', 'drawTriangle', 'drawTexture2D', 'drawTexture2DMirror', 'drawTexture2DSub', 'drawTexture2DSubMirror', 'drawArc', 'drawCircle', 'drawLine', 'drawString', 'drawString', 'drawString', 'drawString', 'drawStringBox', 'drawStringBox', 'drawStringBox', 'drawStringBox', 'drawBezier', 'setDrawMode', 'setFillMode', 'setStrokeMode', 'setFillAndStrokeMode', 'setShapeAntiAlis', 'setStrokeSize', 'setStrokeMiterLimit', 'setLineCap', 'setLineJoin', 'setScissor', 'setIntersectScissor', 'resetScissor', 'beginPath', 'drawLineTo', 'drawBezierTo', 'drawQuadTo', 'drawArcTo', 'closePath', 'fillPath', 'strokePath', 'setPathWinding', 'saveDrawState', 'restoreDrawState', 'resetDrawState', 'resetTransform', 'transformMove', 'transformRotate', 'transformSkewX', 'transformSkewY', 'transformScale', 'transform', 'getTransform', 'getOpenGLTransform', 'setup', 'render', 'close', 'textInputEvent', 'keyPressedEvent', 'mouseMovedEvent', 'mouseScrollEvent', 'mouseButtonEvent', 'windowResizedEvent', 'windowMovedEvent', 'windowCloseEvent', 'windowFocusEvent', 'filesDroppedEvent']
---

# class ffw::GLFWRenderWindow



Inherits the following classes: **[ffw::RenderWindow](classffw_1_1_render_window.md)**, **[ffw::RenderContext](classffw_1_1_render_context.md)**

## Friends

|Type|Name|
|-----|-----|
|friend struct|[**windowCallback**](classffw_1_1_g_l_f_w_render_window.md#1a32cd6707329e9a8ab3327e355b0b86cf)|


## Public Static Functions

|Type|Name|
|-----|-----|
|static std::vector< **[Monitor](structffw_1_1_monitor.md)** >|[**getMonitors**](classffw_1_1_g_l_f_w_render_window.md#1a9322f71069b0a8eca7a2ffbed380d747) () <br>Returns a vector of all physical monitors available. |
|static **[Monitor](structffw_1_1_monitor.md)**|[**getPrimaryMonitor**](classffw_1_1_g_l_f_w_render_window.md#1a194bb6f61cb37b82e5bc36044038ecca) () <br>Returns the primary monitor defined by the OS. |
|static std::vector< **[Monitor::Mode](structffw_1_1_monitor_1_1_mode.md)** >|[**getMonitorModes**](classffw_1_1_g_l_f_w_render_window.md#1a2e26de6f763e57f759dc37ef21ea7d43) (**[Monitor](structffw_1_1_monitor.md)** monitor) <br>Returns all possible modes for the given monitor. |


## Public Functions

|Type|Name|
|-----|-----|
||[**GLFWRenderWindow**](classffw_1_1_g_l_f_w_render_window.md#1ad7b858761fcfdcff4231e934aa953bbb) () |
|virtual |[**~GLFWRenderWindow**](classffw_1_1_g_l_f_w_render_window.md#1ae324e9a10f9443609e0d276d03e325dc) () |
|virtual void|[**setPos**](classffw_1_1_g_l_f_w_render_window.md#1aca827a5d7969a24e8d46bac1d4d4802a) (int posx, int posy) override <br>Sets the position of the window. |
|virtual void|[**setSize**](classffw_1_1_g_l_f_w_render_window.md#1a3d8f1ff605e89c2a57692a71d585d3f3) (int width, int height) override <br>Sets the size of the window. |
|virtual **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**getPos**](classffw_1_1_g_l_f_w_render_window.md#1a458bda82627135f13216484261f51385) () override const |
|virtual **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)**|[**getSize**](classffw_1_1_g_l_f_w_render_window.md#1a0a1fc0217f145e7908f85f31b6556114) () override const |
|bool|[**create**](classffw_1_1_g_l_f_w_render_window.md#1a762e6bc42f85bd389534b83785aed85f) (const **[GLFWRenderWindowArgs](structffw_1_1_g_l_f_w_render_window_args.md)** & args, **[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** \* other, **[Monitor](structffw_1_1_monitor.md)** \* monitor = NULL) <br>Creates the window. |
|void|[**setWindowedMode**](classffw_1_1_g_l_f_w_render_window.md#1ad9cef4fd74e3f331b7da512ff6e70e0d) () <br>Sets the window into windowed mode, if the window was in maximized mode. |
|void|[**setWindowedMode**](classffw_1_1_g_l_f_w_render_window.md#1ae4e3d3c032aac8c77584d218a4144b78) (int posx, int posy, int width, int height) <br>Sets the window into windowed mode with specific size and position. |
|void|[**setFullscreen**](classffw_1_1_g_l_f_w_render_window.md#1a5a59d5ac1c38901701cf15b673535794) (const **[Monitor](structffw_1_1_monitor.md)** \* monitor) <br>Sets the window into fullscreen mode. |
|virtual void|[**destroy**](classffw_1_1_g_l_f_w_render_window.md#1a9878a9b746d9ef330b37487b7bdbcbaa) () override <br>Destroys the window and it's context. |
|virtual bool|[**shouldRender**](classffw_1_1_g_l_f_w_render_window.md#1a5f3698cf9788b2f958d74491cd6e7d84) () override const <br>Returns true if the window is not closed. |
|virtual void|[**renderFrame**](classffw_1_1_g_l_f_w_render_window.md#1aab017fb39fee155108bd31340b3c291d) () override <br>Renders a frame. |
|virtual void|[**poolEvents**](classffw_1_1_g_l_f_w_render_window.md#1ae25f76f373e20a7c1b8212ed579674a7) () override <br>Pools all user input events, if any. |
|virtual void|[**waitForEvents**](classffw_1_1_g_l_f_w_render_window.md#1ab5a5f146c818f7860e9efcdc930b0977) () override <br>Pools all user input events and waits if there is none. |
|virtual bool|[**isInitialized**](classffw_1_1_g_l_f_w_render_window.md#1ab6c7e6dd7db988ac6b0e882a9bdfd0d5) () override const <br>Returns true if the window is initialized. |
|virtual void \*|[**getGlextFunc**](classffw_1_1_g_l_f_w_render_window.md#1acb0a1fa3a63717bf115c4054af0bc554) (const std::string & name) override const <br>Retuns the address of the GL extension function. |
|virtual bool|[**isGlextExtSupported**](classffw_1_1_g_l_f_w_render_window.md#1afbb6742cf5c16894a2dfb37a290a036a) (const std::string & name) override const <br>Returns true if the GL extension is suported. |
|void|[**setSwapInterval**](classffw_1_1_g_l_f_w_render_window.md#1a1135d7e9261e9b484e03ea10edddb110) (int interval) |
|virtual void|[**shouldClose**](classffw_1_1_g_l_f_w_render_window.md#1a8f82af7870873ad5926f7ed401622aee) (bool close) override <br>Set whether the window should close or stay alive. |
|virtual void|[**show**](classffw_1_1_g_l_f_w_render_window.md#1a0e98b25541b758258360aa23a7d15170) () override <br>Shows the window if the window has been hidden. |
|virtual void|[**hide**](classffw_1_1_g_l_f_w_render_window.md#1a5a491781ee464bb3728b6d61aae65c1b) () override <br>Hides the window if the window is visible. |
|virtual void|[**iconify**](classffw_1_1_g_l_f_w_render_window.md#1ae12d6561764be7e94708fd614c2d1cbd) () override <br>Minimizes the window into the task bar. |
|virtual void|[**restore**](classffw_1_1_g_l_f_w_render_window.md#1a19a534b8551ee1e7620d0d166267faa9) () override <br>Restores minimized window into a visible window. |
|virtual void|[**maximize**](classffw_1_1_g_l_f_w_render_window.md#1ab0e4d8b3e04eb3a192a3d78b3a265567) () override <br>Maximizes the window in order to utilize whole screen. |
|virtual void|[**setSingleBufferMode**](classffw_1_1_g_l_f_w_render_window.md#1ac1760a20cdd503e090568cbb0e865b21) (bool enabled) override <br>Sets whether the window should operate using two buffets (back and front) or only in one. |
|**[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** &|[**operator=**](classffw_1_1_g_l_f_w_render_window.md#1a7e4c5c6a7178bac96d24867ebf339701) (const **[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** &) = delete |
||[**GLFWRenderWindow**](classffw_1_1_g_l_f_w_render_window.md#1aa76cc1468168f5c9b0f5df80b96b53e5) (const **[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** &) = delete |
||[**GLFWRenderWindow**](classffw_1_1_g_l_f_w_render_window.md#1a3ddd9b8e36d3d696b55cd42e4467bc88) (**[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** && other) |
|**[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** &|[**operator=**](classffw_1_1_g_l_f_w_render_window.md#1a4fd98edb7a0aa7683147388b6ca6afc0) (**[GLFWRenderWindow](classffw_1_1_g_l_f_w_render_window.md)** && other) |


#### Public Functions inherited from [ffw::RenderContext](classffw_1_1_render_context.md)

|Type|Name|
|-----|-----|
||[**RenderContext**](classffw_1_1_render_context.md#1add23aa7b649ed9d361a16f2b5d840800) () |
|virtual |[**~RenderContext**](classffw_1_1_render_context.md#1ac693a01e5da7e7b29be9cc53ef34d9f5) () |
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


## Protected Functions

|Type|Name|
|-----|-----|
|virtual bool|[**setup**](classffw_1_1_g_l_f_w_render_window.md#1a1e282c45acb7d8ce3d1d0c2441f0e2f1) () = 0<br>Called only once when the window is set up. |
|virtual void|[**render**](classffw_1_1_g_l_f_w_render_window.md#1a3e6badb607370da3adc99b42f88314ff) () = 0<br>Called every time the frame is being rendered. |
|virtual void|[**close**](classffw_1_1_g_l_f_w_render_window.md#1a05b0b6ad5e81f9f8f8ecaa401c72e7f5) () = 0<br>Called only once when the window is being destroyed. |
|virtual void|[**textInputEvent**](classffw_1_1_g_l_f_w_render_window.md#1a7cc7bea67d33aa202bb66ae04e3daaa4) (unsigned int c) <br>Called when the user presses a key to type text (unicode only) |
|virtual void|[**keyPressedEvent**](classffw_1_1_g_l_f_w_render_window.md#1ae96a6ee1b02e34ce56b72abf35727118) (**[ffw::Key](namespaceffw.md#1a4194e8f0528edf866a3fdfbc1ecba254)** key, **[ffw::Mode](namespaceffw.md#1a7c343296bbf3216a2b78bd49ae015373)** mode) <br>Called when the user presses a physical key. |
|virtual void|[**mouseMovedEvent**](classffw_1_1_g_l_f_w_render_window.md#1a57ce8aa5d43ba52e705b2cc303bfe844) (int mousex, int mousey) <br>Called when the user moves a mouse. |
|virtual void|[**mouseScrollEvent**](classffw_1_1_g_l_f_w_render_window.md#1a3bc81f8aca844cc6f5c48940e6618b61) (int scroll) <br>Called when the user scrolls down or up. |
|virtual void|[**mouseButtonEvent**](classffw_1_1_g_l_f_w_render_window.md#1ace21446d60282d4f29be403f4654d98c) (**[ffw::MouseButton](namespaceffw.md#1a27b70bbb6a1b35235c34a999d7420b25)** button, **[ffw::Mode](namespaceffw.md#1a7c343296bbf3216a2b78bd49ae015373)** mode) <br>Called when the user presses a mouse button. |
|virtual void|[**windowResizedEvent**](classffw_1_1_g_l_f_w_render_window.md#1a23874ff965329d5b1e5c21095255bb47) (int width, int height) <br>Called when the window is resized to a new size. |
|virtual void|[**windowMovedEvent**](classffw_1_1_g_l_f_w_render_window.md#1ab4c060cb7a1593f96ff4daaafe08d332) (int posx, int posy) <br>Called when the window is moved to a new position. |
|virtual void|[**windowCloseEvent**](classffw_1_1_g_l_f_w_render_window.md#1aae2eaed68878d28c04055b6080ffdbcc) () <br>Called when the user presses the [X] button on the window. |
|virtual void|[**windowFocusEvent**](classffw_1_1_g_l_f_w_render_window.md#1a9109d479866278051350c973a9535e2d) (bool focus) <br>Called when the window will gain or looses focus. |
|virtual void|[**filesDroppedEvent**](classffw_1_1_g_l_f_w_render_window.md#1a73e68c1f7acca1e43e2f1a1461bee355) (std::vector< std::string > filelist) <br>Called when the user drags and drops one or multiple files. |


## Additional Inherited Members

#### Public Attributes inherited from [ffw::RenderContext](classffw_1_1_render_context.md)

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


## Friends Documentation

### friend <a id="1a32cd6707329e9a8ab3327e355b0b86cf" href="#1a32cd6707329e9a8ab3327e355b0b86cf">windowCallback</a>

```cpp
friend struct windowCallback;
```



## Public Static Functions Documentation

### function <a id="1a9322f71069b0a8eca7a2ffbed380d747" href="#1a9322f71069b0a8eca7a2ffbed380d747">getMonitors</a>

```cpp
static std::vector< Monitor > ffw::GLFWRenderWindow::getMonitors ()
```

Returns a vector of all physical monitors available. 


### function <a id="1a194bb6f61cb37b82e5bc36044038ecca" href="#1a194bb6f61cb37b82e5bc36044038ecca">getPrimaryMonitor</a>

```cpp
static Monitor ffw::GLFWRenderWindow::getPrimaryMonitor ()
```

Returns the primary monitor defined by the OS. 


### function <a id="1a2e26de6f763e57f759dc37ef21ea7d43" href="#1a2e26de6f763e57f759dc37ef21ea7d43">getMonitorModes</a>

```cpp
static std::vector< Monitor::Mode > ffw::GLFWRenderWindow::getMonitorModes (
    Monitor monitor
)
```

Returns all possible modes for the given monitor. 


## Public Functions Documentation

### function <a id="1ad7b858761fcfdcff4231e934aa953bbb" href="#1ad7b858761fcfdcff4231e934aa953bbb">GLFWRenderWindow</a>

```cpp
ffw::GLFWRenderWindow::GLFWRenderWindow ()
```



### function <a id="1ae324e9a10f9443609e0d276d03e325dc" href="#1ae324e9a10f9443609e0d276d03e325dc">~GLFWRenderWindow</a>

```cpp
virtual ffw::GLFWRenderWindow::~GLFWRenderWindow ()
```



### function <a id="1aca827a5d7969a24e8d46bac1d4d4802a" href="#1aca827a5d7969a24e8d46bac1d4d4802a">setPos</a>

```cpp
virtual void ffw::GLFWRenderWindow::setPos (
    int posx
    int posy
)
```

Overrides **[RenderWindow::setPos](classffw_1_1_render_window.md#1a555c078b31cabb0093fe2775949617a1)**
Sets the position of the window. 


### function <a id="1a3d8f1ff605e89c2a57692a71d585d3f3" href="#1a3d8f1ff605e89c2a57692a71d585d3f3">setSize</a>

```cpp
virtual void ffw::GLFWRenderWindow::setSize (
    int width
    int height
)
```

Overrides **[RenderWindow::setSize](classffw_1_1_render_window.md#1a5e8e8ff90cc10668fd094f014a1d4443)**
Sets the size of the window. 


### function <a id="1a458bda82627135f13216484261f51385" href="#1a458bda82627135f13216484261f51385">getPos</a>

```cpp
virtual ffw::Vec2i ffw::GLFWRenderWindow::getPos () const
```

Overrides **[RenderWindow::getPos](classffw_1_1_render_window.md#1aa315da9361cd782570780a3cc2c774af)**


### function <a id="1a0a1fc0217f145e7908f85f31b6556114" href="#1a0a1fc0217f145e7908f85f31b6556114">getSize</a>

```cpp
virtual ffw::Vec2i ffw::GLFWRenderWindow::getSize () const
```

Overrides **[RenderWindow::getSize](classffw_1_1_render_window.md#1a595588b6d95c29495cd0928e8af747ca)**


### function <a id="1a762e6bc42f85bd389534b83785aed85f" href="#1a762e6bc42f85bd389534b83785aed85f">create</a>

```cpp
bool ffw::GLFWRenderWindow::create (
    const GLFWRenderWindowArgs & args
    GLFWRenderWindow * other
    Monitor * monitor = NULL
)
```

Creates the window. 



**Parameters:**


* _args_ Arguments and hints for the window 
* _other_ If another window is provided, their OpenGL context will be shared, otherwise NULL 
* _monitor_ If a monitor is provided, the window will be fullscreen 



**Returns:**

Will return false if:
* The window `has` already been created `` 
* The target size (width or height) defined by args is zero or less
* The GLFW failed due to missing OpenGL or there is no display to output to (running in terminal only)
* The _OS_ OpenGL version _is_ less than 1.1
* The _target_ _size_ is not supported by the **monitor** ****(only when fullscreen) 






### function <a id="1ad9cef4fd74e3f331b7da512ff6e70e0d" href="#1ad9cef4fd74e3f331b7da512ff6e70e0d">setWindowedMode</a>

```cpp
void ffw::GLFWRenderWindow::setWindowedMode ()
```

Sets the window into windowed mode, if the window was in maximized mode. 


### function <a id="1ae4e3d3c032aac8c77584d218a4144b78" href="#1ae4e3d3c032aac8c77584d218a4144b78">setWindowedMode</a>

```cpp
void ffw::GLFWRenderWindow::setWindowedMode (
    int posx
    int posy
    int width
    int height
)
```

Sets the window into windowed mode with specific size and position. 


### function <a id="1a5a59d5ac1c38901701cf15b673535794" href="#1a5a59d5ac1c38901701cf15b673535794">setFullscreen</a>

```cpp
void ffw::GLFWRenderWindow::setFullscreen (
    const Monitor * monitor
)
```

Sets the window into fullscreen mode. 

You will need to change the size of the window with **[setSize()](classffw_1_1_g_l_f_w_render_window.md#1a3d8f1ff605e89c2a57692a71d585d3f3)** 

### function <a id="1a9878a9b746d9ef330b37487b7bdbcbaa" href="#1a9878a9b746d9ef330b37487b7bdbcbaa">destroy</a>

```cpp
virtual void ffw::GLFWRenderWindow::destroy ()
```

Overrides **[RenderWindow::destroy](classffw_1_1_render_window.md#1aa2da20ab3804b6087420b48c8eb18736)**
Destroys the window and it's context. 


### function <a id="1a5f3698cf9788b2f958d74491cd6e7d84" href="#1a5f3698cf9788b2f958d74491cd6e7d84">shouldRender</a>

```cpp
virtual bool ffw::GLFWRenderWindow::shouldRender () const
```

Overrides **[RenderWindow::shouldRender](classffw_1_1_render_window.md#1a1ebad2106b42ec4f771a69bc3a3fb082)**
Returns true if the window is not closed. 

When **[shouldClose()](classffw_1_1_g_l_f_w_render_window.md#1a8f82af7870873ad5926f7ed401622aee)** is called with a 'true' boolean value, this function will then return false 

### function <a id="1aab017fb39fee155108bd31340b3c291d" href="#1aab017fb39fee155108bd31340b3c291d">renderFrame</a>

```cpp
virtual void ffw::GLFWRenderWindow::renderFrame ()
```

Overrides **[RenderWindow::renderFrame](classffw_1_1_render_window.md#1adca1e202f3dc76ab2423090551676a3c)**
Renders a frame. 


### function <a id="1ae25f76f373e20a7c1b8212ed579674a7" href="#1ae25f76f373e20a7c1b8212ed579674a7">poolEvents</a>

```cpp
virtual void ffw::GLFWRenderWindow::poolEvents ()
```

Overrides **[RenderWindow::poolEvents](classffw_1_1_render_window.md#1ab804b9ad96a1c7c1b21d90860f01e01c)**
Pools all user input events, if any. 

This is blocking function that will return whenever there are any events in the queue. If you wish to wait for the user first, see **[waitForEvents()](classffw_1_1_g_l_f_w_render_window.md#1ab5a5f146c818f7860e9efcdc930b0977)** 

### function <a id="1ab5a5f146c818f7860e9efcdc930b0977" href="#1ab5a5f146c818f7860e9efcdc930b0977">waitForEvents</a>

```cpp
virtual void ffw::GLFWRenderWindow::waitForEvents ()
```

Overrides **[RenderWindow::waitForEvents](classffw_1_1_render_window.md#1ae421509ca35010cbd7db71f8c11946ca)**
Pools all user input events and waits if there is none. 

This is blocking function that will not return unless there is at least one user event. If you wish to have continuous rendering, even if there are no user events, use **[poolEvents()](classffw_1_1_g_l_f_w_render_window.md#1ae25f76f373e20a7c1b8212ed579674a7)** 

### function <a id="1ab6c7e6dd7db988ac6b0e882a9bdfd0d5" href="#1ab6c7e6dd7db988ac6b0e882a9bdfd0d5">isInitialized</a>

```cpp
virtual bool ffw::GLFWRenderWindow::isInitialized () const
```

Overrides **[RenderWindow::isInitialized](classffw_1_1_render_window.md#1a72fc237b45f777dd7f4dbeb014b0b616)**
Returns true if the window is initialized. 


### function <a id="1acb0a1fa3a63717bf115c4054af0bc554" href="#1acb0a1fa3a63717bf115c4054af0bc554">getGlextFunc</a>

```cpp
virtual void * ffw::GLFWRenderWindow::getGlextFunc (
    const std::string & name
) const
```

Overrides **[RenderContext::getGlextFunc](classffw_1_1_render_context.md#1add007968b520cde93577b6b858f029a9)**
Retuns the address of the GL extension function. 

The pointer to the GL extension function may not be the same on different GL contexts! 

### function <a id="1afbb6742cf5c16894a2dfb37a290a036a" href="#1afbb6742cf5c16894a2dfb37a290a036a">isGlextExtSupported</a>

```cpp
virtual bool ffw::GLFWRenderWindow::isGlextExtSupported (
    const std::string & name
) const
```

Overrides **[RenderContext::isGlextExtSupported](classffw_1_1_render_context.md#1a3e75b86b22be32db52bd370ad435fd34)**
Returns true if the GL extension is suported. 

Checks if an GLEXT extension is supported, for example "GL\_ARB\_debug\_output" 

### function <a id="1a1135d7e9261e9b484e03ea10edddb110" href="#1a1135d7e9261e9b484e03ea10edddb110">setSwapInterval</a>

```cpp
void ffw::GLFWRenderWindow::setSwapInterval (
    int interval
)
```



### function <a id="1a8f82af7870873ad5926f7ed401622aee" href="#1a8f82af7870873ad5926f7ed401622aee">shouldClose</a>

```cpp
virtual void ffw::GLFWRenderWindow::shouldClose (
    bool close
)
```

Overrides **[RenderWindow::shouldClose](classffw_1_1_render_window.md#1a8aa07a645357b06812e23fa06bee8076)**
Set whether the window should close or stay alive. 


### function <a id="1a0e98b25541b758258360aa23a7d15170" href="#1a0e98b25541b758258360aa23a7d15170">show</a>

```cpp
virtual void ffw::GLFWRenderWindow::show ()
```

Overrides **[RenderWindow::show](classffw_1_1_render_window.md#1ab8eb2be9cfb3aefc8dffdb1228482d6a)**
Shows the window if the window has been hidden. 


### function <a id="1a5a491781ee464bb3728b6d61aae65c1b" href="#1a5a491781ee464bb3728b6d61aae65c1b">hide</a>

```cpp
virtual void ffw::GLFWRenderWindow::hide ()
```

Overrides **[RenderWindow::hide](classffw_1_1_render_window.md#1ae2a8b392e2537be361ee7c1eea547e31)**
Hides the window if the window is visible. 


### function <a id="1ae12d6561764be7e94708fd614c2d1cbd" href="#1ae12d6561764be7e94708fd614c2d1cbd">iconify</a>

```cpp
virtual void ffw::GLFWRenderWindow::iconify ()
```

Overrides **[RenderWindow::iconify](classffw_1_1_render_window.md#1a7544a3014cddfcce5a51b44a82efaa73)**
Minimizes the window into the task bar. 


### function <a id="1a19a534b8551ee1e7620d0d166267faa9" href="#1a19a534b8551ee1e7620d0d166267faa9">restore</a>

```cpp
virtual void ffw::GLFWRenderWindow::restore ()
```

Overrides **[RenderWindow::restore](classffw_1_1_render_window.md#1a5d09d206980971cf8640360ac331730d)**
Restores minimized window into a visible window. 


### function <a id="1ab0e4d8b3e04eb3a192a3d78b3a265567" href="#1ab0e4d8b3e04eb3a192a3d78b3a265567">maximize</a>

```cpp
virtual void ffw::GLFWRenderWindow::maximize ()
```

Overrides **[RenderWindow::maximize](classffw_1_1_render_window.md#1aed21fdd74781cf3cc44fd11c7da0c17a)**
Maximizes the window in order to utilize whole screen. 

This is not the same as full screen mode! 

### function <a id="1ac1760a20cdd503e090568cbb0e865b21" href="#1ac1760a20cdd503e090568cbb0e865b21">setSingleBufferMode</a>

```cpp
virtual void ffw::GLFWRenderWindow::setSingleBufferMode (
    bool enabled
)
```

Overrides **[RenderWindow::setSingleBufferMode](classffw_1_1_render_window.md#1aaf2199e736ae4006c75d1564d8dcb402)**
Sets whether the window should operate using two buffets (back and front) or only in one. 


### function <a id="1a7e4c5c6a7178bac96d24867ebf339701" href="#1a7e4c5c6a7178bac96d24867ebf339701">operator=</a>

```cpp
GLFWRenderWindow & ffw::GLFWRenderWindow::operator= (
    const GLFWRenderWindow & 
) = delete
```



### function <a id="1aa76cc1468168f5c9b0f5df80b96b53e5" href="#1aa76cc1468168f5c9b0f5df80b96b53e5">GLFWRenderWindow</a>

```cpp
ffw::GLFWRenderWindow::GLFWRenderWindow (
    const GLFWRenderWindow & 
) = delete
```



### function <a id="1a3ddd9b8e36d3d696b55cd42e4467bc88" href="#1a3ddd9b8e36d3d696b55cd42e4467bc88">GLFWRenderWindow</a>

```cpp
ffw::GLFWRenderWindow::GLFWRenderWindow (
    GLFWRenderWindow && other
)
```



### function <a id="1a4fd98edb7a0aa7683147388b6ca6afc0" href="#1a4fd98edb7a0aa7683147388b6ca6afc0">operator=</a>

```cpp
GLFWRenderWindow & ffw::GLFWRenderWindow::operator= (
    GLFWRenderWindow && other
)
```



## Protected Functions Documentation

### function <a id="1a1e282c45acb7d8ce3d1d0c2441f0e2f1" href="#1a1e282c45acb7d8ce3d1d0c2441f0e2f1">setup</a>

```cpp
virtual bool ffw::GLFWRenderWindow::setup () = 0
```

Called only once when the window is set up. 


### function <a id="1a3e6badb607370da3adc99b42f88314ff" href="#1a3e6badb607370da3adc99b42f88314ff">render</a>

```cpp
virtual void ffw::GLFWRenderWindow::render () = 0
```

Called every time the frame is being rendered. 


### function <a id="1a05b0b6ad5e81f9f8f8ecaa401c72e7f5" href="#1a05b0b6ad5e81f9f8f8ecaa401c72e7f5">close</a>

```cpp
virtual void ffw::GLFWRenderWindow::close () = 0
```

Called only once when the window is being destroyed. 


### function <a id="1a7cc7bea67d33aa202bb66ae04e3daaa4" href="#1a7cc7bea67d33aa202bb66ae04e3daaa4">textInputEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::textInputEvent (
    unsigned int c
)
```

Called when the user presses a key to type text (unicode only) 


### function <a id="1ae96a6ee1b02e34ce56b72abf35727118" href="#1ae96a6ee1b02e34ce56b72abf35727118">keyPressedEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::keyPressedEvent (
    ffw::Key key
    ffw::Mode mode
)
```

Called when the user presses a physical key. 


### function <a id="1a57ce8aa5d43ba52e705b2cc303bfe844" href="#1a57ce8aa5d43ba52e705b2cc303bfe844">mouseMovedEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::mouseMovedEvent (
    int mousex
    int mousey
)
```

Called when the user moves a mouse. 


### function <a id="1a3bc81f8aca844cc6f5c48940e6618b61" href="#1a3bc81f8aca844cc6f5c48940e6618b61">mouseScrollEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::mouseScrollEvent (
    int scroll
)
```

Called when the user scrolls down or up. 


### function <a id="1ace21446d60282d4f29be403f4654d98c" href="#1ace21446d60282d4f29be403f4654d98c">mouseButtonEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::mouseButtonEvent (
    ffw::MouseButton button
    ffw::Mode mode
)
```

Called when the user presses a mouse button. 


### function <a id="1a23874ff965329d5b1e5c21095255bb47" href="#1a23874ff965329d5b1e5c21095255bb47">windowResizedEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::windowResizedEvent (
    int width
    int height
)
```

Called when the window is resized to a new size. 


### function <a id="1ab4c060cb7a1593f96ff4daaafe08d332" href="#1ab4c060cb7a1593f96ff4daaafe08d332">windowMovedEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::windowMovedEvent (
    int posx
    int posy
)
```

Called when the window is moved to a new position. 


### function <a id="1aae2eaed68878d28c04055b6080ffdbcc" href="#1aae2eaed68878d28c04055b6080ffdbcc">windowCloseEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::windowCloseEvent ()
```

Called when the user presses the [X] button on the window. 


### function <a id="1a9109d479866278051350c973a9535e2d" href="#1a9109d479866278051350c973a9535e2d">windowFocusEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::windowFocusEvent (
    bool focus
)
```

Called when the window will gain or looses focus. 


### function <a id="1a73e68c1f7acca1e43e2f1a1461bee355" href="#1a73e68c1f7acca1e43e2f1a1461bee355">filesDroppedEvent</a>

```cpp
virtual void ffw::GLFWRenderWindow::filesDroppedEvent (
    std::vector< std::string > filelist
)
```

Called when the user drags and drops one or multiple files. 



**Note:**

UTF-8 enabled 






----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/glfwrenderwindow.h`
