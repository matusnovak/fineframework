/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiswitch.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSwitch::GuiSwitch(GuiWindow* context) :
	GuiWidget(context) {
	togglefocusflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SWITCH");
	styleButton = &context->GetTheme()->GetStyleGroup("GUI_SWITCH_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiSwitch::~GuiSwitch() {
}

///=============================================================================
void ffw::GuiSwitch::SetValue(bool value) {
	SetFocus(value);
}

///=============================================================================
bool ffw::GuiSwitch::GetValue() const {
	return HasFocus();
}

///=============================================================================
void ffw::GuiSwitch::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	auto style = GetCurrentStyle(styleButton);
	if (style != NULL) {
		int offset = 0;
		if (HasFocus()) {
			offset = contentsize.x - contentsize.y;
		}
		ffw::Vec2i buttonSize(contentsize.y, contentsize.y);
		ffw::Vec2i buttonPos(contentoffset.x + offset, contentoffset.y);
		RenderComponent(buttonPos, buttonSize, style);
	}
}

///=============================================================================
void ffw::GuiSwitch::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiSwitch::EventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiSwitch::EventHover(bool gained) {
	Redraw();
}

///=============================================================================
void ffw::GuiSwitch::EventFocus(bool gained) {
	Redraw();

	GuiEvent::Data dat;
	dat.clicked.value = gained;
	PushEvent(GuiEvent::Type::CLICKED, dat);
}

///=============================================================================
void ffw::GuiSwitch::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiSwitch::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiSwitch::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiSwitch::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiSwitch::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiSwitch::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SWITCH");
	styleButton = &theme->GetStyleGroup("GUI_SWITCH_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiSwitch::GetMinimumWrapSize() {
	return ffw::Vec2i(16, 8);
}