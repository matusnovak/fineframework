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
|   | [Color](#74212703) ()  _Default constructor, sets color to black with 0% alpha._ |
|   | [Color](#59951134) (float _red_, float _green_, float _blue_, float _alpha_)  _Construcor, sets the color based on the parameters._ |
|   | [Color](#91bbfd2b) (float _val_, float _alpha_)  _Constructor, sets the color to grayscale with alpha._ |
|   | [Color](#21db9079) (const [Color](ffw_Color.html) & _vec_)  _Copy Constructor._ |
|   | [Color](#f7ee4d25) (const std::initializer_list< float > & _list_)  _Construcor, sets the color from braced list of 4 floating point values._ |
|  void | [set](#a52bf2c2) (float _red_, float _green_, float _blue_, float _alpha_)  _Sets the color._ |
|  void | [set](#6c5c6e06) (float _val_, float _alpha_)  _Sets the color._ |
|  void | [set](#4d3a7723) (const [Color](ffw_Color.html) & _vec_)  _Sets the color from another color class._ |
|  void | [set](#a9b6485b) (const std::initializer_list< float > & _list_)  _Sets the color from a braced list of 4 floating point values._ |
|  [ffw::Color](ffw_Color.html) | [operator-](#cc3e2651) () const  _Performs unary minus operation on all r,g,b,a channels._ |
|  [ffw::Color](ffw_Color.html) & | [operator=](#e62cbff7) (const [Color](ffw_Color.html) & _vec_)  _Copies values from different color instance._ |
|  [ffw::Color](ffw_Color.html) | [operator+](#518ec544) (const [Color](ffw_Color.html) & _vec_) const  _Adds together two colors, returning a copy._ |
|  [ffw::Color](ffw_Color.html) & | [operator+=](#e68cbc6b) (const [Color](ffw_Color.html) & _vec_)  _Adds together two colors._ |
|  [ffw::Color](ffw_Color.html) | [operator-](#dc887d80) (const [Color](ffw_Color.html) & _vec_) const  _Substracts together two colors, returning a copy._ |
|  [ffw::Color](ffw_Color.html) & | [operator-=](#c53dfea1) (const [Color](ffw_Color.html) & _vec_)  _Substracts together two colors._ |
|  [ffw::Color](ffw_Color.html) | [operator/](#334d957d) (const [Color](ffw_Color.html) & _vec_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator/=](#d8c24713) (const [Color](ffw_Color.html) & _vec_)  |
|  [ffw::Color](ffw_Color.html) | [operator*](#0586de37) (const [Color](ffw_Color.html) & _vec_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator*=](#446ed6a2) (const [Color](ffw_Color.html) & _vec_)  |
|  [ffw::Color](ffw_Color.html) & | [operator=](#234d4e26) (const float & _val_)  _Assigns same value to all RGBA components._ |
|  [ffw::Color](ffw_Color.html) | [operator+](#d0f48049) (const float & _val_) const  _Adds value to all RGBA components, returning a copy._ |
|  [ffw::Color](ffw_Color.html) & | [operator+=](#b7ca3a75) (const float & _val_)  _Adds value to all RGBA components._ |
|  [ffw::Color](ffw_Color.html) | [operator-](#9b89cea0) (const float & _val_) const  _Substracts from all RGBA components, returning a copy._ |
|  [ffw::Color](ffw_Color.html) & | [operator-=](#3eda6b73) (const float & _val_)  _Substracts from all RGBA components._ |
|  [ffw::Color](ffw_Color.html) | [operator/](#ed6eef31) (const float & _val_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator/=](#7c828228) (const float & _val_)  |
|  [ffw::Color](ffw_Color.html) | [operator*](#4df2d50f) (const float & _val_) const  |
|  [ffw::Color](ffw_Color.html) & | [operator*=](#eef16604) (const float & _val_)  |
|  bool | [operator!=](#47c8bd75) (const [Color](ffw_Color.html) & _vec_) const  _Checks if this instance is not equal to other one, using epsilon._ |
|  bool | [operator==](#f0ee3ebd) (const [Color](ffw_Color.html) & _vec_) const  _Checks if this instance is equal to other one, using epsilon._ |
|  [ffw::Color](ffw_Color.html) & | [clamp](#ee136eb5) ()  _Clamps all RGBA components so that all values are between 0.0 and 1.0._ |
|  [ffw::Color](ffw_Color.html) & | [normalize](#0720f90a) ()  _Normalises a color._ |
|  [ffw::Color](ffw_Color.html) & | [scale](#58c9f4f0) (const float _val_)  _Scales all RGBA components with single value._ |
|  double | [length](#52d2971e) () const  _Returns the length of a vector (color is treated as a vector)_ |
|  float | [lengthf](#006193c9) () const  _Returns the length of a vector (color is treated as a vector)_ |
|  float | [lengthSqrd](#093b3b39) () const  _Returns the squared length of a vector (color is treated as a vector)_ |


## Public Attributes Documentation

### _variable_ <a id="de98d59f" href="#de98d59f">r</a>

```cpp
float r
```



### _variable_ <a id="f87a9edd" href="#f87a9edd">g</a>

```cpp
float g
```



### _variable_ <a id="d155be4f" href="#d155be4f">b</a>

```cpp
float b
```



### _variable_ <a id="ac8a0369" href="#ac8a0369">a</a>

```cpp
float a
```





## Public Functions Documentation

### _function_ <a id="74212703" href="#74212703">Color</a>

```cpp
inline  Color () 
```

Default constructor, sets color to black with 0% alpha. 

### _function_ <a id="59951134" href="#59951134">Color</a>

```cpp
inline  Color (
    float red,
    float green,
    float blue,
    float alpha
) 
```

Construcor, sets the color based on the parameters. 

### _function_ <a id="91bbfd2b" href="#91bbfd2b">Color</a>

```cpp
inline  Color (
    float val,
    float alpha
) 
```

Constructor, sets the color to grayscale with alpha. 

### _function_ <a id="21db9079" href="#21db9079">Color</a>

```cpp
inline  Color (
    const Color & vec
) 
```

Copy Constructor. 

### _function_ <a id="f7ee4d25" href="#f7ee4d25">Color</a>

```cpp
inline  Color (
    const std::initializer_list< float > & list
) 
```

Construcor, sets the color from braced list of 4 floating point values. 

### _function_ <a id="a52bf2c2" href="#a52bf2c2">set</a>

```cpp
inline void set (
    float red,
    float green,
    float blue,
    float alpha
) 
```

Sets the color. 

### _function_ <a id="6c5c6e06" href="#6c5c6e06">set</a>

```cpp
inline void set (
    float val,
    float alpha
) 
```

Sets the color. 

### _function_ <a id="4d3a7723" href="#4d3a7723">set</a>

```cpp
inline void set (
    const Color & vec
) 
```

Sets the color from another color class. 

### _function_ <a id="a9b6485b" href="#a9b6485b">set</a>

```cpp
inline void set (
    const std::initializer_list< float > & list
) 
```

Sets the color from a braced list of 4 floating point values. 

### _function_ <a id="cc3e2651" href="#cc3e2651">operator-</a>

```cpp
inline ffw::Color operator- () const 
```

Performs unary minus operation on all r,g,b,a channels. 

### _function_ <a id="e62cbff7" href="#e62cbff7">operator=</a>

```cpp
inline ffw::Color & operator= (
    const Color & vec
) 
```

Copies values from different color instance. 

### _function_ <a id="518ec544" href="#518ec544">operator+</a>

```cpp
inline ffw::Color operator+ (
    const Color & vec
) const 
```

Adds together two colors, returning a copy. 

### _function_ <a id="e68cbc6b" href="#e68cbc6b">operator+=</a>

```cpp
inline ffw::Color & operator+= (
    const Color & vec
) 
```

Adds together two colors. 

### _function_ <a id="dc887d80" href="#dc887d80">operator-</a>

```cpp
inline ffw::Color operator- (
    const Color & vec
) const 
```

Substracts together two colors, returning a copy. 

### _function_ <a id="c53dfea1" href="#c53dfea1">operator-=</a>

```cpp
inline ffw::Color & operator-= (
    const Color & vec
) 
```

Substracts together two colors. 

### _function_ <a id="334d957d" href="#334d957d">operator/</a>

```cpp
inline ffw::Color operator/ (
    const Color & vec
) const 
```



### _function_ <a id="d8c24713" href="#d8c24713">operator/=</a>

```cpp
inline ffw::Color & operator/= (
    const Color & vec
) 
```



### _function_ <a id="0586de37" href="#0586de37">operator*</a>

```cpp
inline ffw::Color operator* (
    const Color & vec
) const 
```



### _function_ <a id="446ed6a2" href="#446ed6a2">operator*=</a>

```cpp
inline ffw::Color & operator*= (
    const Color & vec
) 
```



### _function_ <a id="234d4e26" href="#234d4e26">operator=</a>

```cpp
inline ffw::Color & operator= (
    const float & val
) 
```

Assigns same value to all RGBA components. 

### _function_ <a id="d0f48049" href="#d0f48049">operator+</a>

```cpp
inline ffw::Color operator+ (
    const float & val
) const 
```

Adds value to all RGBA components, returning a copy. 

### _function_ <a id="b7ca3a75" href="#b7ca3a75">operator+=</a>

```cpp
inline ffw::Color & operator+= (
    const float & val
) 
```

Adds value to all RGBA components. 

### _function_ <a id="9b89cea0" href="#9b89cea0">operator-</a>

```cpp
inline ffw::Color operator- (
    const float & val
) const 
```

Substracts from all RGBA components, returning a copy. 

### _function_ <a id="3eda6b73" href="#3eda6b73">operator-=</a>

```cpp
inline ffw::Color & operator-= (
    const float & val
) 
```

Substracts from all RGBA components. 

### _function_ <a id="ed6eef31" href="#ed6eef31">operator/</a>

```cpp
inline ffw::Color operator/ (
    const float & val
) const 
```



### _function_ <a id="7c828228" href="#7c828228">operator/=</a>

```cpp
inline ffw::Color & operator/= (
    const float & val
) 
```



### _function_ <a id="4df2d50f" href="#4df2d50f">operator*</a>

```cpp
inline ffw::Color operator* (
    const float & val
) const 
```



### _function_ <a id="eef16604" href="#eef16604">operator*=</a>

```cpp
inline ffw::Color & operator*= (
    const float & val
) 
```



### _function_ <a id="47c8bd75" href="#47c8bd75">operator!=</a>

```cpp
inline bool operator!= (
    const Color & vec
) const 
```

Checks if this instance is not equal to other one, using epsilon. 

### _function_ <a id="f0ee3ebd" href="#f0ee3ebd">operator==</a>

```cpp
inline bool operator== (
    const Color & vec
) const 
```

Checks if this instance is equal to other one, using epsilon. 

### _function_ <a id="ee136eb5" href="#ee136eb5">clamp</a>

```cpp
inline ffw::Color & clamp () 
```

Clamps all RGBA components so that all values are between 0.0 and 1.0. 

**note:** Does not perform a normalization! 


### _function_ <a id="0720f90a" href="#0720f90a">normalize</a>

```cpp
inline ffw::Color & normalize () 
```

Normalises a color. 

**note:** [Color](ffw_Color.html) is treated as a 3D vector but alpha is ignored and clamped instead. 


### _function_ <a id="58c9f4f0" href="#58c9f4f0">scale</a>

```cpp
inline ffw::Color & scale (
    const float val
) 
```

Scales all RGBA components with single value. 

### _function_ <a id="52d2971e" href="#52d2971e">length</a>

```cpp
inline double length () const 
```

Returns the length of a vector (color is treated as a vector) 

### _function_ <a id="006193c9" href="#006193c9">lengthf</a>

```cpp
inline float lengthf () const 
```

Returns the length of a vector (color is treated as a vector) 

### _function_ <a id="093b3b39" href="#093b3b39">lengthSqrd</a>

```cpp
inline float lengthSqrd () const 
```

Returns the squared length of a vector (color is treated as a vector) 



