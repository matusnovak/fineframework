---
search:
    keywords: ['ffw::ObjLoader', 'ObjLoader', 'ObjLoader', 'ObjLoader', '~ObjLoader', 'swap', 'open', 'getNextObject', 'getPolygon', 'calculatePolyCount', 'isOpen', 'operator bool', 'getMtllibName', 'getCurrentLineNum', 'getCurrentMaterialName', 'getMaterialFoundFlag', 'resetMaterialFoundFlag', 'objectHasNormals', 'objectHasTexcoords', 'getIndex0', 'getIndex1', 'getIndex2', 'getVertex', 'getNormal', 'getTexCoord2', 'getTexCoord3', 'gotObject', 'fillData', 'close', 'operator=', 'operator=']
---

# class ffw::ObjLoader

## Public Functions

|Type|Name|
|-----|-----|
||[**ObjLoader**](classffw_1_1_obj_loader.md#1a8acebc72a1cef3fb9d3b65549077d421) () |
||[**ObjLoader**](classffw_1_1_obj_loader.md#1a195b0b9d7dfc9dec3cafc3a32353beef) (const **[ObjLoader](classffw_1_1_obj_loader.md)** & other) = delete |
||[**ObjLoader**](classffw_1_1_obj_loader.md#1ae59c36220f6af5e86edeef6b30fe5590) (**[ObjLoader](classffw_1_1_obj_loader.md)** && other) |
||[**~ObjLoader**](classffw_1_1_obj_loader.md#1af0912b0d4ced0eab9c41c5e28b06f33c) () |
|void|[**swap**](classffw_1_1_obj_loader.md#1a48d46e8866944732bfc2fc8426e8f4b8) (**[ObjLoader](classffw_1_1_obj_loader.md)** & other) |
|bool|[**open**](classffw_1_1_obj_loader.md#1af70d32ed79ae198ce458988d89f85b4c) (const std::string & path) |
|bool|[**getNextObject**](classffw_1_1_obj_loader.md#1a5d447ca1d0008cd122093ddd9973f7a9) (std::string \* name) |
|bool|[**getPolygon**](classffw_1_1_obj_loader.md#1a6df1173c0625ada4de430984e1bbf19c) () |
|size\_t|[**calculatePolyCount**](classffw_1_1_obj_loader.md#1adb7ca13305dd4e7b12853f3c2e4193cc) () |
|bool|[**isOpen**](classffw_1_1_obj_loader.md#1a0ee85ebf57668cff53da3d7f8214729c) () const |
||[**operator bool**](classffw_1_1_obj_loader.md#1a4d7bc4f8c53b8c284228c96d82158ab2) () const |
|const std::string &|[**getMtllibName**](classffw_1_1_obj_loader.md#1ae4f4cff08e9496e9da66d784bfe65962) () const |
|size\_t|[**getCurrentLineNum**](classffw_1_1_obj_loader.md#1a1fc5310d5f57b161495bb2de51f7c07a) () const |
|const std::string &|[**getCurrentMaterialName**](classffw_1_1_obj_loader.md#1a5fced66015c1fa9b23ccb8a97f0554a0) () const |
|bool|[**getMaterialFoundFlag**](classffw_1_1_obj_loader.md#1aab77c2ace1d87af28892094f3796e392) () const |
|void|[**resetMaterialFoundFlag**](classffw_1_1_obj_loader.md#1af8faa49d3e864396df5763b2330ae027) () |
|bool|[**objectHasNormals**](classffw_1_1_obj_loader.md#1aa3dda22e1b95626a180f5c1f83e673f4) () const |
|bool|[**objectHasTexcoords**](classffw_1_1_obj_loader.md#1a07b0b4bf5dd0aef15ef30e2cf3f67d2b) () const |
|const **[ffw::Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)** &|[**getIndex0**](classffw_1_1_obj_loader.md#1aba255199fa4b97fdf6e130f3daf4a4da) () const |
|const **[ffw::Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)** &|[**getIndex1**](classffw_1_1_obj_loader.md#1ace8089e87e540d12aa5167336b10d472) () const |
|const **[ffw::Vec3i](group__math_.md#gafd4bb1ab82109f15d80681d443404df8)** &|[**getIndex2**](classffw_1_1_obj_loader.md#1a2b119c3ad79abd7263775cb8dbe9b458) () const |
|const **[ffw::Vec3f](group__math_.md#ga50484cfc0427110bb2a8072649b021af)** &|[**getVertex**](classffw_1_1_obj_loader.md#1ab913f5ee6d8d9a3c1dcbd340d4c2fea2) (size\_t i) const |
|const **[ffw::Vec3f](group__math_.md#ga50484cfc0427110bb2a8072649b021af)** &|[**getNormal**](classffw_1_1_obj_loader.md#1ad24efbd5bfb0238320fa1d602084c87d) (size\_t i) const |
|const **[ffw::Vec2f](group__math_.md#ga44573357c25b7969b4391ca0ae427636)** &|[**getTexCoord2**](classffw_1_1_obj_loader.md#1a5783dd1258e52bb2db59f12efb65a2de) (size\_t i) const |
|const **[ffw::Vec3f](group__math_.md#ga50484cfc0427110bb2a8072649b021af)** &|[**getTexCoord3**](classffw_1_1_obj_loader.md#1a4fb56909b297e34748c55c401fba6d5c) (size\_t i) const |
|bool|[**gotObject**](classffw_1_1_obj_loader.md#1aa0c2819c91da64fb00caf6af3684a1e2) () const |
|void|[**fillData**](classffw_1_1_obj_loader.md#1a562bc528cf4029512db84b0576e6e46b) (float \* ptr, size\_t vo = 0, size\_t no = 3, size\_t to = 6, bool ts = false, size\_t stride = 8) |
|void|[**close**](classffw_1_1_obj_loader.md#1a7c7556f84e4756386876603708567d45) () |
|**[ObjLoader](classffw_1_1_obj_loader.md)** &|[**operator=**](classffw_1_1_obj_loader.md#1ae62c787a7f83f35fd30d908571dd89c9) (**[ObjLoader](classffw_1_1_obj_loader.md)** && Other) |
|**[ObjLoader](classffw_1_1_obj_loader.md)** &|[**operator=**](classffw_1_1_obj_loader.md#1a619a5b553f2655717d040007f529dccc) (const **[ObjLoader](classffw_1_1_obj_loader.md)** & Other) = delete |


## Public Functions Documentation

### function <a id="1a8acebc72a1cef3fb9d3b65549077d421" href="#1a8acebc72a1cef3fb9d3b65549077d421">ObjLoader</a>

```cpp
ffw::ObjLoader::ObjLoader ()
```



### function <a id="1a195b0b9d7dfc9dec3cafc3a32353beef" href="#1a195b0b9d7dfc9dec3cafc3a32353beef">ObjLoader</a>

```cpp
ffw::ObjLoader::ObjLoader (
    const ObjLoader & other
) = delete
```



### function <a id="1ae59c36220f6af5e86edeef6b30fe5590" href="#1ae59c36220f6af5e86edeef6b30fe5590">ObjLoader</a>

```cpp
ffw::ObjLoader::ObjLoader (
    ObjLoader && other
)
```



### function <a id="1af0912b0d4ced0eab9c41c5e28b06f33c" href="#1af0912b0d4ced0eab9c41c5e28b06f33c">~ObjLoader</a>

```cpp
ffw::ObjLoader::~ObjLoader ()
```



### function <a id="1a48d46e8866944732bfc2fc8426e8f4b8" href="#1a48d46e8866944732bfc2fc8426e8f4b8">swap</a>

```cpp
void ffw::ObjLoader::swap (
    ObjLoader & other
)
```



### function <a id="1af70d32ed79ae198ce458988d89f85b4c" href="#1af70d32ed79ae198ce458988d89f85b4c">open</a>

```cpp
bool ffw::ObjLoader::open (
    const std::string & path
)
```



### function <a id="1a5d447ca1d0008cd122093ddd9973f7a9" href="#1a5d447ca1d0008cd122093ddd9973f7a9">getNextObject</a>

```cpp
bool ffw::ObjLoader::getNextObject (
    std::string * name
)
```



### function <a id="1a6df1173c0625ada4de430984e1bbf19c" href="#1a6df1173c0625ada4de430984e1bbf19c">getPolygon</a>

```cpp
bool ffw::ObjLoader::getPolygon ()
```



### function <a id="1adb7ca13305dd4e7b12853f3c2e4193cc" href="#1adb7ca13305dd4e7b12853f3c2e4193cc">calculatePolyCount</a>

```cpp
size_t ffw::ObjLoader::calculatePolyCount ()
```



### function <a id="1a0ee85ebf57668cff53da3d7f8214729c" href="#1a0ee85ebf57668cff53da3d7f8214729c">isOpen</a>

```cpp
bool ffw::ObjLoader::isOpen () const
```



### function <a id="1a4d7bc4f8c53b8c284228c96d82158ab2" href="#1a4d7bc4f8c53b8c284228c96d82158ab2">operator bool</a>

```cpp
ffw::ObjLoader::operator bool () const
```



### function <a id="1ae4f4cff08e9496e9da66d784bfe65962" href="#1ae4f4cff08e9496e9da66d784bfe65962">getMtllibName</a>

```cpp
const std::string & ffw::ObjLoader::getMtllibName () const
```



### function <a id="1a1fc5310d5f57b161495bb2de51f7c07a" href="#1a1fc5310d5f57b161495bb2de51f7c07a">getCurrentLineNum</a>

```cpp
size_t ffw::ObjLoader::getCurrentLineNum () const
```



### function <a id="1a5fced66015c1fa9b23ccb8a97f0554a0" href="#1a5fced66015c1fa9b23ccb8a97f0554a0">getCurrentMaterialName</a>

```cpp
const std::string & ffw::ObjLoader::getCurrentMaterialName () const
```



### function <a id="1aab77c2ace1d87af28892094f3796e392" href="#1aab77c2ace1d87af28892094f3796e392">getMaterialFoundFlag</a>

```cpp
bool ffw::ObjLoader::getMaterialFoundFlag () const
```



### function <a id="1af8faa49d3e864396df5763b2330ae027" href="#1af8faa49d3e864396df5763b2330ae027">resetMaterialFoundFlag</a>

```cpp
void ffw::ObjLoader::resetMaterialFoundFlag ()
```



### function <a id="1aa3dda22e1b95626a180f5c1f83e673f4" href="#1aa3dda22e1b95626a180f5c1f83e673f4">objectHasNormals</a>

```cpp
bool ffw::ObjLoader::objectHasNormals () const
```



### function <a id="1a07b0b4bf5dd0aef15ef30e2cf3f67d2b" href="#1a07b0b4bf5dd0aef15ef30e2cf3f67d2b">objectHasTexcoords</a>

```cpp
bool ffw::ObjLoader::objectHasTexcoords () const
```



### function <a id="1aba255199fa4b97fdf6e130f3daf4a4da" href="#1aba255199fa4b97fdf6e130f3daf4a4da">getIndex0</a>

```cpp
const ffw::Vec3i & ffw::ObjLoader::getIndex0 () const
```



### function <a id="1ace8089e87e540d12aa5167336b10d472" href="#1ace8089e87e540d12aa5167336b10d472">getIndex1</a>

```cpp
const ffw::Vec3i & ffw::ObjLoader::getIndex1 () const
```



### function <a id="1a2b119c3ad79abd7263775cb8dbe9b458" href="#1a2b119c3ad79abd7263775cb8dbe9b458">getIndex2</a>

```cpp
const ffw::Vec3i & ffw::ObjLoader::getIndex2 () const
```



### function <a id="1ab913f5ee6d8d9a3c1dcbd340d4c2fea2" href="#1ab913f5ee6d8d9a3c1dcbd340d4c2fea2">getVertex</a>

```cpp
const ffw::Vec3f & ffw::ObjLoader::getVertex (
    size_t i
) const
```



### function <a id="1ad24efbd5bfb0238320fa1d602084c87d" href="#1ad24efbd5bfb0238320fa1d602084c87d">getNormal</a>

```cpp
const ffw::Vec3f & ffw::ObjLoader::getNormal (
    size_t i
) const
```



### function <a id="1a5783dd1258e52bb2db59f12efb65a2de" href="#1a5783dd1258e52bb2db59f12efb65a2de">getTexCoord2</a>

```cpp
const ffw::Vec2f & ffw::ObjLoader::getTexCoord2 (
    size_t i
) const
```



### function <a id="1a4fb56909b297e34748c55c401fba6d5c" href="#1a4fb56909b297e34748c55c401fba6d5c">getTexCoord3</a>

```cpp
const ffw::Vec3f & ffw::ObjLoader::getTexCoord3 (
    size_t i
) const
```



### function <a id="1aa0c2819c91da64fb00caf6af3684a1e2" href="#1aa0c2819c91da64fb00caf6af3684a1e2">gotObject</a>

```cpp
bool ffw::ObjLoader::gotObject () const
```



### function <a id="1a562bc528cf4029512db84b0576e6e46b" href="#1a562bc528cf4029512db84b0576e6e46b">fillData</a>

```cpp
void ffw::ObjLoader::fillData (
    float * ptr
    size_t vo = 0
    size_t no = 3
    size_t to = 6
    bool ts = false
    size_t stride = 8
)
```



### function <a id="1a7c7556f84e4756386876603708567d45" href="#1a7c7556f84e4756386876603708567d45">close</a>

```cpp
void ffw::ObjLoader::close ()
```



### function <a id="1ae62c787a7f83f35fd30d908571dd89c9" href="#1ae62c787a7f83f35fd30d908571dd89c9">operator=</a>

```cpp
ObjLoader & ffw::ObjLoader::operator= (
    ObjLoader && Other
)
```



### function <a id="1a619a5b553f2655717d040007f529dccc" href="#1a619a5b553f2655717d040007f529dccc">operator=</a>

```cpp
ObjLoader & ffw::ObjLoader::operator= (
    const ObjLoader & Other
) = delete
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/media/objloader.h`
