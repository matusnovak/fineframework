/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiwidget.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guiscrollable.h"

///=============================================================================
static ffw::Vec4i RectangleBoolean(const ffw::Vec2i& parentpos, const ffw::Vec2i& parentsize, const ffw::Vec2i& childpos, const ffw::Vec2i& childsize){
	ffw::Vec4i out;

	//std::cout << "parentpos: " << parentpos << std::endl;
	//std::cout << "parentsize: " << parentsize << std::endl;
	//std::cout << "childpos: " << childpos << std::endl;
	//std::cout << "childsize: " << childsize << std::endl;

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
	
	/*// Is child of the parent?
	out.x = childpos.x;
	out.y = childpos.y;
	out.z = childsize.x;
	out.w = childsize.y;

	if(childpos.x + childsize.x <= parentpos.x)return 0;
	if(childpos.y + childsize.y <= parentpos.y)return 0;
	if(childpos.x >= parentpos.x + parentsize.x)return 0;
	if(childpos.y >= parentpos.y + parentsize.y)return 0;

	if(childpos.x <= parentpos.x)out.z = childsize.x - (parentpos.x - childpos.x);
	if(childpos.y <= parentpos.y)out.w = childsize.y - (parentpos.y - childpos.y);

	if(childpos.x + childsize.x > parentpos.x + parentsize.x){
		out.z = parentpos.x + parentsize.x - childpos.x;
	}

	if(childpos.y + childsize.y > parentpos.y + parentsize.y){
		out.w = parentpos.y + parentsize.y - childpos.y;
	}

	out.x = std::max(childpos.x, parentpos.x);
	out.y = std::max(childpos.y, parentpos.y);*/

	return out;
}

///=============================================================================
ffw::GuiWidget::GuiWidget(GuiWindow* con):context(con){
	size.Set(0, 0);
	pos.Set(0, 0);
	posreal.Set(0, 0);
	sizereal.Set(0, 0);
	updateflag = true;
	parent = NULL;
	calleventpos = false;
	calleventsize = false;
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
	align = GuiAlign::LEFT;
	SetMargin(0);
	SetPadding(0);
	id = -1;
	onsizeeventcallback = nullptr;
	onposeventcallback = nullptr;
	onhovereventcallback = nullptr;
	onfocuseventcallback = nullptr;
	callbackPtr = this;
}

///=============================================================================
ffw::GuiWidget::~GuiWidget(){
	DeleteWidgets();
}

///=============================================================================
void ffw::GuiWidget::DeleteWidgets(){
	for(auto& w : widgets){
		delete w;
	}
	widgets.clear();
	SetSize(size.x, size.y);
}

///=============================================================================
bool ffw::GuiWidget::DeleteSingleWidget(GuiWidget* widget){
	auto it = std::find(widgets.begin(), widgets.end(), widget);
	if(it == widgets.end())return false;

	widgets.erase(it);
	SetSize(size.x, size.y);
	return true;
}

///=============================================================================
void ffw::GuiWidget::RecalculatePos(){
	ffw::Vec2i parentsize = sizereal;
	if(parent != NULL)parentsize = parent->sizereal;

	if(pos.x.inPercent){
		posreal.x = static_cast<int>((pos.x.value / 100.0f) * parentsize.x);
	} else {
		posreal.x = pos.x.value;
	}

	if(pos.y.inPercent){
		posreal.y = static_cast<int>((pos.y.value / 100.0f) * parentsize.y);
	} else {
		posreal.y = pos.y.value;
	}
}

