/* This file is part of FineFramework project */
#ifndef FFW_BASE_FUNCTIONS
#define FFW_BASE_FUNCTIONS
#include "../config.h"

namespace ffw{
    template <class T> T Lerp(const T& a, const T& b, float weight);
    template <class T> float Dot(const Vec2<T>& v1, const Vec2<T>& v2);
    template <class T>  float Dot(const Vec3<T>& v1, const Vec3<T>& v2);
    template <class T> Vec3<T> Cross(const Vec3<T>& v1, const Vec3<T>& v2);
    template <class T> Vec2<T> Normalize(const Vec2<T>& v);
    template <class T> Vec3<T> Normalize(const Vec3<T>& v);
    template <class T> Vec4<T> Normalize(const Vec4<T>& v);
    template <class T> Quat<T> Normalize(const Quat<T>& q);
    template <class T> float Angle(const Vec3<T>& v1, const Vec3<T>& v2);
    template <class T> float Angle(const Vec2<T>& v1, const Vec2<T>& v2);
    template <class T> float AngleRad(const Vec3<T>& v1, const Vec3<T>& v2);
    template <class T> float AngleRad(const Vec2<T>& v1, const Vec2<T>& v2);
    Mat4x4f MakeProjectionMatrix(float fieldofview, float aspect, float near, float far);
    Mat4x4f MakeLookAtMatrix(const Vec3f& eyes, const Vec3f& target, const Vec3f& upvector);
    Mat4x4f MakeFpsCameraMatrix(const Vec3f& eyes, float pitch, float yaw);
	template<class T> T Clamp(T value, T min, T max);
	template<class T> T Remap(T value, T inmin, T inmax, T outmin, T outmax);
	unsigned long NextPowOfTwo(unsigned long value);
	template <class T> Mat4x4<T> MakeRotationMatrix(const Quat<T>& q);
	template<class T> Vec3<T> Vec2ToVec3(const Vec2<T>& vec, T z);
	template<class T> Vec4<T> Vec3ToVec4(const Vec3<T>& vec, T w);
	template<class T> Vec3<T> Vec2ToVec3(const Vec2<T>& vec);
	template<class T> Vec4<T> Vec3ToVec4(const Vec3<T>& vec);
	template<class T> Vec3<T> Vec4ToVec3(const Vec4<T>& vec);
	template<class T> Vec2<T> Vec3ToVec2(const Vec3<T>& vec);
	template <class T> Vec3<T> QuatToVec3(const Quat<T>& Quat);
	template <class T> Vec4<T> QuatToVec4(const Quat<T>& Quat);
	template<class T> Quat<T> Vec4ToQuat(const Vec4<T>& vec);
	unsigned short ByteSwap16(unsigned short value);
	unsigned long ByteSwap32(unsigned long value);
	unsigned long long ByteSwap64(unsigned long long value);
    template <class T> std::ostream& operator << (std::ostream& os, const Vec2<T>& v);
    template <class T> std::ostream& operator << (std::ostream& os, const Vec3<T>& v);
    template <class T> std::ostream& operator << (std::ostream& os, const Vec4<T>& v);
	std::ostream& operator << (std::ostream& os, const Color& c);
	template <class T> std::ostream& operator << (std::ostream& os, const Quat<T>& q);
};
#include "functions.inl"
#endif
