/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiwidget.h"
#include "ffw/gui/guiwindow.h"
#include <assert.h>

///=============================================================================
static ffw::Vec4i RectangleBoolean(const ffw::Vec2i& parentpos, const ffw::Vec2i& parentsize, const ffw::Vec2i& childpos, const ffw::Vec2i& childsize){
	ffw::Vec4i out;

	ffw::Vec2i parentend = parentpos + parentsize;
	ffw::Vec2i childend = childpos + childsize;

	out.x = std::max(parentpos.x, childpos.x);
	out.y = std::max(parentpos.y, childpos.y);
	out.z = std::min(parentend.x, childend.x);
	out.w = std::min(parentend.y, childend.y);
	out.z -= out.x;
	out.w -= out.y;

	if(out.z <= 0)out.z = 0;
	if(out.w <= 0)out.w = 0;

	return out;
}

///=============================================================================
ffw::GuiWidget::GuiWidget(GuiWindow* ctx):context(ctx){
	assert(context != NULL && "The context (GuiWindow) must not be NULL!");
	assert(context->getTheme() != NULL && "The context (GuiWindow) has to have a valid theme!");
	widgetStyle = NULL;
	posReal.set(0, 0);
	sizeReal.set(0, 0);
	size.set(0, 0);
	pos.set(0, 0);
	parent = NULL;
	flags.events.pos = false;
	flags.events.size = false;
	flags.events.disabled = false;
	flags.events.focus = false;
	flags.events.hover = false;
	flags.events.inner = false;
	orientation = Orientation::VERTICAL;
	flags.focusType = GuiWidget::Focus::DEFAULT;
	//first = true;
	widgetfont = NULL;
	align = GuiStyle::Align::TOP_LEFT;
	setMargin(0);
	setPadding(0);
	id = -1;
	callbackPtr = this;
	lineHeight = 1.5f;

	flags.hidden = false;
	flags.disabled = false;
	flags.focus = false;
	flags.hover = false;
	flags.wrap = false;
	flags.render = true;
	flags.invalidate = true;
	flags.rearrange = true;
	flags.first = true;
	flags.ignore = false;
}

///=============================================================================
ffw::GuiWidget::GuiWidget(GuiWidget&& other) {
	swap(other);
}

///=============================================================================
void ffw::GuiWidget::swap(GuiWidget& other) {
	if(this != &other) {
		using std::swap;

	}
}

///=============================================================================
ffw::GuiWidget& ffw::GuiWidget::operator = (GuiWidget&& other) {
	if (this != &other) {
		swap(other);
	}
	return *this;
}

///=============================================================================
ffw::GuiWidget::~GuiWidget(){
	deleteWidgetsInternal();
}

///=============================================================================
void ffw::GuiWidget::recalculatePos(){
	if(parent != NULL)posReal = pos.toReal(parent->getVisibleContentSize());
	else posReal = pos.toReal(sizeReal);

	/*if (typeid(*this) == typeid(ffw::GuiScrollBar::Scroll)) {
		std::cout << "recalculatePos()   END: " << typeid(*this).name() << " posReal: " << posReal << std::endl;
	}*/
}

///=============================================================================
void ffw::GuiWidget::arrangeWidgetsHorizontal(GuiWidget* ptr) {
	ffw::Vec2i contentSize = getVisibleContentSize();

	int maxheight = 0;
	int left = 0;
	int top = 0;

	for (auto& w : widgets) {
		if (w->isHidden())continue;
		// recalculate widget size...
		if (w != ptr)w->recalculateSize(this);

		// get its margin
		const auto& widgetmargin = w->margin;
		int realmargin[4];

		// calculate margin
		realmargin[0] = widgetmargin[0].toReal(contentSize.y);
		realmargin[1] = widgetmargin[1].toReal(contentSize.x);
		realmargin[2] = widgetmargin[2].toReal(contentSize.y);
		realmargin[3] = widgetmargin[3].toReal(contentSize.x);

		if (flags.wrap && size.x != guiWrap()) {
			int test = left + realmargin[3] + w->getRealSize().x;
			if (test > contentSize.x) {
				top += maxheight;
				maxheight = 0;
				left = 0;
			}
		}

		w->pos.set(guiPixels(left + realmargin[3]), guiPixels(top + realmargin[0]));
		w->recalculatePos();
		left += w->getRealSize().x + realmargin[3] + realmargin[1];

		int testheight = w->getRealSize().y + realmargin[0] + realmargin[2];
		maxheight = std::max(maxheight, testheight);

		totalSize.x = std::max(totalSize.x, left);
		totalSize.y = std::max(totalSize.y, std::max(top + testheight, maxheight));
	}
}

