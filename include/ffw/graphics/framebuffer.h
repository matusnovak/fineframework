/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FRAMEBUFFER
#define FFW_GRAPHICS_FRAMEBUFFER
#include "../config.h"
#include "texture2d.h"
#include "texture2dms.h"
#include "renderbuffer2d.h"
#include "renderbuffer2dms.h"
#include "texturecubemap.h"

namespace ffw {
    /**
     * @ingroup graphics
     */
    class FFW_API Framebuffer {
    public:
        Framebuffer();
        Framebuffer(const Framebuffer& other) = delete;
        Framebuffer(Framebuffer&& other);
        void swap(Framebuffer& other);
        ~Framebuffer();
        inline bool isCreated() const {
            return created_;
        }
        bool create();
        bool addTexture(GLenum attachment, GLuint textype, GLuint texture, GLint level = 0) const;
        bool addRenderbuffer(GLenum attachment, GLuint texture) const;

        inline bool addStencilTexture(const ffw::Texture2D* texture, GLint level = 0) {
            return addTexture(GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texture->getHandle(), level);
        }
        inline bool addStencilBuffer(const ffw::Renderbuffer2D* texture) {
            return addRenderbuffer(GL_STENCIL_ATTACHMENT, texture->getHandle());
        }
        bool addColorTexture(const ffw::Texture2D* texture, GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D, texture->getHandle(), level))return false;
            colorcount_++;
            return true;
        }
        bool addCubemapTexture(const ffw::TextureCubemap* texture, GLint side, GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, texture->getHandle(), level))return false;
            colorcount_++;
            return true;
        }
        bool addDepthTexture(const ffw::Texture2D* texture, GLint level = 0) {
            return addTexture(GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture->getHandle(), level);
        }
        bool addColorTextureMS(const ffw::Texture2DMS* texture, GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount_, GL_TEXTURE_2D_MULTISAMPLE, texture->getHandle(), level))return false;
            colorcount_++;
            return true;
        }
        bool addDepthTextureMS(const ffw::Texture2DMS* texture, GLint level = 0) {
            return addTexture(GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, texture->getHandle(), level);
        }
        bool addColorRenderbuffer(const ffw::Renderbuffer2D* texture) {
            if (!addRenderbuffer(GL_COLOR_ATTACHMENT0 + colorcount_, texture->getHandle()))return false;
            colorcount_++;
            return true;
        }
        bool addDepthRenderbuffer(const ffw::Renderbuffer2D* texture) {
            return addRenderbuffer(GL_DEPTH_ATTACHMENT, texture->getHandle());
        }
        bool addColorRenderbufferMS(const ffw::Renderbuffer2DMS* texture) {
            if (!addRenderbuffer(GL_COLOR_ATTACHMENT0 + colorcount_, texture->getHandle()))return false;
            colorcount_++;
            return true;
        }
        bool addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* texture) {
            return addRenderbuffer(GL_DEPTH_ATTACHMENT, texture->getHandle());
        }
        bool checkStatus();
        inline unsigned int getHandle() const {
            return fbo_;
        }
        inline void resetColorCount() {
            colorcount_ = 0;
        }
        bool destroy();
        void bind() const;
        void unbind() const;

        Framebuffer& operator = (const Framebuffer& other) = delete;
        Framebuffer& operator = (Framebuffer&& other);
    private:
        bool created_;
        unsigned int fbo_;
        int colorcount_;
        const RenderExtensions* gl_;
    };
};

inline void swap(ffw::Framebuffer& first, ffw::Framebuffer& second) {
    first.swap(second);
}
#endif
