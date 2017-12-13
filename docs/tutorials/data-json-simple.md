# Encode and decode JSON

This tutorial will explain how to decode and encode JSON structure. 

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](math-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

## Decoding

When decoding a JSON, values are converted into C++ specific data types:

| JSON value  | C++ data type              |
| ----------- | -------------------------- |
| { }         | ffw::Object                |
| [ ]         | ffw::Array                 |
| "string"    | ffw::Var as std::string    |
| 123456      | ffw::Var as int            |
| 123.456e-10 | ffw::Var as float          |
| true false  | ffw::Var as bool           |
| null        | empty ffw::Var             |

The strings that contain unicode characters encoded as '\\uXXXX' will be converted into UTF-8 

Decoding can be done as the following:

[import:'example0'](../../examples/data/json_simple.cpp)

Please note:
* If the decoding fails, an ffw::JsonDecodeException is thrown
* The [] operator with std::string assumes that you are trying to get ffw::Object
* The [] operator with int assumes that you are trying to get ffw::Array

## Encoding

The following code is a simple way to create a data structure using ffw::Var and encoding it as JSON. Note that an exception can be thrown if:

* the root node of the data structure is not object or array
* any of the values contain invalid data type, only the following are valid: (ffw::Object, ffw::Array, any signed or unsigned integer, bool, std::string or const char*, any floating point). For example, you can not encode a C++ reference, or pointer, or class, etc...

[import:'example1'](../../examples/data/json_simple.cpp)

Will create the following equivalent JSON structure:

```json
{
    "menu":{
        "id":"file",
        "value":"File",
        "popup":{
            "menuitem":[
                {
                    "value":"New",
                    "onclick":"CreateNewDoc()"
                },
                {
                    "value":"Open",
                    "onclick":"OpenDoc()"
                },
                {
                    "value":"Close",
                    "onclick":"CloseDoc()"
                }
            ]
        }
    }
}
```

Please note:

* Characters such as new-line, quote, apostrophe, cariage-return will be escaped into '\\n', '\\"', '\\'', '\\r' and so on.