///=============================================================================
void ffw::GuiWidget::arrangeWidgetsVertical(GuiWidget* ptr) {
	ffw::Vec2i contentSize = getVisibleContentSize();
	
	int maxwidth = 0;
	int left = 0;
	int top = 0;
	for (auto& w : widgets) {
		if (w->isHidden())continue;

		// recalculate widget size...
		if (w != ptr)w->recalculateSize(this);

		// get its margin
		const auto& widgetmargin = w->margin;
		int realmargin[4];

		// calculate margin
		realmargin[0] = widgetmargin[0].toReal(contentSize.y);
		realmargin[1] = widgetmargin[1].toReal(contentSize.x);
		realmargin[2] = widgetmargin[2].toReal(contentSize.y);
		realmargin[3] = widgetmargin[3].toReal(contentSize.x);

		if (flags.wrap && size.y != guiWrap()) {
			int test = top + realmargin[0] + w->getRealSize().y;
			if (test > contentSize.y) {
				left += maxwidth;
				maxwidth = 0;
				top = 0;
			}
		}

		w->pos.set(guiPixels(left + realmargin[3]), guiPixels(top + realmargin[0]));
		w->recalculatePos();
		//std::cout << "widget: " << typeid(*w).name() << " put at: " << w->posReal << std::endl;
		top += w->getRealSize().y + realmargin[0] + realmargin[2];

		int testwidth = w->getRealSize().x + realmargin[1] + realmargin[3];
		maxwidth = std::max(maxwidth, testwidth);

		totalSize.x = std::max(totalSize.x, std::max(maxwidth, left + testwidth));
		totalSize.y = std::max(totalSize.y, top);
	}
}

///=============================================================================
void ffw::GuiWidget::arrangeWidgetsFixed(GuiWidget* ptr) {
	for (auto& w : widgets) {
		if (w->isHidden())continue;

		// recalculate widget size...
		if(w != ptr)w->recalculateSize(this);

		w->recalculatePos();

		ffw::Vec2i test;
		test = w->getRealPos() + w->getRealSize();

		totalSize.x = std::max(totalSize.x, test.x);
		totalSize.y = std::max(totalSize.y, test.y);
	}
}

