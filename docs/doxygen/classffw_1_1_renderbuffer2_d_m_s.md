---
search:
    keywords: ['ffw::Renderbuffer2DMS', 'Renderbuffer2DMS', '~Renderbuffer2DMS', 'create', 'resize', 'Renderbuffer', 'Renderbuffer', 'Renderbuffer', 'swap', '~Renderbuffer', 'isCreated', 'destroy', 'bind', 'unbind', 'getHandle', 'getWidth', 'getHeight', 'getInternalFormat', 'getSamples', 'operator=', 'operator=']
---

# class ffw::Renderbuffer2DMS



Inherits the following classes: **[ffw::Renderbuffer](classffw_1_1_renderbuffer.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Renderbuffer2DMS**](classffw_1_1_renderbuffer2_d_m_s.md#1ab574bb5d1f12bfd650403b1cde90c56c) () |
||[**~Renderbuffer2DMS**](classffw_1_1_renderbuffer2_d_m_s.md#1a53f165494186efc0b8da7caa46ea1aa3) () |
|bool|[**create**](classffw_1_1_renderbuffer2_d_m_s.md#1aed76615f38ca8506a5729c5a366e374c) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** internalformat, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** samples) |
|bool|[**resize**](classffw_1_1_renderbuffer2_d_m_s.md#1a08a6cbcbd6aa711fb35b48426f483389) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** samples) |


#### Public Functions inherited from [ffw::Renderbuffer](classffw_1_1_renderbuffer.md)

|Type|Name|
|-----|-----|
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1a65db165157a54da0fac51d2d97db9807) () |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1ad137b5468f6ae402c6ecf29d70b2fb07) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1aa47daf9663b63fae754d7b9ea07ea579) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |
|void|[**swap**](classffw_1_1_renderbuffer.md#1ae313c164f24ace73b7d7966ad28de1df) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) |
|virtual |[**~Renderbuffer**](classffw_1_1_renderbuffer.md#1a8eff07b1c9fc9ec8ef1c7000ed559a07) () |
|bool|[**isCreated**](classffw_1_1_renderbuffer.md#1a552242b8116d8d678c6e89a9ffb9783e) () const |
|void|[**destroy**](classffw_1_1_renderbuffer.md#1aaa69b089c2ac512d8a98db965d66b4cf) () |
|void|[**bind**](classffw_1_1_renderbuffer.md#1a5c367ec01f6ec6148400f91b92afe927) () const |
|void|[**unbind**](classffw_1_1_renderbuffer.md#1a5eb9e6a65534f5cb6cf22724b47de36f) () const |
|unsigned int|[**getHandle**](classffw_1_1_renderbuffer.md#1a1ada3d4ed804dea175ccd9b55bd402a1) () const |
|int|[**getWidth**](classffw_1_1_renderbuffer.md#1a1b1bb5f9dc99503c42b7c62df0e2fc14) () const |
|int|[**getHeight**](classffw_1_1_renderbuffer.md#1a2f9721ee995e6aaeed30330667d56744) () const |
|unsigned int|[**getInternalFormat**](classffw_1_1_renderbuffer.md#1acebb8692752c44c6e9abe56b77bad366) () const |
|int|[**getSamples**](classffw_1_1_renderbuffer.md#1a0d3242b593acb7066382713d419c0fd5) () const |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1a081c8fa6aca820251c2370ce9a46c1b1) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1ab7cd00f965b3b856c7664a1055650938) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::Renderbuffer](classffw_1_1_renderbuffer.md)

|Type|Name|
|-----|-----|
|bool|[**loaded\_**](classffw_1_1_renderbuffer.md#1a988c68ce530337f7f7f8d53de33c90fe)|
|unsigned int|[**internalformat\_**](classffw_1_1_renderbuffer.md#1a2b55653bc7296e65bdadaaba965e59ab)|
|unsigned int|[**buffer\_**](classffw_1_1_renderbuffer.md#1ae8c27524014cff2282db77f3d0b723e9)|
|int|[**width\_**](classffw_1_1_renderbuffer.md#1a3be68a1764f745f53e256329e6dbf6d4)|
|int|[**height\_**](classffw_1_1_renderbuffer.md#1a1b20781d8df0a99ff32283e0115dd98d)|
|int|[**samples\_**](classffw_1_1_renderbuffer.md#1a2543d77fb24a979bca6a019e3d86c968)|


## Public Functions Documentation

### function <a id="1ab574bb5d1f12bfd650403b1cde90c56c" href="#1ab574bb5d1f12bfd650403b1cde90c56c">Renderbuffer2DMS</a>

```cpp
ffw::Renderbuffer2DMS::Renderbuffer2DMS ()
```



### function <a id="1a53f165494186efc0b8da7caa46ea1aa3" href="#1a53f165494186efc0b8da7caa46ea1aa3">~Renderbuffer2DMS</a>

```cpp
ffw::Renderbuffer2DMS::~Renderbuffer2DMS ()
```



### function <a id="1aed76615f38ca8506a5729c5a366e374c" href="#1aed76615f38ca8506a5729c5a366e374c">create</a>

```cpp
bool ffw::Renderbuffer2DMS::create (
    GLsizei width
    GLsizei height
    GLenum internalformat
    GLint samples
)
```



### function <a id="1a08a6cbcbd6aa711fb35b48426f483389" href="#1a08a6cbcbd6aa711fb35b48426f483389">resize</a>

```cpp
bool ffw::Renderbuffer2DMS::resize (
    GLsizei width
    GLsizei height
    GLint samples
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/renderbuffer2dms.h`
