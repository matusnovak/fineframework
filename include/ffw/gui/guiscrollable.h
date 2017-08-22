/* This file is part of FineFramework project */
#ifndef FFW_GUI_SCROLLABLE
#define FFW_GUI_SCROLLABLE
#include "guiwidget.h"
#include "guiscrollbar.h"
#include "guilayout.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiScrollable : public GuiWidget {
	public:
		GuiScrollable(GuiWindow* context, GuiWidget* widget, bool hori, bool vert);
		virtual ~GuiScrollable();
		ffw::Vec2f getMinimumWrapSize() override;
		void setScrollbarThickness(float px);
		void setScrollValues(float hori, float vert);
		inline ffw::Vec2f getScrollValues() const {
			ffw::Vec2f values;
			if (hscroll != NULL)values.x = hscroll->getValue();
			if (vscroll != NULL)values.x = vscroll->getValue();
			return values;
		}
		inline float getScrollbarThickness() const {
			return thickness;
		}
		inline ffw::GuiScrollBar* getVscroll() {
			return vscroll;
		}
		inline const ffw::GuiScrollBar* getVscroll() const {
			return vscroll;
		}
		inline ffw::GuiScrollBar* getHscroll() {
			return hscroll;
		}
		inline const ffw::GuiScrollBar* getHscroll() const {
			return hscroll;
		}
		inline void setScrollIncrements(float inc) {
			scrollInc = inc;
		}
		inline float getScrollIncrements() const {
			return scrollInc;
		}
	protected:
		inline ffw::GuiWidget* getInnerAsWidget() {
			return inner;
		}
		inline const ffw::GuiWidget* getInnerAsWidget() const {
			return inner;
		}
	private:
		void widgetEvent(GuiEvent e);
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
		void eventThemeChanged(const GuiTheme* theme) override;
		ffw::GuiScrollBar* vscroll;
		ffw::GuiScrollBar* hscroll;
		ffw::GuiWidget* inner;
		float thickness;
		float scrollInc;
	};
	/**
	* @ingroup gui
	*/
	class FFW_API GuiScrollableLayout : public GuiScrollable {
	public:
		GuiScrollableLayout(GuiWindow* context, GuiLayout::Orientation orientation, bool hori, bool vert);
		virtual ~GuiScrollableLayout();
		inline GuiLayout* getInner(){
			return dynamic_cast<ffw::GuiLayout*>(getInnerAsWidget());
		}
		inline const GuiLayout* getInner() const{
			return dynamic_cast<const ffw::GuiLayout*>(getInnerAsWidget());
		}
	};
}
#endif