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
void ffw::GuiLayout::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize){
	(void)contentsize;
	(void)contentoffset;
}

///=============================================================================
void ffw::GuiLayout::eventPos(const ffw::Vec2f& p){
	(void)p;
}

///=============================================================================
void ffw::GuiLayout::eventSize(const ffw::Vec2f& s){
	(void)s;
}

///=============================================================================
void ffw::GuiLayout::eventHover(bool gained){
	(void)gained;
}

///=============================================================================
void ffw::GuiLayout::eventFocus(bool gained){
	(void)gained;
}

///=============================================================================
void ffw::GuiLayout::eventMouse(const ffw::Vec2f& mousePos){
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiLayout::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiLayout::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiLayout::eventText(wchar_t chr){
	(void)chr;
}

///=============================================================================
void ffw::GuiLayout::eventKey(ffw::Key key, ffw::Mode mode){
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiLayout::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiLayout::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_LAYOUT");
	//setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiLayout::getMinimumWrapSize() {
	return 0;
}