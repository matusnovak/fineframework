---
search: false
---

# helpers.h File Reference

**[Go to the documentation of this file.](helpers_8h.md)**
Source: `include/ffw/data/helpers.h`

    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_DATA_HELPERS
#define FFW_DATA_HELPERS

#include "../config.h"

namespace ffw {
    bool FFW_API stringContainsWhitespace(std::string::const_iterator begin, std::string::const_iterator end);
    bool FFW_API stringisInteger(std::string::const_iterator begin, std::string::const_iterator end);
    bool FFW_API stringisFloat(std::string::const_iterator begin, std::string::const_iterator end);
    bool FFW_API stringisBool(std::string::const_iterator begin, std::string::const_iterator end);
};

#endif
```


    
  
