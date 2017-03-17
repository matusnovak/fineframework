/* This file is part of FineFramework project */
#ifndef FFW_GUI_PROGRESSBAR
#define FFW_GUI_PROGRESSBAR
#include "guiwidget.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiProgressBar : public GuiWidget {
	public:
		GuiProgressBar(GuiWindow* context);
		virtual ~GuiProgressBar();
		ffw::Vec2i getMinimumWrapSize() override;
		inline void setValue(int value) {
			percent = ffw::clamp(value, 0, 100);
			redraw();
		}
		inline int getValue() const {
			return percent;
		}
		void setInnerStyleGroup(const GuiStyleGroup* style) {
			innerStyle = style;
			redraw();
		}
		const GuiStyleGroup* getInnerStyleGroup() const  {
			return innerStyle;
		}
	protected:
		const GuiStyleGroup* innerStyle;
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
		int percent;
	};
}
#endif
