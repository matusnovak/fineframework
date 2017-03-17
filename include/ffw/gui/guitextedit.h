/* This file is part of FineFramework project */
#ifndef FFW_GUI_TEXT_EDIT
#define FFW_GUI_TEXT_EDIT
#include "guiwidget.h"
#include "guiscrollable.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiTextInput : public GuiWidget {
	public:
		GuiTextInput(GuiWindow* context, bool multiline = false, bool editable = true);
		virtual ~GuiTextInput();
		void setValue(const std::wstring& str);
		std::wstring getValue() const;
		ffw::Vec2i getMinimumWrapSize() override;
		bool isEmpty() const;
		inline void setMatch(const std::wstring& match) {
			regexStr = match;
		}
		inline const std::wstring& getMatch() const {
			return regexStr;
		}
	private:
		class TextLine {
		public:
			TextLine(const std::wstring& s);
			const std::wstring& get() const;
			const std::vector<size_t>& Tokens() const;
			void setText(const std::wstring& s);
			void recalculate(const ffw::GuiFont* font, int width, bool ignore);
			void insertAt(size_t pos, wchar_t chr);
			void removeAt(size_t pos);
			void append(const std::wstring& str);
			inline size_t getNumOfTokens() const {
				return tokens.size();
			}
		private:
			std::wstring str;
			std::vector<size_t> tokens;
		};
		void eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void eventPos(const ffw::Vec2i& pos) override;
		void eventSize(const ffw::Vec2i& size) override;
		void eventHover(bool gained) override;
		void eventFocus(bool gained) override;
		void eventMouse(const ffw::Vec2i& pos) override;
		void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void eventText(wchar_t chr) override;
		void eventKey(ffw::Key key, ffw::Mode mode) override;
		void eventDisabled(bool disabled) override;
		void eventThemeChanged(const GuiTheme* theme) override;

		std::pair<ffw::Vec2i, ffw::Vec2i> calculateCursor(const ffw::Vec2i& mouse);
		ffw::Vec2i calculateCursorPos(const ffw::Vec2i& index);
		void insertAtCurrent(wchar_t chr);
		void removeAtCurrent(int offset);
		void splitAtCurrent();
		void replaceSection(ffw::Vec2i beg, ffw::Vec2i end, const std::wstring& s);
		std::vector<TextLine> lines;
		int linesLastWidth;
		bool mousedown;
		bool multi;
		bool ignoreFirst;
		bool selection;
		ffw::Vec2i cursorPos;
		ffw::Vec2i cursorPosEnd;
		ffw::Vec2<size_t> cursorIndex;
		ffw::Vec2<size_t> cursorIndexEnd;
		std::wstring regexStr;
	};

	class FFW_API GuiTextArea : public GuiScrollable {
	public:
		class Inner : public GuiTextInput {
		public:
			Inner(GuiWindow* context, bool editable);
			virtual ~Inner();
			void eventThemeChanged(const GuiTheme* theme) override;
		};

		GuiTextArea(GuiWindow* context, bool editable = true);
		virtual ~GuiTextArea();
		inline void setValue(const std::wstring& str) {
			textinput->setValue(str);
		}
		inline std::wstring getValue() const {
			return textinput->getValue();
		}
		void eventThemeChanged(const GuiTheme* theme) override;
	private:
		GuiTextInput* textinput;
	};
}
#endif
