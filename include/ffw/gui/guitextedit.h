/* This file is part of FineFramework project */
#ifndef FFW_GUI_TEXT_EDIT
#define FFW_GUI_TEXT_EDIT
#include "guiwidget.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiTextEdit: public GuiWidget {
	public:
		GuiTextEdit(GuiWindow* context, const std::string& str, bool multiline = false, bool editable = true);
		GuiTextEdit(GuiWindow* context, const std::wstring& str, bool multiline = false, bool editable = true);
		virtual ~GuiTextEdit();
		void SetValue(const std::wstring& str);
		std::wstring GetValue() const;
		ffw::Vec2i GetMinimumWrapSize() const override;
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
		std::pair<ffw::Vec2i, ffw::Vec2i> CalculateCursor(const ffw::Vec2i& mouse);
		ffw::Vec2i CalculateCursorPos(const ffw::Vec2i& index);
		void InsertAtCurrent(wchar_t chr);
		void RemoveAtCurrent(int offset);
		void SplitAtCurrent();
		void ReplaceSection(ffw::Vec2i beg, ffw::Vec2i end, const std::wstring& s);
		int GetLineHeight() const;
		std::vector<TextLine> lines;
		bool mousedown;
		bool multi;
		int lineHeight;
		bool ignoreFirst;
		bool selection;
		ffw::Vec2i cursorPos;
		ffw::Vec2i cursorPosEnd;
		ffw::Vec2i cursorIndex;
		ffw::Vec2i cursorIndexEnd;
	};
}
#endif
