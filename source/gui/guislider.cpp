/*** This file is part of FineFramework project ***/

#include "ffw/gui/guislider.h"
#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guitheme.h"
#include "ffw/math/functions.h"

///=============================================================================
ffw::GuiSlider::GuiSlider(GuiWindow* context, const bool vertical):GuiWidget(context),styleButton(nullptr),styleBar(nullptr),vertical(vertical) {
    setDropFocus();

    setStyle(&context->getTheme()->slider, true);
    setMargin(0, 0, 5, 0);

    inverse = false;

    if (vertical) {
        auto s = getSize();
        setSize(s.y, s.x);
        std::swap(buttonSize.x, buttonSize.y);
        std::swap(barSize.x, barSize.y);
    }

    value = 50;
    range.set(0, 100);
}

///=============================================================================
bool ffw::GuiSlider::isVertical() const {
    return vertical;
}

///=============================================================================
void ffw::GuiSlider::setBarSize(const ffw::Vec2<GuiUnits>& s) {
    barSize = s;
    redraw();
}

///=============================================================================
void ffw::GuiSlider::setButtonSize(const ffw::Vec2<GuiUnits>& s) {
    buttonSize = s;
    redraw();
}

///=============================================================================
void ffw::GuiSlider::setValue(float val){
    if(inverse) {
        val = (range.y - range.x) - val;
    }
    const auto old = value;
    value = ffw::clamp(val, range.x, range.y);
    if(old != value){
        GuiEvent::Data dat;
        dat.action.value = int(getValue());
        pushEvent(GuiEventType::ACTION, dat);
        redraw();
    }
}

///=============================================================================
float ffw::GuiSlider::getValue() const {
    if (inverse)return (range.y - range.x) - value;
    return value;
}

///=============================================================================
const ffw::Vec2f& ffw::GuiSlider::getRange() const {
    return range;
}

///=============================================================================
void ffw::GuiSlider::setRange(const float min, const float max){
    range.set(min, max);
    const auto old = value;
    value = ffw::clamp(value, range.x, range.y);
    if(std::abs(old - value) > std::numeric_limits<float>::epsilon()){
        GuiEvent::Data dat;
        dat.action.value = int(getValue());
        pushEvent(GuiEventType::ACTION, dat);
    }
    redraw();
}

///=============================================================================
void ffw::GuiSlider::setInversed(const bool inversed){
    inverse = inversed;
    redraw();
}

///=============================================================================
bool ffw::GuiSlider::getInversed() const {
    return inverse;
}

///=============================================================================
void ffw::GuiSlider::setBarStyleGroup(const GuiWidget::Style* style) {
    styleBar = style;
    redraw();
}

///=============================================================================
void ffw::GuiSlider::setButtonStyleGroup(const GuiWidget::Style* style) {
    styleButton = style;
    redraw();
}

///=============================================================================
void ffw::GuiSlider::calculateButtonSize(ffw::Vec2f& p, ffw::Vec2f& s) const {
    const auto contentsize = getVisibleContentSize();
    s = ffw::Vec2f(buttonSize.x.toReal(contentsize.x), buttonSize.y.toReal(contentsize.y));
    const auto thick = ffw::Vec2f(barSize.x.toReal(contentsize.x), barSize.y.toReal(contentsize.y));

    if (vertical) {
        auto height = float(((value - range.x) / float(range.y)) * (contentsize.y - s.y));
        height = ffw::clamp(height, 0.0f, (contentsize.y - s.y));

        p.set(0, 0);
        p.x += contentsize.x / 2;
        p.y += height;
        p.x -= s.x / 2;
    }
    else {
        auto width = float(((value - range.x) / float(range.y)) * (contentsize.x - s.x));
        width = ffw::clamp(width, 0.0f, (contentsize.x - s.x));

        p.set(0, 0);
        p.y += contentsize.y / 2;
        p.x += width;
        p.y -= s.y / 2;
    }
}

