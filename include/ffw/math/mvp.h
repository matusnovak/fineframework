/* This file is part of FineFramework project */
#ifndef FFW_MODEL_VIEW_PROJECTION
#define FFW_MODEL_VIEW_PROJECTION
#include "../config.h"
#include "mat4.h"

namespace ffw {
    /**
    * @ingroup math
    */
    template <class T>
    inline ffw::Mat4x4<T> makeRotationMatrix(const ffw::Quat<T>& Q) {
        Mat4x4<T> m;
        m[0] = 1.0f - 2.0f * (Q.y * Q.y + Q.z * Q.z);    m[4] = 2.0f * (Q.x * Q.y + Q.z * Q.w);         m[8] = 2.0f * (Q.x * Q.z - Q.y * Q.w);
        m[1] = 2.0f * (Q.x * Q.y - Q.z * Q.w);           m[5] = 1.0f - 2.0f * (Q.x * Q.x + Q.z * Q.z);  m[9] = 2.0f * (Q.y * Q.z + Q.x * Q.w);
        m[2] = 2.0f * (Q.x * Q.z + Q.y * Q.w);           m[6] = 2.0f * (Q.y * Q.z - Q.x * Q.w);         m[10] = 1.0f - 2.0f * (Q.x * Q.x + Q.y * Q.y);
        return m;
    }
    /**
    * @ingroup math
    */
    template <class T>
    inline ffw::Mat4x4<T> getRotationMatrix(const ffw::Mat4x4<T>& other){
    }
    /**
    * @ingroup math
    */
    template<typename T>
    Mat4x4<T> makeProjectionMatrix(T FieldOfView, T Aspect, T Near, T Far) {
        T halfFov = FieldOfView / 2;
        T tanFov = (T)tan(halfFov*DEG_TO_RAD);
        ffw::Mat4x4<T> mat;
        mat.ptr[0] = 1 / (Aspect * tanFov);
        mat.ptr[5] = 1 / tanFov;
        mat.ptr[10] = (Near + Far) / (Near - Far);
        mat.ptr[11] = -1;
        mat.ptr[14] = (2 * Far * Near) / (Near - Far);
        return mat;
    }
    /**
    * @ingroup math
    */
    template<typename T>
    Mat4x4<T> makeLookAtMatrix(const Vec3<T>& Eyes, const Vec3<T>& Target, const Vec3<T>& UpVector) {
        Mat4x4<T> mat;
        Vec3<T> f = ffw::normalize(Target - Eyes);
        Vec3<T> s = ffw::normalize(ffw::cross(f, UpVector));
        Vec3<T> u = ffw::cross(s, f);
        mat[0] = s.x;
        mat[4] = s.y;
        mat[8] = s.z;
        mat[3] = 0;
        mat[1] = u.x;
        mat[5] = u.y;
        mat[9] = u.z;
        mat[7] = 0;
        mat[2] = -f.x;
        mat[6] = -f.y;
        mat[10] = -f.z;
        mat[11] = 0;
        mat[12] = -ffw::dot(s, Eyes);
        mat[13] = -ffw::dot(u, Eyes);
        mat[14] = ffw::dot(f, Eyes);
        mat[15] = 1;
        return mat;
    }
    /**
    * @ingroup math
    */
    template<typename T>
    Mat4x4<T> makeFpsCameraMatrix(const Vec3<T>& Eyes, float Pitch, float Yaw) {
        T cPitch = (T)cos(Pitch*DEG_TO_RAD);
        T sPitch = (T)sin(Pitch*DEG_TO_RAD);
        T cYaw = (T)cos(Yaw*DEG_TO_RAD);
        T sYaw = (T)sin(Yaw*DEG_TO_RAD);
        ffw::Mat4x4<T> mat;
        ffw::Vec3<T> s(cYaw, 0, -sYaw);
        ffw::Vec3<T> u(sYaw * sPitch, cPitch, cYaw * sPitch);
        ffw::Vec3<T> f(sYaw * cPitch, -sPitch, cPitch * cYaw);
        mat[0] = s.x;
        mat[4] = s.y;
        mat[8] = s.z;
        mat[3] = 0;
        mat[1] = u.x;
        mat[5] = u.y;
        mat[9] = u.z;
        mat[7] = 0;
        mat[2] = -f.x;
        mat[6] = -f.y;
        mat[10] = -f.z;
        mat[11] = 0;
        mat[12] = -ffw::dot(s, Eyes);
        mat[13] = -ffw::dot(u, Eyes);
        mat[14] = ffw::dot(f, Eyes);
        mat[15] = 1;
        return mat;
    }
    /**
    * @ingroup math
    */
    template<typename T>
    Mat4x4<T> makeOrthoMatrix(T left, T right, T bottom, T top, T znear, T zfar) {
        ffw::Mat4x4<T> mat;
        mat[0] = (T)(2) / (right - left);        mat[4] = 0;                                mat[8] = 0;   mat[12] = -(right + left) / (right - left);
        mat[1] = 0;                                mat[5] = (T)(2) / (top - bottom);        mat[9] = 0;   mat[13] = -(top + bottom) / (top - bottom);
        mat[2] = 0;                                mat[6] = 0;                                mat[10] = (T)(1) / (zfar - znear);  mat[14] = -znear / (zfar - znear);
        mat[3] = 0;                                mat[7] = 0;                                mat[11] = 0;  mat[15] = 1;
        return mat;
    }
};

#endif