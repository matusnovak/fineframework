---
search: false
---

# class ffw::ImageBuffer



Inherits the following classes: **[ffw::ImageFormat](classffw_1_1_image_format.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**ImageBuffer**](classffw_1_1_image_buffer.md#1aa2601d0a67436504ad8e401e6220fc7f) () |
||[**ImageBuffer**](classffw_1_1_image_buffer.md#1a6efc1b9d05e89db7c9930e4ed6c8459a) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & other) = delete |
||[**ImageBuffer**](classffw_1_1_image_buffer.md#1af766b0913aa374d5eb400544ffe7bfae) (**[ImageBuffer](classffw_1_1_image_buffer.md)** && other) |
|virtual |[**~ImageBuffer**](classffw_1_1_image_buffer.md#1a223afa91dfec13da4a19a422f7404644) () |
|bool|[**isAllocated**](classffw_1_1_image_buffer.md#1a1cd4d4f32085d0d2d4fc6b5d10a83d0b) () const |
||[**operator bool**](classffw_1_1_image_buffer.md#1aa69b9385989641d7ba6ad71d4c6984a5) () const |
|int|[**getNumOfMipMaps**](classffw_1_1_image_buffer.md#1a78a15bb77b043fc3331cae1f9eb4605e) () const |
|void|[**swap**](classffw_1_1_image_buffer.md#1aa042c681f2827acd62f1fe6fc549a78e) (**[ImageBuffer](classffw_1_1_image_buffer.md)** & second) |
|void|[**destroy**](classffw_1_1_image_buffer.md#1acd8d8790ba7cb4745551a7b5d16ef627) () |
|bool|[**allocate**](classffw_1_1_image_buffer.md#1a70ead23e8e34c4f6e7e9abbc39223758) (int w, int h, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** type, const void \* pixels = NULL, int mips = 0) |
|unsigned char \*|[**getPtr**](classffw_1_1_image_buffer.md#1afcd0678209f660458d44635bfe8f75f2) () |
|const unsigned char \*|[**getPtr**](classffw_1_1_image_buffer.md#1a42a1e8612281f1221e945e8b2a87cf78) () const |
|unsigned char \*|[**getMipMapPtr**](classffw_1_1_image_buffer.md#1a6d7a4c4fb8affd7c88cbb1a2d84bc985) (int level) |
|const unsigned char \*|[**getMipMapPtr**](classffw_1_1_image_buffer.md#1a42a8d3e4afc218425581c5e720606f85) (int level) const |
|size\_t|[**getSize**](classffw_1_1_image_buffer.md#1aa517d5755bb12537512c93921b728a4d) () const |
|**[ImageBuffer](classffw_1_1_image_buffer.md)** &|[**operator=**](classffw_1_1_image_buffer.md#1af2af2641d4efad1ef78ec9d2be08b686) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & other) = delete |
|**[ImageBuffer](classffw_1_1_image_buffer.md)** &|[**operator=**](classffw_1_1_image_buffer.md#1ad7f09039076de8a991a7a5753b2e97f4) (**[ImageBuffer](classffw_1_1_image_buffer.md)** && other) |
|bool|[**operator==**](classffw_1_1_image_buffer.md#1a495dbb42a5e53f24b52339de7bca48e5) (const **[ImageBuffer](classffw_1_1_image_buffer.md)** & other) const |


#### Public Functions inherited from [ffw::ImageFormat](classffw_1_1_image_format.md)

|Type|Name|
|-----|-----|
||[**ImageFormat**](classffw_1_1_image_format.md#1a5c2552e2129595fdb74923e00f3f51e1) () |
||[**ImageFormat**](classffw_1_1_image_format.md#1a0d214d9324cce891461d07b30be64c34) (int width, int height, int depth, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** format) |
||[**ImageFormat**](classffw_1_1_image_format.md#1a292f274f857b9da281b9ccb17d07b9ef) (const **[ImageFormat](classffw_1_1_image_format.md)** & other) |
|**[ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)**|[**getImageType**](classffw_1_1_image_format.md#1a1bb0e2d7c7916dc840516e97b0fe27d1) () const |
|int|[**getWidth**](classffw_1_1_image_format.md#1af8aa5a20fe893f3289a26b1bc52c1a43) (int mipmap = 0) const |
|int|[**getHeight**](classffw_1_1_image_format.md#1a73e22a919bf12a2207d65496398a6a5f) (int mipmap = 0) const |
|int|[**getDepth**](classffw_1_1_image_format.md#1ae162bf4b48f3dd2e2d7739c927a779b8) (int mipmap = 0) const |
|size\_t|[**getStrideSize**](classffw_1_1_image_format.md#1a55de6ea2325fc284e2fbd027146a53ee) (int mipmap = 0) const |
|int|[**getBitsPerPixel**](classffw_1_1_image_format.md#1a4926378546cb727ad4930fa5797ddd83) () const |
|int|[**getBitDepth**](classffw_1_1_image_format.md#1a07c9771437ef7bfaabe3f51164a99eac) () const |
|int|[**getNumberOfChannels**](classffw_1_1_image_format.md#1a388b531a9ea109266cfc2509e79f6751) () const |
|bool|[**isCompressed**](classffw_1_1_image_format.md#1a6c4430f5cfc51120bfc04008bcdb6210) () const |
|size\_t|[**getMipMapSize**](classffw_1_1_image_format.md#1ac8967d7bd7b6b300e2a8c3ff6b6dfd88) (int level) const |
|size\_t|[**getMipMapPtrOffset**](classffw_1_1_image_format.md#1a95be015bde6130bcf6d27472b74f555e) (int level) const |
|void|[**swap**](classffw_1_1_image_format.md#1a1f855dd5b248274b53766a81102d583d) (**[ImageFormat](classffw_1_1_image_format.md)** & other) |
|**[ImageFormat](classffw_1_1_image_format.md)** &|[**operator=**](classffw_1_1_image_format.md#1a69b46ddfe7e8768658602003530bac23) (const **[ImageFormat](classffw_1_1_image_format.md)** & other) |
|size\_t|[**getAllocationSize**](classffw_1_1_image_format.md#1a6e0eb8d724ec7ee0195ee8f25cf92ff3) (int mipmaps) const |
|bool|[**operator==**](classffw_1_1_image_format.md#1a859ea5ac46aee7a01817dcaca12a18bd) (const **[ImageFormat](classffw_1_1_image_format.md)** & other) const |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::ImageFormat](classffw_1_1_image_format.md)

|Type|Name|
|-----|-----|
|**[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)**|[**format**](classffw_1_1_image_format.md#1a00569cba5e7d8df7582554718f908d7e)|
|int|[**width**](classffw_1_1_image_format.md#1a1a26d9b05851d073858b34ccabc40a79)|
|int|[**height**](classffw_1_1_image_format.md#1a7c62585ac46e6fc7c3fe6efab59cfd4c)|
|int|[**depth**](classffw_1_1_image_format.md#1a128894191ad04073b44663b8541f97aa)|


## Public Functions Documentation

### function <a id="1aa2601d0a67436504ad8e401e6220fc7f" href="#1aa2601d0a67436504ad8e401e6220fc7f">ImageBuffer</a>

```cpp
ffw::ImageBuffer::ImageBuffer ()
```



### function <a id="1a6efc1b9d05e89db7c9930e4ed6c8459a" href="#1a6efc1b9d05e89db7c9930e4ed6c8459a">ImageBuffer</a>

```cpp
ffw::ImageBuffer::ImageBuffer (
    const ImageBuffer & other
) = delete
```



### function <a id="1af766b0913aa374d5eb400544ffe7bfae" href="#1af766b0913aa374d5eb400544ffe7bfae">ImageBuffer</a>

```cpp
ffw::ImageBuffer::ImageBuffer (
    ImageBuffer && other
)
```



### function <a id="1a223afa91dfec13da4a19a422f7404644" href="#1a223afa91dfec13da4a19a422f7404644">~ImageBuffer</a>

```cpp
virtual ffw::ImageBuffer::~ImageBuffer ()
```



### function <a id="1a1cd4d4f32085d0d2d4fc6b5d10a83d0b" href="#1a1cd4d4f32085d0d2d4fc6b5d10a83d0b">isAllocated</a>

```cpp
bool ffw::ImageBuffer::isAllocated () const
```



### function <a id="1aa69b9385989641d7ba6ad71d4c6984a5" href="#1aa69b9385989641d7ba6ad71d4c6984a5">operator bool</a>

```cpp
ffw::ImageBuffer::operator bool () const
```



### function <a id="1a78a15bb77b043fc3331cae1f9eb4605e" href="#1a78a15bb77b043fc3331cae1f9eb4605e">getNumOfMipMaps</a>

```cpp
int ffw::ImageBuffer::getNumOfMipMaps () const
```



### function <a id="1aa042c681f2827acd62f1fe6fc549a78e" href="#1aa042c681f2827acd62f1fe6fc549a78e">swap</a>

```cpp
void ffw::ImageBuffer::swap (
    ImageBuffer & second
)
```



### function <a id="1acd8d8790ba7cb4745551a7b5d16ef627" href="#1acd8d8790ba7cb4745551a7b5d16ef627">destroy</a>

```cpp
void ffw::ImageBuffer::destroy ()
```



### function <a id="1a70ead23e8e34c4f6e7e9abbc39223758" href="#1a70ead23e8e34c4f6e7e9abbc39223758">allocate</a>

```cpp
bool ffw::ImageBuffer::allocate (
    int w
    int h
    ffw::ImageType type
    const void * pixels = NULL
    int mips = 0
)
```



### function <a id="1afcd0678209f660458d44635bfe8f75f2" href="#1afcd0678209f660458d44635bfe8f75f2">getPtr</a>

```cpp
unsigned char * ffw::ImageBuffer::getPtr ()
```



### function <a id="1a42a1e8612281f1221e945e8b2a87cf78" href="#1a42a1e8612281f1221e945e8b2a87cf78">getPtr</a>

```cpp
const unsigned char * ffw::ImageBuffer::getPtr () const
```



### function <a id="1a6d7a4c4fb8affd7c88cbb1a2d84bc985" href="#1a6d7a4c4fb8affd7c88cbb1a2d84bc985">getMipMapPtr</a>

```cpp
unsigned char * ffw::ImageBuffer::getMipMapPtr (
    int level
)
```



### function <a id="1a42a8d3e4afc218425581c5e720606f85" href="#1a42a8d3e4afc218425581c5e720606f85">getMipMapPtr</a>

```cpp
const unsigned char * ffw::ImageBuffer::getMipMapPtr (
    int level
) const
```



### function <a id="1aa517d5755bb12537512c93921b728a4d" href="#1aa517d5755bb12537512c93921b728a4d">getSize</a>

```cpp
size_t ffw::ImageBuffer::getSize () const
```



### function <a id="1af2af2641d4efad1ef78ec9d2be08b686" href="#1af2af2641d4efad1ef78ec9d2be08b686">operator=</a>

```cpp
ImageBuffer & ffw::ImageBuffer::operator= (
    const ImageBuffer & other
) = delete
```



### function <a id="1ad7f09039076de8a991a7a5753b2e97f4" href="#1ad7f09039076de8a991a7a5753b2e97f4">operator=</a>

```cpp
ImageBuffer & ffw::ImageBuffer::operator= (
    ImageBuffer && other
)
```



### function <a id="1a495dbb42a5e53f24b52339de7bca48e5" href="#1a495dbb42a5e53f24b52339de7bca48e5">operator==</a>

```cpp
bool ffw::ImageBuffer::operator== (
    const ImageBuffer & other
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/imagebuffer.h`
