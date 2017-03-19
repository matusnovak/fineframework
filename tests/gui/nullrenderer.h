#include <ffw/gui.h>

class GuiWidgetNull: public ffw::GuiWidget {
public:
	GuiWidgetNull(ffw::GuiWindow* context):GuiWidget(context) {
	}
	virtual ~GuiWidgetNull() {
	}
	ffw::Vec2i getMinimumWrapSize() override {
		return 0;
	}
private:
	void eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) override {
		(void)contentoffset;
		(void)contentsize;
	}
	void eventPos(const ffw::Vec2i& pos) override {
		(void)pos;
	}
	void eventSize(const ffw::Vec2i& size) override {
		(void)size;
	}
	void eventHover(bool gained) override {
		(void)gained;
	}
	void eventFocus(bool gained) override {
		(void)gained;
	}
	void eventMouse(const ffw::Vec2i& pos) override {
		(void)pos;
	}
	void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) override {
		(void)button;
		(void)mode;
	}
	void eventText(wchar_t chr) override {
		(void)chr;
	}
	void eventKey(ffw::Key key, ffw::Mode mode) override {
		(void)key;
		(void)mode;
	}
	void eventDisabled(bool disabled) override {
		(void)disabled;
	}
	void eventThemeChanged(const ffw::GuiTheme* theme) override {
		(void)theme;
	}
};

class GuiFontNull: public ffw::GuiFont {
public:
	GuiFontNull() {
		points = 0;
	}
	virtual ~GuiFontNull() {
	}
	bool isCreated() const override {
		return true;
	}
	void destroy() override {
	}
	void create(int pixels) {
		points = pixels;
	}
	ffw::Vec2i getStringSize(const std::wstring& str, float lineHeight = 1.25) const override {
		return getStringSizeFunc(str, lineHeight);
	}
	ffw::Vec2i getStringSize(const std::string& str, float lineHeight = 1.25) const override {
		return getStringSizeFunc(str, lineHeight);
	}
	virtual int getCharAdvance(wchar_t c) const override {
		(void)c;
		return points;
	}
	virtual int getSizeInPixels() const override {
		return points;
	}
private:
	template<class T>
	ffw::Vec2i getStringSizeFunc(const T& str, float lineHeight) const {
		ffw::Vec2i size(0, int(points * lineHeight));
		int width = 0;
		for (const auto& c : str) {
			if (c == '\n') {
				size.y += int(points * lineHeight);
				width = std::max(size.x, width);
				size.x = 0;
			}
			else {
				width += points;
			}
		}
		size.x = std::max(size.x, width);
		return size;
	}
	int points;
};

class GuiWindowNull : public ffw::GuiWindow {
public:
	GuiWindowNull() {
	}
	virtual ~GuiWindowNull() {
	}
	 void resize(int width, int height) override {
		 (void)width;
		 (void)height;
	}
	void drawRectangle(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color) const override {
		(void)pos;
		(void)size;
		(void)color;
	}
	void drawTriangle(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Color& color) const override {
		(void)p0;
		(void)p1;
		(void)p2;
		(void)color;
	}
	void drawRectangleRounded(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::Color& color, int tl, int tr, int br, int bl) const override {
		(void)pos;
		(void)size;
		(void)color;
		(void)tl;
		(void)tr;
		(void)br;
		(void)bl;
	}
	void drawLine(const ffw::Vec2i& start, const ffw::Vec2i& end, const ffw::Color& color) const override {
		(void)start;
		(void)end;
		(void)color;
	}
	void drawCircle(const ffw::Vec2i& pos, int radius, const ffw::Color& color) const override {
		(void)pos;
		(void)radius;
		(void)color;
	}
	void drawArc(const ffw::Vec2i& pos, int inner, int outer, float start, float end, const ffw::Color& color) const override {
		(void)pos;
		(void)inner;
		(void)outer;
		(void)start;
		(void)end;
		(void)color;
	}
	void drawQuad(const ffw::Vec2i& p0, const ffw::Vec2i& p1, const ffw::Vec2i& p2, const ffw::Vec2i& p3, const ffw::Color& color) const override {
		(void)p0;
		(void)p1;
		(void)p2;
		(void)p3;
		(void)color;
	}
	void drawString(const ffw::Vec2i& pos, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const override {
		(void)pos;
		(void)font;
		(void)str;
		(void)length;
		(void)color;
	}
	void drawImage(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const override {
		(void)pos;
		(void)size;
		(void)image;
		(void)sub;
		(void)mirrorX;
		(void)mirrorY;
		(void)color;
	}
	void startRender() override {
	}
	void endRender() override {
	}
	void setScissors(const ffw::Vec2i& pos, const ffw::Vec2i& size) const override {
		(void)pos;
		(void)size;
	}
	void clearWithColor(const ffw::Color& color) const override {
		(void)color;
	}
};

class GuiWidgetNullSticky : public GuiWidgetNull {
public:
	GuiWidgetNullSticky(ffw::GuiWindow* context):GuiWidgetNull(context) {
		GuiWidget::setStickyFocus();
	}
	virtual ~GuiWidgetNullSticky() {

	}
};

class GuiWidgetNullToggle : public GuiWidgetNull {
public:
	GuiWidgetNullToggle(ffw::GuiWindow* context) :GuiWidgetNull(context) {
		GuiWidget::setToggleFocus();
	}
	virtual ~GuiWidgetNullToggle() {

	}
};

class GuiWidgetNullDrop : public GuiWidgetNull {
public:
	GuiWidgetNullDrop(ffw::GuiWindow* context) :GuiWidgetNull(context) {
		GuiWidget::setDropFocus();
	}
	virtual ~GuiWidgetNullDrop() {

	}
};

class GuiEventCatcher {
public:
	GuiEventCatcher() {

	}
	~GuiEventCatcher() {

	}
	void widgetEvent(ffw::GuiEvent e) {
		events.push_back(e);
	}
	void reset() {
		events.clear();
	}
	size_t count(ffw::GuiEvent::Type type, ffw::GuiWidget* widget = NULL) {
		size_t cnt = 0;
		for (const auto& e : events) {
			if (widget != NULL && e.type == type && e.widget == widget)cnt++;
			if (widget == NULL && e.type == type)cnt++;
		}
		return cnt;
	}
	ffw::GuiEvent get(ffw::GuiEvent::Type type, ffw::GuiWidget* widget = NULL) {
		for (const auto& e : events) {
			if (widget != NULL && e.type == type && e.widget == widget)return e;
			if (widget == NULL && e.type == type)return e;
		}
		throw std::out_of_range("No event found!");
	}
	std::vector<ffw::GuiEvent> events;
};

#include "nullstyles.h"

#define TEST_SETUP_WINDOW(w, h) \
	GuiWindowNull gui; \
	GuiFontNull font; \
	font.create(8); \
	gui.setPos(0, 0); \
	gui.setSize(w, h); \
	gui.setTheme(&NullTheme); \
	gui.setDefaultFont(&font);

#define TEST_UPDATE_AND_RENDER \
	gui.update(); \
	gui.render(); \
	gui.poolEvents();
	
// End