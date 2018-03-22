---
search:
    keywords: ['ffw::TifLoader', 'TifLoader', 'TifLoader', 'TifLoader', 'swap', 'operator=', 'operator=', '~TifLoader', 'open', 'readRow', 'close', 'ImageReader', '~ImageReader', 'open', 'close', 'readRow', 'getMipMap', 'readAll', 'readAll', 'eof', 'operator bool', 'getRowOffset', 'isOpen', 'getNumOfMipMaps', 'getMipMapOffset', 'ImageFormat', 'ImageFormat', 'ImageFormat', 'getImageType', 'getWidth', 'getHeight', 'getDepth', 'getStrideSize', 'getBitsPerPixel', 'getBitDepth', 'getNumberOfChannels', 'isCompressed', 'getMipMapSize', 'getMipMapPtrOffset', 'swap', 'operator=', 'getAllocationSize', 'operator==']
---

# class ffw::TifLoader



Inherits the following classes: **[ffw::ImageReader](classffw_1_1_image_reader.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**TifLoader**](classffw_1_1_tif_loader.md#1a86d13b948cd54a6db84cb7e84843d3d6) () |
||[**TifLoader**](classffw_1_1_tif_loader.md#1ab3aae809cde9470ec86b346a5e8510cf) (const **[TifLoader](classffw_1_1_tif_loader.md)** & other) = delete |
||[**TifLoader**](classffw_1_1_tif_loader.md#1a614ce0e933cd514e884900abf7f5cb25) (**[TifLoader](classffw_1_1_tif_loader.md)** && other) |
|void|[**swap**](classffw_1_1_tif_loader.md#1ac81fbe7a7fa8bfb28bf61ee84e0138ca) (**[TifLoader](classffw_1_1_tif_loader.md)** & other) |
|**[TifLoader](classffw_1_1_tif_loader.md)** &|[**operator=**](classffw_1_1_tif_loader.md#1a0a7b5701a1a9e8e2636031187c571ef6) (const **[TifLoader](classffw_1_1_tif_loader.md)** & other) = delete |
|**[TifLoader](classffw_1_1_tif_loader.md)** &|[**operator=**](classffw_1_1_tif_loader.md#1aaf010032cbbcbe7c9121b4d006ec3bb2) (**[TifLoader](classffw_1_1_tif_loader.md)** && other) |
|virtual |[**~TifLoader**](classffw_1_1_tif_loader.md#1aa64271c49c1001fa4353288887c138da) () |
|virtual bool|[**open**](classffw_1_1_tif_loader.md#1a491fe2b1c834592ef9996a77e478bd47) (const std::string & path) override |
|virtual size\_t|[**readRow**](classffw_1_1_tif_loader.md#1a660d8761c84c97af92b79a320f99d9af) (void \* dest) override |
|virtual void|[**close**](classffw_1_1_tif_loader.md#1a2b3efef5b09e9c44973616249c1ac1c7) () override |


#### Public Functions inherited from [ffw::ImageReader](classffw_1_1_image_reader.md)

|Type|Name|
|-----|-----|
||[**ImageReader**](classffw_1_1_image_reader.md#1aa8c4726989a7fa3a5cdeee4141ec69f1) () |
|virtual |[**~ImageReader**](classffw_1_1_image_reader.md#1a84fd72d1a2d7474d727b21745eab497b) () |
|virtual bool|[**getMipMap**](classffw_1_1_image_reader.md#1a9b243ebae163d4ad5b29e5df1d48b93d) (int level) |
|bool|[**readAll**](classffw_1_1_image_reader.md#1a4b8358fa73e99ab21911ea25071e993c) (void \* dest) |
|bool|[**readAll**](classffw_1_1_image_reader.md#1aee930a79534e0a24db03d5974cd5a829) (**[ffw::ImageBuffer](classffw_1_1_image_buffer.md)** & buffer) |
|bool|[**eof**](classffw_1_1_image_reader.md#1a5fd58d19c67ad4417e168c46af91cfbd) () const |
||[**operator bool**](classffw_1_1_image_reader.md#1a227735bc9d3f0ea6ea9987a8e88c84f5) () const |
|int|[**getRowOffset**](classffw_1_1_image_reader.md#1aa04e2077f3b95d4f1c8e7d1e1893eb71) () const |
|bool|[**isOpen**](classffw_1_1_image_reader.md#1a9eceacdc6b3cd1a48e96bb0e67c66319) () const |
|int|[**getNumOfMipMaps**](classffw_1_1_image_reader.md#1a08b74fdbfd615976290da9fbc6765457) () const |
|int|[**getMipMapOffset**](classffw_1_1_image_reader.md#1afeaa3abd68a0485f72f73608fd7e84a4) () const |


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

#### Protected Attributes inherited from [ffw::ImageReader](classffw_1_1_image_reader.md)

|Type|Name|
|-----|-----|
|bool|[**loaded**](classffw_1_1_image_reader.md#1a59264aeb0286d25bd9e11ca68db53030)|
|int|[**row**](classffw_1_1_image_reader.md#1a4d4caf860786d419663b33f126416890)|
|int|[**mipmapOffset**](classffw_1_1_image_reader.md#1a35b39bd82926d24d8c52c2ce17532a4e)|
|int|[**mipmaps**](classffw_1_1_image_reader.md#1ab65ec798fc33d05864eeafd2d6e123fb)|


#### Protected Attributes inherited from [ffw::ImageFormat](classffw_1_1_image_format.md)

|Type|Name|
|-----|-----|
|**[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)**|[**format**](classffw_1_1_image_format.md#1a00569cba5e7d8df7582554718f908d7e)|
|int|[**width**](classffw_1_1_image_format.md#1a1a26d9b05851d073858b34ccabc40a79)|
|int|[**height**](classffw_1_1_image_format.md#1a7c62585ac46e6fc7c3fe6efab59cfd4c)|
|int|[**depth**](classffw_1_1_image_format.md#1a128894191ad04073b44663b8541f97aa)|


## Public Functions Documentation

### function <a id="1a86d13b948cd54a6db84cb7e84843d3d6" href="#1a86d13b948cd54a6db84cb7e84843d3d6">TifLoader</a>

```cpp
ffw::TifLoader::TifLoader ()
```



### function <a id="1ab3aae809cde9470ec86b346a5e8510cf" href="#1ab3aae809cde9470ec86b346a5e8510cf">TifLoader</a>

```cpp
ffw::TifLoader::TifLoader (
    const TifLoader & other
) = delete
```



### function <a id="1a614ce0e933cd514e884900abf7f5cb25" href="#1a614ce0e933cd514e884900abf7f5cb25">TifLoader</a>

```cpp
ffw::TifLoader::TifLoader (
    TifLoader && other
)
```



### function <a id="1ac81fbe7a7fa8bfb28bf61ee84e0138ca" href="#1ac81fbe7a7fa8bfb28bf61ee84e0138ca">swap</a>

```cpp
void ffw::TifLoader::swap (
    TifLoader & other
)
```



### function <a id="1a0a7b5701a1a9e8e2636031187c571ef6" href="#1a0a7b5701a1a9e8e2636031187c571ef6">operator=</a>

```cpp
TifLoader & ffw::TifLoader::operator= (
    const TifLoader & other
) = delete
```



### function <a id="1aaf010032cbbcbe7c9121b4d006ec3bb2" href="#1aaf010032cbbcbe7c9121b4d006ec3bb2">operator=</a>

```cpp
TifLoader & ffw::TifLoader::operator= (
    TifLoader && other
)
```



### function <a id="1aa64271c49c1001fa4353288887c138da" href="#1aa64271c49c1001fa4353288887c138da">~TifLoader</a>

```cpp
virtual ffw::TifLoader::~TifLoader ()
```



### function <a id="1a491fe2b1c834592ef9996a77e478bd47" href="#1a491fe2b1c834592ef9996a77e478bd47">open</a>

```cpp
virtual bool ffw::TifLoader::open (
    const std::string & path
)
```

Overrides **[ImageReader::open](classffw_1_1_image_reader.md#1a7155f92f0f65eec33d9204ff4a63a518)**


### function <a id="1a660d8761c84c97af92b79a320f99d9af" href="#1a660d8761c84c97af92b79a320f99d9af">readRow</a>

```cpp
virtual size_t ffw::TifLoader::readRow (
    void * dest
)
```

Overrides **[ImageReader::readRow](classffw_1_1_image_reader.md#1a4a172a49d03b415e5c0bb535af9599c9)**


### function <a id="1a2b3efef5b09e9c44973616249c1ac1c7" href="#1a2b3efef5b09e9c44973616249c1ac1c7">close</a>

```cpp
virtual void ffw::TifLoader::close ()
```

Overrides **[ImageReader::close](classffw_1_1_image_reader.md#1aab601ee6de85c082b72214ed816d4c4d)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/media/tifloader.h`
