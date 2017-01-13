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
void ffw::GuiRadio::Value::SetValue(int val){
	value = val;
	for(auto r : radios){
		if(r->GetBaseValue() == value)r->AssignValue(true);
		else r->AssignValue(false);
	}
}

///=============================================================================
int ffw::GuiRadio::Value::GetValue() const{
	return value;
}

///=============================================================================
void ffw::GuiRadio::Value::Assign(GuiRadio* radio){
	if(radio != NULL && std::find(radios.begin(), radios.end(), radio) == radios.end()){
		radios.push_back(radio);
	}
}

///=============================================================================
void ffw::GuiRadio::Value::Remove(GuiRadio* radio){
	auto it = std::find(radios.begin(), radios.end(), radio);
	if(it != radios.end()){
		radios.erase(it);
	}
}

///=============================================================================
void ffw::GuiRadio::Value::ClearAllExcept(const GuiRadio* radio){
	for(auto r : radios){
		if(r == radio){
			value = r->GetBaseValue();
			break;
		}
	}

	for (auto r : radios) {
		r->AssignValue(r == radio);
	}
}

///=============================================================================
size_t ffw::GuiRadio::Value::GetNumOfAssigned() const {
	return radios.size();
}

///=============================================================================
ffw::GuiRadio::Button::Button(GuiWindow* context):GuiWidget(context){
	stickyfocusflag = true;
	
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_RADIO_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiRadio::Button::~Button(){
}

///=============================================================================
void ffw::GuiRadio::Button::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	context->DrawCircle(contentoffset + contentsize / 2, std::min(contentsize.x, contentsize.y) / 2, GetCurrentStyle()->function.color);
}

///=============================================================================
void ffw::GuiRadio::Button::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::Button::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiRadio::Button::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiRadio::Button::EventFocus(bool gained){
	if(gained){
		group->ClearAllExcept(parentradio);
		GuiEvent::Data dat;
		dat.clicked.value = gained;
		PushEvent(GuiEvent::Type::CLICKED, dat);
		Redraw();
	}
}

///=============================================================================
void ffw::GuiRadio::Button::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::Button::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::Button::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiRadio::Button::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::Button::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiRadio::Button::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_RADIO_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiRadio::Button::GetMinimumWrapSize() const {
	return 0;
}

///=============================================================================
ffw::GuiRadio::GuiRadio(GuiWindow* context, const std::string& label_, int base, GuiRadio* other):GuiRadio(context, Utf8ToWstr(label_), base, other){
}

///=============================================================================
ffw::GuiRadio::GuiRadio(GuiWindow* context, const std::wstring& label_, int base, GuiRadio* other):GuiWidget(context),label(label_){
	basevalue = base;
	SetOrientation(Orientation::HORIZONTAL);
	ignoreinputflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_RADIO");
	SetDefaults(&widgetStyle->defaults);

	widgetbutton = new GuiRadio::Button(context);
	widgetbutton->SetCallbackPtr(this);

	AddWidgetInternal(widgetbutton);

	if(other != NULL){
		group = other->group;
	} else {
		group = new GuiRadio::Value();
	}

	group->Assign(this);
	widgetbutton->group = group;
	widgetbutton->parentradio = this;
}

///=============================================================================
ffw::GuiRadio::~GuiRadio(){
	DeleteWidgetsInternal();

	group->Remove(this);
	if(group->GetNumOfAssigned() == 0){
		delete group;
	}
}

///=============================================================================
void ffw::GuiRadio::SetButtonSize(int width){
	widgetbutton->SetSize(width, width);
}

///=============================================================================
void ffw::GuiRadio::SetLabel(const std::wstring& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiRadio::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiRadio::AssignValue(bool value){
	widgetbutton->SetFocus(value);

	GuiEvent::Data dat;
	dat.changed.value = GetValue();
	PushEvent(GuiEvent::Type::CHANGED, dat);
}

///=============================================================================
int ffw::GuiRadio::GetValue() const {
	return group->GetValue();
}

///=============================================================================
int ffw::GuiRadio::GetBaseValue() const {
	return basevalue;
}

///=============================================================================
void ffw::GuiRadio::SetValue(int value){
	group->SetValue(value);
}

///=============================================================================
void ffw::GuiRadio::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	auto size = widgetbutton->GetRealSize();
	size.x += widgetbutton->GetMarginInPixels(1);
	size.y = 0;
	const auto& stl = GetCurrentStyle();
	context->DrawStringAligned(contentoffset + size, contentsize - size, GetCurrentFont(), GetAlign(), label, GetCurrentStyle()->text);
}

///=============================================================================
void ffw::GuiRadio::EventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiRadio::EventHover(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::EventFocus(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiRadio::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiRadio::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_RADIO");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiRadio::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	auto strsize = GetCurrentFont()->GetStringSize(label);
	strsize.x += widgetbutton->GetSize().x.value + indent;
	strsize.y = std::max(strsize.y, widgetbutton->GetSize().y.value);
	return strsize;
}