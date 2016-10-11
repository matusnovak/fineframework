/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_MS
#define FFW_TEXTURE_2D_MS
#include "texture.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
	class FFW_API Texture2DMS: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture2DMS();
        ~Texture2DMS();
        bool Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLenum internalformat, GLenum format, GLenum pixelformat, GLint samples);
		bool Resize(GLsizei width, GLsizei height, GLint samples);
	};
};
#endif
