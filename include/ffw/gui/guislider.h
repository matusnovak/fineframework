/* This file is part of FineFramework project */
#ifndef FFW_GUI_SLIDER
#define FFW_GUI_SLIDER
#include "guiwidget.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiSlider: public GuiWidget {
	public:
		GuiSlider(GuiWindow* context, bool vertical);
		virtual ~GuiSlider();
		bool IsVertical() const;
		void SetValue(int val);
		int GetValue() const;
		void SetBarSize(const ffw::Vec2<GuiUnits>& s);
		inline const ffw::Vec2<GuiUnits>& GetBarSize() const {
			return barSize;
		}
		const ffw::Vec2i& GetRange() const;
		void SetRange(int min, int max);
		void SetButtonSize(const ffw::Vec2<GuiUnits>& s);
		inline const ffw::Vec2<GuiUnits>& GetButtonSize() const {
			return buttonSize;
		}
		void SetInversed(bool inversed);
		bool GetInversed() const;
		ffw::Vec2i GetMinimumWrapSize() const override;
	protected:
		const GuiStyleGroup* styleButton;
		const GuiStyleGroup* styleBar;
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
		bool vertical;
		ffw::Vec2i range;
		int value;
		ffw::Vec2<GuiUnits> buttonSize;
		ffw::Vec2<GuiUnits> barSize;
		bool inverse;
	};
}
#endif
