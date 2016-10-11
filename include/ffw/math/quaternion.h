/* This file is part of FineFramework project */
#ifndef FFW_Quat
#define FFW_Quat

namespace ffw {
	/**
	 * @ingroup math
	 */
    template <class T> struct Quat {
    public:
        T x;
        T y;
        T z;
        T w;
        Quat();
        Quat(T X, T Y, T Z, T W);
        Quat(const Quat<T>& Quat);
        void Set(T X, T Y, T Z, T W);
        void Set(const Quat<T>& Quat);
        Quat& rotate(T Deg, T X, T Y, T Z);
        Quat& rotateRad(T Rad, T X, T Y, T Z);
        Quat operator - () const;
        Quat  operator * (const Quat& Quat) const;
        Quat& operator *= (const Quat& Quat);
        Quat  operator * (T Value) const;
        Quat& operator *= (T Value);
        Quat  operator + (const Quat& Quat) const;
        Quat& operator += (const Quat& Quat);
        Quat  operator - (const Quat& Quat) const;
        Quat& operator -= (const Quat& Quat);
        Quat  operator / (T Value) const;
        Quat& operator /= (T Value);
        void normalize();
        void getEuler(T* Roll, T* Pitch, T* Yaw) const;
        float Length() const;
        float LengthSqrd() const;
		Quat getConjugate() const;
		Quat getInversed() const;
		Quat& inverse();
    };
	/**
	 * @ingroup math
	 */
	typedef Quat<float> Quatf;
	/**
	 * @ingroup math
	 */
	typedef Quat<double> Quatd;
};
#include "quaternion.inl"
#endif
