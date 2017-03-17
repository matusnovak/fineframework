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
void ffw::GuiList::Value::setValue(int val) {
	value = val;
	bool found = false;
	for (auto r : items) {
		if (r->getBaseValue() == value) {
			r->assignValue(true);
			found = true;
		}
		else {
			r->assignValue(false);
		}
	}

	if (found) {
		GuiEvent::Data dat;
		dat.changed.value = value;
		parent->pushEvent(GuiEvent::Type::CHANGED, dat);
	}
}

///=============================================================================
void ffw::GuiList::Value::reset() {
	items.clear();
}

///=============================================================================
int ffw::GuiList::Value::getValue() const {
	return value;
}

///=============================================================================
void ffw::GuiList::Value::assign(GuiList::Item* item) {
	if (item != NULL && std::find(items.begin(), items.end(), item) == items.end()) {
		items.push_back(item);
	}
}

///=============================================================================
void ffw::GuiList::Value::remove(GuiList::Item* item) {
	for(size_t i = 0; i < items.size(); i++) {
		if(items[i] == item) {
			items.erase(items.begin() + i);
			break;
		}
	}
}

///=============================================================================
void ffw::GuiList::Value::clearAllExcept(const GuiList::Item* item) {
	bool found = false;
	for (auto r : items) {
		if (r == item) {
			value = r->getBaseValue();
			found = true;
			break;
		}
	}

	for (auto r : items) {
		r->assignValue(r == item);
	}

	if (found) {
		GuiEvent::Data dat;
		dat.changed.value = value;
		parent->pushEvent(GuiEvent::Type::CHANGED, dat);
	}
}

///=============================================================================
ffw::GuiList::Item::Item(GuiWindow* context, const std::string& label_, int b, GuiList::Value* g) :
	GuiList::Item(context, utf8ToWstr(label_), b, g) {
}

///=============================================================================
ffw::GuiList::Item::Item(GuiWindow* context, const std::wstring& label_, int b, GuiList::Value* g) :
	GuiWidget(context), label(label_), base(b), group(g) {
	group->assign(this);
	setStickyFocus();
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_LIST_ITEM");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiList::Item::~Item() {
	group->remove(this);
}

///=============================================================================
void ffw::GuiList::Item::setLabel(const std::wstring& label_) {
	label = label_;
	redraw();
}

///=============================================================================
const std::wstring& ffw::GuiList::Item::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiList::Item::assignValue(bool value) {
	if (value) {
		setFocus(true);
		GuiEvent::Data dat;
		dat.clicked.value = true;
		pushEvent(GuiEvent::Type::CLICKED, dat);
	}
	else {
		setFocus(false);
	}
	redraw();
}

///=============================================================================
bool ffw::GuiList::Item::isSelected() const {
	return (base == group->getValue());
}

///=============================================================================
void ffw::GuiList::Item::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	context->drawStringAligned(contentoffset, contentsize, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiList::Item::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiList::Item::eventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiList::Item::eventHover(bool gained) {
	redraw();
}

///=============================================================================
void ffw::GuiList::Item::eventFocus(bool gained) {
	if (gained) {
		group->clearAllExcept(this);
	}
	redraw();
}

///=============================================================================
void ffw::GuiList::Item::eventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiList::Item::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiList::Item::eventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiList::Item::eventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiList::Item::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiList::Item::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_LIST_ITEM");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiList::Item::getMinimumWrapSize() {
	if (getCurrentFont() == NULL)return 0;
	return getCurrentFont()->getStringSize(label, getLineHeight());
}

///=============================================================================
ffw::GuiList::GuiList(GuiWindow* context):
	GuiScrollableLayout(context, ffw::GuiLayout::Orientation::VERTICAL, false, true),group(this) {
	getInner()->setPadding(0);
	counter = 0;
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_LIST");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiList::~GuiList() {
}

///=============================================================================
ffw::GuiList::Item* ffw::GuiList::addItem(const std::string& label) {
	auto item = new GuiList::Item(context, label, counter++, &group);
	getInner()->addWidget(item);
	return item;
}

///=============================================================================
ffw::GuiList::Item* ffw::GuiList::addItem(const std::wstring& label) {
	auto item = new GuiList::Item(context, label, counter++, &group);
	getInner()->addWidget(item);
	return item;
}

///=============================================================================
void ffw::GuiList::DeleteAllItems() {
	getInner()->deleteWidgets();
	group.reset();
	counter = 0;
}

///=============================================================================
bool ffw::GuiList::DeleteItem(const GuiList::Item* item) {
	return getInner()->deleteSingleWidget(item);
}

///=============================================================================
void ffw::GuiList::setSelected(int index) {
	group.setValue(index);
}

///=============================================================================
void ffw::GuiList::ResetSelected() {
	group.setValue(-1);
}

///=============================================================================
void ffw::GuiList::setSelected(const GuiList::Item* item) {
	if (item != NULL) {
		group.setValue(item->getBaseValue());
	}
}

///=============================================================================
ffw::GuiList::Item* ffw::GuiList::getSelectedItem() const {
	auto value = group.getValue();
	for (auto* w : getAllWidgets()) {
		auto item = dynamic_cast<GuiList::Item*>(w);
		if (item != NULL && item->getBaseValue() == value) {
			return item;
		}
	}
	return NULL;
}

///=============================================================================
void ffw::GuiList::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_LIST");
	setDefaults(&widgetStyle->defaults);
}