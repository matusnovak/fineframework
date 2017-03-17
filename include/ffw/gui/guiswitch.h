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
		void setValue(bool value);
		bool getValue() const;
		ffw::Vec2i getMinimumWrapSize() override;
	protected:
		const GuiStyleGroup* styleButton;
	private:
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
		virtual void eventThemeChanged(const GuiTheme* theme) override;
	};
}
#endif
