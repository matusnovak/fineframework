/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_FRAMEBUFFER
#define FFW_GRAPHICS_FRAMEBUFFER
#include "../config.h"
#include "texture2d.h"
#include "texture2dms.h"
#include "renderbuffer2d.h"
#include "renderbuffer2dms.h"

namespace ffw {
    class RenderContext;
	/**
	 * @ingroup graphics
	 */
	class FFW_API Framebuffer {
    public:
        static bool CheckCompability(const RenderContext* Renderer);
		Framebuffer();
        ~Framebuffer();
        inline bool IsCreated() const {
			return created_;
		}
        bool Create(const RenderContext* Renderer);
        bool AddColorTexture(const ffw::Texture2D* DepthTexture);
        bool AddDepthTexture(const ffw::Texture2D* ColorTexture);
        bool AddColorTextureMS(const ffw::Texture2DMS* DepthTexture);
        bool AddDepthTextureMS(const ffw::Texture2DMS* ColorTexture);
        bool AddColorRenderbuffer(const ffw::Renderbuffer2D* DepthTexture);
        bool AddDepthRenderbuffer(const ffw::Renderbuffer2D* ColorTexture);
        bool AddColorRenderbufferMS(const ffw::Renderbuffer2DMS* DepthTexture);
        bool AddDepthRenderbufferMS(const ffw::Renderbuffer2DMS* ColorTexture);
		bool CheckStatus();
		inline unsigned int GetHandle() const {
			return fbo_;
		}
        bool Destroy();
        void Bind() const;
        void Unbind() const;
    private:
        bool created_;
        unsigned int fbo_;
		int colorcount_;
        const RenderExtensions* gl_;
    };
};
#endif
