RenderContext
===================================


**Inherits from:** [ffw::RenderExtensions](ffw_RenderExtensions.html)

**Implemented by:** [ffw::GLFWRenderWindow](ffw_GLFWRenderWindow.html)

The documentation for this class was generated from: `include/ffw/graphics/rendercontext.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [RenderContext](#b667aae5) ()  |
|  virtual  | [~RenderContext](#b635b879) ()  |
|  virtual void * | [getGlextFunc](#16d7b686) (const std::string & _name_) const = 0  _Retuns the address of the GL extension function._ |
|  virtual bool | [isGlextExtSupported](#66742b2f) (const std::string & _name_) const = 0  _Returns true if the GL extension is suported._ |
|  void | [setViewport](#1e515370) (int _posx_, int _posy_, int _width_, int _height_)  _Sets the viewport dimensions and position._ |
|  void | [setDrawColor](#6b8df6af) (const [ffw::Color](ffw_Color.html) & _color_)  _Sets the color of the next draw commands._ |
|  void | [drawQuad](#98c11b5c) (float _p0x_, float _p0y_, float _p1x_, float _p1y_, float _p2x_, float _p2y_, float _p3x_, float _p3y_)  _Draws a quad composing of 4 points._ |
|  void | [drawRectangle](#e04aedbb) (float _posx_, float _posy_, float _width_, float _height_)  _Draws a simple rectangle._ |
|  void | [drawRectangleRounded](#651eec48) (float _posx_, float _posy_, float _width_, float _height_, float _corners_)  _Draws a rectangle with rounded corners._ |
|  void | [drawRectangleRounded](#12c63167) (float _posx_, float _posy_, float _width_, float _height_, float _leftTop_, float _rightTop_, float _bottomRight_, float _bottomLeft_)  _Draws a rectangle with rounded corners._ |
|  void | [drawTriangle](#79fc47bb) (float _p0x_, float _p0y_, float _p1x_, float _p1y_, float _p2x_, float _p2y_)  _Draws a simple triangle._ |
|  void | [drawTexture2D](#cc8d1ac9) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_)  _Draws a 2D texture._ |
|  void | [drawTexture2DMirror](#fd18ad28) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, bool _mirrorx_, bool _mirrory_)  _Draws a 2D texture that can be mirrored._ |
|  void | [drawTexture2DSub](#e7341ced) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, int _subx_, int _suby_, int _subw_, int _subh_)  _Draws a rectangular subsection of the texture._ |
|  void | [drawTexture2DSubMirror](#d35d4e67) (float _posx_, float _posy_, float _width_, float _height_, const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, int _subx_, int _suby_, int _subw_, int _subh_, bool _mirrorx_, bool _mirrory_)  _Draws a mirrored rectangular subsection of the texture._ |
|  void | [drawArc](#df89b764) (float _posx_, float _posy_, float _innerradius_, float _outerradius_, double _startangle_, double _endangle_)  _Draws an arc using starting and ending angle._ |
|  void | [drawCircle](#a99be3f4) (float _posx_, float _posy_, float _radius_)  _Draws a simple circle._ |
|  void | [drawLine](#5bb70248) (float _startx_, float _starty_, float _endx_, float _edny_)  _Draws a line from point A to point B._ |
|  void | [drawString](#a583cfdb) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const std::string & _str_, float _lineHeight_ = 1.25f)  _Draws a string._ |
|  void | [drawString](#8c56a4f4) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const std::wstring & _str_, float _lineHeight_ = 1.25f)  _Draws a multi-byte string._ |
|  void | [drawString](#8f467161) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const char * _str_, float _lineHeight_ = 1.25f)  _Draws a string._ |
|  void | [drawString](#4a15697f) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const char * _str_, size_t _length_, float _lineHeight_ = 1.25f)  _Draws a string._ |
|  void | [drawString](#149b09e3) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const wchar_t * _str_, float _lineHeight_ = 1.25f)  _Draws a multi-byte string._ |
|  void | [drawString](#03e75086) (float _posx_, float _posy_, const [Font](ffw_Font.html) * _font_, const wchar_t * _str_, size_t _length_, float _lineHeight_ = 1.25f)  _Draws a multi-byte string._ |
|  void | [drawBezier](#b36a1802) (float _startx_, float _starty_, float _cp0x_, float _cp0y_, float _cp1x_, float _cp1y_, float _endx_, float _endy_)  _Draws a quadratic bezier curve._ |
|  void | [setArcSteps](#a28974fb) (int _steps_)  _Sets the number of steps for the arc and circle._ |
|  void | [setBezierSteps](#f0653c70) (int _steps_)  _Sets the number of steps for the bezier curve._ |
|  void | [setRectangleSteps](#29a68498) (int _steps_)  _Sets the number of steps for corners of the rounded rectangle._ |
|  void | [setOutlineMode](#9279a9aa) (bool _enabled_)  _Sets if the next rendered primitive should be filled or outlined._ |
|  void | [setOutlineSize](#7acd1170) (int _pixels_)  _Sets the thickness of the outline mode._ |
|  bool | [getOutlineMode](#c78e717c) () const  _Returns true if the outline mode is enabled._ |
|  int | [getOutlineSize](#08402f1f) () const  _Returns the thickness of the outline mode._ |


## Protected Functions

| Type | Name |
| -------: | :------- |
|  bool | [compileShaders](#299cf036) ()  |
|  bool | [compileShadersGL3](#99655cd0) ()  |


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
### _function_ <a id="1e515370" href="#1e515370">setViewport</a>

```cpp
void setViewport (
    int posx,
    int posy,
    int width,
    int height
) 
```

Sets the viewport dimensions and position. 

### _function_ <a id="6b8df6af" href="#6b8df6af">setDrawColor</a>

```cpp
void setDrawColor (
    const ffw::Color & color
) 
```

Sets the color of the next draw commands. 

### _function_ <a id="98c11b5c" href="#98c11b5c">drawQuad</a>

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
) 
```

