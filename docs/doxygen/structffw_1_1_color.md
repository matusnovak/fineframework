---
search: false
---

# struct ffw::Color

Class that holds floating point color, OpenGL friendly. [More...](#detailed-description)
## Public Attributes

|Type|Name|
|-----|-----|
|float|[**r**](structffw_1_1_color.md#1a4ea8fd4c534f9c6466a50d9f4dceb842)|
|float|[**g**](structffw_1_1_color.md#1a8974967f2291c8a15966736c5afbc8fe)|
|float|[**b**](structffw_1_1_color.md#1afd01fc018c4565e8a620bcaea6e8c699)|
|float|[**a**](structffw_1_1_color.md#1a79815481e8833d6b72b849bdf380f84c)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Color**](structffw_1_1_color.md#1af1f87ef12ea5a19ddecb97c72b8e6632) () <br>Default constructor, sets color to black with 0% alpha. |
||[**Color**](structffw_1_1_color.md#1a5f300b40fcc908da46d30855a020044d) (float red, float green, float blue, float alpha) <br>Construcor, sets the color based on the parameters. |
||[**Color**](structffw_1_1_color.md#1ab1d0451430d30b8a23c97ae87a505fdf) (float val, float alpha) <br>Constructor, sets the color to grayscale with alpha. |
||[**Color**](structffw_1_1_color.md#1adfffc900b1a9f79728823bc24ce518b3) (const **[Color](structffw_1_1_color.md)** & vec) <br>Copy Constructor. |
||[**Color**](structffw_1_1_color.md#1af50abf093e2aadb8f1f9b6fd37fd97c2) (const std::initializer\_list< float > & list) <br>Construcor, sets the color from braced list of 4 floating point values. |
|void|[**set**](structffw_1_1_color.md#1aea22e4076daf85b8296786d2732cee11) (float red, float green, float blue, float alpha) <br>Sets the color. |
|void|[**set**](structffw_1_1_color.md#1a9facc20aa59e32735738cbc1d0edf109) (float val, float alpha) <br>Sets the color. |
|void|[**set**](structffw_1_1_color.md#1a30bfdd9c040d4ad3dca93042765ef7c2) (const **[Color](structffw_1_1_color.md)** & vec) <br>Sets the color from another color class. |
|void|[**set**](structffw_1_1_color.md#1aa20d88a0e1b2c72c2b2612a49cae6dd5) (const std::initializer\_list< float > & list) <br>Sets the color from a braced list of 4 floating point values. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator-**](structffw_1_1_color.md#1a0678419e222719d3006502c5652baa57) () const <br>Performs unary minus operation on all r,g,b,a channels. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator=**](structffw_1_1_color.md#1a963378f50576c1c7611d9f3cb237e732) (const **[Color](structffw_1_1_color.md)** & vec) <br>Copies values from different color instance. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator+**](structffw_1_1_color.md#1a6f55bb1fcdba5505c52ef891409bc67c) (const **[Color](structffw_1_1_color.md)** & vec) const <br>Adds together two colors, returning a copy. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator+=**](structffw_1_1_color.md#1a5624288f83e972ba45620d1ff0ade0c2) (const **[Color](structffw_1_1_color.md)** & vec) <br>Adds together two colors. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator-**](structffw_1_1_color.md#1a57c3a12063bbe70d0d15b99b040bf4e7) (const **[Color](structffw_1_1_color.md)** & vec) const <br>Substracts together two colors, returning a copy. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator-=**](structffw_1_1_color.md#1ae6855372bce19ced6831f1c4f968341d) (const **[Color](structffw_1_1_color.md)** & vec) <br>Substracts together two colors. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator/**](structffw_1_1_color.md#1a62c665dd99da74fc303973d62e77c762) (const **[Color](structffw_1_1_color.md)** & vec) const |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator/=**](structffw_1_1_color.md#1a589b004ecd09ef8f012ec00db26113dd) (const **[Color](structffw_1_1_color.md)** & vec) |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator\***](structffw_1_1_color.md#1a8015250fa16402bb0e52232bfd539db9) (const **[Color](structffw_1_1_color.md)** & vec) const |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator\*=**](structffw_1_1_color.md#1a50cdc0555544242afa4718e939608e44) (const **[Color](structffw_1_1_color.md)** & vec) |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator=**](structffw_1_1_color.md#1aae56adce39c6db1467c05849e87a52d2) (const float & val) <br>Assigns same value to all RGBA components. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator+**](structffw_1_1_color.md#1a46f0c8a695db50cb8eaca78a171f7896) (const float & val) const <br>Adds value to all RGBA components, returning a copy. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator+=**](structffw_1_1_color.md#1afc385cf234c1e99b5f93e996caf6dde3) (const float & val) <br>Adds value to all RGBA components. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator-**](structffw_1_1_color.md#1a65aa3ad28f9276e64ce662d60a68c17e) (const float & val) const <br>Substracts from all RGBA components, returning a copy. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator-=**](structffw_1_1_color.md#1a21d01af172f70b6f976b2db9f2441b88) (const float & val) <br>Substracts from all RGBA components. |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator/**](structffw_1_1_color.md#1aff1587495b4a7c100c6643ef3a8423a6) (const float & val) const |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator/=**](structffw_1_1_color.md#1af97ce411be946d21e8dd7a5391330f0a) (const float & val) |
|**[ffw::Color](structffw_1_1_color.md)**|[**operator\***](structffw_1_1_color.md#1ad3fced2a2cb0552d0cc0712d2653fabe) (const float & val) const |
|**[ffw::Color](structffw_1_1_color.md)** &|[**operator\*=**](structffw_1_1_color.md#1a73b89ef20cc87f673305910e682232be) (const float & val) |
|bool|[**operator!=**](structffw_1_1_color.md#1a717aefaf8ed37bd507c8d08560ab625a) (const **[Color](structffw_1_1_color.md)** & vec) const <br>Checks if this instance is not equal to other one, using epsilon. |
|bool|[**operator==**](structffw_1_1_color.md#1aa2121e5089aeccfefe86971b15303cae) (const **[Color](structffw_1_1_color.md)** & vec) const <br>Checks if this instance is equal to other one, using epsilon. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**clamp**](structffw_1_1_color.md#1aee8eff94ef51f8c0452a268b5e9096ad) () <br>Clamps all RGBA components so that all values are between 0.0 and 1.0. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**normalize**](structffw_1_1_color.md#1a6cba1c5d856819ddd88c112cbb3e3f4c) () <br>Normalises a color. |
|**[ffw::Color](structffw_1_1_color.md)** &|[**scale**](structffw_1_1_color.md#1a28b202cae43ae88a352f819000c64f14) (const float val) <br>Scales all RGBA components with single value. |
|double|[**length**](structffw_1_1_color.md#1a36b27fc15253d9ef3741e4f8bd800bac) () const <br>Returns the length of a vector (color is treated as a vector) |
|float|[**lengthf**](structffw_1_1_color.md#1a5212bc495faf0366b5ff1ab8d0e4c79f) () const <br>Returns the length of a vector (color is treated as a vector) |
|float|[**lengthSqrd**](structffw_1_1_color.md#1adea495cd3d3c06e2e081e3337cc9ac82) () const <br>Returns the squared length of a vector (color is treated as a vector) |
|**[Color](structffw_1_1_color.md)**|[**inverted**](structffw_1_1_color.md#1a063115b331732399349a2cc2aebde9c5) () const <br>Returns the inverted R, G, and B components. |


## Detailed Description

You can use this class to represent any RGBA color and pass it to your OpenGL function. This class uses 4 floats to represent color combinations. For example, 100% red color is when r is set to 1.0f and all other (g, b, a) is set to 0.0. You can also use **[ffw::rgba](group__math_.md#ga4a1245bbbe390a0e3d721a3c93bb1200)** function to construct this class with less typing 

**See also:**

**[ffw::rgb](group__math_.md#ga23849e3547e37a5275f6e9d4af0e0948)**, **[ffw::rgba](group__math_.md#ga4a1245bbbe390a0e3d721a3c93bb1200)**, 



## Public Attributes Documentation

### variable <a id="1a4ea8fd4c534f9c6466a50d9f4dceb842" href="#1a4ea8fd4c534f9c6466a50d9f4dceb842">r</a>

```cpp
float ffw::Color::r;
```



### variable <a id="1a8974967f2291c8a15966736c5afbc8fe" href="#1a8974967f2291c8a15966736c5afbc8fe">g</a>

```cpp
float ffw::Color::g;
```



### variable <a id="1afd01fc018c4565e8a620bcaea6e8c699" href="#1afd01fc018c4565e8a620bcaea6e8c699">b</a>

```cpp
float ffw::Color::b;
```



### variable <a id="1a79815481e8833d6b72b849bdf380f84c" href="#1a79815481e8833d6b72b849bdf380f84c">a</a>

```cpp
float ffw::Color::a;
```



## Public Functions Documentation

### function <a id="1af1f87ef12ea5a19ddecb97c72b8e6632" href="#1af1f87ef12ea5a19ddecb97c72b8e6632">Color</a>

```cpp
ffw::Color::Color ()
```

Default constructor, sets color to black with 0% alpha. 


### function <a id="1a5f300b40fcc908da46d30855a020044d" href="#1a5f300b40fcc908da46d30855a020044d">Color</a>

```cpp
ffw::Color::Color (
    float red,
    float green,
    float blue,
    float alpha
)
```

Construcor, sets the color based on the parameters. 


### function <a id="1ab1d0451430d30b8a23c97ae87a505fdf" href="#1ab1d0451430d30b8a23c97ae87a505fdf">Color</a>

```cpp
ffw::Color::Color (
    float val,
    float alpha
)
```

Constructor, sets the color to grayscale with alpha. 


### function <a id="1adfffc900b1a9f79728823bc24ce518b3" href="#1adfffc900b1a9f79728823bc24ce518b3">Color</a>

```cpp
ffw::Color::Color (
    const Color & vec
)
```

Copy Constructor. 


### function <a id="1af50abf093e2aadb8f1f9b6fd37fd97c2" href="#1af50abf093e2aadb8f1f9b6fd37fd97c2">Color</a>

```cpp
ffw::Color::Color (
    const std::initializer_list< float > & list
)
```

Construcor, sets the color from braced list of 4 floating point values. 


### function <a id="1aea22e4076daf85b8296786d2732cee11" href="#1aea22e4076daf85b8296786d2732cee11">set</a>

```cpp
void ffw::Color::set (
    float red,
    float green,
    float blue,
    float alpha
)
```

Sets the color. 


### function <a id="1a9facc20aa59e32735738cbc1d0edf109" href="#1a9facc20aa59e32735738cbc1d0edf109">set</a>

```cpp
void ffw::Color::set (
    float val,
    float alpha
)
```

Sets the color. 


### function <a id="1a30bfdd9c040d4ad3dca93042765ef7c2" href="#1a30bfdd9c040d4ad3dca93042765ef7c2">set</a>

```cpp
void ffw::Color::set (
    const Color & vec
)
```

Sets the color from another color class. 


### function <a id="1aa20d88a0e1b2c72c2b2612a49cae6dd5" href="#1aa20d88a0e1b2c72c2b2612a49cae6dd5">set</a>

```cpp
void ffw::Color::set (
    const std::initializer_list< float > & list
)
```

Sets the color from a braced list of 4 floating point values. 


### function <a id="1a0678419e222719d3006502c5652baa57" href="#1a0678419e222719d3006502c5652baa57">operator-</a>

```cpp
ffw::Color ffw::Color::operator- () const
```

Performs unary minus operation on all r,g,b,a channels. 


### function <a id="1a963378f50576c1c7611d9f3cb237e732" href="#1a963378f50576c1c7611d9f3cb237e732">operator=</a>

```cpp
ffw::Color & ffw::Color::operator= (
    const Color & vec
)
```

Copies values from different color instance. 


### function <a id="1a6f55bb1fcdba5505c52ef891409bc67c" href="#1a6f55bb1fcdba5505c52ef891409bc67c">operator+</a>

```cpp
ffw::Color ffw::Color::operator+ (
    const Color & vec
) const
```

Adds together two colors, returning a copy. 


### function <a id="1a5624288f83e972ba45620d1ff0ade0c2" href="#1a5624288f83e972ba45620d1ff0ade0c2">operator+=</a>

```cpp
ffw::Color & ffw::Color::operator+= (
    const Color & vec
)
```

Adds together two colors. 


### function <a id="1a57c3a12063bbe70d0d15b99b040bf4e7" href="#1a57c3a12063bbe70d0d15b99b040bf4e7">operator-</a>

```cpp
ffw::Color ffw::Color::operator- (
    const Color & vec
) const
```

Substracts together two colors, returning a copy. 


### function <a id="1ae6855372bce19ced6831f1c4f968341d" href="#1ae6855372bce19ced6831f1c4f968341d">operator-=</a>

```cpp
ffw::Color & ffw::Color::operator-= (
    const Color & vec
)
```

Substracts together two colors. 


### function <a id="1a62c665dd99da74fc303973d62e77c762" href="#1a62c665dd99da74fc303973d62e77c762">operator/</a>

```cpp
ffw::Color ffw::Color::operator/ (
    const Color & vec
) const
```



### function <a id="1a589b004ecd09ef8f012ec00db26113dd" href="#1a589b004ecd09ef8f012ec00db26113dd">operator/=</a>

```cpp
ffw::Color & ffw::Color::operator/= (
    const Color & vec
)
```



### function <a id="1a8015250fa16402bb0e52232bfd539db9" href="#1a8015250fa16402bb0e52232bfd539db9">operator\*</a>

```cpp
ffw::Color ffw::Color::operator* (
    const Color & vec
) const
```



### function <a id="1a50cdc0555544242afa4718e939608e44" href="#1a50cdc0555544242afa4718e939608e44">operator\*=</a>

```cpp
ffw::Color & ffw::Color::operator*= (
    const Color & vec
)
```



### function <a id="1aae56adce39c6db1467c05849e87a52d2" href="#1aae56adce39c6db1467c05849e87a52d2">operator=</a>

```cpp
ffw::Color & ffw::Color::operator= (
    const float & val
)
```

Assigns same value to all RGBA components. 


### function <a id="1a46f0c8a695db50cb8eaca78a171f7896" href="#1a46f0c8a695db50cb8eaca78a171f7896">operator+</a>

```cpp
ffw::Color ffw::Color::operator+ (
    const float & val
) const
```

Adds value to all RGBA components, returning a copy. 


### function <a id="1afc385cf234c1e99b5f93e996caf6dde3" href="#1afc385cf234c1e99b5f93e996caf6dde3">operator+=</a>

```cpp
ffw::Color & ffw::Color::operator+= (
    const float & val
)
```

Adds value to all RGBA components. 


### function <a id="1a65aa3ad28f9276e64ce662d60a68c17e" href="#1a65aa3ad28f9276e64ce662d60a68c17e">operator-</a>

```cpp
ffw::Color ffw::Color::operator- (
    const float & val
) const
```

Substracts from all RGBA components, returning a copy. 


### function <a id="1a21d01af172f70b6f976b2db9f2441b88" href="#1a21d01af172f70b6f976b2db9f2441b88">operator-=</a>

```cpp
ffw::Color & ffw::Color::operator-= (
    const float & val
)
```

Substracts from all RGBA components. 


### function <a id="1aff1587495b4a7c100c6643ef3a8423a6" href="#1aff1587495b4a7c100c6643ef3a8423a6">operator/</a>

```cpp
ffw::Color ffw::Color::operator/ (
    const float & val
) const
```



### function <a id="1af97ce411be946d21e8dd7a5391330f0a" href="#1af97ce411be946d21e8dd7a5391330f0a">operator/=</a>

```cpp
ffw::Color & ffw::Color::operator/= (
    const float & val
)
```



### function <a id="1ad3fced2a2cb0552d0cc0712d2653fabe" href="#1ad3fced2a2cb0552d0cc0712d2653fabe">operator\*</a>

```cpp
ffw::Color ffw::Color::operator* (
    const float & val
) const
```



### function <a id="1a73b89ef20cc87f673305910e682232be" href="#1a73b89ef20cc87f673305910e682232be">operator\*=</a>

```cpp
ffw::Color & ffw::Color::operator*= (
    const float & val
)
```



### function <a id="1a717aefaf8ed37bd507c8d08560ab625a" href="#1a717aefaf8ed37bd507c8d08560ab625a">operator!=</a>

```cpp
bool ffw::Color::operator!= (
    const Color & vec
) const
```

Checks if this instance is not equal to other one, using epsilon. 


### function <a id="1aa2121e5089aeccfefe86971b15303cae" href="#1aa2121e5089aeccfefe86971b15303cae">operator==</a>

```cpp
bool ffw::Color::operator== (
    const Color & vec
) const
```

Checks if this instance is equal to other one, using epsilon. 


### function <a id="1aee8eff94ef51f8c0452a268b5e9096ad" href="#1aee8eff94ef51f8c0452a268b5e9096ad">clamp</a>

```cpp
ffw::Color & ffw::Color::clamp ()
```

Clamps all RGBA components so that all values are between 0.0 and 1.0. 



**Note:**

Does not perform a normalization! 




### function <a id="1a6cba1c5d856819ddd88c112cbb3e3f4c" href="#1a6cba1c5d856819ddd88c112cbb3e3f4c">normalize</a>

```cpp
ffw::Color & ffw::Color::normalize ()
```

Normalises a color. 



**Note:**

**[Color](structffw_1_1_color.md)** is treated as a 3D vector but alpha is ignored and clamped instead. 




### function <a id="1a28b202cae43ae88a352f819000c64f14" href="#1a28b202cae43ae88a352f819000c64f14">scale</a>

```cpp
ffw::Color & ffw::Color::scale (
    const float val
)
```

Scales all RGBA components with single value. 


### function <a id="1a36b27fc15253d9ef3741e4f8bd800bac" href="#1a36b27fc15253d9ef3741e4f8bd800bac">length</a>

```cpp
double ffw::Color::length () const
```

Returns the length of a vector (color is treated as a vector) 


### function <a id="1a5212bc495faf0366b5ff1ab8d0e4c79f" href="#1a5212bc495faf0366b5ff1ab8d0e4c79f">lengthf</a>

```cpp
float ffw::Color::lengthf () const
```

Returns the length of a vector (color is treated as a vector) 


### function <a id="1adea495cd3d3c06e2e081e3337cc9ac82" href="#1adea495cd3d3c06e2e081e3337cc9ac82">lengthSqrd</a>

```cpp
float ffw::Color::lengthSqrd () const
```

Returns the squared length of a vector (color is treated as a vector) 


### function <a id="1a063115b331732399349a2cc2aebde9c5" href="#1a063115b331732399349a2cc2aebde9c5">inverted</a>

```cpp
Color ffw::Color::inverted () const
```

Returns the inverted R, G, and B components. 




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/color.h`
