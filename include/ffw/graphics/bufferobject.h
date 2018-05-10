/* This file is part of FineFramework project */
#ifndef FFW_BUFFER_OBJECT
#define FFW_BUFFER_OBJECT

#include <vector>
#include "renderextensionsgl.h"

namespace ffw {
    class RenderContext;
    /**
     * @ingroup graphics
     */
    class FFW_API BufferObject {
    public:
        /**
         * @brief Creates an empty buffer object with specific target type
         * @details During the constructor execution, everything is set to defaults and no
         * actual data is allocated.
         * @param objecttype Allowed values are GL_ARRAY_BUFFER, GL_ATOMIC_COUNTER_BUFFER, 
         *                   GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, GL_DISPATCH_INDIRECT_BUFFER,
         *                   GL_DRAW_INDIRECT_BUFFER, GL_ELEMENT_ARRAY_BUFFER, GL_PIXEL_PACK_BUFFER,
         *                   GL_PIXEL_UNPACK_BUFFER, GL_QUERY_BUFFER, GL_SHADER_STORAGE_BUFFER,
         *                   GL_TEXTURE_BUFFER, GL_TRANSFORM_FEEDBACK_BUFFER, or
         *                   GL_UNIFORM_BUFFER
         */
        BufferObject(GLenum objecttype);
        BufferObject(const BufferObject& other) = delete;
        BufferObject(BufferObject&& other) NOEXCEPT;
        void swap(BufferObject& other) NOEXCEPT;

        virtual ~BufferObject();
        /**
         * @brief Returns true if the object has been allocated
         */
        inline bool isCreated() const {
            return loaded;
        }
        /**
         * @brief Allocates the buffer and copies the data
         * @param data Specifies a pointer to data that will be copied into the data store for
         *             initialization, or NULL if no data is to be copied.
         * @param size Specifies the size in bytes of the buffer object's new data store.
         * @param type Specifies the expected usage pattern of the data store. 
         *             The symbolic constant must be GL_STREAM_DRAW, GL_STREAM_READ, 
         *             GL_STREAM_COPY, GL_STATIC_DRAW, GL_STATIC_READ, GL_STATIC_COPY,
         *             GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.
         */
        bool create(const GLvoid* data, GLsizei size, GLenum type);
        /**
         * @brief Resizes the buffer and copies the data
         * @param data Specifies a pointer to data that will be copied into the data store for
         *             initialization, or NULL if no data is to be copied.
         * @param size Specifies the size in bytes of the buffer object's new data store.
         */
        bool resize(const GLvoid* data, GLsizei size);
        /**
         * @brief Updates a subset of the buffer with data
         * @param data   Specifies a pointer to the new data that will be copied into the
         *               data store. 
         * @param offset Specifies the offset into the buffer object's data store where data 
         *               replacement will begin, measured in bytes. 
         * @param size   Specifies the size in bytes of the data store region being replaced.
         */
        bool setData(const GLvoid* data, GLsizei offset, GLsizei size);
        /**
         * @brief Map all of a buffer object's data store into the client's address space
         * @param pointer Pointer to the client space address. The data can then be directly 
         *                read and/or written relative to the pointer.
         * @param access  Specifies the access policy for glMapBuffer and glMapNamedBuffer, 
         *                indicating whether it will be possible to read from, write to, or both 
         *                read from and write to the buffer object's mapped data store. The 
         *                symbolic constant must be GL_READ_ONLY, GL_WRITE_ONLY, or GL_READ_WRITE.
         */
        bool mapBuffer(GLvoid** pointer, GLenum access) const;
        /**
         * @brief Map all or part of a buffer object's data store into the client's address space
         * @param pointer Pointer to the client space address. The data can then be directly 
         *                read and/or written relative to the pointer.
         * @param offset  Specifies the starting offset within the buffer of the range to be mapped.
         * @param size    Specifies the length of the range to be mapped.
         * @param access  Specifies the access policy for glMapBuffer and glMapNamedBuffer, 
         *                indicating whether it will be possible to read from, write to, or both 
         *                read from and write to the buffer object's mapped data store. The 
         *                symbolic constant must be GL_READ_ONLY, GL_WRITE_ONLY, or GL_READ_WRITE.
         */
        bool mapBufferRange(GLvoid** pointer, GLsizei offset, GLsizei size, GLenum access) const;
        /**
         * @brief Indicate modifications to a range of a mapped buffer.
         * @param offset  Specifies the start of the buffer subrange, in bytes.
         * @param size    Specifies the length of the buffer subrange, in bytes. 
         */
        bool flushMappedBufferRange(GLsizei offset, GLsizei size) const;
        /**
         * @brief Release the mapping of a buffer object's data store 
         *        into the client's address space
         */
        bool unMapBuffer() const;
        /**
         * @brief Deletes the buffer
         */
        void destroy();
        /**
         * @brief Binds the buffer object
         */
        void bind() const;
        /**
         * @brief Unbinds the buffer object and sets the current buffer object to zero
         */
        void unbind() const;
        /**
         * @brief Returns the OpenGL named object (the handle)
         */
        inline GLuint getHandle() const {
            return buffer;
        }
        /**
         * @brief Returns the size of the buffer in bytes
         */
        inline GLsizei getSize() const {
            return size;
        }
        /**
         * @brief Returns the access type of the buffer as GL_READ_ONLY, 
         *        GL_WRITE_ONLY, or GL_READ_WRITE
         */
        inline GLenum getType() const {
            return type;
        }
        /**
         * @brief Returns the object type of the buffer specified during the constructor
         */
        inline GLenum getObjectType() const {
            return objecttype;
        }
        /**
         * @brief Copy all or part of the data store of a buffer object to the data store of 
         *        another buffer object
         * @param other       The other source object to copy data from
         * @param readoffset  Specifies the offset, in bytes, within the data store
         *                    of the source buffer object at which data will be read. 
         * @param writeoffset Specifies the offset, in bytes, within the data store 
         *                    of the destination buffer object at which data will be written.
         * @param size        Specifies the size, in bytes, of the data to be copied 
         *                    from the source buffer object to the destination buffer object.
         */
        bool copyFrom(const BufferObject* other, GLintptr readoffset,
            GLintptr writeoffset, GLsizeiptr size);
        /**
         * @brief Reads a subset of a buffer object's data store
         * @param data   Specifies a pointer to the location where buffer object data is returned.
         * @param offset Specifies the offset into the buffer object's data store from which data 
         *               will be returned, measured in bytes. 
         * @param size   Specifies the size in bytes of the data store region being returned.
         */
        bool getData(GLvoid* data, GLsizei offset, GLsizei size);
        /**
        * @brief Returns a subset of a buffer object's data store
        * @param offset Specifies the offset into the buffer object's data store from which data
        *               will be returned, measured in bytes.
        * @param size   Specifies the size in bytes of the data store region being returned.
        * @returns a vector of uint8_t
        */
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
    /**
     * @ingroup graphics
     * @brief BufferObject of type GL_ARRAY_BUFFER
     */
    class FFW_API Vbo: public BufferObject {
    public:
        Vbo():BufferObject(GL_ARRAY_BUFFER) {
            
        }
    };
    /**
     * @ingroup graphics
     * @brief BufferObject of type GL_ELEMENT_ARRAY_BUFFER
     */
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
