/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollbar.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollBar::ButtonFirst::ButtonFirst(GuiWindow* context, bool vertical):GuiButton(context, "") {
	widgetStyle = &context->getTheme()->getStyleGroup((vertical ? "GUI_SCROLLBAR_BUTTON_TOP" : "GUI_SCROLLBAR_BUTTON_LEFT"));
	setDefaults(&widgetStyle->defaults);
	top = vertical;
}

///=============================================================================
ffw::GuiScrollBar::ButtonFirst::~ButtonFirst() {

}

///=============================================================================
void ffw::GuiScrollBar::ButtonFirst::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	auto radius = std::min(contentsize.x, contentsize.y) / 2;
	auto pos = contentoffset + contentsize / 2;
	
	if(top) {
		context->drawTriangle(
			ffw::Vec2i(pos.x, pos.y - radius),
			ffw::Vec2i(pos.x + radius, pos.y + radius),
			ffw::Vec2i(pos.x - radius, pos.y + radius),
			getCurrentStyle()->text.color);
	} 
	else {
		context->drawTriangle(
			ffw::Vec2i(pos.x + radius, pos.y + radius),
			ffw::Vec2i(pos.x + radius, pos.y - radius),
			ffw::Vec2i(pos.x - radius, pos.y),
			getCurrentStyle()->text.color);
	}
}

///=============================================================================
void ffw::GuiScrollBar::ButtonFirst::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SCROLLBAR_BUTTON_LEFT");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollBar::ButtonSecond::ButtonSecond(GuiWindow* context, bool vertical):GuiButton(context, "") {
	widgetStyle = &context->getTheme()->getStyleGroup((vertical ? "GUI_SCROLLBAR_BUTTON_BOTTOM" : "GUI_SCROLLBAR_BUTTON_RIGHT"));
	setDefaults(&widgetStyle->defaults);
	bot = vertical;
}

///=============================================================================
ffw::GuiScrollBar::ButtonSecond::~ButtonSecond() {

}

///=============================================================================
void ffw::GuiScrollBar::ButtonSecond::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	auto radius = std::min(contentsize.x, contentsize.y) / 2;
	auto pos = contentoffset + contentsize / 2;

	if (bot) {
		context->drawTriangle(
			ffw::Vec2i(pos.x + radius, pos.y - radius),
			ffw::Vec2i(pos.x - radius, pos.y - radius),
			ffw::Vec2i(pos.x, pos.y + radius),
			getCurrentStyle()->text.color);
	}
	else {
		context->drawTriangle(
			ffw::Vec2i(pos.x - radius, pos.y + radius),
			ffw::Vec2i(pos.x - radius, pos.y - radius),
			ffw::Vec2i(pos.x + radius, pos.y),
			getCurrentStyle()->text.color);
	}
}

///=============================================================================
void ffw::GuiScrollBar::ButtonSecond::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SCROLLBAR_BUTTON_RIGHT");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiScrollBar::Scroll::Scroll(GuiWindow* context, bool vertical):GuiSlider(context, vertical) {
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_SCROLLBAR_SLIDER");
	setDefaults(&widgetStyle->defaults);
	styleBar = &context->getTheme()->getStyleGroup("GUI_SCROLLBAR_SLIDER_BAR");
	styleButton = &context->getTheme()->getStyleGroup("GUI_SCROLLBAR_SLIDER_BUTTON");

	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	if (isVertical()) {
		auto s = getSize();
		setSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}
}

///=============================================================================
ffw::GuiScrollBar::Scroll::~Scroll() {

}

///=============================================================================
void ffw::GuiScrollBar::Scroll::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SCROLLBAR_SLIDER");
	setDefaults(&widgetStyle->defaults);
	styleBar = &theme->getStyleGroup("GUI_SCROLLBAR_SLIDER_BAR");
	styleButton = &theme->getStyleGroup("GUI_SCROLLBAR_SLIDER_BUTTON");

	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	if (isVertical()) {
		auto s = getSize();
		setSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}
}

