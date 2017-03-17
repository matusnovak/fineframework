/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_1D_ARRAY
#define FFW_TEXTURE_1D_ARRAY
#include "texture.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture1DArray: public Texture {
    public:
        static bool checkCompability(const RenderContext* renderer);
		Texture1DArray();
		Texture1DArray(const Texture1DArray& second) = delete;
		Texture1DArray(Texture1DArray&& second);
        ~Texture1DArray();
        bool create(const ffw::RenderContext* Renderer, GLsizei width, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool resize(GLsizei width, GLsizei layers);
        bool setPixels(GLint level, GLint xoffset, GLint loffset, GLsizei width, const void* pixels);
		bool getPixels(void* pixels);
		Texture1DArray& operator = (const Texture1DArray& second) = delete;
		Texture1DArray& operator = (Texture1DArray&& second);
    };
};
#endif

