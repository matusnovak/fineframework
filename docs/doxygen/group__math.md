---
search: false
---

# group math

From basic up to advanced math function and additional data types such as vectors, matrices, and more. [More...](#detailed-description)
## Classes

|Type|Name|
|-----|-----|
|class|[**ffw::Any**](classffw_1_1_any.md)|
|class|[**ffw::Array**](classffw_1_1_array.md)|
|class|[**ffw::Object**](classffw_1_1_object.md)|
|struct|[**ffw::Color**](structffw_1_1_color.md)|
|class|[**ffw::ImageFormat**](classffw_1_1_image_format.md)|
|class|[**ffw::ImageBuffer**](classffw_1_1_image_buffer.md)|
|struct|[**ffw::Mat4x4**](structffw_1_1_mat4x4.md)|
|class|[**ffw::PromiseInterface**](classffw_1_1_promise_interface.md)|
|class|[**ffw::PromiseException**](classffw_1_1_promise_exception.md)|
|class|[**ffw::Promise**](classffw_1_1_promise.md)|
|struct|[**ffw::Quat**](structffw_1_1_quat.md)|
|class|[**ffw::RingBuffer**](classffw_1_1_ring_buffer.md)|
|class|[**ffw::FileInfo**](classffw_1_1_file_info.md)|
|class|[**ffw::TextWrapper**](classffw_1_1_text_wrapper.md)|
|class|[**ffw::Tokenizer**](classffw_1_1_tokenizer.md)|
|struct|[**ffw::Vec2**](structffw_1_1_vec2.md)|
|struct|[**ffw::Vec3**](structffw_1_1_vec3.md)|
|struct|[**ffw::Vec4**](structffw_1_1_vec4.md)|


## Typedefs

|Type|Name|
|-----|-----|
|typedef Mat4x4< float >|[**Mat4x4f**](group__math_.md#gab671e957e1ab5adf76e6a93c1a382845)|
|typedef Quat< float >|[**Quatf**](group__math_.md#ga5c5fbc50c60251c052c94b7caf35790b)|
|typedef Quat< double >|[**Quatd**](group__math_.md#gac0f2ea66cdb01b61113598b4c6269e4e)|
|typedef Vec2< float >|[**Vec2f**](group__math_.md#ga44573357c25b7969b4391ca0ae427636)|
|typedef Vec2< int >|[**Vec2i**](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)|
|typedef Vec2< short >|[**Vec2s**](group__math_.md#ga31e3a08ac07c7cb58a983ac52997d04c)|
|typedef Vec2< long long >|[**Vec2ll**](group__math_.md#ga8804045100c01f29258ec6875f67cddd)|
|typedef Vec2< double >|[**Vec2d**](group__math_.md#gaba3a86e20858e1f03abb24a45f67f0da)|
|typedef Vec3< float >|[**Vec3f**](group__math_.md#ga50484cfc0427110bb2a8072649b021af)|
|typedef Vec3< int >|[**Vec3i**](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)|
|typedef Vec3< short >|[**Vec3s**](group__math_.md#gac2b9a8d484a2c5194d8851de0e270853)|
|typedef Vec3< long long >|[**Vec3ll**](group__math_.md#ga6209bdc0000253ad109353a07b29c1b0)|
|typedef Vec3< double >|[**Vec3d**](group__math_.md#ga2ca146e043d6ec51b863ec9c190cca4e)|
|typedef Vec4< float >|[**Vec4f**](group__math_.md#gaa695e6ed043ba7215ae5cdb452cba72f)|
|typedef Vec4< int >|[**Vec4i**](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)|
|typedef Vec4< short >|[**Vec4s**](group__math_.md#ga0f413f96f36977754b4d84cbf1ffed8b)|
|typedef Vec4< long long >|[**Vec4ll**](group__math_.md#gac61c013cf4478478d84e2952d9ffd994)|
|typedef Vec4< double >|[**Vec4d**](group__math_.md#gaa642302a9d47f7a7a62d7c9b1b65938c)|


## Functions

|Type|Name|
|-----|-----|
|Color|[**rgb**](group__math_.md#ga23849e3547e37a5275f6e9d4af0e0948) (unsigned long Hex) <br>Constructs **[ffw::Color](structffw_1_1_color.md)** from a hexadecimal value. |
|Color|[**rgb**](group__math_.md#ga8973dec4a8a0f09c025539e53f5a9977) (unsigned char Red, unsigned char Green, unsigned char Blue) <br>Constructs **[ffw::Color](structffw_1_1_color.md)** from three 8-bit balues. |
|Color|[**rgba**](group__math_.md#ga4a1245bbbe390a0e3d721a3c93bb1200) (unsigned long Hex) <br>Constructs **[ffw::Color](structffw_1_1_color.md)** from a hexadecimal value with alpha. |
|Color|[**rgba**](group__math_.md#ga2fb191a8ff350d6adde176128de0a2db) (unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) <br>Constructs **[ffw::Color](structffw_1_1_color.md)** from three 8-bit balues with alpha. |
|**[ffw::Color](structffw_1_1_color.md)**|[**normalize**](group__math_.md#gabc69a1bb30bbe34f78a558faccbd8657) (const Color & col) <br>Normalizes a color returning a copy (won't modify the original) |
|**[ffw::Color](structffw_1_1_color.md)**|[**clamp**](group__math_.md#ga7b2d747aec87da417e3750618962c9a7) (const **[ffw::Color](structffw_1_1_color.md)** & color) <br>Clamps a color between 0.0 and 1.0 values returning a copy (won't modify the original) |
|std::ostream &|[**operator<<**](group__math_.md#gadb1a887a1be9904a45a1870ef7d8f382) (std::ostream & os, const **[ffw::Color](structffw_1_1_color.md)** & color) |
|T|[**clamp**](group__math_.md#ga3bfc8e9f36aecf684954ae9a640a862c) (T Val, T Min, T Max) |
|T|[**lerp**](group__math_.md#ga89387935a07cfc6fcd97d030ad39856f) (const T & a, const T & b, float w) |
|T|[**radians**](group__math_.md#gaaee81fad9de4a063bc0fecc65216fdab) (T val) |
|T|[**degrees**](group__math_.md#ga3605496812ff4e949f8f31dd26fd9c53) (T val) |
|T|[**remap**](group__math_.md#gae12e3a7c35c01f5d7d98986d0d377d88) (T value, T InMin, T InMax, T OutMin, T OutMax) |
|unsigned long|[**nextPowOfTwo**](group__math_.md#ga1aca5d147b49da493839cde608997bf9) (unsigned long Value) |
|unsigned short|[**byteSwap16**](group__math_.md#gaaef6b8491ce9f2b5de15defd810753c1) (unsigned short Value) |
|unsigned long|[**byteSwap32**](group__math_.md#ga54d44fd37dacd7edc3b5110f17ecac6c) (unsigned long Value) |
|unsigned long long|[**byteSwap64**](group__math_.md#ga99ffa4725a3d53d87b4ac5962c8d66f6) (unsigned long long Value) |
|**[ffw::Vec4](structffw_1_1_vec4.md)**< T >|[**containImage**](group__math_.md#gadf9ac939242e14fce09bae91da1a3d78) (T imgwidth, T imgheight, T maxwidth, T maxheight) |
|**[ffw::Vec4](structffw_1_1_vec4.md)**< T >|[**coverImage**](group__math_.md#ga80e63c5d349b097a1ac065cbb78d5f34) (T imgwidth, T imgheight, T maxwidth, T maxheight) |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T >|[**makeRotationMatrix**](group__math_.md#ga4b620bc4d84a5095de6208c47ab85b8c) (const **[ffw::Quat](structffw_1_1_quat.md)**< T > & Q) |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T >|[**getRotationMatrix**](group__math_.md#ga0c67c4141c59c705d6742aa0e0415422) (const **[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > & other) |
|Mat4x4< T >|[**makeProjectionMatrix**](group__math_.md#ga093116a0e998121f8812336d53178bfb) (T FieldOfView, T Aspect, T Near, T Far) |
|Mat4x4< T >|[**makeLookAtMatrix**](group__math_.md#ga69d89caee5878ac8f4387289728b365d) (const Vec3< T > & Eyes, const Vec3< T > & Target, const Vec3< T > & UpVector) |
|Mat4x4< T >|[**makeFpsCameraMatrix**](group__math_.md#ga9b4c1a21520f9517a126af9f842896e7) (const Vec3< T > & Eyes, float Pitch, float Yaw) |
|Mat4x4< T >|[**makeOrthoMatrix**](group__math_.md#gaa4223b25c5b7378e425ab375260ea2ad) (T left, T right, T bottom, T top, T znear, T zfar) |
|**[ffw::Quat](structffw_1_1_quat.md)**< T >|[**normalize**](group__math_.md#gaec6c08a8c4391a8a9a1872f42b99232a) (const Quat< T > & Q) |
|std::ostream &|[**operator<<**](group__math_.md#gacfb8d763bbfc190efe04d7b42c6e531d) (std::ostream & os, const **[ffw::Quat](structffw_1_1_quat.md)**< T > & quat) |
|T|[**stringToVal**](group__math_.md#ga2ff4bfee8a2663b98766162bc8c00ccc) (const std::string & str) |
|float|[**stringToVal< float >**](group__math_.md#gaeac975c7b5ae332fed3de5833237b9b3) (const std::string & Str) |
|double|[**stringToVal< double >**](group__math_.md#gafe40cb539436abc33d1896b160d76554) (const std::string & Str) |
|long double|[**stringToVal< long double >**](group__math_.md#gaa56cad3cc623474f77c06a581d63b630) (const std::string & Str) |
|short|[**stringToVal< short >**](group__math_.md#gac97b724e1b8596ef1c68798d4fd0c608) (const std::string & Str) |
|int|[**stringToVal< int >**](group__math_.md#ga4f3e01c7e12df6677b75681941b32b30) (const std::string & Str) |
|long|[**stringToVal< long >**](group__math_.md#gabccd4b5222962384d6248b8c571bc7fc) (const std::string & Str) |
|long long|[**stringToVal< long long >**](group__math_.md#gaff1ce49835d3c5053815630c730f5ea7) (const std::string & Str) |
|unsigned short|[**stringToVal< unsigned short >**](group__math_.md#ga77838ae1490643409890adc2911c4261) (const std::string & Str) |
|unsigned int|[**stringToVal< unsigned int >**](group__math_.md#gaf8954547cb7495c5ba00035b6a610b77) (const std::string & Str) |
|unsigned long|[**stringToVal< unsigned long >**](group__math_.md#gaf82ff6cf1dcfdd58226e00b059cb3f21) (const std::string & Str) |
|unsigned long long|[**stringToVal< unsigned long long >**](group__math_.md#ga8c2dee9c89a9fb3ab8e175eef8f0a9bf) (const std::string & Str) |
|std::string|[**valToString**](group__math_.md#ga0c324b219570b6ec058ff4f2e982acdd) (T Value) |
|std::string|[**valToString**](group__math_.md#ga82d279a5f98699bb77ff307e160089df) (T Value, unsigned int Dec) |
|T|[**hexToVal**](group__math_.md#ga351156c52c279421816a905578862de8) (const std::string & Str) |
|std::string|[**valToHex**](group__math_.md#gaebc8f28ee8ab35ca46b57d86b95a9e39) (const T & Value) |
|size\_t|[**getTokensFunc**](group__math_.md#ga15a2514f69a546f3fac92f7c1c280ab0) (std::vector< std::basic\_string< T, CharTrait, Allocator >> \* vec, const std::basic\_string< T, CharTrait, Allocator > & str, const std::basic\_string< T, CharTrait, Allocator > & delim) |
|std::vector< std::string >|[**getTokens**](group__math_.md#ga4b43ef7e1fc970a912ffadb8c1b9e2a9) (const std::string & str, const std::string & delim) |
|std::vector< std::string >|[**getTokens**](group__math_.md#ga1bbfa5fe5f477f94049f554f303c9ccd) (const std::string & str, char delim) |
|std::vector< std::wstring >|[**getTokens**](group__math_.md#gaa5db012248a0f19fec64c202f6dd6b01) (const std::wstring & str, const std::wstring & delim) |
|std::vector< std::wstring >|[**getTokens**](group__math_.md#ga4569a193bb9dbb5d37b686318c7e1a26) (const std::wstring & str, wchar\_t delim) |
|size\_t|[**getTokensNum**](group__math_.md#ga10ee196b7313a531f518caa5d3acce27) (const std::string & str, const std::string & delim) |
|size\_t|[**getTokensNum**](group__math_.md#ga1bb826240bd167407a787d82aca1cf99) (const std::string & str, char delim) |
|size\_t|[**getTokensNum**](group__math_.md#gadac16be453663adf6294d4eee4bd20ee) (const std::wstring & str, const std::wstring & delim) |
|size\_t|[**getTokensNum**](group__math_.md#ga8c47cc665d17401c36534245137dc9eb) (const std::wstring & str, wchar\_t delim) |
|FileInfo< std::basic\_string< T, CharTrait, Allocator > >|[**getFileInfo**](group__math_.md#ga9a2dd9c982c0513e3d6d3b1132f91e3c) (const std::basic\_string< T, CharTrait, Allocator > & path) |
|std::string|[**basename**](group__math_.md#gaf582739c1c9cc3a8b0a9158969673ff9) (const std::basic\_string< T, CharTrait, Allocator > & path) |
|std::string|[**dirname**](group__math_.md#ga12751f27f4a3186f039626ba3804f189) (const std::basic\_string< T, CharTrait, Allocator > & path) |
|std::string|[**extension**](group__math_.md#ga2114703275d612eae345d082c71fa34a) (const std::basic\_string< T, CharTrait, Allocator > & path) |
|std::string|[**toUpper**](group__math_.md#ga72158648ccbc4e5d39228d22127daa1f) (const std::string & str) |
|std::string|[**toLower**](group__math_.md#ga4f964a4d674a4f427b9c856e4ae2094b) (const std::string & str) |
|std::string|[**unicodeToUtf8**](group__math_.md#ga8a167331ed4fcca7e2db86f24dfb3f18) (uint32\_t chr) |
|std::string|[**wstrToUtf8**](group__math_.md#ga079248c58a9fb437561ecfd652449492) (const std::wstring & wstr) |
|size\_t|[**wstrToUtf8Size**](group__math_.md#ga3b47148a08c91878e24c4de3de8aaa65) (const std::wstring & wstr) |
|std::wstring|[**utf8ToWstr**](group__math_.md#ga474fbf758ae9eca0a807629c8d6b2233) (const std::string & str) |
|size\_t|[**utf8ToWstrSize**](group__math_.md#ga692564f8dc1db8b2e66be991976a021c) (const std::string & str) |
|std::wstring|[**valToWstring**](group__math_.md#gac9a0231fee17d0b3bcfa6ba1a0399747) (T Value) |
|std::wstring|[**valToWstring**](group__math_.md#ga2668dc1f9d1f2efdbe3ed6e14757270b) (T Value, unsigned int Dec) |
|uint32\_t|[**getNextChar**](group__math_.md#ga6fb76dc97b45c29c8196864c4384b37a) (const T \*& it, const T \* end) |
|uint32\_t|[**getNextChar**](group__math_.md#ga1460ed3d538f8124ecc2b7930b14717d) (const char \*& it, const char \* end) |
|uint32\_t|[**getNextChar**](group__math_.md#ga4ab45f8258be6f6c816254f3253ee02f) (const wchar\_t \*& it, const wchar\_t \* end) |
|T|[**dot**](group__math_.md#gadd2af6c9a91a4a28c1bf37646a11fa54) (const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & V1, const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & V2) |
|T|[**distance**](group__math_.md#ga96f1d51c63fc87247632206bdc6aca93) (const Vec2< T > & v1, const Vec2< T > & v2) |
|Vec2< T >|[**middle**](group__math_.md#ga4355209b0efc738b4913602da57d8328) (const Vec2< T > & v1, const Vec2< T > & v2) |
|**[ffw::Vec2](structffw_1_1_vec2.md)**< T >|[**normalize**](group__math_.md#gaa7d9fe4a7e87ca5fc0e192dc7d52f77e) (const Vec2< T > & vec) |
|double|[**angle**](group__math_.md#gaedbc2ebdf8746a67ba453736492e4b61) (const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & V1, const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & V2) |
|double|[**angleRad**](group__math_.md#ga0b98b06298ec83aa179b241844fc841c) (const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & V1, const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & V2) |
|std::ostream &|[**operator<<**](group__math_.md#ga6abf760193050ca6e1eb7f7d61669d08) (std::ostream & os, const **[ffw::Vec2](structffw_1_1_vec2.md)**< T > & vec) |
|T|[**dot**](group__math_.md#gacbb105abbd17a95e94798a695863f885) (const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V1, const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V2) |
|**[ffw::Vec3](structffw_1_1_vec3.md)**< T >|[**cross**](group__math_.md#ga387f42cbfeaf813c9009998b9c38a8e2) (const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V1, const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V2) |
|T|[**distance**](group__math_.md#ga2610f00c257e4e2210c5f404f90bfa24) (const Vec3< T > & v1, const Vec3< T > & v2) |
|Vec3< T >|[**middle**](group__math_.md#ga4c7cffe6f277650490b347b05d764d83) (const Vec3< T > & v1, const Vec3< T > & v2) |
|**[ffw::Vec3](structffw_1_1_vec3.md)**< T >|[**normalize**](group__math_.md#gafd1cabd02c06cca28b13d7fa8d335546) (const Vec3< T > & vec) |
|double|[**angle**](group__math_.md#ga23a1976cd945644f200c012b70770a4b) (const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V1, const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V2) |
|double|[**angleRad**](group__math_.md#ga3082129383a0e8c14ab355506588cf8c) (const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V1, const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & V2) |
|std::ostream &|[**operator<<**](group__math_.md#gae9a61c1a91b743cda7a7df1133b792cd) (std::ostream & os, const **[ffw::Vec3](structffw_1_1_vec3.md)**< T > & vec) |
|T|[**dot**](group__math_.md#ga61d640dfefe7ae0d5f0dba41ce4d9088) (const **[ffw::Vec4](structffw_1_1_vec4.md)**< T > & V1, const **[ffw::Vec4](structffw_1_1_vec4.md)**< T > & V2) |
|T|[**distance**](group__math_.md#gaa638c1a0c2eb80a31759a38271a1badd) (const Vec4< T > & v1, const Vec4< T > & v2) |
|Vec4< T >|[**middle**](group__math_.md#gab162d6d5654c5fe8e4568e2a76bb7765) (const Vec4< T > & v1, const Vec4< T > & v2) |
|**[ffw::Vec4](structffw_1_1_vec4.md)**< T >|[**normalize**](group__math_.md#ga9e16c7a1c5f2be9554ddde94fd1a3f66) (const Vec4< T > & vec) |
|std::ostream &|[**operator<<**](group__math_.md#ga025f573b0ae85e151902eb6555b9e542) (std::ostream & os, const **[ffw::Vec4](structffw_1_1_vec4.md)**< T > & vec) |
|T|[**dot**](group__math_.md#gab2d2cff0ad36ea43c2e12159aca2913f) (const **[ffw::Vec](classffw_1_1_vec.md)**< T, S > & V1, const **[ffw::Vec](classffw_1_1_vec.md)**< T, S > & V2) |
|T|[**distance**](group__math_.md#gacb0fb790d2226fbe88db3bb47b411afc) (const Vec< T, S > & v1, const Vec< T, S > & v2) |
|Vec< T, S >|[**middle**](group__math_.md#gaa30cffe50165ce82aee52b6cd9d22073) (const Vec< T, S > & v1, const Vec< T, S > & v2) |
|**[ffw::Vec](classffw_1_1_vec.md)**< T, S >|[**normalize**](group__math_.md#ga0a9cc9a789a441ac96892c61bc9bbc35) (const Vec< T, S > & vec) |
|std::ostream &|[**operator<<**](group__math_.md#gaea8e4e15b76d5559b8d9abcf790a91d8) (std::ostream & os, const **[ffw::Vec](classffw_1_1_vec.md)**< T, S > & vec) |


## Detailed Description

This module is header only, it does not need to be compiled, and is used by all modules listed here. Contains various math functions (calculating angles, creating model-view-projection matrices, colour management, UTF-8 to wide string conversion and back) and also provides several new types (2D, 3D, and 4D vectors, matrices, ring buffers, quaternions, and more). Uses third party library [utfcpp](https://github.com/nemtrif/utfcpp) 
## Typedefs Documentation

### typedef <a id="gab671e957e1ab5adf76e6a93c1a382845" href="#gab671e957e1ab5adf76e6a93c1a382845">Mat4x4f</a>

```cpp
typedef Mat4x4<float> ffw::Mat4x4f;
```



### typedef <a id="ga5c5fbc50c60251c052c94b7caf35790b" href="#ga5c5fbc50c60251c052c94b7caf35790b">Quatf</a>

```cpp
typedef Quat<float> ffw::Quatf;
```



### typedef <a id="gac0f2ea66cdb01b61113598b4c6269e4e" href="#gac0f2ea66cdb01b61113598b4c6269e4e">Quatd</a>

```cpp
typedef Quat<double> ffw::Quatd;
```



### typedef <a id="ga44573357c25b7969b4391ca0ae427636" href="#ga44573357c25b7969b4391ca0ae427636">Vec2f</a>

```cpp
typedef Vec2<float> ffw::Vec2f;
```



### typedef <a id="ga8ac6bae8a24d96d0223a29ecfff14570" href="#ga8ac6bae8a24d96d0223a29ecfff14570">Vec2i</a>

```cpp
typedef Vec2<int> ffw::Vec2i;
```



### typedef <a id="ga31e3a08ac07c7cb58a983ac52997d04c" href="#ga31e3a08ac07c7cb58a983ac52997d04c">Vec2s</a>

```cpp
typedef Vec2<short> ffw::Vec2s;
```



### typedef <a id="ga8804045100c01f29258ec6875f67cddd" href="#ga8804045100c01f29258ec6875f67cddd">Vec2ll</a>

```cpp
typedef Vec2<long long> ffw::Vec2ll;
```



### typedef <a id="gaba3a86e20858e1f03abb24a45f67f0da" href="#gaba3a86e20858e1f03abb24a45f67f0da">Vec2d</a>

```cpp
typedef Vec2<double> ffw::Vec2d;
```



### typedef <a id="ga50484cfc0427110bb2a8072649b021af" href="#ga50484cfc0427110bb2a8072649b021af">Vec3f</a>

```cpp
typedef Vec3<float> ffw::Vec3f;
```



### typedef <a id="gafd4bb1ab82109f15d80681d443404df8" href="#gafd4bb1ab82109f15d80681d443404df8">Vec3i</a>

```cpp
typedef Vec3<int> ffw::Vec3i;
```



### typedef <a id="gac2b9a8d484a2c5194d8851de0e270853" href="#gac2b9a8d484a2c5194d8851de0e270853">Vec3s</a>

```cpp
typedef Vec3<short> ffw::Vec3s;
```



### typedef <a id="ga6209bdc0000253ad109353a07b29c1b0" href="#ga6209bdc0000253ad109353a07b29c1b0">Vec3ll</a>

```cpp
typedef Vec3<long long> ffw::Vec3ll;
```



### typedef <a id="ga2ca146e043d6ec51b863ec9c190cca4e" href="#ga2ca146e043d6ec51b863ec9c190cca4e">Vec3d</a>

```cpp
typedef Vec3<double> ffw::Vec3d;
```



### typedef <a id="gaa695e6ed043ba7215ae5cdb452cba72f" href="#gaa695e6ed043ba7215ae5cdb452cba72f">Vec4f</a>

```cpp
typedef Vec4<float> ffw::Vec4f;
```



### typedef <a id="ga3bd7b708561d6e2db0e66a1dd4177400" href="#ga3bd7b708561d6e2db0e66a1dd4177400">Vec4i</a>

```cpp
typedef Vec4<int> ffw::Vec4i;
```



### typedef <a id="ga0f413f96f36977754b4d84cbf1ffed8b" href="#ga0f413f96f36977754b4d84cbf1ffed8b">Vec4s</a>

```cpp
typedef Vec4<short> ffw::Vec4s;
```



### typedef <a id="gac61c013cf4478478d84e2952d9ffd994" href="#gac61c013cf4478478d84e2952d9ffd994">Vec4ll</a>

```cpp
typedef Vec4<long long> ffw::Vec4ll;
```



### typedef <a id="gaa642302a9d47f7a7a62d7c9b1b65938c" href="#gaa642302a9d47f7a7a62d7c9b1b65938c">Vec4d</a>

```cpp
typedef Vec4<double> ffw::Vec4d;
```



## Functions Documentation

### function <a id="ga23849e3547e37a5275f6e9d4af0e0948" href="#ga23849e3547e37a5275f6e9d4af0e0948">rgb</a>

```cpp
Color math::rgb (
    unsigned long Hex
)
```

Constructs **[ffw::Color](structffw_1_1_color.md)** from a hexadecimal value. 

For example, ffw::rgb(0xFF0080) returns 100% red and 50% blue. Alpha is set to 100%. 

**Warning:**

Make sure to use 0xRRGGBB formula. For example, using 0xFF00 in this function would result of color with 0% red, 100% green, and 0% blue. Also, using 0xFF would result in complete blue color. 




### function <a id="ga8973dec4a8a0f09c025539e53f5a9977" href="#ga8973dec4a8a0f09c025539e53f5a9977">rgb</a>

```cpp
Color math::rgb (
    unsigned char Red,
    unsigned char Green,
    unsigned char Blue
)
```

Constructs **[ffw::Color](structffw_1_1_color.md)** from three 8-bit balues. 

For example, ffw::rgb(255, 0, 128) returns 100% red and 50% blue. Alpha is set to 100%. 

### function <a id="ga4a1245bbbe390a0e3d721a3c93bb1200" href="#ga4a1245bbbe390a0e3d721a3c93bb1200">rgba</a>

```cpp
Color math::rgba (
    unsigned long Hex
)
```

Constructs **[ffw::Color](structffw_1_1_color.md)** from a hexadecimal value with alpha. 

For example, ffw::rgba(0xFF0080BF) returns 100% red, 50% blue, and 80% alpha. 

**Warning:**

Make sure to use 0xRRGGBBAA formula. For example, using 0xFF0080 in this function would result of color with 0% red, 100% green, 0% blue, and 50% alpha. Also, using 0xFF would result in complete black color with 100% alpha. 




### function <a id="ga2fb191a8ff350d6adde176128de0a2db" href="#ga2fb191a8ff350d6adde176128de0a2db">rgba</a>

```cpp
Color math::rgba (
    unsigned char Red,
    unsigned char Green,
    unsigned char Blue,
    unsigned char Alpha
)
```

Constructs **[ffw::Color](structffw_1_1_color.md)** from three 8-bit balues with alpha. 

For example, ffw::rgba(255, 0, 128, 191) returns 100% red, 50% blue, and 80% alpha. 

### function <a id="gabc69a1bb30bbe34f78a558faccbd8657" href="#gabc69a1bb30bbe34f78a558faccbd8657">normalize</a>

```cpp
ffw::Color math::normalize (
    const Color & col
)
```

Normalizes a color returning a copy (won't modify the original) 


### function <a id="ga7b2d747aec87da417e3750618962c9a7" href="#ga7b2d747aec87da417e3750618962c9a7">clamp</a>

```cpp
ffw::Color math::clamp (
    const ffw::Color & color
)
```

Clamps a color between 0.0 and 1.0 values returning a copy (won't modify the original) 


### function <a id="gadb1a887a1be9904a45a1870ef7d8f382" href="#gadb1a887a1be9904a45a1870ef7d8f382">operator<<</a>

```cpp
std::ostream & math::operator<< (
    std::ostream & os,
    const ffw::Color & color
)
```



### function <a id="ga3bfc8e9f36aecf684954ae9a640a862c" href="#ga3bfc8e9f36aecf684954ae9a640a862c">clamp</a>

```cpp
T math::clamp (
    T Val,
    T Min,
    T Max
)
```



### function <a id="ga89387935a07cfc6fcd97d030ad39856f" href="#ga89387935a07cfc6fcd97d030ad39856f">lerp</a>

```cpp
T math::lerp (
    const T & a,
    const T & b,
    float w
)
```



### function <a id="gaaee81fad9de4a063bc0fecc65216fdab" href="#gaaee81fad9de4a063bc0fecc65216fdab">radians</a>

```cpp
T math::radians (
    T val
)
```



### function <a id="ga3605496812ff4e949f8f31dd26fd9c53" href="#ga3605496812ff4e949f8f31dd26fd9c53">degrees</a>

```cpp
T math::degrees (
    T val
)
```



### function <a id="gae12e3a7c35c01f5d7d98986d0d377d88" href="#gae12e3a7c35c01f5d7d98986d0d377d88">remap</a>

```cpp
T math::remap (
    T value,
    T InMin,
    T InMax,
    T OutMin,
    T OutMax
)
```



### function <a id="ga1aca5d147b49da493839cde608997bf9" href="#ga1aca5d147b49da493839cde608997bf9">nextPowOfTwo</a>

```cpp
unsigned long math::nextPowOfTwo (
    unsigned long Value
)
```



### function <a id="gaaef6b8491ce9f2b5de15defd810753c1" href="#gaaef6b8491ce9f2b5de15defd810753c1">byteSwap16</a>

```cpp
unsigned short math::byteSwap16 (
    unsigned short Value
)
```



### function <a id="ga54d44fd37dacd7edc3b5110f17ecac6c" href="#ga54d44fd37dacd7edc3b5110f17ecac6c">byteSwap32</a>

```cpp
unsigned long math::byteSwap32 (
    unsigned long Value
)
```



### function <a id="ga99ffa4725a3d53d87b4ac5962c8d66f6" href="#ga99ffa4725a3d53d87b4ac5962c8d66f6">byteSwap64</a>

```cpp
unsigned long long math::byteSwap64 (
    unsigned long long Value
)
```



### function <a id="gadf9ac939242e14fce09bae91da1a3d78" href="#gadf9ac939242e14fce09bae91da1a3d78">containImage</a>

```cpp
ffw::Vec4< T > math::containImage (
    T imgwidth,
    T imgheight,
    T maxwidth,
    T maxheight
)
```



### function <a id="ga80e63c5d349b097a1ac065cbb78d5f34" href="#ga80e63c5d349b097a1ac065cbb78d5f34">coverImage</a>

```cpp
ffw::Vec4< T > math::coverImage (
    T imgwidth,
    T imgheight,
    T maxwidth,
    T maxheight
)
```



### function <a id="ga4b620bc4d84a5095de6208c47ab85b8c" href="#ga4b620bc4d84a5095de6208c47ab85b8c">makeRotationMatrix</a>

```cpp
ffw::Mat4x4< T > math::makeRotationMatrix (
    const ffw::Quat< T > & Q
)
```



### function <a id="ga0c67c4141c59c705d6742aa0e0415422" href="#ga0c67c4141c59c705d6742aa0e0415422">getRotationMatrix</a>

```cpp
ffw::Mat4x4< T > math::getRotationMatrix (
    const ffw::Mat4x4< T > & other
)
```



### function <a id="ga093116a0e998121f8812336d53178bfb" href="#ga093116a0e998121f8812336d53178bfb">makeProjectionMatrix</a>

```cpp
Mat4x4< T > math::makeProjectionMatrix (
    T FieldOfView,
    T Aspect,
    T Near,
    T Far
)
```



### function <a id="ga69d89caee5878ac8f4387289728b365d" href="#ga69d89caee5878ac8f4387289728b365d">makeLookAtMatrix</a>

```cpp
Mat4x4< T > math::makeLookAtMatrix (
    const Vec3< T > & Eyes,
    const Vec3< T > & Target,
    const Vec3< T > & UpVector
)
```



### function <a id="ga9b4c1a21520f9517a126af9f842896e7" href="#ga9b4c1a21520f9517a126af9f842896e7">makeFpsCameraMatrix</a>

```cpp
Mat4x4< T > math::makeFpsCameraMatrix (
    const Vec3< T > & Eyes,
    float Pitch,
    float Yaw
)
```



### function <a id="gaa4223b25c5b7378e425ab375260ea2ad" href="#gaa4223b25c5b7378e425ab375260ea2ad">makeOrthoMatrix</a>

```cpp
Mat4x4< T > math::makeOrthoMatrix (
    T left,
    T right,
    T bottom,
    T top,
    T znear,
    T zfar
)
```



### function <a id="gaec6c08a8c4391a8a9a1872f42b99232a" href="#gaec6c08a8c4391a8a9a1872f42b99232a">normalize</a>

```cpp
ffw::Quat< T > math::normalize (
    const Quat< T > & Q
)
```



### function <a id="gacfb8d763bbfc190efe04d7b42c6e531d" href="#gacfb8d763bbfc190efe04d7b42c6e531d">operator<<</a>

```cpp
std::ostream & math::operator<< (
    std::ostream & os,
    const ffw::Quat< T > & quat
)
```



### function <a id="ga2ff4bfee8a2663b98766162bc8c00ccc" href="#ga2ff4bfee8a2663b98766162bc8c00ccc">stringToVal</a>

```cpp
T math::stringToVal (
    const std::string & str
)
```




**Exception:**


* _Throws_ std::invalid\_argument (invalid conversion) or std::out\_of\_range (conversion is out of the range) 



### function <a id="gaeac975c7b5ae332fed3de5833237b9b3" href="#gaeac975c7b5ae332fed3de5833237b9b3">stringToVal< float ></a>

```cpp
float math::stringToVal< float > (
    const std::string & Str
)
```



### function <a id="gafe40cb539436abc33d1896b160d76554" href="#gafe40cb539436abc33d1896b160d76554">stringToVal< double ></a>

```cpp
double math::stringToVal< double > (
    const std::string & Str
)
```



### function <a id="gaa56cad3cc623474f77c06a581d63b630" href="#gaa56cad3cc623474f77c06a581d63b630">stringToVal< long double ></a>

```cpp
long double math::stringToVal< long double > (
    const std::string & Str
)
```



### function <a id="gac97b724e1b8596ef1c68798d4fd0c608" href="#gac97b724e1b8596ef1c68798d4fd0c608">stringToVal< short ></a>

```cpp
short math::stringToVal< short > (
    const std::string & Str
)
```



### function <a id="ga4f3e01c7e12df6677b75681941b32b30" href="#ga4f3e01c7e12df6677b75681941b32b30">stringToVal< int ></a>

```cpp
int math::stringToVal< int > (
    const std::string & Str
)
```



### function <a id="gabccd4b5222962384d6248b8c571bc7fc" href="#gabccd4b5222962384d6248b8c571bc7fc">stringToVal< long ></a>

```cpp
long math::stringToVal< long > (
    const std::string & Str
)
```



### function <a id="gaff1ce49835d3c5053815630c730f5ea7" href="#gaff1ce49835d3c5053815630c730f5ea7">stringToVal< long long ></a>

```cpp
long long math::stringToVal< long long > (
    const std::string & Str
)
```



### function <a id="ga77838ae1490643409890adc2911c4261" href="#ga77838ae1490643409890adc2911c4261">stringToVal< unsigned short ></a>

```cpp
unsigned short math::stringToVal< unsigned short > (
    const std::string & Str
)
```



### function <a id="gaf8954547cb7495c5ba00035b6a610b77" href="#gaf8954547cb7495c5ba00035b6a610b77">stringToVal< unsigned int ></a>

```cpp
unsigned int math::stringToVal< unsigned int > (
    const std::string & Str
)
```



### function <a id="gaf82ff6cf1dcfdd58226e00b059cb3f21" href="#gaf82ff6cf1dcfdd58226e00b059cb3f21">stringToVal< unsigned long ></a>

```cpp
unsigned long math::stringToVal< unsigned long > (
    const std::string & Str
)
```



### function <a id="ga8c2dee9c89a9fb3ab8e175eef8f0a9bf" href="#ga8c2dee9c89a9fb3ab8e175eef8f0a9bf">stringToVal< unsigned long long ></a>

```cpp
unsigned long long math::stringToVal< unsigned long long > (
    const std::string & Str
)
```



### function <a id="ga0c324b219570b6ec058ff4f2e982acdd" href="#ga0c324b219570b6ec058ff4f2e982acdd">valToString</a>

```cpp
std::string math::valToString (
    T Value
)
```



### function <a id="ga82d279a5f98699bb77ff307e160089df" href="#ga82d279a5f98699bb77ff307e160089df">valToString</a>

```cpp
std::string math::valToString (
    T Value,
    unsigned int Dec
)
```



### function <a id="ga351156c52c279421816a905578862de8" href="#ga351156c52c279421816a905578862de8">hexToVal</a>

```cpp
T math::hexToVal (
    const std::string & Str
)
```



### function <a id="gaebc8f28ee8ab35ca46b57d86b95a9e39" href="#gaebc8f28ee8ab35ca46b57d86b95a9e39">valToHex</a>

```cpp
std::string math::valToHex (
    const T & Value
)
```



### function <a id="ga15a2514f69a546f3fac92f7c1c280ab0" href="#ga15a2514f69a546f3fac92f7c1c280ab0">getTokensFunc</a>

```cpp
size_t math::getTokensFunc (
    std::vector< std::basic_string< T, CharTrait, Allocator >> * vec,
    const std::basic_string< T, CharTrait, Allocator > & str,
    const std::basic_string< T, CharTrait, Allocator > & delim
)
```



### function <a id="ga4b43ef7e1fc970a912ffadb8c1b9e2a9" href="#ga4b43ef7e1fc970a912ffadb8c1b9e2a9">getTokens</a>

```cpp
std::vector< std::string > math::getTokens (
    const std::string & str,
    const std::string & delim
)
```



### function <a id="ga1bbfa5fe5f477f94049f554f303c9ccd" href="#ga1bbfa5fe5f477f94049f554f303c9ccd">getTokens</a>

```cpp
std::vector< std::string > math::getTokens (
    const std::string & str,
    char delim
)
```



### function <a id="gaa5db012248a0f19fec64c202f6dd6b01" href="#gaa5db012248a0f19fec64c202f6dd6b01">getTokens</a>

```cpp
std::vector< std::wstring > math::getTokens (
    const std::wstring & str,
    const std::wstring & delim
)
```



### function <a id="ga4569a193bb9dbb5d37b686318c7e1a26" href="#ga4569a193bb9dbb5d37b686318c7e1a26">getTokens</a>

```cpp
std::vector< std::wstring > math::getTokens (
    const std::wstring & str,
    wchar_t delim
)
```



### function <a id="ga10ee196b7313a531f518caa5d3acce27" href="#ga10ee196b7313a531f518caa5d3acce27">getTokensNum</a>

```cpp
size_t math::getTokensNum (
    const std::string & str,
    const std::string & delim
)
```



### function <a id="ga1bb826240bd167407a787d82aca1cf99" href="#ga1bb826240bd167407a787d82aca1cf99">getTokensNum</a>

```cpp
size_t math::getTokensNum (
    const std::string & str,
    char delim
)
```



### function <a id="gadac16be453663adf6294d4eee4bd20ee" href="#gadac16be453663adf6294d4eee4bd20ee">getTokensNum</a>

```cpp
size_t math::getTokensNum (
    const std::wstring & str,
    const std::wstring & delim
)
```



### function <a id="ga8c47cc665d17401c36534245137dc9eb" href="#ga8c47cc665d17401c36534245137dc9eb">getTokensNum</a>

```cpp
size_t math::getTokensNum (
    const std::wstring & str,
    wchar_t delim
)
```



### function <a id="ga9a2dd9c982c0513e3d6d3b1132f91e3c" href="#ga9a2dd9c982c0513e3d6d3b1132f91e3c">getFileInfo</a>

```cpp
FileInfo< std::basic_string< T, CharTrait, Allocator > > math::getFileInfo (
    const std::basic_string< T, CharTrait, Allocator > & path
)
```



### function <a id="gaf582739c1c9cc3a8b0a9158969673ff9" href="#gaf582739c1c9cc3a8b0a9158969673ff9">basename</a>

```cpp
std::string math::basename (
    const std::basic_string< T, CharTrait, Allocator > & path
)
```



### function <a id="ga12751f27f4a3186f039626ba3804f189" href="#ga12751f27f4a3186f039626ba3804f189">dirname</a>

```cpp
std::string math::dirname (
    const std::basic_string< T, CharTrait, Allocator > & path
)
```



### function <a id="ga2114703275d612eae345d082c71fa34a" href="#ga2114703275d612eae345d082c71fa34a">extension</a>

```cpp
std::string math::extension (
    const std::basic_string< T, CharTrait, Allocator > & path
)
```



### function <a id="ga72158648ccbc4e5d39228d22127daa1f" href="#ga72158648ccbc4e5d39228d22127daa1f">toUpper</a>

```cpp
std::string math::toUpper (
    const std::string & str
)
```



### function <a id="ga4f964a4d674a4f427b9c856e4ae2094b" href="#ga4f964a4d674a4f427b9c856e4ae2094b">toLower</a>

```cpp
std::string math::toLower (
    const std::string & str
)
```



### function <a id="ga8a167331ed4fcca7e2db86f24dfb3f18" href="#ga8a167331ed4fcca7e2db86f24dfb3f18">unicodeToUtf8</a>

```cpp
std::string math::unicodeToUtf8 (
    uint32_t chr
)
```



### function <a id="ga079248c58a9fb437561ecfd652449492" href="#ga079248c58a9fb437561ecfd652449492">wstrToUtf8</a>

```cpp
std::string math::wstrToUtf8 (
    const std::wstring & wstr
)
```



### function <a id="ga3b47148a08c91878e24c4de3de8aaa65" href="#ga3b47148a08c91878e24c4de3de8aaa65">wstrToUtf8Size</a>

```cpp
size_t math::wstrToUtf8Size (
    const std::wstring & wstr
)
```



### function <a id="ga474fbf758ae9eca0a807629c8d6b2233" href="#ga474fbf758ae9eca0a807629c8d6b2233">utf8ToWstr</a>

```cpp
std::wstring math::utf8ToWstr (
    const std::string & str
)
```



### function <a id="ga692564f8dc1db8b2e66be991976a021c" href="#ga692564f8dc1db8b2e66be991976a021c">utf8ToWstrSize</a>

```cpp
size_t math::utf8ToWstrSize (
    const std::string & str
)
```



### function <a id="gac9a0231fee17d0b3bcfa6ba1a0399747" href="#gac9a0231fee17d0b3bcfa6ba1a0399747">valToWstring</a>

```cpp
std::wstring math::valToWstring (
    T Value
)
```



### function <a id="ga2668dc1f9d1f2efdbe3ed6e14757270b" href="#ga2668dc1f9d1f2efdbe3ed6e14757270b">valToWstring</a>

```cpp
std::wstring math::valToWstring (
    T Value,
    unsigned int Dec
)
```



### function <a id="ga6fb76dc97b45c29c8196864c4384b37a" href="#ga6fb76dc97b45c29c8196864c4384b37a">getNextChar</a>

```cpp
uint32_t math::getNextChar (
    const T *& it,
    const T * end
)
```



### function <a id="ga1460ed3d538f8124ecc2b7930b14717d" href="#ga1460ed3d538f8124ecc2b7930b14717d">getNextChar</a>

```cpp
uint32_t math::getNextChar (
    const char *& it,
    const char * end
)
```



### function <a id="ga4ab45f8258be6f6c816254f3253ee02f" href="#ga4ab45f8258be6f6c816254f3253ee02f">getNextChar</a>

```cpp
uint32_t math::getNextChar (
    const wchar_t *& it,
    const wchar_t * end
)
```



### function <a id="gadd2af6c9a91a4a28c1bf37646a11fa54" href="#gadd2af6c9a91a4a28c1bf37646a11fa54">dot</a>

```cpp
T math::dot (
    const ffw::Vec2< T > & V1,
    const ffw::Vec2< T > & V2
)
```



### function <a id="ga96f1d51c63fc87247632206bdc6aca93" href="#ga96f1d51c63fc87247632206bdc6aca93">distance</a>

```cpp
T math::distance (
    const Vec2< T > & v1,
    const Vec2< T > & v2
)
```



### function <a id="ga4355209b0efc738b4913602da57d8328" href="#ga4355209b0efc738b4913602da57d8328">middle</a>

```cpp
Vec2< T > math::middle (
    const Vec2< T > & v1,
    const Vec2< T > & v2
)
```



### function <a id="gaa7d9fe4a7e87ca5fc0e192dc7d52f77e" href="#gaa7d9fe4a7e87ca5fc0e192dc7d52f77e">normalize</a>

```cpp
ffw::Vec2< T > math::normalize (
    const Vec2< T > & vec
)
```



### function <a id="gaedbc2ebdf8746a67ba453736492e4b61" href="#gaedbc2ebdf8746a67ba453736492e4b61">angle</a>

```cpp
double math::angle (
    const ffw::Vec2< T > & V1,
    const ffw::Vec2< T > & V2
)
```



### function <a id="ga0b98b06298ec83aa179b241844fc841c" href="#ga0b98b06298ec83aa179b241844fc841c">angleRad</a>

```cpp
double math::angleRad (
    const ffw::Vec2< T > & V1,
    const ffw::Vec2< T > & V2
)
```



### function <a id="ga6abf760193050ca6e1eb7f7d61669d08" href="#ga6abf760193050ca6e1eb7f7d61669d08">operator<<</a>

```cpp
std::ostream & math::operator<< (
    std::ostream & os,
    const ffw::Vec2< T > & vec
)
```



### function <a id="gacbb105abbd17a95e94798a695863f885" href="#gacbb105abbd17a95e94798a695863f885">dot</a>

```cpp
T math::dot (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
)
```



### function <a id="ga387f42cbfeaf813c9009998b9c38a8e2" href="#ga387f42cbfeaf813c9009998b9c38a8e2">cross</a>

```cpp
ffw::Vec3< T > math::cross (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
)
```



### function <a id="ga2610f00c257e4e2210c5f404f90bfa24" href="#ga2610f00c257e4e2210c5f404f90bfa24">distance</a>

```cpp
T math::distance (
    const Vec3< T > & v1,
    const Vec3< T > & v2
)
```



### function <a id="ga4c7cffe6f277650490b347b05d764d83" href="#ga4c7cffe6f277650490b347b05d764d83">middle</a>

```cpp
Vec3< T > math::middle (
    const Vec3< T > & v1,
    const Vec3< T > & v2
)
```



### function <a id="gafd1cabd02c06cca28b13d7fa8d335546" href="#gafd1cabd02c06cca28b13d7fa8d335546">normalize</a>

```cpp
ffw::Vec3< T > math::normalize (
    const Vec3< T > & vec
)
```



### function <a id="ga23a1976cd945644f200c012b70770a4b" href="#ga23a1976cd945644f200c012b70770a4b">angle</a>

```cpp
double math::angle (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
)
```



### function <a id="ga3082129383a0e8c14ab355506588cf8c" href="#ga3082129383a0e8c14ab355506588cf8c">angleRad</a>

```cpp
double math::angleRad (
    const ffw::Vec3< T > & V1,
    const ffw::Vec3< T > & V2
)
```



### function <a id="gae9a61c1a91b743cda7a7df1133b792cd" href="#gae9a61c1a91b743cda7a7df1133b792cd">operator<<</a>

```cpp
std::ostream & math::operator<< (
    std::ostream & os,
    const ffw::Vec3< T > & vec
)
```



### function <a id="ga61d640dfefe7ae0d5f0dba41ce4d9088" href="#ga61d640dfefe7ae0d5f0dba41ce4d9088">dot</a>

```cpp
T math::dot (
    const ffw::Vec4< T > & V1,
    const ffw::Vec4< T > & V2
)
```



### function <a id="gaa638c1a0c2eb80a31759a38271a1badd" href="#gaa638c1a0c2eb80a31759a38271a1badd">distance</a>

```cpp
T math::distance (
    const Vec4< T > & v1,
    const Vec4< T > & v2
)
```



### function <a id="gab162d6d5654c5fe8e4568e2a76bb7765" href="#gab162d6d5654c5fe8e4568e2a76bb7765">middle</a>

```cpp
Vec4< T > math::middle (
    const Vec4< T > & v1,
    const Vec4< T > & v2
)
```



### function <a id="ga9e16c7a1c5f2be9554ddde94fd1a3f66" href="#ga9e16c7a1c5f2be9554ddde94fd1a3f66">normalize</a>

```cpp
ffw::Vec4< T > math::normalize (
    const Vec4< T > & vec
)
```



### function <a id="ga025f573b0ae85e151902eb6555b9e542" href="#ga025f573b0ae85e151902eb6555b9e542">operator<<</a>

```cpp
std::ostream & math::operator<< (
    std::ostream & os,
    const ffw::Vec4< T > & vec
)
```



### function <a id="gab2d2cff0ad36ea43c2e12159aca2913f" href="#gab2d2cff0ad36ea43c2e12159aca2913f">dot</a>

```cpp
T math::dot (
    const ffw::Vec< T, S > & V1,
    const ffw::Vec< T, S > & V2
)
```



### function <a id="gacb0fb790d2226fbe88db3bb47b411afc" href="#gacb0fb790d2226fbe88db3bb47b411afc">distance</a>

```cpp
T math::distance (
    const Vec< T, S > & v1,
    const Vec< T, S > & v2
)
```



### function <a id="gaa30cffe50165ce82aee52b6cd9d22073" href="#gaa30cffe50165ce82aee52b6cd9d22073">middle</a>

```cpp
Vec< T, S > math::middle (
    const Vec< T, S > & v1,
    const Vec< T, S > & v2
)
```



### function <a id="ga0a9cc9a789a441ac96892c61bc9bbc35" href="#ga0a9cc9a789a441ac96892c61bc9bbc35">normalize</a>

```cpp
ffw::Vec< T, S > math::normalize (
    const Vec< T, S > & vec
)
```



### function <a id="gaea8e4e15b76d5559b8d9abcf790a91d8" href="#gaea8e4e15b76d5559b8d9abcf790a91d8">operator<<</a>

```cpp
std::ostream & math::operator<< (
    std::ostream & os,
    const ffw::Vec< T, S > & vec
)
```



