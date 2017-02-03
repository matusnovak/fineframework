/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitab.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiTabs::Button::Button(GuiWindow* context, const std::string& label):GuiButtonToggle(context, label) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_TABS_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Button::Button(GuiWindow* context, const std::wstring& label):GuiButtonToggle(context, label) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_TABS_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Button::~Button() {
}

///=============================================================================
void ffw::GuiTabs::Button::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_TABS_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Content::Content(GuiWindow* context) :GuiLayout(context, ffw::GuiLayout::Orientation::FIXED) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_TABS_CONTENT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Content::~Content() {
}

///=============================================================================
void ffw::GuiTabs::Content::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_TABS_CONTENT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::TopBar::TopBar(GuiWindow* context):GuiLayout(context, ffw::GuiLayout::Orientation::HORIZONTAL) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_TABS_BAR");
	SetDefaults(&widgetStyle->defaults);
	SetWrap(true);
}

///=============================================================================
ffw::GuiTabs::TopBar::~TopBar() {
}

///=============================================================================
void ffw::GuiTabs::TopBar::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_TABS_BAR");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::GuiTabs(GuiWindow* context):GuiWidget(context) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_TABS");
	SetDefaults(&widgetStyle->defaults);

	bar = new GuiTabs::TopBar(context);
	content = new GuiTabs::Content(context);
	GuiWidget::AddWidgetInternal(bar);
	GuiWidget::AddWidgetInternal(content);
}

///=============================================================================
ffw::GuiTabs::~GuiTabs() {

}

///=============================================================================
void ffw::GuiTabs::WidgetEvent(GuiEvent e) {
	if (e.type == GuiEvent::Type::CLICKED && e.data.clicked.value == true) {
		HideAllExcept(e.widget);
	}
}

///=============================================================================
void ffw::GuiTabs::HideAllExcept(GuiWidget* widget) {
	for (auto& pair : tabs) {
		if (pair.first == widget) {
			pair.first->SetValue(true);
			pair.second->SetHidden(false);
		}
		else {
			pair.first->SetValue(false);
			pair.second->SetHidden(true);
		}
	}
}

///=============================================================================
void ffw::GuiTabs::ShowTabByIndex(size_t index) {
	for (size_t i = 0; i < tabs.size(); i++) {
		if (i == index) {
			tabs[i].first->SetValue(true);
			tabs[i].second->SetHidden(false);
		}
		else {
			tabs[i].first->SetValue(false);
			tabs[i].second->SetHidden(true);
		}
	}
}

///=============================================================================
void ffw::GuiTabs::ShowTabByWidget(const GuiWidget *widget) {
	for (auto& pair : tabs) {
		if (pair.second == widget) {
			pair.first->SetValue(true);
			pair.second->SetHidden(false);
		}
		else {
			pair.first->SetValue(false);
			pair.second->SetHidden(true);
		}
	}
}

///=============================================================================
void ffw::GuiTabs::AddWidgetPair(GuiButtonToggle* button, GuiWidget* widget) {
	//widget->SetSize(ffw::GuiPercent(100), ffw::GuiPercent(100));
	button->AddEventCallback(&GuiTabs::WidgetEvent, this, true);
	button->SetValue(tabs.size() == 0);
	widget->SetHidden(tabs.size() != 0);
	content->AddWidget(widget);
	bar->AddWidget(button);
	tabs.push_back(std::make_pair(button, widget));
}

///=============================================================================
ffw::GuiWidget* ffw::GuiTabs::AddTab(const std::string& label, GuiWidget* widget) {
	if (widget != NULL) {
		AddWidgetPair(new GuiTabs::Button(context, label), widget);
	}
	return widget;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiTabs::AddTab(const std::wstring& label, GuiWidget* widget) {
	if (widget != NULL) {
		AddWidgetPair(new GuiTabs::Button(context, label), widget);
	}
	return widget;
}

///=============================================================================
void ffw::GuiTabs::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiTabs::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiTabs::EventSize(const ffw::Vec2i& size) {
	/*const auto& topSize = bar->GetRealSizeWithMargin();
	ffw::Vec2i contentSize(size.x, size.y - topSize.y);
	contentSize.x -= content->GetMarginInPixels(1);
	contentSize.x -= content->GetMarginInPixels(3);
	contentSize.y -= content->GetMarginInPixels(0);
	contentSize.y -= content->GetMarginInPixels(2);
	content->SetSize(contentSize.x, contentSize.y);*/
}

///=============================================================================
void ffw::GuiTabs::EventHover(bool gained) {
}

///=============================================================================
void ffw::GuiTabs::EventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiTabs::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiTabs::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiTabs::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiTabs::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiTabs::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiTabs::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_TABS");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiTabs::GetMinimumWrapSize() {
	return 0;
}