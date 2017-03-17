/*** This file is part of FineFramework project ***/

#include "ffw/gui/guislider.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSlider::GuiSlider(GuiWindow* context, bool vertical_):GuiWidget(context),vertical(vertical_){
	setDropFocus();

	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_SLIDER");
	styleBar = &context->getTheme()->getStyleGroup("GUI_SLIDER_BAR");
	styleButton = &context->getTheme()->getStyleGroup("GUI_SLIDER_BUTTON");
	setDefaults(&widgetStyle->defaults);

	setMargin(0, 0, 5, 0);

	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	inverse = false;

	if (vertical) {
		auto s = getSize();
		setSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}

	value = 50;
	range.set(0, 100);
}

///=============================================================================
ffw::GuiSlider::~GuiSlider(){
}

///=============================================================================
bool ffw::GuiSlider::isVertical() const {
	return vertical;
}

///=============================================================================
void ffw::GuiSlider::setBarSize(const ffw::Vec2<GuiUnits>& s) {
	barSize = s;
	redraw();
}

///=============================================================================
void ffw::GuiSlider::setButtonSize(const ffw::Vec2<GuiUnits>& s) {
	buttonSize = s;
	redraw();
}

///=============================================================================
void ffw::GuiSlider::setValue(int val){
	if(inverse) {
		val = (range.y - range.x) - val;
	}
	int old = value;
	value = ffw::clamp(val, range.x, range.y);
	if(old != value){
		GuiEvent::Data dat;
		dat.changed.value = getValue();
		pushEvent(GuiEvent::Type::CHANGED, dat);
		redraw();
	}
}

///=============================================================================
int ffw::GuiSlider::getValue() const {
	if (inverse)return (range.y - range.x) - value;
	return value;
}

///=============================================================================
const ffw::Vec2i& ffw::GuiSlider::getRange() const {
	return range;
}

///=============================================================================
void ffw::GuiSlider::setRange(int min, int max){
	range.set(min, max);
	int old = value;
	value = ffw::clamp(value, range.x, range.y);
	if(old != value){
		GuiEvent::Data dat;
		dat.changed.value = getValue();
		pushEvent(GuiEvent::Type::CHANGED, dat);
	}
	redraw();
}

///=============================================================================
void ffw::GuiSlider::setInversed(bool inversed){
	inverse = inversed;
	redraw();
}

///=============================================================================
bool ffw::GuiSlider::getInversed() const {
	return inverse;
}

///=============================================================================
void ffw::GuiSlider::calculateButtonSize(ffw::Vec2i& pos, ffw::Vec2i& size) const {
	auto contentsize = getVisibleContentSize();
	size = ffw::Vec2i(buttonSize.x.toReal(contentsize.x), buttonSize.y.toReal(contentsize.y));
	const auto thick = ffw::Vec2i(barSize.x.toReal(contentsize.x), barSize.y.toReal(contentsize.y));

	if (vertical) {
		int height = 0;

		if (inverse) {
			height = int((1.0f - ((value - range.x) / float(range.y))) * thick.y);
		}
		else {
			height = int(((value - range.x) / float(range.y)) * thick.y);
		}
		height = ffw::clamp(height, 0, thick.y);

		height = int(((value - range.x) / float(range.y)) * (contentsize.y - size.y));
		height = ffw::clamp(height, 0, (contentsize.y - size.y));

		pos.set(0, 0);
		pos.x += contentsize.x / 2;
		pos.y += height;
		pos.x -= size.x / 2;
	}
	else {
		int width = 0;

		if (inverse) {
			width = int((1.0f - ((value - range.x) / float(range.y))) * thick.x);
		}
		else {
			width = int(((value - range.x) / float(range.y)) * thick.x);
		}
		width = ffw::clamp(width, 0, thick.x);

		width = int(((value - range.x) / float(range.y)) * (contentsize.x - size.x));
		width = ffw::clamp(width, 0, (contentsize.x - size.x));

		pos.set(0, 0);
		pos.y += contentsize.y / 2;
		pos.x += width;
		pos.y -= size.y / 2;
	}
}

