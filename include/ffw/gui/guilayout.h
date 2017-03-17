/* This file is part of FineFramework project */
#ifndef FFW_GUI_LAYOUT
#define FFW_GUI_LAYOUT
#include "guiwidget.h"
namespace ffw {
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiLayout: public GuiWidget {
	public:
		typedef GuiWidget::Orientation Orientation;
		GuiLayout(GuiWindow* context, Orientation orientation);
		virtual ~GuiLayout();
		GuiWidget* addWidget(GuiWidget* widget);
		GuiWidget* addWidgetAfter(const GuiWidget* previous, GuiWidget* widget);
		GuiWidget* addWidgetBefore(const GuiWidget* next, GuiWidget* widget);
		void deleteWidgets();
		bool deleteSingleWidget(const GuiWidget* widget);
		void setOrientation(Orientation orient);
		ffw::Vec2i getMinimumWrapSize() override;
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
		void eventThemeChanged(const GuiTheme* theme) override;
	};
	/**
	 * @ingroup gui
	 */
	class GuiVerticalLayout: public GuiLayout {
	public:
		GuiVerticalLayout(GuiWindow* context):
			GuiLayout(context, ffw::GuiWidget::Orientation::VERTICAL){}
		virtual ~GuiVerticalLayout(){}
	};
	/**
	 * @ingroup gui
	 */
	class GuiHorizontalLayout: public GuiLayout {
	public:
		GuiHorizontalLayout(GuiWindow* context):
			GuiLayout(context, ffw::GuiWidget::Orientation::HORIZONTAL){}
		virtual ~GuiHorizontalLayout(){}
	};
	/**
	 * @ingroup gui
	 */
	class GuiFixedLayout: public GuiLayout {
	public:
		GuiFixedLayout(GuiWindow* context):
			GuiLayout(context, ffw::GuiWidget::Orientation::FIXED){}
		virtual ~GuiFixedLayout(){}
	};
}
#endif
