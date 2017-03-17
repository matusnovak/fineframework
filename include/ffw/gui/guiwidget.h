/* This file is part of FineFramework project */
#ifndef FFW_GUI_WIDGET
#define FFW_GUI_WIDGET
#include "guifont.h"
#include "guitheme.h"
#include <functional>
namespace ffw {
	class GuiWindow;
	class GuiWidget;
	/**
	 * @ingroup gui
	 */
	class GuiEvent {
	public:
		enum class Type {
			CLICKED = 0,
			SELECTED,
			CHANGED,
			SIZE,
			INNER,
			POSITION,
			HOVER,
			FOCUS,
			STATE,
			INPUT,
			KEY,
		};
		union Data {
			struct ClickedData {
				bool value;
			} clicked;

			struct SelectedData {
				unsigned int index;
			} selected;

			struct ChangedData {
				int value;
			} changed;

			struct SizeData {
				int width;
				int height;
			} size;

			struct InnerData {
				int width;
				int height;
			} inner;

			struct PosData {
				int x;
				int y;
			} pos;

			struct HoverData {
				bool gained;
			} hover;

			struct FocusData {
				bool gained;
			} focus;

			struct StateData {
				bool disabled;
			} state;

			struct InputData {
				wchar_t chr;
			} input;

			struct InputKey {
				ffw::Key key;
				ffw::Mode mode;
			} key;
		};
		GuiWidget* widget;
		Type type;
		Data data;
	};
	/**
	* @ingroup gui
	*/
	class GuiCallback {
	public:
		class Data {
		public:
			std::function<void(GuiEvent)> func = nullptr;
			bool now = false;
		};
		template<class T>
		void add(void (T::*memfuncptr)(GuiEvent), T* instance, bool instant) {
			callbacks.push_back(Data());
			callbacks.back().func = std::bind(memfuncptr, instance, std::placeholders::_1);
			callbacks.back().now = instant;
		}
		std::vector<Data> callbacks;
	};
	/**
	 * @ingroup gui
	 */
	class GuiUserInput {
	public:
		ffw::MouseButton mousebtn;
		ffw::Mode mousemode;
		wchar_t chr;
		ffw::Key key;
		ffw::Mode keymode;
	};
	/**
	 * @ingroup gui
	 */
	class FFW_API GuiWidget {
	public:
		enum class Orientation {
			FIXED,
			VERTICAL,
			HORIZONTAL
		};
		enum class Focus {
			DEFAULT = 0,
			STICKY,
			DROP,
			TOGGLE,
		};
		struct Flags {
			bool hover;
			bool focus;
			bool disabled;
			bool hidden;
			bool wrap;
			bool render;
			bool invalidate;
			//bool stickyFocus;
			//bool dropFocus;
			//bool toggleFocus;
			Focus focusType;
			bool ignore;
			bool rearrange;
			bool first;