///=============================================================================
ffw::GuiScrollBar::GuiScrollBar(GuiWindow* context, bool vertical) :
	GuiWidget(context){
	setIgnoreUserInput(true);

	widgetStyle = &context->getTheme()->getStyleGroup("GUI_SCROLLBAR");
	setDefaults(&widgetStyle->defaults);

	if (vertical) {
		auto s = getSize();
		setSize(s.y, s.x);
	}

	left = new GuiScrollBar::ButtonFirst(context, vertical);
	right = new GuiScrollBar::ButtonSecond(context, vertical);
	slider = new GuiScrollBar::Scroll(context, vertical);

	//right->setSize(0, 0);
	//left->setPadding(2);
	left->setMargin(0);

	//right->setPadding(2);
	right->setMargin(0);

	//slider->setPadding(0);
	slider->setMargin(0);

	recalculate(getVisibleContentSize());

	if (vertical) {
		//left->setSymbol(&ffw::GuiSymbol::ArrowTop);
		//right->setSymbol(&ffw::GuiSymbol::ArrowBottom);
		this->setOrientation(ffw::GuiLayout::Orientation::VERTICAL);
	}
	else {
		//left->setSymbol(&ffw::GuiSymbol::ArrowLeft);
		//right->setSymbol(&ffw::GuiSymbol::ArrowRight);
		this->setOrientation(ffw::GuiLayout::Orientation::HORIZONTAL);
	}

	slider->setRange(0, 100);
	slider->setValue(50);
	//slider->setButtonSize(ffw::guiPixels(12));
	slider->setCallbackPtr(this);
	increments = 10;

	left->addEventCallback(&GuiScrollBar::ButtonCallback, this, true);
	right->addEventCallback(&GuiScrollBar::ButtonCallback, this, true);

	this->addWidgetInternal(left);
	this->addWidgetInternal(slider);
	this->addWidgetInternal(right);
}

///=============================================================================
ffw::GuiScrollBar::~GuiScrollBar() {
}

///=============================================================================
void ffw::GuiScrollBar::setButtonLength(GuiUnits length) {
	auto size = slider->getButtonSize();
	if (slider->isVertical()) {
		size.y = length;
		slider->setButtonSize(size);
	}
	else {
		size.x = length;
		slider->setButtonSize(size);
	}
}

///=============================================================================
void ffw::GuiScrollBar::ButtonCallback(ffw::GuiEvent e) {
	if (e.type == ffw::GuiEvent::Type::CLICKED) {
		int val = slider->getValue();

		if (e.widget == left) {
			slider->setValue(val - increments);

		}
		else {
			slider->setValue(val + increments);
		}

		redraw();
	}
}

///=============================================================================
void ffw::GuiScrollBar::recalculate(const ffw::Vec2i& size) {
	if (slider->isVertical()) {
		left->setSize(size.x, size.x);
		right->setSize(size.x, size.x);
		slider->setSize(size.x, size.y - size.x * 2);
	}
	else {
		left->setSize(size.y, size.y);
		right->setSize(size.y, size.y);
		slider->setSize(size.x - size.y * 2, size.y);
	}
	invalidate();
}

///=============================================================================
void ffw::GuiScrollBar::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiScrollBar::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollBar::eventSize(const ffw::Vec2i& size) {
	recalculate(size);
	redraw();
}

///=============================================================================
void ffw::GuiScrollBar::eventHover(bool gained) {
}

///=============================================================================
void ffw::GuiScrollBar::eventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiScrollBar::eventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollBar::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollBar::eventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiScrollBar::eventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollBar::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiScrollBar::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SCROLLBAR");
	setDefaults(&widgetStyle->defaults);

	if (isVertical()) {
		auto s = getSize();
		setSize(s.y, s.x);
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollBar::getMinimumWrapSize() {
	ffw::Vec2i s;

	auto slidermin = slider->getMinimumWrapSize();
	auto leftmin = left->getMinimumWrapSize();
	auto rightmin = left->getMinimumWrapSize();

	if (slider->isVertical()) {
		s.x = std::max(slidermin.x, std::max(leftmin.x, rightmin.x));
		s.y = slidermin.y + leftmin.y + rightmin.y;
	}
	else {
		s.x = slidermin.x + leftmin.x + rightmin.x;
		s.y = std::max(slidermin.y, std::max(leftmin.y, rightmin.y));
	}

	return s;
}