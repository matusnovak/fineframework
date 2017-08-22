/* This file is part of FineFramework project */
#ifndef FFW_GUI_FONT
#define FFW_GUI_FONT
#include "../config.h"
#include "../math/vec2.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class GuiFont{
	public:
		virtual bool isCreated() const = 0;
		virtual void destroy() = 0;
		virtual ffw::Vec2f getStringSize(const std::wstring& str, float lineHeight = 1.25) const = 0;
		virtual ffw::Vec2f getStringSize(const std::string& str, float lineHeight = 1.25) const = 0;
		virtual float getCharAdvance(wchar_t c) const = 0;
		virtual int getSizeInPixels() const = 0;
	};
}
#endif
