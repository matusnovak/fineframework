/*** This file is part of FineFramework project ***/

#include "ffw/gui/guislider.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSlider::GuiSlider(GuiWindow* context, bool vertical_, const std::type_info& type):GuiWidget(context, type),vertical(vertical_){
	dropfocusflag = true;
	
	if(!vertical){
		SetSize(GuiPercent(100), GuiWrap());
	} else {
		SetSize(GuiWrap(), GuiPercent(100));
	}

	SetMargin(0, 0, 5, 0);

	thickness = 4;
	buttonsize = 16;
	inverse = false;

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
void ffw::GuiSlider::SetButtonSize(const ffw::Vec2i& size){
	buttonsize = size;
	Redraw();
}

///=============================================================================
const ffw::Vec2i& ffw::GuiSlider::GetButtonSize() const {
	return buttonsize;
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
	//const auto& stylbar = GetCurrentStyle(stylebar);
	//const auto& stylbtn = GetCurrentStyle(stylebutton);

	if(vertical){
		int height = 0;
		
		if(inverse){
			height = int((1.0f - ((value - range.x) / float(range.y))) * contentsize.y);
		} else {
			height = int(((value - range.x) / float(range.y)) * contentsize.y);
		}
		height = ffw::Clamp(height, 0, contentsize.y);
		
		ffw::Vec2i off(contentsize.x / 2 - thickness / 2, 0);
		ffw::Vec2i pos(contentoffset + off);
		ffw::Vec2i size(thickness, contentsize.y);

		//context->DrawBackground(pos, size, stylbar);
		//context->DrawBorder(pos, size, stylbar);

		size.y = height;

		/*if(stylbar.bordersize[0]){
			size.y -= stylbar.bordersize[0];
			pos.y += stylbar.bordersize[0];
		}
		if(stylbar.bordersize[1]){
			size.x -= stylbar.bordersize[1];
		}
		if(stylbar.bordersize[2]){
			size.y -= stylbar.bordersize[2];
		}
		if(stylbar.bordersize[3]){
			size.x -= stylbar.bordersize[3];
			pos.x += stylbar.bordersize[0];
		}

		if(color.a > 0.0f){
			if(inverse){
				//context->SetDrawColor(color);
				//context->DrawRectangle(pos + ffw::Vec2i(0, contentsize.y - height), size);
			} else {
				//context->SetDrawColor(color);
				//context->DrawRectangle(pos, size);
			}
		}

		height = int(((value - range.x) / float(range.y)) * (contentsize.y - buttonsize));
		height = ffw::Clamp(height, 0, (contentsize.y - buttonsize));

		pos.Set(contentoffset);
		pos.x += contentsize.x / 2;
		pos.y += height;
		pos.x -= buttonsize/2;*/

		//context->DrawBackground(pos, buttonsize, stylbtn);
		//context->DrawBorder(pos, buttonsize, stylbtn);

	} else {
		int width = 0;
		
		if(inverse){
			width = int((1.0f - ((value - range.x) / float(range.y))) * contentsize.x);
		} else {
			width = int(((value - range.x) / float(range.y)) * contentsize.x);
		}
		width = ffw::Clamp(width, 0, contentsize.x);
		
		ffw::Vec2i off(0, contentsize.y / 2 - thickness / 2);
		ffw::Vec2i pos(contentoffset + off);
		ffw::Vec2i size(contentsize.x, thickness);

		//context->DrawBackground(pos, size, stylbar);
		//context->DrawBorder(pos, size, stylbar);

		size.x = width;

		/*if(stylbar.bordersize[0]){
			size.y -= stylbar.bordersize[0];
			pos.y += stylbar.bordersize[0];
		}
		if(stylbar.bordersize[1]){
			size.x -= stylbar.bordersize[1];
		}
		if(stylbar.bordersize[2]){
			size.y -= stylbar.bordersize[2];
		}
		if(stylbar.bordersize[3]){
			size.x -= stylbar.bordersize[3];
			pos.x += stylbar.bordersize[0];
		}

		if(color.a > 0.0f){
			if(inverse){
				//context->SetDrawColor(color);
				//context->DrawRectangle(pos + ffw::Vec2i(contentsize.x - width, 0), size);
			} else {
				//context->SetDrawColor(color);
				//context->DrawRectangle(pos, size);
			}
		}

		width = int(((value - range.x) / float(range.y)) * (contentsize.x - buttonsize));
		width = ffw::Clamp(width, 0, (contentsize.x - buttonsize));

		pos.Set(contentoffset);
		pos.y += contentsize.y / 2;
		pos.x += width;
		pos.y -= buttonsize/2;*/

		//context->DrawBackground(pos, buttonsize, stylbtn);
		//context->DrawBorder(pos, buttonsize, stylbtn);
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
		if(vertical){
			int height = GetRealSize().y - buttonsize.y;
			float frac = ffw::Clamp((pos.y - buttonsize.y/2) / float(height), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		} else {
			int width = GetRealSize().x - buttonsize.x;
			float frac = ffw::Clamp((pos.x - buttonsize.x/2) / float(width), 0.0f, 1.0f);

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
ffw::Vec2i ffw::GuiSlider::GetMinimumWrapSize() const {
	if(vertical)return ffw::Vec2i(std::max(buttonsize.x, thickness), buttonsize.y*2);
	return ffw::Vec2i(buttonsize.x*2, std::max(buttonsize.y, thickness));
}