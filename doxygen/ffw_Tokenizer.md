Tokenizer
===================================


The documentation for this class was generated from: `include/ffw/math/tokenizer.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Tokenizer](#dc748513) (const std::basic_string< T, CharTrait, Allocator > & _str_, const std::basic_string< T, CharTrait, Allocator > & _delim_)  |
|  bool | [getNext](#68a4debf) (std::basic_string< T, CharTrait, Allocator > * _str_)  |
|  std::basic_string< T, CharTrait, Allocator > | [getNext](#17a4d4bc) ()  |
|  bool | [skipNext](#83eb9482) ()  |
|  bool | [hasNext](#4adfb51e) ()  |
|  size_t | [getPos](#ecd29501) ()  |


## Public Functions Documentation

### _function_ <a id="dc748513" href="#dc748513">Tokenizer</a>

```cpp
inline  Tokenizer (
    const std::basic_string< T, CharTrait, Allocator > & str,
    const std::basic_string< T, CharTrait, Allocator > & delim
) 
```



### _function_ <a id="68a4debf" href="#68a4debf">getNext</a>

```cpp
inline bool getNext (
    std::basic_string< T, CharTrait, Allocator > * str
) 
```



### _function_ <a id="17a4d4bc" href="#17a4d4bc">getNext</a>

```cpp
inline std::basic_string< T, CharTrait, Allocator > getNext () 
```



### _function_ <a id="83eb9482" href="#83eb9482">skipNext</a>

```cpp
inline bool skipNext () 
```



### _function_ <a id="4adfb51e" href="#4adfb51e">hasNext</a>

```cpp
inline bool hasNext () 
```



### _function_ <a id="ecd29501" href="#ecd29501">getPos</a>

```cpp
inline size_t getPos () 
```