///=============================================================================
void ffw::GuiSlider::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize){
    const auto* cStyleBar = getCurrentStyle(styleBar);
    const auto* cStyleButton = getCurrentStyle(styleButton);

    if (cStyleBar == nullptr || cStyleButton == nullptr)return;

    const auto test = std::abs(range.x - range.y);
    if (test == 0)return;

    const auto buttonSizeReal = ffw::Vec2f(buttonSize.x.toReal(contentsize.x), buttonSize.y.toReal(contentsize.y));

    if(vertical){
        float height = 0;
        const auto thick = ffw::Vec2f(barSize.x.toReal(contentsize.x), barSize.y.toReal(contentsize.y));
        const ffw::Vec2f off(contentsize.x / 2 - thick.x / 2, contentsize.y / 2 - thick.y / 2);
        ffw::Vec2f p(contentoffset + off);
        ffw::Vec2f s(thick.x, thick.y);
        
        if(inverse){
            height = float((1.0f - ((value - range.x) / float(range.y))) * thick.y);
        } else {
            height = float(((value - range.x) / float(range.y)) * thick.y);
        }
        height = ffw::clamp(height, 0.0f, thick.y);

        renderComponent(p, thick, cStyleBar);

        s.y = height;
        if(cStyleBar->border.size[0]){
            s.y -= cStyleBar->border.size[0];
            p.y += cStyleBar->border.size[0];
        }
        if(cStyleBar->border.size[1]){
            s.x -= cStyleBar->border.size[1];
        }
        if(cStyleBar->border.size[2]){
            s.y -= cStyleBar->border.size[2];
        }
        if(cStyleBar->border.size[3]){
            s.x -= cStyleBar->border.size[3];
            p.x += cStyleBar->border.size[0];
        }

        if(cStyleBar->function.color.a > 0.0f && s.y > 0){
            if(inverse){
                context->drawRectangle((p + ffw::Vec2f(0, thick.y - height)).floor(), s.ceil(), cStyleBar->function.color);
            } else {
                context->drawRectangle(p.floor(), s.ceil(), cStyleBar->function.color);
            }
        }

        height = float(((value - range.x) / float(range.y)) * (contentsize.y - buttonSizeReal.y));
        height = ffw::clamp(height, 0.0f, (contentsize.y - buttonSizeReal.y));

        p.set(contentoffset);
        p.x += contentsize.x / 2;
        p.y += height;
        p.x -= buttonSizeReal.x /2;

        renderComponent(p, buttonSizeReal, cStyleButton);

    } else {
        float width = 0;
        const auto thick = ffw::Vec2f(barSize.x.toReal(contentsize.x), barSize.y.toReal(contentsize.y));
        const ffw::Vec2f off(contentsize.x / 2 - thick.x / 2, contentsize.y / 2 - thick.y / 2);
        ffw::Vec2f p(contentoffset + off);
        ffw::Vec2f s(contentsize.x, thick.y);
        
        if(inverse){
            width = float((1.0f - ((value - range.x) / float(range.y))) * thick.x);
        } else {
            width = float(((value - range.x) / float(range.y)) * thick.x);
        }
        width = ffw::clamp(width, 0.0f, thick.x);

        renderComponent(p, thick, cStyleBar);

        s.x = width;
        if(cStyleBar->border.size[0]){
            s.y -= cStyleBar->border.size[0];
            p.y += cStyleBar->border.size[0];
        }
        if(cStyleBar->border.size[1]){
            s.x -= cStyleBar->border.size[1];
        }
        if(cStyleBar->border.size[2]){
            s.y -= cStyleBar->border.size[2];
        }
        if(cStyleBar->border.size[3]){
            s.x -= cStyleBar->border.size[3];
            p.x += cStyleBar->border.size[0];
        }

        if(cStyleBar->function.color.a > 0.0f && s.x > 0){
            if(inverse){
                context->drawRectangle((p + ffw::Vec2f(thick.x - width, 0)).floor(), s.ceil(), cStyleBar->function.color);
            } else {
                context->drawRectangle(p.floor(), s.ceil(), cStyleBar->function.color);
            }
        }

        width = float(((value - range.x) / float(range.y)) * (contentsize.x - buttonSizeReal.x));
        width = ffw::clamp(width, 0.0f, (contentsize.x - buttonSizeReal.x));

        p.set(contentoffset);
        p.y += contentsize.y / 2;
        p.x += width;
        p.y -= buttonSizeReal.y /2;

        renderComponent(p, buttonSizeReal, cStyleButton);
    }
}

