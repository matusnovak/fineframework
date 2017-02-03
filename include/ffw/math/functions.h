/* This file is part of FineFramework project */
#ifndef FFW_BASE_FUNCTIONS
#define FFW_BASE_FUNCTIONS
#include "../config.h"

namespace ffw {
	/**
	* @ingroup math
	*/
	template <class T>
	inline T Lerp(const T& a, const T& b, float w) {
		return T((1 - w)*a + w*b);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T Dot(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2) {
		return (V1.x*V2.x + V1.y*V2.y);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T Dot(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		return (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T Dot(const ffw::Vec4<T>& V1, const ffw::Vec4<T>& V2) {
		return (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z + V1.w*V2.w);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec3<T> Cross(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
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
	inline T Distance(const Vec2<T>& v1, const Vec2<T>& v2) {
		auto v = v2 - v1;
		return static_cast<T>(v.Length());
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T Distance(const Vec3<T>& v1, const Vec3<T>& v2) {
		auto v = v2 - v1;
		return static_cast<T>(v.Length());
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline T Distance(const Vec4<T>& v1, const Vec4<T>& v2) {
		auto v = v2 - v1;
		return static_cast<T>(v.Length());
	}
	/**
	* @ingroup math
	*/
	template <class Vec>
	inline Vec Middle(const Vec& v1, const Vec& v2) {
		auto v = (v2 - v1) / 2.0;
		return v1 + v;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec2<T> Normalize(const Vec2<T>& vec) {
		auto copy = vec;
		copy.Normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec3<T> Normalize(const Vec3<T>& vec) {
		auto copy = vec;
		copy.Normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	inline ffw::Color Normalize(const Color& col) {
		auto copy = col;
		copy.Normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec4<T> Normalize(const Vec4<T>& vec) {
		auto copy = vec;
		copy.Normalize();
		return copy;
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Quat<T> Normalize(const Quat<T>& Q) {
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
	inline double Angle(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2) {
		double dot = (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
		double V1Length = sqrt(V1.x*V1.x + V1.y*V1.y + V1.z*V1.z);
		double V2Length = sqrt(V2.x*V2.x + V2.y*V2.y + V2.z*V2.z);
		return static_cast<double>(acos(dot / (V1Length*V2Length))*RAD_TO_DEG);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline double Angle(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2) {
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
	inline T Clamp(T Val, T Min, T Max) {
		return std::max(Min, std::min(Val, Max));
	}
	/**
	* @ingroup math
	*/
	inline ffw::Color Clamp(const ffw::Color& color) {
		return ffw::Color(color).Clamp();
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline T Remap(T Value, T InMin, T InMax, T OutMin, T OutMax) {
		return (Value - InMin) / (InMax - InMin) * (OutMax - OutMin) + OutMin;
	}
	/**
	* @ingroup math
	*/
	inline unsigned long NextPowOfTwo(unsigned long Value) {
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
	inline ffw::Vec3<T> Vec2ToVec3(const Vec2<T>& Vec) {
		return Vec3<T>(Vec.x, Vec.y, 0);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec4<T> Vec3ToVec4(const ffw::Vec3<T>& Vec) {
		return Vec4<T>(Vec.x, Vec.y, Vec.z, 0);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec3<T> Vec2ToVec3(const ffw::Vec2<T>& Vec, T Z) {
		return Vec3<T>(Vec.x, Vec.y, Z);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec4<T> Vec3ToVec4(const ffw::Vec3<T>& Vec, T W) {
		return Vec4<T>(Vec.x, Vec.y, Vec.z, W);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec3<T> Vec4ToVec3(const ffw::Vec4<T>& Vec) {
		return Vec3<T>(Vec.x, Vec.y, Vec.z);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline ffw::Vec2<T> Vec3ToVec2(const ffw::Vec3<T>& Vec) {
		return Vec3<T>(Vec.x, Vec.y);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec3<T> QuatToVec3(const ffw::Quat<T>& Quat) {
		return Vec3<T>(Quat.x, Quat.y, Quat.z);
	}
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Vec4<T> QuatToVec4(const ffw::Quat<T>& Quat) {
		return Vec4<T>(Quat.x, Quat.y, Quat.z, Quat.w);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	ffw::Quat<T> Vec4ToQuat(const ffw::Vec4<T>& Vec) {
		return Quaternion(Vec.x, Vec.y, Vec.z, Vec.w);
	}

#ifdef FFW_WINDOWS_MSVC
	/**
	* @ingroup math
	*/
	inline unsigned short ByteSwap16(unsigned short Value) {
		return _byteswap_ushort(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long ByteSwap32(unsigned long Value) {
		return _byteswap_ulong(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long long ByteSwap64(unsigned long long Value) {
		return _byteswap_uint64(Value);
	}
#else
	/**
	* @ingroup math
	*/
	inline unsigned short ByteSwap16(unsigned short Value) {
		return __builtin_bswap16(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long ByteSwap32(unsigned long Value) {
		return __builtin_bswap32(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long long ByteSwap64(unsigned long long Value) {
		return __builtin_bswap64(Value);
	}
#endif
	/**
	* @ingroup math
	*/
	inline ffw::Vec4i ContainImage(int imgwidth, int imgheight, int maxwidth, int maxheight) {
		float frameAspect = imgheight / float(imgwidth);
		ffw::Vec4i ret;

		if (maxwidth*frameAspect <= maxheight) {
			ret.z = maxwidth;
			ret.w = int(maxwidth*frameAspect);
			ret.x = 0;
			ret.y = (maxheight - ret.w) / 2;

		}
		else {
			ret.z = int(maxheight / frameAspect);
			ret.w = maxheight;
			ret.x = (maxwidth - ret.z) / 2;
			ret.y = 0;
		}

		return ret;
	}
	/**
	* @ingroup math
	*/
	inline ffw::Vec4i CoverImage(int imgwidth, int imgheight, int maxwidth, int maxheight) {
		float imgAspect = imgheight / float(imgwidth);
		ffw::Vec4i ret;

		// Target area is vertical
		if (maxheight / float(maxwidth) >= 1.0f) {
			// Image is vertical
			if (imgAspect >= 1.0f) {
				ret.z = int(maxheight / imgAspect);
				ret.w = maxheight;
				if (ret.z < maxwidth) {
					ret.z = maxwidth;
					ret.w = int(maxwidth*imgAspect);
				}
				// Image is horizontal
			}
			else {
				ret.z = int(maxheight / imgAspect);
				ret.w = maxheight;
			}
			// Target area is horizontal
		}
		else {
			// Image is vertical
			if (imgAspect >= 1.0f) {
				ret.z = maxwidth;
				ret.w = int(maxwidth*imgAspect);
				// Image is horizontal
			}
			else {
				ret.z = maxwidth;
				ret.w = int(maxwidth*imgAspect);
				if (ret.w < maxheight) {
					ret.z = int(maxheight / imgAspect);
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
