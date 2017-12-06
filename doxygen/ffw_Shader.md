Shader
===================================


The documentation for this class was generated from: `include/ffw/graphics/shader.h`



## Classes

| Name |
|:-----|
| class [ffw::Shader::CompileException](ffw_Shader_CompileException.html) |
| class [ffw::Shader::FileException](ffw_Shader_FileException.html) |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  bool | [checkCompability](#8e08f5b2) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Shader](#e929dbbf) ()  |
|   | [Shader](#79260d74) (const [Shader](ffw_Shader.html) & _other_) = delete  |
|   | [Shader](#976cb0e2) ([Shader](ffw_Shader.html) && _other_)  |
|  void | [swap](#3b166104) ([Shader](ffw_Shader.html) & _other_)  |
|  virtual  | [~Shader](#bc33d946) ()  |
|  bool | [isCreated](#8554476f) () const  |
|  bool | [isLinked](#b20a7cb0) () const  |
|  bool | [isUsingFrag](#2f0dbbf2) () const  |
|  bool | [isUsingGeom](#41f93ea7) () const  |
|  bool | [isUsingVert](#f212a979) () const  |
|  bool | [create](#0666e82a) (const [RenderContext](ffw_RenderContext.html) * _renderer_)  |
|  void | [Link](#d4d71735) ()  |
|  void | [compileFragFromData](#6ee9ed24) (const std::string & _code_)  |
|  void | [compileGeomFromData](#0cc1953c) (const std::string & _code_)  |
|  void | [compileVertFromData](#9902ad63) (const std::string & _code_)  |
|  void | [createFromFile](#d1ec165d) (const [RenderContext](ffw_RenderContext.html) * _renderer_, const std::string & _geomfile_, const std::string & _vertfile_, const std::string & _fragfile_)  |
|  void | [createFromData](#6f953245) (const [RenderContext](ffw_RenderContext.html) * _renderer_, const std::string & _geomdata_, const std::string & _vertdata_, const std::string & _fragdata_)  |
|  void | [destroy](#72cf3a57) ()  |
|  unsigned int | [getHandle](#185cc4b2) () const  |
|  void | [setAttributePointerf](#14e7ce8e) (int _location_, int _size_, int _stride_, const GLvoid * _offset_) const  |
|  void | [setAttributeDivisor](#18bbb3b4) (unsigned int _index_, unsigned int _divisor_) const  |
|  void | [drawArrays](#8f550b13) (unsigned int _mode_, int _first_, int _cnt_) const  |
|  void | [drawArraysInstanced](#feffcb24) (unsigned int _mode_, int _First_, int _count_, int _instancecount_) const  |
|  void | [drawElements](#bfd5dfb7) (unsigned int _mode_, int _cnt_, unsigned int _type_, const void * _indices_) const  |
|  void | [drawElementsRange](#956cca77) (unsigned int _mode_, unsigned int _start_, unsigned int _end_, int _cnt_, unsigned int _type_, const void * _indices_) const  |
|  void | [drawElementsInstanced](#eee0192f) (unsigned int _mode_, int _cnt_, unsigned int _type_, const void * _indices_, int _instancecount_) const  |
|  void | [bind](#be70e79a) () const  |
|  void | [unbind](#16c9be2f) () const  |
|  int | [getUniformLocation](#175f952f) (const char * _name_) const  |
|  int | [getAttributeLocation](#887334cd) (const char * _name_) const  |
|  void | [setUniform1f](#6503e2a2) (int _location_, float _value_) const  |
|  void | [setUniform1fv](#271e2a75) (int _location_, const float * _array_, int _length_) const  |
|  void | [setUniform1i](#1158aed1) (int _location_, int _value_) const  |
|  void | [setUniform1iv](#85983c9e) (int _location_, const int * _array_, int _length_) const  |
|  void | [setUniform2f](#fb90232b) (int _location_, float _x_, float _y_) const  |
|  void | [setUniform2fv](#5d8f846c) (int _location_, const float * _array_, int _length_) const  |
|  void | [setUniform2i](#bafe960c) (int _location_, int _x_, int _y_) const  |
|  void | [setUniform2iv](#59f76b14) (int _location_, const int * _array_, int _length_) const  |
|  void | [setUniform3f](#55de58fa) (int _location_, float _x_, float _y_, float _z_) const  |
|  void | [setUniform3fv](#6a4b77d8) (int _location_, const float * _array_, int _length_) const  |
|  void | [setUniform3i](#08a13ddb) (int _location_, int _x_, int _y_, int _z_) const  |
|  void | [setUniform3iv](#9b201e80) (int _location_, const int * _array_, int _length_) const  |
|  void | [setUniform4f](#79ebc39d) (int _location_, float _x_, float _y_, float _z_, float _w_) const  |
|  void | [setUniform4fv](#b532bba7) (int _location_, const float * _array_, int _length_) const  |
|  void | [setUniform4i](#1ffd23f2) (int _location_, int _x_, int _y_, int _z_, int _w_) const  |
|  void | [setUniform4iv](#75fa2b83) (int _location_, const int * _array_, int _length_) const  |
|  void | [setUniform2f](#b0237f30) (int _location_, const [ffw::Vec2f](ffw.html#fcfaa6c5) & _vec_) const  |
|  void | [setUniform2fv](#b5ab0f12) (int _location_, const [ffw::Vec2f](ffw.html#fcfaa6c5) * _array_, int _length_) const  |
|  void | [setUniform2i](#fea65ed6) (int _location_, const [ffw::Vec2i](ffw.html#e4e07ebe) & _vec_) const  |
|  void | [setUniform2iv](#b54975c1) (int _location_, const [ffw::Vec2i](ffw.html#e4e07ebe) * _array_, int _length_) const  |
|  void | [setUniform3f](#1cf0d846) (int _location_, const [ffw::Vec3f](ffw.html#f1b9b946) & _vec_) const  |
|  void | [setUniform3fv](#db033151) (int _location_, const [ffw::Vec3f](ffw.html#f1b9b946) * _array_, int _length_) const  |
|  void | [setUniform3i](#13dd9fa1) (int _location_, const [ffw::Vec3i](ffw.html#1bc00754) & _vec_) const  |
|  void | [setUniform3iv](#45a2047d) (int _location_, const [ffw::Vec3i](ffw.html#1bc00754) * _array_, int _length_) const  |
|  void | [setUniform4f](#c69695e4) (int _location_, const [ffw::Vec4f](ffw.html#397c4d39) & _vec_) const  |
|  void | [setUniform4fv](#5b805f92) (int _location_, const [ffw::Vec4f](ffw.html#397c4d39) * _array_, int _length_) const  |
|  void | [setUniform4i](#08dc0ecc) (int _location_, const [ffw::Vec4i](ffw.html#fd5627df) & _vec_) const  |
|  void | [setUniform4iv](#57fafe17) (int _location_, const [ffw::Vec4i](ffw.html#fd5627df) * _array_, int _length_) const  |
|  void | [setUniform4f](#af7f67e1) (int _location_, const [ffw::Color](ffw_Color.html) & _vec_) const  |
|  void | [setUniform4fv](#7d16ddb7) (int _location_, const [ffw::Color](ffw_Color.html) * _array_, int _length_) const  |
|  void | [setUniformMatrix2fv](#643a6135) (int _location_, const float * _mat_, int _length_) const  |
|  void | [setUniformMatrix3fv](#051571f5) (int _location_, const float * _mat_, int _length_) const  |
|  void | [setUniformMatrix4fv](#d928a76a) (int _location_, const float * _mat_, int _length_) const  |
|  void | [setUniformMatrix4fv](#64f0b27e) (int _location_, const [Mat4x4f](ffw.html#029b468c) * _mat_, int _length_) const  |
|  [Shader](ffw_Shader.html) & | [operator=](#133ecfaf) (const [Shader](ffw_Shader.html) & _other_) = delete  |
|  [Shader](ffw_Shader.html) & | [operator=](#730a15ea) ([Shader](ffw_Shader.html) && _other_)  |


## Public Static Functions Documentation

### _function_ <a id="8e08f5b2" href="#8e08f5b2">checkCompability</a>

```cpp
static bool checkCompability (
    const RenderContext * renderer
) 
```





## Public Functions Documentation

### _function_ <a id="e929dbbf" href="#e929dbbf">Shader</a>

```cpp
 Shader () 
```



### _function_ <a id="79260d74" href="#79260d74">Shader</a>

```cpp
 Shader (
    const Shader & other
) = delete 
```



### _function_ <a id="976cb0e2" href="#976cb0e2">Shader</a>

```cpp
 Shader (
    Shader && other
) 
```



### _function_ <a id="3b166104" href="#3b166104">swap</a>

```cpp
void swap (
    Shader & other
) 
```



### _function_ <a id="bc33d946" href="#bc33d946">~Shader</a>

```cpp
virtual  ~Shader () 
```



### _function_ <a id="8554476f" href="#8554476f">isCreated</a>

```cpp
inline bool isCreated () const 
```



### _function_ <a id="b20a7cb0" href="#b20a7cb0">isLinked</a>

```cpp
inline bool isLinked () const 
```



### _function_ <a id="2f0dbbf2" href="#2f0dbbf2">isUsingFrag</a>

```cpp
inline bool isUsingFrag () const 
```



### _function_ <a id="41f93ea7" href="#41f93ea7">isUsingGeom</a>

```cpp
inline bool isUsingGeom () const 
```



### _function_ <a id="f212a979" href="#f212a979">isUsingVert</a>

```cpp
inline bool isUsingVert () const 
```



### _function_ <a id="0666e82a" href="#0666e82a">create</a>

```cpp
bool create (
    const RenderContext * renderer
) 
```



### _function_ <a id="d4d71735" href="#d4d71735">Link</a>

```cpp
void Link () 
```



### _function_ <a id="6ee9ed24" href="#6ee9ed24">compileFragFromData</a>

```cpp
void compileFragFromData (
    const std::string & code
) 
```



### _function_ <a id="0cc1953c" href="#0cc1953c">compileGeomFromData</a>

```cpp
void compileGeomFromData (
    const std::string & code
) 
```



### _function_ <a id="9902ad63" href="#9902ad63">compileVertFromData</a>

```cpp
void compileVertFromData (
    const std::string & code
) 
```



### _function_ <a id="d1ec165d" href="#d1ec165d">createFromFile</a>

```cpp
void createFromFile (
    const RenderContext * renderer,
    const std::string & geomfile,
    const std::string & vertfile,
    const std::string & fragfile
) 
```



### _function_ <a id="6f953245" href="#6f953245">createFromData</a>

```cpp
void createFromData (
    const RenderContext * renderer,
    const std::string & geomdata,
    const std::string & vertdata,
    const std::string & fragdata
) 
```



### _function_ <a id="72cf3a57" href="#72cf3a57">destroy</a>

```cpp
void destroy () 
```



### _function_ <a id="185cc4b2" href="#185cc4b2">getHandle</a>

```cpp
inline unsigned int getHandle () const 
```



### _function_ <a id="14e7ce8e" href="#14e7ce8e">setAttributePointerf</a>

```cpp
void setAttributePointerf (
    int location,
    int size,
    int stride,
    const GLvoid * offset
) const 
```



### _function_ <a id="18bbb3b4" href="#18bbb3b4">setAttributeDivisor</a>

```cpp
void setAttributeDivisor (
    unsigned int index,
    unsigned int divisor
) const 
```



### _function_ <a id="8f550b13" href="#8f550b13">drawArrays</a>

```cpp
void drawArrays (
    unsigned int mode,
    int first,
    int cnt
) const 
```



### _function_ <a id="feffcb24" href="#feffcb24">drawArraysInstanced</a>

```cpp
void drawArraysInstanced (
    unsigned int mode,
    int First,
    int count,
    int instancecount
) const 
```



### _function_ <a id="bfd5dfb7" href="#bfd5dfb7">drawElements</a>

```cpp
void drawElements (
    unsigned int mode,
    int cnt,
    unsigned int type,
    const void * indices
) const 
```



### _function_ <a id="956cca77" href="#956cca77">drawElementsRange</a>

```cpp
void drawElementsRange (
    unsigned int mode,
    unsigned int start,
    unsigned int end,
    int cnt,
    unsigned int type,
    const void * indices
) const 
```



### _function_ <a id="eee0192f" href="#eee0192f">drawElementsInstanced</a>

```cpp
void drawElementsInstanced (
    unsigned int mode,
    int cnt,
    unsigned int type,
    const void * indices,
    int instancecount
) const 
```



### _function_ <a id="be70e79a" href="#be70e79a">bind</a>

```cpp
void bind () const 
```



### _function_ <a id="16c9be2f" href="#16c9be2f">unbind</a>

```cpp
void unbind () const 
```



### _function_ <a id="175f952f" href="#175f952f">getUniformLocation</a>

```cpp
int getUniformLocation (
    const char * name
) const 
```



### _function_ <a id="887334cd" href="#887334cd">getAttributeLocation</a>

```cpp
int getAttributeLocation (
    const char * name
) const 
```



### _function_ <a id="6503e2a2" href="#6503e2a2">setUniform1f</a>

```cpp
void setUniform1f (
    int location,
    float value
) const 
```



### _function_ <a id="271e2a75" href="#271e2a75">setUniform1fv</a>

```cpp
void setUniform1fv (
    int location,
    const float * array,
    int length
) const 
```



### _function_ <a id="1158aed1" href="#1158aed1">setUniform1i</a>

```cpp
void setUniform1i (
    int location,
    int value
) const 
```



### _function_ <a id="85983c9e" href="#85983c9e">setUniform1iv</a>

```cpp
void setUniform1iv (
    int location,
    const int * array,
    int length
) const 
```



### _function_ <a id="fb90232b" href="#fb90232b">setUniform2f</a>

```cpp
void setUniform2f (
    int location,
    float x,
    float y
) const 
```



### _function_ <a id="5d8f846c" href="#5d8f846c">setUniform2fv</a>

```cpp
void setUniform2fv (
    int location,
    const float * array,
    int length
) const 
```



### _function_ <a id="bafe960c" href="#bafe960c">setUniform2i</a>

```cpp
void setUniform2i (
    int location,
    int x,
    int y
) const 
```



### _function_ <a id="59f76b14" href="#59f76b14">setUniform2iv</a>

```cpp
void setUniform2iv (
    int location,
    const int * array,
    int length
) const 
```



### _function_ <a id="55de58fa" href="#55de58fa">setUniform3f</a>

```cpp
void setUniform3f (
    int location,
    float x,
    float y,
    float z
) const 
```



### _function_ <a id="6a4b77d8" href="#6a4b77d8">setUniform3fv</a>

```cpp
void setUniform3fv (
    int location,
    const float * array,
    int length
) const 
```



### _function_ <a id="08a13ddb" href="#08a13ddb">setUniform3i</a>

```cpp
void setUniform3i (
    int location,
    int x,
    int y,
    int z
) const 
```



### _function_ <a id="9b201e80" href="#9b201e80">setUniform3iv</a>

```cpp
void setUniform3iv (
    int location,
    const int * array,
    int length
) const 
```



### _function_ <a id="79ebc39d" href="#79ebc39d">setUniform4f</a>

```cpp
void setUniform4f (
    int location,
    float x,
    float y,
    float z,
    float w
) const 
```



### _function_ <a id="b532bba7" href="#b532bba7">setUniform4fv</a>

```cpp
void setUniform4fv (
    int location,
    const float * array,
    int length
) const 
```



### _function_ <a id="1ffd23f2" href="#1ffd23f2">setUniform4i</a>

```cpp
void setUniform4i (
    int location,
    int x,
    int y,
    int z,
    int w
) const 
```



### _function_ <a id="75fa2b83" href="#75fa2b83">setUniform4iv</a>

```cpp
void setUniform4iv (
    int location,
    const int * array,
    int length
) const 
```



### _function_ <a id="b0237f30" href="#b0237f30">setUniform2f</a>

```cpp
void setUniform2f (
    int location,
    const ffw::Vec2f & vec
) const 
```



### _function_ <a id="b5ab0f12" href="#b5ab0f12">setUniform2fv</a>

```cpp
void setUniform2fv (
    int location,
    const ffw::Vec2f * array,
    int length
) const 
```



### _function_ <a id="fea65ed6" href="#fea65ed6">setUniform2i</a>

```cpp
void setUniform2i (
    int location,
    const ffw::Vec2i & vec
) const 
```



### _function_ <a id="b54975c1" href="#b54975c1">setUniform2iv</a>

```cpp
void setUniform2iv (
    int location,
    const ffw::Vec2i * array,
    int length
) const 
```



### _function_ <a id="1cf0d846" href="#1cf0d846">setUniform3f</a>

```cpp
void setUniform3f (
    int location,
    const ffw::Vec3f & vec
) const 
```



### _function_ <a id="db033151" href="#db033151">setUniform3fv</a>

```cpp
void setUniform3fv (
    int location,
    const ffw::Vec3f * array,
    int length
) const 
```



### _function_ <a id="13dd9fa1" href="#13dd9fa1">setUniform3i</a>

```cpp
void setUniform3i (
    int location,
    const ffw::Vec3i & vec
) const 
```



### _function_ <a id="45a2047d" href="#45a2047d">setUniform3iv</a>

```cpp
void setUniform3iv (
    int location,
    const ffw::Vec3i * array,
    int length
) const 
```



### _function_ <a id="c69695e4" href="#c69695e4">setUniform4f</a>

```cpp
void setUniform4f (
    int location,
    const ffw::Vec4f & vec
) const 
```



### _function_ <a id="5b805f92" href="#5b805f92">setUniform4fv</a>

```cpp
void setUniform4fv (
    int location,
    const ffw::Vec4f * array,
    int length
) const 
```



### _function_ <a id="08dc0ecc" href="#08dc0ecc">setUniform4i</a>

```cpp
void setUniform4i (
    int location,
    const ffw::Vec4i & vec
) const 
```



### _function_ <a id="57fafe17" href="#57fafe17">setUniform4iv</a>

```cpp
void setUniform4iv (
    int location,
    const ffw::Vec4i * array,
    int length
) const 
```



### _function_ <a id="af7f67e1" href="#af7f67e1">setUniform4f</a>

```cpp
void setUniform4f (
    int location,
    const ffw::Color & vec
) const 
```



### _function_ <a id="7d16ddb7" href="#7d16ddb7">setUniform4fv</a>

```cpp
void setUniform4fv (
    int location,
    const ffw::Color * array,
    int length
) const 
```



### _function_ <a id="643a6135" href="#643a6135">setUniformMatrix2fv</a>

```cpp
void setUniformMatrix2fv (
    int location,
    const float * mat,
    int length
) const 
```



### _function_ <a id="051571f5" href="#051571f5">setUniformMatrix3fv</a>

```cpp
void setUniformMatrix3fv (
    int location,
    const float * mat,
    int length
) const 
```



### _function_ <a id="d928a76a" href="#d928a76a">setUniformMatrix4fv</a>

```cpp
void setUniformMatrix4fv (
    int location,
    const float * mat,
    int length
) const 
```



### _function_ <a id="64f0b27e" href="#64f0b27e">setUniformMatrix4fv</a>

```cpp
void setUniformMatrix4fv (
    int location,
    const Mat4x4f * mat,
    int length
) const 
```



### _function_ <a id="133ecfaf" href="#133ecfaf">operator=</a>

```cpp
Shader & operator= (
    const Shader & other
) = delete 
```



### _function_ <a id="730a15ea" href="#730a15ea">operator=</a>

```cpp
Shader & operator= (
    Shader && other
) 
```





