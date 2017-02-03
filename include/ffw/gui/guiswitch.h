/* This file is part of FineFramework project */
#ifndef FFW_GUI_SWITCH
#define FFW_GUI_SWITCH
#include "guiwidget.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiSwitch : public GuiWidget {
	public:
		GuiSwitch(GuiWindow* context);
		virtual ~GuiSwitch();
		void SetValue(bool value);
		bool GetValue() const;
		ffw::Vec2i GetMinimumWrapSize() override;
	protected:
		const GuiStyleGroup* styleButton;
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
	};
}
#endif
