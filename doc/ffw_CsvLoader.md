CsvLoader
===================================


The documentation for this class was generated from: `include/ffw/data/csvreader.h`

## Detailed description

doc/markdown/tutorial-csv.md 


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [CsvLoader](#2350a56c) ()  |
|   | [~CsvLoader](#f7e45fee) ()  |
|  bool | [openFromData](#b0a6bdbf) (const std::string & _input_, char _delim_ = ',', char _quote_ = '\"') <div style="opacity:0.8;">Opens CSV from data (string) </div> |
|  bool | [openFromFile](#b4b6bc9e) (const std::string & _path_, char _delim_ = ',', char _quote_ = '\"') <div style="opacity:0.8;">Opens CSV from file. </div> |
|  bool | [isOpen](#7e6535ca) () const  |
|  void | [close](#7c1563e3) ()  |
|  std::string | [getRowRaw](#eaf83a9f) ()  |
|  [ffw::Array](ffw_Array.html) | [getRow](#f16edf3b) (bool _convert_ = true)  |
|  bool | [eof](#68e8a838) () const  |


## Public Static Functions

| Type | Name |
| -------: | :------- |
|  [ffw::Array](ffw_Array.html) | [tokenize](#1dd92eb0) (const std::string & _str_, size_t _begin_, size_t _end_, bool _convert_ = true, char _delim_ = ',', char _quote_ = '\"')  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="2350a56c" href="#2350a56c">CsvLoader</a>

```cpp
 CsvLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="f7e45fee" href="#f7e45fee">~CsvLoader</a>

```cpp
 ~CsvLoader () 
```



### <span style="opacity:0.5;">function</span> <a id="b0a6bdbf" href="#b0a6bdbf">openFromData</a>

```cpp
bool openFromData (
    const std::string & input,
    char delim = ',',
    char quote = '\"'
) 
```

Opens CSV from data (string) 

**return:** Returns true on success 


### <span style="opacity:0.5;">function</span> <a id="b4b6bc9e" href="#b4b6bc9e">openFromFile</a>

```cpp
bool openFromFile (
    const std::string & path,
    char delim = ',',
    char quote = '\"'
) 
```

Opens CSV from file. 

### <span style="opacity:0.5;">function</span> <a id="7e6535ca" href="#7e6535ca">isOpen</a>

```cpp
bool isOpen () const 
```



### <span style="opacity:0.5;">function</span> <a id="7c1563e3" href="#7c1563e3">close</a>

```cpp
void close () 
```



### <span style="opacity:0.5;">function</span> <a id="eaf83a9f" href="#eaf83a9f">getRowRaw</a>

```cpp
std::string getRowRaw () 
```



### <span style="opacity:0.5;">function</span> <a id="f16edf3b" href="#f16edf3b">getRow</a>

```cpp
ffw::Array getRow (
    bool convert = true
) 
```



### <span style="opacity:0.5;">function</span> <a id="68e8a838" href="#68e8a838">eof</a>

```cpp
bool eof () const 
```





## Public Static Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="1dd92eb0" href="#1dd92eb0">tokenize</a>

```cpp
static ffw::Array tokenize (
    const std::string & str,
    size_t begin,
    size_t end,
    bool convert = true,
    char delim = ',',
    char quote = '\"'
) 
```





