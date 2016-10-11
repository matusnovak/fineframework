/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiradio.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiRadioValue::GuiRadioValue(){
	value = 0;
}

///=============================================================================
ffw::GuiRadioValue::~GuiRadioValue(){
}

///=============================================================================
void ffw::GuiRadioValue::SetValue(int val){
	value = val;
	for(auto r : radios){
		if(r->GetBaseValue() == value)r->AssignValue(true);
		else r->AssignValue(false);
	}
}

///=============================================================================
int ffw::GuiRadioValue::GetValue() const{
	return value;
}

///=============================================================================
void ffw::GuiRadioValue::Assign(GuiRadio* radio){
	if(radio != NULL && std::find(radios.begin(), radios.end(), radio) == radios.end()){
		radios.push_back(radio);
	}
}

///=============================================================================
void ffw::GuiRadioValue::Remove(GuiRadio* radio){
	auto it = std::find(radios.begin(), radios.end(), radio);
	if(it != radios.end()){
		radios.erase(it);
	}
}

///=============================================================================
void ffw::GuiRadioValue::ClearAllExcept(const GuiRadio* radio){
	for(auto r : radios){
		if(r == radio){
			value = r->GetBaseValue();
		}
		else r->AssignValue(false);
	}
}

///=============================================================================
size_t ffw::GuiRadioValue::GetNumOfAssigned() const {
	return radios.size();
}

///=============================================================================
ffw::GuiRadioBtn::GuiRadioBtn(GuiWindow* context):GuiWidget(context){
	stickyfocusflag = true;
	SetPadding(GuiUnits::Percent(20));

	style.normal.background = true;
	style.normal.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.normal.border = true;
	style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0x222222);
	style.normal.textcolor = ffw::Rgba(0x22222200);

	style.hover.background = true;
	style.hover.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.hover.border = true;
	style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0x0078D7);
	style.hover.textcolor = ffw::Rgba(0x22222280);

	style.active.background = true;
	style.active.backgroundcolor = ffw::Rgb(0xFFFFFF);
	style.active.border = true;
	style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0x222222);
	style.active.textcolor = ffw::Rgb(0x222222);

	onclickcallback = nullptr;
}

///=============================================================================
ffw::GuiRadioBtn::~GuiRadioBtn(){
}

///=============================================================================
void ffw::GuiRadioBtn::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawCircle(contentoffset + contentsize / 2, std::min(contentsize.x, contentsize.y) / 2, 16);
}

///=============================================================================
void ffw::GuiRadioBtn::EventPos(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadioBtn::EventSize(const ffw::Vec2i& size){
	style.normal.borderradius = std::min(size.x, size.y) / 2;
	style.hover.borderradius = std::min(size.x, size.y) / 2;
	style.active.borderradius = std::min(size.x, size.y) / 2;
}

///=============================================================================
void ffw::GuiRadioBtn::EventHover(bool gained){
	Redraw();
}

///=============================================================================
void ffw::GuiRadioBtn::EventFocus(bool gained){
	if(gained){
		group->ClearAllExcept(parentradio);
		context->PushEvent(onclickcallback, {parentradio, GuiEventType::CLICKED});
		Redraw();
	}
}

///=============================================================================
void ffw::GuiRadioBtn::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadioBtn::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadioBtn::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiRadioBtn::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiRadioBtn::GetMinimumWrapSize() const {
	return 0;
}

///=============================================================================
ffw::GuiRadio::GuiRadio(GuiWindow* context, const std::string& label_, int base, GuiRadio* other):GuiWidget(context),label(label_){
	basevalue = base;
	SetOrientation(Orientation::HORIZONTAL);
	SetSize(GuiUnits::Percent(100), GuiUnits::Wrap());
	SetMargin(0, 0, 5, 0);
	SetAlign(GuiAlign::LEFT);
	ignoreinputflag = true;

	widgetbutton = new GuiRadioBtn(context);
	widgetbutton->SetSize(16, 16);
	indent = int(16 * 0.2);
	widgetbutton->SetMargin(0, 5, 0, 0);

	AddWidget(widgetbutton);

	//style.normal.border = true;
	//style.normal.bordersize = 1;
	style.normal.bordercolor = ffw::Rgb(0xFF0000);
	style.normal.textcolor = ffw::Rgb(0x222222);

	//style.hover.border = true;
	//style.hover.bordersize = 1;
	style.hover.bordercolor = ffw::Rgb(0xFF0000);
	style.hover.textcolor = ffw::Rgb(0x222222);

	//style.active.border = true;
	//style.active.bordersize = 1;
	style.active.bordercolor = ffw::Rgb(0xFF0000);
	style.active.textcolor = ffw::Rgb(0x222222);

	if(other != NULL){
		group = other->group;
	} else {
		group = new GuiRadioValue();
	}

	group->Assign(this);
	widgetbutton->group = group;
	widgetbutton->parentradio = this;
}

///=============================================================================
ffw::GuiRadio::~GuiRadio(){
	DeleteWidgets();

	group->Remove(this);
	if(group->GetNumOfAssigned() == 0){
		delete group;
	}
}

///=============================================================================
void ffw::GuiRadio::SetLabel(const std::string& label_){
	label = label_;
	Redraw();
}

///=============================================================================
const std::string& ffw::GuiRadio::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiRadio::AssignValue(bool value){
	(value == true ? widgetbutton->SetFocus() : widgetbutton->ResetFocus());
}

///=============================================================================
int ffw::GuiRadio::GetValue() const {
	return group->GetValue();
}

///=============================================================================
int ffw::GuiRadio::GetBaseValue() const {
	return basevalue;
}

///=============================================================================
void ffw::GuiRadio::SetValue(int value){
	group->SetValue(value);
}

///=============================================================================
void ffw::GuiRadio::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize){
	auto size = widgetbutton->GetRealSize();
	size.x += indent;
	size.y = 0;
	const auto& stl = GetCurrentStyle();
	context->SetDrawColor(stl.textcolor);
	context->DrawStringAligned(contentoffset + size, contentsize - size, GetCurrentFont(), GetAlign(), label);
}

///=============================================================================
void ffw::GuiRadio::EventPos(const ffw::Vec2i& pos){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::EventSize(const ffw::Vec2i& size){
}

///=============================================================================
void ffw::GuiRadio::EventHover(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::EventFocus(bool gained){
	// Do nothing
}

///=============================================================================
void ffw::GuiRadio::EventMouse(const ffw::Vec2i& pos){
}

///=============================================================================
void ffw::GuiRadio::EventMouseButton(ffw::MouseButton button, ffw::Mode mode){
}

///=============================================================================
void ffw::GuiRadio::EventText(wchar_t chr){
}

///=============================================================================
void ffw::GuiRadio::EventKey(ffw::Key key, ffw::Mode mode){
}

///=============================================================================
ffw::Vec2i ffw::GuiRadio::GetMinimumWrapSize() const {
	if(GetCurrentFont() == NULL)return 0;
	auto strsize = GetCurrentFont()->GetStringSize(label);
	strsize.x += widgetbutton->GetSize().x.value + indent;
	strsize.y = std::max(strsize.y, widgetbutton->GetSize().y.value);
	return strsize;
}