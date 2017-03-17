/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilayout.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLayout::GuiLayout(GuiWindow* context, Orientation Orientation):GuiWidget(context){
	GuiWidget::setOrientation(Orientation);
	setIgnoreUserInput(true);

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_LAYOUT");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiLayout::~GuiLayout(){
	deleteWidgets();
}

///=============================================================================
ffw::GuiWidget* ffw::GuiLayout::addWidget(GuiWidget* widget){
	return GuiWidget::addWidgetInternal(widget);
}

///=============================================================================
ffw::GuiWidget* ffw::GuiLayout::addWidgetAfter(const GuiWidget* previous, GuiWidget* widget) {
	return GuiWidget::addWidgetAfterInternal(previous, widget);
}

///=============================================================================
ffw::GuiWidget* ffw::GuiLayout::addWidgetBefore(const GuiWidget* next, GuiWidget* widget) {
	return GuiWidget::addWidgetBeforeInternal(next, widget);
}

///=============================================================================
void ffw::GuiLayout::deleteWidgets(){
	GuiWidget::deleteWidgetsInternal();
}

///=============================================================================
bool ffw::GuiLayout::deleteSingleWidget(const GuiWidget* widget){
	return GuiWidget::deleteSingleWidgetInternal(widget);
}

///=============================================================================
void ffw::GuiLayout::setOrientation(Orientation orient){
	GuiWidget::setOrientation(orient);
}

///=============================================================================
void ffw::GuiLayout::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
}

///=============================================================================
void ffw::GuiLayout::eventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::eventSize(const ffw::Vec2i& size){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::eventHover(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::eventFocus(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiLayout::eventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiLayout::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiLayout::eventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiLayout::eventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiLayout::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiLayout::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_LAYOUT");
	//setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiLayout::getMinimumWrapSize() {
	return 0;
}