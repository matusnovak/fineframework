/* This file is part of FineFramework project */
#ifndef FFW_GUI_TABS
#define FFW_GUI_TABS
#include "guiwidget.h"
#include "guilayout.h"
#include "guibuttontoggle.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class FFW_API GuiTabs : public GuiWidget {
	public:
		class FFW_API Button : public GuiButtonToggle {
		public:
			Button(GuiWindow* context, const std::string& label);
			Button(GuiWindow* context, const std::wstring& label);
			virtual ~Button();
			void eventThemeChanged(const GuiTheme* theme) override;
		};
		class FFW_API TopBar : public GuiLayout {
		public:
			TopBar(GuiWindow* context);
			virtual ~TopBar();
			void eventThemeChanged(const GuiTheme* theme) override;
		};
		class FFW_API Content : public GuiLayout {
		public:
			Content(GuiWindow* context);
			virtual ~Content();
			void eventThemeChanged(const GuiTheme* theme) override;
		};
		GuiTabs(GuiWindow* context);
		virtual ~GuiTabs();
		ffw::Vec2f getMinimumWrapSize() override;
		std::pair<GuiButtonToggle*, GuiWidget*> addTab(GuiButtonToggle* button, GuiWidget* widget);
		std::pair<GuiButtonToggle*, GuiWidget*> addTab(const std::string& label, GuiWidget* widget);
		std::pair<GuiButtonToggle*, GuiWidget*> addTab(const std::wstring& label, GuiWidget* widget);
		void showTabByIndex(size_t index);
		void showTabByWidget(const GuiWidget *widget);
	private:
		void widgetEvent(GuiEvent e);
		void hideAllExcept(GuiWidget* widget);
		void addWidgetPair(GuiButtonToggle* button, GuiWidget* widget);
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
		std::vector<std::pair<GuiButtonToggle*, GuiWidget*>> tabs;
		GuiTabs::TopBar* bar;
		GuiTabs::Content* content;
	};
}
#endif
