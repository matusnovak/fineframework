/*** This file is part of FineFramework project ***/

#include "ffw/gui/guicheckbox.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiCheckbox::Button::Button(GuiWindow* context):GuiWidget(context){
	togglefocusflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_CHECKBOX_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiCheckbox::Button::~Button(){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	context->DrawRectangle(contentoffset, contentsize, GetCurrentStyle()->function.color);
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventFocus(bool gained){
	Redraw();

	GuiEvent::Data dat;
	dat.clicked.value = gained;
	PushEvent(GuiEvent::Type::CLICKED, dat);
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_CHECKBOX_BUTTON");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiCheckbox::Button::GetMinimumWrapSize() const {
	return 8;
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::string& label_):GuiCheckbox(context, Utf8ToWstr(label_)){
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::wstring& label_):GuiWidget(context),label(label_){
	SetOrientation(Orientation::HORIZONTAL);
	ignoreinputflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_CHECKBOX");
	SetDefaults(&widgetStyle->defaults);

	widgetbutton = new GuiCheckbox::Button(context);
	widgetbutton->SetCallbackPtr(this);

	AddWidgetInternal(widgetbutton);
}

///=============================================================================
ffw::GuiCheckbox::~GuiCheckbox(){
	DeleteWidgetsInternal();
}

///=============================================================================
void ffw::GuiCheckbox::SetLabel(const std::wstring& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiCheckbox::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiCheckbox::SetValue(bool value){
	widgetbutton->SetFocus(value);
}

///=============================================================================
bool ffw::GuiCheckbox::GetValue() const {
	return widgetbutton->HasFocus();
}

///=============================================================================
void ffw::GuiCheckbox::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	auto size = widgetbutton->GetRealSize();
	size.x += widgetbutton->GetMarginInPixels(1);
	size.y = 0;
	context->DrawStringAligned(contentoffset + size, contentsize - size, GetCurrentFont(), GetAlign(), label, GetCurrentStyle()->text);
}

///=============================================================================
void ffw::GuiCheckbox::EventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiCheckbox::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiCheckbox::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiCheckbox::EventFocus(bool gained){
}

///=============================================================================
void ffw::GuiCheckbox::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckbox::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiCheckbox::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckbox::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiCheckbox::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_CHECKBOX");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiCheckbox::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	auto strsize = GetCurrentFont()->GetStringSize(label);
	const auto& buttonSize = widgetbutton->GetRealSizeWithMargin();
	strsize.x += buttonSize.x;
	strsize.y = std::max(strsize.y, buttonSize.y);

	return strsize;
}