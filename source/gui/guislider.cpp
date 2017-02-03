/*** This file is part of FineFramework project ***/

#include "ffw/gui/guislider.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSlider::GuiSlider(GuiWindow* context, bool vertical_):GuiWidget(context),vertical(vertical_){
	dropfocusflag = true;

	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_SLIDER");
	styleBar = &context->GetTheme()->GetStyleGroup("GUI_SLIDER_BAR");
	styleButton = &context->GetTheme()->GetStyleGroup("GUI_SLIDER_BUTTON");
	SetDefaults(&widgetStyle->defaults);

	SetMargin(0, 0, 5, 0);

	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	inverse = false;

	if (vertical) {
		auto s = GetSize();
		SetSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}

	value = 50;
	range.Set(0, 100);
}

///=============================================================================
ffw::GuiSlider::~GuiSlider(){
}

///=============================================================================
bool ffw::GuiSlider::IsVertical() const {
	return vertical;
}

///=============================================================================
void ffw::GuiSlider::SetBarSize(const ffw::Vec2<GuiUnits>& s) {
	barSize = s;
	Redraw();
}

///=============================================================================
void ffw::GuiSlider::SetButtonSize(const ffw::Vec2<GuiUnits>& s) {
	buttonSize = s;
	Redraw();
}

///=============================================================================
void ffw::GuiSlider::SetValue(int val){
	if(inverse) {
		val = (range.y - range.x) - val;
	}
	int old = value;
	value = ffw::Clamp(val, range.x, range.y);
	if(old != value){
		GuiEvent::Data dat;
		dat.changed.value = GetValue();
		PushEvent(GuiEvent::Type::CHANGED, dat);
		Redraw();
	}
}

///=============================================================================
int ffw::GuiSlider::GetValue() const {
	if (inverse)return (range.y - range.x) - value;
	return value;
}

///=============================================================================
const ffw::Vec2i& ffw::GuiSlider::GetRange() const {
	return range;
}

///=============================================================================
void ffw::GuiSlider::SetRange(int min, int max){
	range.Set(min, max);
	int old = value;
	value = ffw::Clamp(value, range.x, range.y);
	if(old != value){
		GuiEvent::Data dat;
		dat.changed.value = GetValue();
		PushEvent(GuiEvent::Type::CHANGED, dat);
	}
	Redraw();
}

///=============================================================================
void ffw::GuiSlider::SetInversed(bool inversed){
	inverse = inversed;
	Redraw();
}

///=============================================================================
bool ffw::GuiSlider::GetInversed() const {
	return inverse;
}

