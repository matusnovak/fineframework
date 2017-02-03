/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibutton.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::string& label_) :
	GuiButton(context, Utf8ToWstr(label_)) {
}

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::wstring& label_) :
	GuiWidget(context), label(label_) {
	dropfocusflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButton::~GuiButton() {
}

///=============================================================================
void ffw::GuiButton::SetLabel(const std::wstring& label_) {
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiButton::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiButton::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label, GetCurrentStyle()->text, GetLineHeight());
}

///=============================================================================
void ffw::GuiButton::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiButton::EventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiButton::EventHover(bool gained) {
	Redraw();
}

///=============================================================================
void ffw::GuiButton::EventFocus(bool gained) {
	Redraw();

	if (!gained || !dropfocusflag) {
		GuiEvent::Data dat;
		if (dropfocusflag)dat.clicked.value = true;
		else dat.clicked.value = gained;
		PushEvent(GuiEvent::Type::CLICKED, dat);
	}
}

///=============================================================================
void ffw::GuiButton::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiButton::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiButton::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiButton::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiButton::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiButton::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiButton::GetMinimumWrapSize() {
	if (GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label, GetLineHeight());
}

///=============================================================================
ffw::GuiButtonPrimary::GuiButtonPrimary(GuiWindow* context, const std::string& label) :
	GuiButton(context, label) {
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_BUTTON_PRIMARY");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiButtonPrimary::GuiButtonPrimary(GuiWindow* context, const std::wstring& label) :
	GuiButton(context, label) {
}

///=============================================================================
ffw::GuiButtonPrimary::~GuiButtonPrimary() {
}

///=============================================================================
void ffw::GuiButtonPrimary::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_BUTTON_PRIMARY");
	SetDefaults(&widgetStyle->defaults);
}