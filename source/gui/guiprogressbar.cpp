/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiprogressbar.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guitheme.h"

///=============================================================================
ffw::GuiProgressBar::GuiProgressBar(GuiWindow* context) : GuiWidget(context),innerStyle(nullptr) {
    
    setStyle(&context->getTheme()->progressBar, true);
    percent = 0.0f;
}

///=============================================================================
void ffw::GuiProgressBar::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
    const auto width = float((percent / 100.0f) * contentsize.x);
    if(width > 0) {
        renderComponent(contentoffset, ffw::Vec2f(width, contentsize.y), getCurrentStyle(innerStyle));
    }
}

///=============================================================================
void ffw::GuiProgressBar::setValue(const float value) {
    percent = ffw::clamp(value, 0.0f, 100.0f);
    redraw();
}

///=============================================================================
void ffw::GuiProgressBar::setInnerStyleGroup(const GuiWidget::Style* style) {
    innerStyle = style;
    redraw();
}

///=============================================================================
void ffw::GuiProgressBar::eventThemeChanged(const GuiTheme* theme, const bool defaults) {
    setStyle(&theme->progressBar, defaults);
}

///=============================================================================
void ffw::GuiProgressBar::setStyle(const GuiProgressBar::Style* style, const bool defaults) {
    widgetStyle = &style->self;
    innerStyle = &style->inner;
    if (defaults)setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiProgressBar::getMinimumWrapSize() {
    return ffw::Vec2i(16, 8);
}