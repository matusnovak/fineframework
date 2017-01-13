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
			void EventThemeChanged(const GuiTheme* theme) override;
		};
		class FFW_API TopBar : public GuiLayout {
		public:
			TopBar(GuiWindow* context);
			virtual ~TopBar();
			void EventThemeChanged(const GuiTheme* theme) override;
		};
		class FFW_API Content : public GuiLayout {
		public:
			Content(GuiWindow* context);
			virtual ~Content();
			void EventThemeChanged(const GuiTheme* theme) override;
		};
		GuiTabs(GuiWindow* context);
		virtual ~GuiTabs();
		ffw::Vec2i GetMinimumWrapSize() const override;
		GuiWidget* AddTab(const std::string& label, GuiWidget* widget);
		GuiWidget* AddTab(const std::wstring& label, GuiWidget* widget);
	private:
		void WidgetEvent(GuiEvent e);
		void HideAllExcept(GuiWidget* widget);
		void AddWidgetPair(GuiButtonToggle* button, GuiWidget* widget);
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
		std::vector<std::pair<GuiButtonToggle*, GuiWidget*>> tabs;
		GuiTabs::TopBar* bar;
		GuiTabs::Content* content;
	};
}
#endif
