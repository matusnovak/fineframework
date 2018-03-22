---
search: false
---

# texture3d.h File Reference

**[Go to the documentation of this file.](texture3d_8h.md)**
Source: `include/ffw/graphics/texture3d.h`

    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_3D
#define FFW_TEXTURE_3D
#include "texture.h"

namespace ffw {
    class FFW_API Texture3D: public Texture {
    public:
        Texture3D();
        Texture3D(const Texture3D& second) = delete;
        Texture3D(Texture3D&& second);
        ~Texture3D();
        bool create(GLsizei width, GLsizei height, GLsizei depth, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels = NULL);
        bool resize(GLsizei width, GLsizei height, GLsizei depth);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const GLvoid* pixels);
        bool setPixels(GLint level, const GLvoid* pixels = NULL);
        bool getPixels(void* pixels);
        Texture3D& operator = (const Texture3D& second) = delete;
        Texture3D& operator = (Texture3D&& second);
    };
};
#endif
```


    
  
