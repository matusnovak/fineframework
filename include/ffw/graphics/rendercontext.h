/* This file is part of FineFramework project */
#ifndef FFW_RENDER_CONTEXT
#define FFW_RENDER_CONTEXT
#include "rendercollection.h"

namespace ffw {
	/**
	 * @ingroup graphics
	 */
    class FFW_API RenderContext {
    public:
		RenderContext();
		virtual ~RenderContext();
        virtual void* GetGlextFunc(const std::string& name) const = 0;
        virtual bool IsGlextFuncPresent(const std::string& name) const = 0;
		virtual RenderCollection* Renderer() = 0;
		virtual const RenderExtensions* Glext() const = 0;
    };
}
#endif
