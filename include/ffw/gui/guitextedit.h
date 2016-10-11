/* This file is part of FineFramework project */
#ifndef FFW_GUI_TEXT_EDIT
#define FFW_GUI_TEXT_EDIT
#include "guiwidget.h"
namespace ffw {
	class FFW_API GuiTextEdit: public GuiWidget {
	public:
		GuiTextEdit(GuiWindow* context, const std::string& str, bool multiline = false, bool editable = true);
		virtual ~GuiTextEdit();
		void SetValue(const std::string& str);
		const std::string& GetValue() const;
		ffw::Vec2i GetMinimumWrapSize() const override;
	private:
		void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void EventPos(const ffw::Vec2i& pos) override;
		void EventSize(const ffw::Vec2i& size) override;
		void EventHover(bool gained) override;
		void EventFocus(bool gained) override;
		void EventMouse(const ffw::Vec2i& pos) override;
		void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void EventText(wchar_t chr) override;
		void EventKey(ffw::Key key, ffw::Mode mode) override;
		void RecalculateCursor(bool frommousepos);
		std::string text;
		ffw::Vec2i cursor;
		size_t start;
		bool multi;
	};
	class GuiTextArea: public GuiTextEdit {
	public:
		GuiTextArea(GuiWindow* context, const std::string& str, bool editable = true):GuiTextEdit(context, str, true, editable){}
	};
	class GuiTextInput: public GuiTextEdit {
	public:
		GuiTextInput(GuiWindow* context, const std::string& str, bool editable = true):GuiTextEdit(context, str, false, editable){}
	};
}
#endif
