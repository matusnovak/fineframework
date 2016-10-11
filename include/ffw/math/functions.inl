/* This file is part of FineFramework project */
#ifndef FFW_BASE_FUNCTIONS_INL
#define FFW_BASE_FUNCTIONS_INL
//==============================================================================
template <class T>
inline T ffw::Lerp(const T& A, const T& B, float Weight) {
    return (1-Weight)*A + Weight*B;
}
//==============================================================================
template <class T>
inline float Dot(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2){
    return (V1.x*V2.x + V1.y*V2.y);
}
//==============================================================================
template <class T>
inline float ffw::Dot(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2){
    return (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T> ffw::Cross(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2){
    ffw::Vec3<T> product;
    product.x = V1.y*V2.z - V1.z*V2.y;
    product.y = V1.z*V2.x - V1.x*V2.z;
    product.z = V1.x*V2.y - V1.y*V2.x;
    return product;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T> ffw::Normalize(const Vec2<T>& V){
    ffw::Vec2<T> result;
    float l = sqrtf(V.x*V.x + V.y*V.y);
    if( l > 0 ) {
        result.x = V.x/l;
        result.y = V.y/l;
    }
    return result;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T> ffw::Normalize(const Vec3<T>& V){
    ffw::Vec3<T> result;
    float l = sqrtf(V.x*V.x + V.y*V.y + V.z*V.z);
    if( l > 0 ) {
        result.x = V.x/l;
        result.y = V.y/l;
        result.z = V.z/l;
    }
    return result;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T> ffw::Normalize(const Vec4<T>& V){
    ffw::Vec4<T> result;
    float l = sqrtf(V.x*V.x + V.y*V.y + V.z*V.z + V.w*V.w);
    if( l > 0 ) {
        result.x = V.x/l;
        result.y = V.y/l;
        result.z = V.z/l;
        result.w = V.w/l;
    }
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Normalize(const Quat<T>& Q){
    ffw::Quat<T> result;
    float n = 1.0f/sqrt(Q.x*Q.x+Q.y*Q.y+Q.z*Q.z+Q.w*Q.w);
    result.x = Q.x * n;
    result.y = Q.y * n;
    result.z = Q.z * n;
    result.w = Q.w * n;
    return result;
}
//==============================================================================
template <class T>
inline float ffw::Angle(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2){
    float dot = (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
    float V1Length = sqrtf(V1.x*V1.x + V1.y*V1.y + V1.z*V1.z);
    float V2Length = sqrtf(V2.x*V2.x + V2.y*V2.y + V2.z*V2.z);
    return acos(dot / (V1Length*V2Length))*57.29577951;
}
//==============================================================================
template <class T>
inline float ffw::Angle(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2){
    float dot = (V1.x*V2.x + V1.y*V2.y);
    float V1Length = sqrtf(V1.x*V1.x + V1.y*V1.y);
    float V2Length = sqrtf(V2.x*V2.x + V2.y*V2.y);
    return acos(dot / (V1Length*V2Length))*57.29577951;
}
//==============================================================================
template <class T>
inline float ffw::AngleRad(const ffw::Vec3<T>& V1, const ffw::Vec3<T>& V2){
    float dot = (V1.x*V2.x + V1.y*V2.y + V1.z*V2.z);
    float V1Length = sqrtf(V1.x*V1.x + V1.y*V1.y + V1.z*V1.z);
    float V2Length = sqrtf(V2.x*V2.x + V2.y*V2.y + V2.z*V2.z);
    return acos(dot / (V1Length*V2Length));
}
//==============================================================================
template <class T>
inline float ffw::AngleRad(const ffw::Vec2<T>& V1, const ffw::Vec2<T>& V2){
    float dot = (V1.x*V2.x + V1.y*V2.y);
    float V1Length = sqrtf(V1.x*V1.x + V1.y*V1.y);
    float V2Length = sqrtf(V2.x*V2.x + V2.y*V2.y);
    return acos(dot / (V1Length*V2Length));
}
//==============================================================================
template<class T>
inline T ffw::Clamp(T Val, T Min, T Max){
    return std::max(Min, std::min(Val, Max));
}
//==============================================================================
template<class T>
inline T ffw::Remap(T Value, T InMin, T InMax, T OutMin, T OutMax){
    return (Value - InMin) / (InMax - InMin) * (OutMax - OutMin) + OutMin;
}
//==============================================================================
inline unsigned long ffw::NextPowOfTwo(unsigned long Value){
    unsigned long P = 1;
    while(P < Value){
        P *= 2;
    }
    return P;
}
//==============================================================================
template <class T>
inline ffw::Mat4x4<T> ffw::MakeRotationMatrix(const ffw::Quat<T>& Q){
    Mat4x4<T> m;
    m[0] = 1.0f - 2.0f * (Q.y * Q.y + Q.z * Q.z);    m[4] = 2.0f * (Q.x * Q.y + Q.z * Q.w);         m[8] = 2.0f * (Q.x * Q.z - Q.y * Q.w);
    m[1] = 2.0f * (Q.x * Q.y - Q.z * Q.w);           m[5] = 1.0f - 2.0f * (Q.x * Q.x + Q.z * Q.z);  m[9] = 2.0f * (Q.y * Q.z + Q.x * Q.w);
    m[2] = 2.0f * (Q.x * Q.z + Q.y * Q.w);           m[6] = 2.0f * (Q.y * Q.z - Q.x * Q.w);         m[10] = 1.0f - 2.0f * (Q.x * Q.x + Q.y * Q.y);
    return m;
}
//==============================================================================
template<class T>
inline ffw::Vec3<T> ffw::Vec2ToVec3(const Vec2<T>& Vec){
    return Vec3<T>(Vec.x, Vec.y, 0);
}
//==============================================================================
template<class T>
inline ffw::Vec4<T> ffw::Vec3ToVec4(const ffw::Vec3<T>& Vec){
    return Vec4<T>(Vec.x, Vec.y, Vec.z, 0);
}
//==============================================================================
template<class T>
inline ffw::Vec3<T> ffw::Vec2ToVec3(const ffw::Vec2<T>& Vec, T Z){
    return Vec3<T>(Vec.x, Vec.y, Z);
}
//==============================================================================
template<class T>
inline ffw::Vec4<T> ffw::Vec3ToVec4(const ffw::Vec3<T>& Vec, T W){
    return Vec4<T>(Vec.x, Vec.y, Vec.z, W);
}
//==============================================================================
template<class T>
inline ffw::Vec3<T> ffw::Vec4ToVec3(const ffw::Vec4<T>& Vec){
    return Vec3<T>(Vec.x, Vec.y, Vec.z);
}
//==============================================================================
template<class T>
inline ffw::Vec2<T> ffw::Vec3ToVec2(const ffw::Vec3<T>& Vec){
    return Vec3<T>(Vec.x, Vec.y);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T> ffw::QuatToVec3(const ffw::Quat<T>& Quat){
    return Vec3<T>(Quat.x, Quat.y, Quat.z);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T> ffw::QuatToVec4(const ffw::Quat<T>& Quat){
    return Vec4<T>(Quat.x, Quat.y, Quat.z, Quat.w);
}
//==============================================================================
template<class T>
ffw::Quat<T> ffw::Vec4ToQuat(const ffw::Vec4<T>& Vec){
    return Quaternion(Vec.x, Vec.y, Vec.z, Vec.w);
}
//==============================================================================
#ifdef FFW_WINDOWS_MSVC
inline unsigned short ffw::ByteSwap16(unsigned short Value){
	return _byteswap_ushort(Value);
}
inline unsigned long ffw::ByteSwap32(unsigned long Value){
	return _byteswap_ulong(Value);
}
inline unsigned long long ffw::ByteSwap64(unsigned long long Value){
	return _byteswap_uint64(Value);
}
#else
inline unsigned short ffw::ByteSwap16(unsigned short Value){
	return __builtin_bswap16(Value);
}
inline unsigned long ffw::ByteSwap32(unsigned long Value){
	return __builtin_bswap32(Value);
}
inline unsigned long long ffw::ByteSwap64(unsigned long long Value){
	return __builtin_bswap64(Value);
}
#endif
//==============================================================================
template <class T>
inline std::ostream& ffw::operator << (std::ostream& os, const ffw::Vec2<T>& V){
    os << V.x << ", " << V.y;
    return os;
}
//==============================================================================
template <class T>
inline std::ostream& ffw::operator << (std::ostream& os, const ffw::Vec3<T>& V){
    os << V.x << ", " << V.y << ", " << V.z;
    return os;
}
//==============================================================================
template <class T>
inline std::ostream& ffw::operator << (std::ostream& os, const ffw::Vec4<T>& V){
    os << V.x << ", " << V.y << ", " << V.z << ", " << V.w;
    return os;
}
//==============================================================================
template <class T>
inline std::ostream& ffw::operator << (std::ostream& os, const ffw::Quat<T>& Q){
    os << Q.x << ", " << Q.y << ", " << Q.z << ", " << Q.w;
    return os;
}
//==============================================================================
inline std::ostream& ffw::operator << (std::ostream& os, const ffw::Color& C){
    os << C.r << ", " << C.g << ", " << C.b << ", " << C.a;
    return os;
}
//==============================================================================
inline ffw::Mat4x4f ffw::MakeProjectionMatrix(float FieldOfView, float Aspect, float Near, float Far){
    float halfFov = FieldOfView/2.0f;
	float tanFov = tanf(halfFov*(float)DEG_TO_RAD);
    ffw::Mat4x4f mat;
    mat.ptr[0] = 1.0f / (Aspect * tanFov);
    mat.ptr[5] = 1.0f / tanFov;
    mat.ptr[10] = (Near + Far) / (Near - Far);
    mat.ptr[11] = -1.0f;
    mat.ptr[14] = (2.0f * Far * Near) / (Near - Far);
    return mat;
}
//==============================================================================
inline ffw::Mat4x4f ffw::MakeLookAtMatrix(const ffw::Vec3f& Eyes, const ffw::Vec3f& Target, const ffw::Vec3f& UpVector){
    ffw::Mat4x4f mat;
    ffw::Vec3f f = ffw::Normalize(Target - Eyes);
    ffw::Vec3f s = ffw::Normalize(ffw::Cross(f, UpVector));
    ffw::Vec3f u = ffw::Cross(s, f);
    mat[0]  =  s.x;
    mat[4]  =  s.y;
    mat[8]  =  s.z;
    mat[3]  =  0.0f;
    mat[1]  =  u.x;
    mat[5]  =  u.y;
    mat[9]  =  u.z;
    mat[7]  =  0.0f;
    mat[2]  = -f.x;
    mat[6]  = -f.y;
    mat[10] = -f.z;
    mat[11] =  0.0f;
    mat[12] = -ffw::Dot(s, Eyes);
    mat[13] = -ffw::Dot(u, Eyes);
    mat[14] =  ffw::Dot(f, Eyes);
    mat[15] =  1.0f;
    return mat;
}
//==============================================================================
inline ffw::Mat4x4f ffw::MakeFpsCameraMatrix(const ffw::Vec3f& Eyes, float Pitch, float Yaw){
	float cPitch = (float)cos(Pitch*DEG_TO_RAD);
	float sPitch = (float)sin(Pitch*DEG_TO_RAD);
	float cYaw = (float)cos(Yaw*DEG_TO_RAD);
	float sYaw = (float)sin(Yaw*DEG_TO_RAD);
    ffw::Mat4x4f mat;
    ffw::Vec3f s(cYaw, 0, -sYaw);
    ffw::Vec3f u(sYaw * sPitch, cPitch, cYaw * sPitch);
    ffw::Vec3f f(sYaw * cPitch, -sPitch, cPitch * cYaw);
    mat[0]  =  s.x;
    mat[4]  =  s.y;
    mat[8]  =  s.z;
    mat[3]  =  0.0f;
    mat[1]  =  u.x;
    mat[5]  =  u.y;
    mat[9]  =  u.z;
    mat[7]  =  0.0f;
    mat[2]  = -f.x;
    mat[6]  = -f.y;
    mat[10] = -f.z;
    mat[11] =  0.0f;
    mat[12] = -ffw::Dot(s, Eyes);
    mat[13] = -ffw::Dot(u, Eyes);
    mat[14] =  ffw::Dot(f, Eyes);
    mat[15] =  1.0f;
    return mat;
}
#endif
