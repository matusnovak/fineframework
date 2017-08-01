/* This file is part of FineFramework project */
#ifndef FFW_GUI_FONT_OPENGL
#define FFW_GUI_FONT_OPENGL
#include "guifont.h"
namespace ffw {
	class RenderContext;
	/**
	 * @ingroup gui
	 */
	class GuiFontOpenGL: public GuiFont, public TrueTypeFont {
	public:
		inline bool isCreated() const override {
			return TrueTypeFont::isCreated();
		}
		inline void destroy() override {
			TrueTypeFont::destroy();
		}
		inline ffw::Vec2i getStringSize(const std::wstring& str, float lineHeight = 1.25) const override {
			return TrueTypeFont::getStringSize(str, lineHeight);
		}
		inline ffw::Vec2i getStringSize(const std::string& str, float lineHeight = 1.25) const override {
			return TrueTypeFont::getStringSize(str, lineHeight);
		}
		inline int getCharAdvance(wchar_t c) const override {
			return (int)TrueTypeFont::getChar(c).advance;
		}
		inline int getSizeInPixels() const override {
			return TrueTypeFont::getSizePixels();
		}
	};
}
#endif