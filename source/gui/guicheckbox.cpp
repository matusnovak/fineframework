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
void ffw::GuiCheckbox::Button::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	//context->drawRectangle(contentoffset, contentsize, getCurrentStyle()->function.color);
	int width = std::min(contentsize.x, contentsize.y) / 2;
	auto pos = contentoffset + contentsize / 2;
	context->drawLine(
		ffw::Vec2i(pos.x - width, pos.y),
		ffw::Vec2i(pos.x, pos.y + width),
		getCurrentStyle()->function.color
	);
	context->drawLine(
		ffw::Vec2i(pos.x, pos.y + width),
		ffw::Vec2i(pos.x + width, pos.y - width),
		getCurrentStyle()->function.color
	);
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventHover(bool gained){
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
void ffw::GuiCheckbox::Button::eventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiCheckbox::Button::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_CHECKBOX_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiCheckbox::Button::getMinimumWrapSize() {
	return 8;
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
void ffw::GuiCheckbox::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	auto size = widgetbutton->getRealSize();
	size.x += widgetbutton->getMarginInPixels(1);
	size.y = 0;
	context->drawStringAligned(contentoffset + size, contentsize - size, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiCheckbox::eventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiCheckbox::eventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiCheckbox::eventHover(bool gained){
}

///=============================================================================
void ffw::GuiCheckbox::eventFocus(bool gained){
}

///=============================================================================
void ffw::GuiCheckbox::eventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckbox::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::eventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiCheckbox::eventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiCheckbox::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_CHECKBOX");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiCheckbox::getMinimumWrapSize() {
	if(getCurrentFont() == NULL)return 0;
	auto strsize = getCurrentFont()->getStringSize(label, getLineHeight());
	const auto& buttonSize = widgetbutton->getRealSizeWithMargin();
	strsize.x += buttonSize.x;
	strsize.y = std::max(strsize.y, buttonSize.y);

	return strsize;
}