Draws a quad composing of 4 points. 

### _function_ <a id="e04aedbb" href="#e04aedbb">drawRectangle</a>

```cpp
void drawRectangle (
    float posx,
    float posy,
    float width,
    float height
) 
```

Draws a simple rectangle. 

### _function_ <a id="651eec48" href="#651eec48">drawRectangleRounded</a>

```cpp
void drawRectangleRounded (
    float posx,
    float posy,
    float width,
    float height,
    float corners
) 
```

Draws a rectangle with rounded corners. 

### _function_ <a id="12c63167" href="#12c63167">drawRectangleRounded</a>

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
) 
```

Draws a rectangle with rounded corners. 

### _function_ <a id="79fc47bb" href="#79fc47bb">drawTriangle</a>

```cpp
void drawTriangle (
    float p0x,
    float p0y,
    float p1x,
    float p1y,
    float p2x,
    float p2y
) 
```

Draws a simple triangle. 

### _function_ <a id="cc8d1ac9" href="#cc8d1ac9">drawTexture2D</a>

```cpp
void drawTexture2D (
    float posx,
    float posy,
    float width,
    float height,
    const ffw::Texture2D * texture
) 
```

Draws a 2D texture. 

### _function_ <a id="fd18ad28" href="#fd18ad28">drawTexture2DMirror</a>

```cpp
void drawTexture2DMirror (
    float posx,
    float posy,
    float width,
    float height,
    const ffw::Texture2D * texture,
    bool mirrorx,
    bool mirrory
) 
```

Draws a 2D texture that can be mirrored. 

### _function_ <a id="e7341ced" href="#e7341ced">drawTexture2DSub</a>

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
) 
```

Draws a rectangular subsection of the texture. 

