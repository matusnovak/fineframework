/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibutton.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButton::GuiButton(GuiWindow* context, const std::string& label_):GuiWidget(context),label(label_){
	dropfocusflag = true;
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetAlign(GuiAlign::CENTER);
	SetMargin(0, 0, 5, 0);
	SetPadding(5);

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xE1E1E1);
	style.normal.border = true;
	style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xADADAD);
	style.normal.textcolor = ffw::Rgb(0x222222);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xE5F1FB);
	style.hover.border = true;
	style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0x0078D7);
	style.hover.textcolor = ffw::Rgb(0x222222);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xCCE4F7);
	style.active.border = true;
	style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0x005499);
	style.active.textcolor = ffw::Rgb(0x222222);

	onclickcallback = nullptr;
}

///=============================================================================
ffw::GuiButton::~GuiButton(){
}

///=============================================================================
void ffw::GuiButton::setLabel(const std::string& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::string& ffw::GuiButton::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiButton::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label);
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

	if(!gained){
		context->PushEvent(onclickcallback, {this, GuiEventType::CLICKED});
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