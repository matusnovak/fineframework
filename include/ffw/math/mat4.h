/* This file is part of FineFramework project */
#ifndef FFW_Mat4x4
#define FFW_Mat4x4

namespace ffw {
    template <class T> struct Mat4x4 {
    public:
		T ptr[16];
        Mat4x4();
        Mat4x4(T xx, T yx, T zx, T wx, T xy, T yy, T zy, T wy, T xz, T yz, T zz, T wz, T xw, T yw, T zw, T ww);
        Mat4x4(T Val);
        Mat4x4(std::initializer_list<T> List);
        inline void Set(T xx, T yx, T zx, T wx, T xy, T yy, T zy, T wy, T xz, T yz, T zz, T wz, T xw, T yw, T zw, T ww);
        void Set(T m[16]);
        void Set(T Val);
        void Set(std::initializer_list<T> List);
        T* GetPtr();
		const T* GetPtr() const;
        Mat4x4<T>& operator = (const Mat4x4<T>& m);
        Mat4x4<T> operator * (const Mat4x4<T>& m) const;
        Mat4x4<T>& operator *= (const Mat4x4<T>& m);
		template <class S> Vec4<S> operator * (const Vec4<S>& V) const;
		template <class S> Vec3<S> operator * (const Vec3<S>& V) const;
        T& operator [] (int x);
        const T& operator [] (int x) const;
		Mat4x4<T>& Rotate(const Quat<T>& Q);
		Mat4x4<T>& Translate(T X, T Y, T Z);
		Mat4x4<T>& Scale(T X, T Y, T Z);
		Mat4x4<T>& Transpose();
		Mat4x4<T>& Inverse();
    };
	typedef Mat4x4<float> Mat4x4f;
};
#include "mat4.inl"
#endif
