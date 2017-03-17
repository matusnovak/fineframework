/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_BASE
#define FFW_TEXTURE_BASE
#include "../config.h"
#include "../math.h"
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
	class RenderExtensions;
	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture {
    public:
		enum Filtering {
			NEAREST,
			LINEAR,
			MIPMAP_NEAREST,
			MIPMAP_LINEAR
		};
        Texture();
		Texture(const Texture& other) = delete;
		Texture(Texture&& other);
		void swap(Texture& other);
        virtual ~Texture();
        inline bool isCreated() const {
			return loaded_;
		}
        void destroy();
        void bind() const;
        void unbind() const;
        inline unsigned int getHandle() const {
			return buffer_;
		}
        inline int getWidth() const {
			return width_;
		}
        inline int getHeight() const {
			return height_;
		}
        inline int getLayers() const {
			return layers_;
		}
        inline int getDepth() const {
			return depth_;
		}
		inline int getSamples() const {
			return samples_;
		}
        inline unsigned int getInternalFormat() const {
			return internalformat_;
		}
        inline unsigned int getFormat() const {
			return format_;
		}
        inline unsigned int getPixelFormat() const {
			return pixelformat_;
		}
        unsigned int getTextureFormat() const {
			return textureformat_;
		}
        void setEnvParami(unsigned int Target, unsigned int Name, int Value);
        void setEnvParamf(unsigned int Target, unsigned int Name, float Value);
        void setTexParami(unsigned int Name, int Value);
		void setTexParamiv(unsigned int Name, int* Values);
        void setTexParamf(unsigned int Name, float Value);
		void setTexParamfv(unsigned int Name, float* Values);
        bool generateMipmaps();
		void setFiltering(Texture::Filtering filtering);

		Texture& operator = (const Texture& other) = delete;
		Texture& operator = (Texture&& other);
    protected:
        bool loaded_;
        unsigned int textureformat_;
        unsigned int internalformat_;
        unsigned int format_;
        unsigned int pixelformat_;
        unsigned int buffer_;
        int width_;
        int height_;
        int depth_;
        int layers_;
        bool mipmaps_;
        bool initialized_;
		int samples_;
        const RenderExtensions* gl_;
    };
};

inline void swap(ffw::Texture& first, ffw::Texture& second) {
	first.swap(second);
}
#endif
