Node
===================================


**Inherits from:** [ffw::XmlReader::Value](ffw_XmlReader_Value.html)

The documentation for this class was generated from: `include/ffw/data/xmlreader.h`



## Public Attributes

| Type | Name |
| -------: | :------- |
|  const tinyxml2::XMLElement * | [elem](#20181d85) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [Node](#2ddac916) ()  |
|   | [Node](#9ec24f59) (const tinyxml2::XMLElement * _node_)  |
|  bool | [getNextAttribute](#209ff6f2) ([Attribute](ffw_XmlReader_Attribute.html) * _node_)  |
|  virtual std::string | [name](#caf37a16) () const  |
|  virtual bool | [isObject](#646813f4) () const  |
|  bool | [hasAttributes](#329452d5) () const  |
|  virtual const char * | [rawCstr](#ab26d14f) () const  |


## Public Attributes Documentation

### _variable_ <a id="20181d85" href="#20181d85">elem</a>

```cpp
const tinyxml2::XMLElement * elem
```





## Public Functions Documentation

### _function_ <a id="2ddac916" href="#2ddac916">Node</a>

```cpp
inline  Node () 
```



### _function_ <a id="9ec24f59" href="#9ec24f59">Node</a>

```cpp
inline  Node (
    const tinyxml2::XMLElement * node
) 
```



### _function_ <a id="209ff6f2" href="#209ff6f2">getNextAttribute</a>

```cpp
bool getNextAttribute (
    Attribute * node
) 
```



### _function_ <a id="caf37a16" href="#caf37a16">name</a>

```cpp
virtual std::string name () const 
```



**Overrides:** [name](/doxygen/ffw_XmlReader_Value.md#26734a66) from class [Value](/doxygen/ffw_XmlReader_Value.md)

### _function_ <a id="646813f4" href="#646813f4">isObject</a>

```cpp
virtual bool isObject () const 
```



**Overrides:** [isObject](/doxygen/ffw_XmlReader_Value.md#b62b9097) from class [Value](/doxygen/ffw_XmlReader_Value.md)

### _function_ <a id="329452d5" href="#329452d5">hasAttributes</a>

```cpp
bool hasAttributes () const 
```



### _function_ <a id="ab26d14f" href="#ab26d14f">rawCstr</a>

```cpp
virtual const char * rawCstr () const 
```



**Overrides:** [rawCstr](/doxygen/ffw_XmlReader_Value.md#a52ffb86) from class [Value](/doxygen/ffw_XmlReader_Value.md)



