/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_3D
#define FFW_TEXTURE_3D
#include "texture.h"

namespace ffw {
	class FFW_API Texture3D: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture3D();
        ~Texture3D();
        bool Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei depth, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool Resize(GLsizei width, GLsizei height, GLsizei depth);
        bool SetPixels(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const void* pixels);
		bool GetPixels(void* pixels);
    };
};
#endif
