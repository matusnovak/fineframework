/* This file is part of FineFramework project */
#ifndef FFW_GRAPHICS_RENDER_WINDOW
#define FFW_GRAPHICS_RENDER_WINDOW
#include "rendercontext.h"

namespace ffw {
	/**
	* @ingroup graphics
	*/
	class FFW_API RenderWindow: public RenderContext {
	public:
		virtual void SetPos(int posx, int posy) = 0;
		virtual void SetSize(int width, int height) = 0;
		virtual ffw::Vec2i GetPos() const = 0;
		virtual ffw::Vec2i GetSize() const = 0;
		virtual void Destroy() = 0;
		virtual bool ShouldRender() const = 0;
		virtual void RenderFrame() = 0;
		virtual void PoolEvents() = 0;
		virtual void WaitForEvents() = 0;
		virtual bool IsInitialized() const = 0;
		virtual void ShouldClose(bool close) = 0;
		virtual void Show() = 0;
		virtual void Hide() = 0;
		virtual void Iconify() = 0;
		virtual void Restore() = 0;
		virtual void Maximize() = 0;
		virtual void SetSingleBufferMode(bool enabled) = 0;
	};
};

#endif