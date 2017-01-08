/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilayout.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLayout::GuiLayout(GuiWindow* context, Orientation Orientation):GuiWidget(context){
	GuiWidget::SetOrientation(Orientation);
	ignoreinputflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_LAYOUT");
	SetDefaults(&widgetStyle->defaults);
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
void ffw::GuiLayout::AddWidgetAfter(const GuiWidget* previous, GuiWidget* widget) {
	GuiWidget::AddWidgetAfter(previous, widget);
}

///=============================================================================
void ffw::GuiLayout::AddWidgetBefore(const GuiWidget* next, GuiWidget* widget) {
	GuiWidget::AddWidgetBefore(next, widget);
}

///=============================================================================
void ffw::GuiLayout::DeleteWidgets(){
	GuiWidget::DeleteWidgets();
}

///=============================================================================
bool ffw::GuiLayout::DeleteSingleWidget(GuiWidget* widget){
	return GuiWidget::DeleteSingleWidget(widget);
}

///=============================================================================
void ffw::GuiLayout::SetOrientation(Orientation orient){
	GuiWidget::SetOrientation(orient);
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
void ffw::GuiLayout::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiLayout::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_LAYOUT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiLayout::GetMinimumWrapSize() const {
	return 0;
}