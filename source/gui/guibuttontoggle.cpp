/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibuttontoggle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::string& label) :GuiButtonToggle(context, Utf8ToWstr(label)) {
}

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::wstring& label) : GuiButton(context, label) {
	togglefocusflag = true;
	dropfocusflag = false;
}

///=============================================================================
ffw::GuiButtonToggle::~GuiButtonToggle() {
}

///=============================================================================
void ffw::GuiButtonToggle::SetValue(bool value) {
	SetFocus(value);
}

///=============================================================================
bool ffw::GuiButtonToggle::GetValue() const {
	return HasFocus();
}

///=============================================================================
ffw::GuiButtonTogglePrimary::GuiButtonTogglePrimary(GuiWindow* context, const std::string& label) :
	GuiButton(context, label) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_BUTTON_PRIMARY");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButtonTogglePrimary::GuiButtonTogglePrimary(GuiWindow* context, const std::wstring& label) :
	GuiButton(context, label) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_BUTTON_PRIMARY");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButtonTogglePrimary::~GuiButtonTogglePrimary() {
}

///=============================================================================
void ffw::GuiButtonTogglePrimary::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_BUTTON_PRIMARY");
	SetDefaults(&widgetStyle->defaults);
}