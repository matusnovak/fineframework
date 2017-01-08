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
			POSITION,
			HOVER,
			FOCUS,
			STATE,
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
		};
		GuiWidget* widget;
		Type type;
		Data data;
	};
	class GuiCallback {
	public:
		class Data {
		public:
			std::function<void(GuiEvent)> func = nullptr;
			bool now = false;
		};
		template<class T>
		void Add(void (T::*memfuncptr)(GuiEvent), T* instance, bool instant) {
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
		ffw::Vec2i mousepos;
		ffw::MouseButton mousebtn;
		ffw::Mode mousemode;
		wchar_t chr;
		ffw::Key key;
		ffw::Mode keymode;
		bool mouseout;
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
		GuiWidget(GuiWindow* context);
		virtual ~GuiWidget();
		inline void SetSize(GuiUnits width, GuiUnits height) {
			SetSize(ffw::Vec2<GuiUnits>(width, height));
		}
		void SetSize(const ffw::Vec2<GuiUnits>& s);
		void SetPos(GuiUnits posx, GuiUnits posy);
		const ffw::Vec2<GuiUnits>& GetPos() const;
		const ffw::Vec2<GuiUnits>& GetSize() const;
		ffw::Vec2i GetVisibleContentSize() const;
		ffw::Vec2i GetVisibleContentPos() const;
		ffw::Vec2i GetTotalContentSize() const;
		ffw::Vec2i GetTotalContentPos() const;
		ffw::Vec2i GetAbsolutePos() const;
		void SetOffset(const ffw::Vec2i off);
		const ffw::Vec2i& GetOffset() const;
		void SetPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		void SetPadding(GuiUnits all);
		inline void SetPadding(const GuiStyle::Padding& pad) {
			SetPadding(pad[0], pad[1], pad[2], pad[3]);
		}
		void SetMargin(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		void SetMargin(GuiUnits all);
		inline void SetMargin(const GuiStyle::Margin& mar) {
			SetMargin(mar[0], mar[1], mar[2], mar[3]);
		}
		GuiUnits GetPadding(int side) const;
		GuiUnits GetMargin(int side) const;
		int GetPaddingInPixels(int side) const;
		int GetMarginInPixels(int side) const;
		void SetAlign(GuiStyle::Align align);
		GuiStyle::Align GetAlign() const;
		void SetWrap(bool wrap);
		inline bool GetWrap() const {
			return wrapWidgets;
		}
		void SetID(unsigned long id);
		unsigned long GetID() const;
		void Update(const ffw::Vec2i& parentpos, const ffw::Vec2i& parentsize, const GuiUserInput& input);
		void Render(const ffw::Vec2i& clippos, const ffw::Vec2i& clipsize, const ffw::Vec2i& off, bool clear);
		bool ShouldRedraw() const;
		void Redraw();
		void Invalidate();
		void SetParent(GuiWidget* parent);
		const GuiWidget* GetParent() const;
		bool HasHover() const;
		bool HasFocus() const;
		void SetFocus(bool f);
		void SetHover(bool h);
		void SetDisabled(bool d);
		void SetHidden(bool h);
		void SetIgnoreUserInput(bool d);
		void Hide();
		void Show();
		bool IsHidden() const;
		void SetFont(const GuiFont* font);
		const GuiFont* GetFont() const;
		const GuiFont* GetCurrentFont() const;
		inline const ffw::Vec2i GetMousePos() const {
			return mouseold;
		}
		virtual ffw::Vec2i GetMinimumWrapSize() const = 0;
		template<class T>
		T* FindByID(unsigned long id_){
			if(typeid(*this).hash_code() == typeid(T).hash_code() && id == id_)return dynamic_cast<T*>(this);
			else if(widgets.size() > 0){
				for(auto& w : widgets){
					T* test = w->FindByID<T>(id_);
					if(test != NULL)return test;
				}
			}
			return NULL;
		}
		template<class T>
		void AddEventCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			eventCallbacks.Add(memfuncptr, instance, now);
		}
		void SetCallbackPtr(GuiWidget* ptr);
		inline GuiWidget* GetCallbackPtr() const {
			return callbackPtr;
		}
		void SetTheme(const GuiTheme* theme);
		void SetStyleGroup(const GuiStyleGroup* style);
		inline const GuiStyleGroup* GetStyleGroup() {
			return widgetStyle;
		}
		inline const ffw::GuiStyle* GetCurrentStyle() const {
			return GetCurrentStyle(widgetStyle);
		}
		const ffw::GuiStyle* GetCurrentStyle(const GuiStyleGroup* group) const;
		inline const ffw::Vec2i& GetRealSize() const {
			return sizereal;
		}
		inline ffw::Vec2i GetRealSizeWithMargin() const {
			return ffw::Vec2i(
				sizereal.x + GetMarginInPixels(1) + GetMarginInPixels(3),
				sizereal.y + GetMarginInPixels(0) + GetMarginInPixels(2)
			);
		}
		inline const ffw::Vec2i& GetRealPos() const {
			return posreal;
		}
		inline void SetDefaults(const ffw::GuiDefaults* def) {
			if (def != NULL) {
				size = def->size;
				padding = def->padding;
				margin = def->margin;
				align = def->align;
			}
		}
	protected:
		void TraverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size);
		void AddWidget(GuiWidget* widget);
		void AddWidgetAfter(const GuiWidget* previous, GuiWidget* widget);
		void AddWidgetBefore(const GuiWidget* next, GuiWidget* widget);
		void DeleteWidgets();
		bool DeleteSingleWidget(GuiWidget* widget);
		void SetOrientation(Orientation orientation);
		void PushEvent(GuiEvent::Type type, GuiEvent::Data data);
		void RecalculatePos();
		void RecalculateSize();
		void RenderComponent(const ffw::Vec2i& pos, const ffw::Vec2i& size, const ffw::GuiStyle* group);
		virtual void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) = 0;
		virtual void EventPos(const ffw::Vec2i& pos) = 0;
		virtual void EventSize(const ffw::Vec2i& size) = 0;
		virtual void EventHover(bool gained) = 0;
		virtual void EventFocus(bool gained) = 0;
		virtual void EventMouse(const ffw::Vec2i& pos) = 0;
		virtual void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) = 0;
		virtual void EventText(wchar_t chr) = 0;
		virtual void EventKey(ffw::Key key, ffw::Mode mode) = 0;
		virtual void EventDisabled(bool disabled) = 0;
		virtual void EventThemeChanged(const GuiTheme* theme) = 0;
		bool dropfocusflag;
		bool ignoreinputflag;
		bool togglefocusflag;
		bool stickyfocusflag;
		GuiWindow* context;
		ffw::Vec2i sizereal;
		ffw::Vec2i posreal;
		bool hoverflag;
		bool focusflag;
		bool disableflag;
		const GuiStyleGroup* widgetStyle;
		GuiWidget* callbackPtr;
		GuiWidget* parent;
		GuiCallback eventCallbacks;
	private:
		ffw::Vec2<GuiUnits> size;
		ffw::Vec2<GuiUnits> pos;
		ffw::Vec2i mouseold;
		ffw::Vec2i offset;
		ffw::Vec2i totalsize;
		Orientation orientation;
		std::vector<GuiWidget*> widgets;
		GuiStyle::Margin margin;
		GuiStyle::Padding padding;
		bool wrapWidgets;
		bool updateflag;
		bool calleventsize;
		bool calleventpos;
		bool calleventdisabled;
		bool calleventfocus;
		bool calleventhover;
		bool invalidateflag;
		bool first;
		bool hidden;
		int shouldhideflag;
		const GuiFont* widgetfont;
		GuiStyle::Align align;
		unsigned long id;
	};
}
#endif
