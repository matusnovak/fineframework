/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiswitch.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSwitch::GuiSwitch(GuiWindow* context) :
	GuiWidget(context) {
	setToggleFocus();

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_SWITCH");
	styleButton = &context->getTheme()->getStyleGroup("GUI_SWITCH_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiSwitch::~GuiSwitch() {
}

///=============================================================================
void ffw::GuiSwitch::setValue(bool value) {
	setFocus(value);
}

///=============================================================================
bool ffw::GuiSwitch::getValue() const {
	return hasFocus();
}

///=============================================================================
void ffw::GuiSwitch::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	auto style = getCurrentStyle(styleButton);
	if (style != NULL) {
		float off = 0;
		if (hasFocus()) {
			off = contentsize.x - contentsize.y;
		}
		ffw::Vec2f buttonSize(contentsize.y, contentsize.y);
		ffw::Vec2f buttonPos(contentoffset.x + off, contentoffset.y);
		renderComponent(buttonPos, buttonSize, style);
	}
}

///=============================================================================
void ffw::GuiSwitch::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiSwitch::eventSize(const ffw::Vec2f& s) {
	(void)s;
}

///=============================================================================
void ffw::GuiSwitch::eventHover(bool gained) {
	(void)gained;
	redraw();
}

///=============================================================================
void ffw::GuiSwitch::eventFocus(bool gained) {
	redraw();

	GuiEvent::Data dat;
	dat.clicked.value = gained;
	pushEvent(GuiEvent::Type::CLICKED, dat);
}

///=============================================================================
void ffw::GuiSwitch::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiSwitch::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiSwitch::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiSwitch::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiSwitch::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiSwitch::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiSwitch::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SWITCH");
	styleButton = &theme->getStyleGroup("GUI_SWITCH_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiSwitch::getMinimumWrapSize() {
	return ffw::Vec2i(16, 8);
}