///=============================================================================
void ffw::GuiSlider::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto* cStyleBar = GetCurrentStyle(styleBar);
	const auto* cStyleButton = GetCurrentStyle(styleButton);

	if (cStyleBar == NULL || cStyleButton == NULL)return;

	auto test = std::abs(range.x - range.y);
	if (test == 0)return;

	auto buttonSizeReal = ffw::Vec2i(buttonSize.x.ToReal(contentsize.x), buttonSize.y.ToReal(contentsize.y));

	if(vertical){
		int height = 0;
		const auto thick = ffw::Vec2i(barSize.x.ToReal(contentsize.x), barSize.y.ToReal(contentsize.y));
		ffw::Vec2i off(contentsize.x / 2 - thick.x / 2, contentsize.y / 2 - thick.y / 2);
		ffw::Vec2i pos(contentoffset + off);
		ffw::Vec2i size(thick.x, thick.y);
		
		if(inverse){
			height = int((1.0f - ((value - range.x) / float(range.y))) * thick.y);
		} else {
			height = int(((value - range.x) / float(range.y)) * thick.y);
		}
		height = ffw::Clamp(height, 0, thick.y);

		RenderComponent(pos, thick, cStyleBar);

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
				context->DrawRectangle(pos + ffw::Vec2i(0, thick.y - height), size, cStyleBar->function.color);
			} else {
				context->DrawRectangle(pos, size, cStyleBar->function.color);
			}
		}

		height = int(((value - range.x) / float(range.y)) * (contentsize.y - buttonSizeReal.y));
		height = ffw::Clamp(height, 0, (contentsize.y - buttonSizeReal.y));

		pos.Set(contentoffset);
		pos.x += contentsize.x / 2;
		pos.y += height;
		pos.x -= buttonSizeReal.x /2;

		RenderComponent(pos, buttonSizeReal, cStyleButton);

	} else {
		int width = 0;
		const auto thick = ffw::Vec2i(barSize.x.ToReal(contentsize.x), barSize.y.ToReal(contentsize.y));
		ffw::Vec2i off(contentsize.x / 2 - thick.x / 2, contentsize.y / 2 - thick.y / 2);
		ffw::Vec2i pos(contentoffset + off);
		ffw::Vec2i size(contentsize.x, thick.y);
		
		if(inverse){
			width = int((1.0f - ((value - range.x) / float(range.y))) * thick.x);
		} else {
			width = int(((value - range.x) / float(range.y)) * thick.x);
		}
		width = ffw::Clamp(width, 0, thick.x);

		RenderComponent(pos, thick, cStyleBar);

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
				context->DrawRectangle(pos + ffw::Vec2i(thick.x - width, 0), size, cStyleBar->function.color);
			} else {
				context->DrawRectangle(pos, size, cStyleBar->function.color);
			}
		}

		width = int(((value - range.x) / float(range.y)) * (contentsize.x - buttonSizeReal.x));
		width = ffw::Clamp(width, 0, (contentsize.x - buttonSizeReal.x));

		pos.Set(contentoffset);
		pos.y += contentsize.y / 2;
		pos.x += width;
		pos.y -= buttonSizeReal.y /2;

		RenderComponent(pos, buttonSizeReal, cStyleButton);
	}
}

///=============================================================================
void ffw::GuiSlider::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiSlider::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiSlider::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiSlider::EventFocus(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiSlider::EventMouse(const ffw::Vec2i& pos){
	if(HasFocus()){
		int newvalue = value;
		auto realSize = GetRealSize();
		auto btnSize = ffw::Vec2i(buttonSize.x.ToReal(realSize.x), buttonSize.y.ToReal(realSize.y));
		if(vertical){
			int height = realSize.y - btnSize.y;
			float frac = ffw::Clamp((pos.y - btnSize.y/2) / float(height), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		} else {
			int width = realSize.x - btnSize.x;
			float frac = ffw::Clamp((pos.x - btnSize.x/2) / float(width), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		}
		if(newvalue != value){
			value = newvalue;
			GuiEvent::Data dat;
			dat.changed.value = GetValue();
			PushEvent(GuiEvent::Type::CHANGED, dat);
			Redraw();
		}
	}
}

///=============================================================================
void ffw::GuiSlider::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	if(button == ffw::MouseButton::LEFT && mode == ffw::Mode::PRESSED){
		GuiEvent::Data dat;
		dat.clicked.value = true;
		PushEvent(GuiEvent::Type::CLICKED, dat);
		EventMouse(GetMousePos());
	}
}

///=============================================================================
void ffw::GuiSlider::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiSlider::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiSlider::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiSlider::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SLIDER");
	styleBar = &theme->GetStyleGroup("GUI_SLIDER_BAR");
	styleButton = &theme->GetStyleGroup("GUI_SLIDER_BUTTON");
	SetDefaults(&widgetStyle->defaults);
	barSize = styleBar->defaults.size;
	buttonSize = styleButton->defaults.size;

	if (vertical) {
		auto s = GetSize();
		SetSize(s.y, s.x);
		std::swap(buttonSize.x, buttonSize.y);
		std::swap(barSize.x, barSize.y);
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiSlider::GetMinimumWrapSize() {
	auto realSize = GetRealSize();
	auto btnSize = ffw::Vec2i(buttonSize.x.ToReal(realSize.x), buttonSize.y.ToReal(realSize.y));

	if (vertical)return ffw::Vec2i(btnSize.x, btnSize.y * 2);
	return ffw::Vec2i(btnSize.x * 2, btnSize.y);
}