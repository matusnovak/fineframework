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
        TextureCubemap(const TextureCubemap& other) = delete;
        TextureCubemap(TextureCubemap&& other) NOEXCEPT;
        virtual ~TextureCubemap() = default;
        bool create(GLsizei width, GLsizei height, GLenum internalformat, GLenum format, 
            GLenum pixelformat, const GLvoid* pixels = nullptr);
        bool resize(GLsizei width, GLsizei height);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, 
            GLsizei height, GLint side, const GLvoid* pixels);
        bool setPixels(GLint level, GLint side, const GLvoid* pixels);
        bool setFromBuffer(const ImageBuffer& image, GLint side, bool inverse = false);
        bool getPixels(GLvoid* pixels);
        TextureCubemap& operator = (const TextureCubemap& other) = delete;
        TextureCubemap& operator = (TextureCubemap&& other) NOEXCEPT;
    private:
        void setPixelsInternal(GLint level, GLint xoffset, GLint yoffset, 
            GLsizei width, GLsizei height, GLint side, const GLvoid* pixels);
        void setPixelsInternal(GLint level, GLint side, const GLvoid* pixels);
    };
};

inline void swap(ffw::TextureCubemap& first, ffw::TextureCubemap& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
