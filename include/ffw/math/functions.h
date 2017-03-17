/* This file is part of FineFramework project */
#ifndef FFW_BASE_FUNCTIONS
#define FFW_BASE_FUNCTIONS
#include "../config.h"

namespace ffw {
	/**
	* @ingroup math
	*/
	template <class T>
	inline T lerp(const T& a, const T& b, float w) {
		return T((1 - w)*a + w*b);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T dot(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2) {
		return (V1.x*V2.x + V1.y*V2.y);
	}
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
	inline T dot(const ffw::Vec4<T>& V1, const ffw::Vec4<T>& V2) {
		return (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z + V1.w*V2.w);
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
	* @bug Some random bug
	*/
	template <class T>
	inline T distance(const Vec2<T>& v1, const Vec2<T>& v2) {
		auto v = v2 - v1;
		return static_cast<T>(v.length());
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
	inline T distance(const Vec4<T>& v1, const Vec4<T>& v2) {
		auto v = v2 - v1;
		return static_cast<T>(v.length());
	}
	/**
	* @ingroup math
	*/
	template <class Vec>
	inline Vec middle(const Vec& v1, const Vec& v2) {
		auto v = (v2 - v1) / 2.0;
		return v1 + v;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec2<T> normalize(const Vec2<T>& vec) {
		auto copy = vec;
		copy.normalize();
		return copy;
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
	inline ffw::Color normalize(const Color& col) {
		auto copy = col;
		copy.normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec4<T> normalize(const Vec4<T>& vec) {
		auto copy = vec;
		copy.normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Quat<T> normalize(const Quat<T>& Q) {
		ffw::Quat<T> result;
		float n = 1.0f / sqrt(Q.x*Q.x + Q.y*Q.y + Q.z*Q.z + Q.w*Q.w);
		result.x = Q.x * n;
		result.y = Q.y * n;
		result.z = Q.z * n;
		result.w = Q.w * n;
		return result;
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
	inline double angle(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2) {
		double dot = (V1.x*V2.x + V1.y*V2.y);
		double V1Length = sqrt(V1.x*V1.x + V1.y*V1.y);
		double V2Length = sqrt(V2.x*V2.x + V2.y*V2.y);
		return static_cast<double>(acos(dot / (V1Length*V2Length))*RAD_TO_DEG);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline double AngleRad(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		double dot = (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
		double V1Length = sqrt(V1.x*V1.x + V1.y*V1.y + V1.z*V1.z);
		double V2Length = sqrt(V2.x*V2.x + V2.y*V2.y + V2.z*V2.z);
		return static_cast<double>(acos(dot / (V1Length*V2Length)));
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline double AngleRad(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2) {
		double dot = (V1.x*V2.x + V1.y*V2.y);
		double V1Length = sqrt(V1.x*V1.x + V1.y*V1.y);
		double V2Length = sqrt(V2.x*V2.x + V2.y*V2.y);
		return static_cast<double>(acos(dot / (V1Length*V2Length)));
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline T clamp(T Val, T Min, T Max) {
		return std::max(Min, std::min(Val, Max));
	}
	/**
	* @ingroup math
	*/
	inline ffw::Color clamp(const ffw::Color& color) {
		return ffw::Color(color).clamp();
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	inline T remap(T value, T InMin, T InMax, T OutMin, T OutMax) {
		return (value - InMin)*(OutMax - OutMin) / (InMax - InMin) + OutMin;
	}
	/**
	* @ingroup math
	*/
	inline unsigned long nextPowOfTwo(unsigned long Value) {
		unsigned long P = 1;
		while (P < Value) {
			P *= 2;
		}
		return P;
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec3<T> vec2ToVec3(const Vec2<T>& Vec) {
		return Vec3<T>(Vec.x, Vec.y, 0);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec4<T> vec3ToVec4(const ffw::Vec3<T>& Vec) {
		return Vec4<T>(Vec.x, Vec.y, Vec.z, 0);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec3<T> vec2ToVec3(const ffw::Vec2<T>& Vec, T Z) {
		return Vec3<T>(Vec.x, Vec.y, Z);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec4<T> vec3ToVec4(const ffw::Vec3<T>& Vec, T W) {
		return Vec4<T>(Vec.x, Vec.y, Vec.z, W);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec3<T> vec4ToVec3(const ffw::Vec4<T>& Vec) {
		return Vec3<T>(Vec.x, Vec.y, Vec.z);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec2<T> vec3ToVec2(const ffw::Vec3<T>& Vec) {
		return Vec3<T>(Vec.x, Vec.y);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec3<T> quatToVec3(const ffw::Quat<T>& Quat) {
		return Vec3<T>(Quat.x, Quat.y, Quat.z);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec4<T> quatToVec4(const ffw::Quat<T>& Quat) {
		return Vec4<T>(Quat.x, Quat.y, Quat.z, Quat.w);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	ffw::Quat<T> vec4ToQuat(const ffw::Vec4<T>& Vec) {
		return Quaternion(Vec.x, Vec.y, Vec.z, Vec.w);
	}

#ifdef FFW_WINDOWS_MSVC
	/**
	* @ingroup math
	*/
	inline unsigned short byteSwap16(unsigned short Value) {
		return _byteswap_ushort(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long byteSwap32(unsigned long Value) {
		return _byteswap_ulong(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long long byteSwap64(unsigned long long Value) {
		return _byteswap_uint64(Value);
	}
#else
	/**
	* @ingroup math
	*/
	inline unsigned short byteSwap16(unsigned short Value) {
		return __builtin_bswap16(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long byteSwap32(unsigned long Value) {
		return __builtin_bswap32(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long long byteSwap64(unsigned long long Value) {
		return __builtin_bswap64(Value);
	}
#endif
	/**
	* @ingroup math
	*/
	template<typename T>
	ffw::Vec4<T> containImage(T imgwidth, T imgheight, T maxwidth, T maxheight) {
		float frameAspect = imgheight / float(imgwidth);
		ffw::Vec4<T> ret;

		if (maxwidth*frameAspect <= maxheight) {
			ret.z = maxwidth;
			ret.w = T(maxwidth*frameAspect);
			ret.x = 0;
			ret.y = (maxheight - ret.w) / 2;

		}
		else {
			ret.z = T(maxheight / frameAspect);
			ret.w = maxheight;
			ret.x = (maxwidth - ret.z) / 2;
			ret.y = 0;
		}

		return ret;
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	ffw::Vec4<T> coverImage(T imgwidth, T imgheight, T maxwidth, T maxheight) {
		float imgAspect = imgheight / float(imgwidth);
		ffw::Vec4<T> ret;

		// Target area is vertical
		if (maxheight / float(maxwidth) >= 1.0f) {
			// Image is vertical
			if (imgAspect >= 1.0f) {
				ret.z = T(maxheight / imgAspect);
				ret.w = maxheight;
				if (ret.z < maxwidth) {
					ret.z = maxwidth;
					ret.w = T(maxwidth*imgAspect);
				}
				// Image is horizontal
			}
			else {
				ret.z = T(maxheight / imgAspect);
				ret.w = maxheight;
			}
			// Target area is horizontal
		}
		else {
			// Image is vertical
			if (imgAspect >= 1.0f) {
				ret.z = maxwidth;
				ret.w = T(maxwidth*imgAspect);
				// Image is horizontal
			}
			else {
				ret.z = maxwidth;
				ret.w = T(maxwidth*imgAspect);
				if (ret.w < maxheight) {
					ret.z = T(maxheight / imgAspect);
					ret.w = maxheight;
				}
			}
		}
		ret.x = (ret.z - maxwidth) / -2;
		ret.y = (ret.w - maxheight) / -2;
		return ret;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::ostream& operator << (std::ostream& os, const ffw::Vec2<T>& vec) {
		os << vec.x << ", " << vec.y;
		return os;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::ostream& operator << (std::ostream& os, const ffw::Vec3<T>& vec) {
		os << vec.x << ", " << vec.y << ", " << vec.z;
		return os;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::ostream& operator << (std::ostream& os, const ffw::Vec4<T>& vec) {
		os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
		return os;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline std::ostream& operator << (std::ostream& os, const ffw::Quat<T>& quat) {
		os << quat.x << ", " << quat.y << ", " << quat.z << ", " << quat.w;
		return os;
	}
	/**
	* @ingroup math
	*/
	inline std::ostream& operator << (std::ostream& os, const ffw::Color& color) {
		os << color.r << ", " << color.g << ", " << color.b << ", " << color.a;
		return os;
	}
};
#endif
