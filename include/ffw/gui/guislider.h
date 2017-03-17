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
		bool isVertical() const;
		void setValue(int val);
		int getValue() const;
		void setBarSize(const ffw::Vec2<GuiUnits>& s);
		inline const ffw::Vec2<GuiUnits>& getBarSize() const {
			return barSize;
		}
		const ffw::Vec2i& getRange() const;
		void setRange(int min, int max);
		void setButtonSize(const ffw::Vec2<GuiUnits>& s);
		inline const ffw::Vec2<GuiUnits>& getButtonSize() const {
			return buttonSize;
		}
		void setInversed(bool inversed);
		bool getInversed() const;
		ffw::Vec2i getMinimumWrapSize() override;
		inline void setBarStyleGroup(const GuiStyleGroup* style) {
			styleBar = style;
			redraw();
		}
		inline const GuiStyleGroup* getBarStyleGroup() const {
			return styleBar;
		}
		inline void setButtonStyleGroup(const GuiStyleGroup* style) {
			styleButton = style;
			redraw();
		}
		inline const GuiStyleGroup* getButtonStyleGroup() const {
			return styleButton;
		}
	protected:
		const GuiStyleGroup* styleButton;
		const GuiStyleGroup* styleBar;
		ffw::Vec2<GuiUnits> buttonSize;
		ffw::Vec2<GuiUnits> barSize;
	private:
		void calculateButtonSize(ffw::Vec2i& pos, ffw::Vec2i& size) const;
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
		bool vertical;
		ffw::Vec2i range;
		int value;
		bool inverse;
		ffw::Vec2i clickedOffset;
	};
}
#endif
