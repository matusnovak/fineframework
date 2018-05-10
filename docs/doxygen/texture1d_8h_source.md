---
search: false
---

# texture1d.h File Reference

**[Go to the documentation of this file.](texture1d_8h.md)**
Source: `include/ffw/graphics/texture1d.h`

    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_1D
#define FFW_TEXTURE_1D

#include "texture.h"

namespace ffw {
    class ImageBuffer;

    class FFW_API Texture1D: public Texture {
    public:
        Texture1D();
        Texture1D(const Texture1D& other) = delete;
        Texture1D(Texture1D&& other) NOEXCEPT;
        virtual ~Texture1D() = default;
        bool create(GLsizei width, GLenum internalformat, GLenum format, GLenum pixelformat, 
            const GLvoid* pixels = nullptr);
        bool resize(GLsizei width, const GLvoid* pixels = nullptr);
        bool createFromBuffer(const ImageBuffer& image);
        bool setPixels(GLint level, const GLvoid* pixels);
        bool setPixels(GLint level, GLint xoffset, GLsizei width, const GLvoid* pixels);
        bool getPixels(void* pixels) const;
        Texture1D& operator = (const Texture1D& other) = delete;
        Texture1D& operator = (Texture1D&& other) NOEXCEPT;
    };
};

inline void swap(ffw::Texture1D& first, ffw::Texture1D& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
