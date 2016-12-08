/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollbar::GuiScrollbar(GuiWindow* context, bool vertical):GuiWidget(context){
	ignoreinputflag = true;
	
	if(!vertical){
		SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	} else {
		SetSize(GuiUnits::Wrap(), GuiUnits::Percent(100));
	}

	SetMargin(0, 0, 5, 0);
	
	right = new ffw::GuiButton(context, L"");
	left = new ffw::GuiButton(context, L"");
	slider = new ffw::GuiSlider(context, vertical);
	slider->SetCallbackPtr(this);

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xE0E0E0);
	style.normal.borderradius = 0;
	style.normal.bordersize = 0;
	style.active = style.hover = style.normal;

	//right->SetSize(0, 0);
	left->SetPadding(2);
	left->SetMargin(0);

	right->SetPadding(2);
	right->SetMargin(0);

	slider->SetPadding(0);
	slider->SetMargin(0);

	slider->Style().normal.background = false;
	slider->Style().normal.borderradius = 0;
	slider->Style().normal.bordersize = 0;

	slider->Style().hover.background = false;
	slider->Style().hover.borderradius = 0;
	slider->Style().hover.bordersize = 0;

	slider->Style().active.background = false;
	slider->Style().active.borderradius = 0;
	slider->Style().active.bordersize = 0;

	slider->StyleBar().normal.background = false;
	slider->StyleBar().normal.borderradius = 0;
	slider->StyleBar().normal.bordersize = 0;

	slider->StyleBar().hover.background = false;
	slider->StyleBar().hover.borderradius = 0;
	slider->StyleBar().hover.bordersize = 0;

	slider->StyleBar().active.background = false;
	slider->StyleBar().active.borderradius = 0;
	slider->StyleBar().active.bordersize = 0;
	slider->SetColor(ffw::Rgba(0x00000000));

	slider->StyleButton().normal.background = true;
	slider->StyleButton().normal.backgroundcolor = ffw::Rgb(0xCDCDCD);
	slider->StyleButton().normal.bordersize = 0;
	slider->StyleButton().normal.borderradius = 0;

	slider->StyleButton().hover.background = true;
	slider->StyleButton().hover.backgroundcolor = ffw::Rgb(0xA6A6A6);
	slider->StyleButton().hover.bordersize = 0;
	slider->StyleButton().hover.borderradius = 0;

	slider->StyleButton().active.background = true;
	slider->StyleButton().active.backgroundcolor = ffw::Rgb(0x606060);
	slider->StyleButton().active.bordersize = 0;
	slider->StyleButton().active.borderradius = 0;

	left->Style().normal.background = false;
	//left->Style().normal.backgroundcolor = ffw::Rgb(0xE0E0E0);
	left->Style().normal.borderradius = 0;
	left->Style().normal.bordersize = 0;
	left->Style().normal.textcolor = ffw::Rgb(0xA6A6A6);

	left->Style().hover.background = true;
	left->Style().hover.backgroundcolor = ffw::Rgb(0xA6A6A6);
	left->Style().hover.borderradius = 0;
	left->Style().hover.bordersize = 0;
	left->Style().hover.textcolor = ffw::Rgb(0x606060);

	left->Style().active.background = true;
	left->Style().active.backgroundcolor = ffw::Rgb(0x606060);
	left->Style().active.borderradius = 0;
	left->Style().active.bordersize = 0;
	left->Style().active.textcolor = ffw::Rgb(0xEEEEEE);

	right->Style() = left->Style();

	EventSize(GetVisibleContentSize());

	if(vertical){
		left->SetSymbol(&ffw::GuiSymbol::ArrowTop);
		right->SetSymbol(&ffw::GuiSymbol::ArrowBottom);
		this->SetOrientation(ffw::GuiLayout::Orientation::VERTICAL);
	} else {
		left->SetSymbol(&ffw::GuiSymbol::ArrowLeft);
		right->SetSymbol(&ffw::GuiSymbol::ArrowRight);
		this->SetOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
	}

	slider->SetRange(0, 100);
	slider->SetValue(50);
	increments = 10;

	left->SetOnClickCallback(&GuiScrollbar::ButtonCallback, this);
	right->SetOnClickCallback(&GuiScrollbar::ButtonCallback, this);

	this->AddWidget(left);
	this->AddWidget(slider);
	this->AddWidget(right);
}

