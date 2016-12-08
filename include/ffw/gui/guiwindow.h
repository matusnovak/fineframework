/* This file is part of FineFramework project */
#ifndef FFW_GUI_WINDOW
#define FFW_GUI_WINDOW
#include "guibackend.h"
#include "guilayout.h"
#include "guifont.h"
#include <queue>
#include <functional>
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiWindow {
	public:
		GuiWindow();
		virtual ~GuiWindow();
		void SetSize(int width, int height);
		void SetPos(int posx, int posy);
		void Destroy();
		void SetBackend(GuiBackend* backend);
		const ffw::Vec2i& GetSize() const;
		const ffw::Vec2i& GetPos() const;
		GuiFont* CreateFontFromData(const unsigned char* buffer, size_t length, int points, int dpi, int start = 0x00, int end = 0xFF) const;
		GuiFont* CreateFontFromFile(const std::string& path, int points, int dpi, int start = 0x00, int end = 0xFF) const;
		void SetScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const;
		void ClearWithColor(const ffw::Color& color) const;
		void SetDrawColor(const ffw::Color& color) const;
		void DrawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3) const;
		void DrawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size) const;
		void DrawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring& str, size_t beg = 0, size_t len = -1) const;
		void DrawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, int thickness) const;
		void DrawCircle(const ffw::Vec2i& pos, int radius, int steps) const;
		void DrawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, int steps) const;
		void DrawTriangleFan(const ffw::Vec2i* arr, int num) const;
		void DrawStringAligned(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiFont* font, GuiAlign align, const std::wstring& str) const;
		void DrawBorder(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiStyle& style) const;
		void DrawBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size, const GuiStyle& style) const;
		void DrawSymbol(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiSymbol& symbol) const;
		void SetDefaultFont(const GuiFont* font);
		const GuiFont* GetDefaultFont() const;
		void InjectMousePos(int posx, int posy);
		void InjectMouseButton(ffw::MouseButton button, ffw::Mode mode);
		void InjectText(wchar_t chr);
		void InjectKey(ffw::Key key, ffw::Mode mode);
		void Update();
		void PoolEvents();
		void Render();
		void Redraw();
		void Invalidate();
		void DeleteWidgets();
		void AddWidget(GuiWidget* widget);
		void PushEvent(std::function<void(GuiEvent)> callback, GuiEvent e);
		void SetPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		void SetPadding(GuiUnits all);
		template<class T>
		T* FindByID(unsigned long id){
			return body->FindByID<T>(id);
		}
	private:
		GuiLayout* body;
		GuiBackend* backend;
		ffw::Vec2i size;
		ffw::Vec2i pos;
		GuiUserInput input;
		const GuiFont* defaultfont;
		std::queue<std::pair<std::function<void(GuiEvent)>, GuiEvent>> eventqueue;
	};
}
#endif
