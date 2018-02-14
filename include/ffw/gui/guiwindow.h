/* This file is part of FineFramework project */
#ifndef FFW_GUI_WINDOW
#define FFW_GUI_WINDOW
#include "guibackend.h"
#include "guilayout.h"
#include "guifont.h"
#include "guibody.h"
#include <queue>
#include <functional>

namespace ffw {
    class GuiBody;
    /**
     * @ingroup gui
     */
    class FFW_API GuiWindow: public GuiBackend {
    public:
        GuiWindow();
        virtual ~GuiWindow();
        void setSize(float width, float height);
        void setPos(float posx, float posy);
        const ffw::Vec2f& getSize() const;
        const ffw::Vec2f& getPos() const;
        void setDefaultFont(const GuiFont* font);
        const GuiFont* getDefaultFont() const;
        void injectMousePos(float posx, float posy);
        void injectScroll(float posx, float posy);
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
        void pushEvent(std::vector<GuiCallback>& callbacks, GuiEvent e);
        void setTheme(const GuiTheme* thm, bool defaults = false);
        const GuiTheme* getTheme() const;
        template<class T>
        T* findByID(unsigned long id){
            return body->findByID<T>(id);
        }
    private:
        GuiBody* body;
        const GuiTheme* theme;
        ffw::Vec2f size;
        ffw::Vec2f pos;
        GuiUserInput input;
        const GuiFont* defaultfont;
        std::queue<std::pair<std::function<void(GuiEvent)>, GuiEvent>> eventqueue;
        ffw::Vec2f mousepos;
    };
}
#endif
