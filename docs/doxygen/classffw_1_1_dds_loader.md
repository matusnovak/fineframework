---
search: false
---

# class ffw::DdsLoader



Inherits the following classes: **[ffw::ImageReader](classffw_1_1_image_reader.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**DdsLoader**](classffw_1_1_dds_loader.md#1a5fa5de1c863c20fbfeb9c0f959afc03f) () |
||[**DdsLoader**](classffw_1_1_dds_loader.md#1a46692564e4588977bf4154294e11096a) (const **[DdsLoader](classffw_1_1_dds_loader.md)** & other) = delete |
||[**DdsLoader**](classffw_1_1_dds_loader.md#1a24e2d01fb679ccaa471f73beaa8e75e3) (**[DdsLoader](classffw_1_1_dds_loader.md)** && other) |
|void|[**swap**](classffw_1_1_dds_loader.md#1a930a29f667b057ab59701f896193e7f8) (**[DdsLoader](classffw_1_1_dds_loader.md)** & other) |
|**[DdsLoader](classffw_1_1_dds_loader.md)** &|[**operator=**](classffw_1_1_dds_loader.md#1adb608d1293b8bd2398401224bc9dd465) (const **[DdsLoader](classffw_1_1_dds_loader.md)** & other) = delete |
|**[DdsLoader](classffw_1_1_dds_loader.md)** &|[**operator=**](classffw_1_1_dds_loader.md#1afcde64a30f738dacb7dbc5b95567c86e) (**[DdsLoader](classffw_1_1_dds_loader.md)** && other) |
|virtual |[**~DdsLoader**](classffw_1_1_dds_loader.md#1a8e812f0de726009ecbe5124672bfd40f) () |
|virtual bool|[**open**](classffw_1_1_dds_loader.md#1a9e3049b7df92b512b1fa23169d468b38) (const std::string & path) override |
|virtual size\_t|[**readRow**](classffw_1_1_dds_loader.md#1aec7e0de483415718bec55880740f33a4) (void \* dest) override |
|virtual bool|[**getMipMap**](classffw_1_1_dds_loader.md#1a7c0879cf5ee9c7bbbadc2fe730e6d982) (int level) override |
|bool|[**getCubemap**](classffw_1_1_dds_loader.md#1a54aacd3f13b3c141aa91b383cbcb4b34) (int side) |
|virtual void|[**close**](classffw_1_1_dds_loader.md#1afa54cf1304889667d5172b6a2887f26b) () override |
|bool|[**isCubemap**](classffw_1_1_dds_loader.md#1a79e052d2e3c984e11e2fdac3c7657344) () const |
|int|[**getCubemapOffset**](classffw_1_1_dds_loader.md#1a617ff567ddf34a5d10628a7964aed8b5) () const |


#### Public Functions inherited from [ffw::ImageReader](classffw_1_1_image_reader.md)

|Type|Name|
|-----|-----|
||[**ImageReader**](classffw_1_1_image_reader.md#1aa8c4726989a7fa3a5cdeee4141ec69f1) () |
|virtual |[**~ImageReader**](classffw_1_1_image_reader.md#1a84fd72d1a2d7474d727b21745eab497b) () |
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

### function <a id="1a5fa5de1c863c20fbfeb9c0f959afc03f" href="#1a5fa5de1c863c20fbfeb9c0f959afc03f">DdsLoader</a>

```cpp
ffw::DdsLoader::DdsLoader ()
```



### function <a id="1a46692564e4588977bf4154294e11096a" href="#1a46692564e4588977bf4154294e11096a">DdsLoader</a>

```cpp
ffw::DdsLoader::DdsLoader (
    const DdsLoader & other
) = delete
```



### function <a id="1a24e2d01fb679ccaa471f73beaa8e75e3" href="#1a24e2d01fb679ccaa471f73beaa8e75e3">DdsLoader</a>

```cpp
ffw::DdsLoader::DdsLoader (
    DdsLoader && other
)
```



### function <a id="1a930a29f667b057ab59701f896193e7f8" href="#1a930a29f667b057ab59701f896193e7f8">swap</a>

```cpp
void ffw::DdsLoader::swap (
    DdsLoader & other
)
```



### function <a id="1adb608d1293b8bd2398401224bc9dd465" href="#1adb608d1293b8bd2398401224bc9dd465">operator=</a>

```cpp
DdsLoader & ffw::DdsLoader::operator= (
    const DdsLoader & other
) = delete
```



### function <a id="1afcde64a30f738dacb7dbc5b95567c86e" href="#1afcde64a30f738dacb7dbc5b95567c86e">operator=</a>

```cpp
DdsLoader & ffw::DdsLoader::operator= (
    DdsLoader && other
)
```



### function <a id="1a8e812f0de726009ecbe5124672bfd40f" href="#1a8e812f0de726009ecbe5124672bfd40f">~DdsLoader</a>

```cpp
virtual ffw::DdsLoader::~DdsLoader ()
```



### function <a id="1a9e3049b7df92b512b1fa23169d468b38" href="#1a9e3049b7df92b512b1fa23169d468b38">open</a>

```cpp
virtual bool ffw::DdsLoader::open (
    const std::string & path
)
```

Overrides **[ImageReader::open](classffw_1_1_image_reader.md#1a7155f92f0f65eec33d9204ff4a63a518)**


### function <a id="1aec7e0de483415718bec55880740f33a4" href="#1aec7e0de483415718bec55880740f33a4">readRow</a>

```cpp
virtual size_t ffw::DdsLoader::readRow (
    void * dest
)
```

Overrides **[ImageReader::readRow](classffw_1_1_image_reader.md#1a4a172a49d03b415e5c0bb535af9599c9)**


### function <a id="1a7c0879cf5ee9c7bbbadc2fe730e6d982" href="#1a7c0879cf5ee9c7bbbadc2fe730e6d982">getMipMap</a>

```cpp
virtual bool ffw::DdsLoader::getMipMap (
    int level
)
```

Overrides **[ImageReader::getMipMap](classffw_1_1_image_reader.md#1a9b243ebae163d4ad5b29e5df1d48b93d)**


### function <a id="1a54aacd3f13b3c141aa91b383cbcb4b34" href="#1a54aacd3f13b3c141aa91b383cbcb4b34">getCubemap</a>

```cpp
bool ffw::DdsLoader::getCubemap (
    int side
)
```



### function <a id="1afa54cf1304889667d5172b6a2887f26b" href="#1afa54cf1304889667d5172b6a2887f26b">close</a>

```cpp
virtual void ffw::DdsLoader::close ()
```

Overrides **[ImageReader::close](classffw_1_1_image_reader.md#1aab601ee6de85c082b72214ed816d4c4d)**


### function <a id="1a79e052d2e3c984e11e2fdac3c7657344" href="#1a79e052d2e3c984e11e2fdac3c7657344">isCubemap</a>

```cpp
bool ffw::DdsLoader::isCubemap () const
```



### function <a id="1a617ff567ddf34a5d10628a7964aed8b5" href="#1a617ff567ddf34a5d10628a7964aed8b5">getCubemapOffset</a>

```cpp
int ffw::DdsLoader::getCubemapOffset () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/media/ddsloader.h`
