/* This file is part of FineFramework project */
#ifndef FFW_BUFFER_OBJECT
#define FFW_BUFFER_OBJECT
#include "../config.h"
#include "renderextensionsgl.h"
namespace ffw {
    class RenderContext;
    /**
     * @ingroup graphics
     */
    class FFW_API BufferObject {
    public:
        BufferObject(unsigned int objecttype);
        BufferObject(const BufferObject& other) = delete;
        BufferObject(BufferObject&& other);
        void swap(BufferObject& other);

        virtual ~BufferObject();
        inline bool isCreated() const {
            return loaded_;
        }
        bool create(const void* data, GLsizei size, GLenum type);
        bool resize(const void* data, GLsizei size);
        bool setData(const void* data, GLsizei offset, GLsizei size);
        bool mapBuffer(void** pointer, GLenum access) const;
        bool unMapBuffer() const;
        void destroy();
        void bind() const;
        void unbind() const;
        inline unsigned int getHandle() const {
            return buffer_;
        }
        inline int getSize() const {
            return size_;
        }
        inline unsigned int getType() const {
            return type_;
        }
        inline unsigned int getObjectType() const {
            return objecttype_;
        }
        bool copyFrom(const BufferObject* other, GLintptr readoffset, GLintptr writeoffset, GLsizeiptr size);
        bool copyFromEnabled() const;
        bool getData(void* data, GLsizei offset, GLsizei size);
        BufferObject& operator = (const BufferObject& other) = delete;
        BufferObject& operator = (BufferObject&& other);
    protected:
        unsigned int type_;
        unsigned int objecttype_;
        bool loaded_;
        unsigned int buffer_;
        int size_;
    };
    /**
     * @ingroup graphics
     */
    class FFW_API Vbo: public BufferObject {
    public:
        Vbo():BufferObject(GL_ARRAY_BUFFER){}
    };
    /**
     * @ingroup graphics
     */
    class FFW_API Ibo: public BufferObject {
    public:
        Ibo():BufferObject(GL_ELEMENT_ARRAY_BUFFER){}
    };
};

inline void swap(ffw::BufferObject& first, ffw::BufferObject& second) {
    first.swap(second);
}
inline void swap(ffw::Vbo& first, ffw::Vbo& second) {
    first.swap(second);
}
inline void swap(ffw::Ibo& first, ffw::Ibo& second) {
    first.swap(second);
}
#endif
