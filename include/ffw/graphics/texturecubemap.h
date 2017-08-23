/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_CUBEMAP
#define FFW_TEXTURE_CUBEMAP
#include "texture.h"

namespace ffw {
	class ImageBuffer;

	/**
	 * @ingroup graphics
	 */
	class FFW_API TextureCubemap: public Texture {
    public:
        static bool checkCompability(const RenderContext* renderer);
		TextureCubemap();
		TextureCubemap(const TextureCubemap& second) = delete;
		TextureCubemap(TextureCubemap&& second);
        ~TextureCubemap();
        bool create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat);
		bool resize(GLsizei width, GLsizei height);
		/**
		 * @brief Sets the pixels
		 * @details The side parameter corresponds to which side
		 * should be set. The accepted values are from 0 to 5 where each number represents:
		 * * 0: GL_TEXTURE_CUBE_MAP_POSITIVE_X (Right)
		 * * 1: GL_TEXTURE_CUBE_MAP_NEGATIVE_X (Left)
		 * * 2: GL_TEXTURE_CUBE_MAP_POSITIVE_Y (Top)
		 * * 3: GL_TEXTURE_CUBE_MAP_NEGATIVE_Y (Bottom)
		 * * 4: GL_TEXTURE_CUBE_MAP_POSITIVE_Z (Back)
		 * * 5: GL_TEXTURE_CUBE_MAP_NEGATIVE_Z (Front)
		 */
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, int side, const void* pixels);
		bool getPixels(void* pixels);
		TextureCubemap& operator = (const TextureCubemap& second) = delete;
		TextureCubemap& operator = (TextureCubemap&& second);
    };
};
#endif
