/* This file is part of FineFramework project */
#ifndef FFW_VEC3
#define FFW_VEC3

namespace ffw {
	/**
	 * @ingroup math
	 */
    template <class T> struct Vec3 {
    public:
        T x;
        T y;
        T z;
		inline Vec3() {
			x = 0;
			y = 0;
			z = 0;
		}

		inline Vec3(T compx, T compy, T compz) {
			x = compx;
			y = compy;
			z = compz;
		}

		inline Vec3(T Value) {
			x = Value;
			y = Value;
			z = Value;
		}

		inline Vec3(const Vec3<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		inline Vec3(const std::initializer_list<T>& list) {
			if (list.size() != 3) {
				x = 0;
				y = 0;
				z = 0;
				return;
			}
			x = *(list.begin());
			y = *(list.begin() + 1);
			z = *(list.begin() + 2);
		}

		inline void Set(T compx, T compy, T compz) {
			x = compx;
			y = compy;
			z = compz;
		}

		inline void Set(T Value) {
			x = Value;
			y = Value;
			z = Value;
		}

		inline void Set(const Vec3<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		inline void Set(const std::initializer_list<T>& list) {
			if (list.size() != 3)return;
			x = *(list.begin());
			y = *(list.begin() + 1);
			z = *(list.begin() + 2);
		}

		inline ffw::Vec3<T>  operator - () const {
			return Vec3<T>(-x, -y, -z);
		}

		inline ffw::Vec3<T>& operator =  (const Vec3<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			return *this;
		}

		inline ffw::Vec3<T>  operator +  (const Vec3<T>& vec) const {
			return Vec3<T>(x + vec.x, y + vec.y, z + vec.z);
		}

		inline ffw::Vec3<T>& operator += (const Vec3<T>& vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			return *this;
		}

		inline ffw::Vec3<T>  operator -  (const Vec3<T>& vec) const {
			return Vec3<T>(x - vec.x, y - vec.y, z - vec.z);
		}

		inline ffw::Vec3<T>& operator -= (const Vec3<T>& vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			return *this;
		}

		inline ffw::Vec3<T>  operator /  (const Vec3<T>& vec) const {
			return Vec3<T>(x / vec.x, y / vec.y, z / vec.z);
		}

		inline ffw::Vec3<T>& operator /= (const Vec3<T>& vec) {
			x /= vec.x;
			y /= vec.y;
			z /= vec.z;
			return *this;
		}

		inline ffw::Vec3<T>  operator *  (const Vec3<T>& vec) const {
			return Vec3<T>(x * vec.x, y * vec.y, z * vec.z);
		}

		inline ffw::Vec3<T>& operator *= (const Vec3<T>& vec) {
			x *= vec.x;
			y *= vec.y;
			z *= vec.z;
			return *this;
		}

		inline ffw::Vec3<T>& operator =  (const T& val) {
			x = val;
			y = val;
			z = val;
			return *this;
		}

		inline ffw::Vec3<T>  operator +  (const T& val) const {
			return Vec3<T>(x + val, y + val, z + val);
		}

		inline ffw::Vec3<T>& operator += (const T& val) {
			x += val;
			y += val;
			z += val;
			return *this;
		}

		inline ffw::Vec3<T>  operator -  (const T& val) const {
			return Vec3<T>(x - val, y - val, z - val);
		}

		inline ffw::Vec3<T>& operator -= (const T& val) {
			x -= val;
			y -= val;
			z -= val;
			return *this;
		}

		inline ffw::Vec3<T>  operator /  (const T& val) const {
			return Vec3<T>(x / val, y / val, z / val);
		}

		inline ffw::Vec3<T>& operator /= (const T& val) {
			x /= val;
			y /= val;
			z /= val;
			return *this;
		}

		inline ffw::Vec3<T>  operator *  (const T& val) const {
			return Vec3<T>(x * val, y * val, z * val);
		}

		inline ffw::Vec3<T>& operator *= (const T& val) {
			x *= val;
			y *= val;
			z *= val;
			return *this;
		}

		inline bool operator != (const Vec3<T>& vec) const {
			return !(*this == vec);
		}

		inline bool operator == (const Vec3<T>& vec) const {
			return (x == vec.x && y == vec.y && z == vec.z);
		}

		inline ffw::Vec3<T>& RotateByAxis(double deg, Vec3<T> axis) {
			return RotateByAxisRad(deg * DEG_TO_RAD, axis);
		}

		inline ffw::Vec3<T>& RotateByAxisRad(double rad, Vec3<T> axis) {
			double sina = sin(rad);
			double cosa = cos(rad);
			double cosb = 1.0f - cosa;
			auto v = *this;
			x = static_cast<T>(v.x*(axis.x*axis.x*cosb + cosa) + v.y*(axis.x*axis.y*cosb - axis.z*sina) + v.z*(axis.x*axis.z*cosb + axis.y*sina));
			y = static_cast<T>(v.x*(axis.y*axis.x*cosb + axis.z*sina) + v.y*(axis.y*axis.y*cosb + cosa) + v.z*(axis.y*axis.z*cosb - axis.x*sina));
			z = static_cast<T>(v.x*(axis.z*axis.x*cosb - axis.y*sina) + v.y*(axis.z*axis.y*cosb + axis.x*sina) + v.z*(axis.z*axis.z*cosb + cosa));
			return *this;
		}

		inline ffw::Vec3<T>& RotateX(double deg) {
			T vy = y;
			T vz = z;
			//x = vx;
			y = static_cast<T>(cos(deg*DEG_TO_RAD))*vy - static_cast<T>(sin(deg*DEG_TO_RAD))*vz;
			z = static_cast<T>(sin(deg*DEG_TO_RAD))*vy + static_cast<T>(cos(deg*DEG_TO_RAD))*vz;
			return *this;
		}

		inline ffw::Vec3<T>& RotateY(double deg) {
			T vx = x;
			T vz = z;
			x = static_cast<T>(cos(deg*DEG_TO_RAD))*vx + static_cast<T>(sin(deg*DEG_TO_RAD))*vz;
			//y = vy;
			z = static_cast<T>(-sin(deg*DEG_TO_RAD))*vx + static_cast<T>(cos(deg*DEG_TO_RAD))*vz;
			return *this;
		}

		inline ffw::Vec3<T>& RotateZ(double deg) {
			T vx = x;
			T vy = y;
			x = static_cast<T>(cos(deg*DEG_TO_RAD))*vx - static_cast<T>(sin(deg*DEG_TO_RAD))*vy;
			y = static_cast<T>(sin(deg*DEG_TO_RAD))*vx + static_cast<T>(cos(deg*DEG_TO_RAD))*vy;
			//z = vz;
			return *this;
		}

		inline ffw::Vec3<T>& RotateXRad(double rad) {
			T vy = y;
			T vz = z;
			//x = vx;
			y = static_cast<T>(cos(rad))*vy - static_cast<T>(sin(rad))*vz;
			z = static_cast<T>(sin(rad))*vy + static_cast<T>(cos(rad))*vz;
			return *this;
		}

		inline ffw::Vec3<T>& RotateYRad(double rad) {
			T vx = x;
			T vz = z;
			x = static_cast<T>(cos(rad))*vx + static_cast<T>(sin(rad))*vz;
			//y = vy;
			z = static_cast<T>(-sin(rad))*vx + static_cast<T>(cos(rad))*vz;
			return *this;
		}

		inline ffw::Vec3<T>& RotateZRad(double rad) {
			T vx = x;
			T vy = y;
			x = static_cast<T>(cos(rad))*vx - static_cast<T>(sin(rad))*vy;
			y = static_cast<T>(sin(rad))*vx + static_cast<T>(cos(rad))*vy;
			//z = vz;
			return *this;
		}

		template<class S>
		inline ffw::Vec3<T>& RotateByQuaternion(const ffw::Quat<S>& quat) {
			ffw::Vec3<T> qvc;
			qvc.x = static_cast<T>(quat.y*z - quat.z*y);
			qvc.y = static_cast<T>(quat.z*x - quat.x*z);
			qvc.z = static_cast<T>(quat.x*y - quat.y*x);
			ffw::Vec3<T> qvcc;
			qvcc.x = static_cast<T>(quat.y*qvc.z - quat.z*qvc.y);
			qvcc.y = static_cast<T>(quat.z*qvc.x - quat.x*qvc.z);
			qvcc.z = static_cast<T>(quat.x*qvc.y - quat.y*qvc.x);
			qvc = static_cast<T>(qvc * (2.0 * quat.w));
			qvcc = static_cast<T>(qvcc * 2.0);
			*this += qvc + qvcc;
			return *this;
		}

		inline ffw::Vec3<T>& Normalize() {
			double l = sqrt(x*x + y*y + z*z);
			if (l > 0) {
				x = static_cast<T>(x / l);
				y = static_cast<T>(y / l);
				z = static_cast<T>(z / l);
			}
			return *this;
		}

		inline ffw::Vec3<T>& Scale(T val) {
			x = x*val;
			y = y*val;
			z = z*val;
			return *this;
		}

		inline double Length() const {
			return sqrt(static_cast<double>(x*x + y*y + z*z));
		}

		inline float Lengthf() const {
			return sqrtf(static_cast<float>(x*x + y*y + z*z));
		}

		inline T LengthSqrd() const {
			return (x*x + y*y + z*z);
		}

		template <class S>
		inline operator ffw::Vec3<S>() const {
			return ffw::Vec3<S>((S)x, (S)y, (S)z);
		}
    };
	/**
	 * @ingroup math
	 */
    typedef Vec3<float> Vec3f;
	/**
	 * @ingroup math
	 */
    typedef Vec3<int> Vec3i;
	/**
	* @ingroup math
	*/
	typedef Vec3<short> Vec3s;
	/**
	* @ingroup math
	*/
	typedef Vec3<long long> Vec3ll;
	/**
	 * @ingroup math
	 */
    typedef Vec3<double> Vec3d;
};
namespace ffw {
	template <>
	inline bool Vec3<float>::operator == (const Vec3<float>& vec) const {
		if (fabs(x - vec.x) > std::numeric_limits<float>::epsilon())return false;
		if (fabs(y - vec.y) > std::numeric_limits<float>::epsilon())return false;
		if (fabs(z - vec.z) > std::numeric_limits<float>::epsilon())return false;
		return true;
	}

	template <>
	inline bool Vec3<double>::operator == (const Vec3<double>& vec) const {
		if (fabs(x - vec.x) > std::numeric_limits<double>::epsilon())return false;
		if (fabs(y - vec.y) > std::numeric_limits<double>::epsilon())return false;
		if (fabs(z - vec.z) > std::numeric_limits<double>::epsilon())return false;
		return true;
	}
};
#endif
