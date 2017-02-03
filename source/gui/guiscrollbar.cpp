/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollBar::ButtonFirst::ButtonFirst(GuiWindow* context, bool vertical):GuiButton(context, "") {
	widgetStyle = &context->GetTheme()->GetStyleGroup((vertical ? "GUI_SCROLLBAR_BUTTON_TOP" : "GUI_SCROLLBAR_BUTTON_LEFT"));
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollBar::ButtonFirst::~ButtonFirst() {

}

///=============================================================================
void ffw::GuiScrollBar::ButtonFirst::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR_BUTTON_LEFT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollBar::ButtonSecond::ButtonSecond(GuiWindow* context, bool vertical):GuiButton(context, "") {
	widgetStyle = &context->GetTheme()->GetStyleGroup((vertical ? "GUI_SCROLLBAR_BUTTON_BOTTOM" : "GUI_SCROLLBAR_BUTTON_RIGHT"));
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollBar::ButtonSecond::~ButtonSecond() {

}

///=============================================================================
void ffw::GuiScrollBar::ButtonSecond::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR_BUTTON_RIGHT");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollBar::Scroll::Scroll(GuiWindow* context, bool vertical):GuiSlider(context, vertical) {
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_SLIDER");
	SetDefaults(&widgetStyle->defaults);
	styleBar = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BAR");
	styleButton = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BUTTON");

	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	if (IsVertical()) {
		auto s = GetSize();
		SetSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}
}

///=============================================================================
ffw::GuiScrollBar::Scroll::~Scroll() {

}

///=============================================================================
void ffw::GuiScrollBar::Scroll::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR_SLIDER");
	SetDefaults(&widgetStyle->defaults);
	styleBar = &theme->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BAR");
	styleButton = &theme->GetStyleGroup("GUI_SCROLLBAR_SLIDER_BUTTON");

	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	if (IsVertical()) {
		auto s = GetSize();
		SetSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}
}

///=============================================================================
ffw::GuiScrollBar::GuiScrollBar(GuiWindow* context, bool vertical) :
	GuiWidget(context){
	dropfocusflag = true;

	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SCROLLBAR");
	SetDefaults(&widgetStyle->defaults);

	if (vertical) {
		auto s = GetSize();
		SetSize(s.y, s.x);
	}

	left = new GuiScrollBar::ButtonFirst(context, vertical);
	right = new GuiScrollBar::ButtonSecond(context, vertical);
	slider = new GuiScrollBar::Scroll(context, vertical);

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
	//slider->SetButtonSize(ffw::GuiPixels(12));
	slider->SetCallbackPtr(this);
	increments = 10;

	left->AddEventCallback(&GuiScrollBar::ButtonCallback, this, true);
	right->AddEventCallback(&GuiScrollBar::ButtonCallback, this, true);

	this->AddWidgetInternal(left);
	this->AddWidgetInternal(slider);
	this->AddWidgetInternal(right);
}

///=============================================================================
ffw::GuiScrollBar::~GuiScrollBar() {
}

///=============================================================================
void ffw::GuiScrollBar::SetButtonLength(GuiUnits length) {
	auto size = slider->GetButtonSize();
	if (slider->IsVertical()) {
		size.y = length;
		slider->SetButtonSize(size);
	}
	else {
		size.x = length;
		slider->SetButtonSize(size);
	}
}

///=============================================================================
void ffw::GuiScrollBar::ButtonCallback(ffw::GuiEvent e) {
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
void ffw::GuiScrollBar::Recalculate(const ffw::Vec2i& size) {
	if (slider->IsVertical()) {
		left->SetSize(size.x, size.x);
		right->SetSize(size.x, size.x);
		slider->SetSize(size.x, size.y - size.x * 2);
		//slider->SetButtonSize(ffw::GuiPixels(size.x));
		//slider->SetButtonSize(ffw::Vec2<GuiUnits>(ffw::GuiPercent(100), buttonLength));
	}
	else {
		left->SetSize(size.y, size.y);
		right->SetSize(size.y, size.y);
		slider->SetSize(size.x - size.y * 2, size.y);
		//slider->SetButtonSize(ffw::GuiPixels(size.y));
		//slider->SetButtonSize(ffw::Vec2<GuiUnits>(buttonLength, ffw::GuiPercent(100)));
	}
	Invalidate();
	//RecalculateSize();
}

///=============================================================================
void ffw::GuiScrollBar::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiScrollBar::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollBar::EventSize(const ffw::Vec2i& size) {
	Recalculate(size);
	Redraw();
}

///=============================================================================
void ffw::GuiScrollBar::EventHover(bool gained) {
}

///=============================================================================
void ffw::GuiScrollBar::EventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiScrollBar::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollBar::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollBar::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiScrollBar::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollBar::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiScrollBar::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLBAR");
	SetDefaults(&widgetStyle->defaults);

	if (IsVertical()) {
		auto s = GetSize();
		SetSize(s.y, s.x);
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollBar::GetMinimumWrapSize() {
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