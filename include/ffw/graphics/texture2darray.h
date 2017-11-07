/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY
#define FFW_TEXTURE_2D_ARRAY
#include "texture.h"

namespace ffw {
	class ImageBuffer;

	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture2DArray: public Texture {
    public:
        static bool checkCompability(const RenderContext* renderer);
		Texture2DArray();
		Texture2DArray(const Texture2DArray& second) = delete;
		Texture2DArray(Texture2DArray&& second);
        ~Texture2DArray();
        bool create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat, const GLvoid* pixels = NULL);
		bool resize(GLsizei width, GLsizei height, GLsizei layers);
		bool setFromBuffer(const ImageBuffer& buffer, GLint level, bool inverse = false);
		bool setPixels(GLint level, const GLvoid* pixels = NULL);
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, GLsizei width, GLsizei height, const GLvoid* pixels);
		bool getPixels(void* pixels) const;
		Texture2DArray& operator = (const Texture2DArray& second) = delete;
		Texture2DArray& operator = (Texture2DArray&& second);
    };
};
#endif

