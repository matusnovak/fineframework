---
search: false
---

# renderbuffer.h File Reference

**[Go to the documentation of this file.](renderbuffer_8h.md)**
Source: `include/ffw/graphics/renderbuffer.h`

    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_RENDERBUFFER
#define FFW_RENDERBUFFER

#include "renderextensionsgl.h"

namespace ffw {
    class FFW_API Renderbuffer {
    public:
        Renderbuffer();
        Renderbuffer(const Renderbuffer& other) = delete;
        Renderbuffer(Renderbuffer&& other) NOEXCEPT;
        void swap(Renderbuffer& other) NOEXCEPT;
        virtual ~Renderbuffer();
        inline bool isCreated() const {
            return loaded;
        }
        void destroy();
        void bind() const;
        void unbind() const;
        inline GLuint getHandle() const {
            return buffer;
        }
        inline GLsizei getWidth() const {
            return width;
        }
        inline GLsizei getHeight() const {
            return height;
        }
        inline GLenum getInternalFormat() const {
            return internalformat;
        }
        inline GLsizei getSamples() const {
            return samples;
        }

        Renderbuffer& operator = (const Renderbuffer& other) = delete;
        Renderbuffer& operator = (Renderbuffer&& other) NOEXCEPT;
    protected:
        bool loaded;
        GLenum internalformat;
        GLuint buffer;
        GLsizei width;
        GLsizei height;
        GLsizei samples;
    };
};

inline void swap(ffw::Renderbuffer& first, ffw::Renderbuffer& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
