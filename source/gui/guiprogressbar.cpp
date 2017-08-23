/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogressbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiProgressBar::GuiProgressBar(GuiWindow* context) : GuiWidget(context) {
	setIgnoreUserInput(true);
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_PROGRESSBAR");
	innerStyle = &context->getTheme()->getStyleGroup("GUI_PROGRESSBAR_INNER");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiProgressBar::~GuiProgressBar() {
}

///=============================================================================
void ffw::GuiProgressBar::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	float width = float((percent / 100.0f) * contentsize.x);
	if(width > 0) {
		renderComponent(contentoffset, ffw::Vec2f(width, contentsize.y), getCurrentStyle(innerStyle));
	}
}

///=============================================================================
void ffw::GuiProgressBar::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiProgressBar::eventSize(const ffw::Vec2f& s) {
	(void)s;
}

///=============================================================================
void ffw::GuiProgressBar::eventHover(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiProgressBar::eventFocus(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiProgressBar::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiProgressBar::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiProgressBar::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiProgressBar::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiProgressBar::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiProgressBar::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiProgressBar::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_PROGRESSBAR");
	innerStyle = &context->getTheme()->getStyleGroup("GUI_PROGRESSBAR_INNER");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiProgressBar::getMinimumWrapSize() {
	return ffw::Vec2i(16, 8);
}