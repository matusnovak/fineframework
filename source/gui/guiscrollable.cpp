/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollable.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollable::GuiScrollable(GuiWindow* context, GuiWidget* widget, bool hori, bool vert) :GuiWidget(context) {
	setIgnoreUserInput(true);

	widgetStyle = &context->getTheme()->getStyleGroup("GUI_SCROLLABLE");
	setDefaults(&widgetStyle->defaults);

	//setSize(ffw::guiPercent(100), ffw::guiPixels(100));
	//setMargin(0, 0, 5, 0);
	//setPadding(1);
	GuiWidget::setWrap(true);
	GuiWidget::setOrientation(GuiWidget::Orientation::HORIZONTAL);

	thickness = 14;

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
	if (e.widget == vscroll && e.type == ffw::GuiEvent::Type::CHANGED) {
		auto off = inner->getOffset();
		inner->setOffset(ffw::Vec2i(off.x, -e.data.changed.value));
	}

	if (e.widget == hscroll && e.type == ffw::GuiEvent::Type::CHANGED) {
		auto off = inner->getOffset();
		inner->setOffset(ffw::Vec2i(-e.data.changed.value, off.y));
	}

	if (e.widget == inner && e.type == ffw::GuiEvent::Type::INNER) {
		const auto total = inner->getInnerContentSize();
		const auto visible = inner->getVisibleContentSize();
		ffw::Vec2i diff = total - visible;

		if (diff.y > 0 && vscroll != NULL) {
			vscroll->setRange(0, diff.y);
			vscroll->setButtonLength(ffw::guiPercent(int((visible.y / float(total.y)) * 100.0f)));
		}
		else if (vscroll != NULL) {
			vscroll->setRange(0, 0);
		}

		if (diff.x > 0 && hscroll != NULL) {
			hscroll->setRange(0, diff.x);
			vscroll->setButtonLength(ffw::guiPercent(int((visible.x / float(total.x)) * 100.0f)));
		}
		else if (hscroll != NULL) {
			hscroll->setRange(0, 0);
		}
	}
}

///=============================================================================
void ffw::GuiScrollable::setScrollValues(int hori, int vert) {
	if (hscroll != NULL) {
		hscroll->setValue(hori);
	}
	if (vscroll != NULL) {
		vscroll->setValue(vert);
	}
	inner->setOffset(ffw::Vec2i(hori, vert));
}

///=============================================================================
void ffw::GuiScrollable::setScrollbarThickness(int px) {
	thickness = px;
	eventSize(getVisibleContentSize());
}

///=============================================================================
void ffw::GuiScrollable::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiScrollable::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollable::eventSize(const ffw::Vec2i& size) {
	ffw::Vec2i s = size;
	if (vscroll != NULL) {
		s.x -= thickness;
		if (hscroll != NULL) {
			vscroll->setSize(thickness, size.y - thickness);
		}
		else {
			vscroll->setSize(thickness, size.y);
		}
		s.x -= vscroll->getPaddingInPixels(3) - vscroll->getPaddingInPixels(1);
	}
	if (hscroll != NULL) {
		s.y -= thickness;
		hscroll->setSize(size.x, thickness);
		s.y -= hscroll->getPaddingInPixels(0) - hscroll->getPaddingInPixels(2);
	}

	inner->setSize(s.x, s.y);
	invalidate();
	//recalculateSize();
}

///=============================================================================
void ffw::GuiScrollable::eventHover(bool gained) {
}

///=============================================================================
void ffw::GuiScrollable::eventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiScrollable::eventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollable::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollable::eventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiScrollable::eventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollable::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiScrollable::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_SCROLLABLE");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollable::getMinimumWrapSize() {
	ffw::Vec2i s = inner->getMinimumWrapSize();

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