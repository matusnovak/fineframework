/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollable.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollable::GuiScrollable(GuiWindow* context, GuiWidget* widget, bool hori, bool vert) :GuiWidget(context) {
	setIgnoreUserInput(false);

	widgetStyle = &context->getTheme()->getStyleGroup("GUI_SCROLLABLE");
	setDefaults(&widgetStyle->defaults);

	//setSize(ffw::guiPercent(100), ffw::guiPixels(100));
	//setMargin(0, 0, 5, 0);
	//setPadding(1);
	GuiWidget::setWrap(true);
	GuiWidget::setOrientation(GuiWidget::Orientation::HORIZONTAL);

	thickness = 14;
	scrollInc = 20.0f;

	inner = widget;
	inner->setMargin(0);
	inner->addEventCallback(&GuiScrollable::widgetEvent, this, true);
	inner->setPadding(2);

	GuiWidget::addWidgetInternal(inner);
	if (vert) {
		vscroll = new ffw::GuiScrollBar(context, true);
		vscroll->setMargin(0);
		vscroll->addEventCallback(&GuiScrollable::widgetEvent, this, true);
		vscroll->setValue(0);
		vscroll->setRange(0, 0);
		GuiWidget::addWidgetInternal(vscroll);
	}
	else {
		vscroll = NULL;
	}
	if (hori) {
		hscroll = new ffw::GuiScrollBar(context, false);
		hscroll->setMargin(0);
		hscroll->addEventCallback(&GuiScrollable::widgetEvent, this, true);
		hscroll->setValue(0);
		hscroll->setRange(0, 0);
		GuiWidget::addWidgetInternal(hscroll);
	}
	else {
		hscroll = NULL;
	}

	eventSize(getVisibleContentSize());
}

///=============================================================================
ffw::GuiScrollable::~GuiScrollable() {
}

///=============================================================================
void ffw::GuiScrollable::widgetEvent(ffw::GuiEvent e) {
	if (e.widget == vscroll && e.type == ffw::GuiEvent::Type::SLIDED) {
		auto off = inner->getOffset();
		inner->setOffset(ffw::Vec2f(off.x, -e.data.slided.value));
	}

	if (e.widget == hscroll && e.type == ffw::GuiEvent::Type::SLIDED) {
		auto off = inner->getOffset();
		inner->setOffset(ffw::Vec2f(-e.data.slided.value, off.y));
	}

	if (e.widget == inner && e.type == ffw::GuiEvent::Type::INNER) {
		const auto total = inner->getInnerContentSize();
		const auto visible = inner->getVisibleContentSize();
		ffw::Vec2f diff = (total - visible).floor();

		if (diff.x > 0 && hscroll != NULL) {
			hscroll->setRange(0, diff.x);
			hscroll->setButtonLength(ffw::guiPercent((visible.x / total.x) * 100.0f));
		}
		else if (hscroll != NULL) {
			hscroll->setRange(0, 0);
		}

		if (diff.y > 0 && vscroll != NULL) {
			vscroll->setRange(0, diff.y);
			vscroll->setButtonLength(ffw::guiPercent((visible.y / total.y) * 100.0f));
		}
		else if (vscroll != NULL) {
			vscroll->setRange(0, 0);
		}
	}
}

///=============================================================================
void ffw::GuiScrollable::setScrollValues(float hori, float vert) {
	if (hscroll != NULL) {
		hscroll->setValue(hori);
	}
	if (vscroll != NULL) {
		vscroll->setValue(vert);
	}
	inner->setOffset(ffw::Vec2f(hori, vert));
}

///=============================================================================
void ffw::GuiScrollable::setScrollbarThickness(float px) {
	thickness = px;
	eventSize(getVisibleContentSize());
}

///=============================================================================
void ffw::GuiScrollable::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	(void)contentoffset;
	(void)contentsize;
}

///=============================================================================
void ffw::GuiScrollable::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiScrollable::eventSize(const ffw::Vec2f& s) {
	//std::cout << "ffw::GuiScrollable::eventSize " << s << std::endl;
	
	ffw::Vec2f ss = s;
	if (vscroll != NULL) {
		ss.x -= thickness;
		if (hscroll != NULL) {
			vscroll->setSize(thickness, s.y - thickness);
		}
		else {
			vscroll->setSize(thickness, s.y);
		}
		ss.x -= vscroll->getPaddingInPixels(3) - vscroll->getPaddingInPixels(1);
	}
	if (hscroll != NULL) {
		ss.y -= thickness;
		hscroll->setSize(s.x, thickness);
		ss.y -= hscroll->getPaddingInPixels(0) - hscroll->getPaddingInPixels(2);
	}

	inner->setSize(ss.x, ss.y);
	invalidate();

	const auto total = inner->getInnerContentSize();
	ffw::Vec2f diff = (total - s).floor();
	
	if (diff.x > 0 && hscroll != NULL) {
		hscroll->setRange(0, diff.x);
		hscroll->setButtonLength(ffw::guiPercent((s.x / total.x) * 100.0f));
	}
	else if (hscroll != NULL) {
		hscroll->setRange(0, 0);
	}

	if (diff.y > 0 && vscroll != NULL) {
		vscroll->setRange(0, diff.y);
		vscroll->setButtonLength(ffw::guiPercent((s.y / total.y) * 100.0f));
	}
	else if (vscroll != NULL) {
		vscroll->setRange(0, 0);
	}
}

///=============================================================================
void ffw::GuiScrollable::eventHover(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiScrollable::eventFocus(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiScrollable::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
void ffw::GuiScrollable::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
bool ffw::GuiScrollable::eventScroll(const ffw::Vec2f& scroll) {
	bool ret = false;

	if (vscroll != NULL) {
		float old = vscroll->getValue();
		vscroll->setValue(old - scroll.y * scrollInc);
		ret |= std::abs(old - vscroll->getValue()) > 0.0001f;
	}

	if (hscroll != NULL) {
		float old = hscroll->getValue();
		hscroll->setValue(old - scroll.x * scrollInc);
		ret |= std::abs(old - hscroll->getValue()) > 0.0001f;
	}

	return ret;
}

///=============================================================================
void ffw::GuiScrollable::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiScrollable::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiScrollable::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiScrollable::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SCROLLABLE");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiScrollable::getMinimumWrapSize() {
	ffw::Vec2f s = inner->getMinimumWrapSize();

	if (vscroll != NULL) {
		s.x += vscroll->getMinimumWrapSize().x;
	}
	if (hscroll != NULL) {
		s.y += hscroll->getMinimumWrapSize().y;
	}

	return s;
}

///=============================================================================
ffw::GuiScrollableLayout::GuiScrollableLayout(GuiWindow* context, GuiLayout::Orientation orientation, bool hori, bool vert):
	GuiScrollable(context, new ffw::GuiLayout(context, orientation), hori, vert){
	getInner()->setPadding(2);
}

///=============================================================================
ffw::GuiScrollableLayout::~GuiScrollableLayout() {

}