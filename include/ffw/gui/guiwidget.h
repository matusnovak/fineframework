/* This file is part of FineFramework project */
#ifndef FFW_GUI_WIDGET
#define FFW_GUI_WIDGET
#include "../config.h"
#include "../math.h"
#include "guifont.h"
#include <typeinfo>

namespace ffw {
	class GuiWindow;
	class GuiWidget;
	enum class GuiEventType {
		CLICKED = 0,
		SELECTED,
	};
	class GuiEvent {
	public:
		GuiWidget* widget;
		GuiEventType type;
	};
	enum class GuiAlign {
		LEFT = 0,
		CENTER,
		RIGHT,
		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,
		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT,
	};
	class GuiUserInput {
	public:
		ffw::Vec2i mousepos;
		ffw::MouseButton mousebtn;
		ffw::Mode mousemode;
		wchar_t chr;
		ffw::Key key;
		ffw::Mode keymode;
	};
	class GuiUnits {
	public:
		static GuiUnits Pixels(int Px){
			return GuiUnits(Px, false);
		}
		static GuiUnits Percent(int Pe){
			return GuiUnits(Pe, true);
		}
		static GuiUnits Wrap(){
			return GuiUnits(-1, true);
		}
		GuiUnits():value(0),inPercent(0){}
		GuiUnits(int Value, bool InPercent):value(Value),inPercent(InPercent){}
		GuiUnits(int Value):value(Value),inPercent(false){}
		bool operator == (const GuiUnits& Other) const {
			return (value == Other.value && inPercent == Other.inPercent);
		}
		int value;
		bool inPercent;
		inline friend std::ostream& operator << (std::ostream& os, const GuiUnits& V){
			os << V.value << (V.inPercent ? "%" : "px");
			return os;
		}
	};
	class GuiStyle {
	public:
		GuiStyle(){
			border[0] = border[1] = border[2] = border[3] = false;
			bordersize[0] = bordersize[1] = bordersize[2] = bordersize[3] = 1;
			bordercolor[0] = bordercolor[1] = bordercolor[2] = bordercolor[3] = ffw::Rgb(0xFFFFFF);
			borderradius[0] = borderradius[1] = borderradius[2] = borderradius[3] = 0;
			background = false;
			backgroundcolor = ffw::Rgb(0xFFFFFF);
			textcolor = ffw::Rgb(0xFFFFFF);
		}
		template <class T>
		struct StyleStruct {
			inline StyleStruct(){
			}
			inline StyleStruct(const StyleStruct& other){
				val[0] = other.val[0];
				val[1] = other.val[1];
				val[2] = other.val[2];
				val[3] = other.val[3];
			}
			inline StyleStruct& operator = (T value){
				val[0] = val[1] = val[2] = val[3] = value;
				return *this;
			}
			inline T& operator [] (int i){
				return val[i];
			}
			inline const T& operator [] (int i) const {
				return val[i];
			}
			inline bool operator == (const StyleStruct& other) const {
				return (val[0] == other.val[0] && val[1] == other.val[1] && val[2] == other.val[2] && val[3] == other.val[3]);
			}
			T val[4];
		};
		typedef StyleStruct<bool> BorderStruct;
		typedef StyleStruct<int> BorderSizeStruct;
		typedef StyleStruct<ffw::Color> BorderColorStruct;
		typedef StyleStruct<int> BorderRadiusStruct;
		BorderStruct border;
		BorderSizeStruct bordersize;
		BorderColorStruct bordercolor;
		BorderRadiusStruct borderradius;
		bool background;
		ffw::Color backgroundcolor;
		ffw::Color textcolor;
	};
	class GuiStyleGroup {
	public:
		GuiStyle normal;
		GuiStyle hover;
		GuiStyle active;
	};
	class FFW_API GuiWidget {
	public:
		enum class Orientation {
			FIXED,
			VERTICAL,
			HORIZONTAL
		};
		GuiWidget(GuiWindow* context);
		virtual ~GuiWidget();
		void SetSize(GuiUnits width, GuiUnits height);
		void SetPos(GuiUnits posx, GuiUnits posy);
		const ffw::Vec2<GuiUnits>& GetPos() const;
		const ffw::Vec2<GuiUnits>& GetSize() const;
		const ffw::Vec2i& GetRealSize() const;
		const ffw::Vec2i& GetRealPos() const;
		const ffw::Vec2i GetVisibleContentSize() const;
		const ffw::Vec2i GetVisibleContentPos() const;
		inline const ffw::Vec2i GetContentSize() const {
			return totalsize;
		}
		inline const ffw::Vec2i GetContentPos() const {
			return GetVisibleContentPos() + offset;
		}
		inline const ffw::Vec2i GetAbsolutePos() const {
			// TOOD
			return 0;
		}
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
		void SetID(unsigned long id);
		unsigned long GetID() const;
		void Update(const GuiUserInput& input);
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
		void SetFont(const GuiFont* font);
		const GuiFont* GetFont() const;
		const GuiFont* GetCurrentFont() const;
		inline const ffw::Vec2i GetMousePos() const {
			return mouseold;
		}
		GuiStyleGroup style;
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
	protected:
		void AddWidget(GuiWidget* widget);
		void DeleteWidgets();
		void SetOrientation(Orientation orientation);
		virtual void EventRender(const ffw::Vec2i& contentoffset, const ffw::Vec2i& contentsize) = 0;
		virtual void EventPos(const ffw::Vec2i& pos) = 0;
		virtual void EventSize(const ffw::Vec2i& size) = 0;
		virtual void EventHover(bool gained) = 0;
		virtual void EventFocus(bool gained) = 0;
		virtual void EventMouse(const ffw::Vec2i& pos) = 0;
		virtual void EventMouseButton(ffw::MouseButton button, ffw::Mode mode) = 0;
		virtual void EventText(wchar_t chr) = 0;
		virtual void EventKey(ffw::Key key, ffw::Mode mode) = 0;
		GuiWindow* context;
		inline GuiStyle& GetCurrentStyle(){
			return GetCurrentStyle(style);
		}
		inline const GuiStyle& GetCurrentStyle() const {
			return GetCurrentStyle(style);
		}
		GuiStyle& GetCurrentStyle(GuiStyleGroup& group);
		const GuiStyle& GetCurrentStyle(const GuiStyleGroup& group) const;
		bool dropfocusflag;
		bool ignoreinputflag;
		bool togglefocusflag;
		bool stickyfocusflag;
	private:
		void TraverseBackground(const ffw::Vec2i& pos, const ffw::Vec2i& size);
		void RecalculatePos();
		void RecalculateSize();
		GuiWidget* parent;
		ffw::Vec2i sizereal;
		ffw::Vec2i posreal;
		ffw::Vec2<GuiUnits> size;
		ffw::Vec2<GuiUnits> pos;
		ffw::Vec2i mouseold;
		ffw::Vec2i offset;
		ffw::Vec2i totalsize;
		Orientation orientation;
		std::vector<GuiWidget*> widgets;
		GuiUnits margin[4];
		GuiUnits padding[4];
		bool updateflag;
		bool calleventsize;
		bool calleventpos;
		bool invalidateflag;
		bool hoverflag;
		bool focusflag;
		bool first;
		const GuiFont* widgetfont;
		GuiAlign align;
		unsigned long id;
	};
}
#endif