///=============================================================================
void ffw::GuiSlider::eventHover(bool gained){
    (void)gained;
    redraw();
}

///=============================================================================
void ffw::GuiSlider::eventFocus(bool gained){
    (void)gained;
    redraw();
}

///=============================================================================
void ffw::GuiSlider::eventMouse(const ffw::Vec2f& mousePos){
    if(hasFocus()){
        const auto newPos = mousePos - clickedOffset;
        auto newvalue = value;
        const auto realSize = getVisibleContentSize();
        const auto btnSize = ffw::Vec2f(buttonSize.x.toReal(realSize.x), buttonSize.y.toReal(realSize.y));
        if(vertical){
            const auto height = realSize.y - btnSize.y;
            const auto frac = ffw::clamp((newPos.y - btnSize.y/2) / float(height), 0.0f, 1.0f);

            newvalue = ffw::lerp(range.x, range.y, frac);
        } else {
            const auto width = realSize.x - btnSize.x;
            const auto frac = ffw::clamp((newPos.x - btnSize.x/2) / float(width), 0.0f, 1.0f);

            newvalue = ffw::lerp(range.x, range.y, frac);
        }
        if(std::abs(newvalue - value) > std::numeric_limits<float>::epsilon()){
            value = newvalue;
            GuiEvent::Data dat;
            dat.action.value = int(getValue());
            pushEvent(GuiEventType::ACTION, dat);
            redraw();
        }
    }
}

///=============================================================================
void ffw::GuiSlider::eventMouseButton(const ffw::MouseButton button, const ffw::Mode mode){
    if(button == ffw::MouseButton::LEFT && mode == ffw::Mode::PRESSED){
        const auto mouse = getMousePos();
        ffw::Vec2f btnPos, btnSize;
        calculateButtonSize(btnPos, btnSize);
        clickedOffset = mouse - btnPos;
        if (clickedOffset.x < 0 || clickedOffset.x > btnSize.x ||
            clickedOffset.y < 0 || clickedOffset.y > btnSize.y) {

            clickedOffset = 0;
        } else {
            clickedOffset -= btnSize / 2;
        }

        eventMouse(mouse);
    }
}

///=============================================================================
void ffw::GuiSlider::eventThemeChanged(const GuiTheme* theme, const bool defaults) {
    setStyle(&theme->slider, defaults);
}

///=============================================================================
void ffw::GuiSlider::setStyle(const GuiSlider::Style* style, const bool defaults) {
    widgetStyle = &style->self;
    styleBar = &style->bar;
    styleButton = &style->button;
    if (defaults) {
        setDefaults(&widgetStyle->defaults);
        barSize = styleBar->defaults.size;
        buttonSize = styleButton->defaults.size;
    }
}

///=============================================================================
ffw::Vec2f ffw::GuiSlider::getMinimumWrapSize() {
    const auto realSize = getRealSize();
    const auto btnSize = ffw::Vec2f(buttonSize.x.toReal(realSize.x), buttonSize.y.toReal(realSize.y));

    if (vertical)return ffw::Vec2f(btnSize.x, btnSize.y * 2);
    return ffw::Vec2f(btnSize.x * 2, btnSize.y);
}