///=============================================================================
void ffw::GuiSlider::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto* cStyleBar = getCurrentStyle(styleBar);
	const auto* cStyleButton = getCurrentStyle(styleButton);

	if (cStyleBar == NULL || cStyleButton == NULL)return;

	auto test = std::abs(range.x - range.y);
	if (test == 0)return;

	auto buttonSizeReal = ffw::Vec2i(buttonSize.x.toReal(contentsize.x), buttonSize.y.toReal(contentsize.y));

	if(vertical){
		int height = 0;
		const auto thick = ffw::Vec2i(barSize.x.toReal(contentsize.x), barSize.y.toReal(contentsize.y));
		ffw::Vec2i off(contentsize.x / 2 - thick.x / 2, contentsize.y / 2 - thick.y / 2);
		ffw::Vec2i pos(contentoffset + off);
		ffw::Vec2i size(thick.x, thick.y);
		
		if(inverse){
			height = int((1.0f - ((value - range.x) / float(range.y))) * thick.y);
		} else {
			height = int(((value - range.x) / float(range.y)) * thick.y);
		}
		height = ffw::clamp(height, 0, thick.y);

		renderComponent(pos, thick, cStyleBar);

		size.y = height;
		if(cStyleBar->border.size[0]){
			size.y -= cStyleBar->border.size[0];
			pos.y += cStyleBar->border.size[0];
		}
		if(cStyleBar->border.size[1]){
			size.x -= cStyleBar->border.size[1];
		}
		if(cStyleBar->border.size[2]){
			size.y -= cStyleBar->border.size[2];
		}
		if(cStyleBar->border.size[3]){
			size.x -= cStyleBar->border.size[3];
			pos.x += cStyleBar->border.size[0];
		}

		if(cStyleBar->function.color.a > 0.0f && size.y > 0){
			if(inverse){
				context->drawRectangle(pos + ffw::Vec2i(0, thick.y - height), size, cStyleBar->function.color);
			} else {
				context->drawRectangle(pos, size, cStyleBar->function.color);
			}
		}

		height = int(((value - range.x) / float(range.y)) * (contentsize.y - buttonSizeReal.y));
		height = ffw::clamp(height, 0, (contentsize.y - buttonSizeReal.y));

		pos.set(contentoffset);
		pos.x += contentsize.x / 2;
		pos.y += height;
		pos.x -= buttonSizeReal.x /2;

		renderComponent(pos, buttonSizeReal, cStyleButton);

	} else {
		int width = 0;
		const auto thick = ffw::Vec2i(barSize.x.toReal(contentsize.x), barSize.y.toReal(contentsize.y));
		ffw::Vec2i off(contentsize.x / 2 - thick.x / 2, contentsize.y / 2 - thick.y / 2);
		ffw::Vec2i pos(contentoffset + off);
		ffw::Vec2i size(contentsize.x, thick.y);
		
		if(inverse){
			width = int((1.0f - ((value - range.x) / float(range.y))) * thick.x);
		} else {
			width = int(((value - range.x) / float(range.y)) * thick.x);
		}
		width = ffw::clamp(width, 0, thick.x);

		renderComponent(pos, thick, cStyleBar);

		size.x = width;
		if(cStyleBar->border.size[0]){
			size.y -= cStyleBar->border.size[0];
			pos.y += cStyleBar->border.size[0];
		}
		if(cStyleBar->border.size[1]){
			size.x -= cStyleBar->border.size[1];
		}
		if(cStyleBar->border.size[2]){
			size.y -= cStyleBar->border.size[2];
		}
		if(cStyleBar->border.size[3]){
			size.x -= cStyleBar->border.size[3];
			pos.x += cStyleBar->border.size[0];
		}

		if(cStyleBar->function.color.a > 0.0f && size.x > 0){
			if(inverse){
				context->drawRectangle(pos + ffw::Vec2i(thick.x - width, 0), size, cStyleBar->function.color);
			} else {
				context->drawRectangle(pos, size, cStyleBar->function.color);
			}
		}

		width = int(((value - range.x) / float(range.y)) * (contentsize.x - buttonSizeReal.x));
		width = ffw::clamp(width, 0, (contentsize.x - buttonSizeReal.x));

		pos.set(contentoffset);
		pos.y += contentsize.y / 2;
		pos.x += width;
		pos.y -= buttonSizeReal.y /2;

		renderComponent(pos, buttonSizeReal, cStyleButton);
	}
}

///=============================================================================
void ffw::GuiSlider::eventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiSlider::eventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiSlider::eventHover(bool gained){
	redraw();
}

///=============================================================================
void ffw::GuiSlider::eventFocus(bool gained){
	redraw();
}

///=============================================================================
void ffw::GuiSlider::eventMouse(const ffw::Vec2i& pos){
	if(hasFocus()){
		auto newPos = pos - clickedOffset;
		int newvalue = value;
		auto realSize = getVisibleContentSize();
		auto btnSize = ffw::Vec2i(buttonSize.x.toReal(realSize.x), buttonSize.y.toReal(realSize.y));
		if(vertical){
			int height = realSize.y - btnSize.y;
			float frac = ffw::clamp((newPos.y - btnSize.y/2) / float(height), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		} else {
			int width = realSize.x - btnSize.x;
			float frac = ffw::clamp((newPos.x - btnSize.x/2) / float(width), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		}
		if(newvalue != value){
			value = newvalue;
			GuiEvent::Data dat;
			dat.changed.value = getValue();
			pushEvent(GuiEvent::Type::CHANGED, dat);
			redraw();
		}
	}
}

///=============================================================================
void ffw::GuiSlider::eventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	if(button == ffw::MouseButton::LEFT && mode == ffw::Mode::PRESSED){
		auto mouse = getMousePos();
		ffw::Vec2i buttonPos, buttonSize;
		calculateButtonSize(buttonPos, buttonSize);
		clickedOffset = mouse - buttonPos;
		if (clickedOffset.x < 0 || clickedOffset.x > buttonSize.x ||
			clickedOffset.y < 0 || clickedOffset.y > buttonSize.y) {

			clickedOffset = 0;
		} else {
			clickedOffset -= buttonSize / 2;
		}
		
		GuiEvent::Data dat;
		dat.clicked.value = true;
		pushEvent(GuiEvent::Type::CLICKED, dat);
		eventMouse(mouse);
	}
}

///=============================================================================
void ffw::GuiSlider::eventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiSlider::eventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiSlider::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiSlider::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SLIDER");
	styleBar = &theme->getStyleGroup("GUI_SLIDER_BAR");
	styleButton = &theme->getStyleGroup("GUI_SLIDER_BUTTON");
	setDefaults(&widgetStyle->defaults);
	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	if (vertical) {
		auto s = getSize();
		setSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiSlider::getMinimumWrapSize() {
	auto realSize = getRealSize();
	auto btnSize = ffw::Vec2i(buttonSize.x.toReal(realSize.x), buttonSize.y.toReal(realSize.y));

	if (vertical)return ffw::Vec2i(btnSize.x, btnSize.y * 2);
	return ffw::Vec2i(btnSize.x * 2, btnSize.y);
}