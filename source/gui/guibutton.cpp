/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibutton.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::string& label_) :
	GuiButton(context, utf8ToWstr(label_)) {
}

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::wstring& label_) :
	GuiWidget(context), label(label_) {
	setDropFocus();

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButton::~GuiButton() {
}

///=============================================================================
void ffw::GuiButton::setLabel(const std::wstring& label_) {
	label = label_;
	redraw();
}

///=============================================================================
const std::wstring& ffw::GuiButton::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiButton::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	context->drawStringAligned(contentoffset, contentsize, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiButton::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiButton::eventSize(const ffw::Vec2f& s) {
	(void)s;
}

///=============================================================================
void ffw::GuiButton::eventHover(bool gained) {
	(void)gained;
	redraw();
}

///=============================================================================
void ffw::GuiButton::eventFocus(bool gained) {
	redraw();

	if (!gained || getFlags().focusType != GuiWidget::Focus::DROP) {
		GuiEvent::Data dat;
		if (getFlags().focusType == GuiWidget::Focus::DROP)dat.clicked.value = true;
		else dat.clicked.value = gained;
		pushEvent(GuiEvent::Type::CLICKED, dat);
	}
}

///=============================================================================
void ffw::GuiButton::eventMouse(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
bool ffw::GuiButton::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiButton::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiButton::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiButton::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiButton::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiButton::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiButton::getMinimumWrapSize() {
	if (getCurrentFont() == NULL || label.size() == 0)return 0;
	return getCurrentFont()->getStringSize(label, getLineHeight());
}

///=============================================================================
ffw::GuiButtonPrimary::GuiButtonPrimary(GuiWindow* context, const std::string& label) :
	GuiButton(context, label) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_BUTTON_PRIMARY");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButtonPrimary::GuiButtonPrimary(GuiWindow* context, const std::wstring& label) :
	GuiButton(context, label) {
}

///=============================================================================
ffw::GuiButtonPrimary::~GuiButtonPrimary() {
}

///=============================================================================
void ffw::GuiButtonPrimary::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_BUTTON_PRIMARY");
	setDefaults(&widgetStyle->defaults);
}