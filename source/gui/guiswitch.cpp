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
void ffw::GuiSwitch::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	auto style = getCurrentStyle(styleButton);
	if (style != NULL) {
		int offset = 0;
		if (hasFocus()) {
			offset = contentsize.x - contentsize.y;
		}
		ffw::Vec2i buttonSize(contentsize.y, contentsize.y);
		ffw::Vec2i buttonPos(contentoffset.x + offset, contentoffset.y);
		renderComponent(buttonPos, buttonSize, style);
	}
}

///=============================================================================
void ffw::GuiSwitch::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiSwitch::eventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiSwitch::eventHover(bool gained) {
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
void ffw::GuiSwitch::eventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiSwitch::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiSwitch::eventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiSwitch::eventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiSwitch::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiSwitch::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SWITCH");
	styleButton = &theme->getStyleGroup("GUI_SWITCH_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiSwitch::getMinimumWrapSize() {
	return ffw::Vec2i(16, 8);
}