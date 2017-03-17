/*** This file is part of FineFramework project ***/

#include "ffw/gui/guitab.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiTabs::Button::Button(GuiWindow* context, const std::string& label):GuiButtonToggle(context, label) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TABS_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Button::Button(GuiWindow* context, const std::wstring& label):GuiButtonToggle(context, label) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TABS_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Button::~Button() {
}

///=============================================================================
void ffw::GuiTabs::Button::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TABS_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Content::Content(GuiWindow* context) :GuiLayout(context, ffw::GuiLayout::Orientation::FIXED) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TABS_CONTENT");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::Content::~Content() {
}

///=============================================================================
void ffw::GuiTabs::Content::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TABS_CONTENT");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::TopBar::TopBar(GuiWindow* context):GuiLayout(context, ffw::GuiLayout::Orientation::HORIZONTAL) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TABS_BAR");
	setDefaults(&widgetStyle->defaults);
	setWrap(true);
}

///=============================================================================
ffw::GuiTabs::TopBar::~TopBar() {
}

///=============================================================================
void ffw::GuiTabs::TopBar::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TABS_BAR");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiTabs::GuiTabs(GuiWindow* context):GuiWidget(context) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_TABS");
	setDefaults(&widgetStyle->defaults);

	bar = new GuiTabs::TopBar(context);
	content = new GuiTabs::Content(context);
	GuiWidget::addWidgetInternal(bar);
	GuiWidget::addWidgetInternal(content);
}

///=============================================================================
ffw::GuiTabs::~GuiTabs() {

}

///=============================================================================
void ffw::GuiTabs::widgetEvent(GuiEvent e) {
	if (e.type == GuiEvent::Type::CLICKED && e.data.clicked.value == true) {
		hideAllExcept(e.widget);
	}
}

///=============================================================================
void ffw::GuiTabs::hideAllExcept(GuiWidget* widget) {
	for (auto& pair : tabs) {
		if (pair.first == widget) {
			pair.first->setValue(true);
			pair.second->setHidden(false);
		}
		else {
			pair.first->setValue(false);
			pair.second->setHidden(true);
		}
	}
}

///=============================================================================
void ffw::GuiTabs::showTabByIndex(size_t index) {
	for (size_t i = 0; i < tabs.size(); i++) {
		if (i == index) {
			tabs[i].first->setValue(true);
			tabs[i].second->setHidden(false);
		}
		else {
			tabs[i].first->setValue(false);
			tabs[i].second->setHidden(true);
		}
	}
}

///=============================================================================
void ffw::GuiTabs::showTabByWidget(const GuiWidget *widget) {
	for (auto& pair : tabs) {
		if (pair.second == widget) {
			pair.first->setValue(true);
			pair.second->setHidden(false);
		}
		else {
			pair.first->setValue(false);
			pair.second->setHidden(true);
		}
	}
}

///=============================================================================
std::pair<ffw::GuiButtonToggle*, ffw::GuiWidget*> ffw::GuiTabs::addTab(GuiButtonToggle* button, GuiWidget* widget) {
	if (widget != NULL) {
		button->addEventCallback(&GuiTabs::widgetEvent, this, true);
		button->setValue(tabs.size() == 0);
		widget->setHidden(tabs.size() != 0);
		content->addWidget(widget);
		bar->addWidget(button);
		tabs.push_back(std::make_pair(button, widget));
	}
	return std::pair<ffw::GuiButtonToggle*, ffw::GuiWidget*>(button, widget);
}

///=============================================================================
std::pair<ffw::GuiButtonToggle*, ffw::GuiWidget*> ffw::GuiTabs::addTab(const std::string& label, GuiWidget* widget) {
	return addTab(new ffw::GuiTabs::Button(context, label), widget);
}

///=============================================================================
std::pair<ffw::GuiButtonToggle*, ffw::GuiWidget*> ffw::GuiTabs::addTab(const std::wstring& label, GuiWidget* widget) {
	return addTab(new ffw::GuiTabs::Button(context, label), widget);
}

///=============================================================================
void ffw::GuiTabs::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiTabs::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiTabs::eventSize(const ffw::Vec2i& size) {
	/*const auto& topSize = bar->getRealSizeWithMargin();
	ffw::Vec2i contentSize(size.x, size.y - topSize.y);
	contentSize.x -= content->getMarginInPixels(1);
	contentSize.x -= content->getMarginInPixels(3);
	contentSize.y -= content->getMarginInPixels(0);
	contentSize.y -= content->getMarginInPixels(2);
	content->setSize(contentSize.x, contentSize.y);*/
}

///=============================================================================
void ffw::GuiTabs::eventHover(bool gained) {
}

///=============================================================================
void ffw::GuiTabs::eventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiTabs::eventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiTabs::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiTabs::eventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiTabs::eventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiTabs::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiTabs::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_TABS");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiTabs::getMinimumWrapSize() {
	return 0;
}