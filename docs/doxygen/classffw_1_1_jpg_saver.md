---
search: false
---

# class ffw::JpgSaver



Inherits the following classes: **[ffw::ImageWriter](classffw_1_1_image_writer.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**JpgSaver**](classffw_1_1_jpg_saver.md#1a95d86fa2d8dc04e5f106169f1b85a015) () |
||[**JpgSaver**](classffw_1_1_jpg_saver.md#1a4abb04bd88594bfeca7d7aad201c023c) (const **[JpgSaver](classffw_1_1_jpg_saver.md)** & other) = delete |
||[**JpgSaver**](classffw_1_1_jpg_saver.md#1a17ab1690e9331e2aba32bcffefed5e7a) (**[JpgSaver](classffw_1_1_jpg_saver.md)** && other) |
|void|[**swap**](classffw_1_1_jpg_saver.md#1a18e49002e7efebc6ceb1f8a2800af7f3) (**[JpgSaver](classffw_1_1_jpg_saver.md)** & other) |
|**[JpgSaver](classffw_1_1_jpg_saver.md)** &|[**operator=**](classffw_1_1_jpg_saver.md#1a1b35c6c0a115d507716db180e5ea60c9) (const **[JpgSaver](classffw_1_1_jpg_saver.md)** & other) = delete |
|**[JpgSaver](classffw_1_1_jpg_saver.md)** &|[**operator=**](classffw_1_1_jpg_saver.md#1a96304fc21677657fe7e58bdbcb173a31) (**[JpgSaver](classffw_1_1_jpg_saver.md)** && other) |
|virtual |[**~JpgSaver**](classffw_1_1_jpg_saver.md#1a2010dc1c689def509062477b76bc7cbd) () |
|virtual bool|[**open**](classffw_1_1_jpg_saver.md#1aa3d510cb26a58a5f45665cb6c55dd855) (const std::string & path, int width, int height, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** type, int quality = 100, int mips = 1) override |
|virtual size\_t|[**writeRow**](classffw_1_1_jpg_saver.md#1a522dfe57eb5b72706652d610c70bfa36) (const void \* src) override |
|virtual bool|[**writeFooter**](classffw_1_1_jpg_saver.md#1afff08ce3229e64572f4374d8b52d88df) () override |
|virtual void|[**close**](classffw_1_1_jpg_saver.md#1ad764307af3135120b5a67cac879769e1) () override |


#### Public Functions inherited from [ffw::ImageWriter](classffw_1_1_image_writer.md)

|Type|Name|
|-----|-----|
||[**ImageWriter**](classffw_1_1_image_writer.md#1a0fd08e680ce039ae73f95aee64496987) () |
|virtual |[**~ImageWriter**](classffw_1_1_image_writer.md#1ace63bec05eb60104b74de3a870eec386) () |
|bool|[**writeAll**](classffw_1_1_image_writer.md#1a95934c31ae9550a2a0a57c2b352a80bc) (void \* dest) |
|bool|[**writeAll**](classffw_1_1_image_writer.md#1ac1271761a010069b418d157e7ea4cea3) (**[ffw::ImageBuffer](classffw_1_1_image_buffer.md)** & buffer) |
|virtual bool|[**setMipMap**](classffw_1_1_image_writer.md#1ac261ab25f1985989831105d3cbcf81e8) (int level) |
|bool|[**eof**](classffw_1_1_image_writer.md#1a5b1c288ec150d346cf0b15cb59f2d61f) () const |
||[**operator bool**](classffw_1_1_image_writer.md#1ab54e10e6ab91958cee30ddfd7949830a) () const |
|int|[**getRowOffset**](classffw_1_1_image_writer.md#1a65502c51bc454d2829ce3482d206a1e8) () const |
|bool|[**isOpen**](classffw_1_1_image_writer.md#1afc935a20677f4f310088dc831b302eb3) () const |
|int|[**getNumOfMipMaps**](classffw_1_1_image_writer.md#1a5caee208812977bba6514290f10acbba) () const |
|int|[**getMipMapOffset**](classffw_1_1_image_writer.md#1a093d6cc0ba73b35b3741167a362c47a4) () const |


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

#### Protected Attributes inherited from [ffw::ImageWriter](classffw_1_1_image_writer.md)

|Type|Name|
|-----|-----|
|bool|[**loaded**](classffw_1_1_image_writer.md#1a4d09307b38ab24200f4c48acf7388f02)|
|int|[**row**](classffw_1_1_image_writer.md#1af45929e45e8a77eafd5385f6e0ec0a1e)|
|int|[**mipmapOffset**](classffw_1_1_image_writer.md#1a5818fb22b1bea07fdf05dbd24d9aa15e)|
|int|[**mipmaps**](classffw_1_1_image_writer.md#1afa8dd4585158b44e4719b20358966328)|


#### Protected Attributes inherited from [ffw::ImageFormat](classffw_1_1_image_format.md)

|Type|Name|
|-----|-----|
|**[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)**|[**format**](classffw_1_1_image_format.md#1a00569cba5e7d8df7582554718f908d7e)|
|int|[**width**](classffw_1_1_image_format.md#1a1a26d9b05851d073858b34ccabc40a79)|
|int|[**height**](classffw_1_1_image_format.md#1a7c62585ac46e6fc7c3fe6efab59cfd4c)|
|int|[**depth**](classffw_1_1_image_format.md#1a128894191ad04073b44663b8541f97aa)|


## Public Functions Documentation

### function <a id="1a95d86fa2d8dc04e5f106169f1b85a015" href="#1a95d86fa2d8dc04e5f106169f1b85a015">JpgSaver</a>

```cpp
ffw::JpgSaver::JpgSaver ()
```



### function <a id="1a4abb04bd88594bfeca7d7aad201c023c" href="#1a4abb04bd88594bfeca7d7aad201c023c">JpgSaver</a>

```cpp
ffw::JpgSaver::JpgSaver (
    const JpgSaver & other
) = delete
```



### function <a id="1a17ab1690e9331e2aba32bcffefed5e7a" href="#1a17ab1690e9331e2aba32bcffefed5e7a">JpgSaver</a>

```cpp
ffw::JpgSaver::JpgSaver (
    JpgSaver && other
)
```



### function <a id="1a18e49002e7efebc6ceb1f8a2800af7f3" href="#1a18e49002e7efebc6ceb1f8a2800af7f3">swap</a>

```cpp
void ffw::JpgSaver::swap (
    JpgSaver & other
)
```



### function <a id="1a1b35c6c0a115d507716db180e5ea60c9" href="#1a1b35c6c0a115d507716db180e5ea60c9">operator=</a>

```cpp
JpgSaver & ffw::JpgSaver::operator= (
    const JpgSaver & other
) = delete
```



### function <a id="1a96304fc21677657fe7e58bdbcb173a31" href="#1a96304fc21677657fe7e58bdbcb173a31">operator=</a>

```cpp
JpgSaver & ffw::JpgSaver::operator= (
    JpgSaver && other
)
```



### function <a id="1a2010dc1c689def509062477b76bc7cbd" href="#1a2010dc1c689def509062477b76bc7cbd">~JpgSaver</a>

```cpp
virtual ffw::JpgSaver::~JpgSaver ()
```



### function <a id="1aa3d510cb26a58a5f45665cb6c55dd855" href="#1aa3d510cb26a58a5f45665cb6c55dd855">open</a>

```cpp
virtual bool ffw::JpgSaver::open (
    const std::string & path
    int width
    int height
    ffw::ImageType type
    int quality = 100
    int mips = 1
)
```

Overrides **[ImageWriter::open](classffw_1_1_image_writer.md#1ab549a1367fdab422ff4c6b41f3e91f15)**


### function <a id="1a522dfe57eb5b72706652d610c70bfa36" href="#1a522dfe57eb5b72706652d610c70bfa36">writeRow</a>

```cpp
virtual size_t ffw::JpgSaver::writeRow (
    const void * src
)
```

Overrides **[ImageWriter::writeRow](classffw_1_1_image_writer.md#1ae3ab21e0cae7dc204aeebdf4ef58337d)**


### function <a id="1afff08ce3229e64572f4374d8b52d88df" href="#1afff08ce3229e64572f4374d8b52d88df">writeFooter</a>

```cpp
virtual bool ffw::JpgSaver::writeFooter ()
```

Overrides **[ImageWriter::writeFooter](classffw_1_1_image_writer.md#1a38a3ee7a3c1580737c141ffd2569f75d)**


### function <a id="1ad764307af3135120b5a67cac879769e1" href="#1ad764307af3135120b5a67cac879769e1">close</a>

```cpp
virtual void ffw::JpgSaver::close ()
```

Overrides **[ImageWriter::close](classffw_1_1_image_writer.md#1a0b18fcad15107286a29b65b6b88fb20b)**




----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/media/jpgsaver.h`
