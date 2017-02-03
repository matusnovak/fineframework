/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiwidget.h"
#include "ffw/gui/guiwindow.h"

static const ffw::GuiStyleGroup ErrorStyle(
	// Normal
	ffw::GuiStyle(
		ffw::GuiStyle::Background(0, ffw::Rgb(0x800000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
		ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Text(ffw::Rgb(0xFF0000)),
		ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
	),
	// Hover
	ffw::GuiStyle(
		ffw::GuiStyle::Background(0, ffw::Rgb(0x800000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
		ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Text(ffw::Rgb(0x00FF00)),
		ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
	),
	// Active
	ffw::GuiStyle(
		ffw::GuiStyle::Background(0, ffw::Rgb(0x800000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
		ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Text(ffw::Rgb(0x0000FF)),
		ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
	),
	// Disabled
	ffw::GuiStyle(
		ffw::GuiStyle::Background(0, ffw::Rgb(0x800000), ffw::Rgb(0x000000), ffw::GuiStyle::Background::Type::SIMPLE),
		ffw::GuiStyle::Border(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Outline(0, 0, ffw::Rgb(0x000000)),
		ffw::GuiStyle::Text(ffw::Rgb(0x000000)),
		ffw::GuiStyle::Function(ffw::Rgb(0xFFFFFF))
	)
);

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
	assert(context->GetTheme() != NULL && "The context (GuiWindow) has to have a valid theme!");
	widgetStyle = NULL;
	posreal.Set(0, 0);
	sizereal.Set(0, 0);
	size.Set(0, 0);
	pos.Set(0, 0);
	updateflag = true;
	parent = NULL;
	calleventpos = false;
	calleventsize = false;
	calleventdisabled = false;
	calleventfocus = false;
	calleventhover = false;
	invalidateflag = true;
	orientation = Orientation::VERTICAL;
	hoverflag = false;
	focusflag = false;
	dropfocusflag = false;
	ignoreinputflag = false;
	togglefocusflag = false;
	stickyfocusflag = false;
	wrapWidgets = false;
	first = true;
	widgetfont = NULL;
	align = GuiStyle::Align::LEFT;
	SetMargin(0);
	SetPadding(0);
	id = -1;
	callbackPtr = this;
	shouldhideflag = 0;
	hidden = false;
	disableflag = false;
	lineHeight = 1.5f;
}

///=============================================================================
ffw::GuiWidget::~GuiWidget(){
	DeleteWidgetsInternal();
}

///=============================================================================
void ffw::GuiWidget::RecalculatePos(){
	ffw::Vec2i parentsize = sizereal;
	if(parent != NULL)parentsize = parent->sizereal;

	if(pos.x == GuiUnits::Type::PERCENT){
		posreal.x = static_cast<int>((pos.x.value / 100.0f) * parentsize.x);
	} else {
		posreal.x = pos.x.value;
	}

	if(pos.y == GuiUnits::Type::PERCENT){
		posreal.y = static_cast<int>((pos.y.value / 100.0f) * parentsize.y);
	} else {
		posreal.y = pos.y.value;
	}
}

///=============================================================================
void ffw::GuiWidget::RecalculateSize(){
	// Do not recalculate when called from the parent directly
	// without setting the flag first
	if (!invalidateflag)return;
	invalidateflag = false;

	ffw::Vec2i oldsizereal = sizereal;
	ffw::Vec2i oldtotalsize = totalsize;

	if(parent != NULL){
		// X set to wrap?
		if(size.x == GuiWrap()){
			sizereal.x = 0;
		} else {
			sizereal.x = size.x.ToReal(parent->GetVisibleContentSize().x);
		}

		// Y set to wrap?
		if(size.y == GuiWrap()){
			sizereal.y = 0;
		} else {
			sizereal.y = size.y.ToReal(parent->GetVisibleContentSize().y);
		}
	} else {
		sizereal.x = size.x.value;
		sizereal.y = size.y.value;
	}

	ffw::Vec2i contentsize = GetVisibleContentSize();
	totalsize = 0;

	int maxheight = 0;
	int maxwidth = 0;
	int left = 0;
	int top = 0;
	if(orientation == Orientation::HORIZONTAL){
		for(auto& w : widgets){
			if (w->IsHidden())continue;
			// Recalculate widget size...
			w->RecalculateSize();

			// Get its margin
			const auto& widgetmargin = w->margin;
			int realmargin[4];

			// Calculate margin
			realmargin[0] = widgetmargin[0].ToReal(contentsize.y);
			realmargin[1] = widgetmargin[1].ToReal(contentsize.x);
			realmargin[2] = widgetmargin[2].ToReal(contentsize.y);
			realmargin[3] = widgetmargin[3].ToReal(contentsize.x);

			if(wrapWidgets && size.x != GuiWrap()){
				int test = left + realmargin[3] + w->GetRealSize().x;
				if(test > contentsize.x){
					top += maxheight;
					maxheight = 0;
					left = 0;
				}
			}

			w->pos.Set(GuiPixels(left + realmargin[3]), GuiPixels(top + realmargin[0]));
			w->RecalculatePos();
			left += w->GetRealSize().x + realmargin[3] + realmargin[1];

			int testheight = w->GetRealSize().y + realmargin[0] + realmargin[2];
			maxheight = std::max(maxheight, testheight);

			totalsize.x = std::max(totalsize.x, left);
			totalsize.y = std::max(totalsize.y, std::max(top + testheight, maxheight));
		}
	} else if(orientation == Orientation::VERTICAL){
		for(auto& w : widgets){
			if (w->IsHidden())continue;
			// Recalculate widget size...
			w->RecalculateSize();

			// Get its margin
			const auto& widgetmargin = w->margin;
			int realmargin[4];

			// Calculate margin
			realmargin[0] = widgetmargin[0].ToReal(contentsize.y);
			realmargin[1] = widgetmargin[1].ToReal(contentsize.x);
			realmargin[2] = widgetmargin[2].ToReal(contentsize.y);
			realmargin[3] = widgetmargin[3].ToReal(contentsize.x);

			if(wrapWidgets && size.y != GuiWrap()){
				int test = top + realmargin[0] + w->GetRealSize().y;
				if(test > contentsize.y){
					left += maxwidth;
					maxwidth = 0;
					top = 0;
				}
			}

			w->pos.Set(GuiPixels(left + realmargin[3]), GuiPixels(top + realmargin[0]));
			w->RecalculatePos();
			top += w->GetRealSize().y + realmargin[0] + realmargin[2];

			int testwidth = w->GetRealSize().x + realmargin[1] + realmargin[3];
			maxwidth = std::max(maxwidth, testwidth);

			totalsize.x = std::max(totalsize.x, std::max(maxwidth, left + testwidth));
			totalsize.y = std::max(totalsize.y, top);
		}
	}
	else if (orientation == Orientation::FIXED) {
		for (auto& w : widgets) {
			if (w->IsHidden()) {
				continue;
			}
			// Recalculate widget size...
			w->RecalculateSize();

			w->RecalculatePos();

			ffw::Vec2i test;
			test = w->GetRealPos() + w->GetRealSize();

			totalsize.x = std::max(totalsize.x, test.x);
			totalsize.y = std::max(totalsize.y, test.y);
		}
	}

	auto min = GetMinimumWrapSize();

	totalsize.x = std::max(totalsize.x, min.x);
	totalsize.y = std::max(totalsize.y, min.y);

	min.x += GetPaddingInPixels(1) + GetPaddingInPixels(3);
	min.y += GetPaddingInPixels(0) + GetPaddingInPixels(2);

	// Wrap X
	if(size.x == ffw::GuiWrap()){
		sizereal.x = totalsize.x;
		if(padding[1] != GuiUnits::Type::PERCENT)sizereal.x += padding[1].value;
		if(padding[3] != GuiUnits::Type::PERCENT)sizereal.x += padding[3].value;
		if (sizereal.x < min.x)sizereal.x = min.x;
	}

	// Wrap Y
	if(size.y == ffw::GuiWrap()){
		sizereal.y = totalsize.y;
		if(padding[0] != GuiUnits::Type::PERCENT)sizereal.y += padding[0].value;
		if(padding[2] != GuiUnits::Type::PERCENT)sizereal.y += padding[2].value;
		if (sizereal.y < min.y)sizereal.y = min.y;
	}

	if(oldsizereal != sizereal){
		if(!first && parent != NULL /*&& (parent->GetSize().x == ffw::GuiWrap() || parent->GetSize().y == ffw::GuiWrap())*/){
			parent->invalidateflag = true;
			parent->RecalculateSize();
		}

		if(parent != NULL) {
			parent->Redraw();
		}

		calleventsize = true;
	}

	if(oldtotalsize != totalsize) {
		calleventsize = true;
	}

	updateflag = true;
	first = false;
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWidget::GetCurrentFont() const {
	if(widgetfont == NULL){
		return context->GetDefaultFont();
	}
	else return widgetfont;
}

///=============================================================================
void ffw::GuiWidget::Update(const ffw::Vec2i& parentpos, const ffw::Vec2i& parentsize, const GuiUserInput& input){
	if (widgetStyle == NULL && context->GetTheme() != NULL) {
		EventThemeChanged(context->GetTheme());
	}
	
	if(invalidateflag){
		RecalculateSize();
	}

	if (shouldhideflag != 0) {
		if (shouldhideflag == -1) {
			hidden = false;
		}
		else if (shouldhideflag == 1) {
			hidden = true;
		}
		if (parent != NULL) {
			parent->Invalidate();
			parent->RecalculateSize();
			parent->Redraw();
		}
		shouldhideflag = 0;
	}

	if (hidden)return;

	if(calleventpos){
		calleventpos = false;
		//updateflag = true;
		EventPos(posreal);
		GuiEvent::Data dat;
		dat.pos.x = posreal.x;
		dat.pos.y = posreal.y;
		PushEvent(GuiEvent::Type::POSITION, dat);
	}

	if(calleventsize){
		calleventsize = false;
		//updateflag = true;
		const auto s = GetVisibleContentSize();
		EventSize(s);
		GuiEvent::Data dat;
		dat.size.width = s.x;
		dat.size.height = s.y;
		PushEvent(GuiEvent::Type::SIZE, dat);
	}

	if (calleventdisabled) {
		calleventdisabled = false;
		EventDisabled(disableflag);
		GuiEvent::Data dat;
		dat.state.disabled = disableflag;
		PushEvent(GuiEvent::Type::STATE, dat);
	}

	if (calleventfocus) {
		calleventfocus = false;
		EventFocus(focusflag);
		GuiEvent::Data dat;
		dat.focus.gained = focusflag;
		PushEvent(GuiEvent::Type::FOCUS, dat);
	}

	if (calleventhover) {
		calleventhover = false;
		EventHover(hoverflag);
		GuiEvent::Data dat;
		dat.hover.gained = hoverflag;
		PushEvent(GuiEvent::Type::HOVER, dat);
	}

	if(!ignoreinputflag && !disableflag){
		if(input.mousepos.x > posreal.x && input.mousepos.x < posreal.x + sizereal.x &&
		   input.mousepos.y > posreal.y && input.mousepos.y < posreal.y + sizereal.y && !input.mouseout){
			
			if(!hoverflag){
				hoverflag = true;
				//updateFlag = true;
				EventHover(true);
				GuiEvent::Data dat;
				dat.hover.gained = true;
				PushEvent(GuiEvent::Type::HOVER, dat);

			}
		} else if(hoverflag){
			hoverflag = false;
			//updateFlag = true;
			EventHover(false);
			GuiEvent::Data dat;
			dat.hover.gained = false;
			PushEvent(GuiEvent::Type::HOVER, dat);
		}

		if(input.mousebtn == ffw::MouseButton::LEFT && input.mousemode != ffw::Mode::NONE){
			if(hoverflag && input.mousemode == ffw::Mode::PRESSED){

				if(togglefocusflag){
					focusflag = !focusflag;
					EventFocus(focusflag);
					GuiEvent::Data dat;
					dat.focus.gained = focusflag;
					PushEvent(GuiEvent::Type::FOCUS, dat);
				} else if(!focusflag){
					focusflag = true;
					EventFocus(true);
					GuiEvent::Data dat;
					dat.focus.gained = true;
					PushEvent(GuiEvent::Type::FOCUS, dat);
				}

			} else if(!togglefocusflag && focusflag && !hoverflag && !stickyfocusflag){
				focusflag = false;
				EventFocus(false);
				GuiEvent::Data dat;
				dat.focus.gained = false;
				PushEvent(GuiEvent::Type::FOCUS, dat);
			}
		}

		if(dropfocusflag && focusflag && input.mousemode == ffw::Mode::RELEASED && !stickyfocusflag){
			focusflag = false;
			EventFocus(false);
			GuiEvent::Data dat;
			dat.focus.gained = false;
			PushEvent(GuiEvent::Type::FOCUS, dat);
		}

		if(focusflag && input.mousemode != ffw::Mode::NONE){
			EventMouseButton(input.mousebtn, input.mousemode);
		}

		if((hoverflag || focusflag) && mouseold != input.mousepos){
			mouseold = input.mousepos - posreal - offset;
			mouseold.x -= GetPaddingInPixels(3);
			mouseold.y -= GetPaddingInPixels(0);
			EventMouse(mouseold);
		}

		if(focusflag && input.chr != 0xFFFF){
			EventText(input.chr);
		}

		if(focusflag && input.keymode != ffw::Mode::NONE){
			EventKey(input.key, input.keymode);
		}
	}

	if (invalidateflag) {
		RecalculateSize();
	}

	if(widgets.size() > 0){
		GuiUserInput inputoffset;
		inputoffset.mousepos = input.mousepos - GetVisibleContentPos() - offset;
		inputoffset.mousemode = input.mousemode;
		inputoffset.mousebtn = input.mousebtn;
		inputoffset.chr = input.chr;
		inputoffset.key = input.key;
		inputoffset.keymode = input.keymode;
		inputoffset.mouseout = input.mouseout;

		// Check whenever mouse pos is outside of the visible area
		// If the mouse pos was outside previously (parent) then do 
		// not calculate it -> we don't need it
		if(!input.mouseout){
			auto mpos = input.mousepos - posreal;
			auto csize = sizereal;
			if(mpos.x < 0 || mpos.x > csize.x || mpos.y < 0 || mpos.y > csize.y){
				inputoffset.mouseout = true;
			}
		}

		for(auto& w : widgets){
			w->Update(GetVisibleContentPos(), GetVisibleContentSize(), inputoffset);
		}
	}
}

///=============================================================================
void ffw::GuiWidget::TraverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size){
	const auto* style = GetCurrentStyle();

	if(style != NULL && style->background && style->background.color.a >= 1.0f) {
		context->DrawBackground(pos, size, style->background);
	}
	
	if(parent != NULL){
		parent->TraverseBackground(pos, size);
	}

	if(style != NULL && style->background){
		context->DrawBackground(pos, size, style->background);
	}
}

///=============================================================================
void ffw::GuiWidget::RenderComponent(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle* style) {
	if (style == NULL)return;

	// Draw background
	if (style->background) {
		context->DrawBackground(pos, size, style->background);
	}

	// Draw border
	if (style->border) {
		context->DrawBorder(pos, size, style->border);
	}
}

///=============================================================================
void ffw::GuiWidget::Render(const ffw::Vec2i& clippos, const ffw::Vec2i& clipsize, const ffw::Vec2i& off, bool clear){
	if (sizereal.x <= 0 || sizereal.y <= 0)return;
	if (hidden)return;
	
	auto posRealOffset = off + posreal;
	ffw::Vec4i cliparea = RectangleBoolean(clippos, clipsize, posRealOffset, sizereal);
	ffw::Vec2i childclippos(cliparea.x, cliparea.y);
	ffw::Vec2i childclipsize(cliparea.z, cliparea.w);

	if(childclipsize.x > 0 && childclipsize.y > 0){
	
		if(updateflag){
			updateflag = false;
		
			context->SetScissors(childclippos, childclipsize);
		
			if(clear){
				context->ClearWithColor(Rgba(0x000000FF));

				// Go up through every parent and draw its background
				if(parent != NULL){
					parent->TraverseBackground(posRealOffset, sizereal);
				}
			}

			const auto* style = GetCurrentStyle();
			const auto& contentpos = off + GetVisibleContentPos() + offset;

			if (style != NULL) {
				// Render the base for the widget
				RenderComponent(posRealOffset, sizereal, style);
				
				// Render derived class specific components
				EventRender(contentpos, GetVisibleContentSize());
			}

			//const auto parentpos = off + GetVisibleContentPos();
			for(auto& w : widgets){
				w->Render(childclippos, childclipsize, contentpos, false);
			}
		} else {
			const auto contentpos = off + GetVisibleContentPos() + offset;
			for(auto& w : widgets){
				w->Render(childclippos, childclipsize, contentpos, true);
			}
		}
	}
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetAbsolutePos() const {
	if (parent == NULL)return posreal;
	auto parentpos = parent->GetAbsolutePos();
	parentpos.x += parent->GetPaddingInPixels(3);
	parentpos.y += parent->GetPaddingInPixels(0);
	parentpos += parent->GetOffset();
	return parentpos + posreal;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetVisibleContentSize() const {
	ffw::Vec2i contentSize = sizereal;
	contentSize.y -= GetPaddingInPixels(0);
	contentSize.x -= GetPaddingInPixels(1);
	contentSize.y -= GetPaddingInPixels(2);
	contentSize.x -= GetPaddingInPixels(3);

	return contentSize;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetVisibleContentPos() const {
	ffw::Vec2i contentPos = posreal;

	// Top
	contentPos.y += padding[0].ToReal(sizereal.y);

	// Left
	contentPos.x += padding[3].ToReal(sizereal.x);

	return contentPos;
}

///=============================================================================
void ffw::GuiWidget::SetWrap(bool wrap){
	wrapWidgets = wrap;
	invalidateflag = true;
	updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::SetOrientation(Orientation o){
	orientation = o;
	invalidateflag = true;
	updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::SetID(unsigned long ID){
	id = ID;
}

///=============================================================================
unsigned long ffw::GuiWidget::GetID() const {
	return id;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::AddWidgetInternal(GuiWidget* widget){
	if(widget != NULL){
		widgets.push_back(widget);
		widget->SetParent(this);
		//SetSize(size.x, size.y);
		Invalidate();
		Redraw();
	}
	return widget;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::AddWidgetAfterInternal(const GuiWidget* previous, GuiWidget* widget) {
	if (widget == NULL || previous == NULL)return NULL;
	auto it = std::find(widgets.begin(), widgets.end(), previous);
	if (it == widgets.end()) {
		widgets.push_back(widget);
		widget->SetParent(this);
	}
	else {
		widgets.insert(it + 1, widget);
		widget->SetParent(this);
	}
	Invalidate();
	Redraw();
	return widget;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::AddWidgetBeforeInternal(const GuiWidget* next, GuiWidget* widget) {
	if (widget == NULL || next == NULL)return NULL;
	auto it = std::find(widgets.begin(), widgets.end(), next);
	if (it == widgets.end()) {
		widgets.push_back(widget);
		widget->SetParent(this);
	}
	else {
		widgets.insert(it, widget);
		widget->SetParent(this);
	}
	Invalidate();
	Redraw();
	return widget;
}

///=============================================================================
void ffw::GuiWidget::DeleteWidgetsInternal() {
	for (auto& w : widgets) {
		delete w;
	}
	widgets.clear();
	//SetSize(size.x, size.y);
	Invalidate();
	Redraw();
}

///=============================================================================
bool ffw::GuiWidget::DeleteSingleWidgetInternal(const GuiWidget* widget) {
	auto it = std::find(widgets.begin(), widgets.end(), widget);
	if (it == widgets.end())return false;

	widgets.erase(it);
	//SetSize(size.x, size.y);
	Invalidate();
	Redraw();
	return true;
}

///=============================================================================
void ffw::GuiWidget::InvalidateAll() {
	invalidateflag = true;
	for (auto& w : widgets)w->InvalidateAll();
}

///=============================================================================
void ffw::GuiWidget::SetSize(const ffw::Vec2<GuiUnits>& s){
	if(size.x == s.x && size.y == s.y)return;

	size = s;
	invalidateflag = true;
	updateflag = true;
	calleventsize = true;

	InvalidateAll();

	if(parent != NULL){
		parent->Invalidate();
	}
}

///=============================================================================
void ffw::GuiWidget::SetOffset(const ffw::Vec2i off){
	offset = off;
	Redraw();
}

///=============================================================================
const ffw::Vec2i& ffw::GuiWidget::GetOffset() const {
	return offset;
}

///=============================================================================
void ffw::GuiWidget::SetPos(GuiUnits posx, GuiUnits posy){
	if(pos.x == posx && pos.y == posy)return;

	pos.Set(posx, posy);
	updateflag = true;
	calleventpos = true;
	RecalculatePos();

	if(parent != NULL){
		parent->invalidateflag = true;
	}
}

///=============================================================================
void ffw::GuiWidget::SetPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left){
	padding[0] = top;
	padding[1] = right;
	padding[2] = bottom;
	padding[3] = left;
	invalidateflag = true;
	updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::SetPadding(GuiUnits all){
	padding[0] = padding[1] = padding[2] = padding[3] = all;
	invalidateflag = true;
	updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::SetMargin(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left){
	margin[0] = top;
	margin[1] = right;
	margin[2] = bottom;
	margin[3] = left;
	invalidateflag = true;
	updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::SetMargin(GuiUnits all){
	margin[0] = margin[1] = margin[2] = margin[3] = all;
	invalidateflag = true;
	updateflag = true;
}

///=============================================================================
int ffw::GuiWidget::GetPaddingInPixels(int side) const {
	if(side == 1 || side == 3){
		return padding[side].ToReal(sizereal.x);
	} else if(side == 0 || side == 2){
		return padding[side].ToReal(sizereal.y);
	}
	return 0;
}

///=============================================================================
int ffw::GuiWidget::GetMarginInPixels(int side) const {
	if(side == 1 || side == 3){
		if(parent != NULL){
			return margin[side].ToReal(parent->GetVisibleContentSize().x);
		} else {
			return margin[side].ToReal(sizereal.x);
		}
	} else if(side == 0 || side == 2){
		if(parent != NULL){
			return margin[side].ToReal(parent->GetVisibleContentSize().y);
		} else {
			return margin[side].ToReal(sizereal.y);
		}
	}
	return 0;
}


///=============================================================================
void ffw::GuiWidget::SetTheme(const GuiTheme* theme) {
	if (theme == NULL)return;
	EventThemeChanged(theme);
	updateflag = true;
	for (auto& w : widgets) {
		w->SetTheme(theme);
	}
}

///=============================================================================
void ffw::GuiWidget::SetStyleGroup(const GuiStyleGroup* style) {
	if (style == NULL)return;
	widgetStyle = style;
	updateflag = true;
}

///=============================================================================
const ffw::GuiStyle* ffw::GuiWidget::GetCurrentStyle(const GuiStyleGroup* group) const {
	if (group == NULL)return NULL;
	if (disableflag)return &group->disabled;
	if (focusflag)return &group->active;
	if (hoverflag)return &group->hover;
	return &group->normal;
}

///=============================================================================
void ffw::GuiWidget::SetAlign(GuiStyle::Align a) {
	align = a;
	invalidateflag = true;
	Redraw();
}

///=============================================================================
ffw::GuiStyle::Align ffw::GuiWidget::GetAlign() const {
	return align;
}

///=============================================================================
void ffw::GuiWidget::SetHidden(bool h) {
	if(hidden != h) {
		hidden = h;
		shouldhideflag = (h ? 1 : -1);
	}
}

///=============================================================================
void ffw::GuiWidget::Hide() {
	if (!hidden) {
		shouldhideflag = 1;
		hidden = true;
	}
}

///=============================================================================
void ffw::GuiWidget::Show() {
	if (hidden) {
		shouldhideflag = -1;
		hidden = false;
	}
}

///=============================================================================
const ffw::Vec2<ffw::GuiUnits>& ffw::GuiWidget::GetPos() const {
	return pos;
}

///=============================================================================
const ffw::Vec2<ffw::GuiUnits>& ffw::GuiWidget::GetSize() const {
	return size;
}

///=============================================================================
void ffw::GuiWidget::SetParent(GuiWidget* parent_){
	parent = parent_;
}

///=============================================================================
const ffw::GuiWidget* ffw::GuiWidget::GetParent() const {
	return parent;
}

///=============================================================================
void ffw::GuiWidget::SetFont(const GuiFont* font){
	widgetfont = font;
	updateflag = true;
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWidget::GetFont() const {
	return widgetfont;
}

///=============================================================================
void ffw::GuiWidget::PushEvent(GuiEvent::Type type, GuiEvent::Data data) {
	context->PushEvent(GetCallbackPtr()->eventCallbacks, { GetCallbackPtr(), type, data });
}

///=============================================================================
bool ffw::GuiWidget::ShouldRedraw() const {
	return updateflag;
}

///=============================================================================
void ffw::GuiWidget::Redraw(){
	updateflag = true;
	for(auto w : widgets){
		w->Redraw();
	}
}

///=============================================================================
void ffw::GuiWidget::Invalidate(){
	invalidateflag = true;
	Redraw();
}

///=============================================================================
void ffw::GuiWidget::SetIgnoreUserInput(bool d) {
	ignoreinputflag = d;
	for (auto& w : widgets)w->SetIgnoreUserInput(d);
}

///=============================================================================
void ffw::GuiWidget::SetFocus(bool f){
	if (focusflag != f) {
		calleventfocus = true;
		updateflag = true;
	}
	focusflag = f;
	for (auto& w : widgets)w->SetFocus(f);
}

///=============================================================================
void ffw::GuiWidget::SetDisabled(bool d) {
	if (ignoreinputflag != d) {
		calleventdisabled = true;
		updateflag = true;
	}
	disableflag = d;
	for (auto& w : widgets)w->SetDisabled(d);
}

///=============================================================================
void ffw::GuiWidget::SetHover(bool h){
	if (hoverflag != h) {
		calleventhover = true;
		updateflag = true;
	}
	hoverflag = h;
	for (auto& w : widgets)w->SetHover(h);
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetTotalContentSize() const {
	return totalsize;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetTotalContentPos() const {
	return GetVisibleContentPos() + offset;
}

///=============================================================================
void ffw::GuiWidget::SetCallbackPtr(GuiWidget* ptr){
	callbackPtr = ptr;
}