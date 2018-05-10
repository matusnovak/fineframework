/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_2D_ARRAY
#define FFW_TEXTURE_2D_ARRAY

#include "texture.h"

namespace ffw {
    class ImageBuffer;

    /**
     * @ingroup graphics
     * @brief OpenGL texture of type GL_TEXTURE_2D_ARRAY
     */
    class FFW_API Texture2DArray: public Texture {
    public:
        Texture2DArray();
        Texture2DArray(const Texture2DArray& other) = delete;
        Texture2DArray(Texture2DArray&& other) NOEXCEPT;
        virtual ~Texture2DArray() = default;
        /**
         * @brief Allocates the texture
         * @param width Specifies the width of the texture image.
         * @param height Specifies the height of the texture image.
         * @param layers Specifies the number of laters of the texture image.
         * @param internalformat Specifies the number of color components in the texture.
         * @param format Specifies the format of the pixel data. The following symbolic values are 
         * accepted: GL_RED, GL_RG, GL_RGB, GL_BGR, GL_RGBA, GL_BGRA, GL_RED_INTEGER, GL_RG_INTEGER,
         * GL_RGB_INTEGER, GL_BGR_INTEGER, GL_RGBA_INTEGER, GL_BGRA_INTEGER, GL_STENCIL_INDEX, 
         * GL_DEPTH_COMPONENT, GL_DEPTH_STENCIL. 
         * @param pixelformat Specifies the data type of the pixel data. The following symbolic 
         * values are accepted: GL_UNSIGNED_BYTE, GL_BYTE, GL_UNSIGNED_SHORT, GL_SHORT, 
         * GL_UNSIGNED_INT, GL_INT, GL_FLOAT, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_BYTE_2_3_3_REV, 
         * GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_SHORT_5_6_5_REV, GL_UNSIGNED_SHORT_4_4_4_4, 
         * GL_UNSIGNED_SHORT_4_4_4_4_REV, GL_UNSIGNED_SHORT_5_5_5_1, GL_UNSIGNED_SHORT_1_5_5_5_REV, 
         * GL_UNSIGNED_INT_8_8_8_8, GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_INT_10_10_10_2, and 
         * GL_UNSIGNED_INT_2_10_10_10_REV. 
         * @param pixels Optional array to the pixels buffer that will be used to initialise the 
         * texture storage. The pixel array must be correct size, otherwise a segmentation fault
         * will occur. If null, the texture storage is not set and initialised with random data.
         * @details The following compressed internalformats are allowed: 
         * GL_COMPRESSED_RGB_S3TC_DXT1_EXT, GL_COMPRESSED_RGBA_S3TC_DXT1_EXT, 
         * GL_COMPRESSED_RGBA_S3TC_DXT3_EXT, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, 
         * GL_COMPRESSED_RED_RGTC1, GL_COMPRESSED_RG_RGTC2, GL_COMPRESSED_SIGNED_RED_RGTC1,
         * GL_COMPRESSED_SIGNED_RG_RGTC2
         * @note The texture is automatically destroyed once destroy() is called, or the instance 
         * of this texture class is freed.
         */
        bool create(GLsizei width, GLsizei height, GLsizei layers, GLenum internalformat, 
            GLenum format, GLenum pixelformat, const GLvoid* pixels = nullptr);
        /**
         * @brief Resizes the texture
         * @param width The new width of the texture
         * @param height The new height of the texture
         * @param layers The new number of layers of the texture
         * @param pixels Optional array to the pixels buffer that will be used to initialise the 
         * texture storage. The pixel array must be correct size, otherwise a segmentation fault
         * will occur. If null, the texture storage is not set and initialised with random data.
         * @note The format, internalformat, and pixelformat are unchanged.
         */
        bool resize(GLsizei width, GLsizei height, GLsizei layers, const GLvoid* pixels = nullptr);
        /**
         * @brief Creates the texture using ImageBuffer
         * @param image The instance of the image buffer.
         * @param layer The layer to set.
         * @param inverse Specifies if the pixels should be mirrored vertically. Set to false
         * (default) to be unchanged.
         */
        bool setFromBuffer(const ImageBuffer& image, GLint layer, bool inverse = false);
        /**
         * @brief Sets the pixels of the entire texture
         * @param level The mipmap level to set. Zero by default.
         * @param pixels Non null pointer to the array of the pixels to upload.
         */
        bool setPixels(GLint level, const GLvoid* pixels);
        /**
         * @brief Sets the pixels of the texture section
         * @param level The mipmap level to set. Zero by default.
         * @param xoffset The x offset of the target area to set.
         * @param yoffset The y offset of the target area to set.
         * @param loffset The layer offset.
         * @param width The width of the area to set.
         * @param height The height of the area to set.
         * @param pixels Non null pointer to the array of the pixels to upload.
         */
        bool setPixels(GLint level, GLint xoffset, GLint yoffset, GLint loffset, 
            GLsizei width, GLsizei height, const GLvoid* pixels);
        /**
         * @brief Returns the pixels of the entire texture
         * @param pixels Non null pointer to an allocated array that will hold the entire
         * texture data. 
         */
        bool getPixels(GLvoid* pixels) const;
        Texture2DArray& operator = (const Texture2DArray& second) = delete;
        Texture2DArray& operator = (Texture2DArray&& second) NOEXCEPT;
    private:
        void setPixelsInternal(GLint level, const GLvoid* pixels = nullptr);
        void setPixelsInternal(GLint level, GLint xoffset, GLint yoffset, GLint loffset,
            GLsizei width, GLsizei height, const GLvoid* pixels);
    };
};

inline void swap(ffw::Texture2DArray& first, ffw::Texture2DArray& second) NOEXCEPT {
    first.swap(second);
}
#endif

