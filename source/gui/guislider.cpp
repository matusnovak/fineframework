/*** This file is part of FineFramework project ***/

#include "ffw/gui/guislider.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiSlider::GuiSlider(GuiWindow* context, bool vertical_):GuiWidget(context),vertical(vertical_){
	dropfocusflag = true;
	
	if(!vertical){
		SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	} else {
		SetSize(GuiUnits::Wrap(), GuiUnits::Percent(100));
	}

	SetMargin(0, 0, 5, 0);

	thickness = 4;
	buttonsize = 16;
	inverse = false;


	/*style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xFFCCCC);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xFFCCCC);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xFFCCCC);*/

	stylebar.normal.background = true;
	stylebar.normal.backgroundcolor = ffw::Rgb(0xE6E6E6);
	stylebar.normal.bordersize = 1;
	stylebar.normal.borderradius = 2;
	stylebar.normal.bordercolor = ffw::Rgb(0xBCBCBC);
	stylebar.normal.textcolor = ffw::Rgb(0x222222);

	stylebar.hover.background = false;
	stylebar.hover.backgroundcolor = ffw::Rgb(0xE6E6E6);
	stylebar.hover.bordersize = 1;
	stylebar.hover.borderradius = 2;
	stylebar.hover.bordercolor = ffw::Rgb(0x0078D7);
	stylebar.hover.textcolor = ffw::Rgb(0x222222);

	stylebar.active.background = false;
	stylebar.active.backgroundcolor = ffw::Rgb(0xE6E6E6);
	stylebar.active.bordersize = 1;
	stylebar.active.borderradius = 2;
	stylebar.active.bordercolor = ffw::Rgb(0x005499);
	stylebar.active.textcolor = ffw::Rgb(0x222222);

	stylebutton.normal.background = true;
	stylebutton.normal.backgroundcolor = ffw::Rgb(0xE1E1E1);
	stylebutton.normal.bordersize = 1;
	stylebutton.normal.borderradius = buttonsize/2;
	stylebutton.normal.bordercolor = ffw::Rgb(0xADADAD);
	stylebutton.normal.textcolor = ffw::Rgb(0x222222);

	stylebutton.hover.background = true;
	stylebutton.hover.backgroundcolor = ffw::Rgb(0xE5F1FB);
	stylebutton.hover.bordersize = 1;
	stylebutton.hover.borderradius = buttonsize/2;
	stylebutton.hover.bordercolor = ffw::Rgb(0x0078D7);
	stylebutton.hover.textcolor = ffw::Rgb(0x222222);

	stylebutton.active.background = true;
	stylebutton.active.backgroundcolor = ffw::Rgb(0xCCE4F7);
	stylebutton.active.bordersize = 1;
	stylebutton.active.borderradius = buttonsize/2;
	stylebutton.active.bordercolor = ffw::Rgb(0x005499);
	stylebutton.active.textcolor = ffw::Rgb(0x222222);

	color = ffw::Rgb(0x00AB1C);
	value = 50;
	range.Set(0, 100);
	onvaluechangedcallback = nullptr;
	onclickcallback = nullptr;
}

///=============================================================================
ffw::GuiSlider::~GuiSlider(){
}

///=============================================================================
bool ffw::GuiSlider::IsVertical() const {
	return vertical;
}

///=============================================================================
void ffw::GuiSlider::SetColor(const ffw::Color& c){
	color = c;
	Redraw();
}

///=============================================================================
const ffw::Color& ffw::GuiSlider::GetColor() const {
	return color;
}

///=============================================================================
void ffw::GuiSlider::SetValue(int val){
	int old = value;
	value = ffw::Clamp(val, range.x, range.y);
	if(old != value){
		GuiEventData dat;
		dat.changed.value = value;
		context->PushEvent(onvaluechangedcallback, {GetCallbackPtr(), GuiEventType::CHANGED, dat});
		Redraw();
	}
}

