/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilayout.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLayout::GuiLayout(GuiWindow* context, Orientation Orientation):GuiWidget(context){
	GuiWidget::SetOrientation(Orientation);
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	ignoreinputflag = true;

	//style.normal.border = false;
	//style.normal.borderSize = 2;
	//style.normal.borderColor = ffw::Rgb(0xFF0000);
}

///=============================================================================
ffw::GuiLayout::~GuiLayout(){
	DeleteWidgets();
}

///=============================================================================
void ffw::GuiLayout::AddWidget(GuiWidget* widget){
	GuiWidget::AddWidget(widget);
}

///=============================================================================
void ffw::GuiLayout::DeleteWidgets(){
	GuiWidget::DeleteWidgets();
}

///=============================================================================
void ffw::GuiLayout::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
}

///=============================================================================
void ffw::GuiLayout::EventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::EventSize(const ffw::Vec2i& size){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::EventHover(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::EventFocus(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiLayout::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiLayout::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiLayout::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiLayout::GetMinimumWrapSize() const {
	return 0;
}