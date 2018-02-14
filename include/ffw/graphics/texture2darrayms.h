/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY_MS
#define FFW_TEXTURE_2D_ARRAY_MS
#include "texture.h"

namespace ffw {
    /**
     * @ingroup graphics
     */
    class FFW_API Texture2DArrayMS: public Texture {
    public:
        Texture2DArrayMS();
        Texture2DArrayMS(const Texture2DArrayMS& second) = delete;
        Texture2DArrayMS(Texture2DArrayMS&& second);
        ~Texture2DArrayMS();
        bool create(GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, GLenum format, GLenum pixelformat, GLint samples);
        bool resize(GLsizei width, GLsizei height, GLsizei layers, GLint samples);
        Texture2DArrayMS& operator = (const Texture2DArrayMS& second) = delete;
        Texture2DArrayMS& operator = (Texture2DArrayMS&& second);
    };
};
#endif

