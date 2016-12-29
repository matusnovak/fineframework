/* This file is part of FineFramework project */
#ifndef FFW_GUI_THEME
#define FFW_GUI_THEME
#include "../config.h"
#include "../math.h"
#include <typeinfo>
namespace ffw {
	/**
	* @ingroup gui
	*/
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
	/**
	* @ingroup gui
	*/
	class GuiUnits {
	public:
		GuiUnits() :value(0), inPercent(0) {}
		GuiUnits(int Value, bool InPercent) :value(Value), inPercent(InPercent) {}
		GuiUnits(int Value) :value(Value), inPercent(false) {}
		inline bool operator == (const GuiUnits& Other) const {
			return (value == Other.value && inPercent == Other.inPercent);
		}
		int value;
		bool inPercent;
		inline friend std::ostream& operator << (std::ostream& os, const GuiUnits& V) {
			os << V.value << (V.inPercent ? "%" : "px");
			return os;
		}
		inline int ToReal(const int val) {
			if (inPercent) {
				return int((value / 100.0) * val);
			}
			else {
				return value;
			}
		}
		inline void SetPixels(int px) {
			inPercent = false;
			value = px;
		}
		inline void SetPercent(int pc) {
			inPercent = true;
			value = pc;
		}
	};
	inline GuiUnits GuiPixels(int Px) {
		return GuiUnits(Px, false);
	}
	inline GuiUnits GuiPercent(int Pe) {
		return GuiUnits(Pe, true);
	}
	inline GuiUnits GuiWrap() {
		return GuiUnits(-1, true);
	}
	class GuiStyle {
	public:
		template <class T>
		class Attribute {
		public:
			inline Attribute() {
				val[0] = T(0);
				val[1] = T(0);
				val[2] = T(0);
				val[3] = T(0);
			}
			inline Attribute(T v) {
				val[0] = v;
				val[1] = v;
				val[2] = v;
				val[3] = v;
			}
			inline Attribute(T top, T right, T bottom, T left) {
				val[0] = top;
				val[1] = right;
				val[2] = bottom;
				val[3] = left;
			}
			inline Attribute(const Attribute& other) {
				val[0] = other.val[0];
				val[1] = other.val[1];
				val[2] = other.val[2];
				val[3] = other.val[3];
			}
			inline Attribute& operator = (const T& value) {
				val[0] = val[1] = val[2] = val[3] = value;
				return *this;
			}
			inline T& operator [] (size_t i) {
				return val[i];
			}
			inline const T& operator [] (size_t i) const {
				return val[i];
			}
			inline bool operator == (const Attribute& other) const {
				return (val[0] == other.val[0] && val[1] == other.val[1] && val[2] == other.val[2] && val[3] == other.val[3]);
			}
			inline bool operator != (const Attribute& other) const {
				return !(*this == other);
			}
			T val[4];
		};
		class Border {
		public:
			inline Border():
				size(0),radius(0),color(ffw::Rgb(0xFFFFFF)) {
			}
			inline Border(const Attribute<int>& s, const Attribute<int>& r, const Attribute<ffw::Color>& c):
				size(s),radius(r),color(c) {
				
			}
			Attribute<int> size;
			Attribute<int> radius;
			Attribute<ffw::Color> color;
		};

		typedef Border Outline;

		class Background {
		public:
			enum class Type {
				NONE = 0,
				SIMPLE,
				HGRADIENT,
				VGRADIENT,
			};
			inline Background Simple(const ffw::Color& c) {
				Background bcg;
				bcg.color = c;
				bcg.type = Background::Type::SIMPLE;
				return bcg;
			}
			inline Background():
				radius(0),color(ffw::Rgb(0x000000)),end(ffw::Rgb(0x000000)),type(Type::NONE) {
			}
			inline Background(const Attribute<int>& r, const ffw::Color& c, const ffw::Color& e, Type t):
				radius(r),color(c),end(e),type(t) {
			}
			Attribute<int> radius;
			ffw::Color color;
			ffw::Color end;
			Type type;
			inline operator bool() const {
				return type != Type::NONE;
			}
		};

		class Text {
		public:
			inline Text():
				color(ffw::Rgb(0xFFFFFF)) {
			}
			inline Text(const ffw::Color& c):
				color(c) {
			}
			ffw::Color color;
		};

		class Function {
		public:
			inline Function() :
				color(ffw::Rgb(0xFFFFFF)) {
			}
			inline Function(const ffw::Color& c):
				color(c) {
			}
			ffw::Color color;
		};
		inline GuiStyle() {
			
		}
		inline GuiStyle(const Background& b, const Border& br, const Outline& ou, const Text& t, const Function& f):
			background(b),border(br),outline(ou),text(t),function(f){
		}

		Background background;
		Border border;
		Outline outline;
		Text text;
		Function function;
	};

	class GuiStyleGroup {
	public:
		inline GuiStyleGroup() {
			
		}
		inline GuiStyleGroup(const GuiStyle& n, const GuiStyle& h, const GuiStyle& a, const GuiStyle& d):
			normal(n),hover(h),active(a),disabled(d) {
		}
		GuiStyle normal;
		GuiStyle hover;
		GuiStyle active;
		GuiStyle disabled;
	};

	class FFW_API GuiTheme {
	public:
		static GuiTheme Windows;

		GuiTheme(const std::initializer_list<std::pair<size_t, GuiStyleGroup>>& list);
		virtual ~GuiTheme();

		template<class T>
		inline const GuiStyleGroup& GetByWidget() const  {
			const auto& type = typeid(T);
			return GetByType(type);
		}

		template<class T>
		inline GuiStyleGroup& GetByWidget() {
			const auto& type = typeid(T);
			return GetByType(type);
		}

		void Add(const std::pair<size_t, GuiStyleGroup>& sty);
		const GuiStyleGroup& GetByType(const std::type_info& type) const;
		GuiStyleGroup& GetByType(const std::type_info& type);
	private:
		std::map<size_t, GuiStyleGroup> styles;
	};
};
#endif