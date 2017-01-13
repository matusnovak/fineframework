/*** This file is part of FineFramework project ***/

#include "ffw/gui/guilist.h"
#include "ffw/gui/guilayout.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiList::Value::Value(GuiList* list):parent(list) {
	value = 0;
}

///=============================================================================
ffw::GuiList::Value::~Value() {
}

///=============================================================================
void ffw::GuiList::Value::SetValue(int val) {
	value = val;
	bool found = false;
	for (auto r : items) {
		if (r->GetBaseValue() == value) {
			r->AssignValue(true);
			found = true;
		}
		else {
			r->AssignValue(false);
		}
	}

	if (found) {
		GuiEvent::Data dat;
		dat.changed.value = value;
		parent->PushEvent(GuiEvent::Type::CHANGED, dat);
	}
}

///=============================================================================
void ffw::GuiList::Value::Reset() {
	items.clear();
}

///=============================================================================
int ffw::GuiList::Value::GetValue() const {
	return value;
}

///=============================================================================
void ffw::GuiList::Value::Assign(GuiList::Item* item) {
	if (item != NULL && std::find(items.begin(), items.end(), item) == items.end()) {
		items.push_back(item);
	}
}

///=============================================================================
void ffw::GuiList::Value::Remove(GuiList::Item* item) {
	auto it = std::find(items.begin(), items.end(), item);
	if (it != items.end()) {
		items.erase(it);
	}
}

///=============================================================================
void ffw::GuiList::Value::ClearAllExcept(const GuiList::Item* item) {
	bool found = false;
	for (auto r : items) {
		if (r == item) {
			value = r->GetBaseValue();
			found = true;
			break;
		}
	}

	for (auto r : items) {
		r->AssignValue(r == item);
	}

	if (found) {
		GuiEvent::Data dat;
		dat.changed.value = value;
		parent->PushEvent(GuiEvent::Type::CHANGED, dat);
	}
}

///=============================================================================
ffw::GuiList::Item::Item(GuiWindow* context, const std::string& label_, int b, GuiList::Value* g) :
	GuiList::Item(context, Utf8ToWstr(label_), b, g) {
}

///=============================================================================
ffw::GuiList::Item::Item(GuiWindow* context, const std::wstring& label_, int b, GuiList::Value* g) :
	GuiWidget(context), label(label_), base(b), group(g) {
	group->Assign(this);
	stickyfocusflag = true;
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_LIST_ITEM");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiList::Item::~Item() {
	group->Remove(this);
}

///=============================================================================
void ffw::GuiList::Item::SetLabel(const std::wstring& label_) {
	label = label_;
	Redraw();
}

///=============================================================================
const std::wstring& ffw::GuiList::Item::GetLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiList::Item::AssignValue(bool value) {
	if (value) {
		SetFocus(true);
		GuiEvent::Data dat;
		dat.clicked.value = true;
		PushEvent(GuiEvent::Type::CLICKED, dat);
	}
	else {
		SetFocus(false);
	}
	Redraw();
}

///=============================================================================
bool ffw::GuiList::Item::IsSelected() const {
	return (base == group->GetValue());
}

///=============================================================================
void ffw::GuiList::Item::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	context->DrawStringAligned(contentoffset, contentsize, GetCurrentFont(), GetAlign(), label, GetCurrentStyle()->text);
}

///=============================================================================
void ffw::GuiList::Item::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiList::Item::EventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiList::Item::EventHover(bool gained) {
	Redraw();
}

///=============================================================================
void ffw::GuiList::Item::EventFocus(bool gained) {
	if (gained) {
		group->ClearAllExcept(this);
	}
	Redraw();
}

///=============================================================================
void ffw::GuiList::Item::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiList::Item::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiList::Item::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiList::Item::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiList::Item::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiList::Item::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_LIST_ITEM");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiList::Item::GetMinimumWrapSize() const {
	if (GetCurrentFont() == NULL)return 0;
	return GetCurrentFont()->GetStringSize(label);
}

///=============================================================================
ffw::GuiList::GuiList(GuiWindow* context):
	GuiScrollable(context, new ffw::GuiLayout(context, ffw::GuiLayout::Orientation::VERTICAL), false, true),group(this) {
	counter = 0;
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_LIST");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiList::~GuiList() {
}

///=============================================================================
ffw::GuiList::Item* ffw::GuiList::AddItem(const std::string& label) {
	auto layout = dynamic_cast<ffw::GuiLayout*>(GetInnerAsWidget());
	auto item = new GuiList::Item(context, label, counter++, &group);
	layout->AddWidget(item);
	return item;
}

///=============================================================================
ffw::GuiList::Item* ffw::GuiList::AddItem(const std::wstring& label) {
	auto layout = dynamic_cast<ffw::GuiLayout*>(GetInnerAsWidget());
	auto item = new GuiList::Item(context, label, counter++, &group);
	layout->AddWidget(item);
	return item;
}

///=============================================================================
void ffw::GuiList::DeleteAllItems() {
	auto layout = dynamic_cast<ffw::GuiLayout*>(GetInnerAsWidget());
	layout->DeleteWidgets();
	group.Reset();
	counter = 0;
}

///=============================================================================
bool ffw::GuiList::DeleteItem(const GuiList::Item* item) {
	auto layout = dynamic_cast<ffw::GuiLayout*>(GetInnerAsWidget());
	return layout->DeleteSingleWidget(item);
}

///=============================================================================
void ffw::GuiList::SetSelected(int index) {
	group.SetValue(index);
}

///=============================================================================
void ffw::GuiList::ResetSelected() {
	group.SetValue(-1);
}

///=============================================================================
void ffw::GuiList::SetSelected(const GuiList::Item* item) {
	if (item != NULL) {
		group.SetValue(item->GetBaseValue());
	}
}

///=============================================================================
ffw::GuiList::Item* ffw::GuiList::GetSelectedItem() const {
	auto value = group.GetValue();
	for (auto* w : GetAllWidgets()) {
		auto item = dynamic_cast<GuiList::Item*>(w);
		if (item != NULL && item->GetBaseValue() == value) {
			return item;
		}
	}
	return NULL;
}

///=============================================================================
void ffw::GuiList::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_LIST");
	SetDefaults(&widgetStyle->defaults);
}