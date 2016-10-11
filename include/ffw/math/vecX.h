/* This file is part of FineFramework project */
#ifndef FFW_VEC_X
#define FFW_VEC_X
#include <array>
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"

namespace ffw{
	template<size_t S, class T> class Vec {
	public:
		std::array<T, S> val;
		Vec();
		Vec(const Vec<S, T>& Other);
		Vec(Vec<S, T>&& Other);
		Vec(T Value);
		Vec(std::initializer_list<T> List);
		void Set(const Vec<S, T>& Other);
		void Set(T Value);
		void Set(std::initializer_list<T> List);
		Vec<S, T>  operator - () const;
        Vec<S, T>& operator =  (const Vec<S, T>& V);
        Vec<S, T>& operator =  (Vec<S, T>&& Other);
        Vec<S, T>  operator +  (const Vec<S, T>& V) const;
        Vec<S, T>& operator += (const Vec<S, T>& V);
        Vec<S, T>  operator -  (const Vec<S, T>& V) const;
        Vec<S, T>& operator -= (const Vec<S, T>& V);
        Vec<S, T>  operator /  (const Vec<S, T>& V) const;
        Vec<S, T>& operator /= (const Vec<S, T>& V);
        Vec<S, T>  operator *  (const Vec<S, T>& V) const;
        Vec<S, T>& operator *= (const Vec<S, T>& V);
        Vec<S, T>& operator =  (const T& Val);
        Vec<S, T>  operator +  (const T& Val) const;
        Vec<S, T>& operator += (const T& Val);
        Vec<S, T>  operator -  (const T& Val) const;
        Vec<S, T>& operator -= (const T& Val);
        Vec<S, T>  operator /  (const T& Val) const;
        Vec<S, T>& operator /= (const T& Val);
        Vec<S, T>  operator *  (const T& Val) const;
        Vec<S, T>& operator *= (const T& Val);
        bool operator != (const Vec<S, T>& V) const;
        bool operator == (const Vec<S, T>& V) const;
        Vec<S, T>& Normalize();
        Vec<S, T>& Scale(const T Val);
        float Length() const;
        T LengthSqrd() const;
		template <class V/*, typename std::enable_if<(S == 2)>::type*/>
		inline explicit operator Vec2<V>() const {
			return ffw::Vec2<V>((V)val[0], (V)val[1]);
		}
		template <class V/*, typename std::enable_if<(S == 3)>::type*/>
		inline explicit operator Vec3<V>() const {
			return ffw::Vec2<V>((V)val[0], (V)val[1], (V)val[2]);
		}
		template <class V/*, typename std::enable_if<(S == 4)>::type*/>
		inline explicit operator Vec4<V>() const {
			return ffw::Vec2<V>((V)val[0], (V)val[1], (V)val[2], (V)val[3]);
		}
	};
};
#include "VecX.inl"
#endif
