/* This file is part of FineFramework project */
#ifndef FFW_VEC2
#define FFW_VEC2

namespace ffw {
	/**
	 * @ingroup math
	 */
    template <class T> struct Vec2 {
    public:
        T x;
        T y;

		inline Vec2() {
			x = T(0);
			y = T(0);
		}

		inline Vec2(T compx, T compy) {
			x = compx;
			y = compy;
		}

		inline Vec2(T Value) {
			x = Value;
			y = Value;
		}

		inline Vec2(const Vec2<T>& vec) {
			x = vec.x;
			y = vec.y;
		}

		inline Vec2(std::initializer_list<T> list) {
			if (list.size() != 2) {
				x = T(0);
				y = T(0);
				return;
			}
			x = *(list.begin());
			y = *(list.begin() + 1);
		}

		inline void Set(T compx, T compy) {
			x = compx;
			y = compy;
		}

		inline void Set(T Value) {
			x = Value;
			y = Value;
		}

		inline void Set(const Vec2<T>& vec) {
			x = vec.x;
			y = vec.y;
		}

		inline void Set(const std::initializer_list<T>& list) {
			if (list.size() == 2) {
				x = *(list.begin());
				y = *(list.begin() + 1);
			}
		}

		inline ffw::Vec2<T>  operator - () const {
			return Vec2<T>(-x, -y);
		}

		inline ffw::Vec2<T>& operator =  (const Vec2<T>& vec) {
			x = vec.x;
			y = vec.y;
			return *this;
		}

		inline ffw::Vec2<T>  operator +  (const Vec2<T>& vec) const {
			return Vec2<T>(x + vec.x, y + vec.y);
		}

		inline ffw::Vec2<T>& operator += (const Vec2<T>& vec) {
			x += vec.x;
			y += vec.y;
			return *this;
		}

		inline ffw::Vec2<T>  operator -  (const Vec2<T>& vec) const {
			return Vec2<T>(x - vec.x, y - vec.y);
		}

		inline ffw::Vec2<T>& operator -= (const Vec2<T>& vec) {
			x -= vec.x;
			y -= vec.y;
			return *this;
		}

		inline ffw::Vec2<T>  operator /  (const Vec2<T>& vec) const {
			return Vec2<T>(x / vec.x, y / vec.y);
		}

		inline ffw::Vec2<T>& operator /= (const Vec2<T>& vec) {
			x /= vec.x;
			y /= vec.y;
			return *this;
		}

		inline ffw::Vec2<T>  operator *  (const Vec2<T>& vec) const {
			return Vec2<T>(x * vec.x, y * vec.y);
		}

		inline ffw::Vec2<T>& operator *= (const Vec2<T>& vec) {
			x *= vec.x;
			y *= vec.y;
			return *this;
		}

		inline ffw::Vec2<T>& operator =  (const T& val) {
			x = val;
			y = val;
			return *this;
		}

		inline ffw::Vec2<T>  operator +  (const T& val) const {
			return Vec2<T>(x + val, y + val);
		}

		inline ffw::Vec2<T>& operator += (const T& val) {
			x += val;
			y += val;
			return *this;
		}

		inline ffw::Vec2<T>  operator -  (const T& val) const {
			return Vec2<T>(x - val, y - val);
		}

		inline ffw::Vec2<T>& operator -= (const T& val) {
			x -= val;
			y -= val;
			return *this;
		}

		inline ffw::Vec2<T>  operator /  (const T& val) const {
			return Vec2<T>(x / val, y / val);
		}

		inline ffw::Vec2<T>& operator /= (const T& val) {
			x /= val;
			y /= val;
			return *this;
		}

		inline ffw::Vec2<T>  operator *  (const T& val) const {
			return Vec2<T>(x * val, y * val);
		}

		inline ffw::Vec2<T>& operator *= (const T& val) {
			x *= val;
			y *= val;
			return *this;
		}

		inline bool operator != (const Vec2<T>& vec) const {
			return !(*this == vec);
		}

		inline bool operator == (const Vec2<T>& vec) const {
			return (x == vec.x && y == vec.y);
		}

		inline ffw::Vec2<T>& Rotate(double deg) {
			auto v = *this;
			x = static_cast<T>(cos(deg*DEG_TO_RAD))*v.x - static_cast<T>(sin(deg*DEG_TO_RAD))*v.y;
			y = static_cast<T>(sin(deg*DEG_TO_RAD))*v.x + static_cast<T>(cos(deg*DEG_TO_RAD))*v.y;
			return *this;
		}

		inline ffw::Vec2<T>& RotateRad(double rad) {
			auto v = *this;
			x = static_cast<T>(cos(rad))*v.x - static_cast<T>(sin(rad))*v.y;
			y = static_cast<T>(sin(rad))*v.x + static_cast<T>(cos(rad))*v.y;
			return *this;
		}

		inline ffw::Vec2<T>& Normalize() {
			double l = sqrtf(x*x + y*y);
			if (l > 0) {
				x = T(x / l);
				y = T(y / l);
			}
			return *this;
		}

		inline ffw::Vec2<T>& Scale(T val) {
			x = x*val;
			y = y*val;
			return *this;
		}

		inline double Length() const {
			return sqrt(static_cast<double>(x*x + y*y));
		}

		inline float Lengthf() const {
			return sqrtf(static_cast<float>(x*x + y*y));
		}

		inline T LengthSqrd() const {
			return (x*x + y*y);
		}

		template <class S>
		inline operator ffw::Vec2<S>() const {
			return ffw::Vec2<S>((S)x, (S)y);
		}
    };
	/**
	 * @ingroup math
	 */
    typedef Vec2<float> Vec2f;
	/**
	 * @ingroup math
	 */
    typedef Vec2<int> Vec2i;
	/**
	* @ingroup math
	*/
	typedef Vec2<short> Vec2s;
	/**
	* @ingroup math
	*/
	typedef Vec2<long long> Vec2ll;
	/**
	 * @ingroup math
	 */
    typedef Vec2<double> Vec2d;
};

namespace ffw {
    template<>
	inline bool ffw::Vec2<float>::operator == (const Vec2<float>& vec) const {
		if (fabs(x - vec.x) > std::numeric_limits<float>::epsilon())return false;
		if (fabs(y - vec.y) > std::numeric_limits<float>::epsilon())return false;
		return true;
	}
    template<>
	inline bool ffw::Vec2<double>::operator == (const Vec2<double>& vec) const {
		if (fabs(x - vec.x) > std::numeric_limits<double>::epsilon())return false;
		if (fabs(y - vec.y) > std::numeric_limits<double>::epsilon())return false;
		return true;
	}
}

#endif
