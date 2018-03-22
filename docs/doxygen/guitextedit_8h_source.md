---
search: false
---

# guitextedit.h File Reference

**[Go to the documentation of this file.](guitextedit_8h.md)**
Source: `include/ffw/gui/guitextedit.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GUI_TEXT_EDIT
#define FFW_GUI_TEXT_EDIT
#include <list>
#include "guiwidget.h"
#include "guiscrollable.h"
#include <regex>

namespace ffw {
    class FFW_API GuiTextInput : public GuiWidget {
    public:
        struct Style {
            GuiWidget::Style self;
        };

        struct Line {
            std::string str;
            float height;
        };

        GuiTextInput(GuiWindow* context, bool multiline = true, bool editable = true);
        virtual ~GuiTextInput() = default;
        void setValue(const std::string& str);
        std::string getValue() const;
        void appendValue(const std::string& str);
        bool setCursorIndex(size_t strOffset, size_t lineNum);
        inline const std::regex& getMatch() const {
            return regexMatch;
        }
        inline void setMatch(const std::regex& r) {
            regexMatch = r;
        }
        inline void setMatch(const std::string& r) {
            regexMatch = std::regex(r);
        }
        inline const std::vector<Line>& getLines() const {
            return lines;
        }
        ffw::Vec2f getMinimumWrapSize() override;
        inline bool isEmpty() const {
            return lines.empty() || (lines.empty() && lines.front().str.empty());
        }
        void setStyle(const GuiTextInput::Style* style, bool defaults = false);
        inline const ffw::Vec2<size_t>& getCursorIndex() const {
            return cursorIndex;
        }
        inline const ffw::Vec2f& getCursorPos() const {
            return cursorPos;
        }
        void insertAtCursor(const std::string& str);
        void removeAtCursor(bool forward);
        void moveCursor(bool forward);
        void splitLineAtCursor();
        void resetSelection();
        void moveCursorToEnd();
        void moveCursorToStart();
        void deleteSelection();
        inline bool hasSelection() const {
            return cursorIndex != selectionIndex;
        }
    private:
        void pushActionEvent();
        int getSelectionNumOfLines() const;
        void recalculateLine(Line& line, float width) const;
        std::pair<ffw::Vec2f, ffw::Vec2<size_t>> getCursorIndex(const ffw::Vec2f& mouse);
        float calculateHeight() const;
        ffw::Vec2f getCursorPos(const ffw::Vec2<size_t>& index);
        void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
        void eventSize(const ffw::Vec2f& size) override;
        void eventHover(bool gained) override;
        void eventFocus(bool gained) override;
        void eventMouse(const ffw::Vec2f& pos) override;
        bool eventScroll(const ffw::Vec2f& scroll) override;
        void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
        void eventText(uint32_t chr) override;
        void eventKey(ffw::Key key, ffw::Mode mode) override;
        void eventThemeChanged(const GuiTheme* theme, bool defaults) override;

        const bool multiline;
        float lastCalculatedSize;
        float lastCalculatedHeight;
        std::vector<Line> lines;
        ffw::Vec2<size_t> cursorIndex;
        ffw::Vec2f cursorPos;
        ffw::Vec2<size_t> selectionIndex;
        ffw::Vec2f selectionPos;
        bool hasCtrl;
        bool hasMouseDown;
        std::regex regexMatch;
    };

    class FFW_API GuiScrollableTextInput : public GuiScrollable {
    public:
        class Inner : public GuiTextInput {
        public:
            struct Style {
                GuiTextInput::Style self;
            };

            Inner(GuiWindow* context, bool editable);
            virtual ~Inner() = default;
            void setStyle(const Inner::Style* style, bool defaults = false);
        private:
            void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        };

        struct Style {
            GuiScrollable::Style self;
            GuiScrollableTextInput::Inner::Style inner;
        };

        GuiScrollableTextInput(GuiWindow* context, bool editable = true);
        virtual ~GuiScrollableTextInput() = default;
        inline const GuiTextInput* getInner() const {
            return dynamic_cast<const GuiTextInput*>(getInnerAsWidget());
        }
        inline GuiTextInput* getInner() {
            return dynamic_cast<GuiTextInput*>(getInnerAsWidget());
        }
        inline void setValue(const std::string& str) {
            getInner()->setValue(str);
        }
        inline std::string getValue() const {
            return getInner()->getValue();
        }
        inline void appendValue(const std::string& str) {
            getInner()->appendValue(str);
        }
        inline const std::vector<GuiTextInput::Line>& getLines() const {
            return getInner()->getLines();
        }
        inline bool isEmpty() const {
            return getInner()->isEmpty();
        }
        void setStyle(const GuiScrollableTextInput::Style* style, bool defaults = false);
    private:
        void eventThemeChanged(const GuiTheme* theme, bool defaults) override;
        GuiScrollableTextInput::Inner* textinput;
    };
}
#endif
```


    
  
