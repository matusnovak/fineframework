/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiscrollable.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiScrollable::GuiScrollable(GuiWindow* context, GuiLayout::Orientation orient, bool hori, bool vert) :GuiWidget(context) {
	ignoreinputflag = true;

	SetSize(ffw::GuiPercent(100), ffw::GuiPixels(100));
	SetMargin(0, 0, 5, 0);
	SetPadding(1);
	GuiWidget::SetWrap(true);
	GuiWidget::SetOrientation(GuiWidget::Orientation::HORIZONTAL);

	thickness = 14;

	inner = new ffw::GuiLayout(context, orient);
	inner->SetMargin(0);
	inner->AddEventCallback(&GuiScrollable::WidgetEvent, this, true);
	inner->SetPadding(2);

	GuiWidget::AddWidget(inner);
	if (vert) {
		vscroll = new ffw::GuiScrollbar(context, true);
		vscroll->SetMargin(0);
		vscroll->AddEventCallback(&GuiScrollable::WidgetEvent, this, true);
		vscroll->SetValue(0);
		GuiWidget::AddWidget(vscroll);
	}
	else {
		vscroll = NULL;
	}
	if (hori) {
		hscroll = new ffw::GuiScrollbar(context, false);
		hscroll->SetMargin(0);
		hscroll->AddEventCallback(&GuiScrollable::WidgetEvent, this, true);
		hscroll->SetValue(0);
		GuiWidget::AddWidget(hscroll);
	}
	else {
		hscroll = NULL;
	}

	EventSize(GetVisibleContentSize());
}

///=============================================================================
ffw::GuiScrollable::~GuiScrollable() {
}

///=============================================================================
void ffw::GuiScrollable::WidgetEvent(ffw::GuiEvent e) {
	if (e.widget == vscroll && e.type == ffw::GuiEvent::Type::CHANGED) {
		auto off = inner->GetOffset();
		inner->SetOffset(ffw::Vec2i(off.x, -e.data.changed.value));
	}

	if (e.widget == hscroll && e.type == ffw::GuiEvent::Type::CHANGED) {
		auto off = inner->GetOffset();
		inner->SetOffset(ffw::Vec2i(-e.data.changed.value, off.y));
	}

	if (e.widget == inner && e.type == ffw::GuiEvent::Type::SIZE) {
		ffw::Vec2i diff = inner->GetTotalContentSize() - inner->GetVisibleContentSize();

		if (diff.y > 0 && vscroll != NULL) {
			vscroll->SetRange(0, diff.y);
		}
		else if (vscroll != NULL) {
			vscroll->SetRange(0, 0);
		}

		if (diff.x > 0 && hscroll != NULL) {
			hscroll->SetRange(0, diff.x);
		}
		else if (hscroll != NULL) {
			hscroll->SetRange(0, 0);
		}
	}
}

///=============================================================================
void ffw::GuiScrollable::SetScrollValues(int hori, int vert) {
	if (hscroll != NULL) {
		hscroll->SetValue(hori);
	}
	if (vscroll != NULL) {
		vscroll->SetValue(vert);
	}
	inner->SetOffset(ffw::Vec2i(hori, vert));
}

///=============================================================================
void ffw::GuiScrollable::SetScrollbarThickness(int px) {
	thickness = px;
	EventSize(GetVisibleContentSize());
}

///=============================================================================
void ffw::GuiScrollable::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
}

///=============================================================================
void ffw::GuiScrollable::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollable::EventSize(const ffw::Vec2i& size) {
	ffw::Vec2i s = size;
	if (vscroll != NULL) {
		s.x -= thickness;
		if (hscroll != NULL) {
			vscroll->SetSize(thickness, size.y - thickness);
		}
		else {
			vscroll->SetSize(thickness, size.y);
		}
		s.x -= vscroll->GetPaddingInPixels(3) - vscroll->GetPaddingInPixels(1);
	}
	if (hscroll != NULL) {
		s.y -= thickness;
		hscroll->SetSize(size.x, thickness);
		s.y -= hscroll->GetPaddingInPixels(0) - hscroll->GetPaddingInPixels(2);
	}
	inner->SetSize(s.x, s.y);
	Invalidate();
	//RecalculateSize();
}

///=============================================================================
void ffw::GuiScrollable::EventHover(bool gained) {
}

///=============================================================================
void ffw::GuiScrollable::EventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiScrollable::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiScrollable::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollable::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiScrollable::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiScrollable::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiScrollable::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_SCROLLABLE");
}

///=============================================================================
ffw::Vec2i ffw::GuiScrollable::GetMinimumWrapSize() const {
	ffw::Vec2i s = inner->GetMinimumWrapSize();

	if (vscroll != NULL) {
		s.x += vscroll->GetMinimumWrapSize().x;
	}
	if (hscroll != NULL) {
		s.y += hscroll->GetMinimumWrapSize().y;
	}

	return s;
}