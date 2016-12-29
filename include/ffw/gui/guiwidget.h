/* This file is part of FineFramework project */
#ifndef FFW_GUI_WIDGET
#define FFW_GUI_WIDGET
#include "guirenderable.h"
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
	class FFW_API GuiWidget: public GuiRenderable {
	public:
		enum class Orientation {
			FIXED,
			VERTICAL,
			HORIZONTAL
		};
		GuiWidget(GuiWindow* context, const std::type_info& type);
		virtual ~GuiWidget();
		void SetSize(GuiUnits width, GuiUnits height);
		void SetPos(GuiUnits posx, GuiUnits posy);
		const ffw::Vec2<GuiUnits>& GetPos() const;
		const ffw::Vec2<GuiUnits>& GetSize() const;
		ffw::Vec2i GetVisibleContentSize() const;
		ffw::Vec2i GetVisibleContentPos() const;
		ffw::Vec2i GetContentSize() const;
		ffw::Vec2i GetContentPos() const;
		ffw::Vec2i GetAbsolutePos() const;
		void SetOffset(const ffw::Vec2i off);
		const ffw::Vec2i& GetOffset() const;
		void SetPadding(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		void SetPadding(GuiUnits all);
		void SetMargin(GuiUnits top, GuiUnits right, GuiUnits bottom, GuiUnits left);
		void SetMargin(GuiUnits all);
		GuiUnits GetPadding(int side) const;
		GuiUnits GetMargin(int side) const;
		int GetPaddingInPixels(int side) const;
		int GetMarginInPixels(int side) const;
		void SetAlign(GuiAlign align);
		GuiAlign GetAlign() const;
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
		void SetFocus();
		void ResetFocus();
		void SetHidden(bool h);
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
		void AddOnSizeEventCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			onsizeeventcallback.Add(memfuncptr, instance, now);
		}
		template<class T>
		void AddOnPosEventCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			onsizeeventcallback.Add(memfuncptr, instance, now);
		}
		template<class T>
		void AddOnHoverEventCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			onsizeeventcallback.Add(memfuncptr, instance, now);
		}
		template<class T>
		void AddOnFocusEventCallback(void (T::*memfuncptr)(GuiEvent), T* instance, bool now = false){
			onsizeeventcallback.Add(memfuncptr, instance, now);
		}
		void SetCallbackPtr(GuiWidget* ptr);
		GuiWidget* GetCallbackPtr() const;
	protected:
		void TraverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size);
		void AddWidget(GuiWidget* widget);
		void AddWidgetAfter(const GuiWidget* previous, GuiWidget* widget);
		void AddWidgetBefore(const GuiWidget* next, GuiWidget* widget);
		void DeleteWidgets();
		bool DeleteSingleWidget(GuiWidget* widget);
		void SetOrientation(Orientation orientation);
		void RecalculatePos();
		void RecalculateSize();
		virtual void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) = 0;
		virtual void EventPos(const ffw::Vec2i& pos) = 0;
		virtual void EventSize(const ffw::Vec2i& size) = 0;
		virtual void EventHover(bool gained) = 0;
		virtual void EventFocus(bool gained) = 0;
		virtual void EventMouse(const ffw::Vec2i& pos) = 0;
		virtual void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) = 0;
		virtual void EventText(wchar_t chr) = 0;
		virtual void EventKey(ffw::Key key, ffw::Mode mode) = 0;
		bool dropfocusflag;
		bool ignoreinputflag;
		bool togglefocusflag;
		bool stickyfocusflag;
	private:
		ffw::Vec2<GuiUnits> size;
		ffw::Vec2<GuiUnits> pos;
		ffw::Vec2i mouseold;
		ffw::Vec2i offset;
		ffw::Vec2i totalsize;
		Orientation orientation;
		std::vector<GuiWidget*> widgets;
		GuiUnits margin[4];
		GuiUnits padding[4];
		bool wrapWidgets;
		bool updateflag;
		bool calleventsize;
		bool calleventpos;
		bool invalidateflag;
		bool first;
		bool hidden;
		int shouldhideflag;
		const GuiFont* widgetfont;
		GuiAlign align;
		unsigned long id;
		GuiWidget* callbackPtr;
		GuiWidget* parent;
		GuiCallback onsizeeventcallback;
		GuiCallback onposeventcallback;
		GuiCallback onhovereventcallback;
		GuiCallback onfocuseventcallback;
	};
}
#endif
