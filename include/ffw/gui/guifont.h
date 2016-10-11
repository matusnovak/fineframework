/* This file is part of FineFramework project */
#ifndef FFW_GUI_FONT
#define FFW_GUI_FONT
#include "../config.h"
#include "../math.h"
namespace ffw {
	class GuiFont{
	public:
		virtual bool IsCreated() const = 0;
		virtual void Destroy() = 0;
		virtual ffw::Vec2i GetStringSize(const std::wstring& str) const = 0;
		virtual ffw::Vec2i GetStringSize(const std::string& str) const = 0;
		virtual int GetCharAdvance(wchar_t c) const = 0;
		virtual int GetLineHeight() const = 0;
	};
}
#endif
