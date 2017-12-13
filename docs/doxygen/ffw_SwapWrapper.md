SwapWrapper
===================================


The documentation for this class was generated from: `include/ffw/swapwrapper.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  std::unique_ptr< T > | [ptr](#26afb438) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [SwapWrapper](#93a69493) (Args &&... _args_)  |
|   | [SwapWrapper](#9de214be) ([SwapWrapper](ffw_SwapWrapper.html) && _other_)  |
|  [SwapWrapper](ffw_SwapWrapper.html) & | [operator=](#bfc8a933) ([SwapWrapper](ffw_SwapWrapper.html) && _other_)  |
|  void | [swap](#a9cdfd36) ([SwapWrapper](ffw_SwapWrapper.html)< T > & _other_)  |
|  T & | [operator*](#4a1757f4) ()  |
|  const T & | [operator*](#26e7f05e) () const  |
|  T * | [operator->](#9ba6472f) ()  |
|  const T * | [operator->](#6e758bbe) () const  |


## Public Attributes Documentation

### _variable_ <a id="26afb438" href="#26afb438">ptr</a>

```cpp
std::unique_ptr< T > ptr
```





## Public Functions Documentation

### _function_ <a id="93a69493" href="#93a69493">SwapWrapper</a>

```cpp
inline  SwapWrapper (
    Args &&... args
) 
```



### _function_ <a id="9de214be" href="#9de214be">SwapWrapper</a>

```cpp
inline  SwapWrapper (
    SwapWrapper && other
) 
```



### _function_ <a id="bfc8a933" href="#bfc8a933">operator=</a>

```cpp
inline SwapWrapper & operator= (
    SwapWrapper && other
) 
```



### _function_ <a id="a9cdfd36" href="#a9cdfd36">swap</a>

```cpp
inline void swap (
    SwapWrapper< T > & other
) 
```



### _function_ <a id="4a1757f4" href="#4a1757f4">operator*</a>

```cpp
inline T & operator* () 
```



### _function_ <a id="26e7f05e" href="#26e7f05e">operator*</a>

```cpp
inline const T & operator* () const 
```



### _function_ <a id="9ba6472f" href="#9ba6472f">operator-></a>

```cpp
inline T * operator-> () 
```



### _function_ <a id="6e758bbe" href="#6e758bbe">operator-></a>

```cpp
inline const T * operator-> () const 
```





