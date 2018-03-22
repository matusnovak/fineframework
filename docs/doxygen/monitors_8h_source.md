---
search: false
---

# monitors.h File Reference

**[Go to the documentation of this file.](monitors_8h.md)**
Source: `include/ffw/graphics/monitors.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GL_MONITORS
#define FFW_GL_MONITORS
#include "../config.h"
#include "../math/vec3.h"
#include <string>
#include <vector>

namespace ffw{
    struct Monitor {
        struct Mode {
            Vec2i resolution;
            Vec3i bitDepth;
            int refreshRate;
        };
        std::string name;
        Vec2i resolution;
        Vec3i bitDepth;
        int refreshRate;
        Vec2i position;
        Vec2i physicalSize;
        void* ptr = NULL;
    };
};
#endif
```


    
  
