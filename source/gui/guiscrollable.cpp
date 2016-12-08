/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollable.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollable::GuiScrollable(GuiWindow* context, GuiLayout::Orientation orient, bool vert, bool hori):GuiWidget(context){
	ignoreinputflag = true;
	
	GuiWidget::SetWrap(true);
	GuiWidget::SetOrientation(GuiWidget::Orientation::HORIZONTAL);

	thickness = 12;

	inner = new ffw::GuiLayout(context, orient);
	inner->SetMargin(0);
	inner->SetOnSizeEventCallback(&GuiScrollable::WidgetEvent, this);

	GuiWidget::AddWidget(inner);
	if(vert){
		vscroll = new ffw::GuiScrollbar(context, true);
		vscroll->SetMargin(0);
		vscroll->SetOnValueChangedCallback(&GuiScrollable::WidgetEvent, this);
		vscroll->SetValue(0);
		GuiWidget::AddWidget(vscroll);
	} else {
		vscroll = NULL;
	}
	if(hori){
		hscroll = new ffw::GuiScrollbar(context, false);
		hscroll->SetMargin(0);
		hscroll->SetOnValueChangedCallback(&GuiScrollable::WidgetEvent, this);
		hscroll->SetValue(0);
		GuiWidget::AddWidget(hscroll);
	} else {
		hscroll = NULL;
	}

	EventSize(GuiWidget::GetVisibleContentSize());
}

///=============================================================================
ffw::GuiScrollable::~GuiScrollable(){
}

///=============================================================================
void ffw::GuiScrollable::WidgetEvent(ffw::GuiEvent e){
	if(e.widget == vscroll && e.type == ffw::GuiEventType::CHANGED){
		auto off = inner->GetOffset();
		inner->SetOffset(ffw::Vec2i(off.x, -e.data.changed.value));
	}

	if(e.widget == hscroll && e.type == ffw::GuiEventType::CHANGED){
		auto off = inner->GetOffset();
		inner->SetOffset(ffw::Vec2i(-e.data.changed.value, off.y));
	}

	if(e.widget == inner && e.type == ffw::GuiEventType::SIZE){
		ffw::Vec2i diff = inner->GetContentSize() - inner->GetVisibleContentSize();
		
		if(diff.y > 0){
			vscroll->SetRange(0, diff.y);
		} else {
			vscroll->SetRange(0, 0);
		}

		if(diff.x > 0){
			hscroll->SetRange(0, diff.x);
		} else {
			hscroll->SetRange(0, 0);
		}
	}
}

///=============================================================================
void ffw::GuiScrollable::AddWidget(GuiWidget* widget){
	inner->AddWidget(widget);
}

///=============================================================================
void ffw::GuiScrollable::SetScrollbarThickness(int px){
	thickness = px;
	EventSize(GetVisibleContentSize());
}

///=============================================================================
void ffw::GuiScrollable::DeleteWidgets(){
	inner->DeleteWidgets();
}

///=============================================================================
ffw::GuiLayout* ffw::GuiScrollable::GetInner(){
	return inner;
}

///=============================================================================
const ffw::GuiLayout* ffw::GuiScrollable::GetInner() const{
	return inner;
}

///=============================================================================
ffw::GuiScrollbar* ffw::GuiScrollable::GetVscroll(){
	return vscroll;
}

///=============================================================================
const ffw::GuiScrollbar* ffw::GuiScrollable::GetVscroll() const{
	return vscroll;
}

///=============================================================================
ffw::GuiScrollbar* ffw::GuiScrollable::GetHscroll(){
	return hscroll;
}

///=============================================================================
const ffw::GuiScrollbar* ffw::GuiScrollable::GetHscroll() const {
	return hscroll;
}

///=============================================================================
bool ffw::GuiScrollable::DeleteSingleWidget(GuiWidget* widget){
	return inner->DeleteSingleWidget(widget);
}

///=============================================================================
void ffw::GuiScrollable::SetOrientation(GuiLayout::Orientation orient){
	inner->SetOrientation(orient);
}

///=============================================================================
void ffw::GuiScrollable::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
}

///=============================================================================
void ffw::GuiScrollable::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiScrollable::EventSize(const ffw::Vec2i& size){
	ffw::Vec2i s = size;
	if(vscroll != NULL){
		s.x -= thickness;
		vscroll->SetSize(thickness, size.y-thickness);
	}
	if(hscroll != NULL){
		s.y -= thickness;
		hscroll->SetSize(size.x, thickness);
	}
	inner->SetSize(s.x, s.y);
	Invalidate();
}

///=============================================================================
void ffw::GuiScrollable::EventHover(bool gained){
}

///=============================================================================
void ffw::GuiScrollable::EventFocus(bool gained){
}

///=============================================================================
void ffw::GuiScrollable::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiScrollable::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiScrollable::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiScrollable::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollable::GetMinimumWrapSize() const {
	ffw::Vec2i s = inner->GetMinimumWrapSize();

	if(vscroll != NULL){
		s.x += vscroll->GetMinimumWrapSize().x;
	}
	if(hscroll != NULL){
		s.y += hscroll->GetMinimumWrapSize().y;
	}

	return s;
}