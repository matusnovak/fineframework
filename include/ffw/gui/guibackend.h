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
		virtual void Resize(int width, int height) = 0;
		virtual GuiFont* CreateFontFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0xFF) const = 0;
		virtual GuiFont* CreateFontFromFile(const std::string& path, int points, int dpi, int start = 0x00, int end = 0xFF) const = 0;
		virtual void StartRender() = 0;
		virtual void EndRender() = 0;
		virtual void SetScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const = 0;
		virtual void ClearWithColor(const ffw::Color& color) const = 0;

		// The following basic drawing functions must be implemented!
		virtual void DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color) const = 0;
		virtual void DrawRectangleRounded(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color, int tl, int tr, int br, int bl) const = 0;
		virtual void DrawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, const ffw::Color& color) const = 0;
		virtual void DrawCircle(const ffw::Vec2i& pos, int radius, const ffw::Color& color) const = 0;
		virtual void DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, const ffw::Color& color) const = 0;
		virtual void DrawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3, const ffw::Color& color) const = 0;
		virtual void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const = 0;

		inline void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring& str, const ffw::Color& color, float lineHeight = 1.25f) const {
			DrawString(pos, font, &str[0], str.size(), color, lineHeight);
		}

		// The following can be overriden
		virtual void DrawBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle::Background& background, bool ignore = false) const;
		virtual void DrawBorder(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle::Border& border) const;
		virtual void DrawStringAligned(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiFont* font, ffw::GuiStyle::Align align, const std::wstring& str, const ffw::GuiStyle::Text& text, float lineHeight = 1.25f) const;
	};
}
#endif
