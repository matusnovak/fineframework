---
search: false
---

# texture2d.h File Reference

**[Go to the documentation of this file.](texture2d_8h.md)**
Source: `include/ffw/graphics/texture2d.h`

    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D
#define FFW_TEXTURE_2D

#include "texture.h"

namespace ffw {
    class ImageBuffer;

    class FFW_API Texture2D: public Texture {
    public:
        Texture2D();
        Texture2D(const Texture2D& other) = delete;
        Texture2D(Texture2D&& other) NOEXCEPT;
        virtual ~Texture2D() = default;
        bool create(GLsizei width, GLsizei height, GLenum internalformat, GLenum format, 
            GLenum pixelformat, const GLvoid* pixels = nullptr);
        bool setPixels(GLint level, const GLvoid* pixels);
        bool createFromBuffer(const ImageBuffer& image, bool inverse = false);
        bool resize(GLsizei width, GLsizei height, const GLvoid* pixels = nullptr);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, 
            GLsizei height, const GLvoid* pixels);
        bool getPixels(void* pixels) const;
        Texture2D& operator = (const Texture2D& other) = delete;
        Texture2D& operator = (Texture2D&& other) NOEXCEPT;
    private:
        void setPixelsInternal(GLint level, const GLvoid* pixels = nullptr);
        void setPixelsInternal(GLint level, GLint xoffset, GLint yoffset, GLsizei width,
            GLsizei height, const GLvoid* pixels);
    };
};

inline void swap(ffw::Texture2D& first, ffw::Texture2D& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
