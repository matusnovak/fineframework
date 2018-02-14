RenderContext
===================================

Basic render context which can be used to draw shapes using nanovg on the screen. 

**Implemented by:** [ffw::GLFWRenderWindow](ffw_GLFWRenderWindow.html), 

The documentation for this class was generated from: `include/ffw/graphics/rendercontext.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  int | [position](#281e33a7) |
|  int | [rgbMixer](#05f2da6c) |
|  int | [color](#e0cf940a) |
|  int | [proj](#d02ef9f1) |
|  int | [uvpos](#f1e0780f) |
|  int | [tex](#c3cdd4a1) |
|  int | [offset](#e6f20158) |
|  int | [view](#e5f21541) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [RenderContext](#b667aae5) ()  |
|  virtual  | [~RenderContext](#b635b879) ()  |
|  virtual void * | [getGlextFunc](#16d7b686) (const std::string & _name_) const = 0  _Retuns the address of the GL extension function._ |
|  virtual bool | [isGlextExtSupported](#66742b2f) (const std::string & _name_) const = 0  _Returns true if the GL extension is suported._ |
|  bool | [initDrawing](#9d9e5d7c) ()  _Initializes drawing functions._ |
|  void | [beginFrame](#5e83973b) () const  _Begins the render frame and makes this context ready to be used with drawing function._ |
|  void | [endFrame](#f453fc43) () const  _Ends the render frame._ |
|  void | [setDrawColor](#1bbcfe20) (const [ffw::Color](ffw_Color.html) & _color_) const  _Sets the color of the next draw commands (fill and stroke color)_ |
|  void | [setFillColor](#adbaf2e4) (const [ffw::Color](ffw_Color.html) & _color_) const  _Sets the color of the next draw commands (fill only)_ |
|  void | [setStrokeColor](#25e8423e) (const [ffw::Color](ffw_Color.html) & _color_) const  _Sets the color of the next draw commands (stroke only)_ |
|  void | [setFillPaint](#89d56de8) (const [DrawPaint](ffw_DrawPaint.html) & _paint_) const  _Sets current fill style to a paint, which can be a one of the gradients._ |
|  void | [setStrokePaint](#265c8cf3) (const [DrawPaint](ffw_DrawPaint.html) & _paint_) const  _Sets current stroke style to a paint, which can be a one of the gradients._ |
|  [DrawPaint](ffw_DrawPaint.html) | [createLinearGradient](#4ff1c181) (float _sx_, float _sy_, float _ex_, float _ey_, const [ffw::Color](ffw_Color.html) & _icol_, const [ffw::Color](ffw_Color.html) & _ocol_) const  _Creates and returns a linear gradient, a wrapper around nvgLinearGradient._ |
|  [DrawPaint](ffw_DrawPaint.html) | [createBoxGradient](#a8af05c4) (float _x_, float _y_, float _w_, float _h_, float _r_, float _f_, const [ffw::Color](ffw_Color.html) & _icol_, const [ffw::Color](ffw_Color.html) & _ocol_) const  _Creates and returns a box gradient, a wrapper around nvgBoxGradient._ |
|  [DrawPaint](ffw_DrawPaint.html) | [createRadialGradient](#a284ffba) (float _cx_, float _cy_, float _inr_, float _outr_, const [ffw::Color](ffw_Color.html) & _icol_, const [ffw::Color](ffw_Color.html) & _ocol_) const  _Creates and returns a radial gradient, a wrapper around nvgRadialGradient._ |
|  void | [drawQuad](#c4d3cc4e) (float _p0x_, float _p0y_, float _p1x_, float _p1y_, float _p2x_, float _p2y_, float _p3x_, float _p3y_) const  _Draws a quad composing of 4 points._ |
|  void | [drawRectangle](#6fe5d001) (float _posx_, float _posy_, float _width_, float _height_) const  _Draws a simple rectangle._ |
|  void | [drawRectangleRounded](#6fcb2744) (float _posx_, float _posy_, float _width_, float _height_, float _corners_) const  _Draws a rectangle with rounded corners._ |
|  void | [drawRectangleRounded](#45134dca) (float _posx_, float _posy_, float _width_, float _height_, float _leftTop_, float _rightTop_, float _bottomRight_, float _bottomLeft_) const  _Draws a rectangle with rounded corners._ |
|  void | [drawTriangle](#05037f8d) (float _p0x_, float _p0y_, float _p1x_, float _p1y_, float _p2x_, float _p2y_) const  _Draws a simple triangle._ |
|  void | [drawTexture2D](#d96eae5a) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_) const  _Draws a 2D texture._ |
|  void | [drawTexture2DMirror](#673acae2) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, bool _mirrorx_, bool _mirrory_) const  _Draws a 2D texture that can be mirrored._ |
|  void | [drawTexture2DSub](#3d93d9f3) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, int _subx_, int _suby_, int _subw_, int _subh_) const  _Draws a rectangular subsection of the texture._ |
|  void | [drawTexture2DSubMirror](#8222a522) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, int _subx_, int _suby_, int _subw_, int _subh_, bool _mirrorx_, bool _mirrory_) const  _Draws a mirrored rectangular subsection of the texture._ |
|  void | [drawArc](#f8aff81a) (float _posx_, float _posy_, float _innerradius_, float _outerradius_, double _startangle_, double _endangle_) const  _Draws an arc using starting and ending angle._ |
|  void | [drawCircle](#3bafdf65) (float _posx_, float _posy_, float _radius_) const  _Draws a simple circle._ |
|  void | [drawLine](#25f27fac) (float _startx_, float _starty_, float _endx_, float _edny_) const  _Draws a line from point A to point B._ |
|  void | [drawString](#7dbbd174) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const std::string & _str_, float _lineHeight_ = 1.25f) const  _Draws a UTF-8 string._ |
|  void | [drawString](#2fa0701f) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const std::wstring & _str_, float _lineHeight_ = 1.25f) const  _Draws a multi-byte string._ |
|  void | [drawString](#c364e3c8) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const char * _str_, size_t _length_, float _lineHeight_ = 1.25f) const  _Draws a UTF-8 string._ |
|  void | [drawString](#9e42296e) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const wchar_t * _str_, size_t _length_, float _lineHeight_ = 1.25f) const  _Draws a wide string._ |
|  void | [drawStringBox](#4d1af6fc) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const std::string & _str_, float _maxWidth_, float _lineHeight_ = 1.25f) const  _Draws a UTF-8 string wrapped inside a box with specified width._ |
|  void | [drawStringBox](#13e2c105) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const std::wstring & _str_, float _maxWidth_, float _lineHeight_ = 1.25f) const  _Draws a UTF-8 string wrapped inside a box with specified width._ |
|  void | [drawStringBox](#56a9bf46) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const char * _str_, size_t _length_, float _maxWidth_, float _lineHeight_ = 1.25f) const  _Draws a multi-byte string wrapped inside a box with specified width._ |
|  void | [drawStringBox](#a1f64bfa) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const wchar_t * _str_, size_t _length_, float _maxWidth_, float _lineHeight_ = 1.25f) const  _Draws a multi-byte string wrapped inside a box with specified width._ |
|  void | [drawBezier](#9ccec8c5) (float _startx_, float _starty_, float _cp0x_, float _cp0y_, float _cp1x_, float _cp1y_, float _endx_, float _endy_) const  _Draws a quadratic bezier curve._ |
|  void | [setDrawMode](#b14a1dca) ([DrawMode](ffw.html#642b0610) _type_) const  _Sets the mode of the next draw calls._ |
|  void | [setFillMode](#6e92f838) () const  _Sets the mode of the next draw calls to be filled._ |
|  void | [setStrokeMode](#68065bbc) () const  _Sets the mode of the next draw calls to be stroked._ |
|  void | [setFillAndStrokeMode](#abb7ddf4) () const  _Sets the mode of the next draw calls to be filled and stroked._ |
|  void | [setShapeAntiAlis](#4121c2b5) (bool _enabled_) const  _Sets whether to draw antialias for filling and stroke._ |
|  void | [setStrokeSize](#118205f8) (float _width_) const  _Sets the thickness of the stroke._ |
|  void | [setStrokeMiterLimit](#9e8a7674) (float _limit_) const  _Sets the miter limit of the stroke style._ |
|  void | [setLineCap](#e7ed27a0) ([LineCap](ffw.html#795eeb36) _type_) const  _Sets how the end of the line (cap) is drawn._ |
|  void | [setLineJoin](#b8272a6d) ([LineCap](ffw.html#795eeb36) _type_) const  _Sets how sharp path corners are drawn._ |
|  void | [setScissor](#bfbf0055) (float _posx_, float _posy_, float _width_, float _height_) const  _Sets the current scissor rectangle._ |
|  void | [setIntersectScissor](#f817f879) (float _posx_, float _posy_, float _width_, float _height_) const  _Intersects current scissor rectangle with the specified rectangle._ |
|  void | [resetScissor](#4651b5e5) () const  _Reset and disables scissoring._ |
|  void | [beginPath](#dfa623b0) (float _x_, float _y_) const  _Clears the current path and sub-paths and moves to position [x, y]._ |
|  void | [drawLineTo](#542679f9) (float _x_, float _y_) const  _Adds line segment from the last point in the path to the specified point._ |
|  void | [drawBezierTo](#65976980) (float _cp0x_, float _cp0y_, float _cp1x_, float _cp1y_, float _endx_, float _endy_) const  _Adds cubic bezier segment from last point in the path via two control points to the specified point._ |
|  void | [drawQuadTo](#d7c46f58) (float _cpx_, float _cpy_, float _endx_, float _endy_) const  _Adds quadratic bezier segment from last point in the path via a control point to the specified point._ |
|  void | [drawArcTo](#bf5ca890) (float _startx_, float _starty_, float _endx_, float _endy_, float _radius_) const  _Adds an arc segment at the corner defined by the last path point, and two specified points._ |
|  void | [closePath](#f60dd2d9) () const  _Closes current sub-path with a line segment._ |
|  void | [fillPath](#1c5dc9fa) () const  _Fills the current path with current fill style._ |
|  void | [strokePath](#7094f473) () const  _Fills the current path with current stroke style._ |
|  void | [setPathWinding](#a7c0a369) ([DrawPathWinding](ffw.html#5ed40213) _winding_) const  _Sets the current sub-path winding._ |
|  void | [saveDrawState](#7fe07254) () const  _Pushes and saves the current render state into a state stack._ |
|  void | [restoreDrawState](#aae38fe6) () const  _Pops and restores current render state._ |
|  void | [resetDrawState](#85ac31cc) () const  _Resets current render state to default values._ |
|  void | [resetTransform](#66964bf0) () const  _Resets current transform to a identity matrix._ |
|  void | [transformMove](#cb5a5c38) (float _x_, float _y_) const  _Translates current coordinate system._ |
|  void | [transformRotate](#b6b6aa64) (float _degrees_) const  _Rotates current coordinate system in degrees._ |
|  void | [transformSkewX](#22ea0e58) (float _degrees_) const  _Skews the current coordinate system along X axis in degrees._ |
|  void | [transformSkewY](#d6c0a4e0) (float _degrees_) const  _Skews the current coordinate system along Y axis in degrees._ |
|  void | [transformScale](#d8030f6e) (float _x_, float _y_) const  _Scales the current coordinate system._ |
|  void | [transform](#ef0e542a) (float _a_, float _b_, float _c_, float _d_, float _e_, float _f_) const  _Translates current coordinate system._ |
|  void | [getTransform](#fa4c273a) (float * _arr_) const  _Stores the transform matrix into the buffer provided._ |
|  void | [getOpenGLTransform](#50a91511) (float * _arr_) const  _Stores the transform matrix as OpenGL matrix into the buffer provided._ |


## Public Attributes Documentation

### _variable_ <a id="281e33a7" href="#281e33a7">position</a>

```cpp
int position
```



### _variable_ <a id="05f2da6c" href="#05f2da6c">rgbMixer</a>

```cpp
int rgbMixer
```



### _variable_ <a id="e0cf940a" href="#e0cf940a">color</a>

```cpp
int color
```



### _variable_ <a id="d02ef9f1" href="#d02ef9f1">proj</a>

```cpp
int proj
```



### _variable_ <a id="f1e0780f" href="#f1e0780f">uvpos</a>

```cpp
int uvpos
```



### _variable_ <a id="c3cdd4a1" href="#c3cdd4a1">tex</a>

```cpp
int tex
```



### _variable_ <a id="e6f20158" href="#e6f20158">offset</a>

```cpp
int offset
```



### _variable_ <a id="e5f21541" href="#e5f21541">view</a>

```cpp
int view
```





## Public Functions Documentation

### _function_ <a id="b667aae5" href="#b667aae5">RenderContext</a>

```cpp
 RenderContext () 
