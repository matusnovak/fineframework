/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilist.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiList::GuiList(GuiWindow* context):GuiWidget(context){
	ignoreinputflag = true;
	
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
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
}

///=============================================================================
ffw::GuiList::~GuiList(){
}

///=============================================================================
void ffw::GuiList::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
}

///=============================================================================
void ffw::GuiList::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiList::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiList::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiList::EventFocus(bool gained){
}

///=============================================================================
void ffw::GuiList::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiList::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiList::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiList::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiList::GetMinimumWrapSize() const {
	return ffw::Vec2i(8, 4);
}