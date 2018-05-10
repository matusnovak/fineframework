---
search: false
---

# texture.h File Reference

**[Go to the documentation of this file.](texture_8h.md)**
Source: `include/ffw/graphics/texture.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_TEXTURE_BASE
#define FFW_TEXTURE_BASE

#include "renderextensionsgl.h"

namespace ffw {
    class RenderContext;
    class RenderExtensions;
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
        Texture(Texture&& other) NOEXCEPT;
        void swap(Texture& other) NOEXCEPT;
        virtual ~Texture();
        inline bool isCreated() const {
            return loaded;
        }
        void destroy();
        void bind() const;
        void unbind() const;
        inline GLuint getHandle() const {
            return buffer;
        }
        inline GLsizei getWidth() const {
            return width;
        }
        inline GLsizei getHeight() const {
            return height;
        }
        inline GLsizei getLayers() const {
            return layers;
        }
        inline GLsizei getDepth() const {
            return depth;
        }
        /***
         * @brief Returns the number of samples
         * @details This only applies to multi-samples textures,
         * otherwise returns 1.
         */
        inline GLsizei getSamples() const {
            return samples;
        }
        inline GLenum getInternalFormat() const {
            return internalformat;
        }
        inline GLenum getFormat() const {
            return format;
        }
        inline GLenum getPixelFormat() const {
            return pixelformat;
        }
        inline GLenum getTextureFormat() const {
            return textureformat;
        }
        inline bool isCompressed() const {
            switch (internalformat) {
                case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
                case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
                case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
                case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
                case GL_COMPRESSED_RED_RGTC1:
                case GL_COMPRESSED_RG_RGTC2:
                case GL_COMPRESSED_SIGNED_RED_RGTC1:
                case GL_COMPRESSED_SIGNED_RG_RGTC2:
                    return true;
                default:
                    return false;
            }
        }
        void setEnvParami(GLenum target, GLenum name, GLint value) const;
        void setEnvParamf(GLenum target, GLenum name, GLfloat value) const;
        void setTexParami(GLenum name, GLint value) const;
        void setTexParamiv(GLenum name, const GLint* value) const;
        void setTexParamf(GLenum name, GLfloat value) const;
        void setTexParamfv(GLenum name, const GLfloat* value) const;
        bool generateMipmaps();
        void setFiltering(Texture::Filtering filtering) const;
        void setWrapping(Texture::Wrapping wrapping) const;
        Texture& operator = (const Texture& other) = delete;
        Texture& operator = (Texture&& other) NOEXCEPT;
    protected:
        inline GLsizei getBlockSize(const GLsizei width, const GLsizei height = 1, const GLsizei depth = 1) const {
            //if (width < 4 || height < 4)return width * height * depth;
            switch(internalformat) {
                case GL_COMPRESSED_RED_RGTC1:
                case GL_COMPRESSED_SIGNED_RED_RGTC1:
                case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
                case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
                    return ((width+3)/4) * ((height+3)/4) * depth * 8;   
                case GL_COMPRESSED_RG_RGTC2:
                case GL_COMPRESSED_SIGNED_RG_RGTC2:
                case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
                case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
                    return ((width+3)/4) * ((height+3)/4) * depth * 16;
                default:
                    return 0;
            }
        }
        bool loaded;
        GLenum textureformat;
        GLenum internalformat;
        GLenum format;
        GLenum pixelformat;
        GLuint buffer;
        GLsizei width;
        GLsizei height;
        GLsizei depth;
        GLsizei layers;
        bool mipmaps;
        bool initialized;
        GLsizei samples;
        bool compressed;
    };
};

inline void swap(ffw::Texture& first, ffw::Texture& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
