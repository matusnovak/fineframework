---
search: false
---

# texturecubemap.h File Reference

**[Go to the documentation of this file.](texturecubemap_8h.md)**
Source: `include/ffw/graphics/texturecubemap.h`

    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_CUBEMAP
#define FFW_TEXTURE_CUBEMAP
#include "texture.h"

namespace ffw {
    class ImageBuffer;

    class FFW_API TextureCubemap: public Texture {
    public:
        TextureCubemap();
        TextureCubemap(const TextureCubemap& second) = delete;
        TextureCubemap(TextureCubemap&& second);
        ~TextureCubemap();
        bool create(GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels = NULL);
        bool resize(GLsizei width, GLsizei height);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLint side, const GLvoid* pixels);
        bool setPixels(GLint level, GLint side, const GLvoid* pixels = NULL);
        bool setFromBuffer(const ImageBuffer& buffer, GLint side, bool inverse = false);
        bool getPixels(void* pixels);
        TextureCubemap& operator = (const TextureCubemap& second) = delete;
        TextureCubemap& operator = (TextureCubemap&& second);
    };
};
#endif
```


    
  
