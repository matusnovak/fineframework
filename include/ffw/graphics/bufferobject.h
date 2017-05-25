/* This file is part of FineFramework project */
#ifndef FFW_BUFFER_OBJECT
#define FFW_BUFFER_OBJECT
#include "../config.h"

#ifdef FFW_OSX
#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#else
#ifndef WINGDIAPI
#define WINGDIAPI __declspec(dllimport)
#define APIENTRY _stdcall
#include "GL/gl.h"
#include "GL/glext.h"
#undef WINGDIAPI
#undef APIENTRY
#else
#ifndef APIENTRY
#define APIENTRY
#endif
#include "GL/gl.h"
#include "GL/glext.h"
#endif
#endif

namespace ffw {
	class RenderContext;
	class RenderExtensions;
	/**
	 * @ingroup graphics
	 */
	class FFW_API BufferObject {
    public:
		static bool checkCompability(const RenderContext* renderer);
		BufferObject(unsigned int objecttype);
		BufferObject(const BufferObject& other) = delete;
		BufferObject(BufferObject&& other);
		void swap(BufferObject& other);

		virtual ~BufferObject();
		inline bool isCreated() const {
			return loaded_;
		}
		bool create(const RenderContext* renderer, const void* data, GLsizei size, GLenum type);
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
        const RenderExtensions* gl_;
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