The subsection coordinates are in pixels. 
### _function_ <a id="d35d4e67" href="#d35d4e67">drawTexture2DSubMirror</a>

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
) 
```

Draws a mirrored rectangular subsection of the texture. 

The subsection coordinates are in pixels and the mirroring affects the result subsection. 
### _function_ <a id="df89b764" href="#df89b764">drawArc</a>

```cpp
void drawArc (
    float posx,
    float posy,
    float innerradius,
    float outerradius,
    double startangle,
    double endangle
) 
```

Draws an arc using starting and ending angle. 

### _function_ <a id="a99be3f4" href="#a99be3f4">drawCircle</a>

```cpp
void drawCircle (
    float posx,
    float posy,
    float radius
) 
```

Draws a simple circle. 

### _function_ <a id="5bb70248" href="#5bb70248">drawLine</a>

```cpp
void drawLine (
    float startx,
    float starty,
    float endx,
    float edny
) 
```

Draws a line from point A to point B. 

### _function_ <a id="a583cfdb" href="#a583cfdb">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const std::string & str,
    float lineHeight = 1.25f
) 
```

Draws a string. 

This is not UTF-8 enabled! 
### _function_ <a id="8c56a4f4" href="#8c56a4f4">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const std::wstring & str,
    float lineHeight = 1.25f
) 
```

Draws a multi-byte string. 

### _function_ <a id="8f467161" href="#8f467161">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const char * str,
    float lineHeight = 1.25f
) 
```

Draws a string. 

This is not UTF-8 enabled! 
### _function_ <a id="4a15697f" href="#4a15697f">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const char * str,
    size_t length,
    float lineHeight = 1.25f
) 
```

Draws a string. 

This is not UTF-8 enabled! 
### _function_ <a id="149b09e3" href="#149b09e3">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const wchar_t * str,
    float lineHeight = 1.25f
) 
```

Draws a multi-byte string. 

### _function_ <a id="03e75086" href="#03e75086">drawString</a>

```cpp
void drawString (
    float posx,
    float posy,
    const Font * font,
    const wchar_t * str,
    size_t length,
    float lineHeight = 1.25f
) 
```

Draws a multi-byte string. 

### _function_ <a id="b36a1802" href="#b36a1802">drawBezier</a>

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
) 
```

Draws a quadratic bezier curve. 

### _function_ <a id="a28974fb" href="#a28974fb">setArcSteps</a>

```cpp
inline void setArcSteps (
    int steps
) 
```

Sets the number of steps for the arc and circle. 

### _function_ <a id="f0653c70" href="#f0653c70">setBezierSteps</a>

```cpp
inline void setBezierSteps (
    int steps
) 
```

Sets the number of steps for the bezier curve. 

### _function_ <a id="29a68498" href="#29a68498">setRectangleSteps</a>

```cpp
inline void setRectangleSteps (
    int steps
) 
```

Sets the number of steps for corners of the rounded rectangle. 

### _function_ <a id="9279a9aa" href="#9279a9aa">setOutlineMode</a>

```cpp
inline void setOutlineMode (
    bool enabled
) 
```

Sets if the next rendered primitive should be filled or outlined. 

### _function_ <a id="7acd1170" href="#7acd1170">setOutlineSize</a>

```cpp
inline void setOutlineSize (
    int pixels
) 
```

Sets the thickness of the outline mode. 

### _function_ <a id="c78e717c" href="#c78e717c">getOutlineMode</a>

```cpp
inline bool getOutlineMode () const 
```

Returns true if the outline mode is enabled. 

### _function_ <a id="08402f1f" href="#08402f1f">getOutlineSize</a>

```cpp
inline int getOutlineSize () const 
```

Returns the thickness of the outline mode. 



## Protected Functions Documentation

### _function_ <a id="299cf036" href="#299cf036">compileShaders</a>

```cpp
bool compileShaders () 
```



### _function_ <a id="99655cd0" href="#99655cd0">compileShadersGL3</a>

```cpp
bool compileShadersGL3 () 
```