///=============================================================================
int ffw::GuiSlider::GetValue() const {
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
		GuiEventData dat;
		dat.changed.value = value;
		context->PushEvent(onvaluechangedcallback, {GetCallbackPtr(), GuiEventType::CHANGED, dat});
		Redraw();
	}
}

///=============================================================================
void ffw::GuiSlider::SetButtonSize(int size){
	buttonsize = size;
	Redraw();
}

///=============================================================================
int ffw::GuiSlider::GetButtonSize() const {
	return buttonsize;
}

///=============================================================================
void ffw::GuiSlider::SetThickness(int val){
	thickness = val;
	Redraw();
}

///=============================================================================
int ffw::GuiSlider::GetThickness() const {
	return thickness;
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
	const auto& stylbar = GetCurrentStyle(stylebar);
	const auto& stylbtn = GetCurrentStyle(stylebutton);

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

		context->DrawBackground(pos, size, stylbar);
		context->DrawBorder(pos, size, stylbar);

		size.y = height;

		if(stylbar.bordersize[0]){
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
				context->SetDrawColor(color);
				context->DrawRectangle(pos + ffw::Vec2i(0, contentsize.y - height), size);
			} else {
				context->SetDrawColor(color);
				context->DrawRectangle(pos, size);
			}
		}

		height = int(((value - range.x) / float(range.y)) * (contentsize.y - buttonsize));
		height = ffw::Clamp(height, 0, (contentsize.y - buttonsize));

		pos.Set(contentoffset);
		pos.x += contentsize.x / 2;
		pos.y += height;
		pos.x -= buttonsize/2;

		context->DrawBackground(pos, buttonsize, stylbtn);
		context->DrawBorder(pos, buttonsize, stylbtn);

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

		context->DrawBackground(pos, size, stylbar);
		context->DrawBorder(pos, size, stylbar);

		size.x = width;

		if(stylbar.bordersize[0]){
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
				context->SetDrawColor(color);
				context->DrawRectangle(pos + ffw::Vec2i(contentsize.x - width, 0), size);
			} else {
				context->SetDrawColor(color);
				context->DrawRectangle(pos, size);
			}
		}

		width = int(((value - range.x) / float(range.y)) * (contentsize.x - buttonsize));
		width = ffw::Clamp(width, 0, (contentsize.x - buttonsize));

		pos.Set(contentoffset);
		pos.y += contentsize.y / 2;
		pos.x += width;
		pos.y -= buttonsize/2;

		context->DrawBackground(pos, buttonsize, stylbtn);
		context->DrawBorder(pos, buttonsize, stylbtn);
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
			int height = GetRealSize().y - buttonsize;
			float frac = ffw::Clamp((pos.y - buttonsize/2) / float(height), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		} else {
			int width = GetRealSize().x - buttonsize;
			float frac = ffw::Clamp((pos.x - buttonsize/2) / float(width), 0.0f, 1.0f);

			newvalue = int(frac * range.y) + range.x;
		}
		if(newvalue != value){
			value = newvalue;
			GuiEventData dat;
			dat.changed.value = value;
			context->PushEvent(onvaluechangedcallback, {GetCallbackPtr(), GuiEventType::CHANGED, dat});
			Redraw();
		}
	}
}

///=============================================================================
void ffw::GuiSlider::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
	if(button == ffw::MouseButton::LEFT && mode == ffw::Mode::PRESSED){
		GuiEventData dat;
		dat.clicked.value = true;
		context->PushEvent(onclickcallback, {GetCallbackPtr(), GuiEventType::CLICKED, dat});
	}
}

///=============================================================================
void ffw::GuiSlider::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiSlider::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiSlider::GetMinimumWrapSize() const {
	int max = std::max(buttonsize, thickness);

	if(vertical)return ffw::Vec2i(max, buttonsize*2);
	return ffw::Vec2i(buttonsize*2, max);
}