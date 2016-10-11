/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D
#define FFW_TEXTURE_2D
#include "texture.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture2D: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture2D();
        ~Texture2D();
        bool Create(const ffw::RenderContext* renderer, GLsizei Width, GLsizei Height, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool Resize(GLsizei width, GLsizei height);
        bool SetPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, const void* pixels);
		bool GetPixels(void* pixels);
    };
};
#endif
