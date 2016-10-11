/* This file is part of FineFramework project */
#ifndef FFW_RENDERBUFFER
#define FFW_RENDERBUFFER
#include "../config.h"
#if defined(FFW_WINDOWS_MSVC)
// Evil windows.h
#define NOMINMAX
#include "windows.h"
#undef NOMINMAX
#endif
#ifdef FFW_OSX
#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#include "gl3.h"
#include "glext.h"
#include "gl.h"
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
	class FFW_API Renderbuffer {
    public:
        Renderbuffer();
        virtual ~Renderbuffer();
        inline bool IsCreated() const {
			return loaded_;
		}
        void Destroy();
        void Bind() const;
        void Unbind() const;
        unsigned int GetHandle() const {
			return buffer_;
		}
        inline int getWidth() const {
			return width_;
		}
        inline int getHeight() const {
			return height_;
		}
        inline unsigned int GetInternalFormat() const {
			return internalformat_;
		}
    protected:
        bool loaded_;
        unsigned int internalformat_;
        unsigned int buffer_;
        int width_;
        int height_;
        const GlextStruct* gl_;
    };
};
#endif
