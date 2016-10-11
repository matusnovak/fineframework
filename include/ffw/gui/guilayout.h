/* This file is part of FineFramework project */
#ifndef FFW_GUI_LAYOUT
#define FFW_GUI_LAYOUT
#include "guiwidget.h"
namespace ffw {
	class FFW_API GuiLayout: public GuiWidget {
	public:
		typedef GuiWidget::Orientation Orientation;
		GuiLayout(GuiWindow* context, Orientation orientation);
		virtual ~GuiLayout();
		void AddWidget(GuiWidget* widget);
		void DeleteWidgets();
		ffw::Vec2i GetMinimumWrapSize() const override;
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
	};
	class GuiVerticalLayout: public GuiLayout {
	public:
		GuiVerticalLayout(GuiWindow* context):GuiLayout(context, ffw::GuiWidget::Orientation::VERTICAL){}
		virtual ~GuiVerticalLayout(){}
	};
	class GuiHorizontalLayout: public GuiLayout {
	public:
		GuiHorizontalLayout(GuiWindow* context):GuiLayout(context, ffw::GuiWidget::Orientation::HORIZONTAL){}
		virtual ~GuiHorizontalLayout(){}
	};
	class GuiFixedLayout: public GuiLayout {
	public:
		GuiFixedLayout(GuiWindow* context):GuiLayout(context, ffw::GuiWidget::Orientation::FIXED){}
		virtual ~GuiFixedLayout(){}
	};
}
#endif
