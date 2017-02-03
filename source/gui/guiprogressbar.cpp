/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogressbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiProgressBar::GuiProgressBar(GuiWindow* context) : GuiWidget(context) {
	ignoreinputflag = true;
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_PROGRESSBAR");
	innerStyle = &context->GetTheme()->GetStyleGroup("GUI_PROGRESSBAR_INNER");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiProgressBar::~GuiProgressBar() {
}

///=============================================================================
void ffw::GuiProgressBar::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	int width = int((percent / 100.0f) * contentsize.x);
	if(width > 0) {
		RenderComponent(contentoffset, ffw::Vec2i(width, contentsize.y), GetCurrentStyle(innerStyle));
	}
}

///=============================================================================
void ffw::GuiProgressBar::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiProgressBar::EventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiProgressBar::EventHover(bool gained) {
}

///=============================================================================
void ffw::GuiProgressBar::EventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiProgressBar::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiProgressBar::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiProgressBar::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiProgressBar::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiProgressBar::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiProgressBar::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_PROGRESSBAR");
	innerStyle = &context->GetTheme()->GetStyleGroup("GUI_PROGRESSBAR_INNER");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiProgressBar::GetMinimumWrapSize() {
	return ffw::Vec2i(16, 8);
}