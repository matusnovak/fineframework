/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilabel.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::string& label_):GuiLabel(context, utf8ToWstr(label_)){
}

///=============================================================================
ffw::GuiLabel::GuiLabel(GuiWindow* context, const std::wstring& label_):GuiWidget(context),label(label_){
	setIgnoreUserInput(true);
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_LABEL");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiLabel::~GuiLabel(){
}

///=============================================================================
void ffw::GuiLabel::setLabel(const std::wstring& label_){
	label = label_;
	redraw();
}

///=============================================================================
const std::wstring& ffw::GuiLabel::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiLabel::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize){
	context->drawStringAligned(contentoffset, contentsize, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiLabel::eventPos(const ffw::Vec2f& p){
	(void)p;
}

///=============================================================================
void ffw::GuiLabel::eventSize(const ffw::Vec2f& s){
	(void)s;
}

///=============================================================================
void ffw::GuiLabel::eventHover(bool gained){
	(void)gained;
}

///=============================================================================
void ffw::GuiLabel::eventFocus(bool gained){
	(void)gained;
}

///=============================================================================
void ffw::GuiLabel::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiLabel::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiLabel::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiLabel::eventText(wchar_t chr){
	(void)chr;
}

///=============================================================================
void ffw::GuiLabel::eventKey(ffw::Key key, ffw::Mode mode){
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiLabel::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiLabel::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_LABEL");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiLabel::getMinimumWrapSize() {
	if(getCurrentFont() == NULL)return 0;
	return getCurrentFont()->getStringSize(label, getLineHeight());
}