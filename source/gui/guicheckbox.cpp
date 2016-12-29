/*** This file is part of FineFramework project ***/

#include "ffw/gui/guicheckbox.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiCheckbox::Button::Button(GuiWindow* context, const std::type_info& type):GuiWidget(context, type){
	togglefocusflag = true;
	SetPadding(GuiPercent(20));
}

///=============================================================================
ffw::GuiCheckbox::Button::~Button(){
}

///=============================================================================
void ffw::GuiCheckbox::Button::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	context->DrawRectangle(contentoffset, contentsize, GetCurrentStyle().function.color);
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
	context->PushEvent(onclickcallback, {GetCallbackPtr(), GuiEvent::Type::CLICKED, dat});
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
ffw::Vec2i ffw::GuiCheckbox::Button::GetMinimumWrapSize() const {
	return 8;
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::string& label_, const std::type_info& type):GuiCheckbox(context, Utf8ToWstr(label_), type){
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::wstring& label_, const std::type_info& type):GuiWidget(context, type),label(label_){
	SetOrientation(Orientation::HORIZONTAL);
	SetSize(GuiPercent(100), GuiWrap());
	SetMargin(0, 0, 5, 0);
	SetAlign(GuiAlign::LEFT);
	ignoreinputflag = true;

	widgetbutton = new GuiCheckbox::Button(context);
	widgetbutton->SetSize(16, 16);
	widgetbutton->SetMargin(0, 5, 0, 0);
	widgetbutton->SetCallbackPtr(this);

	AddWidget(widgetbutton);
}

///=============================================================================
ffw::GuiCheckbox::~GuiCheckbox(){
	DeleteWidgets();
}

///=============================================================================
void ffw::GuiCheckbox::SetIndent(int indent_){
	indent = indent_;
	Invalidate();
}

///=============================================================================
void ffw::GuiCheckbox::SetButtonSize(int width){
	widgetbutton->SetSize(width, width);
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
	(value == true ? widgetbutton->SetFocus() : widgetbutton->ResetFocus());
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
	context->DrawStringAligned(contentoffset + size, contentsize - size, GetCurrentFont(), GetAlign(), label, GetCurrentStyle().text);
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
	// Do nothing
}

///=============================================================================
void ffw::GuiCheckbox::EventFocus(bool gained){
	// Do nothing
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
ffw::Vec2i ffw::GuiCheckbox::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	auto strsize = GetCurrentFont()->GetStringSize(label);
	strsize.x += widgetbutton->GetSize().x.value + indent;
	strsize.y = std::max(strsize.y, widgetbutton->GetSize().y.value);
	return strsize;
}