/* This file is part of FineFramework project */
#ifndef FFW_GUI_THEME
#define FFW_GUI_THEME
#include "../config.h"
#include "../math.h"
namespace ffw {
	/**
	* @ingroup gui
	*/
	class GuiUnits {
	public:
		GuiUnits() :value(0), inPercent(0) {}
		GuiUnits(int Value, bool InPercent) :value(Value), inPercent(InPercent) {}
		GuiUnits(int Value) :value(Value), inPercent(false) {}
		inline bool operator == (const GuiUnits& other) const {
			return (value == other.value && inPercent == other.inPercent);
		}
		inline bool operator == (int v) const {
			return (value == v && inPercent == false);
		}
		int value;
		bool inPercent;
		inline friend std::ostream& operator << (std::ostream& os, const GuiUnits& V) {
			os << V.value << (V.inPercent ? "%" : "px");
			return os;
		}
		inline int ToReal(const int val) const {
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
		enum class Align {
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
			inline friend std::ostream& operator << (std::ostream& os, const Attribute& a) {
				os << a.val[0] << ", " << a.val[1] << ", " << a.val[2] << ", " << a.val[3] << std::endl;
				return os;
			}
		};
		class Border {
		public:
			typedef Attribute<int> Size;
			typedef Attribute<int> Radius;
			typedef Attribute<ffw::Color> Color;
			inline Border():
				size(0),radius(0),color(ffw::Rgb(0xFFFFFF)) {
			}
			inline Border(const Attribute<int>& s, const Attribute<int>& r, const Attribute<ffw::Color>& c):
				size(s),radius(r),color(c) {
			}
			inline operator bool() const {
				return (size[0] > 0 || size[1] > 0 || size[2] > 0 || size[3] > 0);
			}
			Size size;
			Radius radius;
			Color color;
		};

		typedef Border Outline;
		typedef GuiStyle::Attribute<GuiUnits> Padding;
		typedef GuiStyle::Attribute<GuiUnits> Margin;

		class Background {
		public:
			typedef Attribute<int> Radius;
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

	inline GuiStyle::Background GuiSimpleBackground(const ffw::Color& color) {
		return GuiStyle::Background(0, color, ffw::Rgb(0x000000), GuiStyle::Background::Type::SIMPLE);
	}
	inline GuiStyle::Background GuiVGradientBackground(const ffw::Color& top, const ffw::Color& bottom) {
		return GuiStyle::Background(0, top, bottom, GuiStyle::Background::Type::VGRADIENT);
	}
	inline GuiStyle::Background GuiHGradientBackground(const ffw::Color& left, const ffw::Color& right) {
		return GuiStyle::Background(0, left, right, GuiStyle::Background::Type::HGRADIENT);
	}
	inline GuiStyle::Background GuiNoBackground() {
		return GuiStyle::Background(0, ffw::Rgb(0x000000), ffw::Rgb(0x000000), GuiStyle::Background::Type::NONE);
	}

	class GuiDefaults {
	public:
		inline GuiDefaults() :
			margin(0), padding(0), align(GuiStyle::Align::TOP_LEFT), size(ffw::Vec2<GuiUnits>(GuiPercent(100), GuiWrap())) {
		}
		inline GuiDefaults(const GuiStyle::Margin& m, const GuiStyle::Padding& p, GuiStyle::Align a, const ffw::Vec2<GuiUnits>& s):
			margin(m),padding(p),align(a),size(s){
		}
		GuiStyle::Margin margin;
		GuiStyle::Padding padding;
		GuiStyle::Align align;
		ffw::Vec2<GuiUnits> size;
	};

	class GuiStyleGroup {
	public:
		inline GuiStyleGroup() {
			
		}
		inline GuiStyleGroup(const GuiStyle& n, const GuiStyle& h, const GuiStyle& a, const GuiStyle& d, const GuiDefaults& def = GuiDefaults()):
			normal(n),hover(h),active(a),disabled(d),defaults(def) {
		}
		GuiStyle normal;
		GuiStyle hover;
		GuiStyle active;
		GuiStyle disabled;
		GuiDefaults defaults;
	};

	class FFW_API GuiTheme {
	public:
		static const GuiTheme Windows;

		GuiTheme(const std::initializer_list<std::pair<std::string, GuiStyleGroup>>& list);
		virtual ~GuiTheme();
		void Add(const std::pair<std::string, GuiStyleGroup>& sty);
		const GuiStyleGroup& GetStyleGroup(const std::string& type) const;
		GuiStyleGroup& GetStyleGroup(const std::string& type);
	private:
		std::map<std::string, GuiStyleGroup> styles;
	};
};
#endif