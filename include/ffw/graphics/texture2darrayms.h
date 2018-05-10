/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY_MS
#define FFW_TEXTURE_2D_ARRAY_MS

#include "texture.h"

namespace ffw {
    /**
     * @ingroup graphics
     * @brief OpenGL texture of type GL_TEXTURE_2D_MULTISAMPLE_ARRAY
     */
    class FFW_API Texture2DArrayMS: public Texture {
    public:
        Texture2DArrayMS();
        Texture2DArrayMS(const Texture2DArrayMS& other) = delete;
        Texture2DArrayMS(Texture2DArrayMS&& other) NOEXCEPT;
        virtual ~Texture2DArrayMS() = default;
        /**
         * @brief Allocates the texture
         * @param width Specifies the width of the texture image.
         * @param height Specifies the height of the texture image.
         * @param layers Specifies the number of laters of the texture image.
         * @param internalformat The internal format to be used to store the multisample texture's 
         * image. internalformat must specify a color-renderable, depth-renderable, 
         * or stencil-renderable format. 
         * @param samples The number of samples in the multisample texture's image. 
         * @details The following compressed internalformats are allowed: 
         * GL_COMPRESSED_RGB_S3TC_DXT1_EXT, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, 
         * GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, 
         * GL_COMPRESSED_RED_RGTC1, GL_COMPRESSED_RG_RGTC2, GL_COMPRESSED_SIGNED_RED_RGTC1,
         * GL_COMPRESSED_SIGNED_RG_RGTC2
         * @note The texture is automatically destroyed once destroy() is called, or the instance 
         * of this texture class is freed. The format and pixelformat is not used and therefore
         * set to zero (getPixelFormat and getInternalFormat will return value of zero).
         */
        bool create(GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat,
            GLint samples);
        /**
         * @brief Resizes the texture
         * @param width Specifies the width of the texture image.
         * @param height Specifies the height of the texture image.
         * @param layers Specifies the number of laters of the texture image.
         * @param samples The number of samples in the multisample texture's image. 
         * @note The internalformat is unchanged.
         */
        bool resize(GLsizei width, GLsizei height, GLsizei layers, GLint samples);
        Texture2DArrayMS& operator = (const Texture2DArrayMS& other) = delete;
        Texture2DArrayMS& operator = (Texture2DArrayMS&& other) NOEXCEPT;
    };
};

inline void swap(ffw::Texture2DArrayMS& first, ffw::Texture2DArrayMS& second) NOEXCEPT {
    first.swap(second);
}
#endif

