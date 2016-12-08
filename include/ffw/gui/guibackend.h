/* This file is part of FineFramework project */
#ifndef FFW_GUI_BACKEND
#define FFW_GUI_BACKEND
#include "../config.h"
#include "../math.h"
namespace ffw {
	class GuiFont;
	/**
	 * @ingroup gui
	 */
	class GuiBackend {
	public:
		virtual void Resize(int width, int height) = 0;
		virtual GuiFont* CreateFontFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0xFF) const = 0;
		virtual GuiFont* CreateFontFromFile(const std::string& path, int points, int dpi, int start = 0x00, int end = 0xFF) const = 0;
		virtual void StartRender() = 0;
		virtual void EndRender() = 0;
		virtual void SetScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const = 0;
		virtual void ClearWithColor(const ffw::Color& color) const = 0;
		virtual void SetDrawColor(const ffw::Color& color) const = 0;
		virtual void DrawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3) const = 0;
		virtual void DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size) const = 0;
		virtual void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring& str, size_t beg = 0, size_t len = -1) const = 0;
		virtual void DrawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, int thickness) const = 0;
		virtual void DrawCircle(const ffw::Vec2i& pos, int radius, int steps) const = 0;
		virtual void DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, int steps) const = 0;
		virtual void DrawTriangleFan(const ffw::Vec2i* arr, int num) const = 0;
	};
}
#endif
