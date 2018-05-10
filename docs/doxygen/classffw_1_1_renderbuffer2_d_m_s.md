---
search: false
---

# class ffw::Renderbuffer2DMS



Inherits the following classes: **[ffw::Renderbuffer](classffw_1_1_renderbuffer.md)**

## Public Functions

|Type|Name|
|-----|-----|
||[**Renderbuffer2DMS**](classffw_1_1_renderbuffer2_d_m_s.md#1adc4a1fe6bbfc70d8544082b64e25a173) () = default |
|virtual |[**~Renderbuffer2DMS**](classffw_1_1_renderbuffer2_d_m_s.md#1a7c4bcc9a6834336e2dc2ef1014e26cb5) () = default |
|bool|[**create**](classffw_1_1_renderbuffer2_d_m_s.md#1aed76615f38ca8506a5729c5a366e374c) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)** internalformat, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** samples) |
|bool|[**resize**](classffw_1_1_renderbuffer2_d_m_s.md#1a08a6cbcbd6aa711fb35b48426f483389) (**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** width, **[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)** height, **[GLint](glcorearb_8h.md#1a5ac0f3c4d7fafd42b284b5487a791017)** samples) |


#### Public Functions inherited from [ffw::Renderbuffer](classffw_1_1_renderbuffer.md)

|Type|Name|
|-----|-----|
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1a65db165157a54da0fac51d2d97db9807) () <br>Creates an empty renderbuffer storage. |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1ad137b5468f6ae402c6ecf29d70b2fb07) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
||[**Renderbuffer**](classffw_1_1_renderbuffer.md#1aa47daf9663b63fae754d7b9ea07ea579) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |
|void|[**swap**](classffw_1_1_renderbuffer.md#1ae313c164f24ace73b7d7966ad28de1df) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) |
|virtual |[**~Renderbuffer**](classffw_1_1_renderbuffer.md#1a8eff07b1c9fc9ec8ef1c7000ed559a07) () |
|bool|[**isCreated**](classffw_1_1_renderbuffer.md#1a552242b8116d8d678c6e89a9ffb9783e) () const <br>Returns true if the renderbuffer has been allocated. |
|void|[**destroy**](classffw_1_1_renderbuffer.md#1aaa69b089c2ac512d8a98db965d66b4cf) () <br>Destroys the renderbuffer. |
|void|[**bind**](classffw_1_1_renderbuffer.md#1a5c367ec01f6ec6148400f91b92afe927) () const <br>Binds the renderbuffer. |
|void|[**unbind**](classffw_1_1_renderbuffer.md#1a5eb9e6a65534f5cb6cf22724b47de36f) () const <br>Unbinds the texture. |
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**getHandle**](classffw_1_1_renderbuffer.md#1aacb48db33cee24c946aa2a4e738f4d7f) () const <br>Returns the OpenGL pointer, a handle to the renderbuffer. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getWidth**](classffw_1_1_renderbuffer.md#1a835a340fcff8b404951f2bad0b21a62b) () const |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getHeight**](classffw_1_1_renderbuffer.md#1a885c4299038dd0f3f6f4005e49991f26) () const |
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**getInternalFormat**](classffw_1_1_renderbuffer.md#1a01ebd58dd96a47ffaf14aba12c5120e0) () const <br>Returns the internal format used by the renderbuffer. |
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**getSamples**](classffw_1_1_renderbuffer.md#1afb80bac412fc2f21736ea733895efc63) () const <br>Returns the number of samples used by the renderbuffer. |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1a081c8fa6aca820251c2370ce9a46c1b1) (const **[Renderbuffer](classffw_1_1_renderbuffer.md)** & other) = delete |
|**[Renderbuffer](classffw_1_1_renderbuffer.md)** &|[**operator=**](classffw_1_1_renderbuffer.md#1ab7cd00f965b3b856c7664a1055650938) (**[Renderbuffer](classffw_1_1_renderbuffer.md)** && other) |


## Additional Inherited Members

#### Protected Attributes inherited from [ffw::Renderbuffer](classffw_1_1_renderbuffer.md)

|Type|Name|
|-----|-----|
|bool|[**loaded**](classffw_1_1_renderbuffer.md#1a5b4440d36c14d79428f25f6e7d0c34e4)|
|**[GLenum](glcorearb_8h.md#1a7efd7809e1632cdae75603fd1fee61c0)**|[**internalformat**](classffw_1_1_renderbuffer.md#1aa71792df5c496d87bfb5ffb4cdb1638b)|
|**[GLuint](glcorearb_8h.md#1aa311c7f0d6ec4f1a33f9235c3651b86b)**|[**buffer**](classffw_1_1_renderbuffer.md#1a7daf459c62849d34404471148d7996b6)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**width**](classffw_1_1_renderbuffer.md#1ab620da58fc35fa61c947ec91b2039e6b)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**height**](classffw_1_1_renderbuffer.md#1a27be78c36640a6ef0a9e67b17769eac6)|
|**[GLsizei](glcorearb_8h.md#1a9289d5b99dc1f27f01480360f2e18ae0)**|[**samples**](classffw_1_1_renderbuffer.md#1a314a55d8152dbe3350976cb1992a6519)|


## Public Functions Documentation

### function <a id="1adc4a1fe6bbfc70d8544082b64e25a173" href="#1adc4a1fe6bbfc70d8544082b64e25a173">Renderbuffer2DMS</a>

```cpp
ffw::Renderbuffer2DMS::Renderbuffer2DMS () = default
```



### function <a id="1a7c4bcc9a6834336e2dc2ef1014e26cb5" href="#1a7c4bcc9a6834336e2dc2ef1014e26cb5">~Renderbuffer2DMS</a>

```cpp
virtual ffw::Renderbuffer2DMS::~Renderbuffer2DMS () = default
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
