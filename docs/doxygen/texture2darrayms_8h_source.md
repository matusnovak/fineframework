---
search: false
---

# texture2darrayms.h File Reference

**[Go to the documentation of this file.](texture2darrayms_8h.md)**
Source: `include/ffw/graphics/texture2darrayms.h`

    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY_MS
#define FFW_TEXTURE_2D_ARRAY_MS

#include "texture.h"

namespace ffw {
    class FFW_API Texture2DArrayMS: public Texture {
    public:
        Texture2DArrayMS();
        Texture2DArrayMS(const Texture2DArrayMS& other) = delete;
        Texture2DArrayMS(Texture2DArrayMS&& other) NOEXCEPT;
        virtual ~Texture2DArrayMS() = default;
        bool create(GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat,
            GLint samples);
        bool resize(GLsizei width, GLsizei height, GLsizei layers, GLint samples);
        Texture2DArrayMS& operator = (const Texture2DArrayMS& other) = delete;
        Texture2DArrayMS& operator = (Texture2DArrayMS&& other) NOEXCEPT;
    };
};

inline void swap(ffw::Texture2DArrayMS& first, ffw::Texture2DArrayMS& second) NOEXCEPT {
    first.swap(second);
}
#endif

```


    
  