```



### _function_ <a id="b635b879" href="#b635b879">~RenderContext</a>

```cpp
virtual  ~RenderContext () 
```



### _function_ <a id="16d7b686" href="#16d7b686">getGlextFunc</a>

```cpp
virtual void * getGlextFunc (
    const std::string & name
) const = 0 
```

Retuns the address of the GL extension function. 

The pointer to the GL extension function may not be the same on different GL contexts! 
### _function_ <a id="66742b2f" href="#66742b2f">isGlextExtSupported</a>

```cpp
virtual bool isGlextExtSupported (
    const std::string & name
) const = 0 
```

Returns true if the GL extension is suported. 

Checks if an GLEXT extension is supported, for example "GL_ARB_debug_output" 
### _function_ <a id="9d9e5d7c" href="#9d9e5d7c">initDrawing</a>

```cpp
bool initDrawing () 
```

Initializes drawing functions. 

### _function_ <a id="5e83973b" href="#5e83973b">beginFrame</a>

```cpp
void beginFrame () const 
```

Begins the render frame and makes this context ready to be used with drawing function. 

**note:** This function must be called before every draw call 

**Example:**

```cpp
// class MyRenderWindow extends ffw::GLFWRenderWindow
void MyRenderWindow::render(){
    this->beginFrame();
    this->setDrawColor(ffw::rgb(0xFF0000));
    this->drawRectangle(50, 50, 200, 100);
    this->endFrame();
}
```
 


### _function_ <a id="f453fc43" href="#f453fc43">endFrame</a>

```cpp
void endFrame () const 
```

Ends the render frame. 

**note:** This function must be called at the end of each render 

**Example:**

```cpp
// class MyRenderWindow extends ffw::GLFWRenderWindow
void MyRenderWindow::render(){
    this->beginFrame();
    this->setDrawColor(ffw::rgb(0xFF0000));
    this->drawRectangle(50, 50, 200, 100);
    this->endFrame();
}
```
 


### _function_ <a id="1bbcfe20" href="#1bbcfe20">setDrawColor</a>

```cpp
void setDrawColor (
    const ffw::Color & color
) const 
```

Sets the color of the next draw commands (fill and stroke color) 

### _function_ <a id="adbaf2e4" href="#adbaf2e4">setFillColor</a>

```cpp
void setFillColor (
    const ffw::Color & color
) const 
```

Sets the color of the next draw commands (fill only) 

### _function_ <a id="25e8423e" href="#25e8423e">setStrokeColor</a>

```cpp
void setStrokeColor (
    const ffw::Color & color
) const 
```

Sets the color of the next draw commands (stroke only) 

### _function_ <a id="89d56de8" href="#89d56de8">setFillPaint</a>

```cpp
void setFillPaint (
    const DrawPaint & paint
) const 
```

Sets current fill style to a paint, which can be a one of the gradients. 

### _function_ <a id="265c8cf3" href="#265c8cf3">setStrokePaint</a>

```cpp
void setStrokePaint (
    const DrawPaint & paint
) const 
```

Sets current stroke style to a paint, which can be a one of the gradients. 

### _function_ <a id="4ff1c181" href="#4ff1c181">createLinearGradient</a>

```cpp
DrawPaint createLinearGradient (
    float sx,
    float sy,
    float ex,
    float ey,
    const ffw::Color & icol,
    const ffw::Color & ocol
) const 
```

Creates and returns a linear gradient, a wrapper around nvgLinearGradient. 

Parameters (sx,sy)-(ex,ey) specify the start and end coordinates of the linear gradient, icol specifies the start color and ocol the end color. The gradient is transformed by the current transform when it is passed to [setFillPaint()](ffw_RenderContext.html#89d56de8) or [setStrokePaint()](ffw_RenderContext.html#265c8cf3). 
### _function_ <a id="a8af05c4" href="#a8af05c4">createBoxGradient</a>

```cpp
DrawPaint createBoxGradient (
    float x,
    float y,
    float w,
    float h,
    float r,
    float f,
    const ffw::Color & icol,
    const ffw::Color & ocol
) const 
```

Creates and returns a box gradient, a wrapper around nvgBoxGradient. 

Box gradient is a feathered rounded rectangle, it is useful for rendering drop shadows or highlights for boxes. Parameters (x,y) define the top-left corner of the rectangle, (w,h) define the size of the rectangle, r defines the corner radius, and f feather. Feather defines how blurry the border of the rectangle is. Parameter icol specifies the inner color and ocol the outer color of the gradient. The gradient is transformed by the current transform when it is passed to [setFillPaint()](ffw_RenderContext.html#89d56de8) or [setStrokePaint()](ffw_RenderContext.html#265c8cf3). 
### _function_ <a id="a284ffba" href="#a284ffba">createRadialGradient</a>

```cpp
DrawPaint createRadialGradient (
    float cx,
    float cy,
    float inr,
    float outr,
    const ffw::Color & icol,
    const ffw::Color & ocol
) const 
```

Creates and returns a radial gradient, a wrapper around nvgRadialGradient. 

Parameters (cx,cy) specify the center, inr and outr specify the inner and outer radius of the gradient, icol specifies the start color and ocol the end color. The gradient is transformed by the current transform when it is passed to [setFillPaint()](ffw_RenderContext.html#89d56de8) or [setStrokePaint()](ffw_RenderContext.html#265c8cf3). 
### _function_ <a id="c4d3cc4e" href="#c4d3cc4e">drawQuad</a>

```cpp
void drawQuad (
    float p0x,
    float p0y,
    float p1x,
    float p1y,
    float p2x,
    float p2y,
    float p3x,
    float p3y
) const 
```

Draws a quad composing of 4 points. 

### _function_ <a id="6fe5d001" href="#6fe5d001">drawRectangle</a>

```cpp
void drawRectangle (
    float posx,
    float posy,
    float width,
    float height
) const 
```

Draws a simple rectangle. 

### _function_ <a id="6fcb2744" href="#6fcb2744">drawRectangleRounded</a>

```cpp
void drawRectangleRounded (
    float posx,
    float posy,
    float width,
    float height,
    float corners
) const 
```

Draws a rectangle with rounded corners. 

### _function_ <a id="45134dca" href="#45134dca">drawRectangleRounded</a>

```cpp
void drawRectangleRounded (
    float posx,
    float posy,
    float width,
    float height,
    float leftTop,
    float rightTop,
    float bottomRight,
    float bottomLeft
) const 
```

Draws a rectangle with rounded corners. 

### _function_ <a id="05037f8d" href="#05037f8d">drawTriangle</a>

```cpp
void drawTriangle (
    float p0x,
    float p0y,
    float p1x,
    float p1y,
    float p2x,
    float p2y
) const 
```

Draws a simple triangle. 

### _function_ <a id="d96eae5a" href="#d96eae5a">drawTexture2D</a>

```cpp
void drawTexture2D (
    float posx,
    float posy,
    float width,
    float height,
    const ffw::Texture2D * texture
) const 
```

Draws a 2D texture. 

### _function_ <a id="673acae2" href="#673acae2">drawTexture2DMirror</a>

```cpp
void drawTexture2DMirror (
    float posx,
    float posy,
    float width,
    float height,
    const ffw::Texture2D * texture,
    bool mirrorx,
    bool mirrory
) const 
```

Draws a 2D texture that can be mirrored. 

### _function_ <a id="3d93d9f3" href="#3d93d9f3">drawTexture2DSub</a>

```cpp
void drawTexture2DSub (
    float posx,
    float posy,
    float width,
    float height,
    const ffw::Texture2D * texture,
    int subx,
    int suby,
    int subw,
    int subh
) const 
```

Draws a rectangular subsection of the texture. 

The subsection coordinates are in pixels. 
### _function_ <a id="8222a522" href="#8222a522">drawTexture2DSubMirror</a>

```cpp
void drawTexture2DSubMirror (
    float posx,
    float posy,
    float width,
    float height,
    const ffw::Texture2D * texture,
    int subx,
    int suby,
    int subw,
    int subh,
    bool mirrorx,
    bool mirrory
) const 
```

Draws a mirrored rectangular subsection of the texture. 

The subsection coordinates are in pixels and the mirroring affects the result subsection. 
### _function_ <a id="f8aff81a" href="#f8aff81a">drawArc</a>

```cpp
void drawArc (
    float posx,
    float posy,
    float innerradius,
    float outerradius,
    double startangle,
    double endangle
) const 
```

Draws an arc using starting and ending angle. 

### _function_ <a id="3bafdf65" href="#3bafdf65">drawCircle</a>

```cpp
void drawCircle (
    float posx,
    float posy,
    float radius
) const 
```

Draws a simple circle. 

### _function_ <a id="25f27fac" href="#25f27fac">drawLine</a>

```cpp
void drawLine (
    float startx,
    float starty,
    float endx,
    float edny
) const 
```

Draws a line from point A to point B. 

### _function_ <a id="7dbbd174" href="#7dbbd174">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const std::string & str,
    float lineHeight = 1.25f
) const 
```

