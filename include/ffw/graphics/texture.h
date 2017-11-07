/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_BASE
#define FFW_TEXTURE_BASE
#include "../config.h"
#include "renderextensionsgl.h"

namespace ffw {
	class RenderContext;
	class RenderExtensions;
	/**
	 * @ingroup graphics
	 * @brief Base class for all texture types
	 */
	class FFW_API Texture {
    public:
		enum Filtering {
			NEAREST,
			LINEAR,
			MIPMAP_NEAREST,
			MIPMAP_LINEAR
		};
		enum Wrapping {
			REPEAT,
			MIRRORED_REPEAT,
			CLAMP_TO_EDGE,
		};
        Texture();
		Texture(const Texture& other) = delete;
		Texture(Texture&& other);
		void swap(Texture& other);
        virtual ~Texture();
        inline bool isCreated() const {
			return loaded_;
		}
		/**
		 * @brief Destroys the texture
		 * @details Destroys the texture and the allocated memory to it.
		 * Calling this on already deleted texture does nothing.
		 */
        void destroy();
		/**
		 * @brief Actives the texture
		 */
        void bind() const;
        void unbind() const;
		/**
		 * @brief Returns the OpenGL pointer, a handle to the texture
		 */
        inline GLuint getHandle() const {
			return buffer_;
		}
		/**
		 * @brief Returns the width of the texture
		 */
        inline GLsizei getWidth() const {
			return width_;
		}
		/**
		 * @brief Returns the height of the texture
		 * @brief If the texture is 1D texture, the returned
		 * type is always 1.
		 */
        inline GLsizei getHeight() const {
			return height_;
		}
		/**
		 * @brief Returns the number of layers
		 * @details If the texture is not an array, the returned
		 * value is always 1.
		 */
        inline GLsizei getLayers() const {
			return layers_;
		}
		/**
		 * @brief Returns the depth of the texture
		 * @brief This only applies to 3D texture, otherwise
		 * returns 1.
		 */
        inline GLsizei getDepth() const {
			return depth_;
		}
		/***
		 * @brief Returns the number of samples
		 * @details This only applies to multi-samples textures,
		 * otherwise returns 1.
		 */
		inline GLsizei getSamples() const {
			return samples_;
		}
		/**
		 * @brief Returns the number of color components in the texture
		 * @details The internal format can be GL_RGB8, GL_RGBA8, GL_RGB32F, etc...
		 */
        inline GLenum getInternalFormat() const {
			return internalformat_;
		}
		/**
		 * @brief Returns the format of the pixel data
		 * @details The format can be GL_RGB, GL_RED, GL_RGBA, etc...
		 */
        inline GLenum getFormat() const {
			return format_;
		}
		/**
		 * @brief Returns the data type of the pixel data
		 * @details The pixel format can be GL_UNSIGNED_BYTE, GL_FLOAT, etc...
		 */
        inline GLenum getPixelFormat() const {
			return pixelformat_;
		}
		/**
		 * @brief Returns the type of the texture
		 * @details The texture format can be GL_TEXTURE_1D, GL_TEXTURE_2D, etc...
		 */
        inline GLenum getTextureFormat() const {
			return textureformat_;
		}
		inline bool isCompressed() const {
			switch (internalformat_) {
				case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
				case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
				case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
				case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
				case GL_COMPRESSED_SRGB_S3TC_DXT1_EXT:
				case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT:
				case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT:
				case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT:
#ifdef FFW_OSX
				case GL_COMPRESSED_RED_RGTC1:
				case GL_COMPRESSED_RG_RGTC2:
				case GL_COMPRESSED_SIGNED_RED_RGTC1:
				case GL_COMPRESSED_SIGNED_RG_RGTC2:
#else
				case GL_COMPRESSED_RED_RGTC1_EXT:
				case GL_COMPRESSED_RED_GREEN_RGTC2_EXT:
				case GL_COMPRESSED_SIGNED_RED_RGTC1_EXT:
				case GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT:
#endif
					return true;
				default:
					return false;
			}
        }
        void setEnvParami(GLenum Target, GLenum Name, GLint Value);
        void setEnvParamf(GLenum Target, GLenum Name, GLfloat Value);
        void setTexParami(GLenum Name, GLint Value);
		void setTexParamiv(GLenum Name, GLint* Values);
        void setTexParamf(GLenum Name, GLfloat Value);
		void setTexParamfv(GLenum Name, GLfloat* Values);
		/**
		 * @brief Generates mip maps
		 */
        bool generateMipmaps();
		void setFiltering(Texture::Filtering filtering);
		void setWrapping(Texture::Wrapping wrapping);
		Texture& operator = (const Texture& other) = delete;
		Texture& operator = (Texture&& other);
    protected:
		inline GLsizei getBlockSize(GLsizei width, GLsizei height = 1, GLsizei depth = 1) const {
			//if (width < 4 || height < 4)return width * height * depth;
			switch(internalformat_) {
#ifdef FFW_OSX
				case GL_COMPRESSED_RED_RGTC1:
				case GL_COMPRESSED_SIGNED_RED_RGTC1:
#else
				case GL_COMPRESSED_RED_RGTC1_EXT:
				case GL_COMPRESSED_SIGNED_RED_RGTC1_EXT:
#endif
				case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
				case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
				case GL_COMPRESSED_SRGB_S3TC_DXT1_EXT:
				case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT:
					return ((width+3)/4) * ((height+3)/4) * depth * 8;
#ifdef FFW_OSX	
				case GL_COMPRESSED_RG_RGTC2:
				case GL_COMPRESSED_SIGNED_RG_RGTC2:
#else
				case GL_COMPRESSED_RED_GREEN_RGTC2_EXT:
				case GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT:
#endif
				case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
				case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
				case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT:
				case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT:
					return ((width+3)/4) * ((height+3)/4) * depth * 16;
				default:
					return 0;
			}
		}
        bool loaded_;
        GLenum textureformat_;
        GLenum internalformat_;
        GLenum format_;
        GLenum pixelformat_;
        GLuint buffer_;
        GLsizei width_;
        GLsizei height_;
        GLsizei depth_;
        GLsizei layers_;
        bool mipmaps_;
        bool initialized_;
		GLsizei samples_;
        const RenderExtensions* gl_;
		bool compressed_;
    };
};

inline void swap(ffw::Texture& first, ffw::Texture& second) {
	first.swap(second);
}
#endif
