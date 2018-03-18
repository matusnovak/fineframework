math - Math functions and data types
===================================

From basic up to advanced math function and additional data types such as vectors, matrices, and more. 

## Detailed description

This module is header only, it does not need to be compiled, and is used by all modules listed here. Contains various math functions (calculating angles, creating model-view-projection matrices, colour management, UTF-8 to wide string conversion and back) and also provides several new types (2D, 3D, and 4D vectors, matrices, ring buffers, quaternions, and more). Uses third party library [utfcpp](https://github.com/nemtrif/utfcpp) 


## Classes

| Name |
|:-----|
| class [ffw::Any](ffw_Any.html) |
| class [ffw::Array](ffw_Array.html) |
| class [ffw::Object](ffw_Object.html) |
| struct [ffw::Color](ffw_Color.html) <span style="opacity:0.8;">Class that holds floating point color, OpenGL friendly. </span> |
| class [ffw::ImageFormat](ffw_ImageFormat.html) |
| class [ffw::ImageBuffer](ffw_ImageBuffer.html) |
| struct [ffw::Mat4x4](ffw_Mat4x4.html) |
| class [ffw::PromiseI](ffw_PromiseI.html) <span style="opacity:0.8;">Promise interface class. </span> |
| class [ffw::PromiseException](ffw_PromiseException.html) |
| class [ffw::PromiseResult](ffw_PromiseResult.html) |
| class [ffw::PromiseResult< void >](ffw_PromiseResult__void__.html) |
| class [ffw::Promise](ffw_Promise.html) <span style="opacity:0.8;">A simple promise class with chainable lambdas. </span> |
| struct [ffw::Quat](ffw_Quat.html) |
| class [ffw::RingBuffer](ffw_RingBuffer.html) |
| class [ffw::FileInfo](ffw_FileInfo.html) |
| class [ffw::TextWrapper](ffw_TextWrapper.html) |
| class [ffw::Tokenizer](ffw_Tokenizer.html) |
| struct [ffw::Vec2](ffw_Vec2.html) |
| struct [ffw::Vec3](ffw_Vec3.html) |
| struct [ffw::Vec4](ffw_Vec4.html) |


## Typedefs

| Type | Name |
| -------: | :------- |
| typedef Mat4x4< float > | [Mat4x4f](#029b468c) |
| typedef Quat< float > | [Quatf](#470579b4) |
| typedef Quat< double > | [Quatd](#308b855d) |
| typedef Vec2< float > | [Vec2f](#fcfaa6c5) |
| typedef Vec2< int > | [Vec2i](#e4e07ebe) |
| typedef Vec2< short > | [Vec2s](#e634c7d2) |
| typedef Vec2< long long > | [Vec2ll](#2879cf29) |
| typedef Vec2< double > | [Vec2d](#c75035bf) |
| typedef Vec3< float > | [Vec3f](#f1b9b946) |
| typedef Vec3< int > | [Vec3i](#1bc00754) |
| typedef Vec3< short > | [Vec3s](#5d1131e8) |
| typedef Vec3< long long > | [Vec3ll](#5920cd94) |
| typedef Vec3< double > | [Vec3d](#4a8d738f) |
| typedef Vec4< float > | [Vec4f](#397c4d39) |
| typedef Vec4< int > | [Vec4i](#fd5627df) |
| typedef Vec4< short > | [Vec4s](#1277dcdd) |
| typedef Vec4< long long > | [Vec4ll](#95297917) |
| typedef Vec4< double > | [Vec4d](#fcd214ba) |


## Functions

| Type | Name |
| -------: | :------- |
|  Color | [rgb](#e71e7885) (unsigned long _Hex_)  _Constructs ffw::Color from a hexadecimal value._ |
|  Color | [rgb](#e0f036d7) (unsigned char _Red_, unsigned char _Green_, unsigned char _Blue_)  _Constructs ffw::Color from three 8-bit balues._ |
|  Color | [rgba](#efcb64d9) (unsigned long _Hex_)  _Constructs ffw::Color from a hexadecimal value with alpha._ |
|  Color | [rgba](#e3f0f07c) (unsigned char _Red_, unsigned char _Green_, unsigned char _Blue_, unsigned char _Alpha_)  _Constructs ffw::Color from three 8-bit balues with alpha._ |
|  [ffw::Color](ffw_Color.html) | [normalize](#3ae66aa1) (const Color & _col_)  _Normalizes a color returning a copy (won't modify the original)_ |
|  [ffw::Color](ffw_Color.html) | [clamp](#a1534183) (const [ffw::Color](ffw_Color.html) & _color_)  _Clamps a color between 0.0 and 1.0 values returning a copy (won't modify the original)_ |
|  std::ostream & | [operator<<](#1b2c7668) (std::ostream & _os_, const [ffw::Color](ffw_Color.html) & _color_)  |
|  T | [clamp](#da694c2f) (T _Val_, T _Min_, T _Max_)  |
|  T | [lerp](#b7b7ad6f) (const T & _a_, const T & _b_, float _w_)  |
|  T | [radians](#98023008) (T _val_)  |
|  T | [degrees](#0e1d2d7d) (T _val_)  |
|  T | [remap](#e670592a) (T _value_, T _InMin_, T _InMax_, T _OutMin_, T _OutMax_)  |
|  unsigned long | [nextPowOfTwo](#1a601e83) (unsigned long _Value_)  |
|  unsigned short | [byteSwap16](#10b3f73f) (unsigned short _Value_)  |
|  unsigned long | [byteSwap32](#10a673f5) (unsigned long _Value_)  |
|  unsigned long long | [byteSwap64](#ce1909c1) (unsigned long long _Value_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [containImage](#f2841d25) (T _imgwidth_, T _imgheight_, T _maxwidth_, T _maxheight_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [coverImage](#63b8a91b) (T _imgwidth_, T _imgheight_, T _maxwidth_, T _maxheight_)  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > | [makeRotationMatrix](#3886b20d) (const [ffw::Quat](ffw_Quat.html)< T > & _Q_)  |
|  [ffw::Mat4x4](ffw_Mat4x4.html)< T > | [getRotationMatrix](#08c31028) (const [ffw::Mat4x4](ffw_Mat4x4.html)< T > & _other_)  |
|  Mat4x4< T > | [makeProjectionMatrix](#c6652302) (T _FieldOfView_, T _Aspect_, T _Near_, T _Far_)  |
|  Mat4x4< T > | [makeLookAtMatrix](#c9109de4) (const Vec3< T > & _Eyes_, const Vec3< T > & _Target_, const Vec3< T > & _UpVector_)  |
|  Mat4x4< T > | [makeFpsCameraMatrix](#834e22ad) (const Vec3< T > & _Eyes_, float _Pitch_, float _Yaw_)  |
|  Mat4x4< T > | [makeOrthoMatrix](#7a7a57ed) (T _left_, T _right_, T _bottom_, T _top_, T _znear_, T _zfar_)  |
|  [ffw::Quat](ffw_Quat.html)< T > | [normalize](#b5735179) (const Quat< T > & _Q_)  |
|  std::ostream & | [operator<<](#cb1ea679) (std::ostream & _os_, const [ffw::Quat](ffw_Quat.html)< T > & _quat_)  |
|  T | [stringToVal](#eebabb4c) (const std::string & _str_)  |
|  float | [stringToVal< float >](#d710d471) (const std::string & _Str_)  |
|  double | [stringToVal< double >](#fe64a60c) (const std::string & _Str_)  |
|  long double | [stringToVal< long double >](#40c43cfa) (const std::string & _Str_)  |
|  short | [stringToVal< short >](#7c63906d) (const std::string & _Str_)  |
|  int | [stringToVal< int >](#709a0897) (const std::string & _Str_)  |
|  long | [stringToVal< long >](#03bd4805) (const std::string & _Str_)  |
|  long long | [stringToVal< long long >](#36d9113e) (const std::string & _Str_)  |
|  unsigned short | [stringToVal< unsigned short >](#978b12f7) (const std::string & _Str_)  |
|  unsigned int | [stringToVal< unsigned int >](#9c213c9d) (const std::string & _Str_)  |
|  unsigned long | [stringToVal< unsigned long >](#f7a921ef) (const std::string & _Str_)  |
|  unsigned long long | [stringToVal< unsigned long long >](#d8cbf817) (const std::string & _Str_)  |
|  std::string | [valToString](#c771be1a) (T _Value_)  |
|  std::string | [valToString](#4904171a) (T _Value_, unsigned int _Dec_)  |
|  T | [hexToVal](#f2141293) (const std::string & _Str_)  |
|  std::string | [valToHex](#c79a8b0c) (const T & _Value_)  |
|  size_t | [getTokensFunc](#8cb6154f) (std::vector< std::basic_string< T, CharTrait, Allocator >> * _vec_, const std::basic_string< T, CharTrait, Allocator > & _str_, const std::basic_string< T, CharTrait, Allocator > & _delim_)  |
|  std::vector< std::string > | [getTokens](#07be8e2c) (const std::string & _str_, const std::string & _delim_)  |
|  std::vector< std::string > | [getTokens](#d3f38f16) (const std::string & _str_, char _delim_)  |
|  std::vector< std::wstring > | [getTokens](#164cf4d2) (const std::wstring & _str_, const std::wstring & _delim_)  |
|  std::vector< std::wstring > | [getTokens](#4e891034) (const std::wstring & _str_, wchar_t _delim_)  |
|  size_t | [getTokensNum](#3e329403) (const std::string & _str_, const std::string & _delim_)  |
|  size_t | [getTokensNum](#4198f64a) (const std::string & _str_, char _delim_)  |
|  size_t | [getTokensNum](#7cfe7afc) (const std::wstring & _str_, const std::wstring & _delim_)  |
|  size_t | [getTokensNum](#14c22b07) (const std::wstring & _str_, wchar_t _delim_)  |
|  FileInfo< std::basic_string< T, CharTrait, Allocator > > | [getFileInfo](#0391411c) (const std::basic_string< T, CharTrait, Allocator > & _path_)  |
|  std::string | [basename](#faaecb7e) (const std::basic_string< T, CharTrait, Allocator > & _path_)  |
|  std::string | [dirname](#b0d25873) (const std::basic_string< T, CharTrait, Allocator > & _path_)  |
|  std::string | [extension](#9c775320) (const std::basic_string< T, CharTrait, Allocator > & _path_)  |
|  std::string | [toUpper](#ba3ebc58) (const std::string & _str_)  |
|  std::string | [toLower](#ea42dc70) (const std::string & _str_)  |
|  std::string | [unicodeToUtf8](#89cc4a52) (uint32_t _chr_)  |
|  std::string | [wstrToUtf8](#e0a672bc) (const std::wstring & _wstr_)  |
|  size_t | [wstrToUtf8Size](#8252d46f) (const std::wstring & _wstr_)  |
|  std::wstring | [utf8ToWstr](#3b41c519) (const std::string & _str_)  |
|  size_t | [utf8ToWstrSize](#3c6051ab) (const std::string & _str_)  |
|  std::wstring | [valToWstring](#47ce4cde) (T _Value_)  |
|  std::wstring | [valToWstring](#b47de7bb) (T _Value_, unsigned int _Dec_)  |
|  uint32_t | [getNextChar](#40177abc) (const T *& _it_, const T * _end_)  |
|  uint32_t | [getNextChar](#959aa92f) (const char *& _it_, const char * _end_)  |
|  uint32_t | [getNextChar](#d06d5d33) (const wchar_t *& _it_, const wchar_t * _end_)  |
|  T | [dot](#71f5aa67) (const [ffw::Vec2](ffw_Vec2.html)< T > & _V1_, const [ffw::Vec2](ffw_Vec2.html)< T > & _V2_)  |
|  T | [distance](#c2f6a903) (const Vec2< T > & _v1_, const Vec2< T > & _v2_)  |
|  Vec2< T > | [middle](#8cc46fe8) (const Vec2< T > & _v1_, const Vec2< T > & _v2_)  |
|  [ffw::Vec2](ffw_Vec2.html)< T > | [normalize](#47e9bed1) (const Vec2< T > & _vec_)  |
|  double | [angle](#b81562f6) (const [ffw::Vec2](ffw_Vec2.html)< T > & _V1_, const [ffw::Vec2](ffw_Vec2.html)< T > & _V2_)  |
|  double | [angleRad](#117a45b2) (const [ffw::Vec2](ffw_Vec2.html)< T > & _V1_, const [ffw::Vec2](ffw_Vec2.html)< T > & _V2_)  |
|  std::ostream & | [operator<<](#1a605c92) (std::ostream & _os_, const [ffw::Vec2](ffw_Vec2.html)< T > & _vec_)  |
|  T | [dot](#aed5ec99) (const [ffw::Vec3](ffw_Vec3.html)< T > & _V1_, const [ffw::Vec3](ffw_Vec3.html)< T > & _V2_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [cross](#9aaaf389) (const [ffw::Vec3](ffw_Vec3.html)< T > & _V1_, const [ffw::Vec3](ffw_Vec3.html)< T > & _V2_)  |
|  T | [distance](#73ded03a) (const Vec3< T > & _v1_, const Vec3< T > & _v2_)  |
|  Vec3< T > | [middle](#da56ba98) (const Vec3< T > & _v1_, const Vec3< T > & _v2_)  |
|  [ffw::Vec3](ffw_Vec3.html)< T > | [normalize](#3ee634c6) (const Vec3< T > & _vec_)  |
|  double | [angle](#123633be) (const [ffw::Vec3](ffw_Vec3.html)< T > & _V1_, const [ffw::Vec3](ffw_Vec3.html)< T > & _V2_)  |
|  double | [angleRad](#bcf89547) (const [ffw::Vec3](ffw_Vec3.html)< T > & _V1_, const [ffw::Vec3](ffw_Vec3.html)< T > & _V2_)  |
|  std::ostream & | [operator<<](#d3be90fa) (std::ostream & _os_, const [ffw::Vec3](ffw_Vec3.html)< T > & _vec_)  |
|  T | [dot](#c12b1b16) (const [ffw::Vec4](ffw_Vec4.html)< T > & _V1_, const [ffw::Vec4](ffw_Vec4.html)< T > & _V2_)  |
|  T | [distance](#d7fe22b2) (const Vec4< T > & _v1_, const Vec4< T > & _v2_)  |
|  Vec4< T > | [middle](#544bc384) (const Vec4< T > & _v1_, const Vec4< T > & _v2_)  |
|  [ffw::Vec4](ffw_Vec4.html)< T > | [normalize](#57df09be) (const Vec4< T > & _vec_)  |
|  std::ostream & | [operator<<](#3bb35f81) (std::ostream & _os_, const [ffw::Vec4](ffw_Vec4.html)< T > & _vec_)  |
|  T | [dot](#8501b9a4) (const [ffw::Vec](ffw_Vec.html)< T, S > & _V1_, const [ffw::Vec](ffw_Vec.html)< T, S > & _V2_)  |
|  T | [distance](#3197c6d1) (const Vec< T, S > & _v1_, const Vec< T, S > & _v2_)  |
|  Vec< T, S > | [middle](#d95d58f5) (const Vec< T, S > & _v1_, const Vec< T, S > & _v2_)  |
|  [ffw::Vec](ffw_Vec.html)< T, S > | [normalize](#2413d268) (const Vec< T, S > & _vec_)  |
|  std::ostream & | [operator<<](#51221cac) (std::ostream & _os_, const [ffw::Vec](ffw_Vec.html)< T, S > & _vec_)  |


## Typedefs Documentation

### _typedef_ <a id="029b468c" href="#029b468c">Mat4x4f</a>

```cpp
Mat4x4< float > Mat4x4f
```



### _typedef_ <a id="470579b4" href="#470579b4">Quatf</a>

```cpp
Quat< float > Quatf
```



### _typedef_ <a id="308b855d" href="#308b855d">Quatd</a>

```cpp
Quat< double > Quatd
```



### _typedef_ <a id="fcfaa6c5" href="#fcfaa6c5">Vec2f</a>

```cpp
Vec2< float > Vec2f
```



### _typedef_ <a id="e4e07ebe" href="#e4e07ebe">Vec2i</a>

```cpp
Vec2< int > Vec2i
```



### _typedef_ <a id="e634c7d2" href="#e634c7d2">Vec2s</a>

```cpp
Vec2< short > Vec2s
```



### _typedef_ <a id="2879cf29" href="#2879cf29">Vec2ll</a>

```cpp
Vec2< long long > Vec2ll
```



### _typedef_ <a id="c75035bf" href="#c75035bf">Vec2d</a>

```cpp
Vec2< double > Vec2d
```



### _typedef_ <a id="f1b9b946" href="#f1b9b946">Vec3f</a>

```cpp
Vec3< float > Vec3f
```



### _typedef_ <a id="1bc00754" href="#1bc00754">Vec3i</a>

```cpp
Vec3< int > Vec3i
```



### _typedef_ <a id="5d1131e8" href="#5d1131e8">Vec3s</a>

```cpp
Vec3< short > Vec3s
```



### _typedef_ <a id="5920cd94" href="#5920cd94">Vec3ll</a>

```cpp
Vec3< long long > Vec3ll
```



### _typedef_ <a id="4a8d738f" href="#4a8d738f">Vec3d</a>

```cpp
Vec3< double > Vec3d
```



### _typedef_ <a id="397c4d39" href="#397c4d39">Vec4f</a>

```cpp
Vec4< float > Vec4f
```



### _typedef_ <a id="fd5627df" href="#fd5627df">Vec4i</a>

```cpp
Vec4< int > Vec4i
```



### _typedef_ <a id="1277dcdd" href="#1277dcdd">Vec4s</a>

```cpp
Vec4< short > Vec4s
```



### _typedef_ <a id="95297917" href="#95297917">Vec4ll</a>

```cpp
Vec4< long long > Vec4ll
```



### _typedef_ <a id="fcd214ba" href="#fcd214ba">Vec4d</a>

```cpp
Vec4< double > Vec4d
```





## Functions Documentation

### _function_ <a id="e71e7885" href="#e71e7885">rgb</a>

```cpp
inline Color rgb (
    unsigned long Hex
) 
```

Constructs [ffw::Color](ffw_Color.html) from a hexadecimal value. 

For example, ffw::rgb(0xFF0080) returns 100% red and 50% blue. Alpha is set to 100%. **warning:** Make sure to use 0xRRGGBB formula. For example, using 0xFF00 in this function would result of color with 0% red, 100% green, and 0% blue. Also, using 0xFF would result in complete blue color. 


### _function_ <a id="e0f036d7" href="#e0f036d7">rgb</a>

```cpp
inline Color rgb (
    unsigned char Red,
    unsigned char Green,
    unsigned char Blue
) 
```

Constructs [ffw::Color](ffw_Color.html) from three 8-bit balues. 

For example, ffw::rgb(255, 0, 128) returns 100% red and 50% blue. Alpha is set to 100%. 
### _function_ <a id="efcb64d9" href="#efcb64d9">rgba</a>

```cpp
inline Color rgba (
    unsigned long Hex
) 
```

Constructs [ffw::Color](ffw_Color.html) from a hexadecimal value with alpha. 

For example, ffw::rgba(0xFF0080BF) returns 100% red, 50% blue, and 80% alpha. **warning:** Make sure to use 0xRRGGBBAA formula. For example, using 0xFF0080 in this function would result of color with 0% red, 100% green, 0% blue, and 50% alpha. Also, using 0xFF would result in complete black color with 100% alpha. 


### _function_ <a id="e3f0f07c" href="#e3f0f07c">rgba</a>

```cpp
inline Color rgba (
    unsigned char Red,
    unsigned char Green,
    unsigned char Blue,
    unsigned char Alpha
) 
```

Constructs [ffw::Color](ffw_Color.html) from three 8-bit balues with alpha. 

For example, ffw::rgba(255, 0, 128, 191) returns 100% red, 50% blue, and 80% alpha. 
### _function_ <a id="3ae66aa1" href="#3ae66aa1">normalize</a>

```cpp
inline ffw::Color normalize (
    const Color & col
) 
```

Normalizes a color returning a copy (won't modify the original) 

### _function_ <a id="a1534183" href="#a1534183">clamp</a>

```cpp
inline ffw::Color clamp (
    const ffw::Color & color
) 
```

Clamps a color between 0.0 and 1.0 values returning a copy (won't modify the original) 

### _function_ <a id="1b2c7668" href="#1b2c7668">operator<<</a>

```cpp
inline std::ostream & operator<< (
    std::ostream & os,
    const ffw::Color & color
) 
```



### _function_ <a id="da694c2f" href="#da694c2f">clamp</a>

```cpp
inline T clamp (
    T Val,
    T Min,
    T Max
) 
```



### _function_ <a id="b7b7ad6f" href="#b7b7ad6f">lerp</a>

```cpp
inline T lerp (
    const T & a,
    const T & b,
    float w
) 
```



### _function_ <a id="98023008" href="#98023008">radians</a>

```cpp
inline T radians (
    T val
) 
```



### _function_ <a id="0e1d2d7d" href="#0e1d2d7d">degrees</a>

```cpp
inline T degrees (
    T val
) 
```



### _function_ <a id="e670592a" href="#e670592a">remap</a>

```cpp
inline T remap (
    T value,
    T InMin,
    T InMax,
    T OutMin,
    T OutMax
) 
```



### _function_ <a id="1a601e83" href="#1a601e83">nextPowOfTwo</a>

```cpp
inline unsigned long nextPowOfTwo (
    unsigned long Value
) 
```



### _function_ <a id="10b3f73f" href="#10b3f73f">byteSwap16</a>

```cpp
inline unsigned short byteSwap16 (
    unsigned short Value
) 
```



### _function_ <a id="10a673f5" href="#10a673f5">byteSwap32</a>

```cpp
inline unsigned long byteSwap32 (
    unsigned long Value
) 
```



### _function_ <a id="ce1909c1" href="#ce1909c1">byteSwap64</a>

```cpp
inline unsigned long long byteSwap64 (
    unsigned long long Value
) 
```



### _function_ <a id="f2841d25" href="#f2841d25">containImage</a>

```cpp
ffw::Vec4< T > containImage (
    T imgwidth,
    T imgheight,
    T maxwidth,
    T maxheight
) 
```



### _function_ <a id="63b8a91b" href="#63b8a91b">coverImage</a>

```cpp
ffw::Vec4< T > coverImage (
    T imgwidth,
    T imgheight,
    T maxwidth,
    T maxheight
) 
```



### _function_ <a id="3886b20d" href="#3886b20d">makeRotationMatrix</a>

```cpp
inline ffw::Mat4x4< T > makeRotationMatrix (
    const ffw::Quat< T > & Q
) 
```



### _function_ <a id="08c31028" href="#08c31028">getRotationMatrix</a>

```cpp
inline ffw::Mat4x4< T > getRotationMatrix (
    const ffw::Mat4x4< T > & other
) 
```



### _function_ <a id="c6652302" href="#c6652302">makeProjectionMatrix</a>

```cpp
Mat4x4< T > makeProjectionMatrix (
    T FieldOfView,
    T Aspect,
    T Near,
    T Far
) 
```



### _function_ <a id="c9109de4" href="#c9109de4">makeLookAtMatrix</a>

```cpp
Mat4x4< T > makeLookAtMatrix (
    const Vec3< T > & Eyes,
    const Vec3< T > & Target,
    const Vec3< T > & UpVector
) 
```



### _function_ <a id="834e22ad" href="#834e22ad">makeFpsCameraMatrix</a>

```cpp
Mat4x4< T > makeFpsCameraMatrix (
    const Vec3< T > & Eyes,
    float Pitch,
    float Yaw
) 
```



### _function_ <a id="7a7a57ed" href="#7a7a57ed">makeOrthoMatrix</a>

```cpp
Mat4x4< T > makeOrthoMatrix (
    T left,
    T right,
    T bottom,
    T top,
    T znear,
    T zfar
) 
```



### _function_ <a id="b5735179" href="#b5735179">normalize</a>

```cpp
inline ffw::Quat< T > normalize (
    const Quat< T > & Q
) 
```



### _function_ <a id="cb1ea679" href="#cb1ea679">operator<<</a>

```cpp
inline std::ostream & operator<< (
    std::ostream & os,
    const ffw::Quat< T > & quat
) 
```



### _function_ <a id="eebabb4c" href="#eebabb4c">stringToVal</a>

```cpp
inline T stringToVal (
    const std::string & str
) 
```



**Exceptions:**
* _Throws:_ std::invalid_argument (invalid conversion) or std::out_of_range (conversion is out of the range) 


### _function_ <a id="d710d471" href="#d710d471">stringToVal< float ></a>

```cpp
inline float stringToVal< float > (
    const std::string & Str
) 
```



### _function_ <a id="fe64a60c" href="#fe64a60c">stringToVal< double ></a>

```cpp
inline double stringToVal< double > (
    const std::string & Str
) 
```



### _function_ <a id="40c43cfa" href="#40c43cfa">stringToVal< long double ></a>

```cpp
inline long double stringToVal< long double > (
    const std::string & Str
) 
```



### _function_ <a id="7c63906d" href="#7c63906d">stringToVal< short ></a>

```cpp
inline short stringToVal< short > (
    const std::string & Str
) 
```



### _function_ <a id="709a0897" href="#709a0897">stringToVal< int ></a>

```cpp
inline int stringToVal< int > (
    const std::string & Str
) 
```



### _function_ <a id="03bd4805" href="#03bd4805">stringToVal< long ></a>

```cpp
inline long stringToVal< long > (
    const std::string & Str
) 
```



### _function_ <a id="36d9113e" href="#36d9113e">stringToVal< long long ></a>

```cpp
inline long long stringToVal< long long > (
    const std::string & Str
) 
```



### _function_ <a id="978b12f7" href="#978b12f7">stringToVal< unsigned short ></a>

```cpp
inline unsigned short stringToVal< unsigned short > (
    const std::string & Str
) 
```



### _function_ <a id="9c213c9d" href="#9c213c9d">stringToVal< unsigned int ></a>

```cpp
inline unsigned int stringToVal< unsigned int > (
    const std::string & Str
) 
```



### _function_ <a id="f7a921ef" href="#f7a921ef">stringToVal< unsigned long ></a>

```cpp
inline unsigned long stringToVal< unsigned long > (
    const std::string & Str
) 
```



### _function_ <a id="d8cbf817" href="#d8cbf817">stringToVal< unsigned long long ></a>

```cpp
inline unsigned long long stringToVal< unsigned long long > (
    const std::string & Str
) 
```



### _function_ <a id="c771be1a" href="#c771be1a">valToString</a>

```cpp
inline std::string valToString (
    T Value
) 
```



### _function_ <a id="4904171a" href="#4904171a">valToString</a>

```cpp
inline std::string valToString (
    T Value,
    unsigned int Dec
) 
```



### _function_ <a id="f2141293" href="#f2141293">hexToVal</a>

```cpp
inline T hexToVal (
    const std::string & Str
) 
```



### _function_ <a id="c79a8b0c" href="#c79a8b0c">valToHex</a>

```cpp
inline std::string valToHex (
    const T & Value
) 
```



### _function_ <a id="8cb6154f" href="#8cb6154f">getTokensFunc</a>

```cpp
size_t getTokensFunc (
    std::vector< std::basic_string< T, CharTrait, Allocator >> * vec,
    const std::basic_string< T, CharTrait, Allocator > & str,
    const std::basic_string< T, CharTrait, Allocator > & delim
) 
```



### _function_ <a id="07be8e2c" href="#07be8e2c">getTokens</a>

```cpp
inline std::vector< std::string > getTokens (
    const std::string & str,
    const std::string & delim
) 
```



### _function_ <a id="d3f38f16" href="#d3f38f16">getTokens</a>

```cpp
inline std::vector< std::string > getTokens (
    const std::string & str,
    char delim
) 
```



### _function_ <a id="164cf4d2" href="#164cf4d2">getTokens</a>

```cpp
inline std::vector< std::wstring > getTokens (
    const std::wstring & str,
    const std::wstring & delim
) 
```



### _function_ <a id="4e891034" href="#4e891034">getTokens</a>

```cpp
inline std::vector< std::wstring > getTokens (
    const std::wstring & str,
    wchar_t delim
) 
```



### _function_ <a id="3e329403" href="#3e329403">getTokensNum</a>

```cpp
inline size_t getTokensNum (
    const std::string & str,
    const std::string & delim
) 
```



### _function_ <a id="4198f64a" href="#4198f64a">getTokensNum</a>

```cpp
inline size_t getTokensNum (
    const std::string & str,
    char delim
) 
```



### _function_ <a id="7cfe7afc" href="#7cfe7afc">getTokensNum</a>

```cpp
inline size_t getTokensNum (
    const std::wstring & str,
    const std::wstring & delim
) 
```



### _function_ <a id="14c22b07" href="#14c22b07">getTokensNum</a>

```cpp
inline size_t getTokensNum (
    const std::wstring & str,
    wchar_t delim
) 
```



### _function_ <a id="0391411c" href="#0391411c">getFileInfo</a>

```cpp
FileInfo< std::basic_string< T, CharTrait, Allocator > > getFileInfo (
    const std::basic_string< T, CharTrait, Allocator > & path
) 
```



### _function_ <a id="faaecb7e" href="#faaecb7e">basename</a>

```cpp
std::string basename (
    const std::basic_string< T, CharTrait, Allocator > & path
) 
```



### _function_ <a id="b0d25873" href="#b0d25873">dirname</a>

```cpp
std::string dirname (
    const std::basic_string< T, CharTrait, Allocator > & path
) 
```



### _function_ <a id="9c775320" href="#9c775320">extension</a>

```cpp
std::string extension (
    const std::basic_string< T, CharTrait, Allocator > & path
) 
```



### _function_ <a id="ba3ebc58" href="#ba3ebc58">toUpper</a>

```cpp
inline std::string toUpper (
    const std::string & str
) 
```



### _function_ <a id="ea42dc70" href="#ea42dc70">toLower</a>

```cpp
inline std::string toLower (
    const std::string & str
) 
```



### _function_ <a id="89cc4a52" href="#89cc4a52">unicodeToUtf8</a>

```cpp
inline std::string unicodeToUtf8 (
    uint32_t chr
) 
```



### _function_ <a id="e0a672bc" href="#e0a672bc">wstrToUtf8</a>

```cpp
inline std::string wstrToUtf8 (
    const std::wstring & wstr
) 
```



### _function_ <a id="8252d46f" href="#8252d46f">wstrToUtf8Size</a>

```cpp
inline size_t wstrToUtf8Size (
    const std::wstring & wstr
) 
```



### _function_ <a id="3b41c519" href="#3b41c519">utf8ToWstr</a>

```cpp
inline std::wstring utf8ToWstr (
    const std::string & str
) 
```



### _function_ <a id="3c6051ab" href="#3c6051ab">utf8ToWstrSize</a>

```cpp
inline size_t utf8ToWstrSize (
    const std::string & str
) 
```



### _function_ <a id="47ce4cde" href="#47ce4cde">valToWstring</a>

```cpp
inline std::wstring valToWstring (
    T Value
) 
```



### _function_ <a id="b47de7bb" href="#b47de7bb">valToWstring</a>

```cpp
inline std::wstring valToWstring (
    T Value,
    unsigned int Dec
) 
```



### _function_ <a id="40177abc" href="#40177abc">getNextChar</a>

```cpp
inline uint32_t getNextChar (
    const T *& it,
    const T * end
) 
```



### _function_ <a id="959aa92f" href="#959aa92f">getNextChar</a>

```cpp
inline uint32_t getNextChar (
    const char *& it,
    const char * end
) 
```



### _function_ <a id="d06d5d33" href="#d06d5d33">getNextChar</a>

```cpp
inline uint32_t getNextChar (
    const wchar_t *& it,
    const wchar_t * end
) 
```



### _function_ <a id="71f5aa67" href="#71f5aa67">dot</a>

```cpp
inline T dot (
    const ffw::Vec2< T > & V1,
    const ffw::Vec2< T > & V2
) 
```



### _function_ <a id="c2f6a903" href="#c2f6a903">distance</a>

```cpp
inline T distance (
    const Vec2< T > & v1,
    const Vec2< T > & v2
) 
```



### _function_ <a id="8cc46fe8" href="#8cc46fe8">middle</a>

```cpp
inline Vec2< T > middle (
    const Vec2< T > & v1,
    const Vec2< T > & v2
) 
```



### _function_ <a id="47e9bed1" href="#47e9bed1">normalize</a>

```cpp
inline ffw::Vec2< T > normalize (
    const Vec2< T > & vec
) 
```



### _function_ <a id="b81562f6" href="#b81562f6">angle</a>

```cpp
inline double angle (
    const ffw::Vec2< T > & V1,
    const ffw::Vec2< T > & V2
) 
```



### _function_ <a id="117a45b2" href="#117a45b2">angleRad</a>

```cpp
inline double angleRad (
    const ffw::Vec2< T > & V1,
    const ffw::Vec2< T > & V2
) 
```



### _function_ <a id="1a605c92" href="#1a605c92">operator<<</a>

```cpp
inline std::ostream & operator<< (
    std::ostream & os,
    const ffw::Vec2< T > & vec
) 
```



### _function_ <a id="aed5ec99" href="#aed5ec99">dot</a>

```cpp
inline T dot (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
) 
```



### _function_ <a id="9aaaf389" href="#9aaaf389">cross</a>

```cpp
inline ffw::Vec3< T > cross (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
) 
```



### _function_ <a id="73ded03a" href="#73ded03a">distance</a>

```cpp
inline T distance (
    const Vec3< T > & v1,
    const Vec3< T > & v2
) 
```



### _function_ <a id="da56ba98" href="#da56ba98">middle</a>

```cpp
inline Vec3< T > middle (
    const Vec3< T > & v1,
    const Vec3< T > & v2
) 
```



### _function_ <a id="3ee634c6" href="#3ee634c6">normalize</a>

```cpp
inline ffw::Vec3< T > normalize (
    const Vec3< T > & vec
) 
```



### _function_ <a id="123633be" href="#123633be">angle</a>

```cpp
inline double angle (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
) 
```



### _function_ <a id="bcf89547" href="#bcf89547">angleRad</a>

```cpp
inline double angleRad (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
) 
```



### _function_ <a id="d3be90fa" href="#d3be90fa">operator<<</a>

```cpp
inline std::ostream & operator<< (
    std::ostream & os,
    const ffw::Vec3< T > & vec
) 
```



### _function_ <a id="c12b1b16" href="#c12b1b16">dot</a>

```cpp
inline T dot (
    const ffw::Vec4< T > & V1,
    const ffw::Vec4< T > & V2
) 
```



### _function_ <a id="d7fe22b2" href="#d7fe22b2">distance</a>

```cpp
inline T distance (
    const Vec4< T > & v1,
    const Vec4< T > & v2
) 
```



### _function_ <a id="544bc384" href="#544bc384">middle</a>

```cpp
inline Vec4< T > middle (
    const Vec4< T > & v1,
    const Vec4< T > & v2
) 
```



### _function_ <a id="57df09be" href="#57df09be">normalize</a>

```cpp
inline ffw::Vec4< T > normalize (
    const Vec4< T > & vec
) 
```



### _function_ <a id="3bb35f81" href="#3bb35f81">operator<<</a>

```cpp
inline std::ostream & operator<< (
    std::ostream & os,
    const ffw::Vec4< T > & vec
) 
```



### _function_ <a id="8501b9a4" href="#8501b9a4">dot</a>

```cpp
inline T dot (
    const ffw::Vec< T, S > & V1,
    const ffw::Vec< T, S > & V2
) 
```



### _function_ <a id="3197c6d1" href="#3197c6d1">distance</a>

```cpp
inline T distance (
    const Vec< T, S > & v1,
    const Vec< T, S > & v2
) 
```



### _function_ <a id="d95d58f5" href="#d95d58f5">middle</a>

```cpp
inline Vec< T, S > middle (
    const Vec< T, S > & v1,
    const Vec< T, S > & v2
) 
```



### _function_ <a id="2413d268" href="#2413d268">normalize</a>

```cpp
inline ffw::Vec< T, S > normalize (
    const Vec< T, S > & vec
) 
```



### _function_ <a id="51221cac" href="#51221cac">operator<<</a>

```cpp
inline std::ostream & operator<< (
    std::ostream & os,
    const ffw::Vec< T, S > & vec
) 
```