			struct Events {
				bool pos;
				bool size;
				bool inner;
				bool disabled;
				bool focus;
				bool hover;
			} events;
		};
		GuiWidget(GuiWindow* context);
		GuiWidget(const GuiWidget& other) = delete;
		GuiWidget(GuiWidget&& other);
		void swap(GuiWidget& other);
		virtual ~GuiWidget();
		inline void setSize(GuiUnits width, GuiUnits height) {
			setSize(ffw::Vec2<GuiUnits>(width, height));
		}
		void setSize(const ffw::Vec2<GuiUnits>& s);
		void setPos(GuiUnits posx, GuiUnits posy);
		const ffw::Vec2<GuiUnits>& getPos() const;
		const ffw::Vec2<GuiUnits>& getSize() const;
		ffw::Vec2i getVisibleContentSize() const;
		ffw::Vec2i getVisibleContentPos() const;
		inline ffw::Vec2i getInnerContentSize() const {
			return totalSize;
		}
		inline ffw::Vec2i getInnerContentPos() const {
			return getVisibleContentPos() + offset;
		}
		ffw::Vec2i getAbsolutePos() const;
		void setOffset(const ffw::Vec2i off);
		const ffw::Vec2i& getOffset() const;
		void setPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		inline void setPadding(GuiUnits all) {
			setPadding(all, all, all, all);
		}
		inline void setPadding(const GuiStyle::Padding& pad) {
			setPadding(pad[0], pad[1], pad[2], pad[3]);
		}
		void setMargin(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		inline void setMargin(GuiUnits all) {
			setMargin(all, all, all, all);
		}
		inline void setMargin(const GuiStyle::Margin& mar) {
			setMargin(mar[0], mar[1], mar[2], mar[3]);
		}
		inline const GuiStyle::Padding& getPadding() const {
			return padding;
		}
		inline const GuiStyle::Margin& getMargin() const {
			return margin;
		}
		inline GuiUnits getPadding(int side) const {
			return padding[side];
		}
		inline GuiUnits getMargin(int side) const {
			return margin[side];
		}
		inline void setMarginTop(GuiUnits val) {
			setMargin(val, margin[1], margin[2], margin[3]);
		}
		inline void setMarginRight(GuiUnits val) {
			setMargin(margin[0], val, margin[2], margin[3]);
		}
		inline void setMarginBottom(GuiUnits val) {
			setMargin(margin[0], margin[1], val, margin[3]);
		}
		inline void setMarginLeft(GuiUnits val) {
			setMargin(margin[0], margin[1], margin[2], val);
		}
		inline void setPaddingTop(GuiUnits val) {
			setPadding(val, padding[1], padding[2], padding[3]);
		}
		inline void setPaddingRight(GuiUnits val) {
			setPadding(padding[0], val, padding[2], padding[3]);
		}
		inline void setPaddingBottom(GuiUnits val) {
			setPadding(padding[0], padding[1], val, padding[3]);
		}
		inline void setPaddingLeft(GuiUnits val) {
			setPadding(padding[0], padding[1], padding[2], val);
		}
		int getPaddingInPixels(int side) const;
		int getMarginInPixels(int side) const;
		void setAlign(GuiStyle::Align align);
		GuiStyle::Align getAlign() const;
		void setWrap(bool wrap);
		inline bool getWrap() const {
			return flags.wrap;
		}
		void setID(unsigned long id);
		unsigned long getID() const;
		void update(const ffw::Vec2i& parentpos, const ffw::Vec2i& parentsize, const GuiUserInput& input, ffw::Vec2i mousepos, bool mouseout);
		void render(const ffw::Vec2i& clippos, const ffw::Vec2i& clipsize, const ffw::Vec2i& off, bool clear);
		bool shouldRedraw() const;
		void redraw();
		void invalidate();
		void setParent(GuiWidget* parent);
		const GuiWidget* getParent() const;
		inline bool hasHover() const {
			return flags.hover;
		}
		inline bool hasFocus() const {
			return flags.focus;
		}
		void setFocus(bool f);
		void setHover(bool h);
		void setDisabled(bool d);
		void setHidden(bool h);
		void setIgnoreUserInput(bool d);
		inline void hide() {
			setHidden(true);
		}
		inline void show() {
			setHidden(false);
		}
		inline bool isHidden() const {
			return flags.hidden;
		}
		inline bool isDisabled() const {
			return flags.disabled;
		}
		void setFont(const GuiFont* font);
		const GuiFont* getFont() const;
		const GuiFont* getCurrentFont() const;
		inline const ffw::Vec2i getMousePos() const {
			return mouseOld;
		}
		virtual ffw::Vec2i getMinimumWrapSize() = 0;
		template<class T>
		T* findByID(unsigned long id_){
			if(typeid(*this).hash_code() == typeid(T).hash_code() && id == id_)return dynamic_cast<T*>(this);
			else if(widgets.size() > 0){
				for(auto& w : widgets){
					T* test = w->findByID<T>(id_);
					if(test != NULL)return test;
				}
			}
			return NULL;
		}
		template<class T>
		void addEventCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			eventCallbacks.add(memfuncptr, instance, now);
		}
		void setCallbackPtr(GuiWidget* ptr);
		inline GuiWidget* getCallbackPtr() const {
			return callbackPtr;
		}
		void setTheme(const GuiTheme* theme);
		void setStyleGroup(const GuiStyleGroup* style);
		inline const GuiStyleGroup* getStyleGroup() {
			return widgetStyle;
		}
		inline const ffw::GuiStyle* getCurrentStyle() const {
			return getCurrentStyle(widgetStyle);
		}
		const ffw::GuiStyle* getCurrentStyle(const GuiStyleGroup* group) const;
		inline const ffw::Vec2i& getRealSize() const {
			return sizeReal;
		}
		inline ffw::Vec2i getRealSizeWithMargin() const {
			return ffw::Vec2i(
				sizeReal.x + getMarginInPixels(1) + getMarginInPixels(3),
				sizeReal.y + getMarginInPixels(0) + getMarginInPixels(2)
			);
		}
		inline const ffw::Vec2i& getRealPos() const {
			return posReal;
		}
		inline void setLineHeight(float height) {
			lineHeight = height;
			redraw();
		}
		inline float getLineHeight() const {
			return lineHeight;
		}
		inline void setDefaults(const ffw::GuiDefaults* def) {
			if (def != NULL) {
				size.set(def->size.x, def->size.y);
				padding = def->padding;
				margin = def->margin;
				align = def->align;
			}
		}
		inline GuiWindow* getWindow() {
			return context;
		}
		inline const GuiWindow* getWindow() const  {
			return context;
		}
		GuiWidget& operator = (const GuiWidget& other) = delete;
		GuiWidget& operator = (GuiWidget&& other);
	protected:
		void traverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size);
		GuiWidget* addWidgetInternal(GuiWidget* widget);
		GuiWidget* addWidgetAfterInternal(const GuiWidget* previous, GuiWidget* widget);
		GuiWidget* addWidgetBeforeInternal(const GuiWidget* next, GuiWidget* widget);
		void deleteWidgetsInternal();
		bool deleteSingleWidgetInternal(const GuiWidget* widget);
		void setOrientation(Orientation orientation);
		void pushEvent(GuiEvent::Type type, GuiEvent::Data data);
		inline const std::vector<GuiWidget*>& getAllWidgets() const {
			return widgets;
		}
		void recalculatePos();
		void recalculateSize(GuiWidget* ptr = NULL);
		void renderComponent(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle* group);
		virtual void eventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) = 0;
		virtual void eventPos(const ffw::Vec2i& pos) = 0;
		virtual void eventSize(const ffw::Vec2i& size) = 0;
		virtual void eventHover(bool gained) = 0;
		virtual void eventFocus(bool gained) = 0;
		virtual void eventMouse(const ffw::Vec2i& pos) = 0;
		virtual void eventMouseButton(ffw::MouseButton button, ffw::Mode mode) = 0;
		virtual void eventText(wchar_t chr) = 0;
		virtual void eventKey(ffw::Key key, ffw::Mode mode) = 0;
		virtual void eventDisabled(bool disabled) = 0;
		virtual void eventThemeChanged(const GuiTheme* theme) = 0;
		GuiWindow* context;
		const GuiStyleGroup* widgetStyle;
		inline void setToggleFocus() {
			flags.focusType = GuiWidget::Focus::TOGGLE;
		}
		inline void setStickyFocus() {
			flags.focusType = GuiWidget::Focus::STICKY;
		}
		inline void setDropFocus() {
			flags.focusType = GuiWidget::Focus::DROP;
		}
		inline void setDefaultFocus() {
			flags.focusType = GuiWidget::Focus::DEFAULT;
		}
		inline const Flags& getFlags() const {
			return flags;
		}
	private:
		void checkEvents();
		void arrangeWidgetsVertical(GuiWidget* ptr = NULL);
		void arrangeWidgetsHorizontal(GuiWidget* ptr = NULL);
		void arrangeWidgetsFixed(GuiWidget* ptr = NULL);
		ffw::Vec2i sizeReal;
		ffw::Vec2i posReal;
		ffw::GuiUnits2D size;
		ffw::GuiUnits2D pos;
		ffw::Vec2i mouseOld;
		ffw::Vec2i offset;
		ffw::Vec2i totalSize;
		Orientation orientation;
		GuiStyle::Align align;
		std::vector<GuiWidget*> widgets;
		GuiStyle::Margin margin;
		GuiStyle::Padding padding;
		float lineHeight;
		const GuiFont* widgetfont;
		unsigned long id;
		GuiWidget* callbackPtr;
		GuiWidget* parent;
		GuiCallback eventCallbacks;

		Flags flags;
	};
}
#endif
