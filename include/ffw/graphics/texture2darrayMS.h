/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY_MS
#define FFW_TEXTURE_2D_ARRAY_MS
#include "texture.h"

namespace ffw {
	class FFW_API Texture2DArrayMS: public Texture {
    public:
        static bool CheckCompability(const RenderContext* renderer);
		Texture2DArrayMS();
        ~Texture2DArrayMS();
        bool Create(const ffw::RenderContext* renderer, GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat, GLint samples);
		bool Resize(GLsizei width, GLsizei height, GLsizei layers, GLint samples);
	};
};
#endif

