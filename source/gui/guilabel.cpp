/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilabel.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::string& label_):GuiWidget(context),label(label_){
	ignoreinputflag = true;
	SetAlign(GuiAlign::TOP_LEFT);
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetMargin(0, 0, 5, 0);

	style.normal.background = false;
	//style.normal.border = true;
	//style.normal.borderSize = 1;
	//style.normal.borderColor = ffw::Rgb(0xFF0000);
	style.normal.textcolor = ffw::Rgb(0x222222);

	style.hover.background = false;
	//style.hover.border = true;
	//style.hover.borderSize = 1;
	//style.hover.borderColor = ffw::Rgb(0xFF0000);
	style.hover.textcolor = ffw::Rgb(0x222222);

	style.active.background = false;
	//style.active.border = true;
	//style.active.borderSize = 1;
	//style.active.borderColor = ffw::Rgb(0xFF0000);
	style.active.textcolor = ffw::Rgb(0x222222);
}

///=============================================================================
ffw::GuiLabel::~GuiLabel(){
}

///=============================================================================
void ffw::GuiLabel::SetLabel(const std::string& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::string& ffw::GuiLabel::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiLabel::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label);
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
ffw::Vec2i ffw::GuiLabel::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label);
}