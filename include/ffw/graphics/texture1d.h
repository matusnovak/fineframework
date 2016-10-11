/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_1D
#define FFW_TEXTURE_1D
#include "texture.h"

namespace ffw {
	class FFW_API Texture1D: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture1D();
        ~Texture1D();
        bool Create(const ffw::RenderContext* renderer, GLsizei width, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool Resize(GLsizei width);
        bool SetPixels(GLint level, GLint xoffset, GLsizei width, const void* pixels);
		bool GetPixels(void* pixels);
    };
};
#endif
