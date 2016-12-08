/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibuttonToggle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::string& label_):GuiButtonToggle(context, Utf8ToWstr(label_)){
}

///=============================================================================
ffw::GuiButtonToggle::GuiButtonToggle(GuiWindow* context, const std::wstring& label_):GuiWidget(context),label(label_){
	togglefocusflag = true;
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetAlign(GuiAlign::CENTER);
	SetMargin(0, 0, 5, 0);
	SetPadding(5);

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xE1E1E1);
	style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xADADAD);
	style.normal.textcolor = ffw::Rgb(0x222222);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xE5F1FB);
	style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0x0078D7);
	style.hover.textcolor = ffw::Rgb(0x222222);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xCCE4F7);
	style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0x005499);
	style.active.textcolor = ffw::Rgb(0x222222);

	onclickcallback = nullptr;
}

///=============================================================================
ffw::GuiButtonToggle::~GuiButtonToggle(){
}

///=============================================================================
void ffw::GuiButtonToggle::SetLabel(const std::wstring& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiButtonToggle::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiButtonToggle::SetValue(bool value){
	(value == true ? GuiWidget::SetFocus() : GuiWidget::ResetFocus());
}

///=============================================================================
bool ffw::GuiButtonToggle::GetValue() const {
	return GuiWidget::HasFocus();
}

///=============================================================================
void ffw::GuiButtonToggle::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label);
}

///=============================================================================
void ffw::GuiButtonToggle::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiButtonToggle::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiButtonToggle::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiButtonToggle::EventFocus(bool gained){
	Redraw();

	GuiEventData dat;
	dat.clicked.value = gained;
	context->PushEvent(onclickcallback, {GetCallbackPtr(), GuiEventType::CLICKED, dat});
}

///=============================================================================
void ffw::GuiButtonToggle::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiButtonToggle::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiButtonToggle::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiButtonToggle::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiButtonToggle::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label);
}