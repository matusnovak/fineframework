/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogresscircle.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiProgressCircle::GuiProgressCircle(GuiWindow* context) : GuiWidget(context) {
	setIgnoreUserInput(true);
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_PROGRESSCIRCLE");
	setDefaults(&widgetStyle->defaults);
	thickness = 10;
}

///=============================================================================
ffw::GuiProgressCircle::~GuiProgressCircle() {
}

///=============================================================================
void ffw::GuiProgressCircle::eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) {
	int radius = std::min(contentsize.x, contentsize.y) / 2;
	radius -= thickness;

	static const float step = 360.0f / 100.0f;
	float start = 270.0f;
	float end = 270.0f + percent * step;

	context->drawArc(contentoffset + contentsize / 2, radius, radius + thickness, start, end, getCurrentStyle()->function.color);

	context->drawArc(contentoffset + contentsize / 2, radius, radius + thickness, end, 360.0f + start, getCurrentStyle()->function.secondary);

	auto font = getCurrentFont();
	if (font != NULL) {

		std::wstring wstr = ffw::valToWstring(percent) + L"%";
		const auto size = font->getStringSize(wstr);

		auto pos = contentoffset + contentsize / 2 - size / 2;
		context->drawStringAligned(contentoffset, contentsize, font, getAlign(), wstr, getCurrentStyle()->text.color, getLineHeight());
	}
}

///=============================================================================
void ffw::GuiProgressCircle::eventPos(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventSize(const ffw::Vec2i& size) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventHover(bool gained) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventFocus(bool gained) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventMouse(const ffw::Vec2i& pos) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventText(wchar_t chr) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventKey(ffw::Key key, ffw::Mode mode) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventDisabled(bool disabled) {
}

///=============================================================================
void ffw::GuiProgressCircle::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_PROGRESSCIRCLE");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2i ffw::GuiProgressCircle::getMinimumWrapSize() {
	auto font = getCurrentFont();
	if (font == NULL)return ffw::Vec2i(32, 32);
	else {
		const auto size = font->getStringSize("100%", getLineHeight());
		int diamer = (int)sqrtl(size.x*size.x + size.y*size.y);
		return ffw::Vec2i(diamer + thickness * 2);
	}
}