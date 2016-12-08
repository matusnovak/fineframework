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
	class FFW_API GuiScrollable: public GuiWidget {
	public:
		GuiScrollable(GuiWindow* context, GuiLayout::Orientation orient, bool vert, bool hori);
		virtual ~GuiScrollable();
		void AddWidget(GuiWidget* widget);
		void DeleteWidgets();
		bool DeleteSingleWidget(GuiWidget* widget);
		void SetOrientation(GuiLayout::Orientation orient);
		ffw::Vec2i GetMinimumWrapSize() const override;
		void SetScrollbarThickness(int px);
		ffw::GuiLayout* GetInner();
		const ffw::GuiLayout* GetInner() const;
		ffw::GuiScrollbar* GetVscroll();
		const ffw::GuiScrollbar* GetVscroll() const;
		ffw::GuiScrollbar* GetHscroll();
		const ffw::GuiScrollbar* GetHscroll() const;
	private:
		void WidgetEvent(GuiEvent e);
		void ButtonCallback(ffw::GuiEvent e);
		void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override;
		void EventPos(const ffw::Vec2i& pos) override;
		void EventSize(const ffw::Vec2i& size) override;
		void EventHover(bool gained) override;
		void EventFocus(bool gained) override;
		void EventMouse(const ffw::Vec2i& pos) override;
		void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) override;
		void EventText(wchar_t chr) override;
		void EventKey(ffw::Key key, ffw::Mode mode) override;
		ffw::GuiScrollbar* vscroll;
		ffw::GuiScrollbar* hscroll;
		ffw::GuiLayout* inner;
		int increments;
		int thickness;
	};
}
#endif