///=============================================================================
void ffw::GuiWidget::RecalculateSize(){
	invalidateflag = false;

	/*if(dynamic_cast<GuiScrollable*>(this)){
		std::cout << "RecalculateSize" << std::endl;
	}*/

	ffw::Vec2i oldsizereal = sizereal;

	if(parent != NULL){
		// X set to wrap?
		if(size.x.inPercent && size.x.value == -1){
			sizereal.x = 0;
		} else {
			if(size.x.inPercent){
				sizereal.x = static_cast<int>((size.x.value / 100.0f) * parent->GetVisibleContentSize().x);
			} else {
				sizereal.x = size.x.value;
			}
		}

		// Y set to wrap?
		if(size.y.inPercent && size.y.value == -1){
			sizereal.y = 0;
		} else {
			if(size.y.inPercent){
				sizereal.y = static_cast<int>((size.y.value / 100.0f) * parent->GetVisibleContentSize().y);
			} else {
				sizereal.y = size.y.value;
			}
		}
	} else {
		sizereal.x = size.x.value;
		sizereal.y = size.y.value;
	}

	ffw::Vec2i contentsize = GetVisibleContentSize();
	//ffw::Vec2i totalsize = 0;
	totalsize = 0;

	//std::cout << ">>> recalculating" << std::endl;
	//if(parent != NULL)std::cout << "parent size: " << parent->sizereal << std::endl;

	int maxheight = 0;
	int maxwidth = 0;
	int left = 0;
	int top = 0;
	if(orientation == Orientation::HORIZONTAL){
		for(auto& w : widgets){
			// Recalculate widget size...
			w->RecalculateSize();

			// Get its margin
			const GuiUnits (&widgetmargin)[4] = w->margin;
			int realmargin[4];

			// Calculate margin
			if(widgetmargin[0].inPercent)realmargin[0] = static_cast<int>((widgetmargin[0].value / 100.0f) * contentsize.y);
			else realmargin[0] = widgetmargin[0].value;
			if(widgetmargin[1].inPercent)realmargin[1] = static_cast<int>((widgetmargin[1].value / 100.0f) * contentsize.x);
			else realmargin[1] = widgetmargin[1].value;
			if(widgetmargin[2].inPercent)realmargin[2] = static_cast<int>((widgetmargin[2].value / 100.0f) * contentsize.y);
			else realmargin[2] = widgetmargin[2].value;
			if(widgetmargin[3].inPercent)realmargin[3] = static_cast<int>((widgetmargin[3].value / 100.0f) * contentsize.x);
			else realmargin[3] = widgetmargin[3].value;

			if(wrapWidgets && !(size.x.inPercent && size.x.value == -1)){
				int test = left + realmargin[3] + w->GetRealSize().x;
				if(test > contentsize.x){
					top += maxheight;
					maxheight = 0;
					left = 0;
				}
			}

			//w->SetPos(left + realmargin[3], top + realmargin[0]);
			w->pos.Set(GuiUnits::Pixels(left + realmargin[3]), GuiUnits::Pixels(top + realmargin[0]));
			w->RecalculatePos();
			//w->absolutepos = this->absolutepos + w->posreal;
			left += w->GetRealSize().x + realmargin[3] + realmargin[1];

			int testheight = w->GetRealSize().y + realmargin[0] + realmargin[2];
			maxheight = std::max(maxheight, testheight);

			//std::cout << "widget: " << typeid(*w).name() << " put at: " << w->GetAbsolutePos() << " parent size: " << this->GetRealSize() << std::endl;

			totalsize.x = std::max(totalsize.x, left);
			totalsize.y = std::max(totalsize.y, maxheight);
		}
	} else if(orientation == Orientation::VERTICAL){
		for(auto& w : widgets){
			// Recalculate widget size...
			w->RecalculateSize();

			// Get its margin
			const GuiUnits (&widgetmargin)[4] = w->margin;
			int realmargin[4];

			// Calculate margin
			if(widgetmargin[0].inPercent)realmargin[0] = static_cast<int>((widgetmargin[0].value / 100.0f) * contentsize.y);
			else realmargin[0] = widgetmargin[0].value;
			if(widgetmargin[1].inPercent)realmargin[1] = static_cast<int>((widgetmargin[1].value / 100.0f) * contentsize.x);
			else realmargin[1] = widgetmargin[1].value;
			if(widgetmargin[2].inPercent)realmargin[2] = static_cast<int>((widgetmargin[2].value / 100.0f) * contentsize.y);
			else realmargin[2] = widgetmargin[2].value;
			if(widgetmargin[3].inPercent)realmargin[3] = static_cast<int>((widgetmargin[3].value / 100.0f) * contentsize.x);
			else realmargin[3] = widgetmargin[3].value;

			if(wrapWidgets && !(size.y.inPercent && size.y.value == -1)){
				int test = top + realmargin[0] + w->GetRealSize().y;
				if(test > contentsize.y){
					left += maxwidth;
					maxwidth = 0;
					top = 0;
				}
			}

			//w->SetPos(left + realmargin[3], top + realmargin[0]);
			w->pos.Set(GuiUnits::Pixels(left + realmargin[3]), GuiUnits::Pixels(top + realmargin[0]));
			w->RecalculatePos();
			//w->absolutepos = this->absolutepos + w->posreal;
			top += w->GetRealSize().y + realmargin[0] + realmargin[2];

			int testwidth = w->GetRealSize().x + realmargin[1] + realmargin[3];
			maxwidth = std::max(maxwidth, testwidth);

			//std::cout << "widget: " << typeid(*w).name() << " put at: " << w->GetAbsolutePos() << " parent size: " << this->GetRealSize() << std::endl;

			totalsize.x = std::max(totalsize.x, maxwidth);
			totalsize.y = std::max(totalsize.y, top);
		}
	}

	//std::cout << "total: " << totalsize << std::endl;

	// Wrap X
	if(size.x.inPercent && size.x.value == -1){
		//std::cout << "wrap X" << std::endl;
		sizereal.x = totalsize.x;
		if(!padding[1].inPercent)sizereal.x += padding[1].value;
		if(!padding[3].inPercent)sizereal.x += padding[3].value;
	}

	// Wrap Y
	if(size.y.inPercent && size.y.value == -1){
		//std::cout << "wrap Y" << std::endl;
		sizereal.y = totalsize.y;
		if(!padding[0].inPercent)sizereal.y += padding[0].value;
		if(!padding[2].inPercent)sizereal.y += padding[2].value;
	}

	auto min = GetMinimumWrapSize();
	min.x += GetPaddingInPixels(1) + GetPaddingInPixels(3);
	min.y += GetPaddingInPixels(0) + GetPaddingInPixels(2);

	if(sizereal.x < min.x)sizereal.x = min.x;
	if(sizereal.y < min.y)sizereal.y = min.y;

	//std::cout << "recalculate size sizereal: " << sizereal << std::endl;

	//std::cout << std::endl;

	if(oldsizereal.x != sizereal.x || oldsizereal.y != sizereal.y){
		if(!first && parent != NULL && (parent->GetSize().x == ffw::GuiUnits::Wrap() || parent->GetSize().y == ffw::GuiUnits::Wrap())){
			//std::cout << "================================" << std::endl;
			//std::cout << "recalculating size of the parent..." << std::endl;
			//std::cout << "previous size: " << oldsizereal << " new size: " << sizereal << std::endl;
			parent->RecalculateSize();
		}

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
	if(invalidateflag){
		RecalculateSize();
	}

	//if(!ignoreinputflag){
		//auto posRealOffset = off + posreal;
		//ffw::Vec4i cliparea = RectangleBoolean(clippos, clipsize, posRealOffset, sizereal);
		//ffw::Vec2i childclippos(cliparea.x, cliparea.y);
		//ffw::Vec2i childclipsize(cliparea.z, cliparea.w);

		if(calleventpos){
			calleventpos = false;
			updateflag = true;
			EventPos(posreal);
			GuiEventData dat;
			dat.pos.x = posreal.x;
			dat.pos.y = posreal.y;
			context->PushEvent(onposeventcallback, {GetCallbackPtr(), GuiEventType::POSITION, dat});
		}

		if(calleventsize){
			calleventsize = false;
			updateflag = true;
			const auto s = GetVisibleContentSize();
			EventSize(s);
			GuiEventData dat;
			dat.size.width = s.x;
			dat.size.height = s.y;
			context->PushEvent(onsizeeventcallback, {GetCallbackPtr(), GuiEventType::SIZE, dat});
		}

	if(!ignoreinputflag){
		if(input.mousepos.x > posreal.x && input.mousepos.x < posreal.x + sizereal.x &&
		   input.mousepos.y > posreal.y && input.mousepos.y < posreal.y + sizereal.y && !input.mouseout){
			
			if(!hoverflag){
				hoverflag = true;
				//updateFlag = true;
				EventHover(true);
				GuiEventData dat;
				dat.hover.gained = true;
				context->PushEvent(onhovereventcallback, {GetCallbackPtr(), GuiEventType::HOVER, dat});
				//std::cout << "widget hover gained!" << std::endl;

			}
		} else if(hoverflag){
			hoverflag = false;
			//updateFlag = true;
			EventHover(false);
			GuiEventData dat;
			dat.hover.gained = false;
			context->PushEvent(onhovereventcallback, {GetCallbackPtr(), GuiEventType::HOVER, dat});
			//std::cout << "widget hover lost!" << std::endl;
		}

		if(input.mousebtn == ffw::MouseButton::LEFT && input.mousemode != ffw::Mode::NONE){
			if(hoverflag && input.mousemode == ffw::Mode::PRESSED){

				if(togglefocusflag){
					focusflag = !focusflag;
					EventFocus(focusflag);
					GuiEventData dat;
					dat.focus.gained = focusflag;
					context->PushEvent(onfocuseventcallback, {GetCallbackPtr(), GuiEventType::FOCUS, dat});
				} else if(!focusflag){
					focusflag = true;
					EventFocus(true);
					GuiEventData dat;
					dat.focus.gained = true;
					context->PushEvent(onfocuseventcallback, {GetCallbackPtr(), GuiEventType::FOCUS, dat});
				}

			} else if(!togglefocusflag && focusflag && !hoverflag && !stickyfocusflag){
				focusflag = false;
				EventFocus(false);
				GuiEventData dat;
				dat.focus.gained = false;
				context->PushEvent(onfocuseventcallback, {GetCallbackPtr(), GuiEventType::FOCUS, dat});
			}
		}

		if(dropfocusflag && focusflag && input.mousemode == ffw::Mode::RELEASED && !stickyfocusflag){
			focusflag = false;
			EventFocus(false);
			GuiEventData dat;
			dat.focus.gained = false;
			context->PushEvent(onfocuseventcallback, {GetCallbackPtr(), GuiEventType::FOCUS, dat});
		}

		if(focusflag && input.mousemode != ffw::Mode::NONE){
			EventMouseButton(input.mousebtn, input.mousemode);
		}

		if((hoverflag || focusflag) && mouseold != input.mousepos){
			mouseold = input.mousepos - posreal;
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
ffw::Vec2i ffw::GuiWidget::GetAbsolutePos() const {
	if(parent == NULL)return posreal;
	auto parentpos = parent->GetAbsolutePos();
	parentpos.x += parent->GetPaddingInPixels(3);
	parentpos.y += parent->GetPaddingInPixels(0);
	parentpos += parent->GetOffset();
	return parentpos + posreal;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetVisibleContentSize() const {
	ffw::Vec2i contentSize = sizereal;

	/*// Top - size
	if(padding[0].inPercent)contentSize.y -= static_cast<int>((padding[0].value / 100.0f) * sizereal.y);
	else contentSize.y -= padding[0].value;

	// Right - size
	if(padding[1].inPercent)contentSize.x -= static_cast<int>((padding[1].value / 100.0f) * sizereal.x);
	else contentSize.x -= padding[1].value;

	// Bottom - size
	if(padding[2].inPercent)contentSize.y -= static_cast<int>((padding[2].value / 100.0f) * sizereal.y);
	else contentSize.y -= padding[2].value;

	// Left - size
	if(padding[3].inPercent)contentSize.x -= static_cast<int>((padding[3].value / 100.0f) * sizereal.x);
	else contentSize.x -= padding[3].value;*/
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
	if(padding[0].inPercent)contentPos.y += static_cast<int>((padding[0].value / 100.0f) * sizereal.y);
	else contentPos.y += padding[0].value;

	// Left
	if(padding[3].inPercent)contentPos.x += static_cast<int>((padding[3].value / 100.0f) * sizereal.x);
	else contentPos.x += padding[3].value;

	return contentPos;
}

///=============================================================================
void ffw::GuiWidget::TraverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size){
	if(GetCurrentStyle().background && GetCurrentStyle().backgroundcolor.a >= 1.0f){
		context->SetDrawColor(GetCurrentStyle().backgroundcolor);
		context->DrawRectangle(pos, size);
		return;
	}
	
	if(parent != NULL){
		parent->TraverseBackground(pos, size);
	}

	if(GetCurrentStyle().background){
		context->SetDrawColor(GetCurrentStyle().backgroundcolor);
		context->DrawRectangle(pos, size);
	}
}

///=============================================================================
void ffw::GuiWidget::Render(const ffw::Vec2i& clippos, const ffw::Vec2i& clipsize, const ffw::Vec2i& off, bool clear){
	if(invalidateflag){
		RecalculateSize();
	}
	
	auto posRealOffset = off + posreal;
	ffw::Vec4i cliparea = RectangleBoolean(clippos, clipsize, posRealOffset, sizereal);
	//std::cout << "clip region: " << cliparea.x << "x" << cliparea.y << " / " << cliparea.z << "x" << cliparea.w << std::endl;
	ffw::Vec2i childclippos(cliparea.x, cliparea.y);
	ffw::Vec2i childclipsize(cliparea.z, cliparea.w);

	if(childclipsize.x > 0 && childclipsize.y > 0){
	
		if(updateflag){
			updateflag = false;

			auto posRealOffset = off + posreal;

			//std::cout << ">>> rendering: " << typeid(*this).name() << " abs pos: " << absolutepos << std::endl;

			/*// Clip region
			ffw::Vec4i cliparea;
			if(parent != NULL){
				//auto parentPos = parent->GetVisibleContentPos();

				std::cout << ">>> rendering: " << typeid(*this).name() << std::endl;
				std::cout << "parent pos: " << clippos << std::endl;
				std::cout << "current pos: " << posRealOffset << std::endl;
				cliparea = RectangleBoolean(clippos, parent->GetVisibleContentSize(), posRealOffset, sizereal);
			} else {
				cliparea.Set(posRealOffset.x, posRealOffset.y, sizereal.x, sizereal.y);
			}*/

			//std::cout << "clip region: " << cliparea.x << "x" << cliparea.y << " / " << cliparea.z << "x" << cliparea.w << std::endl;
		
			context->SetScissors(childclippos, childclipsize);
		
			if(clear){
				context->ClearWithColor(Rgba(0x000000FF));

				// Go up through every parent and draw its background
				if(parent != NULL){
					parent->TraverseBackground(posRealOffset, sizereal);
				}
			}

			const auto& stly = GetCurrentStyle();

			// Draw background
			if(stly.background){
				//context->SetDrawColor(stly.backgroundcolor);
				//context->DrawRectangle(posRealOffset, sizereal);
				context->DrawBackground(posRealOffset, sizereal, stly);
			}

			// Border
			context->DrawBorder(posRealOffset, sizereal, stly);

			const auto& contentpos = off + GetVisibleContentPos() + offset;
			EventRender(contentpos, GetVisibleContentSize());

			const auto parentpos = off + GetVisibleContentPos();
			for(auto& w : widgets){
				w->Render(childclippos, childclipsize, contentpos, false);
			}
		} else {
			//std::cout << "ffw::GuiWidget::render" << std::endl;
			const auto contentpos = off + GetVisibleContentPos() + offset;
			//const auto parentpos = off + GetVisibleContentPos();
			for(auto& w : widgets){
				w->Render(childclippos, childclipsize, contentpos, true);
			}
		}
	}
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
void ffw::GuiWidget::AddWidget(GuiWidget* widget){
	if(widget != NULL){
		widgets.push_back(widget);
		widgets.back()->SetParent(this);
		SetSize(size.x, size.y);
	}
}

///=============================================================================
void ffw::GuiWidget::SetSize(GuiUnits width, GuiUnits height){
	if(size.x == width && size.y == height)return;

	size.Set(width, height);
	invalidateflag = true;
	updateflag = true;
	calleventsize = true;

	if(parent != NULL){
		parent->invalidateflag = true;
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
ffw::GuiUnits ffw::GuiWidget::GetPadding(int side) const{
	if(side >= 0 && side <= 3)return padding[side];
	return 0;
}

///=============================================================================
ffw::GuiUnits ffw::GuiWidget::GetMargin(int side) const{
	if(side >= 0 && side <= 3)return margin[side];
	return 0;
}

///=============================================================================
int ffw::GuiWidget::GetPaddingInPixels(int side) const {
	if(side == 1 || side == 3){
		if(padding[side].inPercent)return static_cast<int>((padding[side].value / 100.0f) * sizereal.x);
		else return padding[side].value;
	} else if(side == 0 || side == 2){
		if(padding[side].inPercent)return static_cast<int>((padding[side].value / 100.0f) * sizereal.y);
		else return padding[side].value;
	}
	return 0;
}

///=============================================================================
int ffw::GuiWidget::GetMarginInPixels(int side) const {
	if(side == 1 || side == 3){
		if(parent != NULL){
			if(padding[side].inPercent)return static_cast<int>((padding[side].value / 100.0f) * parent->GetVisibleContentSize().x);
			else return padding[side].value;
		} else {
			if(padding[side].inPercent)return static_cast<int>((padding[side].value / 100.0f) * sizereal.x);
			else return padding[side].value;
		}
	} else if(side == 0 || side == 2){
		if(parent != NULL){
			if(padding[side].inPercent)return static_cast<int>((padding[side].value / 100.0f) * parent->GetVisibleContentSize().y);
			else return padding[side].value;
		} else {
			if(padding[side].inPercent)return static_cast<int>((padding[side].value / 100.0f) * sizereal.x);
			else return padding[side].value;
		}
	}
	return 0;
}

///=============================================================================
void ffw::GuiWidget::SetAlign(GuiAlign a) {
	align = a;
	invalidateflag = true;
	Redraw();
}

///=============================================================================
ffw::GuiAlign ffw::GuiWidget::GetAlign() const {
	return align;
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
const ffw::Vec2i& ffw::GuiWidget::GetRealSize() const {
	return sizereal;
}

///=============================================================================
const ffw::Vec2i& ffw::GuiWidget::GetRealPos() const {
	return posreal;
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
bool ffw::GuiWidget::HasHover() const {
	return hoverflag;
}

///=============================================================================
bool ffw::GuiWidget::HasFocus() const {
	return focusflag;
}

///=============================================================================
void ffw::GuiWidget::SetFocus(){
	focusflag = true;
	updateflag = true;
}

///=============================================================================
void ffw::GuiWidget::ResetFocus(){
	focusflag = false;
	updateflag = true;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetContentSize() const {
	return totalsize;
}

///=============================================================================
ffw::Vec2i ffw::GuiWidget::GetContentPos() const {
	return GetVisibleContentPos() + offset;
}

///=============================================================================
ffw::GuiStyle& ffw::GuiWidget::GetCurrentStyle(GuiStyleGroup& group){
	if(focusflag)return group.active;
	else if(hoverflag)return group.hover;
	else return group.normal;
}

///=============================================================================
const ffw::GuiStyle& ffw::GuiWidget::GetCurrentStyle(const GuiStyleGroup& group) const {
	if(focusflag)return group.active;
	else if(hoverflag)return group.hover;
	else return group.normal;
}

///=============================================================================
void ffw::GuiWidget::SetCallbackPtr(GuiWidget* ptr){
	callbackPtr = ptr;
}

///=============================================================================
ffw::GuiWidget* ffw::GuiWidget::GetCallbackPtr() const {
	return callbackPtr;
}