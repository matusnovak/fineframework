---
search:
    keywords: ['ffw::TgaLoader', 'TgaLoader', 'TgaLoader', 'TgaLoader', 'swap', 'operator=', 'operator=', '~TgaLoader', 'open', 'readRow', 'close', 'ImageReader', '~ImageReader', 'open', 'close', 'readRow', 'getMipMap', 'readAll', 'readAll', 'eof', 'operator bool', 'getRowOffset', 'isOpen', 'getNumOfMipMaps', 'getMipMapOffset', 'ImageFormat', 'ImageFormat', 'ImageFormat', 'getImageType', 'getWidth', 'getHeight', 'getDepth', 'getStrideSize', 'getBitsPerPixel', 'getBitDepth', 'getNumberOfChannels', 'isCompressed', 'getMipMapSize', 'getMipMapPtrOffset', 'swap', 'operator=', 'getAllocationSize', 'operator==']
---

# class ffw::TgaLoader



Inherits the following classes: **[ffw::ImageReader](classffw_1_1_image_reader.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**TgaLoader**](classffw_1_1_tga_loader.md#1a3bf8387c6d21073fab279a9fa0ff139c) () |
||[**TgaLoader**](classffw_1_1_tga_loader.md#1a9b1bc10f3531c9e9308b7d59a83e1c42) (const **[TgaLoader](classffw_1_1_tga_loader.md)** & other) = delete |
||[**TgaLoader**](classffw_1_1_tga_loader.md#1a4371c43b9190d3d0536db7498d5c91ff) (**[TgaLoader](classffw_1_1_tga_loader.md)** && other) |
|void|[**swap**](classffw_1_1_tga_loader.md#1a6f5ab30806cccfbeb0cbf759fb65921e) (**[TgaLoader](classffw_1_1_tga_loader.md)** & other) |
|**[TgaLoader](classffw_1_1_tga_loader.md)** &|[**operator=**](classffw_1_1_tga_loader.md#1a955d3c68e20db3f319e0f85a02ac9bb2) (const **[TgaLoader](classffw_1_1_tga_loader.md)** & other) = delete |
|**[TgaLoader](classffw_1_1_tga_loader.md)** &|[**operator=**](classffw_1_1_tga_loader.md#1a84f05d8c750ded1fe8ba68a6b4e7e498) (**[TgaLoader](classffw_1_1_tga_loader.md)** && other) |
|virtual |[**~TgaLoader**](classffw_1_1_tga_loader.md#1a2ba5eabfa85df8be309485eb1cb20268) () |
|virtual bool|[**open**](classffw_1_1_tga_loader.md#1a5928b3e055bb51852dc0e4240150b59a) (const std::string & path) override |
|virtual size\_t|[**readRow**](classffw_1_1_tga_loader.md#1aaaf42d2d93ba55205e8904dabad4de5a) (void \* dest) override |
|virtual void|[**close**](classffw_1_1_tga_loader.md#1af9065772dd4bfabe6da9e1e25a7f4009) () override |


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

### function <a id="1a3bf8387c6d21073fab279a9fa0ff139c" href="#1a3bf8387c6d21073fab279a9fa0ff139c">TgaLoader</a>

```cpp
ffw::TgaLoader::TgaLoader ()
```



### function <a id="1a9b1bc10f3531c9e9308b7d59a83e1c42" href="#1a9b1bc10f3531c9e9308b7d59a83e1c42">TgaLoader</a>

```cpp
ffw::TgaLoader::TgaLoader (
    const TgaLoader & other
) = delete
```



### function <a id="1a4371c43b9190d3d0536db7498d5c91ff" href="#1a4371c43b9190d3d0536db7498d5c91ff">TgaLoader</a>

```cpp
ffw::TgaLoader::TgaLoader (
    TgaLoader && other
)
```



### function <a id="1a6f5ab30806cccfbeb0cbf759fb65921e" href="#1a6f5ab30806cccfbeb0cbf759fb65921e">swap</a>

```cpp
void ffw::TgaLoader::swap (
    TgaLoader & other
)
```



### function <a id="1a955d3c68e20db3f319e0f85a02ac9bb2" href="#1a955d3c68e20db3f319e0f85a02ac9bb2">operator=</a>

```cpp
TgaLoader & ffw::TgaLoader::operator= (
    const TgaLoader & other
) = delete
```



### function <a id="1a84f05d8c750ded1fe8ba68a6b4e7e498" href="#1a84f05d8c750ded1fe8ba68a6b4e7e498">operator=</a>

```cpp
TgaLoader & ffw::TgaLoader::operator= (
    TgaLoader && other
)
```



### function <a id="1a2ba5eabfa85df8be309485eb1cb20268" href="#1a2ba5eabfa85df8be309485eb1cb20268">~TgaLoader</a>

```cpp
virtual ffw::TgaLoader::~TgaLoader ()
```



### function <a id="1a5928b3e055bb51852dc0e4240150b59a" href="#1a5928b3e055bb51852dc0e4240150b59a">open</a>

```cpp
virtual bool ffw::TgaLoader::open (
    const std::string & path
)
```

Overrides **[ImageReader::open](classffw_1_1_image_reader.md#1a7155f92f0f65eec33d9204ff4a63a518)**


### function <a id="1aaaf42d2d93ba55205e8904dabad4de5a" href="#1aaaf42d2d93ba55205e8904dabad4de5a">readRow</a>

```cpp
virtual size_t ffw::TgaLoader::readRow (
    void * dest
)
```

Overrides **[ImageReader::readRow](classffw_1_1_image_reader.md#1a4a172a49d03b415e5c0bb535af9599c9)**


### function <a id="1af9065772dd4bfabe6da9e1e25a7f4009" href="#1af9065772dd4bfabe6da9e1e25a7f4009">close</a>

```cpp
virtual void ffw::TgaLoader::close ()
```

Overrides **[ImageReader::close](classffw_1_1_image_reader.md#1aab601ee6de85c082b72214ed816d4c4d)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/media/tgaloader.h`
