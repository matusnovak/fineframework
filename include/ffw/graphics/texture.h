/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_BASE
#define FFW_TEXTURE_BASE
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
	class FFW_API Texture {
    public:
        Texture();
        virtual ~Texture();
        inline bool IsCreated() const {
			return loaded_;
		}
        void Destroy();
        void Bind() const;
        void Unbind() const;
        inline unsigned int GetHandle() const {
			return buffer_;
		}
        inline int GetWidth() const {
			return width_;
		}
        inline int GetHeight() const {
			return height_;
		}
        inline int GetLayers() const {
			return layers_;
		}
        inline int GetDepth() const {
			return depth_;
		}
		inline int GetSamples() const {
			return samples_;
		}
        inline unsigned int GetInternalFormat() const {
			return internalformat_;
		}
        inline unsigned int GetFormat() const {
			return format_;
		}
        inline unsigned int GetPixelFormat() const {
			return pixelformat_;
		}
        unsigned int GetTextureFormat() const {
			return textureformat_;
		}
        void SetEnvParami(unsigned int Target, unsigned int Name, int Value);
        void SetEnvParamf(unsigned int Target, unsigned int Name, float Value);
        void SetTexParami(unsigned int Name, int Value);
		void SetTexParamiv(unsigned int Name, int* Values);
        void SetTexParamf(unsigned int Name, float Value);
		void SetTexParamfv(unsigned int Name, float* Values);
        bool GenerateMipmaps();
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
        const GlextStruct* gl_;
    };
};
#endif
