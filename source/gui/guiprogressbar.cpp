/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogressbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiProgressBar::GuiProgressBar(GuiWindow* context, const std::string& label_):GuiWidget(context),label(label_){
	SetAlign(GuiAlign::CENTER);
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetMargin(0, 0, 5, 0);

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xE6E6E6);
	style.normal.border = true;
	style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xBCBCBC);
	style.normal.textcolor = ffw::Rgb(0x222222);

	style.hover.background = false;
	style.hover.backgroundcolor = ffw::Rgb(0xE6E6E6);
	style.hover.border = true;
	style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0xBCBCBC);
	style.hover.textcolor = ffw::Rgb(0x222222);

	style.active.background = false;
	style.active.backgroundcolor = ffw::Rgb(0xE6E6E6);
	style.active.border = true;
	style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0xBCBCBC);
	style.active.textcolor = ffw::Rgb(0x222222);

	color = ffw::Rgb(0x00AB1C);
	value = 50;
	range.Set(0, 100);
}

///=============================================================================
ffw::GuiProgressBar::~GuiProgressBar(){
}

///=============================================================================
void ffw::GuiProgressBar::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(color);

	int width = ((value - range.x) / float(range.y)) * contentsize.x;
	width = ffw::Clamp(width, 0, contentsize.x);

	context->DrawRectangle(contentoffset, ffw::Vec2i(width, contentsize.y));

	context->SetDrawColor(stl.textcolor);
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label);
}

///=============================================================================
void ffw::GuiProgressBar::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiProgressBar::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiProgressBar::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiProgressBar::EventFocus(bool gained){
}

///=============================================================================
void ffw::GuiProgressBar::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiProgressBar::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiProgressBar::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiProgressBar::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiProgressBar::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label);
}