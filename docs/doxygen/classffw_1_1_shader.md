---
search: false
---

# class ffw::Shader

## Classes

|Type|Name|
|-----|-----|
|class|[**CompileException**](classffw_1_1_shader_1_1_compile_exception.md)|
|class|[**FileException**](classffw_1_1_shader_1_1_file_exception.md)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Shader**](classffw_1_1_shader.md#1a3e8832a6263f5d337e1e5f07b8835182) () |
||[**Shader**](classffw_1_1_shader.md#1a5f31b86dbe1c56b1deb50d400468ae88) (const **[Shader](classffw_1_1_shader.md)** & other) = delete |
||[**Shader**](classffw_1_1_shader.md#1aebea35d6c7ff96350372baa0926b3426) (**[Shader](classffw_1_1_shader.md)** && other) |
|void|[**swap**](classffw_1_1_shader.md#1ab57fc9ea854d16b06a1af51dfa84f2f2) (**[Shader](classffw_1_1_shader.md)** & other) |
|virtual |[**~Shader**](classffw_1_1_shader.md#1aee0226d806f82eeb633c70d0596d8995) () |
|bool|[**isCreated**](classffw_1_1_shader.md#1a1e6cc4a641090edcd43f85127ab2fd36) () const |
|bool|[**isLinked**](classffw_1_1_shader.md#1a7407c12be5bc642c44e46e1be0f07ab5) () const |
|bool|[**isUsingFrag**](classffw_1_1_shader.md#1ae5d53c3d84123c8b907a4aa03e19c8d6) () const |
|bool|[**isUsingGeom**](classffw_1_1_shader.md#1a217d60086f9f8e69967e713d1e20d2a6) () const |
|bool|[**isUsingVert**](classffw_1_1_shader.md#1a32931f8fba59a480dbd2fab06afdb719) () const |
|bool|[**create**](classffw_1_1_shader.md#1aacbe2f7a7501d75a865239c0f2e9070e) () |
|void|[**Link**](classffw_1_1_shader.md#1a5d7ce766b2987f33c557c7894185e328) () |
|void|[**compileFragFromData**](classffw_1_1_shader.md#1a7587f237d38c49b615df9dfc80fac87e) (const std::string & code) |
|void|[**compileGeomFromData**](classffw_1_1_shader.md#1a8e604a43726c4a5732c5f71b15a0a049) (const std::string & code) |
|void|[**compileVertFromData**](classffw_1_1_shader.md#1a6db5facb2a7817db56e58157aada34b3) (const std::string & code) |
|void|[**createFromFile**](classffw_1_1_shader.md#1adc491f6c127aac2481e0c23ed4fae5b1) (const std::string & geomfile, const std::string & vertfile, const std::string & fragfile) |
|void|[**createFromData**](classffw_1_1_shader.md#1a6af4574b8009edf28e4fa3a53099970e) (const std::string & geomdata, const std::string & vertdata, const std::string & fragdata) |
|void|[**destroy**](classffw_1_1_shader.md#1a6fb21b73d51cdcc9c1c01cc4ddf8d039) () |
|unsigned int|[**getHandle**](classffw_1_1_shader.md#1a1a283cc22b2cad1700cedc2be1a2832b) () const |
|void|[**setAttributePointerf**](classffw_1_1_shader.md#1aad5be1169da5d2504c12a189796c9e23) (int location, int size, int stride, const **[GLvoid](glcorearb_8h.md#1a1e5eb1ac5e47603cc80ab58338b92393)** \* offset) const |
|void|[**setAttributeDivisor**](classffw_1_1_shader.md#1a0fe8b4fac2721f14405964a77cc39a75) (unsigned int index, unsigned int divisor) const |
|void|[**drawArrays**](classffw_1_1_shader.md#1aad8f78f342b5e00a26f309861c49ba90) (unsigned int mode, int first, int cnt) const |
|void|[**drawArraysInstanced**](classffw_1_1_shader.md#1ade838dd3797b8ca4b1dc9e3776805096) (unsigned int mode, int First, int count, int instancecount) const |
|void|[**drawElements**](classffw_1_1_shader.md#1a517ebfc60d9c22d984ad79917aee9dda) (unsigned int mode, int cnt, unsigned int type, const void \* indices) const |
|void|[**drawElementsRange**](classffw_1_1_shader.md#1af4a879097805dbf92f356a2119a26ab3) (unsigned int mode, unsigned int start, unsigned int end, int cnt, unsigned int type, const void \* indices) const |
|void|[**drawElementsInstanced**](classffw_1_1_shader.md#1ae870b387c3dd8f6df8c88e028ca1d217) (unsigned int mode, int cnt, unsigned int type, const void \* indices, int instancecount) const |
|void|[**bind**](classffw_1_1_shader.md#1a2bab874c923b45bc691c9fb0287c916e) () const |
|void|[**unbind**](classffw_1_1_shader.md#1ac1ffbce2c4ee1de6d4fb34f26c7a7415) () const |
|int|[**getUniformLocation**](classffw_1_1_shader.md#1a45fcf360b10b740c7b5d8841aa650f2e) (const char \* name) const |
|int|[**getAttributeLocation**](classffw_1_1_shader.md#1ad98c91799accab8acf7cd8b6f55af112) (const char \* name) const |
|void|[**setUniform1f**](classffw_1_1_shader.md#1a47fc42f655e2eedb43ccf04d1b11bc41) (int location, float value) const |
|void|[**setUniform1fv**](classffw_1_1_shader.md#1ab962479bf0a486d2feca17d92473404f) (int location, const float \* array, int length) const |
|void|[**setUniform1i**](classffw_1_1_shader.md#1a5f31ed9a8644d74b6f433a303afe918f) (int location, int value) const |
|void|[**setUniform1iv**](classffw_1_1_shader.md#1acce81eaddf8c6140d3377dad77d16ffc) (int location, const int \* array, int length) const |
|void|[**setUniform2f**](classffw_1_1_shader.md#1add5da1b4a8c3e7ee150d5e858406a3a3) (int location, float x, float y) const |
|void|[**setUniform2fv**](classffw_1_1_shader.md#1a1e0879c8800a3b297d01559599b98e57) (int location, const float \* array, int length) const |
|void|[**setUniform2i**](classffw_1_1_shader.md#1aa17468d4cc845c7ed14b64bc8611de59) (int location, int x, int y) const |
|void|[**setUniform2iv**](classffw_1_1_shader.md#1a5dd7977add525844cc8b4844925043bf) (int location, const int \* array, int length) const |
|void|[**setUniform3f**](classffw_1_1_shader.md#1a1c83fe2d028fc9a05652004c64143890) (int location, float x, float y, float z) const |
|void|[**setUniform3fv**](classffw_1_1_shader.md#1aed93f99cef5c6ef084a598ddf0aba59f) (int location, const float \* array, int length) const |
|void|[**setUniform3i**](classffw_1_1_shader.md#1a2d6254ad9ddd1446e5add48d54d8ca7a) (int location, int x, int y, int z) const |
|void|[**setUniform3iv**](classffw_1_1_shader.md#1ad001ea7b06a9894e8be18310c2a23d2b) (int location, const int \* array, int length) const |
|void|[**setUniform4f**](classffw_1_1_shader.md#1aa842ce3be07ec0f33c70ee36e33cb86f) (int location, float x, float y, float z, float w) const |
|void|[**setUniform4fv**](classffw_1_1_shader.md#1ab02356d965db08aa0d9f53c4f37d2e5b) (int location, const float \* array, int length) const |
|void|[**setUniform4i**](classffw_1_1_shader.md#1a7b4087d48bf35ac6a1a3e818060146fc) (int location, int x, int y, int z, int w) const |
|void|[**setUniform4iv**](classffw_1_1_shader.md#1ab057dc559a8142a4142e472e62b93f7a) (int location, const int \* array, int length) const |
|void|[**setUniform2f**](classffw_1_1_shader.md#1a008fbdc81720add3ba219cd1d86a5e93) (int location, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** & vec) const |
|void|[**setUniform2fv**](classffw_1_1_shader.md#1ada6859e72b1e39d87c27f2cd9428585f) (int location, const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** \* array, int length) const |
|void|[**setUniform2i**](classffw_1_1_shader.md#1a2363e924ea71d03f28ebd01d79889f34) (int location, const **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)** & vec) const |
|void|[**setUniform2iv**](classffw_1_1_shader.md#1aa92a2ffc7f9403c5d532a65beb96f9b8) (int location, const **[ffw::Vec2i](group__math_.md#ga8ac6bae8a24d96d0223a29ecfff14570)** \* array, int length) const |
|void|[**setUniform3f**](classffw_1_1_shader.md#1a4716661655e2b7c10a6cba8db20950eb) (int location, const **[ffw::Vec3f](group__math_.md#ga50484cfc0427110bb2a8072649b021af)** & vec) const |
|void|[**setUniform3fv**](classffw_1_1_shader.md#1ac6e76403f8824835faec068281ec352d) (int location, const **[ffw::Vec3f](group__math_.md#ga50484cfc0427110bb2a8072649b021af)** \* array, int length) const |
|void|[**setUniform3i**](classffw_1_1_shader.md#1a78e3285b09452c072cb53148fa7f68b7) (int location, const **[ffw::Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)** & vec) const |
|void|[**setUniform3iv**](classffw_1_1_shader.md#1aa0003ef44576ca12b05233dab2d6127a) (int location, const **[ffw::Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)** \* array, int length) const |
|void|[**setUniform4f**](classffw_1_1_shader.md#1ab461fc1475d58c06f17366863deb8732) (int location, const **[ffw::Vec4f](group__math_.md#gaa695e6ed043ba7215ae5cdb452cba72f)** & vec) const |
|void|[**setUniform4fv**](classffw_1_1_shader.md#1a397cdfcdc24dfff3337f0b39f0b2db4d) (int location, const **[ffw::Vec4f](group__math_.md#gaa695e6ed043ba7215ae5cdb452cba72f)** \* array, int length) const |
|void|[**setUniform4i**](classffw_1_1_shader.md#1aa198c5e74722d1c184aa8e5f8f1815ad) (int location, const **[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)** & vec) const |
|void|[**setUniform4iv**](classffw_1_1_shader.md#1a41bbb3ebbe2c24f8211828871c55eba0) (int location, const **[ffw::Vec4i](group__math_.md#ga3bd7b708561d6e2db0e66a1dd4177400)** \* array, int length) const |
|void|[**setUniform4f**](classffw_1_1_shader.md#1a30320f49960d025f866000181ce197fc) (int location, const **[ffw::Color](structffw_1_1_color.md)** & vec) const |
|void|[**setUniform4fv**](classffw_1_1_shader.md#1ad87e54841e2fe586e1b0bb89b4626283) (int location, const **[ffw::Color](structffw_1_1_color.md)** \* array, int length) const |
|void|[**setUniformMatrix2fv**](classffw_1_1_shader.md#1a3b22d42e27ac5b6318f4f1c1a006474e) (int location, const float \* mat, int length) const |
|void|[**setUniformMatrix3fv**](classffw_1_1_shader.md#1aa2336367c257850d8ff08cefc5878ae4) (int location, const float \* mat, int length) const |
|void|[**setUniformMatrix4fv**](classffw_1_1_shader.md#1a1fd6ed728b7787e10d5b31d1ede26c43) (int location, const float \* mat, int length) const |
|void|[**setUniformMatrix4fv**](classffw_1_1_shader.md#1a852874bc441d9ea758254b26e2aca5eb) (int location, const **[Mat4x4f](group__math_.md#gab671e957e1ab5adf76e6a93c1a382845)** \* mat, int length) const |
|**[Shader](classffw_1_1_shader.md)** &|[**operator=**](classffw_1_1_shader.md#1a56fcca032fa4c986657aaf0eb40428c6) (const **[Shader](classffw_1_1_shader.md)** & other) = delete |
|**[Shader](classffw_1_1_shader.md)** &|[**operator=**](classffw_1_1_shader.md#1a8a2ffc57287dd662364ec88f05ced50e) (**[Shader](classffw_1_1_shader.md)** && other) |


## Public Functions Documentation

### function <a id="1a3e8832a6263f5d337e1e5f07b8835182" href="#1a3e8832a6263f5d337e1e5f07b8835182">Shader</a>

```cpp
ffw::Shader::Shader ()
```



### function <a id="1a5f31b86dbe1c56b1deb50d400468ae88" href="#1a5f31b86dbe1c56b1deb50d400468ae88">Shader</a>

```cpp
ffw::Shader::Shader (
    const Shader & other
) = delete
```



### function <a id="1aebea35d6c7ff96350372baa0926b3426" href="#1aebea35d6c7ff96350372baa0926b3426">Shader</a>

```cpp
ffw::Shader::Shader (
    Shader && other
)
```



### function <a id="1ab57fc9ea854d16b06a1af51dfa84f2f2" href="#1ab57fc9ea854d16b06a1af51dfa84f2f2">swap</a>

```cpp
void ffw::Shader::swap (
    Shader & other
)
```



### function <a id="1aee0226d806f82eeb633c70d0596d8995" href="#1aee0226d806f82eeb633c70d0596d8995">~Shader</a>

```cpp
virtual ffw::Shader::~Shader ()
```



### function <a id="1a1e6cc4a641090edcd43f85127ab2fd36" href="#1a1e6cc4a641090edcd43f85127ab2fd36">isCreated</a>

```cpp
bool ffw::Shader::isCreated () const
```



### function <a id="1a7407c12be5bc642c44e46e1be0f07ab5" href="#1a7407c12be5bc642c44e46e1be0f07ab5">isLinked</a>

```cpp
bool ffw::Shader::isLinked () const
```



### function <a id="1ae5d53c3d84123c8b907a4aa03e19c8d6" href="#1ae5d53c3d84123c8b907a4aa03e19c8d6">isUsingFrag</a>

```cpp
bool ffw::Shader::isUsingFrag () const
```



### function <a id="1a217d60086f9f8e69967e713d1e20d2a6" href="#1a217d60086f9f8e69967e713d1e20d2a6">isUsingGeom</a>

```cpp
bool ffw::Shader::isUsingGeom () const
```



### function <a id="1a32931f8fba59a480dbd2fab06afdb719" href="#1a32931f8fba59a480dbd2fab06afdb719">isUsingVert</a>

```cpp
bool ffw::Shader::isUsingVert () const
```



### function <a id="1aacbe2f7a7501d75a865239c0f2e9070e" href="#1aacbe2f7a7501d75a865239c0f2e9070e">create</a>

```cpp
bool ffw::Shader::create ()
```



### function <a id="1a5d7ce766b2987f33c557c7894185e328" href="#1a5d7ce766b2987f33c557c7894185e328">Link</a>

```cpp
void ffw::Shader::Link ()
```



### function <a id="1a7587f237d38c49b615df9dfc80fac87e" href="#1a7587f237d38c49b615df9dfc80fac87e">compileFragFromData</a>

```cpp
void ffw::Shader::compileFragFromData (
    const std::string & code
)
```



### function <a id="1a8e604a43726c4a5732c5f71b15a0a049" href="#1a8e604a43726c4a5732c5f71b15a0a049">compileGeomFromData</a>

```cpp
void ffw::Shader::compileGeomFromData (
    const std::string & code
)
```



### function <a id="1a6db5facb2a7817db56e58157aada34b3" href="#1a6db5facb2a7817db56e58157aada34b3">compileVertFromData</a>

```cpp
void ffw::Shader::compileVertFromData (
    const std::string & code
)
```



### function <a id="1adc491f6c127aac2481e0c23ed4fae5b1" href="#1adc491f6c127aac2481e0c23ed4fae5b1">createFromFile</a>

```cpp
void ffw::Shader::createFromFile (
    const std::string & geomfile,
    const std::string & vertfile,
    const std::string & fragfile
)
```



### function <a id="1a6af4574b8009edf28e4fa3a53099970e" href="#1a6af4574b8009edf28e4fa3a53099970e">createFromData</a>

```cpp
void ffw::Shader::createFromData (
    const std::string & geomdata,
    const std::string & vertdata,
    const std::string & fragdata
)
```



### function <a id="1a6fb21b73d51cdcc9c1c01cc4ddf8d039" href="#1a6fb21b73d51cdcc9c1c01cc4ddf8d039">destroy</a>

```cpp
void ffw::Shader::destroy ()
```



### function <a id="1a1a283cc22b2cad1700cedc2be1a2832b" href="#1a1a283cc22b2cad1700cedc2be1a2832b">getHandle</a>

```cpp
unsigned int ffw::Shader::getHandle () const
```



### function <a id="1aad5be1169da5d2504c12a189796c9e23" href="#1aad5be1169da5d2504c12a189796c9e23">setAttributePointerf</a>

```cpp
void ffw::Shader::setAttributePointerf (
    int location,
    int size,
    int stride,
    const GLvoid * offset
) const
```



### function <a id="1a0fe8b4fac2721f14405964a77cc39a75" href="#1a0fe8b4fac2721f14405964a77cc39a75">setAttributeDivisor</a>

```cpp
void ffw::Shader::setAttributeDivisor (
    unsigned int index,
    unsigned int divisor
) const
```



### function <a id="1aad8f78f342b5e00a26f309861c49ba90" href="#1aad8f78f342b5e00a26f309861c49ba90">drawArrays</a>

```cpp
void ffw::Shader::drawArrays (
    unsigned int mode,
    int first,
    int cnt
) const
```



### function <a id="1ade838dd3797b8ca4b1dc9e3776805096" href="#1ade838dd3797b8ca4b1dc9e3776805096">drawArraysInstanced</a>

```cpp
void ffw::Shader::drawArraysInstanced (
    unsigned int mode,
    int First,
    int count,
    int instancecount
) const
```



### function <a id="1a517ebfc60d9c22d984ad79917aee9dda" href="#1a517ebfc60d9c22d984ad79917aee9dda">drawElements</a>

```cpp
void ffw::Shader::drawElements (
    unsigned int mode,
    int cnt,
    unsigned int type,
    const void * indices
) const
```



### function <a id="1af4a879097805dbf92f356a2119a26ab3" href="#1af4a879097805dbf92f356a2119a26ab3">drawElementsRange</a>

```cpp
void ffw::Shader::drawElementsRange (
    unsigned int mode,
    unsigned int start,
    unsigned int end,
    int cnt,
    unsigned int type,
    const void * indices
) const
```



### function <a id="1ae870b387c3dd8f6df8c88e028ca1d217" href="#1ae870b387c3dd8f6df8c88e028ca1d217">drawElementsInstanced</a>

```cpp
void ffw::Shader::drawElementsInstanced (
    unsigned int mode,
    int cnt,
    unsigned int type,
    const void * indices,
    int instancecount
) const
```



### function <a id="1a2bab874c923b45bc691c9fb0287c916e" href="#1a2bab874c923b45bc691c9fb0287c916e">bind</a>

```cpp
void ffw::Shader::bind () const
```



### function <a id="1ac1ffbce2c4ee1de6d4fb34f26c7a7415" href="#1ac1ffbce2c4ee1de6d4fb34f26c7a7415">unbind</a>

```cpp
void ffw::Shader::unbind () const
```



### function <a id="1a45fcf360b10b740c7b5d8841aa650f2e" href="#1a45fcf360b10b740c7b5d8841aa650f2e">getUniformLocation</a>

```cpp
int ffw::Shader::getUniformLocation (
    const char * name
) const
```



### function <a id="1ad98c91799accab8acf7cd8b6f55af112" href="#1ad98c91799accab8acf7cd8b6f55af112">getAttributeLocation</a>

```cpp
int ffw::Shader::getAttributeLocation (
    const char * name
) const
```



### function <a id="1a47fc42f655e2eedb43ccf04d1b11bc41" href="#1a47fc42f655e2eedb43ccf04d1b11bc41">setUniform1f</a>

```cpp
void ffw::Shader::setUniform1f (
    int location,
    float value
) const
```



### function <a id="1ab962479bf0a486d2feca17d92473404f" href="#1ab962479bf0a486d2feca17d92473404f">setUniform1fv</a>

```cpp
void ffw::Shader::setUniform1fv (
    int location,
    const float * array,
    int length
) const
```



### function <a id="1a5f31ed9a8644d74b6f433a303afe918f" href="#1a5f31ed9a8644d74b6f433a303afe918f">setUniform1i</a>

```cpp
void ffw::Shader::setUniform1i (
    int location,
    int value
) const
```



### function <a id="1acce81eaddf8c6140d3377dad77d16ffc" href="#1acce81eaddf8c6140d3377dad77d16ffc">setUniform1iv</a>

```cpp
void ffw::Shader::setUniform1iv (
    int location,
    const int * array,
    int length
) const
```



### function <a id="1add5da1b4a8c3e7ee150d5e858406a3a3" href="#1add5da1b4a8c3e7ee150d5e858406a3a3">setUniform2f</a>

```cpp
void ffw::Shader::setUniform2f (
    int location,
    float x,
    float y
) const
```



### function <a id="1a1e0879c8800a3b297d01559599b98e57" href="#1a1e0879c8800a3b297d01559599b98e57">setUniform2fv</a>

```cpp
void ffw::Shader::setUniform2fv (
    int location,
    const float * array,
    int length
) const
```



### function <a id="1aa17468d4cc845c7ed14b64bc8611de59" href="#1aa17468d4cc845c7ed14b64bc8611de59">setUniform2i</a>

```cpp
void ffw::Shader::setUniform2i (
    int location,
    int x,
    int y
) const
```



### function <a id="1a5dd7977add525844cc8b4844925043bf" href="#1a5dd7977add525844cc8b4844925043bf">setUniform2iv</a>

```cpp
void ffw::Shader::setUniform2iv (
    int location,
    const int * array,
    int length
) const
```



### function <a id="1a1c83fe2d028fc9a05652004c64143890" href="#1a1c83fe2d028fc9a05652004c64143890">setUniform3f</a>

```cpp
void ffw::Shader::setUniform3f (
    int location,
    float x,
    float y,
    float z
) const
```



### function <a id="1aed93f99cef5c6ef084a598ddf0aba59f" href="#1aed93f99cef5c6ef084a598ddf0aba59f">setUniform3fv</a>

```cpp
void ffw::Shader::setUniform3fv (
    int location,
    const float * array,
    int length
) const
```



### function <a id="1a2d6254ad9ddd1446e5add48d54d8ca7a" href="#1a2d6254ad9ddd1446e5add48d54d8ca7a">setUniform3i</a>

```cpp
void ffw::Shader::setUniform3i (
    int location,
    int x,
    int y,
    int z
) const
```



### function <a id="1ad001ea7b06a9894e8be18310c2a23d2b" href="#1ad001ea7b06a9894e8be18310c2a23d2b">setUniform3iv</a>

```cpp
void ffw::Shader::setUniform3iv (
    int location,
    const int * array,
    int length
) const
```



### function <a id="1aa842ce3be07ec0f33c70ee36e33cb86f" href="#1aa842ce3be07ec0f33c70ee36e33cb86f">setUniform4f</a>

```cpp
void ffw::Shader::setUniform4f (
    int location,
    float x,
    float y,
    float z,
    float w
) const
```



### function <a id="1ab02356d965db08aa0d9f53c4f37d2e5b" href="#1ab02356d965db08aa0d9f53c4f37d2e5b">setUniform4fv</a>

```cpp
void ffw::Shader::setUniform4fv (
    int location,
    const float * array,
    int length
) const
```



### function <a id="1a7b4087d48bf35ac6a1a3e818060146fc" href="#1a7b4087d48bf35ac6a1a3e818060146fc">setUniform4i</a>

```cpp
void ffw::Shader::setUniform4i (
    int location,
    int x,
    int y,
    int z,
    int w
) const
```



### function <a id="1ab057dc559a8142a4142e472e62b93f7a" href="#1ab057dc559a8142a4142e472e62b93f7a">setUniform4iv</a>

```cpp
void ffw::Shader::setUniform4iv (
    int location,
    const int * array,
    int length
) const
```



### function <a id="1a008fbdc81720add3ba219cd1d86a5e93" href="#1a008fbdc81720add3ba219cd1d86a5e93">setUniform2f</a>

```cpp
void ffw::Shader::setUniform2f (
    int location,
    const ffw::Vec2f & vec
) const
```



### function <a id="1ada6859e72b1e39d87c27f2cd9428585f" href="#1ada6859e72b1e39d87c27f2cd9428585f">setUniform2fv</a>

```cpp
void ffw::Shader::setUniform2fv (
    int location,
    const ffw::Vec2f * array,
    int length
) const
```



### function <a id="1a2363e924ea71d03f28ebd01d79889f34" href="#1a2363e924ea71d03f28ebd01d79889f34">setUniform2i</a>

```cpp
void ffw::Shader::setUniform2i (
    int location,
    const ffw::Vec2i & vec
) const
```



### function <a id="1aa92a2ffc7f9403c5d532a65beb96f9b8" href="#1aa92a2ffc7f9403c5d532a65beb96f9b8">setUniform2iv</a>

```cpp
void ffw::Shader::setUniform2iv (
    int location,
    const ffw::Vec2i * array,
    int length
) const
```



### function <a id="1a4716661655e2b7c10a6cba8db20950eb" href="#1a4716661655e2b7c10a6cba8db20950eb">setUniform3f</a>

```cpp
void ffw::Shader::setUniform3f (
    int location,
    const ffw::Vec3f & vec
) const
```



### function <a id="1ac6e76403f8824835faec068281ec352d" href="#1ac6e76403f8824835faec068281ec352d">setUniform3fv</a>

```cpp
void ffw::Shader::setUniform3fv (
    int location,
    const ffw::Vec3f * array,
    int length
) const
```



### function <a id="1a78e3285b09452c072cb53148fa7f68b7" href="#1a78e3285b09452c072cb53148fa7f68b7">setUniform3i</a>

```cpp
void ffw::Shader::setUniform3i (
    int location,
    const ffw::Vec3i & vec
) const
```



### function <a id="1aa0003ef44576ca12b05233dab2d6127a" href="#1aa0003ef44576ca12b05233dab2d6127a">setUniform3iv</a>

```cpp
void ffw::Shader::setUniform3iv (
    int location,
    const ffw::Vec3i * array,
    int length
) const
```



### function <a id="1ab461fc1475d58c06f17366863deb8732" href="#1ab461fc1475d58c06f17366863deb8732">setUniform4f</a>

```cpp
void ffw::Shader::setUniform4f (
    int location,
    const ffw::Vec4f & vec
) const
```



### function <a id="1a397cdfcdc24dfff3337f0b39f0b2db4d" href="#1a397cdfcdc24dfff3337f0b39f0b2db4d">setUniform4fv</a>

```cpp
void ffw::Shader::setUniform4fv (
    int location,
    const ffw::Vec4f * array,
    int length
) const
```



### function <a id="1aa198c5e74722d1c184aa8e5f8f1815ad" href="#1aa198c5e74722d1c184aa8e5f8f1815ad">setUniform4i</a>

```cpp
void ffw::Shader::setUniform4i (
    int location,
    const ffw::Vec4i & vec
) const
```



### function <a id="1a41bbb3ebbe2c24f8211828871c55eba0" href="#1a41bbb3ebbe2c24f8211828871c55eba0">setUniform4iv</a>

```cpp
void ffw::Shader::setUniform4iv (
    int location,
    const ffw::Vec4i * array,
    int length
) const
```



### function <a id="1a30320f49960d025f866000181ce197fc" href="#1a30320f49960d025f866000181ce197fc">setUniform4f</a>

```cpp
void ffw::Shader::setUniform4f (
    int location,
    const ffw::Color & vec
) const
```



### function <a id="1ad87e54841e2fe586e1b0bb89b4626283" href="#1ad87e54841e2fe586e1b0bb89b4626283">setUniform4fv</a>

```cpp
void ffw::Shader::setUniform4fv (
    int location,
    const ffw::Color * array,
    int length
) const
```



### function <a id="1a3b22d42e27ac5b6318f4f1c1a006474e" href="#1a3b22d42e27ac5b6318f4f1c1a006474e">setUniformMatrix2fv</a>

```cpp
void ffw::Shader::setUniformMatrix2fv (
    int location,
    const float * mat,
    int length
) const
```



### function <a id="1aa2336367c257850d8ff08cefc5878ae4" href="#1aa2336367c257850d8ff08cefc5878ae4">setUniformMatrix3fv</a>

```cpp
void ffw::Shader::setUniformMatrix3fv (
    int location,
    const float * mat,
    int length
) const
```



### function <a id="1a1fd6ed728b7787e10d5b31d1ede26c43" href="#1a1fd6ed728b7787e10d5b31d1ede26c43">setUniformMatrix4fv</a>

```cpp
void ffw::Shader::setUniformMatrix4fv (
    int location,
    const float * mat,
    int length
) const
```



### function <a id="1a852874bc441d9ea758254b26e2aca5eb" href="#1a852874bc441d9ea758254b26e2aca5eb">setUniformMatrix4fv</a>

```cpp
void ffw::Shader::setUniformMatrix4fv (
    int location,
    const Mat4x4f * mat,
    int length
) const
```



### function <a id="1a56fcca032fa4c986657aaf0eb40428c6" href="#1a56fcca032fa4c986657aaf0eb40428c6">operator=</a>

```cpp
Shader & ffw::Shader::operator= (
    const Shader & other
) = delete
```



### function <a id="1a8a2ffc57287dd662364ec88f05ced50e" href="#1a8a2ffc57287dd662364ec88f05ced50e">operator=</a>

```cpp
Shader & ffw::Shader::operator= (
    Shader && other
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/graphics/shader.h`
