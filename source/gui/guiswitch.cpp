/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiswitch.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSwitch::GuiSwitch(GuiWindow* context):GuiWidget(context){
	togglefocusflag = true;
	
	SetSize(GuiUnits::Percent(32), GuiUnits::Pixels(16));
	SetMargin(0, 0, 5, 0);

	//style.normal.border = true;
	//style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xFF0000);
	style.normal.textcolor = ffw::Rgb(0x222222);

	//style.hover.border = true;
	//style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0xFF0000);
	style.hover.textcolor = ffw::Rgb(0x222222);

	//style.active.border = true;
	//style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0xFF0000);
	style.active.textcolor = ffw::Rgb(0x222222);

	onclickcallback = nullptr;
}

///=============================================================================
ffw::GuiSwitch::~GuiSwitch(){
}

///=============================================================================
void ffw::GuiSwitch::SetValue(bool value){
	(value == true ? SetFocus() : ResetFocus());
}

///=============================================================================
bool ffw::GuiSwitch::GetValue() const {
	return HasFocus();
}

///=============================================================================
void ffw::GuiSwitch::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	
}

///=============================================================================
void ffw::GuiSwitch::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiSwitch::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiSwitch::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiSwitch::EventFocus(bool gained){
	Redraw();

	if(!gained){
		context->PushEvent(onclickcallback, {this, GuiEventType::CLICKED});
	}
}

///=============================================================================
void ffw::GuiSwitch::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiSwitch::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiSwitch::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiSwitch::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiSwitch::GetMinimumWrapSize() const {
	return ffw::Vec2i(8, 4);
}