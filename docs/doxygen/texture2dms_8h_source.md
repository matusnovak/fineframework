---
search: false
---

# texture2dms.h File Reference

**[Go to the documentation of this file.](texture2dms_8h.md)**
Source: `include/ffw/graphics/texture2dms.h`

    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_MS
#define FFW_TEXTURE_2D_MS
#include "texture.h"

namespace ffw {
    class FFW_API Texture2DMS: public Texture {
    public:
        Texture2DMS();
        Texture2DMS(const Texture2DMS& second) = delete;
        Texture2DMS(Texture2DMS&& second);
        ~Texture2DMS();
        bool create(GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat, GLint samples);
        bool resize(GLsizei width, GLsizei height, GLint samples);
        Texture2DMS& operator = (const Texture2DMS& second) = delete;
        Texture2DMS& operator = (Texture2DMS&& second);
    };
};
#endif
```


    
  
