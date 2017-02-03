/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogresscircle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiProgressCircle::GuiProgressCircle(GuiWindow* context) : GuiWidget(context) {
	ignoreinputflag = true;
	// At this point, we are sure that the context and GetTheme() are not NULL
	widgetStyle = &context->GetTheme()->GetStyleGroup("GUI_PROGRESSCIRCLE");
	SetDefaults(&widgetStyle->defaults);
	thickness = 10;
}

///=============================================================================
ffw::GuiProgressCircle::~GuiProgressCircle() {
}

///=============================================================================
void ffw::GuiProgressCircle::EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	int radius = std::min(contentsize.x, contentsize.y) / 2;
	radius -= thickness;

	static const float step = 360.0f / 100.0f;
	float start = 270.0f;
	float end = 270.0f + percent * step;

	context->DrawArc(contentoffset + contentsize / 2, radius, radius + thickness, start, end, GetCurrentStyle()->function.color);

	context->DrawArc(contentoffset + contentsize / 2, radius, radius + thickness, end, 360.0f + start, GetCurrentStyle()->function.secondary);

	auto font = GetCurrentFont();
	if (font != NULL) {

		std::wstring wstr = ffw::ValToWstring(percent) + L"%";
		const auto size = font->GetStringSize(wstr);

		auto pos = contentoffset + contentsize / 2 - size / 2;
		context->DrawStringAligned(contentoffset, contentsize, font, GetAlign(), wstr, GetCurrentStyle()->text.color, GetLineHeight());
	}
}

///=============================================================================
void ffw::GuiProgressCircle::EventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventHover(bool gained) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiProgressCircle::EventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->GetStyleGroup("GUI_PROGRESSCIRCLE");
	SetDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiProgressCircle::GetMinimumWrapSize() {
	auto font = GetCurrentFont();
	if (font == NULL)return ffw::Vec2i(32, 32);
	else {
		const auto size = font->GetStringSize("100%", GetLineHeight());
		int diamer = (int)sqrtl(size.x*size.x + size.y*size.y);
		return ffw::Vec2i(diamer + thickness * 2);
	}
}