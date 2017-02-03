/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilabel.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::string& label_):GuiLabel(context, Utf8ToWstr(label_)){
}

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::wstring& label_):GuiWidget(context),label(label_){
	ignoreinputflag = true;
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_LABEL");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiLabel::~GuiLabel(){
}

///=============================================================================
void ffw::GuiLabel::SetLabel(const std::wstring& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiLabel::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiLabel::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label, GetCurrentStyle()->text, GetLineHeight());
}

///=============================================================================
void ffw::GuiLabel::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiLabel::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiLabel::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiLabel::EventFocus(bool gained){
}

///=============================================================================
void ffw::GuiLabel::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiLabel::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiLabel::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiLabel::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiLabel::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiLabel::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_LABEL");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiLabel::GetMinimumWrapSize() {
	if(GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label, GetLineHeight());
}