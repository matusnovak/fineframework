/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiwindow.h"
#include "ffw/gui/guitheme.h"

///=============================================================================
ffw::GuiWindow::GuiWindow(){
    theme = &GuiThemeSimpleLight::singleton;
    body = new GuiBody(this, GuiOrientation::VERTICAL);
    body->setPos(0, 0);
    defaultfont = NULL;
    input.chr = 0xFFFF;
    input.keymode = ffw::Mode::NONE;
    input.mousemode = ffw::Mode::NONE;
}

///=============================================================================
ffw::GuiWindow::~GuiWindow(){
    delete body;
}

///=============================================================================
void ffw::GuiWindow::setSize(float width, float height){
    size.set(width, height);
    body->setSize(width, height);
    resize((int)width, (int)height);
}

///=============================================================================
void ffw::GuiWindow::setPos(float posx, float posy){
    pos.set(posx, posy);
}

///=============================================================================
const ffw::Vec2f& ffw::GuiWindow::getSize() const {
    return size;
}

///=============================================================================
const ffw::Vec2f& ffw::GuiWindow::getPos() const {
    return pos;
}

///=============================================================================
void ffw::GuiWindow::setTheme(const GuiTheme* thm, const bool defaults) {
    theme = thm;
    body->setTheme(thm, defaults);
}

///=============================================================================
const ffw::GuiTheme* ffw::GuiWindow::getTheme() const {
    return theme;
}
        
///=============================================================================
void ffw::GuiWindow::setDefaultFont(const GuiFont* font){
    defaultfont = font;
    body->redraw();
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWindow::getDefaultFont() const {
    return defaultfont;
}

///=============================================================================
void ffw::GuiWindow::injectMousePos(float posx, float posy){
    mousepos.set(posx - pos.x, posy - pos.y);
}

///=============================================================================
void ffw::GuiWindow::injectScroll(float posx, float posy){
    input.scroll.set(posx, posy);
}

///=============================================================================
void ffw::GuiWindow::injectMouseButton(ffw::MouseButton button, ffw::Mode mode){
    input.mousebtn = button;
    input.mousemode = mode;
}

///=============================================================================
void ffw::GuiWindow::injectText(wchar_t chr){
    input.chr = chr;
}

///=============================================================================
void ffw::GuiWindow::injectKey(ffw::Key key, ffw::Mode mode){
    input.key = key;
    input.keymode = mode;
}

///=============================================================================
void ffw::GuiWindow::update(){
    const auto& s = body->getSize();
    body->update(ffw::Vec2f(0, 0), ffw::Vec2f(s.x.value, s.y.value), input, mousepos, false);
    input.mousemode = ffw::Mode::NONE;
    input.chr = 0xFFFF;
    input.keymode = ffw::Mode::NONE;
    input.scroll = 0;
}

///=============================================================================
void ffw::GuiWindow::poolEvents(){
    while(!eventqueue.empty()){
        auto& e = eventqueue.front();

        if(e.first != nullptr){
            e.first(e.second);
        }

        eventqueue.pop();
    }
}

///=============================================================================
void ffw::GuiWindow::render(){
    startRender();
    const auto& s = body->getSize();
    body->render(ffw::Vec2f(0, 0), ffw::Vec2f(s.x.value, s.y.value), ffw::Vec2f(0, 0), true);
    endRender();
}

///=============================================================================
void ffw::GuiWindow::redraw(){
    body->redraw();
}

///=============================================================================
void ffw::GuiWindow::invalidate(){
    body->redraw();
}

///=============================================================================
void ffw::GuiWindow::pushEvent(std::vector<GuiCallback>& callbacks, GuiEvent e){
    for(auto& call : callbacks) {
        if (call.func == nullptr)continue;
        if ((int)call.type & (int)e.type) {

            if (call.now) {
                call.func(e);
            }
            else {
                eventqueue.push(std::make_pair(call.func, e));
            }
        }
    }
}