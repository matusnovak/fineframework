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
	class FFW_API GuiWindow: public GuiBackend {
	public:
		class FFW_API GuiBody: public GuiLayout {
		public:
			GuiBody(GuiWindow* context, GuiLayout::Orientation orient);
			virtual ~GuiBody();
		};
		GuiWindow();
		virtual ~GuiWindow();
		void SetSize(int width, int height);
		void SetPos(int posx, int posy);
		void Destroy();
		const ffw::Vec2i& GetSize() const;
		const ffw::Vec2i& GetPos() const;
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
		inline void AddWidget(GuiWidget* widget) {
			body->AddWidget(widget);
		}
		inline void AddWidgetAfter(const GuiWidget* previous, GuiWidget* widget) {
			body->AddWidgetAfter(previous, widget);
		}
		inline void AddWidgetBefore(const GuiWidget* next, GuiWidget* widget) {
			body->AddWidgetBefore(next, widget);
		}
		inline void DeleteWidgets() {
			body->DeleteWidgets();
		}
		inline bool DeleteSingleWidget(GuiWidget* widget) {
			return body->DeleteSingleWidget(widget);
		}
		inline void SetWrap(bool wrap) {
			body->SetWrap(wrap);
		}
		inline void SetOrientation(GuiLayout::Orientation orientation) {
			body->SetOrientation(orientation);
		}
		void PushEvent(GuiCallback& callback, GuiEvent e);
		void SetPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		void SetPadding(GuiUnits all);
		void SetTheme(const GuiTheme* thm);
		const GuiTheme* GetTheme() const;
		template<class T>
		T* FindByID(unsigned long id){
			return body->FindByID<T>(id);
		}
	private:
		GuiBody* body;
		const GuiTheme* theme;
		ffw::Vec2i size;
		ffw::Vec2i pos;
		GuiUserInput input;
		const GuiFont* defaultfont;
		std::queue<std::pair<std::function<void(GuiEvent)>, GuiEvent>> eventqueue;
	};
}
#endif
