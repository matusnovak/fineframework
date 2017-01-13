/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollbar::ButtonLeft::ButtonLeft(GuiWindow* context):GuiButton(context, "") {
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_BUTTON_LEFT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollbar::ButtonLeft::~ButtonLeft() {

}

///=============================================================================
void ffw::GuiScrollbar::ButtonLeft::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR_BUTTON_LEFT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollbar::ButtonRight::ButtonRight(GuiWindow* context):GuiButton(context, "") {
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_BUTTON_RIGHT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollbar::ButtonRight::~ButtonRight() {

}

///=============================================================================
void ffw::GuiScrollbar::ButtonRight::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR_BUTTON_RIGHT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollbar::Scroll::Scroll(GuiWindow* context, bool vertical):GuiSlider(context, vertical) {
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_SLIDER");
	SetDefaults(&widgetStyle->defaults);
	styleBar = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BAR");
	styleButton = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BUTTON");
}

///=============================================================================
ffw::GuiScrollbar::Scroll::~Scroll() {

}

///=============================================================================
void ffw::GuiScrollbar::Scroll::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR_SLIDER");
	SetDefaults(&widgetStyle->defaults);
	styleBar = &theme->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BAR");
	styleButton = &theme->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BUTTON");
}

///=============================================================================
ffw::GuiScrollbar::GuiScrollbar(GuiWindow* context, bool vertical) :
	GuiWidget(context){
	dropfocusflag = true;

	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR");
	SetDefaults(&widgetStyle->defaults);

	if (vertical) {
		auto s = GetSize();
		SetSize(s.y, s.x);
	}

	right = new GuiScrollbar::ButtonRight(context);
	left = new GuiScrollbar::ButtonLeft(context);
	slider = new GuiScrollbar::Scroll(context, vertical);

	//right->SetSize(0, 0);
	left->SetPadding(2);
	left->SetMargin(0);

	right->SetPadding(2);
	right->SetMargin(0);

	slider->SetPadding(0);
	slider->SetMargin(0);

	Recalculate(GetVisibleContentSize());

	if (vertical) {
		//left->SetSymbol(&ffw::GuiSymbol::ArrowTop);
		//right->SetSymbol(&ffw::GuiSymbol::ArrowBottom);
		this->SetOrientation(ffw::GuiLayout::Orientation::VERTICAL);
	}
	else {
		//left->SetSymbol(&ffw::GuiSymbol::ArrowLeft);
		//right->SetSymbol(&ffw::GuiSymbol::ArrowRight);
		this->SetOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
	}

	slider->SetRange(0, 100);
	slider->SetValue(50);
	slider->SetButtonSize(ffw::GuiPixels(12));
	slider->SetCallbackPtr(this);
	increments = 10;

	left->AddEventCallback(&GuiScrollbar::ButtonCallback, this, true);
	right->AddEventCallback(&GuiScrollbar::ButtonCallback, this, true);

	this->AddWidgetInternal(left);
	this->AddWidgetInternal(slider);
	this->AddWidgetInternal(right);
}

///=============================================================================
ffw::GuiScrollbar::~GuiScrollbar() {
}

///=============================================================================
void ffw::GuiScrollbar::ButtonCallback(ffw::GuiEvent e) {
	if (e.type == ffw::GuiEvent::Type::CLICKED) {
		int val = slider->GetValue();

		if (e.widget == left) {
			slider->SetValue(val - increments);

		}
		else {
			slider->SetValue(val + increments);
		}

		Redraw();
	}
}

///=============================================================================
void ffw::GuiScrollbar::Recalculate(const ffw::Vec2i& size) {
	if (slider->IsVertical()) {
		left->SetSize(size.x, size.x);
		right->SetSize(size.x, size.x);
		slider->SetSize(size.x, size.y - size.x * 2);
		slider->SetButtonSize(ffw::GuiPixels(size.x));
	}
	else {
		left->SetSize(size.y, size.y);
		right->SetSize(size.y, size.y);
		slider->SetSize(size.x - size.y * 2, size.y);
		slider->SetButtonSize(ffw::GuiPixels(size.y));
	}
	Invalidate();
	//RecalculateSize();
}

///=============================================================================
void ffw::GuiScrollbar::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiScrollbar::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollbar::EventSize(const ffw::Vec2i& size) {
	Recalculate(size);
	Redraw();
}

///=============================================================================
void ffw::GuiScrollbar::EventHover(bool gained) {
}

///=============================================================================
void ffw::GuiScrollbar::EventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiScrollbar::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollbar::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollbar::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiScrollbar::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollbar::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiScrollbar::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR");
	SetDefaults(&widgetStyle->defaults);

	if (IsVertical()) {
		auto s = GetSize();
		SetSize(s.y, s.x);
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollbar::GetMinimumWrapSize() const {
	ffw::Vec2i s;

	auto slidermin = slider->GetMinimumWrapSize();
	auto leftmin = left->GetMinimumWrapSize();
	auto rightmin = left->GetMinimumWrapSize();

	if (slider->IsVertical()) {
		s.x = std::max(slidermin.x, std::max(leftmin.x, rightmin.x));
		s.y = slidermin.y + leftmin.y + rightmin.y;
	}
	else {
		s.x = slidermin.x + leftmin.x + rightmin.x;
		s.y = std::max(slidermin.y, std::max(leftmin.y, rightmin.y));
	}

	return s;
}