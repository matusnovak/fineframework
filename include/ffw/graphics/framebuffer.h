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
    /**
     * @ingroup graphics
     */
    class FFW_API Framebuffer {
    public:
        /**
         * @brief Constructs an empty framebuffer object
         */
        Framebuffer();
        Framebuffer(const Framebuffer& other) = delete;
        Framebuffer(Framebuffer&& other) NOEXCEPT;
        void swap(Framebuffer& other) NOEXCEPT;
        ~Framebuffer();
        /**
         * @brief Returns true if the framebuffer object has been created
         */
        inline bool isCreated() const {
            return created;
        }
        /**
         * @brief Generate framebuffer object
         */
        bool create();
        /**
         * @brief Attach a texture image to the framebuffer object
         * @param attachment Specifies the attachment point to which an image from texture should 
         *                   be attached. Must be one of the GL_COLOR_ATTACHMENT0, 
         *                   GL_DEPTH_ATTACHMENT, or GL_STENCIL_ATTACHMENT.
         * @param textype    Specifies the texture target. Must be one of the GL_TEXTURE_2D,
		 *                   GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
		 *                   GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
		 *                   GL_TEXTURE_CUBE_MAP_POSITIVE_Z, or GL_TEXTURE_CUBE_MAP_NEGATIVE_Z.
		 * @param texture    Specifies the texture object whose image is to be attached. (the 
		 *                   handle returned by ffw::Texture::getHandle())
		 * @param level      Specifies the mipmap level of the texture image to be attached,
		 *                   which must be 0.
		 * @see ffw::Texture::getHandle
         */
        bool addTexture(GLenum attachment, GLuint textype, GLuint texture, GLint level = 0) const;
        /**
         * @brief Attach a renderbuffer object to a framebuffer object
         * @param attachment Specifies the attachment point to which renderbuffer should be 
         *                   attached. Must be one of the GL_COLOR_ATTACHMENT0, 
         *                   GL_DEPTH_ATTACHMENT, or GL_STENCIL_ATTACHMENT.
         * @param texture    Specifies the renderbuffer object that is to be attached. (the 
		 *                   handle returned by ffw::Renderbuffer::getHandle())
		 * @see ffw::Renderbuffer::getHandle
         */
        bool addRenderbuffer(GLenum attachment, GLuint texture) const;
        /**
         * @brief Attach a stencil texture to the framebuffer object
         * @param texture The texture that is to be attached.
         * @param level   The mipmap level, must be 0.
         */
        inline bool addStencilTexture(const ffw::Texture2D* texture, const GLint level = 0) {
            return addTexture(GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, texture->getHandle(), level);
        }
        /**
         * @brief Attach a stencil renderbuffer to the framebuffer object
         * @param texture The renderbuffer that is to be attached.
         * @param level   The mipmap level, must be 0.
         */
        inline bool addStencilBuffer(const ffw::Renderbuffer2D* texture) {
            return addRenderbuffer(GL_STENCIL_ATTACHMENT, texture->getHandle());
        }
        /**
         * @brief Attach a color texture to the framebuffer object
         * @param texture The texture that is to be attached.
         * @param level   The mipmap level, must be 0.
         */
        bool addColorTexture(const ffw::Texture2D* texture, const GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount, 
                GL_TEXTURE_2D, texture->getHandle(), level))return false;
            colorcount++;
            return true;
        }
        /**
         * @brief Attach a color cubemap texture to the framebuffer object
         * @param texture The texture that is to be attached.
         * @param side    The size of the cubemap to attach where 0 is positive X side followed by
         *                X negative (1), Y positive (2), Y negative (3), Z positive (4), 
         *                Z negative (5).
         * @param level   The mipmap level, must be 0.
         */
        bool addCubemapTexture(const ffw::TextureCubemap* texture, 
            const GLint side, const GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount, 
                GL_TEXTURE_CUBE_MAP_POSITIVE_X + side, texture->getHandle(), level))return false;
            colorcount++;
            return true;
        }
        /**
         * @brief Attach a depth texture to the framebuffer object
         * @param texture The texture that is to be attached.
         * @param level   The mipmap level, must be 0.
         */
        bool addDepthTexture(const ffw::Texture2D* texture, const GLint level = 0) {
            return addTexture(GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, 
                texture->getHandle(), level);
        }
        /**
         * @brief Attach a color multisample texture to the framebuffer object
         * @param texture The texture that is to be attached.
         * @param level   The mipmap level, must be 0.
         */
        bool addColorTextureMS(const ffw::Texture2DMS* texture, const GLint level = 0) {
            if (!addTexture(GL_COLOR_ATTACHMENT0 + colorcount, GL_TEXTURE_2D_MULTISAMPLE, 
                texture->getHandle(), level))return false;
            colorcount++;
            return true;
        }
        /**
         * @brief Attach a depth multisample texture to the framebuffer object
         * @param texture The texture that is to be attached.
         * @param level   The mipmap level, must be 0.
         */
        bool addDepthTextureMS(const ffw::Texture2DMS* texture, const GLint level = 0) {
            return addTexture(GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, 
                texture->getHandle(), level);
        }
        /**
         * @brief Attach a color renderbuffer to the framebuffer object
         * @param texture The renderbuffer that is to be attached.
         */
        bool addColorRenderbuffer(const ffw::Renderbuffer2D* texture) {
            if (!addRenderbuffer(GL_COLOR_ATTACHMENT0 + colorcount, 
                texture->getHandle()))return false;
            colorcount++;
            return true;
        }
        /**
         * @brief Attach a depth renderbuffer to the framebuffer object
         * @param texture The renderbuffer that is to be attached.
         */
        bool addDepthRenderbuffer(const ffw::Renderbuffer2D* texture) {
            return addRenderbuffer(GL_DEPTH_ATTACHMENT, texture->getHandle());
        }
        /**
         * @brief Attach a color multisample renderbuffer to the framebuffer object
         * @param texture The renderbuffer that is to be attached.
         */
        bool addColorRenderbufferMS(const ffw::Renderbuffer2DMS* texture) {
            if (!addRenderbuffer(GL_COLOR_ATTACHMENT0 + colorcount, 
                texture->getHandle()))return false;
            colorcount++;
            return true;
        }
        /**
         * @brief Attach a depth multisample renderbuffer to the framebuffer object
         * @param texture The renderbuffer that is to be attached.
         */
        bool addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* texture) {
            return addRenderbuffer(GL_DEPTH_ATTACHMENT, texture->getHandle());
        }
        /**
         * @brief Check the completeness status of a framebuffer
         */
        bool checkStatus();
        /**
         * @brief Returns the named object of the framebuffer (the handle)
         */
        inline unsigned int getHandle() const {
            return fbo;
        }
        /**
         * @brief Resets the color count of the color attachments
         */
        inline void resetColorCount() {
            colorcount = 0;
        }
        /**
         * @brief Destroys the framebuffer object
         */
        bool destroy();
        /**
         * @brief Binds the framebuffer object as GL_FRAMEBUFFER
         */
        void bind() const;
        /**
         * @brief Unbinds the framebuffer object by setting the current GL_FRAMEBUFFER to zero
         */
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
