GuiTheme
===================================


The documentation for this class was generated from: `include/ffw/gui/guitheme.h`



## Public Static Attributes

| Type | Name |
| -------: | :------- |
|  const [GuiTheme](ffw_GuiTheme.html) | [windows](#7188908e) |
|  const [GuiTheme](ffw_GuiTheme.html) | [simpleLight](#fdd54264) |
|  const [GuiTheme](ffw_GuiTheme.html) | [simpleDark](#cece5f74) |
|  const [GuiTheme](ffw_GuiTheme.html) | [modernFlat](#db1b9bcd) |


## Public Functions

| Type | Name |
| -------: | :------- |
|   | [GuiTheme](#533e2f20) (const std::initializer_list< std::pair< std::string, [GuiStyleGroup](ffw_GuiStyleGroup.html) >> & _list_)  |
|  virtual  | [~GuiTheme](#071aecaf) ()  |
|  void | [add](#d8afc5f0) (const std::pair< std::string, [GuiStyleGroup](ffw_GuiStyleGroup.html) > & _sty_)  |
|  const [GuiStyleGroup](ffw_GuiStyleGroup.html) & | [getStyleGroup](#0cc7626e) (const std::string & _type_) const  |
|  [GuiStyleGroup](ffw_GuiStyleGroup.html) & | [getStyleGroup](#7692f56e) (const std::string & _type_)  |


## Public Static Attributes Documentation

### _variable_ <a id="7188908e" href="#7188908e">windows</a>

```cpp
static const GuiTheme windows
```



### _variable_ <a id="fdd54264" href="#fdd54264">simpleLight</a>

```cpp
static const GuiTheme simpleLight
```



### _variable_ <a id="cece5f74" href="#cece5f74">simpleDark</a>

```cpp
static const GuiTheme simpleDark
```



### _variable_ <a id="db1b9bcd" href="#db1b9bcd">modernFlat</a>

```cpp
static const GuiTheme modernFlat
```





## Public Functions Documentation

### _function_ <a id="533e2f20" href="#533e2f20">GuiTheme</a>

```cpp
 GuiTheme (
    const std::initializer_list< std::pair< std::string, GuiStyleGroup >> & list
) 
```



### _function_ <a id="071aecaf" href="#071aecaf">~GuiTheme</a>

```cpp
virtual  ~GuiTheme () 
```



### _function_ <a id="d8afc5f0" href="#d8afc5f0">add</a>

```cpp
void add (
    const std::pair< std::string, GuiStyleGroup > & sty
) 
```



### _function_ <a id="0cc7626e" href="#0cc7626e">getStyleGroup</a>

```cpp
const GuiStyleGroup & getStyleGroup (
    const std::string & type
) const 
```



### _function_ <a id="7692f56e" href="#7692f56e">getStyleGroup</a>

```cpp
GuiStyleGroup & getStyleGroup (
    const std::string & type
) 
```





