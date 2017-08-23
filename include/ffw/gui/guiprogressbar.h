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
		ffw::Vec2f getMinimumWrapSize() override;
		inline void setValue(float value) {
			percent = ffw::clamp(value, 0.0f, 100.0f);
			redraw();
		}
		inline float getValue() const {
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
		void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override;
		void eventPos(const ffw::Vec2f& pos) override;
		void eventSize(const ffw::Vec2f& size) override;
		void eventHover(bool gained) override;
		void eventFocus(bool gained) override;
		void eventMouse(const ffw::Vec2f& pos) override;
		bool eventScroll(const ffw::Vec2f& scroll) override;
		void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void eventText(wchar_t chr) override;
		void eventKey(ffw::Key key, ffw::Mode mode) override;
		void eventDisabled(bool disabled) override;
		virtual void eventThemeChanged(const GuiTheme* theme) override;
		float percent;
	};
}
#endif
