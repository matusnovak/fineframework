---
search: false
---

# bufferobject.h File Reference

**[Go to the documentation of this file.](bufferobject_8h.md)**
Source: `include/ffw/graphics/bufferobject.h`

    
    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_BUFFER_OBJECT
#define FFW_BUFFER_OBJECT

#include <vector>
#include "renderextensionsgl.h"

namespace ffw {
    class RenderContext;
    class FFW_API BufferObject {
    public:
        BufferObject(GLenum objecttype);
        BufferObject(const BufferObject& other) = delete;
        BufferObject(BufferObject&& other) NOEXCEPT;
        void swap(BufferObject& other) NOEXCEPT;

        virtual ~BufferObject();
        inline bool isCreated() const {
            return loaded;
        }
        bool create(const GLvoid* data, GLsizei size, GLenum type);
        bool resize(const GLvoid* data, GLsizei size);
        bool setData(const GLvoid* data, GLsizei offset, GLsizei size);
        bool mapBuffer(GLvoid** pointer, GLenum access) const;
        bool mapBufferRange(GLvoid** pointer, GLsizei offset, GLsizei size, GLenum access) const;
        bool flushMappedBufferRange(GLsizei offset, GLsizei size) const;
        bool unMapBuffer() const;
        void destroy();
        void bind() const;
        void unbind() const;
        inline GLuint getHandle() const {
            return buffer;
        }
        inline GLsizei getSize() const {
            return size;
        }
        inline GLenum getType() const {
            return type;
        }
        inline GLenum getObjectType() const {
            return objecttype;
        }
        bool copyFrom(const BufferObject* other, GLintptr readoffset,
            GLintptr writeoffset, GLsizeiptr size);
        bool getData(GLvoid* data, GLsizei offset, GLsizei size);
        std::vector<uint8_t> getData(GLsizei offset, GLsizei size);
        BufferObject& operator = (const BufferObject& other) = delete;
        BufferObject& operator = (BufferObject&& other) NOEXCEPT;
    protected:
        GLenum type;
        GLenum objecttype;
        bool loaded;
        GLuint buffer;
        GLsizei size;
    };
    class FFW_API Vbo: public BufferObject {
    public:
        Vbo():BufferObject(GL_ARRAY_BUFFER) {
            
        }
    };
    class FFW_API Ibo: public BufferObject {
    public:
        Ibo():BufferObject(GL_ELEMENT_ARRAY_BUFFER) {
            
        }
    };
};

inline void swap(ffw::BufferObject& first, ffw::BufferObject& second) NOEXCEPT {
    first.swap(second);
}
inline void swap(ffw::Vbo& first, ffw::Vbo& second) NOEXCEPT {
    first.swap(second);
}
inline void swap(ffw::Ibo& first, ffw::Ibo& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
