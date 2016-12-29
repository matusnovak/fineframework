/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibutton.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::string& label_, const std::type_info& type):
	GuiButton(context, Utf8ToWstr(label_), type){
}

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::wstring& label_, const std::type_info& type):
	GuiWidget(context, type),label(label_){
	dropfocusflag = true;
	SetSize(GuiPercent(100), GuiWrap());
	SetAlign(GuiAlign::CENTER);
	SetMargin(0, 0, 5, 0);
	SetPadding(5);
}

///=============================================================================
ffw::GuiButton::~GuiButton(){
}

///=============================================================================
void ffw::GuiButton::SetLabel(const std::wstring& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiButton::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiButton::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label, GetCurrentStyle().text);
}

///=============================================================================
void ffw::GuiButton::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiButton::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiButton::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiButton::EventFocus(bool gained){
	Redraw();

	if(!gained || !dropfocusflag){
		GuiEvent::Data dat;
		if(dropfocusflag)dat.clicked.value = true;
		else dat.clicked.value = gained;
		context->PushEvent(onclickcallback, {GetCallbackPtr(), GuiEvent::Type::CLICKED, dat});
	}
}

///=============================================================================
void ffw::GuiButton::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiButton::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiButton::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiButton::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiButton::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label);
}