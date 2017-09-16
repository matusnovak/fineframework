Texture
===================================


**Implemented by:** [ffw::Texture1D](ffw_Texture1D.html), [ffw::Texture1DArray](ffw_Texture1DArray.html), [ffw::Texture2D](ffw_Texture2D.html), [ffw::Texture2DArray](ffw_Texture2DArray.html), [ffw::Texture2DArrayMS](ffw_Texture2DArrayMS.html), [ffw::Texture2DMS](ffw_Texture2DMS.html), [ffw::Texture3D](ffw_Texture3D.html), [ffw::TextureCubemap](ffw_TextureCubemap.html), 

The documentation for this class was generated from: `include/ffw/graphics/texture.h`



## Public Types

| Type | Name |
| -------: | :------- |
| enum | [Filtering](#0342016e) |
| enum | [Wrapping](#e1626a42) |


## Protected Attributes

| Type | Name |
| -------: | :------- |
|  bool | [loaded_](#3712489e) |
|  unsigned int | [textureformat_](#5d93f702) |
|  unsigned int | [internalformat_](#d21c801d) |
|  unsigned int | [format_](#ecfcb0c7) |
|  unsigned int | [pixelformat_](#30be9b01) |
|  unsigned int | [buffer_](#357761a5) |
|  int | [width_](#40f402bd) |
|  int | [height_](#027f8ad6) |
|  int | [depth_](#6f38ebd2) |
|  int | [layers_](#e15bc835) |
|  bool | [mipmaps_](#68175277) |
|  bool | [initialized_](#78620727) |
|  int | [samples_](#5eda4ea3) |
|  const [RenderExtensions](ffw_RenderExtensions.html) * | [gl_](#52cddaa1) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Texture](#01b2641d) ()  |
|   | [Texture](#a988485b) (const [Texture](ffw_Texture.html) & _other_) = delete  |
|   | [Texture](#ebd529ea) ([Texture](ffw_Texture.html) && _other_)  |
|  void | [swap](#65f662f7) ([Texture](ffw_Texture.html) & _other_)  |
|  virtual  | [~Texture](#dbda44f2) ()  |
|  bool | [isCreated](#84ce8388) () const  |
|  void | [destroy](#97a0d99f) ()  |
|  void | [bind](#7f4f9eff) () const  |
|  void | [unbind](#e194da6f) () const  |
|  unsigned int | [getHandle](#49985807) () const  |
|  int | [getWidth](#88cc7d54) () const  |
|  int | [getHeight](#601ebb4a) () const  |
|  int | [getLayers](#f4ba027d) () const  |
|  int | [getDepth](#ee377ec5) () const  |
|  int | [getSamples](#6ba63b6e) () const  |
|  unsigned int | [getInternalFormat](#fce3679f) () const  |
|  unsigned int | [getFormat](#30486275) () const  |
|  unsigned int | [getPixelFormat](#eff9ff9a) () const  |
|  unsigned int | [getTextureFormat](#3dc19096) () const  |
|  void | [setEnvParami](#47bd0fcc) (unsigned int _Target_, unsigned int _Name_, int _Value_)  |
|  void | [setEnvParamf](#e920eadf) (unsigned int _Target_, unsigned int _Name_, float _Value_)  |
|  void | [setTexParami](#8da9b27f) (unsigned int _Name_, int _Value_)  |
|  void | [setTexParamiv](#16de1a6a) (unsigned int _Name_, int * _Values_)  |
|  void | [setTexParamf](#f811fa82) (unsigned int _Name_, float _Value_)  |
|  void | [setTexParamfv](#5945ac50) (unsigned int _Name_, float * _Values_)  |
|  bool | [generateMipmaps](#6add236e) ()  |
|  void | [setFiltering](#c441998e) ([Texture::Filtering](ffw_Texture.html#0342016e) _filtering_)  |
|  void | [setWrapping](#3edc29d4) ([Texture::Wrapping](ffw_Texture.html#e1626a42) _wrapping_)  |
|  [Texture](ffw_Texture.html) & | [operator=](#eeca55f9) (const [Texture](ffw_Texture.html) & _other_) = delete  |
|  [Texture](ffw_Texture.html) & | [operator=](#24b442db) ([Texture](ffw_Texture.html) && _other_)  |


## Public Types Documentation

### <span style="opacity:0.5;">enum</span> <a id="0342016e" href="#0342016e">Filtering</a>

```cpp
enum Filtering {
    NEAREST,
    LINEAR,
    MIPMAP_NEAREST,
    MIPMAP_LINEAR,
}
```



### <span style="opacity:0.5;">enum</span> <a id="e1626a42" href="#e1626a42">Wrapping</a>

```cpp
enum Wrapping {
    REPEAT,
    MIRRORED_REPEAT,
    CLAMP_TO_EDGE,
}
```





## Protected Attributes Documentation

### <span style="opacity:0.5;">variable</span> <a id="3712489e" href="#3712489e">loaded_</a>

```cpp
bool loaded_
```



### <span style="opacity:0.5;">variable</span> <a id="5d93f702" href="#5d93f702">textureformat_</a>

```cpp
unsigned int textureformat_
```



### <span style="opacity:0.5;">variable</span> <a id="d21c801d" href="#d21c801d">internalformat_</a>

```cpp
unsigned int internalformat_
```



### <span style="opacity:0.5;">variable</span> <a id="ecfcb0c7" href="#ecfcb0c7">format_</a>

```cpp
unsigned int format_
```



### <span style="opacity:0.5;">variable</span> <a id="30be9b01" href="#30be9b01">pixelformat_</a>

```cpp
unsigned int pixelformat_
```



### <span style="opacity:0.5;">variable</span> <a id="357761a5" href="#357761a5">buffer_</a>

```cpp
unsigned int buffer_
```



### <span style="opacity:0.5;">variable</span> <a id="40f402bd" href="#40f402bd">width_</a>

```cpp
int width_
```



### <span style="opacity:0.5;">variable</span> <a id="027f8ad6" href="#027f8ad6">height_</a>

```cpp
int height_
```



### <span style="opacity:0.5;">variable</span> <a id="6f38ebd2" href="#6f38ebd2">depth_</a>

```cpp
int depth_
```



### <span style="opacity:0.5;">variable</span> <a id="e15bc835" href="#e15bc835">layers_</a>

```cpp
int layers_
```



### <span style="opacity:0.5;">variable</span> <a id="68175277" href="#68175277">mipmaps_</a>

```cpp
bool mipmaps_
```



### <span style="opacity:0.5;">variable</span> <a id="78620727" href="#78620727">initialized_</a>

```cpp
bool initialized_
```



### <span style="opacity:0.5;">variable</span> <a id="5eda4ea3" href="#5eda4ea3">samples_</a>

```cpp
int samples_
```



### <span style="opacity:0.5;">variable</span> <a id="52cddaa1" href="#52cddaa1">gl_</a>

```cpp
const RenderExtensions * gl_
```





## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="01b2641d" href="#01b2641d">Texture</a>

```cpp
 Texture () 
```



### <span style="opacity:0.5;">function</span> <a id="a988485b" href="#a988485b">Texture</a>

```cpp
 Texture (
    const Texture & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="ebd529ea" href="#ebd529ea">Texture</a>

```cpp
 Texture (
    Texture && other
) 
```



### <span style="opacity:0.5;">function</span> <a id="65f662f7" href="#65f662f7">swap</a>

```cpp
void swap (
    Texture & other
) 
```



### <span style="opacity:0.5;">function</span> <a id="dbda44f2" href="#dbda44f2">~Texture</a>

```cpp
virtual  ~Texture () 
```



### <span style="opacity:0.5;">function</span> <a id="84ce8388" href="#84ce8388">isCreated</a>

```cpp
inline bool isCreated () const 
```



### <span style="opacity:0.5;">function</span> <a id="97a0d99f" href="#97a0d99f">destroy</a>

```cpp
void destroy () 
```



### <span style="opacity:0.5;">function</span> <a id="7f4f9eff" href="#7f4f9eff">bind</a>

```cpp
void bind () const 
```



### <span style="opacity:0.5;">function</span> <a id="e194da6f" href="#e194da6f">unbind</a>

```cpp
void unbind () const 
```



### <span style="opacity:0.5;">function</span> <a id="49985807" href="#49985807">getHandle</a>

```cpp
inline unsigned int getHandle () const 
```



### <span style="opacity:0.5;">function</span> <a id="88cc7d54" href="#88cc7d54">getWidth</a>

```cpp
inline int getWidth () const 
```



### <span style="opacity:0.5;">function</span> <a id="601ebb4a" href="#601ebb4a">getHeight</a>

```cpp
inline int getHeight () const 
```



### <span style="opacity:0.5;">function</span> <a id="f4ba027d" href="#f4ba027d">getLayers</a>

```cpp
inline int getLayers () const 
```



### <span style="opacity:0.5;">function</span> <a id="ee377ec5" href="#ee377ec5">getDepth</a>

```cpp
inline int getDepth () const 
```



### <span style="opacity:0.5;">function</span> <a id="6ba63b6e" href="#6ba63b6e">getSamples</a>

```cpp
inline int getSamples () const 
```



### <span style="opacity:0.5;">function</span> <a id="fce3679f" href="#fce3679f">getInternalFormat</a>

```cpp
inline unsigned int getInternalFormat () const 
```



### <span style="opacity:0.5;">function</span> <a id="30486275" href="#30486275">getFormat</a>

```cpp
inline unsigned int getFormat () const 
```



### <span style="opacity:0.5;">function</span> <a id="eff9ff9a" href="#eff9ff9a">getPixelFormat</a>

```cpp
inline unsigned int getPixelFormat () const 
```



### <span style="opacity:0.5;">function</span> <a id="3dc19096" href="#3dc19096">getTextureFormat</a>

```cpp
inline unsigned int getTextureFormat () const 
```



### <span style="opacity:0.5;">function</span> <a id="47bd0fcc" href="#47bd0fcc">setEnvParami</a>

```cpp
void setEnvParami (
    unsigned int Target,
    unsigned int Name,
    int Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="e920eadf" href="#e920eadf">setEnvParamf</a>

```cpp
void setEnvParamf (
    unsigned int Target,
    unsigned int Name,
    float Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="8da9b27f" href="#8da9b27f">setTexParami</a>

```cpp
void setTexParami (
    unsigned int Name,
    int Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="16de1a6a" href="#16de1a6a">setTexParamiv</a>

```cpp
void setTexParamiv (
    unsigned int Name,
    int * Values
) 
```



### <span style="opacity:0.5;">function</span> <a id="f811fa82" href="#f811fa82">setTexParamf</a>

```cpp
void setTexParamf (
    unsigned int Name,
    float Value
) 
```



### <span style="opacity:0.5;">function</span> <a id="5945ac50" href="#5945ac50">setTexParamfv</a>

```cpp
void setTexParamfv (
    unsigned int Name,
    float * Values
) 
```



### <span style="opacity:0.5;">function</span> <a id="6add236e" href="#6add236e">generateMipmaps</a>

```cpp
bool generateMipmaps () 
```



### <span style="opacity:0.5;">function</span> <a id="c441998e" href="#c441998e">setFiltering</a>

```cpp
void setFiltering (
    Texture::Filtering filtering
) 
```



### <span style="opacity:0.5;">function</span> <a id="3edc29d4" href="#3edc29d4">setWrapping</a>

```cpp
void setWrapping (
    Texture::Wrapping wrapping
) 
```



### <span style="opacity:0.5;">function</span> <a id="eeca55f9" href="#eeca55f9">operator=</a>

```cpp
Texture & operator= (
    const Texture & other
) = delete 
```



### <span style="opacity:0.5;">function</span> <a id="24b442db" href="#24b442db">operator=</a>

```cpp
Texture & operator= (
    Texture && other
) 
```





