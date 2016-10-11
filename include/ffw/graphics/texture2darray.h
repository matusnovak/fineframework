/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY
#define FFW_TEXTURE_2D_ARRAY
#include "texture.h"

namespace ffw {
	class FFW_API Texture2DArray: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture2DArray();
        ~Texture2DArray();
        bool Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool Resize(GLsizei width, GLsizei height, GLsizei layers);
        bool SetPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, GLsizei width, GLsizei height, const void* pixels);
		bool GetPixels(void* pixels);
    };
};
#endif

