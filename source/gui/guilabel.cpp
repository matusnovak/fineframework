/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilabel.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::string& label_, const std::type_info& type):GuiLabel(context, Utf8ToWstr(label_), type){
}

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::wstring& label_, const std::type_info& type):GuiWidget(context, type),label(label_){
	ignoreinputflag = true;
	SetAlign(GuiAlign::TOP_LEFT);
	SetSize(GuiPercent(100), GuiWrap());
	SetMargin(0, 0, 5, 0);
	SetPadding(0, 0, 5, 0);
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
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label, GetCurrentStyle().text);
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
ffw::Vec2i ffw::GuiLabel::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label);
}