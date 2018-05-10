---
search: false
---

# struct ffw::Mat4x4

## Public Attributes

|Type|Name|
|-----|-----|
|T|[**ptr**](structffw_1_1_mat4x4.md#1a5616fb7b407526c72b23884ceb85a987)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Mat4x4**](structffw_1_1_mat4x4.md#1ac08d4ddb7eace87ee2f1db2994890668) () |
||[**Mat4x4**](structffw_1_1_mat4x4.md#1a1f504a1bf89198c32ca5a83826b5f7b3) (T xx, T yx, T zx, T wx, T xy, T yy, T zy, T wy, T xz, T yz, T zz, T wz, T xw, T yw, T zw, T ww) |
||[**Mat4x4**](structffw_1_1_mat4x4.md#1a000b5e3b462d197d6ae552f1ecca0879) (T Val) |
||[**Mat4x4**](structffw_1_1_mat4x4.md#1af12e0fbae5826cc1e89a6197582520f8) (std::initializer\_list< T > List) |
|void|[**set**](structffw_1_1_mat4x4.md#1ad93df0edf1e4c23a56d199143e4b80a6) (T xx, T yx, T zx, T wx, T xy, T yy, T zy, T wy, T xz, T yz, T zz, T wz, T xw, T yw, T zw, T ww) |
|void|[**set**](structffw_1_1_mat4x4.md#1ab077c2bc263bd35b3d4c21561fe9bc0e) (T Val) |
|void|[**set**](structffw_1_1_mat4x4.md#1a4844d20a4f7c99e822905bc981fef682) (T m) |
|void|[**set**](structffw_1_1_mat4x4.md#1a4ecc83495050456d9ba3a69d2c24648e) (std::initializer\_list< T > List) |
|T \*|[**getPtr**](structffw_1_1_mat4x4.md#1a4a5ab9ab057824fa23496d4ad1f132d3) () |
|const T \*|[**getPtr**](structffw_1_1_mat4x4.md#1adfe75252ab21dec59ea316624112ebc5) () const |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**operator=**](structffw_1_1_mat4x4.md#1af997761fd0b632f9c6f7c05637d4c19b) (const **[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > & m) |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T >|[**operator\***](structffw_1_1_mat4x4.md#1a1694f0e8379d08e88c3f53c6f986dfa9) (const **[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > & m) const |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**operator\*=**](structffw_1_1_mat4x4.md#1a274275d2c324b2941bdd13ee4544e567) (const **[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > & m) |
|**[ffw::Vec4](structffw_1_1_vec4.md)**< S >|[**operator\***](structffw_1_1_mat4x4.md#1aacf211375a943dae6b7400adb450b481) (const **[ffw::Vec4](structffw_1_1_vec4.md)**< S > & V) const |
|**[ffw::Vec3](structffw_1_1_vec3.md)**< S >|[**operator\***](structffw_1_1_mat4x4.md#1a6b619b07185c50bb7e794d22d1937cc0) (const **[ffw::Vec3](structffw_1_1_vec3.md)**< S > & V) const |
|T &|[**operator[]**](structffw_1_1_mat4x4.md#1a3e79c2a92ee85975f45c31fd490bc7a5) (int x) |
|const T &|[**operator[]**](structffw_1_1_mat4x4.md#1ac810a730e1aa6df0f250841f7813581c) (int x) const |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**rotate**](structffw_1_1_mat4x4.md#1a219ca7707f847586e0475758829fe46b) (const **[ffw::Quat](structffw_1_1_quat.md)**< T > & Q) |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**translate**](structffw_1_1_mat4x4.md#1ac993b836ed434943edf0e5a642c7a1ec) (T X, T Y, T Z) |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**scale**](structffw_1_1_mat4x4.md#1a4abe9c0e35b75407218e8f2ac8b473eb) (T X, T Y, T Z) |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**transpose**](structffw_1_1_mat4x4.md#1a7f44976780017551bf439f1aedab156d) () |
|**[ffw::Mat4x4](structffw_1_1_mat4x4.md)**< T > &|[**inverse**](structffw_1_1_mat4x4.md#1aa91016470aa507e5841facadb09e5189) () |


## Public Attributes Documentation

### variable <a id="1a5616fb7b407526c72b23884ceb85a987" href="#1a5616fb7b407526c72b23884ceb85a987">ptr</a>

```cpp
T ffw::Mat4x4< T >::ptr[16];
```



## Public Functions Documentation

### function <a id="1ac08d4ddb7eace87ee2f1db2994890668" href="#1ac08d4ddb7eace87ee2f1db2994890668">Mat4x4</a>

```cpp
ffw::Mat4x4::Mat4x4 ()
```



### function <a id="1a1f504a1bf89198c32ca5a83826b5f7b3" href="#1a1f504a1bf89198c32ca5a83826b5f7b3">Mat4x4</a>

```cpp
ffw::Mat4x4::Mat4x4 (
    T xx
    T yx
    T zx
    T wx
    T xy
    T yy
    T zy
    T wy
    T xz
    T yz
    T zz
    T wz
    T xw
    T yw
    T zw
    T ww
)
```



### function <a id="1a000b5e3b462d197d6ae552f1ecca0879" href="#1a000b5e3b462d197d6ae552f1ecca0879">Mat4x4</a>

```cpp
ffw::Mat4x4::Mat4x4 (
    T Val
)
```



### function <a id="1af12e0fbae5826cc1e89a6197582520f8" href="#1af12e0fbae5826cc1e89a6197582520f8">Mat4x4</a>

```cpp
ffw::Mat4x4::Mat4x4 (
    std::initializer_list< T > List
)
```



### function <a id="1ad93df0edf1e4c23a56d199143e4b80a6" href="#1ad93df0edf1e4c23a56d199143e4b80a6">set</a>

```cpp
void ffw::Mat4x4::set (
    T xx
    T yx
    T zx
    T wx
    T xy
    T yy
    T zy
    T wy
    T xz
    T yz
    T zz
    T wz
    T xw
    T yw
    T zw
    T ww
)
```



### function <a id="1ab077c2bc263bd35b3d4c21561fe9bc0e" href="#1ab077c2bc263bd35b3d4c21561fe9bc0e">set</a>

```cpp
void ffw::Mat4x4::set (
    T Val
)
```



### function <a id="1a4844d20a4f7c99e822905bc981fef682" href="#1a4844d20a4f7c99e822905bc981fef682">set</a>

```cpp
void ffw::Mat4x4::set (
    T m
)
```



### function <a id="1a4ecc83495050456d9ba3a69d2c24648e" href="#1a4ecc83495050456d9ba3a69d2c24648e">set</a>

```cpp
void ffw::Mat4x4::set (
    std::initializer_list< T > List
)
```



### function <a id="1a4a5ab9ab057824fa23496d4ad1f132d3" href="#1a4a5ab9ab057824fa23496d4ad1f132d3">getPtr</a>

```cpp
T * ffw::Mat4x4::getPtr ()
```



### function <a id="1adfe75252ab21dec59ea316624112ebc5" href="#1adfe75252ab21dec59ea316624112ebc5">getPtr</a>

```cpp
const T * ffw::Mat4x4::getPtr () const
```



### function <a id="1af997761fd0b632f9c6f7c05637d4c19b" href="#1af997761fd0b632f9c6f7c05637d4c19b">operator=</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::operator= (
    const ffw::Mat4x4< T > & m
)
```



### function <a id="1a1694f0e8379d08e88c3f53c6f986dfa9" href="#1a1694f0e8379d08e88c3f53c6f986dfa9">operator\*</a>

```cpp
ffw::Mat4x4< T > ffw::Mat4x4::operator* (
    const ffw::Mat4x4< T > & m
) const
```



### function <a id="1a274275d2c324b2941bdd13ee4544e567" href="#1a274275d2c324b2941bdd13ee4544e567">operator\*=</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::operator*= (
    const ffw::Mat4x4< T > & m
)
```



### function <a id="1aacf211375a943dae6b7400adb450b481" href="#1aacf211375a943dae6b7400adb450b481">operator\*</a>

```cpp
ffw::Vec4< S > ffw::Mat4x4::operator* (
    const ffw::Vec4< S > & V
) const
```



### function <a id="1a6b619b07185c50bb7e794d22d1937cc0" href="#1a6b619b07185c50bb7e794d22d1937cc0">operator\*</a>

```cpp
ffw::Vec3< S > ffw::Mat4x4::operator* (
    const ffw::Vec3< S > & V
) const
```



### function <a id="1a3e79c2a92ee85975f45c31fd490bc7a5" href="#1a3e79c2a92ee85975f45c31fd490bc7a5">operator[]</a>

```cpp
T & ffw::Mat4x4::operator[] (
    int x
)
```



### function <a id="1ac810a730e1aa6df0f250841f7813581c" href="#1ac810a730e1aa6df0f250841f7813581c">operator[]</a>

```cpp
const T & ffw::Mat4x4::operator[] (
    int x
) const
```



### function <a id="1a219ca7707f847586e0475758829fe46b" href="#1a219ca7707f847586e0475758829fe46b">rotate</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::rotate (
    const ffw::Quat< T > & Q
)
```



### function <a id="1ac993b836ed434943edf0e5a642c7a1ec" href="#1ac993b836ed434943edf0e5a642c7a1ec">translate</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::translate (
    T X
    T Y
    T Z
)
```



### function <a id="1a4abe9c0e35b75407218e8f2ac8b473eb" href="#1a4abe9c0e35b75407218e8f2ac8b473eb">scale</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::scale (
    T X
    T Y
    T Z
)
```



### function <a id="1a7f44976780017551bf439f1aedab156d" href="#1a7f44976780017551bf439f1aedab156d">transpose</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::transpose ()
```



### function <a id="1aa91016470aa507e5841facadb09e5189" href="#1aa91016470aa507e5841facadb09e5189">inverse</a>

```cpp
ffw::Mat4x4< T > & ffw::Mat4x4::inverse ()
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/mat4.h`
