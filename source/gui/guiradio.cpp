/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiradio.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiRadio::Value::Value(){
	value = 0;
}

///=============================================================================
ffw::GuiRadio::Value::~Value(){
}

///=============================================================================
void ffw::GuiRadio::Value::setValue(int val){
	value = val;
	for(auto r : radios){
		if(r->getBaseValue() == value)r->assignValue(true);
		else r->assignValue(false);
	}
}

///=============================================================================
int ffw::GuiRadio::Value::getValue() const{
	return value;
}

///=============================================================================
void ffw::GuiRadio::Value::assign(GuiRadio* radio){
	if(radio != NULL && std::find(radios.begin(), radios.end(), radio) == radios.end()){
		radios.push_back(radio);
	}
}

///=============================================================================
void ffw::GuiRadio::Value::remove(GuiRadio* radio){
	auto it = std::find(radios.begin(), radios.end(), radio);
	if(it != radios.end()){
		radios.erase(it);
	}
}

///=============================================================================
void ffw::GuiRadio::Value::clearAllExcept(const GuiRadio* radio){
	for(auto r : radios){
		if(r == radio){
			value = r->getBaseValue();
			break;
		}
	}

	for (auto r : radios) {
		r->assignValue(r == radio);
	}
}

///=============================================================================
size_t ffw::GuiRadio::Value::getNumOfAssigned() const {
	return radios.size();
}

///=============================================================================
ffw::GuiRadio::Button::Button(GuiWindow* context):GuiWidget(context){
	setStickyFocus();
	
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_RADIO_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiRadio::Button::~Button(){
}

///=============================================================================
void ffw::GuiRadio::Button::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	context->drawCircle(contentoffset + contentsize / 2, std::min(contentsize.x, contentsize.y) / 2, getCurrentStyle()->function.color);
}

///=============================================================================
void ffw::GuiRadio::Button::eventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::Button::eventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiRadio::Button::eventHover(bool gained){
	redraw();
}

///=============================================================================
void ffw::GuiRadio::Button::eventFocus(bool gained){
	if(gained){
		group->clearAllExcept(parentradio);
		GuiEvent::Data dat;
		dat.clicked.value = gained;
		pushEvent(GuiEvent::Type::CLICKED, dat);
		redraw();
	}
}

///=============================================================================
void ffw::GuiRadio::Button::eventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::Button::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::Button::eventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiRadio::Button::eventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::Button::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiRadio::Button::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_RADIO_BUTTON");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiRadio::Button::getMinimumWrapSize() {
	return 0;
}

///=============================================================================
ffw::GuiRadio::GuiRadio(GuiWindow* context, const std::string& label_, int base, GuiRadio* other):GuiRadio(context, utf8ToWstr(label_), base, other){
}

///=============================================================================
ffw::GuiRadio::GuiRadio(GuiWindow* context, const std::wstring& label_, int base, GuiRadio* other):GuiWidget(context),label(label_){
	basevalue = base;
	setOrientation(Orientation::HORIZONTAL);
	setIgnoreUserInput(true);

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_RADIO");
	setDefaults(&widgetStyle->defaults);

	widgetbutton = new GuiRadio::Button(context);
	widgetbutton->setCallbackPtr(this);

	addWidgetInternal(widgetbutton);

	if(other != NULL){
		group = other->group;
	} else {
		group = new GuiRadio::Value();
	}

	group->assign(this);
	widgetbutton->group = group;
	widgetbutton->parentradio = this;
}

///=============================================================================
ffw::GuiRadio::~GuiRadio(){
	deleteWidgetsInternal();

	group->remove(this);
	if(group->getNumOfAssigned() == 0){
		delete group;
	}
}

///=============================================================================
void ffw::GuiRadio::setButtonSize(int width){
	widgetbutton->setSize(width, width);
}

///=============================================================================
void ffw::GuiRadio::setLabel(const std::wstring& label_){
	label = label_;
	redraw();
}

///=============================================================================
const std::wstring& ffw::GuiRadio::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiRadio::assignValue(bool value){
	widgetbutton->setFocus(value);

	GuiEvent::Data dat;
	dat.changed.value = getValue();
	pushEvent(GuiEvent::Type::CHANGED, dat);
}

///=============================================================================
int ffw::GuiRadio::getValue() const {
	return group->getValue();
}

///=============================================================================
int ffw::GuiRadio::getBaseValue() const {
	return basevalue;
}

///=============================================================================
void ffw::GuiRadio::setValue(int value){
	group->setValue(value);
}

///=============================================================================
void ffw::GuiRadio::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	auto size = widgetbutton->getRealSize();
	size.x += widgetbutton->getMarginInPixels(1);
	size.y = 0;
	const auto& stl = getCurrentStyle();
	context->drawStringAligned(contentoffset + size, contentsize - size, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiRadio::eventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::eventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiRadio::eventHover(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::eventFocus(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::eventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::eventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiRadio::eventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiRadio::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_RADIO");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiRadio::getMinimumWrapSize() {
	if(getCurrentFont() == NULL)return 0;
	auto strsize = getCurrentFont()->getStringSize(label, getLineHeight());
	strsize.x += widgetbutton->getSize().x.value + indent;
	strsize.y = std::max(strsize.y, widgetbutton->getSize().y.value);
	return strsize;
}