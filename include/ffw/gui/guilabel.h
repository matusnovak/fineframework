/* This file is part of FineFramework project */
#ifndef FFW_GUI_LABEL
#define FFW_GUI_LABEL
#include "guiwidget.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiLabel: public GuiWidget {
	public:
		GuiLabel(GuiWindow* context, const std::string& label);
		GuiLabel(GuiWindow* context, const std::wstring& label);
		virtual ~GuiLabel();
		void SetLabel(const std::wstring& label);
		const std::wstring& GetLabel() const;
		ffw::Vec2i GetMinimumWrapSize() override;
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
		void EventDisabled(bool disabled) override;
		virtual void EventThemeChanged(const GuiTheme* theme) override;
		std::wstring label;
	};
}
#endif
