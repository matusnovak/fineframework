Value
===================================


**Implemented by:** [ffw::XmlReader::Attribute](ffw_XmlReader_Attribute.html), [ffw::XmlReader::Node](ffw_XmlReader_Node.html), 

The documentation for this class was generated from: `include/ffw/data/xmlreader.h`



## Public Functions

| Type | Name |
| -------: | :------- |
|  virtual std::string | [name](#26734a66) () const = 0  |
|  virtual bool | [isObject](#b62b9097) () const = 0  |
|  bool | [isEmpty](#955a5a59) () const  |
|  bool | [isString](#05622955) () const  |
|  bool | [isNumber](#174680c9) () const  |
|  bool | [isInteger](#ccfb3120) () const  |
|  bool | [isFloat](#31b732b6) () const  |
|  bool | [isBoolean](#b727156a) () const  |
|  bool | [isNull](#e25d5339) () const  |
|  std::string | [toString](#67029414) () const  |
|  int | [toInteger](#c35ebe41) () const  |
|  double | [toDouble](#e9218fec) () const  |
|  float | [toFloat](#006ddac7) () const  |
|  bool | [toBoolean](#29faca5d) () const  |
|  [Type](ffw_XmlReader.html#ed4bf013) | [getType](#21507cc3) () const  |
|  virtual const char * | [rawCstr](#a52ffb86) () const = 0  |


## Public Functions Documentation

### <span style="opacity:0.5;">function</span> <a id="26734a66" href="#26734a66">name</a>

```cpp
virtual std::string name () const = 0 
```



### <span style="opacity:0.5;">function</span> <a id="b62b9097" href="#b62b9097">isObject</a>

```cpp
virtual bool isObject () const = 0 
```



### <span style="opacity:0.5;">function</span> <a id="955a5a59" href="#955a5a59">isEmpty</a>

```cpp
bool isEmpty () const 
```



### <span style="opacity:0.5;">function</span> <a id="05622955" href="#05622955">isString</a>

```cpp
bool isString () const 
```



### <span style="opacity:0.5;">function</span> <a id="174680c9" href="#174680c9">isNumber</a>

```cpp
bool isNumber () const 
```



### <span style="opacity:0.5;">function</span> <a id="ccfb3120" href="#ccfb3120">isInteger</a>

```cpp
bool isInteger () const 
```



### <span style="opacity:0.5;">function</span> <a id="31b732b6" href="#31b732b6">isFloat</a>

```cpp
bool isFloat () const 
```



### <span style="opacity:0.5;">function</span> <a id="b727156a" href="#b727156a">isBoolean</a>

```cpp
bool isBoolean () const 
```



### <span style="opacity:0.5;">function</span> <a id="e25d5339" href="#e25d5339">isNull</a>

```cpp
bool isNull () const 
```



### <span style="opacity:0.5;">function</span> <a id="67029414" href="#67029414">toString</a>

```cpp
std::string toString () const 
```



### <span style="opacity:0.5;">function</span> <a id="c35ebe41" href="#c35ebe41">toInteger</a>

```cpp
int toInteger () const 
```



### <span style="opacity:0.5;">function</span> <a id="e9218fec" href="#e9218fec">toDouble</a>

```cpp
double toDouble () const 
```



### <span style="opacity:0.5;">function</span> <a id="006ddac7" href="#006ddac7">toFloat</a>

```cpp
float toFloat () const 
```



### <span style="opacity:0.5;">function</span> <a id="29faca5d" href="#29faca5d">toBoolean</a>

```cpp
bool toBoolean () const 
```



### <span style="opacity:0.5;">function</span> <a id="21507cc3" href="#21507cc3">getType</a>

```cpp
Type getType () const 
```



### <span style="opacity:0.5;">function</span> <a id="a52ffb86" href="#a52ffb86">rawCstr</a>

```cpp
virtual const char * rawCstr () const = 0 
```





