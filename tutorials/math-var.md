# Var - JSON-like data structure

This tutorial will explain how the ffw::Var class can accept and hold any data type, including creating JSON like data structures via key value pairs and arrays.

## Basics

Before we start, make sure to add this to your project:

```cpp
#include <iostream>
#include <ffw/math.h>
```

A ffw::Var can be initialized as any other variable and can be re-assigned into a different data type at runtime. There is not limit on what it can hold.

```cpp
ffw::Var a;
a = 123; 
// Now holds an integer

std::cout << "Value of var: " << a.getAs<int>() << std::endl;
// prints: "Value of var: 123"

a = -0.0042f;
// Now holds a float

std::cout << "Value of var: " << a.getAs<float>() << std::endl;
// Prints: "Value of var: -0.0042"
```

At any time, you check which data type it holds.

```cpp
ffw::Var a = -0.0042f;

if(a.empty()){
  std::cout << "a holds nothing!" << std::endl;
}
else if(a.is<int>()){
  std::cout << "a holds an integer!" << std::endl;
}
else if(a.is<float>()){
  std::cout << "a holds a float!" << std::endl;
}
else if(a.is<char>()){
  std::cout << "a holds a char!" << std::endl;
}
// Prints: "a holds a float!"
```

The ffw::Var holds exactly the data type you put into it. This might raise some issues such as handling unsigned and signed integers

```cpp
ffw::Var a = (int)123;

if(a.is<int>()){
  std::cout << "a holds an signed integer!" << std::endl;
} 
else if(a.is<unsigned int>()){
  std::cout << "a holds an unsigned integer!" << std::endl;
}
// Prints: "a holds an signed integer!"

a = (unsigned int)123;

if(a.is<int>()){
  std::cout << "a holds an signed integer!" << std::endl;
} 
else if(a.is<unsigned int>()){
  std::cout << "a holds an unsigned integer!" << std::endl;
}
// Prints: "a holds an unsigned integer!"
```

You can also modify the stored value. The ffw::Var::getAs method will return a reference to the stored value.

```cpp
ffw::Var a = -0.0042f;

a.getAs<float>() = 100.0f;

std::cout << "Value of var: " << a.getAs<float>() << std::endl;
// Prints: "Value of var: 100"
```

Note that storing a reference might be usefull, but after you re-assign a new value, the reference will be invalid! Imagine it as a pointer, you set a pointer to `float& ref = a.getAs<float>();` and when you create a new value `a = 200.0f` the address will change!

```cpp
ffw::Var a = -0.0042f;

float& ref = a.getAs<float>();
ref = 100.0f;

std::cout << "Value of var: " << a.getAs<float>() << std::endl;
// Prints: "Value of var: 100"

a = 200.0f;
// New float assigned to a, the old one is gone forever!

ref = 100.0f;
// Will result in undefined behaviour!
// Prefer to access the value via a.getAs<float>()
```

Trying to get a different data type than is stored inside of ffw::Var will throw you an std::bad_cast

```cpp
ffw::Var a = -0.0042f;

std::cout << "Value of var: " << a.getAs<float>() << std::endl;
// OK Prints: "Value of var: 100"

std::cout << "Value of var: " << a.getAs<int>() << std::endl;
// ERROR: std::bad_cast
```

The ffw::Var::getAs has to know the explicit type you are trying to retrieve!

## With great power comes great responsibility

The ffw::Var can tell you what data it holds via ffw::Var::getTypeid method. This can only tell you what is inside but it will never ever give you the true data. It simply can not, this is limited by the C++ language. 

You have to know what are you storing and you have to know exactly what are you looking for when trying to retrieve the value behind ffw::Var

## The problem with strings