///=============================================================================
void ffw::GuiWidget::recalculateSize(GuiWidget* caller){
	flags.invalidate = false;
	//std::cout << "recalculateSize() BEGIN: " << typeid(*this).name() << " sizeReal: " << sizeReal << std::endl;

	auto oldSizeReal = sizeReal;
	auto oldTotalSize = totalSize;

	if (parent != NULL) {
		// X set to wrap?
		if (size.x == guiWrap()) {
			sizeReal.x = 0;
		}
		else {
			sizeReal.x = size.x.toReal(parent->getVisibleContentSize().x);
		}

		// Y set to wrap?
		if (size.y == guiWrap()) {
			sizeReal.y = 0;
		}
		else {
			sizeReal.y = size.y.toReal(parent->getVisibleContentSize().y);
		}
	}
	else {
		sizeReal.x = size.x.value;
		sizeReal.y = size.y.value;
	}

	auto min = getMinimumWrapSize();

	totalSize = 0;
	totalSize.x = std::max(totalSize.x, min.x);
	totalSize.y = std::max(totalSize.y, min.y);

	min.x += getPaddingInPixels(1) + getPaddingInPixels(3);
	min.y += getPaddingInPixels(0) + getPaddingInPixels(2);

	//totalSize = 0;
	switch (orientation) {
		case Orientation::HORIZONTAL: arrangeWidgetsHorizontal(); break;
		case Orientation::VERTICAL: arrangeWidgetsVertical(); break;
		default: arrangeWidgetsFixed();  break;
	}

	// Wrap X
	if (size.x == ffw::guiWrap()) {
		sizeReal.x = totalSize.x;
		if (padding[1] != GuiUnits::Type::PERCENT)sizeReal.x += padding[1].value;
		if (padding[3] != GuiUnits::Type::PERCENT)sizeReal.x += padding[3].value;
		if (sizeReal.x < min.x)sizeReal.x = min.x;
	}

	// Wrap Y
	if (size.y == ffw::guiWrap()) {
		sizeReal.y = totalSize.y;
		if (padding[0] != GuiUnits::Type::PERCENT)sizeReal.y += padding[0].value;
		if (padding[2] != GuiUnits::Type::PERCENT)sizeReal.y += padding[2].value;
		if (sizeReal.y < min.y)sizeReal.y = min.y;
	}

	if (flags.first) {
		oldSizeReal = sizeReal;
		flags.events.size = true;
	}

	if(oldSizeReal != sizeReal) {
		if(parent != NULL) {
			if (caller != parent) {
				//std::cout << "parent: " << typeid(*parent).name() << " of: " << typeid(*this).name() << " should redraw" << std::endl;
				parent->recalculateSize(this);
				parent->redraw();
			}
		}

		flags.events.size = true;
		flags.render = true;
	}

	if(oldTotalSize != totalSize) {
		flags.events.inner = true;
	}

	//std::cout << "recalculateSize()   END: " << typeid(*this).name() << " sizeReal: " << sizeReal << " totalSize: " << totalSize << std::endl;
	//std::cout << "\ttotal: " << totalSize << " old: " << oldTotalSize << std::endl;
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWidget::getCurrentFont() const {
	if(widgetfont == NULL){
		return context->getDefaultFont();
	}
	else return widgetfont;
}

///=============================================================================
void ffw::GuiWidget::checkEvents() {
	if (flags.events.pos) {
		flags.events.pos = false;
		eventPos(posReal);
		GuiEvent::Data dat;
		dat.pos.x = posReal.x;
		dat.pos.y = posReal.y;
		pushEvent(GuiEvent::Type::POSITION, dat);
	}

	if (flags.events.size) {
		flags.events.size = false;
		//updateflag = true;
		const auto s = getVisibleContentSize();
		eventSize(s);
		GuiEvent::Data dat;
		dat.size.width = s.x;
		dat.size.height = s.y;
		pushEvent(GuiEvent::Type::SIZE, dat);
	}

	if (flags.events.inner) {
		flags.events.inner = false;
		//updateflag = true;
		const auto s = getInnerContentSize();
		GuiEvent::Data dat;
		dat.inner.width = s.x;
		dat.inner.height = s.y;
		pushEvent(GuiEvent::Type::INNER, dat);
	}

	if (flags.events.disabled) {
		flags.events.disabled = false;
		eventDisabled(flags.disabled);
		GuiEvent::Data dat;
		dat.state.disabled = flags.disabled;
		pushEvent(GuiEvent::Type::STATE, dat);
	}

	if (flags.events.focus) {
		flags.events.focus = false;
		eventFocus(flags.focus);
		GuiEvent::Data dat;
		dat.focus.gained = flags.events.focus;
		pushEvent(GuiEvent::Type::FOCUS, dat);
	}

	if (flags.events.hover) {
		flags.events.hover = false;
		eventHover(flags.hover);
		GuiEvent::Data dat;
		dat.hover.gained = flags.hover;
		pushEvent(GuiEvent::Type::HOVER, dat);
	}
}

///=============================================================================
void ffw::GuiWidget::update(const ffw::Vec2i& parentpos, const ffw::Vec2i& parentsize, const GuiUserInput& input, ffw::Vec2i mousepos, bool mouseout){
	//std::cout << "update for: " << typeid(*this).name() << " (" << mousepos << "/" << mouseout << ")" << std::endl;
	
	if (widgetStyle == NULL && context->getTheme() != NULL) {
		eventThemeChanged(context->getTheme());
	}
	
	if(flags.invalidate){
		recalculateSize();
	}

	// Do not proceed if the widget is hidden
	if (flags.hidden)return;

	checkEvents();

	//std::cout << "checking flags: " << flags.ignore << " / " << flags.disabled << std::endl;
	if (!flags.ignore && !flags.disabled) {
		//std::cout << "THE FUCK" << std::endl;
		if (mousepos != mouseOld){
			//std::cout << "calculating mouse" << std::endl;
			if (!mouseout &&
				mousepos.x > posReal.x && mousepos.x < posReal.x + sizeReal.x &&
				mousepos.y > posReal.y && mousepos.y < posReal.y + sizeReal.y) {

				//std::cout << "mouse is in!" << std::endl;

				if (!flags.hover) {
					//std::cout << "hover!" << std::endl;
					flags.hover = true;
					//updateFlag = true;
					eventHover(true);
					GuiEvent::Data dat;
					dat.hover.gained = true;
					pushEvent(GuiEvent::Type::HOVER, dat);

				}
			}
			else if (flags.hover) {
				flags.hover = false;
				//updateFlag = true;
				eventHover(false);
				GuiEvent::Data dat;
				dat.hover.gained = false;
				pushEvent(GuiEvent::Type::HOVER, dat);
			}
		}

		if(input.mousebtn == ffw::MouseButton::LEFT && input.mousemode != ffw::Mode::NONE){
			if (flags.hover && input.mousemode == ffw::Mode::PRESSED) {
				// If focus is 'toggle' then only change the focus,
				// otherwise always set the focus to true
				if (flags.focusType == GuiWidget::Focus::TOGGLE) {
					flags.focus = !flags.focus;
					eventFocus(flags.focus);
					GuiEvent::Data dat;
					dat.focus.gained = flags.focus;
					pushEvent(GuiEvent::Type::FOCUS, dat);
				}
				else if (!flags.focus) {
					flags.focus = true;
					eventFocus(flags.focus);
					GuiEvent::Data dat;
					dat.focus.gained = flags.focus;
					pushEvent(GuiEvent::Type::FOCUS, dat);
				}
			}
			else if (!flags.hover && input.mousemode == ffw::Mode::PRESSED) {				
				// Clicked outside of the widget, drop the focus if set as 'default'
				if (flags.focus && flags.focusType == GuiWidget::Focus::DEFAULT) {
					flags.focus = false;
					eventFocus(flags.focus);
					GuiEvent::Data dat;
					dat.focus.gained = flags.focus;
					pushEvent(GuiEvent::Type::FOCUS, dat);
				}
			}
			else if(input.mousemode == ffw::Mode::RELEASED){
				// Drop focus if set as 'drop'
				if (flags.focus && flags.focusType == GuiWidget::Focus::DROP) {
					flags.focus = false;
					eventFocus(flags.focus);
					GuiEvent::Data dat;
					dat.focus.gained = flags.focus;
					pushEvent(GuiEvent::Type::FOCUS, dat);
				}
			}
		}

		if(flags.focus && input.mousemode != ffw::Mode::NONE){
			eventMouseButton(input.mousebtn, input.mousemode);
		}

		if((flags.hover || flags.focus) && mouseOld != mousepos){
			mouseOld = mousepos - posReal - offset;
			mouseOld.x -= getPaddingInPixels(3);
			mouseOld.y -= getPaddingInPixels(0);
			eventMouse(mouseOld);
		}

		if(flags.focus && input.chr != 0xFFFF){
			GuiEvent::Data dat;
			dat.input.chr = input.chr;
			pushEvent(GuiEvent::Type::INPUT, dat);
			eventText(input.chr);
		}

		if(flags.focus && input.keymode != ffw::Mode::NONE){
			GuiEvent::Data dat;
			dat.key.key = input.key;
			dat.key.mode = input.keymode;
			pushEvent(GuiEvent::Type::KEY, dat);
			eventKey(input.key, input.keymode);
		}
	}

	if (flags.invalidate) {
		recalculateSize();
	}

	checkEvents();

	if(widgets.size() > 0){
		// Check whenever mouse pos is outside of the visible area
		// If the mouse pos was outside previously (parent) then do 
		// not calculate it -> we don't need it
		if(!mouseout){
			auto mpos = mousepos - posReal;
			auto csize = sizeReal;
			if(mpos.x < 0 || mpos.x > csize.x || mpos.y < 0 || mpos.y > csize.y){
				mouseout = true;
			}
		}

		mousepos = mousepos - getVisibleContentPos() - offset;

		for(auto& w : widgets){
			w->update(getVisibleContentPos(), getVisibleContentSize(), input, mousepos, mouseout);
		}
	}

	flags.first = false;
}

///=============================================================================
void ffw::GuiWidget::traverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size){
	const auto* style = getCurrentStyle();

	if(style != NULL && style->background && style->background.color.a >= 1.0f) {
		context->drawBackground(pos, size, style->background);
	}
	
	if(parent != NULL){
		parent->traverseBackground(pos, size);
	}

	if(style != NULL && style->background){
		context->drawBackground(pos, size, style->background);
	}
}

