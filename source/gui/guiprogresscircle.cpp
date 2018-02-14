/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogresscircle.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guitheme.h"

///=============================================================================
ffw::GuiProgressCircle::GuiProgressCircle(GuiWindow* context) : GuiWidget(context) {
    setStyle(&context->getTheme()->progressCircle, true);
    thickness = 10;
    percent = 0.0f;
}

///=============================================================================
void ffw::GuiProgressCircle::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
    auto radius = std::min(contentsize.x, contentsize.y) / 2;
    radius -= thickness;

    static const float step = 360.0f / 100.0f;
    const auto start = 270.0f;
    const auto end = 270.0f + percent * step;

    context->drawArc(contentoffset + contentsize / 2.0f, radius, radius + thickness, start, end, getCurrentStyle()->function.color);

    context->drawArc(contentoffset + contentsize / 2.0f, radius, radius + thickness, end, 360.0f + start, getCurrentStyle()->function.secondary);

    const auto font = getCurrentFont();
    if (font != nullptr) {

        const auto str = ffw::valToString(percent, 1) + "%";
        context->drawStringAligned(contentoffset, contentsize, font, getAlign(), str, getCurrentStyle()->text.color, getLineHeight());
    }
}

///=============================================================================
void ffw::GuiProgressCircle::setValue(const float value) {
    percent = ffw::clamp(value, 0.0f, 100.0f);
    redraw();
}

///=============================================================================
void ffw::GuiProgressCircle::setThickness(const float val) {
    thickness = val;
    redraw();
}

///=============================================================================
void ffw::GuiProgressCircle::eventThemeChanged(const GuiTheme* theme, const bool defaults) {
    setStyle(&theme->progressCircle, defaults);
}

///=============================================================================
void ffw::GuiProgressCircle::setStyle(const GuiProgressCircle::Style* style, const bool defaults) {
    widgetStyle = &style->self;
    if (defaults)setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiProgressCircle::getMinimumWrapSize() {
    const auto font = getCurrentFont();
    if (font == nullptr)return ffw::Vec2f(32, 32);
    else {
        const auto s = font->getStringSize("100.0%", -1.0f, getLineHeight());
        const auto diamer = float(sqrt(s.x*s.x + s.y*s.y));
        return ffw::Vec2f(diamer + thickness * 2);
    }
}