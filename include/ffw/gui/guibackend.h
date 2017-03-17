/* This file is part of FineFramework project */
#ifndef FFW_GUI_BACKEND
#define FFW_GUI_BACKEND
#include "../config.h"
#include "../math.h"
#include "guitheme.h"
#include "guifont.h"
namespace ffw {
	class GuiFont;
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiBackend {
	public:
		// The following must be implemented!
		virtual void resize(int width, int height) = 0;
		virtual void startRender() = 0;
		virtual void endRender() = 0;
		virtual void setScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const = 0;
		virtual void clearWithColor(const ffw::Color& color) const = 0;

		// The following basic drawing functions must be implemented!
		virtual void drawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color) const = 0;
		virtual void drawRectangleRounded(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color, int tl, int tr, int br, int bl) const = 0;
		virtual void drawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, const ffw::Color& color) const = 0;
		virtual void drawCircle(const ffw::Vec2i& pos, int radius, const ffw::Color& color) const = 0;
		virtual void drawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, const ffw::Color& color) const = 0;
		virtual void drawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3, const ffw::Color& color) const = 0;
		virtual void drawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const = 0;
		virtual void drawTriangle(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Color& color) const = 0;
		virtual void drawImage(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const = 0;

		inline void drawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring& str, const ffw::Color& color, float lineHeight = 1.25f) const {
			drawString(pos, font, &str[0], str.size(), color, lineHeight);
		}

		// The following can be overriden
		virtual void drawBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle::Background& background, bool ignore = false) const;
		virtual void drawBorder(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle::Border& border) const;
		virtual void drawStringAligned(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiFont* font, ffw::GuiStyle::Align align, const std::wstring& str, const ffw::GuiStyle::Text& text, float lineHeight = 1.25f) const;
	};
}
#endif
