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
        static bool checkCompability(const RenderContext* Renderer);
		Framebuffer();
		Framebuffer(const Framebuffer& other) = delete;
		Framebuffer(Framebuffer&& other);
		void swap(Framebuffer& other);
        ~Framebuffer();
        inline bool isCreated() const {
			return created_;
		}
        bool create(const RenderContext* Renderer);
        bool addColorTexture(const ffw::Texture2D* texture, int mip = 0);
		bool addCubemapTexture(const ffw::TextureCubemap* texture, int side, int mip = 0);
        bool addDepthTexture(const ffw::Texture2D* texture, int mip = 0);
        bool addColorTextureMS(const ffw::Texture2DMS* texture, int mip = 0);
        bool addDepthTextureMS(const ffw::Texture2DMS* texture, int mip = 0);
        bool addColorRenderbuffer(const ffw::Renderbuffer2D* texture);
        bool addDepthRenderbuffer(const ffw::Renderbuffer2D* texture);
        bool addColorRenderbufferMS(const ffw::Renderbuffer2DMS* texture);
        bool addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* texture);
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
