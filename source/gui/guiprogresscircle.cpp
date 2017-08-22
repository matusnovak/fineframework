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
void ffw::GuiProgressCircle::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	float radius = std::min(contentsize.x, contentsize.y) / 2;
	radius -= thickness;

	static const float step = 360.0f / 100.0f;
	float start = 270.0f;
	float end = 270.0f + percent * step;

	context->drawArc(contentoffset + contentsize / 2.0f, radius, radius + thickness, start, end, getCurrentStyle()->function.color);

	context->drawArc(contentoffset + contentsize / 2.0f, radius, radius + thickness, end, 360.0f + start, getCurrentStyle()->function.secondary);

	auto font = getCurrentFont();
	if (font != NULL) {

		std::wstring wstr = ffw::valToWstring(percent, 1) + L"%";
		context->drawStringAligned(contentoffset, contentsize, font, getAlign(), wstr, getCurrentStyle()->text.color, getLineHeight());
	}
}

///=============================================================================
void ffw::GuiProgressCircle::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiProgressCircle::eventSize(const ffw::Vec2f& s) {
	(void)s;
}

///=============================================================================
void ffw::GuiProgressCircle::eventHover(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiProgressCircle::eventFocus(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiProgressCircle::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiProgressCircle::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiProgressCircle::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiProgressCircle::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiProgressCircle::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiProgressCircle::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiProgressCircle::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_PROGRESSCIRCLE");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiProgressCircle::getMinimumWrapSize() {
	auto font = getCurrentFont();
	if (font == NULL)return ffw::Vec2f(32, 32);
	else {
		const auto s = font->getStringSize("100.0%", getLineHeight());
		float diamer = (float)sqrt(s.x*s.x + s.y*s.y);
		return ffw::Vec2f(diamer + thickness * 2);
	}
}