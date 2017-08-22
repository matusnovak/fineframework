/*** This file is part of FineFramework project ***/

#include "ffw/gui/guirichtext.h"
#include "ffw/gui/guiwindow.h"

///=============================================================================
ffw::GuiRichText::GuiRichText(GuiWindow* context) : GuiWidget(context) {
	setIgnoreUserInput(true);
	// At this point, we are sure that the context and getTheme() are not NULL
	widgetStyle = &context->getTheme()->getStyleGroup("GUI_LABEL");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::GuiRichText::~GuiRichText() {
}

///=============================================================================
void ffw::GuiRichText::setText(const std::wstring& label_) {
	text.setValue(label_, getStyleGroup()->normal.text.color, getCurrentFont());
	lastCalculatedWidth = getVisibleContentSize().x;
	text.recalculate(lastCalculatedWidth);
	redraw();
}

///=============================================================================
const std::wstring ffw::GuiRichText::getText() const {
	return text.getValue();
}

///=============================================================================
void ffw::GuiRichText::addParagraph() {
	text.addParagraph();
	redraw();
}

///=============================================================================
void ffw::GuiRichText::addSection(const ffw::Color& color, ffw::GuiFont* font) {
	text.section(color, (font == NULL ? getCurrentFont() : font));
	redraw();
}

///=============================================================================
void ffw::GuiRichText::addSection(ffw::GuiFont* font) {
	text.section(getStyleGroup()->normal.text.color, (font == NULL ? getCurrentFont() : font));
	redraw();
}

///=============================================================================
void ffw::GuiRichText::addSectionDefault() {
	text.section(getStyleGroup()->normal.text.color, getCurrentFont());
	redraw();
}

///=============================================================================
void ffw::GuiRichText::addText(const std::wstring& str) {
	if (text.getParagraphs().size() > 0) {
		text.append(str);
		text.getParagraphs().back().recalculate(getVisibleContentSize().x);
		redraw();
	}
}

///=============================================================================
void ffw::GuiRichText::eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) {
	(void)contentsize;
	//context->drawStringAligned(contentoffset, contentsize, getCurrentFont(), getAlign(), label, getCurrentStyle()->text, getLineHeight());
	if(text.getParagraphs().size() > 0) {
		ffw::Vec2f p = contentoffset;
		for(const auto& par : text.getParagraphs()) {
			if (par.getText().size() == 0)continue;

			ffw::GuiTextWrapper::Stepper stepper(par);
			while(stepper.getNext()) {
				if (stepper.getLength() == 0)continue;
				context->drawString(p, stepper.getFont(), stepper.getPtr(), stepper.getLength(), stepper.getColor(), getLineHeight());
				if (stepper.isNewline()) {
					p.y += int(stepper.getHeight() * getLineHeight());
					p.x = contentoffset.x;
				} else {
					auto font = stepper.getFont();
					auto wstr = stepper.getPtr();
					for(size_t i = 0; i < stepper.getLength(); i++) {
						p.x += font->getCharAdvance(wstr[i]);
					}
				}
			}
		}
	}
}

///=============================================================================
void ffw::GuiRichText::eventPos(const ffw::Vec2f& p) {
	(void)p;
}

///=============================================================================
void ffw::GuiRichText::eventSize(const ffw::Vec2f& s) {
	(void)s;
	lastCalculatedWidth = getVisibleContentSize().x;
	text.recalculate(lastCalculatedWidth);
}

///=============================================================================
void ffw::GuiRichText::eventHover(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiRichText::eventFocus(bool gained) {
	(void)gained;
}

///=============================================================================
void ffw::GuiRichText::eventMouse(const ffw::Vec2f& mousePos) {
	(void)mousePos;
}

///=============================================================================
bool ffw::GuiRichText::eventScroll(const ffw::Vec2f& scroll) {
	(void)scroll;
	return false;
}

///=============================================================================
void ffw::GuiRichText::eventMouseButton(ffw::MouseButton button, ffw::Mode mode) {
	(void)button;
	(void)mode;
}

///=============================================================================
void ffw::GuiRichText::eventText(wchar_t chr) {
	(void)chr;
}

///=============================================================================
void ffw::GuiRichText::eventKey(ffw::Key key, ffw::Mode mode) {
	(void)key;
	(void)mode;
}

///=============================================================================
void ffw::GuiRichText::eventDisabled(bool disabled) {
	(void)disabled;
}

///=============================================================================
void ffw::GuiRichText::eventThemeChanged(const GuiTheme* theme) {
	widgetStyle = &theme->getStyleGroup("GUI_LABEL");
	setDefaults(&widgetStyle->defaults);
}

///=============================================================================
ffw::Vec2f ffw::GuiRichText::getMinimumWrapSize() {
	auto test = getVisibleContentSize().x;;
	if(test != lastCalculatedWidth) {
		text.recalculate(test);
	}
	ffw::Vec2f ret(test, 0);
	for(const auto& p : text.getParagraphs()) {
		ret.y += float(p.getTotalHeight() * getLineHeight());
	}
	return ret;
}