---
search: false
---

# texture1darray.h File Reference

**[Go to the documentation of this file.](texture1darray_8h.md)**
Source: `include/ffw/graphics/texture1darray.h`

    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_1D_ARRAY
#define FFW_TEXTURE_1D_ARRAY

#include "texture.h"

namespace ffw {
    class FFW_API Texture1DArray: public Texture {
    public:
        Texture1DArray();
        Texture1DArray(const Texture1DArray& other) = delete;
        Texture1DArray(Texture1DArray&& other) NOEXCEPT;
        virtual ~Texture1DArray() = default;
        bool create(GLsizei width, GLsizei layers, GLenum internalformat, GLenum format, 
            GLenum pixelformat, const GLvoid* pixels = nullptr);
        bool resize(GLsizei width, GLsizei layers, const GLvoid* pixels = nullptr);
        bool setPixels(GLint level, GLint xoffset, GLint loffset, 
            GLsizei width, const GLvoid* pixels);
        bool setPixels(GLint level, const GLvoid* pixels);
        bool getPixels(GLvoid* pixels) const;
        Texture1DArray& operator = (const Texture1DArray& other) = delete;
        Texture1DArray& operator = (Texture1DArray&& other) NOEXCEPT;
    };
};

inline void swap(ffw::Texture1DArray& first, ffw::Texture1DArray& second) NOEXCEPT {
    first.swap(second);
}
#endif

```


    
  
