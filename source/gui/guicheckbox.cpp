/*** This file is part of FineFramework project ***/

#include "ffw/gui/guicheckbox.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiCheckbox::Button::Button(GuiWindow* context):GuiWidget(context){
	setToggleFocus();

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_CHECKBOX_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiCheckbox::Button::~Button(){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize){
	//context->drawRectangle(contentoffset, contentsize, getCurrentStyle()->function.color);
	float width = std::min(contentsize.x, contentsize.y) / 2.0f;
	auto p = contentoffset + contentsize / 2.0f;
	context->drawLine(
		ffw::Vec2f(p.x - width, p.y).floor(),
		ffw::Vec2f(p.x, p.y + width).ceil(),
		getCurrentStyle()->function.color
	);
	context->drawLine(
		ffw::Vec2f(p.x, p.y + width).ceil(),
		ffw::Vec2f(p.x + width, p.y - width).floor(),
		getCurrentStyle()->function.color
	);
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventPos(const ffw::Vec2f& p){
	(void)p;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventSize(const ffw::Vec2f& s){
	(void)s;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventHover(bool gained){
	(void)gained;
	redraw();
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventFocus(bool gained){
	redraw();

	GuiEvent::Data dat;
	dat.clicked.value = gained;
	pushEvent(GuiEvent::Type::CLICKED, dat);
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventMouse(const ffw::Vec2f& mousePos){
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiCheckbox::Button::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventText(wchar_t chr){
	(void)chr;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventKey(ffw::Key key, ffw::Mode mode){
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_CHECKBOX_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiCheckbox::Button::getMinimumWrapSize() {
	return 8.0f;
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::string& label_):GuiCheckbox(context, utf8ToWstr(label_)){
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::wstring& label_):GuiWidget(context),label(label_){
	setOrientation(Orientation::HORIZONTAL);
	setIgnoreUserInput(true);

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_CHECKBOX");
	setDefaults(&widgetStyle->defaults);

	widgetbutton = new GuiCheckbox::Button(context);
	widgetbutton->setCallbackPtr(this);

	addWidgetInternal(widgetbutton);
}

///=============================================================================
ffw::GuiCheckbox::~GuiCheckbox(){
	deleteWidgetsInternal();
}

///=============================================================================
void ffw::GuiCheckbox::setLabel(const std::wstring& label_){
	label = label_;
	redraw();
}

///=============================================================================
const std::wstring& ffw::GuiCheckbox::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiCheckbox::setValue(bool value){
	widgetbutton->setFocus(value);
}

///=============================================================================
bool ffw::GuiCheckbox::getValue() const {
	return widgetbutton->hasFocus();
}

///=============================================================================
void ffw::GuiCheckbox::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize){
	auto s = widgetbutton->getRealSize();
	s.x += widgetbutton->getMarginInPixels(1);
	s.y = 0;
	context->drawStringAligned(contentoffset + s, contentsize - s, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiCheckbox::eventPos(const ffw::Vec2f& p){
	(void)p;
}

///=============================================================================
void ffw::GuiCheckbox::eventSize(const ffw::Vec2f& s){
	(void)s;
}

///=============================================================================
void ffw::GuiCheckbox::eventHover(bool gained){
	(void)gained;
}

///=============================================================================
void ffw::GuiCheckbox::eventFocus(bool gained){
	(void)gained;
}

///=============================================================================
void ffw::GuiCheckbox::eventMouse(const ffw::Vec2f& mousePos){
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiCheckbox::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiCheckbox::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiCheckbox::eventText(wchar_t chr){
	(void)chr;
}

///=============================================================================
void ffw::GuiCheckbox::eventKey(ffw::Key key, ffw::Mode mode){
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiCheckbox::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiCheckbox::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_CHECKBOX");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiCheckbox::getMinimumWrapSize() {
	if(getCurrentFont() == NULL)return 0;
	auto strsize = static_cast<ffw::Vec2f>(getCurrentFont()->getStringSize(label, getLineHeight()));
	const auto& buttonSize = widgetbutton->getRealSizeWithMargin();
	strsize.x += buttonSize.x;
	strsize.y = std::max(strsize.y, buttonSize.y);

	return strsize;
}