///=============================================================================
ffw::GuiScrollbar::~GuiScrollbar(){
}

///=============================================================================
void ffw::GuiScrollbar::ButtonCallback(ffw::GuiEvent e){
	int val = slider->GetValue();

	if(e.widget == left){
		slider->SetValue(val - increments);

	} else {
		slider->SetValue(val + increments);
	}

	Redraw();
}

///=============================================================================
ffw::GuiStyleGroup& ffw::GuiScrollbar::StyleLeft(){
	return left->Style();
}

///=============================================================================
ffw::GuiStyleGroup& ffw::GuiScrollbar::StyleRight() {
	return right->Style();
}

///=============================================================================
ffw::GuiStyleGroup& ffw::GuiScrollbar::StyleButton() {
	return slider->StyleButton();
}

///=============================================================================
const ffw::GuiStyleGroup& ffw::GuiScrollbar::StyleLeft() const {
	return left->Style();
}

///=============================================================================
const ffw::GuiStyleGroup& ffw::GuiScrollbar::StyleRight() const {
	return right->Style();
}

///=============================================================================
const ffw::GuiStyleGroup& ffw::GuiScrollbar::StyleButton() const {
	return slider->StyleButton();
}

///=============================================================================
void ffw::GuiScrollbar::SetValue(int val){
	slider->SetValue(val);
}

///=============================================================================
int ffw::GuiScrollbar::GetValue() const{
	return slider->GetValue();
}

///=============================================================================
const ffw::Vec2i& ffw::GuiScrollbar::GetRange() const{
	return slider->GetRange();
}

///=============================================================================
void ffw::GuiScrollbar::SetRange(int min, int max){
	slider->SetRange(min, max);
}

///=============================================================================
int ffw::GuiScrollbar::GetIncrement() const {
	return increments;
}

///=============================================================================
void ffw::GuiScrollbar::SetIncrement(int inc){
	increments = inc;
}

///=============================================================================
void ffw::GuiScrollbar::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
}

///=============================================================================
void ffw::GuiScrollbar::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiScrollbar::EventSize(const ffw::Vec2i& size){
	if(slider->IsVertical()){
		left->SetSize(size.x, size.x);
		right->SetSize(size.x, size.x);
		slider->SetSize(size.x, size.y - size.x*2);
		slider->SetButtonSize(size.x);
	} else {
		left->SetSize(size.y, size.y);
		right->SetSize(size.y, size.y);
		slider->SetSize(size.x - size.y*2, size.y);
		slider->SetButtonSize(size.y);
	}
	Redraw();
}

///=============================================================================
void ffw::GuiScrollbar::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiScrollbar::EventFocus(bool gained){
}

///=============================================================================
void ffw::GuiScrollbar::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiScrollbar::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiScrollbar::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiScrollbar::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollbar::GetMinimumWrapSize() const {
	ffw::Vec2i s;

	auto slidermin = slider->GetMinimumWrapSize();
	auto leftmin = left->GetMinimumWrapSize();
	auto rightmin = left->GetMinimumWrapSize();

	if(slider->IsVertical()){
		s.x = std::min(slidermin.x, std::min(leftmin.x, rightmin.x));
		s.y = slidermin.y + leftmin.y + rightmin.y;
	} else {
		s.x = slidermin.x + leftmin.x + rightmin.x;
		s.y = std::min(slidermin.y, std::min(leftmin.y, rightmin.y));
	}

	return s;
}