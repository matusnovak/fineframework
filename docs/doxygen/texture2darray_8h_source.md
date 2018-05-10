---
search: false
---

# texture2darray.h File Reference

**[Go to the documentation of this file.](texture2darray_8h.md)**
Source: `include/ffw/graphics/texture2darray.h`

    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY
#define FFW_TEXTURE_2D_ARRAY

#include "texture.h"

namespace ffw {
    class ImageBuffer;

    class FFW_API Texture2DArray: public Texture {
    public:
        Texture2DArray();
        Texture2DArray(const Texture2DArray& other) = delete;
        Texture2DArray(Texture2DArray&& other) NOEXCEPT;
        virtual ~Texture2DArray() = default;
        bool create(GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, 
            GLenum format, GLenum pixelformat, const GLvoid* pixels = nullptr);
        bool resize(GLsizei width, GLsizei height, GLsizei layers, const GLvoid* pixels = nullptr);
        bool setFromBuffer(const ImageBuffer& image, GLint layer, bool inverse = false);
        bool setPixels(GLint level, const GLvoid* pixels);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, 
            GLsizei width, GLsizei height, const GLvoid* pixels);
        bool getPixels(GLvoid* pixels) const;
        Texture2DArray& operator = (const Texture2DArray& second) = delete;
        Texture2DArray& operator = (Texture2DArray&& second) NOEXCEPT;
    private:
        void setPixelsInternal(GLint level, const GLvoid* pixels = nullptr);
        void setPixelsInternal(GLint level, GLint xoffset, GLint yoffset, GLint loffset,
            GLsizei width, GLsizei height, const GLvoid* pixels);
    };
};

inline void swap(ffw::Texture2DArray& first, ffw::Texture2DArray& second) NOEXCEPT {
    first.swap(second);
}
#endif

```


    
  
