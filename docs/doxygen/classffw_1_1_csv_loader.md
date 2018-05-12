---
search: false
---

# class ffw::CsvLoader

## Public Functions

|Type|Name|
|-----|-----|
||[**CsvLoader**](classffw_1_1_csv_loader.md#1a00df7f523c607e54a0674435d28287ca) () |
||[**~CsvLoader**](classffw_1_1_csv_loader.md#1ab4979a080e64793780b1ded073f651d5) () |
|bool|[**openFromData**](classffw_1_1_csv_loader.md#1a8d7473dde2f5776bda43a003593269a7) (const std::string & input, char delim = ',', char quote = '\"') <br>Opens CSV from data (string) |
|bool|[**openFromFile**](classffw_1_1_csv_loader.md#1a42ae6d1fa3e13b686c7546d44a397548) (const std::string & path, char delim = ',', char quote = '\"') <br>Opens CSV from file. |
|bool|[**isOpen**](classffw_1_1_csv_loader.md#1a5a073efffc4762b47019ac310f02e7d9) () const |
|void|[**close**](classffw_1_1_csv_loader.md#1a7db4818716354fbe834b64b82ee0b1af) () |
|std::string|[**getRowRaw**](classffw_1_1_csv_loader.md#1a7a2312f6cfcff07f1a509a5165173ba2) () |
|**[ffw::Array](classffw_1_1_array.md)**|[**getRow**](classffw_1_1_csv_loader.md#1a3021f058a120e4aedf0a892579e3dc8b) (bool convert = true) |
|bool|[**eof**](classffw_1_1_csv_loader.md#1a660eb27565d56a5140110322780cabc8) () const |


## Public Static Functions

|Type|Name|
|-----|-----|
|static **[ffw::Array](classffw_1_1_array.md)**|[**tokenize**](classffw_1_1_csv_loader.md#1a088b3e61b47fb380fcec3bf247f6487f) (const std::string & str, size\_t begin, size\_t end, bool convert = true, char delim = ',', char quote = '\"') |


## Detailed Description

doc/markdown/tutorial-csv.md 
## Public Functions Documentation

### function <a id="1a00df7f523c607e54a0674435d28287ca" href="#1a00df7f523c607e54a0674435d28287ca">CsvLoader</a>

```cpp
ffw::CsvLoader::CsvLoader ()
```



### function <a id="1ab4979a080e64793780b1ded073f651d5" href="#1ab4979a080e64793780b1ded073f651d5">~CsvLoader</a>

```cpp
ffw::CsvLoader::~CsvLoader ()
```



### function <a id="1a8d7473dde2f5776bda43a003593269a7" href="#1a8d7473dde2f5776bda43a003593269a7">openFromData</a>

```cpp
bool ffw::CsvLoader::openFromData (
    const std::string & input,
    char delim = ',',
    char quote = '\"'
)
```

Opens CSV from data (string) 



**Returns:**

Returns true on success 




### function <a id="1a42ae6d1fa3e13b686c7546d44a397548" href="#1a42ae6d1fa3e13b686c7546d44a397548">openFromFile</a>

```cpp
bool ffw::CsvLoader::openFromFile (
    const std::string & path,
    char delim = ',',
    char quote = '\"'
)
```

Opens CSV from file. 


### function <a id="1a5a073efffc4762b47019ac310f02e7d9" href="#1a5a073efffc4762b47019ac310f02e7d9">isOpen</a>

```cpp
bool ffw::CsvLoader::isOpen () const
```



### function <a id="1a7db4818716354fbe834b64b82ee0b1af" href="#1a7db4818716354fbe834b64b82ee0b1af">close</a>

```cpp
void ffw::CsvLoader::close ()
```



### function <a id="1a7a2312f6cfcff07f1a509a5165173ba2" href="#1a7a2312f6cfcff07f1a509a5165173ba2">getRowRaw</a>

```cpp
std::string ffw::CsvLoader::getRowRaw ()
```



### function <a id="1a3021f058a120e4aedf0a892579e3dc8b" href="#1a3021f058a120e4aedf0a892579e3dc8b">getRow</a>

```cpp
ffw::Array ffw::CsvLoader::getRow (
    bool convert = true
)
```



### function <a id="1a660eb27565d56a5140110322780cabc8" href="#1a660eb27565d56a5140110322780cabc8">eof</a>

```cpp
bool ffw::CsvLoader::eof () const
```



## Public Static Functions Documentation

### function <a id="1a088b3e61b47fb380fcec3bf247f6487f" href="#1a088b3e61b47fb380fcec3bf247f6487f">tokenize</a>

```cpp
static ffw::Array ffw::CsvLoader::tokenize (
    const std::string & str,
    size_t begin,
    size_t end,
    bool convert = true,
    char delim = ',',
    char quote = '\"'
)
```





----------------------------------------
The documentation for this class was generated from the following file: `include/ffw/data/csvreader.h`
