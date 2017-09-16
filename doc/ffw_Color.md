Color
===================================

Class that holds floating point color, OpenGL friendly. 

The documentation for this struct was generated from: `include/ffw/math/color.h`

## Detailed description

You can use this class to represent any RGBA color and pass it to your OpenGL function. This class uses 4 floats to represent color combinations. For example, 100% red color is when r is set to 1.0f and all other (g, b, a) is set to 0.0. You can also use [ffw::rgba](ffw.html#efcb64d9) function to construct this class with less typing **see:** [ffw::rgb](ffw.html#e71e7885), [ffw::rgba](ffw.html#efcb64d9), 




## Public Attributes

| Type | Name |
| -------: | :------- |
|  float | [r](#de98d59f) |
|  float | [g](#f87a9edd) |
|  float | [b](#d155be4f) |
|  float | [a](#ac8a0369) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Color](#74212703) () <div style="opacity:0.8;">Default constructor, sets color to black with 0% alpha. </div> |
|   | [Color](#59951134) (float _red_, float _green_, float _blue_, float _alpha_) <div style="opacity:0.8;">Construcor, sets the color based on the parameters. </div> |
|   | [Color](#91bbfd2b) (float _val_, float _alpha_) <div style="opacity:0.8;">Constructor, sets the color to grayscale with alpha. </div> |
|   | [Color](#21db9079) (const [Color](ffw_Color.html) & _vec_) <div style="opacity:0.8;">Copy Constructor. </div> |
|   | [Color](#f7ee4d25) (const std::initializer_list< float > & _list_) <div style="opacity:0.8;">Construcor, sets the color from braced list of 4 floating point values. </div> |
|  void | [set](#a52bf2c2) (float _red_, float _green_, float _blue_, float _alpha_) <div style="opacity:0.8;">Sets the color. </div> |
|  void | [set](#6c5c6e06) (float _val_, float _alpha_) <div style="opacity:0.8;">Sets the color. </div> |
|  void | [set](#4d3a7723) (const [Color](ffw_Color.html) & _vec_) <div style="opacity:0.8;">Sets the color from another color class. </div> |
|  void | [set](#a9b6485b) (const std::initializer_list< float > & _list_) <div style="opacity:0.8;">Sets the color from a braced list of 4 floating point values. </div> |
|  [ffw::Color](ffw_Color.html) | [operator-](#cc3e2651) () const <div style="opacity:0.8;">Performs unary minus operation on all r,g,b,a channels. </div> |
|  [ffw::Color](ffw_Color.html) & | [operator=](#e62cbff7) (const [Color](ffw_Color.html) & _vec_) <div style="opacity:0.8;">Copies values from different color instance. </div> |
|  [ffw::Color](ffw_Color.html) | [operator+](#518ec544) (const [Color](ffw_Color.html) & _vec_) const <div style="opacity:0.8;">Adds together two colors, returning a copy. </div> |
|  [ffw::Color](ffw_Color.html) & | [operator+=](#e68cbc6b) (const [Color](ffw_Color.html) & _vec_) <div style="opacity:0.8;">Adds together two colors. </div> |
|  [ffw::Color](ffw_Color.html) | [operator-](#dc887d80) (const [Color](ffw_Color.html) & _vec_) const <div style="opacity:0.8;">Substracts together two colors, returning a copy. </div> |
|  [ffw::Color](ffw_Color.html) & | [operator-=](#c53dfea1) (const [Color](ffw_Color.html) & _vec_) <div style="opacity:0.8;">Substracts together two colors. </div> |
|  [ffw::Color](ffw_Color.html) | [operator/](#334d957d) (const [Color](ffw_Color.html) & _vec_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator/=](#d8c24713) (const [Color](ffw_Color.html) & _vec_)  |
|  [ffw::Color](ffw_Color.html) | [operator*](#0586de37) (const [Color](ffw_Color.html) & _vec_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator*=](#446ed6a2) (const [Color](ffw_Color.html) & _vec_)  |
|  [ffw::Color](ffw_Color.html) & | [operator=](#234d4e26) (const float & _val_) <div style="opacity:0.8;">Assigns same value to all RGBA components. </div> |
|  [ffw::Color](ffw_Color.html) | [operator+](#d0f48049) (const float & _val_) const <div style="opacity:0.8;">Adds value to all RGBA components, returning a copy. </div> |
|  [ffw::Color](ffw_Color.html) & | [operator+=](#b7ca3a75) (const float & _val_) <div style="opacity:0.8;">Adds value to all RGBA components. </div> |
|  [ffw::Color](ffw_Color.html) | [operator-](#9b89cea0) (const float & _val_) const <div style="opacity:0.8;">Substracts from all RGBA components, returning a copy. </div> |
|  [ffw::Color](ffw_Color.html) & | [operator-=](#3eda6b73) (const float & _val_) <div style="opacity:0.8;">Substracts from all RGBA components. </div> |
|  [ffw::Color](ffw_Color.html) | [operator/](#ed6eef31) (const float & _val_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator/=](#7c828228) (const float & _val_)  |
|  [ffw::Color](ffw_Color.html) | [operator*](#4df2d50f) (const float & _val_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator*=](#eef16604) (const float & _val_)  |
|  bool | [operator!=](#47c8bd75) (const [Color](ffw_Color.html) & _vec_) const <div style="opacity:0.8;">Checks if this instance is not equal to other one, using epsilon. </div> |
|  bool | [operator==](#f0ee3ebd) (const [Color](ffw_Color.html) & _vec_) const <div style="opacity:0.8;">Checks if this instance is equal to other one, using epsilon. </div> |
|  [ffw::Color](ffw_Color.html) & | [clamp](#ee136eb5) () <div style="opacity:0.8;">Clamps all RGBA components so that all values are between 0.0 and 1.0. </div> |
|  [ffw::Color](ffw_Color.html) & | [normalize](#0720f90a) () <div style="opacity:0.8;">Normalises a color. </div> |
|  [ffw::Color](ffw_Color.html) & | [scale](#58c9f4f0) (const float _val_) <div style="opacity:0.8;">Scales all RGBA components with single value. </div> |
|  double | [length](#52d2971e) () const <div style="opacity:0.8;">Returns the length of a vector (color is treated as a vector) </div> |
|  float | [lengthf](#006193c9) () const <div style="opacity:0.8;">Returns the length of a vector (color is treated as a vector) </div> |
|  float | [lengthSqrd](#093b3b39) () const <div style="opacity:0.8;">Returns the squared length of a vector (color is treated as a vector) </div> |


## Public Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="de98d59f" href="#de98d59f">r</a>

```cpp
float r
```



### <span style="opacity:0.5;">variable</span> <a id="f87a9edd" href="#f87a9edd">g</a>

```cpp
float g
```



### <span style="opacity:0.5;">variable</span> <a id="d155be4f" href="#d155be4f">b</a>

```cpp
float b
```



### <span style="opacity:0.5;">variable</span> <a id="ac8a0369" href="#ac8a0369">a</a>

```cpp
float a
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="74212703" href="#74212703">Color</a>

```cpp
inline  Color () 
```

Default constructor, sets color to black with 0% alpha. 

### <span style="opacity:0.5;">function</span> <a id="59951134" href="#59951134">Color</a>

```cpp
inline  Color (
    float red,
    float green,
    float blue,
    float alpha
) 
```

Construcor, sets the color based on the parameters. 

### <span style="opacity:0.5;">function</span> <a id="91bbfd2b" href="#91bbfd2b">Color</a>

```cpp
inline  Color (
    float val,
    float alpha
) 
```

Constructor, sets the color to grayscale with alpha. 

### <span style="opacity:0.5;">function</span> <a id="21db9079" href="#21db9079">Color</a>

```cpp
inline  Color (
    const Color & vec
) 
```

Copy Constructor. 

### <span style="opacity:0.5;">function</span> <a id="f7ee4d25" href="#f7ee4d25">Color</a>

```cpp
inline  Color (
    const std::initializer_list< float > & list
) 
```

Construcor, sets the color from braced list of 4 floating point values. 

### <span style="opacity:0.5;">function</span> <a id="a52bf2c2" href="#a52bf2c2">set</a>

```cpp
inline void set (
    float red,
    float green,
    float blue,
    float alpha
) 
```

Sets the color. 

### <span style="opacity:0.5;">function</span> <a id="6c5c6e06" href="#6c5c6e06">set</a>

```cpp
inline void set (
    float val,
    float alpha
) 
```

Sets the color. 

### <span style="opacity:0.5;">function</span> <a id="4d3a7723" href="#4d3a7723">set</a>

```cpp
inline void set (
    const Color & vec
) 
```

Sets the color from another color class. 

### <span style="opacity:0.5;">function</span> <a id="a9b6485b" href="#a9b6485b">set</a>

```cpp
inline void set (
    const std::initializer_list< float > & list
) 
```

Sets the color from a braced list of 4 floating point values. 

### <span style="opacity:0.5;">function</span> <a id="cc3e2651" href="#cc3e2651">operator-</a>

```cpp
inline ffw::Color operator- () const 
```

Performs unary minus operation on all r,g,b,a channels. 

### <span style="opacity:0.5;">function</span> <a id="e62cbff7" href="#e62cbff7">operator=</a>

```cpp
inline ffw::Color & operator= (
    const Color & vec
) 
```

Copies values from different color instance. 

### <span style="opacity:0.5;">function</span> <a id="518ec544" href="#518ec544">operator+</a>

```cpp
inline ffw::Color operator+ (
    const Color & vec
) const 
```

Adds together two colors, returning a copy. 

### <span style="opacity:0.5;">function</span> <a id="e68cbc6b" href="#e68cbc6b">operator+=</a>

```cpp
inline ffw::Color & operator+= (
    const Color & vec
) 
```

Adds together two colors. 

### <span style="opacity:0.5;">function</span> <a id="dc887d80" href="#dc887d80">operator-</a>

```cpp
inline ffw::Color operator- (
    const Color & vec
) const 
```

Substracts together two colors, returning a copy. 

### <span style="opacity:0.5;">function</span> <a id="c53dfea1" href="#c53dfea1">operator-=</a>

```cpp
inline ffw::Color & operator-= (
    const Color & vec
) 
```

Substracts together two colors. 

### <span style="opacity:0.5;">function</span> <a id="334d957d" href="#334d957d">operator/</a>

```cpp
inline ffw::Color operator/ (
    const Color & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="d8c24713" href="#d8c24713">operator/=</a>

```cpp
inline ffw::Color & operator/= (
    const Color & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="0586de37" href="#0586de37">operator*</a>

```cpp
inline ffw::Color operator* (
    const Color & vec
) const 
```



### <span style="opacity:0.5;">function</span> <a id="446ed6a2" href="#446ed6a2">operator*=</a>

```cpp
inline ffw::Color & operator*= (
    const Color & vec
) 
```



### <span style="opacity:0.5;">function</span> <a id="234d4e26" href="#234d4e26">operator=</a>

```cpp
inline ffw::Color & operator= (
    const float & val
) 
```

Assigns same value to all RGBA components. 

### <span style="opacity:0.5;">function</span> <a id="d0f48049" href="#d0f48049">operator+</a>

```cpp
inline ffw::Color operator+ (
    const float & val
) const 
```

Adds value to all RGBA components, returning a copy. 

### <span style="opacity:0.5;">function</span> <a id="b7ca3a75" href="#b7ca3a75">operator+=</a>

```cpp
inline ffw::Color & operator+= (
    const float & val
) 
```

Adds value to all RGBA components. 

### <span style="opacity:0.5;">function</span> <a id="9b89cea0" href="#9b89cea0">operator-</a>

```cpp
inline ffw::Color operator- (
    const float & val
) const 
```

Substracts from all RGBA components, returning a copy. 

### <span style="opacity:0.5;">function</span> <a id="3eda6b73" href="#3eda6b73">operator-=</a>

```cpp
inline ffw::Color & operator-= (
    const float & val
) 
```

Substracts from all RGBA components. 

### <span style="opacity:0.5;">function</span> <a id="ed6eef31" href="#ed6eef31">operator/</a>

```cpp
inline ffw::Color operator/ (
    const float & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="7c828228" href="#7c828228">operator/=</a>

```cpp
inline ffw::Color & operator/= (
    const float & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="4df2d50f" href="#4df2d50f">operator*</a>

```cpp
inline ffw::Color operator* (
    const float & val
) const 
```



### <span style="opacity:0.5;">function</span> <a id="eef16604" href="#eef16604">operator*=</a>

```cpp
inline ffw::Color & operator*= (
    const float & val
) 
```



### <span style="opacity:0.5;">function</span> <a id="47c8bd75" href="#47c8bd75">operator!=</a>

```cpp
inline bool operator!= (
    const Color & vec
) const 
```

Checks if this instance is not equal to other one, using epsilon. 

### <span style="opacity:0.5;">function</span> <a id="f0ee3ebd" href="#f0ee3ebd">operator==</a>

```cpp
inline bool operator== (
    const Color & vec
) const 
```

Checks if this instance is equal to other one, using epsilon. 

### <span style="opacity:0.5;">function</span> <a id="ee136eb5" href="#ee136eb5">clamp</a>

```cpp
inline ffw::Color & clamp () 
```

Clamps all RGBA components so that all values are between 0.0 and 1.0. 

#### Details:
**note:** Does not perform a normalization! 


### <span style="opacity:0.5;">function</span> <a id="0720f90a" href="#0720f90a">normalize</a>

```cpp
inline ffw::Color & normalize () 
```

Normalises a color. 

#### Details:
**note:** [Color](ffw_Color.html) is treated as a 3D vector but alpha is ignored and clamped instead. 


### <span style="opacity:0.5;">function</span> <a id="58c9f4f0" href="#58c9f4f0">scale</a>

```cpp
inline ffw::Color & scale (
    const float val
) 
```

Scales all RGBA components with single value. 

### <span style="opacity:0.5;">function</span> <a id="52d2971e" href="#52d2971e">length</a>

```cpp
inline double length () const 
```

Returns the length of a vector (color is treated as a vector) 

### <span style="opacity:0.5;">function</span> <a id="006193c9" href="#006193c9">lengthf</a>

```cpp
inline float lengthf () const 
```

Returns the length of a vector (color is treated as a vector) 

### <span style="opacity:0.5;">function</span> <a id="093b3b39" href="#093b3b39">lengthSqrd</a>

```cpp
inline float lengthSqrd () const 
```

Returns the squared length of a vector (color is treated as a vector) 



