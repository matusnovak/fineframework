---
search: false
---

# xmlexception.h File Reference

**[Go to the documentation of this file.](xmlexception_8h.md)**
Source: `include/ffw/data/xmlexception.h`

    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#pragma once
#ifndef FFW_XML_EXCEPTION
#define FFW_XML_EXCEPTION
#include "../config.h"
#include <stdexcept>

namespace ffw {
    class XmlException : public std::runtime_error {
    public:
        inline XmlException(const std::string& msg) :std::runtime_error(msg) {

        }
    };
    class XmlDecodeException : public XmlException {
    public:
        inline XmlDecodeException(const std::string& msg) :XmlException(msg) {

        }
    };
    class XmlEncodeException : public XmlException {
    public:
        inline XmlEncodeException(const std::string& msg) :XmlException(msg) {

        }
    };
};

#endif
```


    
  
