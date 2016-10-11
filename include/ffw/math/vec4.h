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
        Vec4();
        Vec4(T X, T Y, T Z, T W);
        Vec4(T Value);
        Vec4(const Vec4<T>& V);
        Vec4(std::initializer_list<T> List);
        void Set(T X, T Y, T Z, T W);
        void Set(T Value);
        void Set(const Vec4<T>& V);
        void Set(std::initializer_list<T> List);
        Vec4<T>  operator - () const;
        Vec4<T>& operator =  (const Vec4<T>& V);
        Vec4<T>  operator +  (const Vec4<T>& V) const;
        Vec4<T>& operator += (const Vec4<T>& V);
        Vec4<T>  operator -  (const Vec4<T>& V) const;
        Vec4<T>& operator -= (const Vec4<T>& V);
        Vec4<T>  operator /  (const Vec4<T>& V) const;
        Vec4<T>& operator /= (const Vec4<T>& V);
        Vec4<T>  operator *  (const Vec4<T>& V) const;
        Vec4<T>& operator *= (const Vec4<T>& V);
        Vec4<T>& operator =  (const T& Val);
        Vec4<T>  operator +  (const T& Val) const;
        Vec4<T>& operator += (const T& Val);
        Vec4<T>  operator -  (const T& Val) const;
        Vec4<T>& operator -= (const T& Val);
        Vec4<T>  operator /  (const T& Val) const;
        Vec4<T>& operator /= (const T& Val);
        Vec4<T>  operator *  (const T& Val) const;
        Vec4<T>& operator *= (const T& Val);
        bool operator != (const Vec4<T>& V) const;
        bool operator == (const Vec4<T>& V) const;
        Vec4<T>& Normalize();
        Vec4<T>& Scale(const T Val);
        float Length() const;
        T LengthSqrd() const;
		template <class S> explicit operator Vec4<S>() const;
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
    typedef Vec4<double> Vec4d;
};
#include "Vec4.inl"
#endif