Draws a UTF-8 string. 

### _function_ <a id="2fa0701f" href="#2fa0701f">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const std::wstring & str,
    float lineHeight = 1.25f
) const 
```

Draws a multi-byte string. 

### _function_ <a id="c364e3c8" href="#c364e3c8">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const char * str,
    size_t length,
    float lineHeight = 1.25f
) const 
```

Draws a UTF-8 string. 

### _function_ <a id="9e42296e" href="#9e42296e">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const wchar_t * str,
    size_t length,
    float lineHeight = 1.25f
) const 
```

Draws a wide string. 

### _function_ <a id="4d1af6fc" href="#4d1af6fc">drawStringBox</a>

```cpp
void drawStringBox (
    float posx,
    float posy,
    const Font * font,
    const std::string & str,
    float maxWidth,
    float lineHeight = 1.25f
) const 
```

Draws a UTF-8 string wrapped inside a box with specified width. 

### _function_ <a id="13e2c105" href="#13e2c105">drawStringBox</a>

```cpp
void drawStringBox (
    float posx,
    float posy,
    const Font * font,
    const std::wstring & str,
    float maxWidth,
    float lineHeight = 1.25f
) const 
```

Draws a UTF-8 string wrapped inside a box with specified width. 

### _function_ <a id="56a9bf46" href="#56a9bf46">drawStringBox</a>

```cpp
void drawStringBox (
    float posx,
    float posy,
    const Font * font,
    const char * str,
    size_t length,
    float maxWidth,
    float lineHeight = 1.25f
) const 
```

Draws a multi-byte string wrapped inside a box with specified width. 

### _function_ <a id="a1f64bfa" href="#a1f64bfa">drawStringBox</a>

```cpp
void drawStringBox (
    float posx,
    float posy,
    const Font * font,
    const wchar_t * str,
    size_t length,
    float maxWidth,
    float lineHeight = 1.25f
) const 
```

Draws a multi-byte string wrapped inside a box with specified width. 

### _function_ <a id="9ccec8c5" href="#9ccec8c5">drawBezier</a>

```cpp
void drawBezier (
    float startx,
    float starty,
    float cp0x,
    float cp0y,
    float cp1x,
    float cp1y,
    float endx,
    float endy
) const 
```

Draws a quadratic bezier curve. 

### _function_ <a id="b14a1dca" href="#b14a1dca">setDrawMode</a>

```cpp
void setDrawMode (
    DrawMode type
) const 
```

Sets the mode of the next draw calls. 

### _function_ <a id="6e92f838" href="#6e92f838">setFillMode</a>

```cpp
inline void setFillMode () const 
```

Sets the mode of the next draw calls to be filled. 

### _function_ <a id="68065bbc" href="#68065bbc">setStrokeMode</a>

```cpp
inline void setStrokeMode () const 
```

Sets the mode of the next draw calls to be stroked. 

### _function_ <a id="abb7ddf4" href="#abb7ddf4">setFillAndStrokeMode</a>

```cpp
inline void setFillAndStrokeMode () const 
```

Sets the mode of the next draw calls to be filled and stroked. 

### _function_ <a id="4121c2b5" href="#4121c2b5">setShapeAntiAlis</a>

```cpp
void setShapeAntiAlis (
    bool enabled
) const 
```

Sets whether to draw antialias for filling and stroke. 

It's enabled by default. **note:** Performs nvgShapeAntiAlias from nanovg 


### _function_ <a id="118205f8" href="#118205f8">setStrokeSize</a>

```cpp
void setStrokeSize (
    float width
) const 
```

Sets the thickness of the stroke. 

### _function_ <a id="9e8a7674" href="#9e8a7674">setStrokeMiterLimit</a>

```cpp
void setStrokeMiterLimit (
    float limit
) const 
```

Sets the miter limit of the stroke style. 

Miter limit controls when a sharp corner is beveled 
### _function_ <a id="e7ed27a0" href="#e7ed27a0">setLineCap</a>

```cpp
void setLineCap (
    LineCap type
) const 
```

Sets how the end of the line (cap) is drawn. 

### _function_ <a id="b8272a6d" href="#b8272a6d">setLineJoin</a>

```cpp
void setLineJoin (
    LineCap type
) const 
```

Sets how sharp path corners are drawn. 

### _function_ <a id="bfbf0055" href="#bfbf0055">setScissor</a>

```cpp
void setScissor (
    float posx,
    float posy,
    float width,
    float height
) const 
```

Sets the current scissor rectangle. 

Scissoring allows you to clip the rendering into a rectangle. The scissor rectangle is transformed by the current transform. **note:** Acts same as nvgScissor from nanovg 


### _function_ <a id="f817f879" href="#f817f879">setIntersectScissor</a>

```cpp
void setIntersectScissor (
    float posx,
    float posy,
    float width,
    float height
) const 
```

Intersects current scissor rectangle with the specified rectangle. 

The scissor rectangle is transformed by the current transform. In case the rotation of previous scissor rect differs from the current one, the intersection will be done between the specified rectangle and the previous scissor rectangle transformed in the current transform space. The resulting shape is always rectangle. **note:** Acts same as nvgIntersectScissor from nanovg 


### _function_ <a id="4651b5e5" href="#4651b5e5">resetScissor</a>

```cpp
void resetScissor () const 
```

Reset and disables scissoring. 

**note:** Acts same as nvgResetScissor from nanovg 


### _function_ <a id="dfa623b0" href="#dfa623b0">beginPath</a>

```cpp
void beginPath (
    float x,
    float y
) const 
```

Clears the current path and sub-paths and moves to position [x, y]. 

**note:** Performs nvgBeginPath and nvgMoveTo from nanovg 


### _function_ <a id="542679f9" href="#542679f9">drawLineTo</a>

```cpp
void drawLineTo (
    float x,
    float y
) const 
```

Adds line segment from the last point in the path to the specified point. 

**note:** Performs nvgLineTo from nanovg 


### _function_ <a id="65976980" href="#65976980">drawBezierTo</a>

```cpp
void drawBezierTo (
    float cp0x,
    float cp0y,
    float cp1x,
    float cp1y,
    float endx,
    float endy
) const 
```

Adds cubic bezier segment from last point in the path via two control points to the specified point. 

**note:** Performs nvgBezierTo from nanovg 


### _function_ <a id="d7c46f58" href="#d7c46f58">drawQuadTo</a>

```cpp
void drawQuadTo (
    float cpx,
    float cpy,
    float endx,
    float endy
) const 
```

Adds quadratic bezier segment from last point in the path via a control point to the specified point. 

**note:** Performs nvgQuadTo from nanovg 


### _function_ <a id="bf5ca890" href="#bf5ca890">drawArcTo</a>

```cpp
void drawArcTo (
    float startx,
    float starty,
    float endx,
    float endy,
    float radius
) const 
```

Adds an arc segment at the corner defined by the last path point, and two specified points. 

**note:** Performs nvgArcTo from nanovg 


### _function_ <a id="f60dd2d9" href="#f60dd2d9">closePath</a>

```cpp
void closePath () const 
```

Closes current sub-path with a line segment. 

**note:** Performs nvgClosePath 


### _function_ <a id="1c5dc9fa" href="#1c5dc9fa">fillPath</a>

```cpp
void fillPath () const 
```

Fills the current path with current fill style. 

**note:** Performs nvgFill from nanovg 


### _function_ <a id="7094f473" href="#7094f473">strokePath</a>

```cpp
void strokePath () const 
```

Fills the current path with current stroke style. 

**note:** Performs nvgStroke from nanovg 


### _function_ <a id="a7c0a369" href="#a7c0a369">setPathWinding</a>

```cpp
void setPathWinding (
    DrawPathWinding winding
) const 
```

Sets the current sub-path winding. 

**note:** Performs nvgPathWinding from nanovg 


### _function_ <a id="7fe07254" href="#7fe07254">saveDrawState</a>

```cpp
void saveDrawState () const 
```

Pushes and saves the current render state into a state stack. 

**note:** Performs nvgStroke from nanovg 


### _function_ <a id="aae38fe6" href="#aae38fe6">restoreDrawState</a>

```cpp
void restoreDrawState () const 
```

Pops and restores current render state. 

**note:** Performs nvgStroke from nanovg 


### _function_ <a id="85ac31cc" href="#85ac31cc">resetDrawState</a>

```cpp
void resetDrawState () const 
```

Resets current render state to default values. 

**note:** Performs nvgStroke from nanovg 


### _function_ <a id="66964bf0" href="#66964bf0">resetTransform</a>

```cpp
void resetTransform () const 
```

Resets current transform to a identity matrix. 

**note:** Performs nvgStroke from nanovg 


### _function_ <a id="cb5a5c38" href="#cb5a5c38">transformMove</a>

```cpp
void transformMove (
    float x,
    float y
) const 
```

Translates current coordinate system. 

**note:** Performs nvgTranslate from nanovg 


### _function_ <a id="b6b6aa64" href="#b6b6aa64">transformRotate</a>

```cpp
void transformRotate (
    float degrees
) const 
```

Rotates current coordinate system in degrees. 

**note:** Performs nvgRotate from nanovg 


### _function_ <a id="22ea0e58" href="#22ea0e58">transformSkewX</a>

```cpp
void transformSkewX (
    float degrees
) const 
```

Skews the current coordinate system along X axis in degrees. 

**note:** Performs nvgSkewX from nanovg 


### _function_ <a id="d6c0a4e0" href="#d6c0a4e0">transformSkewY</a>

```cpp
void transformSkewY (
    float degrees
) const 
```

Skews the current coordinate system along Y axis in degrees. 

**note:** Performs nvgSkewY from nanovg 


### _function_ <a id="d8030f6e" href="#d8030f6e">transformScale</a>

```cpp
void transformScale (
    float x,
    float y
) const 
```

Scales the current coordinate system. 

**note:** Performs nvgScale from nanovg 


### _function_ <a id="ef0e542a" href="#ef0e542a">transform</a>

```cpp
void transform (
    float a,
    float b,
    float c,
    float d,
    float e,
    float f
) const 
```

Translates current coordinate system. 

The parameters are interpreted as matrix as follows First row: [a c e] Second row: [b d f] Third row: [0 0 1] **note:** Performs nvgTransform from nanovg 


### _function_ <a id="fa4c273a" href="#fa4c273a">getTransform</a>

```cpp
void getTransform (
    float * arr
) const 
```

Stores the transform matrix into the buffer provided. 

Stores the top part (a-f) of the current transformation matrix in to the specified buffer. There should be space for 6 floats in the return buffer for the values a-f. 

**Example:**

```cpp
// | a c e |
// | b d f |
// | 0 0 1 |
```
 **note:** Performs nvgCurrentTransform from nanovg 


### _function_ <a id="50a91511" href="#50a91511">getOpenGLTransform</a>

```cpp
void getOpenGLTransform (
    float * arr
) const 
```

Stores the transform matrix as OpenGL matrix into the buffer provided. 

Similar to [getTransform()](ffw_RenderContext.html#fa4c273a) but this function returns OpenGL matrix that can be used within shaders. The function expects an array of 9 floats. 


