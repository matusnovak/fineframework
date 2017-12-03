# Decode CSV - Simple

This tutorial will explain how to decode CSV structure. 

**The tutorial uses ffw::Var which is essential in the following examples. You must read [Var - JSON-like data structure](math-var.html) tutorial first!**

Make sure you add `finedata` into your linker and add the following headers into your project:

```cpp
#include <ffw/math.h>
#include <ffw/data.h>
```

[import:'example0'](../../examples/data/csv_simple.cpp)

Why the following two lines below are equal?

```cpp
std::cout << arr[2].getAs<ffw::Array>()[3].getAs<float>() << std::endl;
std::cout << arr[2][3].getAs<float>() << std::endl;
```

In the first line, `arr` is already ffw::Array. However, ffw::Array holds ffw::Var which can hold any c++ data type. We know that ffw::decodeCsv returns array of arrays, so it is safe to explicitly call `getAs<ffw::Array>()`. The `[3]` returns 4th element and `getAs<float>()` gives us a reference to the float.

The second line does exactly same thing. The ffw::Var contains two [ ] operators, one for integers, one for strings. If you call the operator with an integer, it will assume you are trying to get ffw::Array and it will call `getAs<ffw::Array>()` and `[int]` at the same time for you... it's just for simplicitly. If you would put a string inside the [ ] operator, it will call `getAs<ffw::Object>()` which throws std::bad_cast because in this example because we are dealing with arrays only, no objects.