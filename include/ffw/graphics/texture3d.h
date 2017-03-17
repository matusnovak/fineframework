/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_3D
#define FFW_TEXTURE_3D
#include "texture.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture3D: public Texture {
    public:
        static bool checkCompability(const RenderContext* renderer);
		Texture3D();
		Texture3D(const Texture3D& second) = delete;
		Texture3D(Texture3D&& second);
        ~Texture3D();
        bool create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei depth, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool resize(GLsizei width, GLsizei height, GLsizei depth);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, const void* pixels);
		bool getPixels(void* pixels);
		Texture3D& operator = (const Texture3D& second) = delete;
		Texture3D& operator = (Texture3D&& second);
    };
};
#endif
