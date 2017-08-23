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
void ffw::GuiScrollBar::ButtonFirst::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	auto radius = std::min(contentsize.x, contentsize.y) / 2.0f;
	auto p = contentoffset + contentsize / 2.0f;
	
	if(top) {
		context->drawTriangle(
			ffw::Vec2f(p.x, p.y - radius),
			ffw::Vec2f(p.x + radius, p.y + radius),
			ffw::Vec2f(p.x - radius, p.y + radius),
			getCurrentStyle()->text.color);
	} 
	else {
		context->drawTriangle(
			ffw::Vec2f(p.x + radius, p.y + radius),
			ffw::Vec2f(p.x + radius, p.y - radius),
			ffw::Vec2f(p.x - radius, p.y),
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
void ffw::GuiScrollBar::ButtonSecond::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	auto radius = std::min(contentsize.x, contentsize.y) / 2.0f;
	auto p = contentoffset + contentsize / 2.0f;

	if (bot) {
		context->drawTriangle(
			ffw::Vec2f(p.x + radius, p.y - radius),
			ffw::Vec2f(p.x - radius, p.y - radius),
			ffw::Vec2f(p.x, p.y + radius),
			getCurrentStyle()->text.color);
	}
	else {
		context->drawTriangle(
			ffw::Vec2f(p.x - radius, p.y + radius),
			ffw::Vec2f(p.x - radius, p.y - radius),
			ffw::Vec2f(p.x + radius, p.y),
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
	auto s = slider->getButtonSize();
	if (slider->isVertical()) {
		s.y = length;
		slider->setButtonSize(s);
	}
	else {
		s.x = length;
		slider->setButtonSize(s);
	}
}

///=============================================================================
void ffw::GuiScrollBar::ButtonCallback(ffw::GuiEvent e) {
	if (e.type == ffw::GuiEvent::Type::CLICKED) {
		float val = slider->getValue();

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
void ffw::GuiScrollBar::recalculate(const ffw::Vec2f& s) {
	if (slider->isVertical()) {
		left->setSize(s.x, s.x);
		right->setSize(s.x, s.x);
		slider->setSize(s.x, s.y - s.x * 2);
	}
	else {
		left->setSize(s.y, s.y);
		right->setSize(s.y, s.y);
		slider->setSize(s.x - s.y * 2, s.y);
	}
	invalidate();
}

///=============================================================================
void ffw::GuiScrollBar::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	(void)contentoffset;
	(void)contentsize;
}

///=============================================================================
void ffw::GuiScrollBar::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiScrollBar::eventSize(const ffw::Vec2f& s) {
	recalculate(s);
	redraw();
}

///=============================================================================
void ffw::GuiScrollBar::eventHover(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiScrollBar::eventFocus(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiScrollBar::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiScrollBar::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiScrollBar::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiScrollBar::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiScrollBar::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiScrollBar::eventDisabled(bool disabled) {
	(void)disabled;
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
ffw::Vec2f ffw::GuiScrollBar::getMinimumWrapSize() {
	ffw::Vec2f s;

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