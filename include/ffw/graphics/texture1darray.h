/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_1D_ARRAY
#define FFW_TEXTURE_1D_ARRAY
#include "texture.h"

namespace ffw {
	class FFW_API Texture1DArray: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture1DArray();
        ~Texture1DArray();
        bool Create(const ffw::RenderContext* Renderer, GLsizei width, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool Resize(GLsizei width, GLsizei layers);
        bool SetPixels(GLint level, GLint xoffset, GLint loffset, GLsizei width, const void* pixels);
		bool GetPixels(void* pixels);
    };
};
#endif

