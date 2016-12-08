/* This file is part of FineFramework project */
#ifndef FFW_BUFFER_OBJECT
#define FFW_BUFFER_OBJECT
#include "../config.h"
#if defined(FFW_WINDOWS_MSVC)
// Evil windows.h
#define NOMINMAX
#include "windows.h"
#undef NOMINMAX
#endif
#ifdef FFW_OSX
#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#include <OpenGL/gl3.h>
#include <OpenGL/glext.h>
#include <OpenGL/gl.h>
#else
#include "GL/gl.h"
#include "GL/glext.h"
#endif

namespace ffw {
	class RenderContext;
	class GlextStruct;
	/**
	 * @ingroup graphics
	 */
	class FFW_API BufferObject {
    public:
		static bool CheckCompability(const RenderContext* renderer);
		BufferObject(unsigned int objecttype);
		virtual ~BufferObject();
		inline bool IsCreated() const {
			return loaded_;
		}
		bool Create(const RenderContext* renderer, const void* data, int size, unsigned int type);
		bool SetData(const void* data, int offset, int size);
        bool MapBuffer(void** pointer, unsigned int access) const;
        bool UnMapBuffer() const;
		void Destroy();
		void Bind() const;
		void Unbind() const;
		inline unsigned int GetHandle() const {
			return buffer_;
		}
		inline int GetSize() const {
			return size_;
		}
		inline unsigned int GetType() const {
			return type_;
		}
		inline unsigned int GetObjectType() const {
			return objecttype_;
		}
		bool CopyFrom(const BufferObject* other, ptrdiff_t offset1, ptrdiff_t offset2, ptrdiff_t size);
    private:
        unsigned int type_;
        const unsigned int objecttype_;
        bool loaded_;
        unsigned int buffer_;
        int size_;
        const GlextStruct* gl_;
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
#endif
