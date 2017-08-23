#include <ffw/gui.h>

class GuiWidgetNull: public ffw::GuiWidget {
public:
	GuiWidgetNull(ffw::GuiWindow* context):GuiWidget(context) {
	}
	virtual ~GuiWidgetNull() {
	}
	ffw::Vec2f getMinimumWrapSize() override {
		return 0;
	}
private:
	void eventRender(const ffw::Vec2f& contentoffset, const ffw::Vec2f& contentsize) override {
		(void)contentoffset;
		(void)contentsize;
	}
	void eventPos(const ffw::Vec2f& p) override {
		(void)p;
	}
	void eventSize(const ffw::Vec2f& s) override {
		(void)s;
	}
	void eventHover(bool gained) override {
		(void)gained;
	}
	void eventFocus(bool gained) override {
		(void)gained;
	}
	void eventMouse(const ffw::Vec2f& p) override {
		(void)p;
	}
	bool eventScroll(const ffw::Vec2f& s) override {
		(void)s;
		return false;
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
	ffw::Vec2f getStringSize(const std::wstring& str, float lineHeight = 1.25) const override {
		return getStringSizeFunc(str, lineHeight);
	}
	ffw::Vec2f getStringSize(const std::string& str, float lineHeight = 1.25) const override {
		return getStringSizeFunc(str, lineHeight);
	}
	virtual float getCharAdvance(wchar_t c) const override {
		(void)c;
		return (float)points;
	}
	virtual int getSizeInPixels() const override {
		return points;
	}
private:
	template<class T>
	ffw::Vec2f getStringSizeFunc(const T& str, float lineHeight) const {
		ffw::Vec2f s(0, float(points * lineHeight));
		float width = 0;
		for (const auto& c : str) {
			if (c == '\n') {
				s.y += int(points * lineHeight);
				width = std::max(s.x, width);
				s.x = 0;
			}
			else {
				width += points;
			}
		}
		s.x = std::max(s.x, width);
		return s;
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
	void drawRectangle(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::Color& color) const override {
		(void)p;
		(void)s;
		(void)color;
	}
	void drawTriangle(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Color& color) const override {
		(void)p0;
		(void)p1;
		(void)p2;
		(void)color;
	}
	void drawRectangleRounded(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::Color& color, float tl, float tr, float br, float bl) const override {
		(void)p;
		(void)s;
		(void)color;
		(void)tl;
		(void)tr;
		(void)br;
		(void)bl;
	}
	void drawLine(const ffw::Vec2f& start, const ffw::Vec2f& end, const ffw::Color& color) const override {
		(void)start;
		(void)end;
		(void)color;
	}
	void drawCircle(const ffw::Vec2f& p, float radius, const ffw::Color& color) const override {
		(void)p;
		(void)radius;
		(void)color;
	}
	void drawArc(const ffw::Vec2f& p, float inner, float outer, float start, float end, const ffw::Color& color) const override {
		(void)p;
		(void)inner;
		(void)outer;
		(void)start;
		(void)end;
		(void)color;
	}
	void drawQuad(const ffw::Vec2f& p0, const ffw::Vec2f& p1, const ffw::Vec2f& p2, const ffw::Vec2f& p3, const ffw::Color& color) const override {
		(void)p0;
		(void)p1;
		(void)p2;
		(void)p3;
		(void)color;
	}
	void drawString(const ffw::Vec2f& p, const ffw::GuiFont* font, const std::wstring::value_type* str, size_t length, const ffw::Color& color, float lineHeight = 1.25f) const override {
		(void)p;
		(void)font;
		(void)str;
		(void)length;
		(void)color;
		(void)lineHeight;
	}
	void drawImage(const ffw::Vec2f& p, const ffw::Vec2f& s, const ffw::GuiImage* image, const ffw::Vec4i& sub, bool mirrorX, bool mirrorY, const ffw::Color& color) const override {
		(void)p;
		(void)s;
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
	void setScissors(const ffw::Vec2f& p, const ffw::Vec2f& s) const override {
		(void)p;
		(void)s;
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
	gui.setTheme(&NullTheme); \
	gui.setPos(0, 0); \
	gui.setSize(w, h); \
	gui.setDefaultFont(&font);

#define TEST_UPDATE_AND_RENDER \
	gui.update(); \
	gui.render(); \
	gui.poolEvents();
	
// End