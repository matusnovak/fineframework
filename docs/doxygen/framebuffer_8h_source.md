---
search: false
---

# framebuffer.h File Reference

**[Go to the documentation of this file.](framebuffer_8h.md)**
Source: `include/ffw/graphics/framebuffer.h`

    
    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FRAMEBUFFER
#define FFW_GRAPHICS_FRAMEBUFFER

#include "renderextensionsgl.h"
#include "texture2d.h"
#include "texture2dms.h"
#include "renderbuffer2d.h"
#include "renderbuffer2dms.h"
#include "texturecubemap.h"

namespace ffw {
    class FFW_API Framebuffer {
    public:
        Framebuffer();
        Framebuffer(const Framebuffer& other) = delete;
        Framebuffer(Framebuffer&& other) NOEXCEPT;
        void swap(Framebuffer& other) NOEXCEPT;
        ~Framebuffer();
        inline bool isCreated() const {
            return created;
        }
        bool create();
        bool addTexture(GLenum attachment, GLuint textype, GLuint texture, GLint level = 0) const;
        bool addRenderbuffer(GLenum attachment, GLuint texture) const;
        inline bool addStencilTexture(const ffw::Texture2D* texture, const GLint level = 0) {
            return addTexture(GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texture->getHandle(), level);
        }
        inline bool addStencilBuffer(const ffw::Renderbuffer2D* texture) {
            return addRenderbuffer(GL_STENCIL_ATTACHMENT, texture->getHandle());
        }
        bool addColorTexture(const ffw::Texture2D* texture, const GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount, 
                GL_TEXTURE_2D, texture->getHandle(), level))return false;
            colorcount++;
            return true;
        }
        bool addCubemapTexture(const ffw::TextureCubemap* texture, 
            const GLint side, const GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount, 
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, texture->getHandle(), level))return false;
            colorcount++;
            return true;
        }
        bool addDepthTexture(const ffw::Texture2D* texture, const GLint level = 0) {
            return addTexture(GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, 
                texture->getHandle(), level);
        }
        bool addColorTextureMS(const ffw::Texture2DMS* texture, const GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount, GL_TEXTURE_2D_MULTISAMPLE, 
                texture->getHandle(), level))return false;
            colorcount++;
            return true;
        }
        bool addDepthTextureMS(const ffw::Texture2DMS* texture, const GLint level = 0) {
            return addTexture(GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, 
                texture->getHandle(), level);
        }
        bool addColorRenderbuffer(const ffw::Renderbuffer2D* texture) {
            if (!addRenderbuffer(GL_COLOR_ATTACHMENT0 + colorcount, 
                texture->getHandle()))return false;
            colorcount++;
            return true;
        }
        bool addDepthRenderbuffer(const ffw::Renderbuffer2D* texture) {
            return addRenderbuffer(GL_DEPTH_ATTACHMENT, texture->getHandle());
        }
        bool addColorRenderbufferMS(const ffw::Renderbuffer2DMS* texture) {
            if (!addRenderbuffer(GL_COLOR_ATTACHMENT0 + colorcount, 
                texture->getHandle()))return false;
            colorcount++;
            return true;
        }
        bool addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* texture) {
            return addRenderbuffer(GL_DEPTH_ATTACHMENT, texture->getHandle());
        }
        bool checkStatus();
        inline unsigned int getHandle() const {
            return fbo;
        }
        inline void resetColorCount() {
            colorcount = 0;
        }
        bool destroy();
        void bind() const;
        void unbind() const;
        Framebuffer& operator = (const Framebuffer& other) = delete;
        Framebuffer& operator = (Framebuffer&& other) NOEXCEPT;
    private:
        bool created;
        unsigned int fbo;
        int colorcount;
    };
};

inline void swap(ffw::Framebuffer& first, ffw::Framebuffer& second) NOEXCEPT {
    first.swap(second);
}
#endif
```


    
  
