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
			void eventThemeChanged(const GuiTheme* theme) override;
			virtual ~GuiBody();
		};
		GuiWindow();
		virtual ~GuiWindow();
		void setSize(int width, int height);
		void setPos(int posx, int posy);
		const ffw::Vec2i& getSize() const;
		const ffw::Vec2i& getPos() const;
		void setDefaultFont(const GuiFont* font);
		const GuiFont* getDefaultFont() const;
		void injectMousePos(int posx, int posy);
		void injectMouseButton(ffw::MouseButton button, ffw::Mode mode);
		void injectText(wchar_t chr);
		void injectKey(ffw::Key key, ffw::Mode mode);
		void update();
		void poolEvents();
		void render();
		void redraw();
		void invalidate();
		GuiBody* getLayout() {
			return body;
		}
		const GuiBody* getLayout() const {
			return body;
		}
		void pushEvent(GuiCallback& callback, GuiEvent e);
		void setTheme(const GuiTheme* thm);
		const GuiTheme* getTheme() const;
		template<class T>
		T* findByID(unsigned long id){
			return body->findByID<T>(id);
		}
	private:
		GuiBody* body;
		const GuiTheme* theme;
		ffw::Vec2i size;
		ffw::Vec2i pos;
		GuiUserInput input;
		const GuiFont* defaultfont;
		std::queue<std::pair<std::function<void(GuiEvent)>, GuiEvent>> eventqueue;
		ffw::Vec2i mousepos;
	};
}
#endif
