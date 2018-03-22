---
search:
    keywords: ['ffw::ImageFormat', 'format', 'width', 'height', 'depth', 'ImageFormat', 'ImageFormat', 'ImageFormat', 'getImageType', 'getWidth', 'getHeight', 'getDepth', 'getStrideSize', 'getBitsPerPixel', 'getBitDepth', 'getNumberOfChannels', 'isCompressed', 'getMipMapSize', 'getMipMapPtrOffset', 'swap', 'operator=', 'getAllocationSize', 'operator==']
---

# class ffw::ImageFormat



Inherited by the following classes: **[ffw::ImageBuffer](classffw_1_1_image_buffer.md)**, **[ffw::ImageReader](classffw_1_1_image_reader.md)**, **[ffw::ImageWriter](classffw_1_1_image_writer.md)**

## Protected Attributes

|Type|Name|
|-----|-----|
|**[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)**|[**format**](classffw_1_1_image_format.md#1a00569cba5e7d8df7582554718f908d7e)|
|int|[**width**](classffw_1_1_image_format.md#1a1a26d9b05851d073858b34ccabc40a79)|
|int|[**height**](classffw_1_1_image_format.md#1a7c62585ac46e6fc7c3fe6efab59cfd4c)|
|int|[**depth**](classffw_1_1_image_format.md#1a128894191ad04073b44663b8541f97aa)|


## Public Functions

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


## Protected Attributes Documentation

### variable <a id="1a00569cba5e7d8df7582554718f908d7e" href="#1a00569cba5e7d8df7582554718f908d7e">format</a>

```cpp
ffw::ImageType ffw::ImageFormat::format;
```



### variable <a id="1a1a26d9b05851d073858b34ccabc40a79" href="#1a1a26d9b05851d073858b34ccabc40a79">width</a>

```cpp
int ffw::ImageFormat::width;
```



### variable <a id="1a7c62585ac46e6fc7c3fe6efab59cfd4c" href="#1a7c62585ac46e6fc7c3fe6efab59cfd4c">height</a>

```cpp
int ffw::ImageFormat::height;
```



### variable <a id="1a128894191ad04073b44663b8541f97aa" href="#1a128894191ad04073b44663b8541f97aa">depth</a>

```cpp
int ffw::ImageFormat::depth;
```



## Public Functions Documentation

### function <a id="1a5c2552e2129595fdb74923e00f3f51e1" href="#1a5c2552e2129595fdb74923e00f3f51e1">ImageFormat</a>

```cpp
ffw::ImageFormat::ImageFormat ()
```



### function <a id="1a0d214d9324cce891461d07b30be64c34" href="#1a0d214d9324cce891461d07b30be64c34">ImageFormat</a>

```cpp
ffw::ImageFormat::ImageFormat (
    int width
    int height
    int depth
    ffw::ImageType format
)
```



### function <a id="1a292f274f857b9da281b9ccb17d07b9ef" href="#1a292f274f857b9da281b9ccb17d07b9ef">ImageFormat</a>

```cpp
ffw::ImageFormat::ImageFormat (
    const ImageFormat & other
)
```



### function <a id="1a1bb0e2d7c7916dc840516e97b0fe27d1" href="#1a1bb0e2d7c7916dc840516e97b0fe27d1">getImageType</a>

```cpp
ImageType ffw::ImageFormat::getImageType () const
```



### function <a id="1af8aa5a20fe893f3289a26b1bc52c1a43" href="#1af8aa5a20fe893f3289a26b1bc52c1a43">getWidth</a>

```cpp
int ffw::ImageFormat::getWidth (
    int mipmap = 0
) const
```



### function <a id="1a73e22a919bf12a2207d65496398a6a5f" href="#1a73e22a919bf12a2207d65496398a6a5f">getHeight</a>

```cpp
int ffw::ImageFormat::getHeight (
    int mipmap = 0
) const
```



### function <a id="1ae162bf4b48f3dd2e2d7739c927a779b8" href="#1ae162bf4b48f3dd2e2d7739c927a779b8">getDepth</a>

```cpp
int ffw::ImageFormat::getDepth (
    int mipmap = 0
) const
```



### function <a id="1a55de6ea2325fc284e2fbd027146a53ee" href="#1a55de6ea2325fc284e2fbd027146a53ee">getStrideSize</a>

```cpp
size_t ffw::ImageFormat::getStrideSize (
    int mipmap = 0
) const
```



### function <a id="1a4926378546cb727ad4930fa5797ddd83" href="#1a4926378546cb727ad4930fa5797ddd83">getBitsPerPixel</a>

```cpp
int ffw::ImageFormat::getBitsPerPixel () const
```



### function <a id="1a07c9771437ef7bfaabe3f51164a99eac" href="#1a07c9771437ef7bfaabe3f51164a99eac">getBitDepth</a>

```cpp
int ffw::ImageFormat::getBitDepth () const
```



### function <a id="1a388b531a9ea109266cfc2509e79f6751" href="#1a388b531a9ea109266cfc2509e79f6751">getNumberOfChannels</a>

```cpp
int ffw::ImageFormat::getNumberOfChannels () const
```



### function <a id="1a6c4430f5cfc51120bfc04008bcdb6210" href="#1a6c4430f5cfc51120bfc04008bcdb6210">isCompressed</a>

```cpp
bool ffw::ImageFormat::isCompressed () const
```



### function <a id="1ac8967d7bd7b6b300e2a8c3ff6b6dfd88" href="#1ac8967d7bd7b6b300e2a8c3ff6b6dfd88">getMipMapSize</a>

```cpp
size_t ffw::ImageFormat::getMipMapSize (
    int level
) const
```



### function <a id="1a95be015bde6130bcf6d27472b74f555e" href="#1a95be015bde6130bcf6d27472b74f555e">getMipMapPtrOffset</a>

```cpp
size_t ffw::ImageFormat::getMipMapPtrOffset (
    int level
) const
```



### function <a id="1a1f855dd5b248274b53766a81102d583d" href="#1a1f855dd5b248274b53766a81102d583d">swap</a>

```cpp
void ffw::ImageFormat::swap (
    ImageFormat & other
)
```



### function <a id="1a69b46ddfe7e8768658602003530bac23" href="#1a69b46ddfe7e8768658602003530bac23">operator=</a>

```cpp
ImageFormat & ffw::ImageFormat::operator= (
    const ImageFormat & other
)
```



### function <a id="1a6e0eb8d724ec7ee0195ee8f25cf92ff3" href="#1a6e0eb8d724ec7ee0195ee8f25cf92ff3">getAllocationSize</a>

```cpp
size_t ffw::ImageFormat::getAllocationSize (
    int mipmaps
) const
```



### function <a id="1a859ea5ac46aee7a01817dcaca12a18bd" href="#1a859ea5ac46aee7a01817dcaca12a18bd">operator==</a>

```cpp
bool ffw::ImageFormat::operator== (
    const ImageFormat & other
) const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/math/imagebuffer.h`
