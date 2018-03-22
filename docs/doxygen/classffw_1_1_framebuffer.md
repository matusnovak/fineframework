---
search:
    keywords: ['ffw::Framebuffer', 'Framebuffer', 'Framebuffer', 'Framebuffer', 'swap', '~Framebuffer', 'isCreated', 'create', 'addColorTexture', 'addCubemapTexture', 'addDepthTexture', 'addColorTextureMS', 'addDepthTextureMS', 'addColorRenderbuffer', 'addDepthRenderbuffer', 'addColorRenderbufferMS', 'addDepthRenderbufferMS', 'checkStatus', 'getHandle', 'resetColorCount', 'destroy', 'bind', 'unbind', 'operator=', 'operator=']
---

# class ffw::Framebuffer

## Public Functions

|Type|Name|
|-----|-----|
||[**Framebuffer**](classffw_1_1_framebuffer.md#1a934d32601dcd69dab1cbb3cab2937cad) () |
||[**Framebuffer**](classffw_1_1_framebuffer.md#1aec740a7e58dbb78720654fb1705d18a5) (const **[Framebuffer](classffw_1_1_framebuffer.md)** & other) = delete |
||[**Framebuffer**](classffw_1_1_framebuffer.md#1a2d09f2e68864fd65e37ff1652fbcc61d) (**[Framebuffer](classffw_1_1_framebuffer.md)** && other) |
|void|[**swap**](classffw_1_1_framebuffer.md#1a4644aaf6f77e6380cff0ddeadd131a12) (**[Framebuffer](classffw_1_1_framebuffer.md)** & other) |
||[**~Framebuffer**](classffw_1_1_framebuffer.md#1a5fac7b441e2c97098b6256e0af601ae6) () |
|bool|[**isCreated**](classffw_1_1_framebuffer.md#1a7c1f98d179f746bf2f26bf1eed95f9fd) () const |
|bool|[**create**](classffw_1_1_framebuffer.md#1ad5108eaf30a33c4690ac00f97cb199b8) () |
|bool|[**addColorTexture**](classffw_1_1_framebuffer.md#1a9582e8ddd25e0b4ae4fb0a695b2eb308) (const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, int mip = 0) |
|bool|[**addCubemapTexture**](classffw_1_1_framebuffer.md#1a3f54ead2e40950583c35589bde7767f8) (const **[ffw::TextureCubemap](classffw_1_1_texture_cubemap.md)** \* texture, int side, int mip = 0) |
|bool|[**addDepthTexture**](classffw_1_1_framebuffer.md#1abb46bb706c04b997981c55e791c39cfe) (const **[ffw::Texture2D](classffw_1_1_texture2_d.md)** \* texture, int mip = 0) |
|bool|[**addColorTextureMS**](classffw_1_1_framebuffer.md#1add2c0d4e118d524055e59f24b9d79b8e) (const **[ffw::Texture2DMS](classffw_1_1_texture2_d_m_s.md)** \* texture, int mip = 0) |
|bool|[**addDepthTextureMS**](classffw_1_1_framebuffer.md#1adb3aaf092d5fa55296bc5f82be28b3fe) (const **[ffw::Texture2DMS](classffw_1_1_texture2_d_m_s.md)** \* texture, int mip = 0) |
|bool|[**addColorRenderbuffer**](classffw_1_1_framebuffer.md#1a09a4c7ea2fb2a8351b5674416b36d295) (const **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)** \* texture) |
|bool|[**addDepthRenderbuffer**](classffw_1_1_framebuffer.md#1a4b9eff078631930f19a83bfc04b637aa) (const **[ffw::Renderbuffer2D](classffw_1_1_renderbuffer2_d.md)** \* texture) |
|bool|[**addColorRenderbufferMS**](classffw_1_1_framebuffer.md#1a9de525b69c4abc44f6186dc571d6b274) (const **[ffw::Renderbuffer2DMS](classffw_1_1_renderbuffer2_d_m_s.md)** \* texture) |
|bool|[**addDepthRenderbufferMS**](classffw_1_1_framebuffer.md#1a89b18d1f9fc6d6ad01866d9f385f4af3) (const **[ffw::Renderbuffer2DMS](classffw_1_1_renderbuffer2_d_m_s.md)** \* texture) |
|bool|[**checkStatus**](classffw_1_1_framebuffer.md#1a9553b7deb789fd727b0287879846bc69) () |
|unsigned int|[**getHandle**](classffw_1_1_framebuffer.md#1a399e05f0243f71c62616d9a688a19083) () const |
|void|[**resetColorCount**](classffw_1_1_framebuffer.md#1ae216bdc5f547f9b79232c720fa168232) () |
|bool|[**destroy**](classffw_1_1_framebuffer.md#1a7965073ccaacb74922c7ef94138d4e65) () |
|void|[**bind**](classffw_1_1_framebuffer.md#1a7c6cdd2d6797d36ab523656f9abbf34d) () const |
|void|[**unbind**](classffw_1_1_framebuffer.md#1a2c4a652b9e959f3f97c10116a9542296) () const |
|**[Framebuffer](classffw_1_1_framebuffer.md)** &|[**operator=**](classffw_1_1_framebuffer.md#1a9c4cc12bd66f49d23c024d983cb0491b) (const **[Framebuffer](classffw_1_1_framebuffer.md)** & other) = delete |
|**[Framebuffer](classffw_1_1_framebuffer.md)** &|[**operator=**](classffw_1_1_framebuffer.md#1a8ee569b7a1aed4e49a71aad6c93aa187) (**[Framebuffer](classffw_1_1_framebuffer.md)** && other) |


## Public Functions Documentation

### function <a id="1a934d32601dcd69dab1cbb3cab2937cad" href="#1a934d32601dcd69dab1cbb3cab2937cad">Framebuffer</a>

```cpp
ffw::Framebuffer::Framebuffer ()
```



### function <a id="1aec740a7e58dbb78720654fb1705d18a5" href="#1aec740a7e58dbb78720654fb1705d18a5">Framebuffer</a>

```cpp
ffw::Framebuffer::Framebuffer (
    const Framebuffer & other
) = delete
```



### function <a id="1a2d09f2e68864fd65e37ff1652fbcc61d" href="#1a2d09f2e68864fd65e37ff1652fbcc61d">Framebuffer</a>

```cpp
ffw::Framebuffer::Framebuffer (
    Framebuffer && other
)
```



### function <a id="1a4644aaf6f77e6380cff0ddeadd131a12" href="#1a4644aaf6f77e6380cff0ddeadd131a12">swap</a>

```cpp
void ffw::Framebuffer::swap (
    Framebuffer & other
)
```



### function <a id="1a5fac7b441e2c97098b6256e0af601ae6" href="#1a5fac7b441e2c97098b6256e0af601ae6">~Framebuffer</a>

```cpp
ffw::Framebuffer::~Framebuffer ()
```



### function <a id="1a7c1f98d179f746bf2f26bf1eed95f9fd" href="#1a7c1f98d179f746bf2f26bf1eed95f9fd">isCreated</a>

```cpp
bool ffw::Framebuffer::isCreated () const
```



### function <a id="1ad5108eaf30a33c4690ac00f97cb199b8" href="#1ad5108eaf30a33c4690ac00f97cb199b8">create</a>

```cpp
bool ffw::Framebuffer::create ()
```



### function <a id="1a9582e8ddd25e0b4ae4fb0a695b2eb308" href="#1a9582e8ddd25e0b4ae4fb0a695b2eb308">addColorTexture</a>

```cpp
bool ffw::Framebuffer::addColorTexture (
    const ffw::Texture2D * texture
    int mip = 0
)
```



### function <a id="1a3f54ead2e40950583c35589bde7767f8" href="#1a3f54ead2e40950583c35589bde7767f8">addCubemapTexture</a>

```cpp
bool ffw::Framebuffer::addCubemapTexture (
    const ffw::TextureCubemap * texture
    int side
    int mip = 0
)
```



### function <a id="1abb46bb706c04b997981c55e791c39cfe" href="#1abb46bb706c04b997981c55e791c39cfe">addDepthTexture</a>

```cpp
bool ffw::Framebuffer::addDepthTexture (
    const ffw::Texture2D * texture
    int mip = 0
)
```



### function <a id="1add2c0d4e118d524055e59f24b9d79b8e" href="#1add2c0d4e118d524055e59f24b9d79b8e">addColorTextureMS</a>

```cpp
bool ffw::Framebuffer::addColorTextureMS (
    const ffw::Texture2DMS * texture
    int mip = 0
)
```



### function <a id="1adb3aaf092d5fa55296bc5f82be28b3fe" href="#1adb3aaf092d5fa55296bc5f82be28b3fe">addDepthTextureMS</a>

```cpp
bool ffw::Framebuffer::addDepthTextureMS (
    const ffw::Texture2DMS * texture
    int mip = 0
)
```



### function <a id="1a09a4c7ea2fb2a8351b5674416b36d295" href="#1a09a4c7ea2fb2a8351b5674416b36d295">addColorRenderbuffer</a>

```cpp
bool ffw::Framebuffer::addColorRenderbuffer (
    const ffw::Renderbuffer2D * texture
)
```



### function <a id="1a4b9eff078631930f19a83bfc04b637aa" href="#1a4b9eff078631930f19a83bfc04b637aa">addDepthRenderbuffer</a>

```cpp
bool ffw::Framebuffer::addDepthRenderbuffer (
    const ffw::Renderbuffer2D * texture
)
```



### function <a id="1a9de525b69c4abc44f6186dc571d6b274" href="#1a9de525b69c4abc44f6186dc571d6b274">addColorRenderbufferMS</a>

```cpp
bool ffw::Framebuffer::addColorRenderbufferMS (
    const ffw::Renderbuffer2DMS * texture
)
```



### function <a id="1a89b18d1f9fc6d6ad01866d9f385f4af3" href="#1a89b18d1f9fc6d6ad01866d9f385f4af3">addDepthRenderbufferMS</a>

```cpp
bool ffw::Framebuffer::addDepthRenderbufferMS (
    const ffw::Renderbuffer2DMS * texture
)
```



### function <a id="1a9553b7deb789fd727b0287879846bc69" href="#1a9553b7deb789fd727b0287879846bc69">checkStatus</a>

```cpp
bool ffw::Framebuffer::checkStatus ()
```



### function <a id="1a399e05f0243f71c62616d9a688a19083" href="#1a399e05f0243f71c62616d9a688a19083">getHandle</a>

```cpp
unsigned int ffw::Framebuffer::getHandle () const
```



### function <a id="1ae216bdc5f547f9b79232c720fa168232" href="#1ae216bdc5f547f9b79232c720fa168232">resetColorCount</a>

```cpp
void ffw::Framebuffer::resetColorCount ()
```



### function <a id="1a7965073ccaacb74922c7ef94138d4e65" href="#1a7965073ccaacb74922c7ef94138d4e65">destroy</a>

```cpp
bool ffw::Framebuffer::destroy ()
```



### function <a id="1a7c6cdd2d6797d36ab523656f9abbf34d" href="#1a7c6cdd2d6797d36ab523656f9abbf34d">bind</a>

```cpp
void ffw::Framebuffer::bind () const
```



### function <a id="1a2c4a652b9e959f3f97c10116a9542296" href="#1a2c4a652b9e959f3f97c10116a9542296">unbind</a>

```cpp
void ffw::Framebuffer::unbind () const
```



### function <a id="1a9c4cc12bd66f49d23c024d983cb0491b" href="#1a9c4cc12bd66f49d23c024d983cb0491b">operator=</a>

```cpp
Framebuffer & ffw::Framebuffer::operator= (
    const Framebuffer & other
) = delete
```



### function <a id="1a8ee569b7a1aed4e49a71aad6c93aa187" href="#1a8ee569b7a1aed4e49a71aad6c93aa187">operator=</a>

```cpp
Framebuffer & ffw::Framebuffer::operator= (
    Framebuffer && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/framebuffer.h`
