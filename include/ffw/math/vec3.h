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
        Vec3();
        Vec3(T X, T Y, T Z);
        Vec3(T Value);
        Vec3(const Vec3<T>& V);
        Vec3(std::initializer_list<T> List);
        void Set(T X, T Y, T Z);
        void Set(T Value);
        void Set(const Vec3<T>& V);
        void Set(std::initializer_list<T> List);
        Vec3<T> operator - () const;
        Vec3<T>& operator =  (const Vec3<T>& V);
        Vec3<T>  operator +  (const Vec3<T>& V) const;
        Vec3<T>& operator += (const Vec3<T>& V);
        Vec3<T>  operator -  (const Vec3<T>& V) const;
        Vec3<T>& operator -= (const Vec3<T>& V);
        Vec3<T>  operator /  (const Vec3<T>& V) const;
        Vec3<T>& operator /= (const Vec3<T>& V);
        Vec3<T>  operator *  (const Vec3<T>& V) const;
        Vec3<T>& operator *= (const Vec3<T>& V);
        Vec3<T>& operator =  (const T& Val);
        Vec3<T>  operator +  (const T& Val) const;
        Vec3<T>& operator += (const T& Val);
        Vec3<T>  operator -  (const T& Val) const;
        Vec3<T>& operator -= (const T& Val);
        Vec3<T>  operator /  (const T& Val) const;
        Vec3<T>& operator /= (const T& Val);
        Vec3<T>  operator *  (const T& Val) const;
        Vec3<T>& operator *= (const T& Val);
        bool operator != (const Vec3<T>& V) const;
        bool operator == (const Vec3<T>& V) const;
        Vec3<T>& RotateByAxis(const float Deg, Vec3<T> Axis);
        Vec3<T>& RotateX(const float Deg);
        Vec3<T>& RotateY(const float Deg);
        Vec3<T>& RotateZ(const float Deg);
        Vec3<T>& RotateXRad(const float Rad);
        Vec3<T>& RotateYRad(const float Rad);
        Vec3<T>& RotateZRad(const float Rad);
        Vec3<T>& RotateByQuaternion(const ffw::Quat<T>& Q);
        Vec3<T>& Normalize();
        Vec3<T>& Scale(const T Val);
        float Length() const;
        T LengthSqrd() const;
		template <class S> explicit operator Vec3<S>() const;
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
    typedef Vec3<double> Vec3d;
};
#include "Vec3.inl"
#endif
