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
        Vec2();
        Vec2(T X, T Y);
        Vec2(T Value);
        Vec2(const Vec2<T>& V);
        Vec2(std::initializer_list<T> List);
        void Set(T X, T Y);
        void Set(T Value);
        void Set(const Vec2<T>& V);
        void Set(std::initializer_list<T> List);
        Vec2<T> operator - () const;
        Vec2<T>& operator =  (const Vec2<T>& V);
        Vec2<T>  operator +  (const Vec2<T>& V) const;
        Vec2<T>& operator += (const Vec2<T>& V);
        Vec2<T>  operator -  (const Vec2<T>& V) const;
        Vec2<T>& operator -= (const Vec2<T>& V);
        Vec2<T>  operator /  (const Vec2<T>& V) const;
        Vec2<T>& operator /= (const Vec2<T>& V);
        Vec2<T>  operator *  (const Vec2<T>& V) const;
        Vec2<T>& operator *= (const Vec2<T>& V);
        Vec2<T>& operator =  (const T& Val);
        Vec2<T>  operator +  (const T& Val) const;
        Vec2<T>& operator += (const T& Val);
        Vec2<T>  operator -  (const T& Val) const;
        Vec2<T>& operator -= (const T& Val);
        Vec2<T>  operator /  (const T& Val) const;
        Vec2<T>& operator /= (const T& Val);
        Vec2<T>  operator *  (const T& Val) const;
        Vec2<T>& operator *= (const T& Val);
        bool operator != (const Vec2<T>& V) const;
        bool operator == (const Vec2<T>& V) const;
        Vec2<T>& Rotate(const float Deg);
        Vec2<T>& RotateRad(const float Rad);
        Vec2<T>& Normalize();
        Vec2<T>& Scale(const T Val);
        float Length() const;
        T LengthSqrd() const;
		template <class S> explicit operator Vec2<S>() const;
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
    typedef Vec2<double> Vec2d;
};
#include "vec2.inl"
#endif
