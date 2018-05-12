---
search: false
---

# group media

Provides classes for reading and writing image files and loading of 3D OBJ files. [More...](#detailed-description)
## Classes

|Type|Name|
|-----|-----|
|class|[**ffw::BmpLoader**](classffw_1_1_bmp_loader.md)|
|class|[**ffw::BmpSaver**](classffw_1_1_bmp_saver.md)|
|class|[**ffw::DdsLoader**](classffw_1_1_dds_loader.md)|
|class|[**ffw::DdsSaver**](classffw_1_1_dds_saver.md)|
|class|[**ffw::ImageReader**](classffw_1_1_image_reader.md)|
|class|[**ffw::ImageWriter**](classffw_1_1_image_writer.md)|
|class|[**ffw::JpgLoader**](classffw_1_1_jpg_loader.md)|
|class|[**ffw::JpgSaver**](classffw_1_1_jpg_saver.md)|
|class|[**ffw::ObjLoader**](classffw_1_1_obj_loader.md)|
|class|[**ffw::PbmLoader**](classffw_1_1_pbm_loader.md)|
|class|[**ffw::PbmSaver**](classffw_1_1_pbm_saver.md)|
|class|[**ffw::PngLoader**](classffw_1_1_png_loader.md)|
|class|[**ffw::PngSaver**](classffw_1_1_png_saver.md)|
|class|[**ffw::TgaLoader**](classffw_1_1_tga_loader.md)|
|class|[**ffw::TgaSaver**](classffw_1_1_tga_saver.md)|
|class|[**ffw::TifLoader**](classffw_1_1_tif_loader.md)|
|class|[**ffw::TifSaver**](classffw_1_1_tif_saver.md)|


## Functions

|Type|Name|
|-----|-----|
|ImageReader \*|[**openImageReader**](group__media_.md#ga87e5ca033117b5fbfb132649d75185f5) (const std::string & path) |
|ImageWriter \*|[**openImageWriter**](group__media_.md#ga48161b9edfec370464b0f34e44f5cfe1) (const std::string & path, int width, int height, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** type, int quality = 100) |
|bool|[**readImage**](group__media_.md#ga25c072f18cc450f158787ef898a40b0c) (const std::string & path, void \*\* dest, int \* width, int \* height, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** \* format, int \* mips = NULL) |
|bool|[**writeImage**](group__media_.md#gad6dc94a496288bc08a7a16b20e509ac0) (const std::string & path, const void \* src, int width, int height, **[ffw::ImageType](namespaceffw.md#1a92226423d9aa0edfe0ca1dde2141e028)** format, int quality = 100, int mips = 1) |
|bool|[**readImage**](group__media_.md#gac28da3874e34bde73f3d8b116c34dda0) (const std::string & path, **[ffw::ImageBuffer](classffw_1_1_image_buffer.md)** & image) |
|bool|[**writeImage**](group__media_.md#ga23e75b6f8951cfb8067a2682229aacb6) (const std::string & path, const **[ffw::ImageBuffer](classffw_1_1_image_buffer.md)** & image, int quality = 100) |
|bool|[**readObj**](group__media_.md#ga6c79e9458a338f0003e5313f667641b3) (const std::string & path, float \*\* vertices, unsigned int \* numVertices) |


## Detailed Description

Uses the following third party libraries: [libjpeg](http://www.ijg.org/), [libpng](http://www.libpng.org/pub/png/libpng.html), [libtiff](http://www.libtiff.org/), and [libz](http://www.zlib.net/) 
## Functions Documentation

### function <a id="ga87e5ca033117b5fbfb132649d75185f5" href="#ga87e5ca033117b5fbfb132649d75185f5">openImageReader</a>

```cpp
ImageReader * media::openImageReader (
    const std::string & path
)
```



### function <a id="ga48161b9edfec370464b0f34e44f5cfe1" href="#ga48161b9edfec370464b0f34e44f5cfe1">openImageWriter</a>

```cpp
ImageWriter * media::openImageWriter (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100
)
```



### function <a id="ga25c072f18cc450f158787ef898a40b0c" href="#ga25c072f18cc450f158787ef898a40b0c">readImage</a>

```cpp
bool media::readImage (
    const std::string & path,
    void ** dest,
    int * width,
    int * height,
    ffw::ImageType * format,
    int * mips = NULL
)
```



### function <a id="gad6dc94a496288bc08a7a16b20e509ac0" href="#gad6dc94a496288bc08a7a16b20e509ac0">writeImage</a>

```cpp
bool media::writeImage (
    const std::string & path,
    const void * src,
    int width,
    int height,
    ffw::ImageType format,
    int quality = 100,
    int mips = 1
)
```



### function <a id="gac28da3874e34bde73f3d8b116c34dda0" href="#gac28da3874e34bde73f3d8b116c34dda0">readImage</a>

```cpp
bool media::readImage (
    const std::string & path,
    ffw::ImageBuffer & image
)
```



### function <a id="ga23e75b6f8951cfb8067a2682229aacb6" href="#ga23e75b6f8951cfb8067a2682229aacb6">writeImage</a>

```cpp
bool media::writeImage (
    const std::string & path,
    const ffw::ImageBuffer & image,
    int quality = 100
)
```



### function <a id="ga6c79e9458a338f0003e5313f667641b3" href="#ga6c79e9458a338f0003e5313f667641b3">readObj</a>

```cpp
bool media::readObj (
    const std::string & path,
    float ** vertices,
    unsigned int * numVertices
)
```



