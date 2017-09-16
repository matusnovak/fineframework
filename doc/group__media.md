media - Image and 3D object file loaders/savers
===================================

Provides classes for reading and writing image files and loadinf of 3D OBJ files. 

## Detailed description

Provides functions and classes to load and save image files such as PNG, JPG, PBM, BMP, TIF, TGA, and loading OBJ (3D objects) as well. Uses following third party libraries: [libjpeg](http://www.ijg.org/), [libpng](http://www.libpng.org/pub/png/libpng.html), [libtiff](http://www.libtiff.org/), and [libz](http://www.zlib.net/) 


## Classes

| Name |
|:-----|
| class [ffw::BmpLoader](ffw_BmpLoader.html) |
| class [ffw::BmpSaver](ffw_BmpSaver.html) |
| class [ffw::ImageReader](ffw_ImageReader.html) |
| class [ffw::ImageWriter](ffw_ImageWriter.html) |
| class [ffw::JpgLoader](ffw_JpgLoader.html) |
| class [ffw::JpgSaver](ffw_JpgSaver.html) |
| class [ffw::ObjLoader](ffw_ObjLoader.html) |
| class [ffw::PbmLoader](ffw_PbmLoader.html) |
| class [ffw::PbmSaver](ffw_PbmSaver.html) |
| class [ffw::PngLoader](ffw_PngLoader.html) |
| class [ffw::PngSaver](ffw_PngSaver.html) |
| class [ffw::TgaLoader](ffw_TgaLoader.html) |
| class [ffw::TgaSaver](ffw_TgaSaver.html) |
| class [ffw::TifLoader](ffw_TifLoader.html) |
| class [ffw::TifSaver](ffw_TifSaver.html) |


## Functions

| Type | Name |
| -------: | :------- |
|  ImageReader * | [openImageReader](#66d303c6) (const std::string & _path_)  |
|  ImageWriter * | [openImageWriter](#8ffae09c) (const std::string & _path_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _type_, int _quality_ = 100)  |
|  bool | [readImage](#9f3c979a) (const std::string & _path_, void ** _dest_, int * _width_, int * _height_, [ffw::ImageType](ffw.html#fa711f90) * _format_)  |
|  bool | [writeImage](#26e62acf) (const std::string & _path_, const void * _src_, int _width_, int _height_, [ffw::ImageType](ffw.html#fa711f90) _format_, int _quality_ = 100)  |
|  bool | [readImage](#fd2661e9) (const std::string & _path_, [ffw::ImageBuffer](ffw_ImageBuffer.html) & _image_)  |
|  [ffw::ImageBuffer](ffw_ImageBuffer.html) | [readImage](#07bb69e7) (const std::string & _path_)  |
|  bool | [writeImage](#2c1dd671) (const std::string & _path_, const [ffw::ImageBuffer](ffw_ImageBuffer.html) & _image_, int _quality_ = 100)  |
|  bool | [readObj](#d3cfdde0) (const std::string & _path_, float ** _vertices_, unsigned int * _numVertices_)  |


## Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="66d303c6" href="#66d303c6">openImageReader</a>

```cpp
ImageReader * openImageReader (
    const std::string & path
) 
```



### <span style="opacity:0.5;">function</span> <a id="8ffae09c" href="#8ffae09c">openImageWriter</a>

```cpp
ImageWriter * openImageWriter (
    const std::string & path,
    int width,
    int height,
    ffw::ImageType type,
    int quality = 100
) 
```



### <span style="opacity:0.5;">function</span> <a id="9f3c979a" href="#9f3c979a">readImage</a>

```cpp
bool readImage (
    const std::string & path,
    void ** dest,
    int * width,
    int * height,
    ffw::ImageType * format
) 
```



### <span style="opacity:0.5;">function</span> <a id="26e62acf" href="#26e62acf">writeImage</a>

```cpp
bool writeImage (
    const std::string & path,
    const void * src,
    int width,
    int height,
    ffw::ImageType format,
    int quality = 100
) 
```



### <span style="opacity:0.5;">function</span> <a id="fd2661e9" href="#fd2661e9">readImage</a>

```cpp
bool readImage (
    const std::string & path,
    ffw::ImageBuffer & image
) 
```



### <span style="opacity:0.5;">function</span> <a id="07bb69e7" href="#07bb69e7">readImage</a>

```cpp
ffw::ImageBuffer readImage (
    const std::string & path
) 
```



### <span style="opacity:0.5;">function</span> <a id="2c1dd671" href="#2c1dd671">writeImage</a>

```cpp
bool writeImage (
    const std::string & path,
    const ffw::ImageBuffer & image,
    int quality = 100
) 
```



### <span style="opacity:0.5;">function</span> <a id="d3cfdde0" href="#d3cfdde0">readObj</a>

```cpp
bool readObj (
    const std::string & path,
    float ** vertices,
    unsigned int * numVertices
) 
```





