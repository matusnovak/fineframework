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
        static bool checkCompability(const RenderContext* renderer);
		Texture2D();
		Texture2D(const Texture2D& second) = delete;
		Texture2D(Texture2D&& second);
        ~Texture2D();
        bool create(const ffw::RenderContext* renderer, GLsizei Width, GLsizei Height, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool createFromBuffer(const ffw::RenderContext* renderer, const ImageBuffer& buffer, bool inverse = false);
		bool resize(GLsizei width, GLsizei height);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, const void* pixels);
		bool getPixels(void* pixels);
		Texture2D& operator = (const Texture2D& second) = delete;
		Texture2D& operator = (Texture2D&& second);
    };
};
#endif
