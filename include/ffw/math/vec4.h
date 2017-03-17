/* This file is part of FineFramework project */
#ifndef FFW_VEC4
#define FFW_VEC4

namespace ffw {
	/**
	 * @ingroup math
	 */
    template <class T> struct Vec4 {
    public:
        T x;
        T y;
        T z;
        T w;

		inline Vec4() {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		inline Vec4(T compx, T compy, T compz, T compw) {
			x = compx;
			y = compy;
			z = compz;
			w = compw;
		}

		inline Vec4(T val) {
			x = val;
			y = val;
			z = val;
			w = val;
		}

		inline Vec4(const Vec4<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
		}

		inline Vec4(const std::initializer_list<T>& list) {
			if (list.size() != 4) {
				x = 0;
				y = 0;
				z = 0;
				w = 0;
				return;
			}
			x = *(list.begin());
			y = *(list.begin() + 1);
			z = *(list.begin() + 2);
			w = *(list.begin() + 3);
		}

		inline void set(T compx, T compy, T compz, T compw) {
			x = compx;
			y = compy;
			z = compz;
			w = compw;
		}

		inline void set(T val) {
			x = val;
			y = val;
			z = val;
			w = val;
		}

		inline void set(const Vec4<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
		}

		inline void set(const std::initializer_list<T>& list) {
			if (list.size() != 4)return;
			x = *(list.begin());
			y = *(list.begin() + 1);
			z = *(list.begin() + 2);
			w = *(list.begin() + 3);
		}

		inline ffw::Vec4<T>  operator - () const {
			return Vec4<T>(-x, -y, -z, -w);
		}

		inline ffw::Vec4<T>& operator =  (const Vec4<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
			return *this;
		}

		inline ffw::Vec4<T>  operator +  (const Vec4<T>& vec) const {
			return Vec4<T>(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
		}

		inline ffw::Vec4<T>& operator += (const Vec4<T>& vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			w += vec.w;
			return *this;
		}

		inline ffw::Vec4<T>  operator -  (const Vec4<T>& vec) const {
			return Vec4<T>(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
		}

		inline ffw::Vec4<T>& operator -= (const Vec4<T>& vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			w -= vec.w;
			return *this;
		}

		inline ffw::Vec4<T>  operator /  (const Vec4<T>& vec) const {
			return Vec4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
		}

		inline ffw::Vec4<T>& operator /= (const Vec4<T>& vec) {
			x /= vec.x;
			y /= vec.y;
			z /= vec.z;
			w /= vec.w;
			return *this;
		}

		inline ffw::Vec4<T>  operator *  (const Vec4<T>& vec) const {
			return Vec4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
		}

		inline ffw::Vec4<T>& operator *= (const Vec4<T>& vec) {
			x *= vec.x;
			y *= vec.y;
			z *= vec.z;
			w *= vec.w;
			return *this;
		}

		inline ffw::Vec4<T>& operator =  (const T& val) {
			x = val;
			y = val;
			z = val;
			w = val;
			return *this;
		}

		inline ffw::Vec4<T>  operator +  (const T& val) const {
			return Vec4<T>(x + val, y + val, z + val, w + val);
		}

		inline ffw::Vec4<T>& operator += (const T& val) {
			x += val;
			y += val;
			z += val;
			w += val;
			return *this;
		}

		inline ffw::Vec4<T>  operator -  (const T& val) const {
			return Vec4<T>(x - val, y - val, z - val, w - val);
		}

		inline ffw::Vec4<T>& operator -= (const T& val) {
			x -= val;
			y -= val;
			z -= val;
			w -= val;
			return *this;
		}

		inline ffw::Vec4<T>  operator /  (const T& val) const {
			return Vec4<T>(x / val, y / val, z / val, w / val);
		}

		inline ffw::Vec4<T>& operator /= (const T& val) {
			x /= val;
			y /= val;
			z /= val;
			w /= val;
			return *this;
		}

		inline ffw::Vec4<T>  operator *  (const T& val) const {
			return Vec4<T>(x * val, y * val, z * val, w * val);
		}

		inline ffw::Vec4<T>& operator *= (const T& val) {
			x *= val;
			y *= val;
			z *= val;
			w *= val;
			return *this;
		}

		inline bool operator != (const Vec4<T>& vec) const {
			return !(*this == vec);
		}

		inline bool operator == (const Vec4<T>& vec) const {
			return (x == vec.x && y == vec.y && z == vec.z && w == vec.w);
		}

		inline ffw::Vec4<T>& normalize() {
			float l = sqrtf(x*x + y*y + z*z + w*w);
			if (l > 0) {
				x = x / l;
				y = y / l;
				z = z / l;
				w = w / l;
			}
			return *this;
		}

		inline ffw::Vec4<T>& scale(const T val) {
			x = x*val;
			y = y*val;
			z = z*val;
			w = w*val;
			return *this;
		}

		inline double length() const {
			return sqrt(static_cast<double>(x*x + y*y + z*z + w*w));
		}

		inline float lengthf() const {
			return sqrtf(static_cast<float>(x*x + y*y + z*z + w*w));
		}

		inline T lengthSqrd() const {
			return (x*x + y*y + z*z + w*w);
		}

		template <class S>
		inline operator ffw::Vec4<S>() const {
			return ffw::Vec4<S>((S)x, (S)y, (S)z, (S)w);
		}

    };
	/**
	 * @ingroup math
	 */
    typedef Vec4<float> Vec4f;
	/**
	 * @ingroup math
	 */
    typedef Vec4<int> Vec4i;
	/**
	* @ingroup math
	*/
	typedef Vec4<short> Vec4s;
	/**
	* @ingroup math
	*/
	typedef Vec4<long long> Vec4ll;
	/**
	 * @ingroup math
	 */
    typedef Vec4<double> Vec4d;
};
namespace ffw {
	template <>
	inline bool ffw::Vec4<float>::operator == (const Vec4<float>& vec) const {
		if (fabs(x - vec.x) > std::numeric_limits<float>::epsilon())return false;
		if (fabs(y - vec.y) > std::numeric_limits<float>::epsilon())return false;
		if (fabs(z - vec.z) > std::numeric_limits<float>::epsilon())return false;
		if (fabs(w - vec.w) > std::numeric_limits<float>::epsilon())return false;
		return true;
	}

	template <>
	inline bool ffw::Vec4<double>::operator == (const Vec4<double>& vec) const {
		if (fabs(x - vec.x) > std::numeric_limits<double>::epsilon())return false;
		if (fabs(y - vec.y) > std::numeric_limits<double>::epsilon())return false;
		if (fabs(z - vec.z) > std::numeric_limits<double>::epsilon())return false;
		if (fabs(w - vec.w) > std::numeric_limits<double>::epsilon())return false;
		return true;
	}
};
#endif
