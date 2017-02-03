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
		void SetValue(const std::wstring& str);
		std::wstring GetValue() const;
		ffw::Vec2i GetMinimumWrapSize() override;
		bool IsEmpty() const;
		class Limit {
		public:
			inline static Limit Range(wchar_t from, wchar_t to) {
				return Limit(from, to);
			}
			inline static Limit Single(wchar_t chr) {
				return Limit(chr, '\0');
			}
			inline Limit(wchar_t from, wchar_t to) :first(from), last(to) {
			}
			inline bool IsValid(wchar_t chr) const {
				if (last == '\0')return chr == first;
				else return chr >= first && chr <= last;
			}
		private:
			wchar_t first;
			wchar_t last;
		};
		inline void AddLimit(const GuiTextInput::Limit& limit) {
			limits.push_back(limit);
		}
		inline void RemoveLimits() {
			limits.clear();
		}
		inline void AddRangeLimit(wchar_t from, wchar_t to) {
			limits.push_back(GuiTextInput::Limit::Range(from, to));
		}
		inline void AddSingleLimit(wchar_t chr) {
			limits.push_back(GuiTextInput::Limit::Single(chr));
		}
		inline void AddListOfLimits(const std::initializer_list<wchar_t>& list) {
			for (const auto& item : list) {
				limits.push_back(GuiTextInput::Limit::Single(item));
			}
		}
	private:
		class TextLine {
		public:
			TextLine(const std::wstring& s);
			const std::wstring& Get() const;
			const std::vector<size_t>& Tokens() const;
			void SetText(const std::wstring& s);
			void Recalculate(const ffw::GuiFont* font, int width, bool ignore);
			void InsertAt(size_t pos, wchar_t chr);
			void RemoveAt(size_t pos);
			void Append(const std::wstring& str);
			inline size_t GetNumOfTokens() const {
				return tokens.size();
			}
		private:
			std::wstring str;
			std::vector<size_t> tokens;
		};
		void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void EventPos(const ffw::Vec2i& pos) override;
		void EventSize(const ffw::Vec2i& size) override;
		void EventHover(bool gained) override;
		void EventFocus(bool gained) override;
		void EventMouse(const ffw::Vec2i& pos) override;
		void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void EventText(wchar_t chr) override;
		void EventKey(ffw::Key key, ffw::Mode mode) override;
		void EventDisabled(bool disabled) override;
		void EventThemeChanged(const GuiTheme* theme) override;

		std::pair<ffw::Vec2i, ffw::Vec2i> CalculateCursor(const ffw::Vec2i& mouse);
		ffw::Vec2i CalculateCursorPos(const ffw::Vec2i& index);
		void InsertAtCurrent(wchar_t chr);
		void RemoveAtCurrent(int offset);
		void SplitAtCurrent();
		void ReplaceSection(ffw::Vec2i beg, ffw::Vec2i end, const std::wstring& s);
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
		std::vector<GuiTextInput::Limit> limits;
	};

	class FFW_API GuiTextArea : public GuiScrollable {
	public:
		class Inner : public GuiTextInput {
		public:
			Inner(GuiWindow* context, bool editable);
			virtual ~Inner();
			void EventThemeChanged(const GuiTheme* theme) override;
		};

		GuiTextArea(GuiWindow* context, bool editable = true);
		virtual ~GuiTextArea();
		inline void SetValue(const std::wstring& str) {
			textinput->SetValue(str);
		}
		inline std::wstring GetValue() const {
			return textinput->GetValue();
		}
		void EventThemeChanged(const GuiTheme* theme) override;
	private:
		GuiTextInput* textinput;
	};
}
#endif