Because ffw::Var stores explicit type (if you store double, it's double, not float... if you store int, it's not unsigned int, nor long, it's just an int...) there is an issue with C style strings (const char*), string arrays (const char[N]), and C++ std::strings.

For example:

```cpp
ffw::Var a = "Hello World!";

if(a.is<std::string>()){
  std::cout << "a holds std::string!" << std::endl;
}
else if(a.is<const char*>()){
  std::cout << "a holds const char*!" << std::endl;
}
// Prints: "a holds const char*!"
```

A simple workaround is to always store value as std::string

```cpp
ffw::Var a = std::string("Hello World!");

if(a.is<std::string>()){
  std::cout << "a holds std::string!" << std::endl;
}
else if(a.is<const char*>()){
  std::cout << "a holds const char*!" << std::endl;
}
// Prints: "a holds std::string!"
```

If you are using both std::string and const char* then you might would like to use ffw::Var::isString and ffw::Var::toString methods. Note that the toString method will always return a copy of the original string. **If the ffw::Var does not hold any kind of string, it will return an empty string.**

```cpp
ffw::Var a = "Hello World!";
ffw::Var b = std::string("Hello World!");

// Always true, even though they are different data types
if(a.isString() && b.isString()){
  std::cout << "a and b are strings!" << std::endl;
  std::cout << "a: " << a.toString() << " b: " << b.toString() << std::endl;
}

// Prints: "a: Hello World! b: Hello World!"
```

## The problem with inetegers, floats, booleans

As mentioned above, storing an signed integer and then asking for unsigned integer will throw a std::bad_cast exception. 

```cpp
ffw::Var a = (unsigned int)123;

std::cout << "a: " << a.getAs<int>() << std::endl; // Error! std::bad_cast
std::cout << "a: " << a.getAs<unsigned int>() << std::endl; // OK!
```

The ffw::Var offers the following methods, similarly to ffw::Var::toString as explained above. All of the following methods do not throw an exception. For example, if the stored data type is std::string and you will call ffw::Var::toInt it will return an integer of value of zero. This applies to toBool (will return false) and toFloat (will return 0.0f).

* ffw::Var::toInt and ffw::Var::isInt for all integer data types (int, short, unsigned long, uint32_t, etc...)
* ffw::Var::toFloat and ffw::Var::isFloat for all floating point data types (float, double, etc...)
* ffw::Var::toBool and ffw::Var::isBool for booleans, will also work if any integer is stored

## Key value mapping

If you heard about JSON, you will know what is this about. The ffw::Object is a fancy std::unordered_map structure that contains keys as std::string and values as ffw::Var. With this, we can create a JSON-like object:

```cpp
ffw::Object obj;

// Insert into object
obj.insert(std::make_pair("value", 123));

// This works as well
// The operator [] will insert a new key pair if the key does not exist
obj["boolean"] = true;

obj.has_key("boolean"); // Returns true
```

You can then use the mapped values as any other ffw::Var 

```cpp
if(obj["value"].isInt()){
  std::cout << "value: " << obj["value"].toInt() << std::endl;
  // obj["value"].getAs<int>() also works
}
if(obj["boolean"].isBool()){
  std::cout << "boolean: " << obj["value"].toBool() << std::endl;
  // obj["value"].getAs<bool>() also works
}
// Prints: "value: 123"
//         "boolean: 1"
```

The ffw::Object offers a braced list constructor which simplifies things even further:

```cpp
ffw::Object obj = {
  {"integer", 123},
  {"float", 456.7f},
  {"double", 456.7},
  {"boolean", true},
  {"object", ffw::Object 
    {
      {"first", 10},
      {"second", 20}
    }
  }
};

// Access object -> first -> int
std::cout << "object/first: " << obj["object"]["first"].toInt() << std::endl;
// Prints "object/first: 10"

std::cout << "object/invalid: " << obj["object"]["invalid"].toInt() << std::endl;
// Prints "object/first: 0"
// Why zero ? Because operator [] creates a new empty value, so the following:
std::cout << "object/new: " << obj["object"]["new"].empty() << std::endl;
// Prints "object/new: 1"
```

Note that [operator[] will insert a new value if the key does not exist](http://en.cppreference.com/w/cpp/container/unordered_map/operator_at) If you wish the program to throw an exception if the key does not exist, you might want to use ffw::Object::at For example: `obj.at("invalid-key").isBool()` will throw [std::out_of_range](http://en.cppreference.com/w/cpp/error/out_of_range)

Also, when having an object inside of an object, you might think of doing this:

```cpp
// Access object -> first -> int
std::cout << "object/first: " << 
  obj["object"].getAs<ffw::Object>()["first"].toInt()
  << std::endl;
// Prints "object/first: 10"
```

So how come the previous section does not have `getAs` and it still works? The ffw::Var offers two [] operators. If you supply std::string, it will assume that you are treating it as ffw::Object, if you supply an integer, it will assume you are treating it as ffw::Array

```cpp
ffw::Var a = 123;
a["something"] = 456; // std::bad_cast the a is not an object

a = ffw::Object();

// Both are exactly same:
a["something"] = 456; // OK new value inserted
a.getAs<ffw::Object>()["something"] = 456; // Also OK value modyfied

a[0] = 456; // std::bad_cast the a is not an Array

a = ffw::Array();
a[0] = 456; // Segmentation fault, array is empty!
a.push_back(123);
a[0] = 456; // OK!
a.getAs<ffw::Array>()[0] = 456; // OK!
```

## Arrays

Alongside ffw::Object we have ffw::Array which is fancy std::vector that holds ffw::Var. It works exactly such as a normal std::vector

```cpp
ffw::Array a;
a.push_back(123); // int
a.push_back(456.7f); // float
a.push_back(456.7); // double
a.push_back(ffw::Array{10, 20, 30}); // array of 3 ints
a.push_back(true); // bool

std::cout << "int: " << a[0].toInt() << std::endl;
std::cout << "float: " << a[1].toFloat() << std::endl;
std::cout << "double: " << a[2].getAs<double>() << std::endl;
std::cout << "array: " << 
  a[3][0].toInt() << ", " << 
  a[3][1].toInt() << ", " <<
  a[3][2].toInt() << std::endl;
std::cout << "bool: " << a[4].toBool() << std::endl;
// Prints: "int: 123"
//         "float: 456.7"
//         "double: 456.7"
//         "array: 10, 20, 30"
//         "bool: 1"
```

## Putting it all together

With both arrays and objects, you can create some fancy looking data structures:

```cpp
ffw::Object example1 = { 
	"menu", ffw::Object{
		{"id", "file",},
		{"value", "File",},
		{"popup", ffw::Object{
			{"menuitem", ffw::Array{
				ffw::Object{ {"value", "New"}, {"onclick", "CreateNewDoc()"} },
				ffw::Object{ {"value", "Open"}, {"onclick", "OpenDoc()"} },
				ffw::Object{ {"value", "Close"}, {"onclick", "CloseDoc()"} }
      }
      },
    }
    },
	} 
};
```

Which is equivalent to the following JSON:

```javascript
{
  "menu": {
    "id": "file",
    "value": "File",
    "popup": {
      "menuitem": [
        {"value": "New", "onclick": "CreateNewDoc()"},
        {"value": "Open", "onclick": "OpenDoc()"},
        {"value": "Close", "onclick": "CloseDoc()"}
      ]
    }
  }
}
```

## What about JSON or XML?

Yes, you can use ffw::Var ffw::Object and ffw::Array to encode (serialize) or decode (deserialize) JSON and XML. See **[Encode and decode JSON](data-json-simple.html)** and **[Encode and decode XML](data-xml-simple.html)** tutorials.