///=============================================================================
void ffw::GuiWidget::renderComponent(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle* style) {
	if (style == NULL)return;

	// draw background
	if (style->background) {
		context->drawBackground(pos, size, style->background);
	}

	// draw border
	if (style->border) {
		context->drawBorder(pos, size, style->border);
	}
}

///=============================================================================
void ffw::GuiWidget::render(const ffw::Vec2i& clippos, const ffw::Vec2i& clipsize, const ffw::Vec2i& off, bool clear){
	if (sizeReal.x <= 0 || sizeReal.y <= 0)return;
	if (flags.hidden)return;
	
	auto posRealOffset = off + posReal;
	ffw::Vec4i cliparea = RectangleBoolean(clippos, clipsize, posRealOffset, sizeReal);
	ffw::Vec2i childclippos(cliparea.x, cliparea.y);
	ffw::Vec2i childclipsize(cliparea.z, cliparea.w);

	if(childclipsize.x > 0 && childclipsize.y > 0){
	
		if(flags.render){
			flags.render = false;
		
			context->setScissors(childclippos, childclipsize);
		
			if(clear){
				context->clearWithColor(rgba(0x000000FF));

				// Go up through every parent and draw its background
				if(parent != NULL){
					parent->traverseBackground(posRealOffset, sizeReal);
				}
			}

			const auto* style = getCurrentStyle();
			const auto& contentpos = off + getVisibleContentPos() + offset;

			if (style != NULL) {
				// render the base for the widget
				renderComponent(posRealOffset, sizeReal, style);
				
				// render derived class specific components
				eventRender(contentpos, getVisibleContentSize());
			}

			//const auto parentpos = off + getVisibleContentPos();
			for(auto& w : widgets){
				w->render(childclippos, childclipsize, contentpos, false);
			}
		} else {
			const auto contentpos = off + getVisibleContentPos() + offset;
			for(auto& w : widgets){
				w->render(childclippos, childclipsize, contentpos, true);
			}
		}
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::getAbsolutePos() const {
	if (parent == NULL)return posReal;
	auto parentpos = parent->getAbsolutePos();
	parentpos.x += parent->getPaddingInPixels(3);
	parentpos.y += parent->getPaddingInPixels(0);
	parentpos += parent->getOffset();
	return parentpos + posReal;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::getVisibleContentSize() const {
	ffw::Vec2i contentSize = sizeReal;
	contentSize.y -= getPaddingInPixels(0);
	contentSize.x -= getPaddingInPixels(1);
	contentSize.y -= getPaddingInPixels(2);
	contentSize.x -= getPaddingInPixels(3);
	return contentSize;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::getVisibleContentPos() const {
	ffw::Vec2i contentPos = posReal;

	// Top
	contentPos.y += padding[0].toReal(sizeReal.y);

	// Left
	contentPos.x += padding[3].toReal(sizeReal.x);

	return contentPos;
}

///=============================================================================
void ffw::GuiWidget::setWrap(bool wrap){
	flags.wrap = wrap;
	flags.invalidate = true;
	//invalidateflag = true;
	//updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::setOrientation(Orientation o){
	orientation = o;
	flags.invalidate = true;
	//invalidateflag = true;
	//updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::setID(unsigned long ID){
	id = ID;
}

///=============================================================================
unsigned long ffw::GuiWidget::getID() const {
	return id;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::addWidgetInternal(GuiWidget* widget){
	if(widget != NULL){
		widgets.push_back(widget);
		widget->setParent(this);
		flags.invalidate = true;
		//setSize(size.x, size.y);
		//invalidate();
		//redraw();
	}
	return widget;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::addWidgetAfterInternal(const GuiWidget* previous, GuiWidget* widget) {
	if (widget == NULL || previous == NULL)return NULL;
	auto it = std::find(widgets.begin(), widgets.end(), previous);
	if (it == widgets.end()) {
		widgets.push_back(widget);
		widget->setParent(this);
	}
	else {
		widgets.insert(it + 1, widget);
		widget->setParent(this);
	}
	flags.invalidate = true;
	//invalidate();
	//redraw();
	return widget;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::addWidgetBeforeInternal(const GuiWidget* next, GuiWidget* widget) {
	if (widget == NULL || next == NULL)return NULL;
	auto it = std::find(widgets.begin(), widgets.end(), next);
	if (it == widgets.end()) {
		widgets.push_back(widget);
		widget->setParent(this);
	}
	else {
		widgets.insert(it, widget);
		widget->setParent(this);
	}
	flags.invalidate = true;
	//invalidate();
	//redraw();
	return widget;
}

///=============================================================================
void ffw::GuiWidget::deleteWidgetsInternal() {
	for (auto& w : widgets) {
		delete w;
	}
	widgets.clear();
	flags.invalidate = true;
	//setSize(size.x, size.y);
	//invalidate();
	//redraw();
}

///=============================================================================
bool ffw::GuiWidget::deleteSingleWidgetInternal(const GuiWidget* widget) {
	auto it = std::find(widgets.begin(), widgets.end(), widget);
	if (it == widgets.end())return false;

	widgets.erase(it);
	//setSize(size.x, size.y);
	//invalidate();
	//redraw();
	return true;
}

///=============================================================================
void ffw::GuiWidget::setSize(const ffw::Vec2<GuiUnits>& s){
	if(size.x == s.x && size.y == s.y)return;

	size.set(s.x, s.y);
	flags.invalidate = true;
	flags.rearrange = true;
	//invalidateflag = true;
	//updateflag = true;
	//calleventsize = true;

	//InvalidateAll();

	//if(parent != NULL){
	//	parent->invalidate();
	//}
}

///=============================================================================
void ffw::GuiWidget::setOffset(const ffw::Vec2i off){
	offset = off;
	redraw();
}

///=============================================================================
const ffw::Vec2i& ffw::GuiWidget::getOffset() const {
	return offset;
}

///=============================================================================
void ffw::GuiWidget::setPos(GuiUnits posx, GuiUnits posy){
	if(pos.x == posx && pos.y == posy)return;

	pos.set(posx, posy);
	//updateflag = true;
	//calleventpos = true;
	recalculatePos();

	//if(parent != NULL){
	//	parent->invalidateflag = true;
	//}
}

///=============================================================================
void ffw::GuiWidget::setPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left){
	padding[0] = top;
	padding[1] = right;
	padding[2] = bottom;
	padding[3] = left;
	flags.invalidate = true;
	//invalidateflag = true;
	//InvalidateFirstDown();
}

///=============================================================================
void ffw::GuiWidget::setMargin(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left){
	margin[0] = top;
	margin[1] = right;
	margin[2] = bottom;
	margin[3] = left;
	if(parent != NULL)parent->flags.invalidate = true;
	else flags.invalidate = true;
	//invalidateflag = true;
	//updateflag = true;
}

///=============================================================================
int ffw::GuiWidget::getPaddingInPixels(int side) const {
	if(side == 1 || side == 3){
		return padding[side].toReal(sizeReal.x);
	} else if(side == 0 || side == 2){
		return padding[side].toReal(sizeReal.y);
	}
	return 0;
}

///=============================================================================
int ffw::GuiWidget::getMarginInPixels(int side) const {
	if(side == 1 || side == 3){
		if(parent != NULL){
			return margin[side].toReal(parent->getVisibleContentSize().x);
		} else {
			return margin[side].toReal(sizeReal.x);
		}
	} else if(side == 0 || side == 2){
		if(parent != NULL){
			return margin[side].toReal(parent->getVisibleContentSize().y);
		} else {
			return margin[side].toReal(sizeReal.y);
		}
	}
	return 0;
}


///=============================================================================
void ffw::GuiWidget::setTheme(const GuiTheme* theme) {
	if (theme == NULL)return;
	eventThemeChanged(theme);
	flags.render = true;
	for (auto& w : widgets) {
		w->setTheme(theme);
	}
}

///=============================================================================
void ffw::GuiWidget::setStyleGroup(const GuiStyleGroup* style) {
	if (style == NULL)return;
	widgetStyle = style;
	//updateflag = true;
}

///=============================================================================
const ffw::GuiStyle* ffw::GuiWidget::getCurrentStyle(const GuiStyleGroup* group) const {
	if (group == NULL)return NULL;
	if (flags.disabled)return &group->disabled;
	if (flags.focus)return &group->active;
	if (flags.hover)return &group->hover;
	return &group->normal;
}

///=============================================================================
void ffw::GuiWidget::setAlign(GuiStyle::Align a) {
	align = a;
	//invalidateflag = true;
	//redraw();
}

///=============================================================================
ffw::GuiStyle::Align ffw::GuiWidget::getAlign() const {
	return align;
}

///=============================================================================
void ffw::GuiWidget::setHidden(bool h) {
	if(flags.hidden != h) {
		flags.hidden = h;
		//flags.shouldHide = (h ? 1 : -1);
		if (parent != NULL)parent->flags.invalidate = true;
	}
}

///=============================================================================
const ffw::Vec2<ffw::GuiUnits>& ffw::GuiWidget::getPos() const {
	return pos;
}

///=============================================================================
const ffw::Vec2<ffw::GuiUnits>& ffw::GuiWidget::getSize() const {
	return size;
}

///=============================================================================
void ffw::GuiWidget::setParent(GuiWidget* parent_){
	parent = parent_;
}

///=============================================================================
const ffw::GuiWidget* ffw::GuiWidget::getParent() const {
	return parent;
}

///=============================================================================
void ffw::GuiWidget::setFont(const GuiFont* font){
	widgetfont = font;
	flags.render = true;
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWidget::getFont() const {
	return widgetfont;
}

///=============================================================================
void ffw::GuiWidget::pushEvent(GuiEvent::Type type, GuiEvent::Data data) {
	if (getCallbackPtr()->eventCallbacks.callbacks.size() > 0) {
		context->pushEvent(getCallbackPtr()->eventCallbacks, { getCallbackPtr(), type, data });
	}
}

///=============================================================================
bool ffw::GuiWidget::shouldRedraw() const {
	return flags.render;
}

///=============================================================================
void ffw::GuiWidget::redraw(){
	flags.render = true;
	for(auto w : widgets){
		w->redraw();
	}
}

///=============================================================================
void ffw::GuiWidget::invalidate(){
	//std::cout << "invalidate called" << std::endl;
	flags.invalidate = true;
	//redraw();
}

///=============================================================================
void ffw::GuiWidget::setIgnoreUserInput(bool d) {
	flags.ignore = d;
	for (auto& w : widgets)w->setIgnoreUserInput(d);
}

///=============================================================================
void ffw::GuiWidget::setFocus(bool f){
	if (flags.focus != f) {
		flags.events.focus = true;
		flags.render = true;
	}
	flags.focus = f;
	for (auto& w : widgets)w->setFocus(f);
}

///=============================================================================
void ffw::GuiWidget::setDisabled(bool d) {
	if (flags.disabled != d) {
		flags.events.disabled = true;
		flags.render = true;
	}
	flags.disabled = d;
	for (auto& w : widgets)w->setDisabled(d);
}

///=============================================================================
void ffw::GuiWidget::setHover(bool h){
	if (flags.hover != h) {
		flags.events.hover = true;
		flags.render = true;
	}
	flags.hover = h;
	for (auto& w : widgets)w->setHover(h);
}

///=============================================================================
void ffw::GuiWidget::setCallbackPtr(GuiWidget* ptr){
	callbackPtr = ptr;
}