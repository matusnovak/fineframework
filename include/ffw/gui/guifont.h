/* This file is part of FineFramework project */
#ifndef FFW_GUI_FONT
#define FFW_GUI_FONT
#include "../config.h"
#include "../math.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class GuiFont{
	public:
		virtual bool IsCreated() const = 0;
		virtual void Destroy() = 0;
		virtual ffw::Vec2i GetStringSize(const std::wstring& str, float lineHeight = 1.25) const = 0;
		virtual ffw::Vec2i GetStringSize(const std::string& str, float lineHeight = 1.25) const = 0;
		virtual int GetCharAdvance(wchar_t c) const = 0;
		virtual int GetSizeInPixels() const = 0;
	};
}
#endif
