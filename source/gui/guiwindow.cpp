/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiWindow::GuiBody::GuiBody(GuiWindow* context, GuiLayout::Orientation orient):GuiLayout(context, orient, typeid(GuiBody)) {
	
}

ffw::GuiWindow::GuiBody::~GuiBody() {
	
}

///=============================================================================
ffw::GuiWindow::GuiWindow(){
	theme = &GuiTheme::Windows;
	body = new GuiBody(this, GuiLayout::Orientation::VERTICAL);
	body->SetPos(0, 0);
	body->SetPadding(ffw::GuiPixels(10));
	//body->Style().normal.background = true;
	//body->Style().normal.backgroundcolor = ffw::Rgb(0xF0F0F0);
	defaultfont = NULL;
	input.chr = 0xFFFF;
	input.keymode = ffw::Mode::NONE;
	input.mousemode = ffw::Mode::NONE;
	input.mouseout = false;
}

///=============================================================================
ffw::GuiWindow::~GuiWindow(){
	delete body;
}

///=============================================================================
void ffw::GuiWindow::SetSize(int width, int height){
	size.Set(width, height);
	body->SetSize(width, height);
	Resize(width, height);
}

///=============================================================================
void ffw::GuiWindow::SetPos(int posx, int posy){
	pos.Set(posx, posy);
}

///=============================================================================
const ffw::Vec2i& ffw::GuiWindow::GetSize() const {
	return size;
}

///=============================================================================
const ffw::Vec2i& ffw::GuiWindow::GetPos() const {
	return pos;
}

///=============================================================================
void ffw::GuiWindow::SetPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left){
	body->SetPadding(top, right, bottom, left);
}

///=============================================================================
void ffw::GuiWindow::SetTheme(const GuiTheme* thm) {
	theme = thm;
}

///=============================================================================
const ffw::GuiTheme* ffw::GuiWindow::GetTheme() const {
	return theme;
}

///=============================================================================
void ffw::GuiWindow::SetPadding(GuiUnits all){
	body->SetPadding(all);
}

///=============================================================================
void ffw::GuiWindow::Destroy(){
	DeleteWidgets();
}
		
///=============================================================================
void ffw::GuiWindow::SetDefaultFont(const GuiFont* font){
	defaultfont = font;
	body->Redraw();
}

///=============================================================================
const ffw::GuiFont* ffw::GuiWindow::GetDefaultFont() const {
	return defaultfont;
}

///=============================================================================
void ffw::GuiWindow::InjectMousePos(int posx, int posy){
	input.mousepos.Set(posx, posy);
}

///=============================================================================
void ffw::GuiWindow::InjectMouseButton(ffw::MouseButton button, ffw::Mode mode){
	input.mousebtn = button;
	input.mousemode = mode;
}

///=============================================================================
void ffw::GuiWindow::InjectText(wchar_t chr){
	input.chr = chr;
}

///=============================================================================
void ffw::GuiWindow::InjectKey(ffw::Key key, ffw::Mode mode){
	input.key = key;
	input.keymode = mode;
}

///=============================================================================
void ffw::GuiWindow::Update(){
	const auto& size = body->GetSize();
	body->Update(ffw::Vec2i(0, 0), ffw::Vec2i(size.x.value, size.y.value), input);
	input.mousemode = ffw::Mode::NONE;
	input.chr = 0xFFFF;
	input.keymode = ffw::Mode::NONE;
}

///=============================================================================
void ffw::GuiWindow::PoolEvents(){
	while(!eventqueue.empty()){
		auto& e = eventqueue.front();

		if(e.first != nullptr){
			e.first(e.second);
		}

		eventqueue.pop();
	}
}

///=============================================================================
void ffw::GuiWindow::Render(){
	StartRender();
	const auto& size = body->GetSize();
	body->Render(ffw::Vec2i(0, 0), ffw::Vec2i(size.x.value, size.y.value), ffw::Vec2i(0, 0), true);
	EndRender();
}

///=============================================================================
void ffw::GuiWindow::Redraw(){
	body->Redraw();
}

///=============================================================================
void ffw::GuiWindow::Invalidate(){
	body->Redraw();
}

///=============================================================================
void ffw::GuiWindow::PushEvent(GuiCallback& callback, GuiEvent e){
	/*if (callback == nullptr) {
		std::cout << "callback is null!" << std::endl;
		return;
	}
	eventqueue.push(std::make_pair(callback, e));*/
	for(auto& call : callback.callbacks) {
		if (call.func == nullptr)continue;

		if(call.now) {
			call.func(e);
		} else {
			eventqueue.push(std::make_pair(call.func, e));
		}
	}
}