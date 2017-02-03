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
		ffw::Vec2i GetMinimumWrapSize() override;
		void SetScrollbarThickness(int px);
		void SetScrollValues(int hori, int vert);
		inline ffw::Vec2i GetScrollValues() const {
			ffw::Vec2i values;
			if (hscroll != NULL)values.x = hscroll->GetValue();
			if (vscroll != NULL)values.x = vscroll->GetValue();
			return values;
		}
		inline int GetScrollbarThickness() const {
			return thickness;
		}
		inline ffw::GuiScrollBar* GetVscroll() {
			return vscroll;
		}
		inline const ffw::GuiScrollBar* GetVscroll() const {
			return vscroll;
		}
		inline ffw::GuiScrollBar* GetHscroll() {
			return hscroll;
		}
		inline const ffw::GuiScrollBar* GetHscroll() const {
			return hscroll;
		}
	protected:
		inline ffw::GuiWidget* GetInnerAsWidget() {
			return inner;
		}
		inline const ffw::GuiWidget* GetInnerAsWidget() const {
			return inner;
		}
	private:
		void WidgetEvent(GuiEvent e);
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
		void EventThemeChanged(const GuiTheme* theme) override;
		ffw::GuiScrollBar* vscroll;
		ffw::GuiScrollBar* hscroll;
		ffw::GuiWidget* inner;
		int thickness;
	};
	/**
	* @ingroup gui
	*/
	class FFW_API GuiScrollableLayout : public GuiScrollable {
	public:
		GuiScrollableLayout(GuiWindow* context, GuiLayout::Orientation orientation, bool hori, bool vert);
		virtual ~GuiScrollableLayout();
		inline GuiLayout* GetInner(){
			return dynamic_cast<ffw::GuiLayout*>(GetInnerAsWidget());
		}
		inline const GuiLayout* GetInner() const{
			return dynamic_cast<const ffw::GuiLayout*>(GetInnerAsWidget());
		}
	};
}
#endif