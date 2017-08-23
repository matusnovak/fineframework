Tutorial: String tokenizer
---------------------

This tutorial will explain how to use string tokenizer using ffw::Tokenizer class and ffw::getTokens function. The tokenizer is inside of [math module](group__math.html) which is a header only library. All you need to do is to add `#include <ffw/math.h>` into your project.

### Tokenizing string with one call

```cpp
// The second parameter is the delimiter, based on which the tokenizer
// will split the source string.
std::vector<std::string> tokens = ffw::getTokens("  Hello    World!  ", " ");

// Will return two tokens

// Do something with tokens
for(const auto& token : tokens){
  std::cout << token << std::endl;
}
// Prints:
// Hello
// World!
```

```cpp
// Also works with std::wstring!
// Will work with any std::basic_string 
std::vector<std::wstring> tokens = ffw::getTokens(L"xyzHelloxyzWorld!xyzxyz", L"xyz");

// Returns exactly two tokens

// Do something with tokens
for(const auto& token : tokens){
  std::wcout << token << std::endl;
}
// Prints:
// Hello
// World!
```

### Tokenizing with ffw::Tokenizer

```cpp
std::string source = "  Hello    World!  ";
std::string delim = " ";

// Create instance of ffw::Tokenizer.
// Note that std::string uses "char"!
ffw::Tokenizer<char> tokenizer(source, " ");

// Get all tokens
std::string str;
while(tokenizer.getNext(&str)){
  std::cout << str << std::endl;
}
// Prints:
// Hello
// World!
```

