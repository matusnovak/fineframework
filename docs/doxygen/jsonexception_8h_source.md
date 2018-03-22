---
search: false
---

# jsonexception.h File Reference

**[Go to the documentation of this file.](jsonexception_8h.md)**
Source: `include/ffw/data/jsonexception.h`

    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_JSON_EXCEPTION
#define FFW_JSON_EXCEPTION
#include "../config.h"
#include <stdexcept>

namespace ffw {
    class JsonException : public std::runtime_error {
    public:
        inline JsonException(const std::string& msg) :std::runtime_error(msg) {

        }
    };
    class JsonDecodeException : public JsonException {
    public:
        inline JsonDecodeException(const std::string& msg) :JsonException(msg) {

        }
    };
    class JsonEncodeException : public JsonException {
    public:
        inline JsonEncodeException(const std::string& msg) :JsonException(msg) {

        }
    };
};

#endif
```


    
  
