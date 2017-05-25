/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FRAMEBUFFER
#define FFW_GRAPHICS_FRAMEBUFFER
#include "../config.h"
#include "texture2d.h"
#include "texture2dms.h"
#include "renderbuffer2d.h"
#include "renderbuffer2dms.h"

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
        bool addColorTexture(const ffw::Texture2D* DepthTexture);
        bool addDepthTexture(const ffw::Texture2D* ColorTexture);
        bool addColorTextureMS(const ffw::Texture2DMS* DepthTexture);
        bool addDepthTextureMS(const ffw::Texture2DMS* ColorTexture);
        bool addColorRenderbuffer(const ffw::Renderbuffer2D* DepthTexture);
        bool addDepthRenderbuffer(const ffw::Renderbuffer2D* ColorTexture);
        bool addColorRenderbufferMS(const ffw::Renderbuffer2DMS* DepthTexture);
        bool addDepthRenderbufferMS(const ffw::Renderbuffer2DMS* ColorTexture);
		bool checkStatus();
		inline unsigned int getHandle() const {
			return fbo_;
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
