/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibuttontoggle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::string& label) :GuiButtonToggle(context, utf8ToWstr(label)) {
}

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::wstring& label) : GuiButton(context, label) {
	setToggleFocus();
}

///=============================================================================
ffw::GuiButtonToggle::~GuiButtonToggle() {
}

///=============================================================================
void ffw::GuiButtonToggle::setValue(bool value) {
	setFocus(value);
}

///=============================================================================
bool ffw::GuiButtonToggle::getValue() const {
	return hasFocus();
}

///=============================================================================
ffw::GuiButtonTogglePrimary::GuiButtonTogglePrimary(GuiWindow* context, const std::string& label) :
	GuiButton(context, label) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_BUTTON_PRIMARY");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButtonTogglePrimary::GuiButtonTogglePrimary(GuiWindow* context, const std::wstring& label) :
	GuiButton(context, label) {
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_BUTTON_PRIMARY");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButtonTogglePrimary::~GuiButtonTogglePrimary() {
}

///=============================================================================
void ffw::GuiButtonTogglePrimary::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_BUTTON_PRIMARY");
	setDefaults(&widgetStyle->defaults);
}