Framebuffer
===================================


The documentation for this class was generated from: `include/ffw/graphics/framebuffer.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Framebuffer](#cbdc1833) ()  |
|   | [Framebuffer](#cac36763) (const [Framebuffer](ffw_Framebuffer.html) & _other_) = delete  |
|   | [Framebuffer](#395ffc13) ([Framebuffer](ffw_Framebuffer.html) && _other_)  |
|  void | [swap](#3ccaa21a) ([Framebuffer](ffw_Framebuffer.html) & _other_)  |
|   | [~Framebuffer](#d20a7379) ()  |
|  bool | [isCreated](#6e7996e6) () const  |
|  bool | [create](#48fb6571) ()  |
|  bool | [addColorTexture](#22669d61) (const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, int _mip_ = 0)  |
|  bool | [addCubemapTexture](#36c3274b) (const [ffw::TextureCubemap](ffw_TextureCubemap.html) * _texture_, int _side_, int _mip_ = 0)  |
|  bool | [addDepthTexture](#419f17e6) (const [ffw::Texture2D](ffw_Texture2D.html) * _texture_, int _mip_ = 0)  |
|  bool | [addColorTextureMS](#d83356c1) (const [ffw::Texture2DMS](ffw_Texture2DMS.html) * _texture_, int _mip_ = 0)  |
|  bool | [addDepthTextureMS](#34c22216) (const [ffw::Texture2DMS](ffw_Texture2DMS.html) * _texture_, int _mip_ = 0)  |
|  bool | [addColorRenderbuffer](#44882ad0) (const [ffw::Renderbuffer2D](ffw_Renderbuffer2D.html) * _texture_)  |
|  bool | [addDepthRenderbuffer](#ea713f27) (const [ffw::Renderbuffer2D](ffw_Renderbuffer2D.html) * _texture_)  |
|  bool | [addColorRenderbufferMS](#9bed5c26) (const [ffw::Renderbuffer2DMS](ffw_Renderbuffer2DMS.html) * _texture_)  |
|  bool | [addDepthRenderbufferMS](#bd3edd14) (const [ffw::Renderbuffer2DMS](ffw_Renderbuffer2DMS.html) * _texture_)  |
|  bool | [checkStatus](#e70eba1b) ()  |
|  unsigned int | [getHandle](#0aa95a34) () const  |
|  void | [resetColorCount](#ad57aff6) ()  |
|  bool | [destroy](#f35d6d8e) ()  |
|  void | [bind](#02b41d77) () const  |
|  void | [unbind](#1ab39037) () const  |
|  [Framebuffer](ffw_Framebuffer.html) & | [operator=](#824e8bcd) (const [Framebuffer](ffw_Framebuffer.html) & _other_) = delete  |
|  [Framebuffer](ffw_Framebuffer.html) & | [operator=](#98aced71) ([Framebuffer](ffw_Framebuffer.html) && _other_)  |


## Public Functions Documentation

### _function_ <a id="cbdc1833" href="#cbdc1833">Framebuffer</a>

```cpp
 Framebuffer () 
```



### _function_ <a id="cac36763" href="#cac36763">Framebuffer</a>

```cpp
 Framebuffer (
    const Framebuffer & other
) = delete 
```



### _function_ <a id="395ffc13" href="#395ffc13">Framebuffer</a>

```cpp
 Framebuffer (
    Framebuffer && other
) 
```



### _function_ <a id="3ccaa21a" href="#3ccaa21a">swap</a>

```cpp
void swap (
    Framebuffer & other
) 
```



### _function_ <a id="d20a7379" href="#d20a7379">~Framebuffer</a>

```cpp
 ~Framebuffer () 
```



### _function_ <a id="6e7996e6" href="#6e7996e6">isCreated</a>

```cpp
inline bool isCreated () const 
```



### _function_ <a id="48fb6571" href="#48fb6571">create</a>

```cpp
bool create () 
```



### _function_ <a id="22669d61" href="#22669d61">addColorTexture</a>

```cpp
bool addColorTexture (
    const ffw::Texture2D * texture,
    int mip = 0
) 
```



### _function_ <a id="36c3274b" href="#36c3274b">addCubemapTexture</a>

```cpp
bool addCubemapTexture (
    const ffw::TextureCubemap * texture,
    int side,
    int mip = 0
) 
```



### _function_ <a id="419f17e6" href="#419f17e6">addDepthTexture</a>

```cpp
bool addDepthTexture (
    const ffw::Texture2D * texture,
    int mip = 0
) 
```



### _function_ <a id="d83356c1" href="#d83356c1">addColorTextureMS</a>

```cpp
bool addColorTextureMS (
    const ffw::Texture2DMS * texture,
    int mip = 0
) 
```



### _function_ <a id="34c22216" href="#34c22216">addDepthTextureMS</a>

```cpp
bool addDepthTextureMS (
    const ffw::Texture2DMS * texture,
    int mip = 0
) 
```



### _function_ <a id="44882ad0" href="#44882ad0">addColorRenderbuffer</a>

```cpp
bool addColorRenderbuffer (
    const ffw::Renderbuffer2D * texture
) 
```



### _function_ <a id="ea713f27" href="#ea713f27">addDepthRenderbuffer</a>

```cpp
bool addDepthRenderbuffer (
    const ffw::Renderbuffer2D * texture
) 
```



### _function_ <a id="9bed5c26" href="#9bed5c26">addColorRenderbufferMS</a>

```cpp
bool addColorRenderbufferMS (
    const ffw::Renderbuffer2DMS * texture
) 
```



### _function_ <a id="bd3edd14" href="#bd3edd14">addDepthRenderbufferMS</a>

```cpp
bool addDepthRenderbufferMS (
    const ffw::Renderbuffer2DMS * texture
) 
```



### _function_ <a id="e70eba1b" href="#e70eba1b">checkStatus</a>

```cpp
bool checkStatus () 
```



### _function_ <a id="0aa95a34" href="#0aa95a34">getHandle</a>

```cpp
inline unsigned int getHandle () const 
```



### _function_ <a id="ad57aff6" href="#ad57aff6">resetColorCount</a>

```cpp
inline void resetColorCount () 
```



### _function_ <a id="f35d6d8e" href="#f35d6d8e">destroy</a>

```cpp
bool destroy () 
```



### _function_ <a id="02b41d77" href="#02b41d77">bind</a>

```cpp
void bind () const 
```



### _function_ <a id="1ab39037" href="#1ab39037">unbind</a>

```cpp
void unbind () const 
```



### _function_ <a id="824e8bcd" href="#824e8bcd">operator=</a>

```cpp
Framebuffer & operator= (
    const Framebuffer & other
) = delete 
```



### _function_ <a id="98aced71" href="#98aced71">operator=</a>

```cpp
Framebuffer & operator= (
    Framebuffer && other
) 
```





