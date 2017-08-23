/*** This file is part of FineFramework project ***/

#include "ffw/gui/guiimageviewer.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiImageViewer::GuiImageViewer(GuiWindow* context, const GuiImage* image) : GuiWidget(context) {
	setIgnoreUserInput(true);
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_IMAGE");
	setDefaults(&widgetStyle->defaults);
	setImage(image);
}

///=============================================================================
ffw::GuiImageViewer::~GuiImageViewer() {
}

///=============================================================================
void ffw::GuiImageViewer::setImage(const GuiImage* image) {
	img = image;
	if(image != NULL)setSubsection(0, 0, img->getWidth(), img->getHeight());
	else setSubsection(0, 0, 0, 0);
	setMirror(false, false);
	redraw();
}

///=============================================================================
void ffw::GuiImageViewer::setSubsection(int posx, int posy, int width, int height) {
	sub.set(posx, posy, width, height);
	redraw();
}

///=============================================================================
void ffw::GuiImageViewer::setMirror(bool mirrorX, bool mirrorY) {
	mirror.set(mirrorX, mirrorY);
	redraw();
}

///=============================================================================
void ffw::GuiImageViewer::setLabel(const std::wstring& label_){
	label = label_;
	redraw();
}

///=============================================================================
const std::wstring& ffw::GuiImageViewer::getLabel() const {
	return label;
}

///=============================================================================
void ffw::GuiImageViewer::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	context->drawImage(contentoffset, contentsize, img, sub, mirror.x, mirror.y, getCurrentStyle()->function.color);
	context->drawStringAligned(contentoffset, contentsize, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
}

///=============================================================================
void ffw::GuiImageViewer::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiImageViewer::eventSize(const ffw::Vec2f& s) {
	(void)s;
}

///=============================================================================
void ffw::GuiImageViewer::eventHover(bool gained) {
	(void)gained;
	redraw();
}

///=============================================================================
void ffw::GuiImageViewer::eventFocus(bool gained) {
	redraw();

	if (!gained || getFlags().focusType != GuiWidget::Focus::DROP) {
		GuiEvent::Data dat;
		if (getFlags().focusType == GuiWidget::Focus::DROP)dat.clicked.value = true;
		else dat.clicked.value = gained;
		pushEvent(GuiEvent::Type::CLICKED, dat);
	}
}

///=============================================================================
void ffw::GuiImageViewer::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiImageViewer::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiImageViewer::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiImageViewer::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiImageViewer::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiImageViewer::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiImageViewer::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_IMAGE");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiImageViewer::getMinimumWrapSize() {
	if (img == NULL)return 0;
	//return ffw::Vec2i(img->getWidth(), img->getHeight());
	if(getSize().x == guiWrap() && getSize().y == guiWrap()) {
		return static_cast<ffw::Vec2f>(ffw::Vec2i(sub.z, sub.w));
	}
	else if(getSize().x == guiWrap()) {
		float aspect = sub.z / (float)sub.w;
		auto s = getVisibleContentSize();
		return ffw::Vec2f(s.y * aspect, s.y);
	}
	else if (getSize().y == guiWrap()) {
		float aspect = sub.z / (float)sub.w;
		auto s = getVisibleContentSize();
		return ffw::Vec2f(s.x, s.x / aspect);
	}
	else {
		return static_cast<ffw::Vec2f>(ffw::Vec2i(sub.z, sub.w));
	}
}