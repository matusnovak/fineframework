---
search:
    keywords: ['ffw::JsonReader::Node', 'ptr', 'len', 'Node', 'Node', 'str', 'raw', 'getType', 'isString', 'isObject', 'isArray', 'isEmpty', 'isNumber', 'isInteger', 'isFloat', 'isBoolean', 'isNull', 'toString', 'toInteger', 'toDouble', 'toFloat', 'toBoolean']
---

# class ffw::JsonReader::Node

## Public Attributes

|Type|Name|
|-----|-----|
|const char \*|[**ptr**](classffw_1_1_json_reader_1_1_node.md#1a8f79be890e0676ea36ed6ddb362a0859)|
|size\_t|[**len**](classffw_1_1_json_reader_1_1_node.md#1a685d381ec8118b55f72e97cdb1de4c1f)|


## Public Functions

|Type|Name|
|-----|-----|
||[**Node**](classffw_1_1_json_reader_1_1_node.md#1a5edfccc90f621d7ceb72a5b4c05795d7) (const char \* p, size\_t l) |
||[**Node**](classffw_1_1_json_reader_1_1_node.md#1a4cb21e2f0281f24b62b6c2978a0e52ea) () |
|std::string|[**str**](classffw_1_1_json_reader_1_1_node.md#1a23db5bd03a788069afd356339559c205) () const |
|std::string|[**raw**](classffw_1_1_json_reader_1_1_node.md#1a1d0e0f4843fa161538a75643247b39fa) () const |
|**[Type](classffw_1_1_json_reader.md#1a84e248b0f735533d7692ce091095de16)**|[**getType**](classffw_1_1_json_reader_1_1_node.md#1a1e162896b9a10100a41c50da52d7bc2d) () const |
|bool|[**isString**](classffw_1_1_json_reader_1_1_node.md#1a3ef88585d37ddcda68dbccd378b44b77) () const |
|bool|[**isObject**](classffw_1_1_json_reader_1_1_node.md#1a67b95625b7d22e6699235e6b98b46f51) () const |
|bool|[**isArray**](classffw_1_1_json_reader_1_1_node.md#1ab2e7e5adeb331bfd0cd19ade1d387af6) () const |
|bool|[**isEmpty**](classffw_1_1_json_reader_1_1_node.md#1a7d3d86c0112c70d2800a5da5fee79ade) () const |
|bool|[**isNumber**](classffw_1_1_json_reader_1_1_node.md#1a741d5374a7544f4701accce6b5e4cd26) () const |
|bool|[**isInteger**](classffw_1_1_json_reader_1_1_node.md#1a939690e54f17813f10ebf4d889efc118) () const |
|bool|[**isFloat**](classffw_1_1_json_reader_1_1_node.md#1a4fdf6f974c0751ad57d6dfe14e16ef71) () const |
|bool|[**isBoolean**](classffw_1_1_json_reader_1_1_node.md#1a62811ba773df1ee153bc90fbf49e8e9e) () const |
|bool|[**isNull**](classffw_1_1_json_reader_1_1_node.md#1a3946c2badd09e546e570dbcfd310e1ba) () const |
|std::string|[**toString**](classffw_1_1_json_reader_1_1_node.md#1ad8629fdeeebbd23c0514be98b3aa79a8) () const |
|int|[**toInteger**](classffw_1_1_json_reader_1_1_node.md#1afc748672940bb24d058fe49bde79adf9) () const |
|double|[**toDouble**](classffw_1_1_json_reader_1_1_node.md#1a578416be84c0a1e84664e0a5da5924df) () const |
|float|[**toFloat**](classffw_1_1_json_reader_1_1_node.md#1a57c24a23a1aba60e5b94d0bd3698cc46) () const |
|bool|[**toBoolean**](classffw_1_1_json_reader_1_1_node.md#1ab4ef6cb4cc5ae7575bc0088039ecd813) () const |


## Public Attributes Documentation

### variable <a id="1a8f79be890e0676ea36ed6ddb362a0859" href="#1a8f79be890e0676ea36ed6ddb362a0859">ptr</a>

```cpp
const char* ffw::JsonReader::Node::ptr;
```



### variable <a id="1a685d381ec8118b55f72e97cdb1de4c1f" href="#1a685d381ec8118b55f72e97cdb1de4c1f">len</a>

```cpp
size_t ffw::JsonReader::Node::len;
```



## Public Functions Documentation

### function <a id="1a5edfccc90f621d7ceb72a5b4c05795d7" href="#1a5edfccc90f621d7ceb72a5b4c05795d7">Node</a>

```cpp
ffw::JsonReader::Node::Node (
    const char * p
    size_t l
)
```



### function <a id="1a4cb21e2f0281f24b62b6c2978a0e52ea" href="#1a4cb21e2f0281f24b62b6c2978a0e52ea">Node</a>

```cpp
ffw::JsonReader::Node::Node ()
```



### function <a id="1a23db5bd03a788069afd356339559c205" href="#1a23db5bd03a788069afd356339559c205">str</a>

```cpp
std::string ffw::JsonReader::Node::str () const
```



### function <a id="1a1d0e0f4843fa161538a75643247b39fa" href="#1a1d0e0f4843fa161538a75643247b39fa">raw</a>

```cpp
std::string ffw::JsonReader::Node::raw () const
```



### function <a id="1a1e162896b9a10100a41c50da52d7bc2d" href="#1a1e162896b9a10100a41c50da52d7bc2d">getType</a>

```cpp
Type ffw::JsonReader::Node::getType () const
```



### function <a id="1a3ef88585d37ddcda68dbccd378b44b77" href="#1a3ef88585d37ddcda68dbccd378b44b77">isString</a>

```cpp
bool ffw::JsonReader::Node::isString () const
```



### function <a id="1a67b95625b7d22e6699235e6b98b46f51" href="#1a67b95625b7d22e6699235e6b98b46f51">isObject</a>

```cpp
bool ffw::JsonReader::Node::isObject () const
```



### function <a id="1ab2e7e5adeb331bfd0cd19ade1d387af6" href="#1ab2e7e5adeb331bfd0cd19ade1d387af6">isArray</a>

```cpp
bool ffw::JsonReader::Node::isArray () const
```



### function <a id="1a7d3d86c0112c70d2800a5da5fee79ade" href="#1a7d3d86c0112c70d2800a5da5fee79ade">isEmpty</a>

```cpp
bool ffw::JsonReader::Node::isEmpty () const
```



### function <a id="1a741d5374a7544f4701accce6b5e4cd26" href="#1a741d5374a7544f4701accce6b5e4cd26">isNumber</a>

```cpp
bool ffw::JsonReader::Node::isNumber () const
```



### function <a id="1a939690e54f17813f10ebf4d889efc118" href="#1a939690e54f17813f10ebf4d889efc118">isInteger</a>

```cpp
bool ffw::JsonReader::Node::isInteger () const
```



### function <a id="1a4fdf6f974c0751ad57d6dfe14e16ef71" href="#1a4fdf6f974c0751ad57d6dfe14e16ef71">isFloat</a>

```cpp
bool ffw::JsonReader::Node::isFloat () const
```



### function <a id="1a62811ba773df1ee153bc90fbf49e8e9e" href="#1a62811ba773df1ee153bc90fbf49e8e9e">isBoolean</a>

```cpp
bool ffw::JsonReader::Node::isBoolean () const
```



### function <a id="1a3946c2badd09e546e570dbcfd310e1ba" href="#1a3946c2badd09e546e570dbcfd310e1ba">isNull</a>

```cpp
bool ffw::JsonReader::Node::isNull () const
```



### function <a id="1ad8629fdeeebbd23c0514be98b3aa79a8" href="#1ad8629fdeeebbd23c0514be98b3aa79a8">toString</a>

```cpp
std::string ffw::JsonReader::Node::toString () const
```



### function <a id="1afc748672940bb24d058fe49bde79adf9" href="#1afc748672940bb24d058fe49bde79adf9">toInteger</a>

```cpp
int ffw::JsonReader::Node::toInteger () const
```



### function <a id="1a578416be84c0a1e84664e0a5da5924df" href="#1a578416be84c0a1e84664e0a5da5924df">toDouble</a>

```cpp
double ffw::JsonReader::Node::toDouble () const
```



### function <a id="1a57c24a23a1aba60e5b94d0bd3698cc46" href="#1a57c24a23a1aba60e5b94d0bd3698cc46">toFloat</a>

```cpp
float ffw::JsonReader::Node::toFloat () const
```



### function <a id="1ab4ef6cb4cc5ae7575bc0088039ecd813" href="#1ab4ef6cb4cc5ae7575bc0088039ecd813">toBoolean</a>

```cpp
bool ffw::JsonReader::Node::toBoolean () const
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/jsonreader.h`
