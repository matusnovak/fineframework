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
		ffw::Vec2i GetMinimumWrapSize() override;
		inline void SetValue(int value) {
			percent = ffw::Clamp(value, 0, 100);
			Redraw();
		}
		inline int GetValue() const {
			return percent;
		}
		void SetInnerStyleGroup(const GuiStyleGroup* style) {
			innerStyle = style;
			Redraw();
		}
		const GuiStyleGroup* GetInnerStyleGroup() const  {
			return innerStyle;
		}
	protected:
		const GuiStyleGroup* innerStyle;
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
		int percent;
	};
}
#endif
