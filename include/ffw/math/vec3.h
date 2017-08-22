/* This file is part of FineFramework project */
#ifndef FFW_VEC3
#define FFW_VEC3
#include "../config.h"
#include "quaternion.h"
#include <limits>
#include <cmath>

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

		inline void set(T compx, T compy, T compz) {
			x = compx;
			y = compy;
			z = compz;
		}

		inline void set(T Value) {
			x = Value;
			y = Value;
			z = Value;
		}

		inline void set(const Vec3<T>& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
		}

		inline void set(const std::initializer_list<T>& list) {
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

		inline ffw::Vec3<T>& rotateByAxis(double deg, Vec3<T> axis) {
			return rotateByAxisRad(deg * DEG_TO_RAD, axis);
		}

		inline ffw::Vec3<T>& rotateByAxisRad(double rad, Vec3<T> axis) {
			double sina = sin(rad);
			double cosa = cos(rad);
			double cosb = 1.0f - cosa;
			auto v = *this;
			x = static_cast<T>(v.x*(axis.x*axis.x*cosb + cosa) + v.y*(axis.x*axis.y*cosb - axis.z*sina) + v.z*(axis.x*axis.z*cosb + axis.y*sina));
			y = static_cast<T>(v.x*(axis.y*axis.x*cosb + axis.z*sina) + v.y*(axis.y*axis.y*cosb + cosa) + v.z*(axis.y*axis.z*cosb - axis.x*sina));
			z = static_cast<T>(v.x*(axis.z*axis.x*cosb - axis.y*sina) + v.y*(axis.z*axis.y*cosb + axis.x*sina) + v.z*(axis.z*axis.z*cosb + cosa));
			return *this;
		}

		inline ffw::Vec3<T>& rotateX(double deg) {
			T vy = y;
			T vz = z;
			//x = vx;
			y = static_cast<T>(vy*cos(deg*DEG_TO_RAD) - vz*sin(deg*DEG_TO_RAD));
			z = static_cast<T>(vy*sin(deg*DEG_TO_RAD) + vz*cos(deg*DEG_TO_RAD));
			return *this;
		}

		inline ffw::Vec3<T>& rotateY(double deg) {
			T vx = x;
			T vz = z;
			x = static_cast<T>(vx*cos(deg*DEG_TO_RAD) + vz*sin(deg*DEG_TO_RAD));
			//y = vy;
			z = static_cast<T>(vx*-sin(deg*DEG_TO_RAD) + vz*cos(deg*DEG_TO_RAD));
			return *this;
		}

		inline ffw::Vec3<T>& rotateZ(double deg) {
			T vx = x;
			T vy = y;
			x = static_cast<T>(vx*cos(deg*DEG_TO_RAD) - vy*sin(deg*DEG_TO_RAD));
			y = static_cast<T>(vx*sin(deg*DEG_TO_RAD) + vy*cos(deg*DEG_TO_RAD));
			//z = vz;
			return *this;
		}

		inline ffw::Vec3<T>& rotateXRad(double rad) {
			T vy = y;
			T vz = z;
			//x = vx;
			y = static_cast<T>(vy*cos(rad) - vz*sin(rad));
			z = static_cast<T>(vy*sin(rad) + vz*cos(rad));
			return *this;
		}

		inline ffw::Vec3<T>& rotateYRad(double rad) {
			T vx = x;
			T vz = z;
			x = static_cast<T>(vx*cos(rad) + vz*sin(rad));
			//y = vy;
			z = static_cast<T>(vx*-sin(rad) + vz*cos(rad));
			return *this;
		}

		inline ffw::Vec3<T>& rotateZRad(double rad) {
			T vx = x;
			T vy = y;
			x = static_cast<T>(vx*cos(rad) - vy*sin(rad));
			y = static_cast<T>(vx*sin(rad) + vy*cos(rad));
			//z = vz;
			return *this;
		}

		template<class S>
		inline ffw::Vec3<T>& rotateByQuaternion(const ffw::Quat<S>& quat) {
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

		inline ffw::Vec3<T>& normalize() {
			double l = sqrt(x*x + y*y + z*z);
			if (l > 0) {
				x = static_cast<T>(x / l);
				y = static_cast<T>(y / l);
				z = static_cast<T>(z / l);
			}
			return *this;
		}

		inline ffw::Vec3<T>& scale(T val) {
			x = x*val;
			y = y*val;
			z = z*val;
			return *this;
		}

		inline double length() const {
			return sqrt(static_cast<double>(x*x + y*y + z*z));
		}

		inline float lengthf() const {
			return sqrtf(static_cast<float>(x*x + y*y + z*z));
		}

		inline T lengthSqrd() const {
			return (x*x + y*y + z*z);
		}
		
		T& operator [] (size_t i){
			return ((T*)&x)[i];
		}

		const T& operator [] (size_t i) const  {
			return ((T*)&x)[i];
		}

		template <class S>
		inline operator ffw::Vec3<S>() const {
			return ffw::Vec3<S>((S)x, (S)y, (S)z);
		}

		inline Vec3<T> round() const {
			return Vec3<T>(std::round(x), std::round(y), std::round(z));
		}

		inline Vec3<T> floor() const {
			return Vec3<T>(std::floor(x), std::floor(y), std::floor(z));
		}

		inline Vec3<T> ceil() const {
			return Vec3<T>(std::ceil(x), std::ceil(y), std::ceil(z));
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
	/**
	* @ingroup math
	*/
	template <class T>
	inline T dot(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		return (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec3<T> cross(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		ffw::Vec3<T> product;
		product.x = V1.y*V2.z - V1.z*V2.y;
		product.y = V1.z*V2.x - V1.x*V2.z;
		product.z = V1.x*V2.y - V1.y*V2.x;
		return product;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T distance(const Vec3<T>& v1, const Vec3<T>& v2) {
		auto v = v2 - v1;
		return static_cast<T>(v.length());
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline Vec3<T> middle(const Vec3<T>& v1, const Vec3<T>& v2) {
		auto v = (v2 - v1) / 2.0;
		return v1 + v;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec3<T> normalize(const Vec3<T>& vec) {
		auto copy = vec;
		copy.normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline double angle(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		double dot = (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
		double V1Length = sqrt(V1.x*V1.x + V1.y*V1.y + V1.z*V1.z);
		double V2Length = sqrt(V2.x*V2.x + V2.y*V2.y + V2.z*V2.z);
		return static_cast<double>(acos(dot / (V1Length*V2Length))*RAD_TO_DEG);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline double angleRad(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		double dot = (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
		double V1Length = sqrt(V1.x*V1.x + V1.y*V1.y + V1.z*V1.z);
		double V2Length = sqrt(V2.x*V2.x + V2.y*V2.y + V2.z*V2.z);
		return static_cast<double>(acos(dot / (V1Length*V2Length)));
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::ostream& operator << (std::ostream& os, const ffw::Vec3<T>& vec) {
		os << vec.x << ", " << vec.y << ", " << vec.z;
		return os;
	}
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
