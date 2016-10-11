/*** This file is part of FineFramework project ***/

#include "ffw/gui/guicheckbox.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiCheckboxBtn::GuiCheckboxBtn(GuiWindow* context):GuiWidget(context){
	togglefocusflag = true;
	SetPadding(GuiUnits::Percent(20));

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.normal.border = true;
	style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0x222222);
	style.normal.textcolor = ffw::Rgba(0x22222200);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.hover.border = true;
	style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0x0078D7);
	style.hover.textcolor = ffw::Rgba(0x22222280);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.active.border = true;
	style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0x222222);
	style.active.textcolor = ffw::Rgb(0x222222);

	onclickcallback = nullptr;
}

///=============================================================================
ffw::GuiCheckboxBtn::~GuiCheckboxBtn(){
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawRectangle(contentoffset, contentsize);
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventFocus(bool gained){
	Redraw();

	context->PushEvent(onclickcallback, {parentcheckbox, GuiEventType::CLICKED});
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiCheckboxBtn::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiCheckboxBtn::GetMinimumWrapSize() const {
	return 0;
}

///=============================================================================
ffw::GuiCheckbox::GuiCheckbox(GuiWindow* context, const std::string& label_):GuiWidget(context),label(label_){
	SetOrientation(Orientation::HORIZONTAL);
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetMargin(0, 0, 5, 0);
	SetAlign(GuiAlign::LEFT);
	ignoreinputflag = true;

	widgetbutton = new GuiCheckboxBtn(context);
	widgetbutton->SetSize(16, 16);
	indent = int(16 * 0.2);
	widgetbutton->SetMargin(0, 5, 0, 0);

	AddWidget(widgetbutton);

	//style.normal.border = true;
	//style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xFF0000);
	style.normal.textcolor = ffw::Rgb(0x222222);

	//style.hover.border = true;
	//style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0xFF0000);
	style.hover.textcolor = ffw::Rgb(0x222222);

	//style.active.border = true;
	//style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0xFF0000);
	style.active.textcolor = ffw::Rgb(0x222222);

	widgetbutton->parentcheckbox = this;
}

///=============================================================================
ffw::GuiCheckbox::~GuiCheckbox(){
	DeleteWidgets();
}

///=============================================================================
void ffw::GuiCheckbox::SetLabel(const std::string& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::string& ffw::GuiCheckbox::GetLabel() const {
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
	size.x += indent;
	size.y = 0;
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawStringAligned(contentoffset + size, contentsize - size, GetCurrentFont(), GetAlign(), label);
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