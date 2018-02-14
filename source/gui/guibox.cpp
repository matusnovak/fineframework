/*** This file is part of FineFramework project ***/

#include "ffw/gui/guibox.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guitheme.h"

///=============================================================================
ffw::GuiBox::GuiBox(GuiWindow* context, const std::string& label, const GuiOrientation orient) :GuiWidget(context) {
    setOrientationInternal(GuiOrientation::VERTICAL);

    widgetLabel = new GuiLabel(context, label);
    widgetInner = new GuiLayout(context, orient);

    addWidgetInternal(widgetLabel);
    addWidgetInternal(widgetInner);

    setStyle(&context->getTheme()->box, true);
}

///=============================================================================
void ffw::GuiBox::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
    (void)contentoffset;
    (void)contentsize;
}

///=============================================================================
void ffw::GuiBox::eventThemeChanged(const GuiTheme* theme, const bool defaults) {
    setStyle(&theme->box, defaults);
}

///=============================================================================
void ffw::GuiBox::setStyle(const GuiBox::Style* style, const bool defaults){
    widgetStyle = &style->self;
    if(defaults)setDefaults(&widgetStyle->defaults);
    widgetLabel->setStyle(&style->label, defaults);
    widgetInner->setStyle(&style->inner, defaults);
}

///=============================================================================
void ffw::GuiBox::eventSize(const ffw::Vec2f& size) {
    (void)size;
}

///=============================================================================
ffw::Vec2f ffw::GuiBox::getMinimumWrapSize() {
    return 0;
}