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
#include "../config.h"
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
        Texture(Texture&& other);
        void swap(Texture& other);
        virtual ~Texture();
        inline bool isCreated() const {
            return loaded_;
        }
        void destroy();
        void bind() const;
        void unbind() const;
        inline GLuint getHandle() const {
            return buffer_;
        }
        inline GLsizei getWidth() const {
            return width_;
        }
        inline GLsizei getHeight() const {
            return height_;
        }
        inline GLsizei getLayers() const {
            return layers_;
        }
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
        inline GLenum getInternalFormat() const {
            return internalformat_;
        }
        inline GLenum getFormat() const {
            return format_;
        }
        inline GLenum getPixelFormat() const {
            return pixelformat_;
        }
        inline GLenum getTextureFormat() const {
            return textureformat_;
        }
        inline bool isCompressed() const {
            switch (internalformat_) {
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
        void setEnvParami(GLenum Target, GLenum Name, GLint Value);
        void setEnvParamf(GLenum Target, GLenum Name, GLfloat Value);
        void setTexParami(GLenum Name, GLint Value);
        void setTexParamiv(GLenum Name, GLint* Values);
        void setTexParamf(GLenum Name, GLfloat Value);
        void setTexParamfv(GLenum Name, GLfloat* Values);
        bool generateMipmaps();
        void setFiltering(Texture::Filtering filtering);
        void setWrapping(Texture::Wrapping wrapping);
        Texture& operator = (const Texture& other) = delete;
        Texture& operator = (Texture&& other);
    protected:
        inline GLsizei getBlockSize(GLsizei width, GLsizei height = 1, GLsizei depth = 1) const {
            //if (width < 4 || height < 4)return width * height * depth;
            switch(internalformat_) {
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
        bool compressed_;
    };
};

inline void swap(ffw::Texture& first, ffw::Texture& second) {
    first.swap(second);
}
#endif
```


    
  
