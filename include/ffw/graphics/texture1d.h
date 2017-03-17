/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_1D
#define FFW_TEXTURE_1D
#include "texture.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture1D: public Texture {
    public:
        static bool checkCompability(const RenderContext* renderer);
		Texture1D();
		Texture1D(const Texture1D& second) = delete;
		Texture1D(Texture1D&& second);
        ~Texture1D();
        bool create(const ffw::RenderContext* renderer, GLsizei width, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool resize(GLsizei width);
        bool setPixels(GLint level, GLint xoffset, GLsizei width, const void* pixels);
		bool getPixels(void* pixels);
		Texture1D& operator = (const Texture1D& second) = delete;
		Texture1D& operator = (Texture1D&& second);
    };
};
#endif
