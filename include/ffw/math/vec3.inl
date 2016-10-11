/* This file is part of FineFramework project */
//==============================================================================
template <class T>
inline ffw::Vec3<T>::Vec3(){
    x = 0;
    y = 0;
    z = 0;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>::Vec3(T X, T Y, T Z){
    x = X;
    y = Y;
    z = Z;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>::Vec3(T Value){
    x = Value;
    y = Value;
    z = Value;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>::Vec3(const Vec3<T>& V){
    x = V.x;
    y = V.y;
    z = V.z;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>::Vec3(std::initializer_list<T> List){
    if(List.size() != 3){
        x = 0;
        y = 0;
        z = 0;
        return;
    }
    x = *(List.begin());
    y = *(List.begin()+1);
    z = *(List.begin()+2);
}
//==============================================================================
template <class T>
inline void ffw::Vec3<T>::Set(T X, T Y, T Z){
    x = X;
    y = Y;
    z = Z;
}
//==============================================================================
template <class T>
inline void ffw::Vec3<T>::Set(T Value){
    x = Value;
    y = Value;
    z = Value;
}
//==============================================================================
template <class T>
inline void ffw::Vec3<T>::Set(const Vec3<T>& V){
    x = V.x;
    y = V.y;
    z = V.z;
}
//==============================================================================
template <class T>
inline void ffw::Vec3<T>::Set(std::initializer_list<T> List){
    if(List.size() != 3)return;
    x = *(List.begin());
    y = *(List.begin()+1);
    z = *(List.begin()+2);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator - () const{
    return Vec3<T>(-x, -y, -z);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator =  (const Vec3<T>& V){
    x = V.x;
    y = V.y;
    z = V.z;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator +  (const Vec3<T>& V) const{
    return Vec3<T>(x + V.x, y + V.y, z + V.z);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator += (const Vec3<T>& V){
    x += V.x;
    y += V.y;
    z += V.z;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator -  (const Vec3<T>& V) const{
    return Vec3<T>(x - V.x, y - V.y, z - V.z);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator -= (const Vec3<T>& V){
    x -= V.x;
    y -= V.y;
    z -= V.z;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator /  (const Vec3<T>& V) const{
    return Vec3<T>(x / V.x, y / V.y, z / V.z);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator /= (const Vec3<T>& V){
    x /= V.x;
    y /= V.y;
    z /= V.z;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator *  (const Vec3<T>& V) const{
    return Vec3<T>(x * V.x, y * V.y, z * V.z);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator *= (const Vec3<T>& V){
    x *= V.x;
    y *= V.y;
    z *= V.z;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator =  (const T& Val){
    x = Val;
    y = Val;
    z = Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator +  (const T& Val) const{
    return Vec3<T>(x + Val, y + Val, z + Val);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator += (const T& Val){
    x += Val;
    y += Val;
    z += Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator -  (const T& Val) const{
    return Vec3<T>(x - Val, y - Val, z - Val);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator -= (const T& Val){
    x -= Val;
    y -= Val;
    z -= Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator /  (const T& Val) const{
    return Vec3<T>(x / Val, y / Val, z / Val);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator /= (const T& Val){
    x /= Val;
    y /= Val;
    z /= Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>  ffw::Vec3<T>::operator *  (const T& Val) const{
    return Vec3<T>(x * Val, y * Val, z * Val);
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::operator *= (const T& Val){
    x *= Val;
    y *= Val;
    z *= Val;
    return *this;
}
//==============================================================================
template <class T>
inline bool ffw::Vec3<T>::operator != (const Vec3<T>& V) const{
    return !(*this == V);
}
//==============================================================================
template <typename T>
inline bool ffw::Vec3<T>::operator == (const Vec3<T>& V) const{
    return (x == V.x && y == V.y && z == V.z);
}
//==============================================================================
namespace ffw {
    template <>
    inline bool Vec3<float>::operator == (const Vec3<float>& V) const{
        if(fabs(x - V.x) > std::numeric_limits<float>::epsilon())return false;
        if(fabs(y - V.y) > std::numeric_limits<float>::epsilon())return false;
        if(fabs(z - V.z) > std::numeric_limits<float>::epsilon())return false;
        return true;
    }

    template <>
    inline bool Vec3<double>::operator == (const Vec3<double>& V) const{
        if(fabs(x - V.x) > std::numeric_limits<double>::epsilon())return false;
        if(fabs(y - V.y) > std::numeric_limits<double>::epsilon())return false;
        if(fabs(z - V.z) > std::numeric_limits<double>::epsilon())return false;
        return true;
    }
};
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateByAxis(const float Deg, Vec3<T> Axis){
    //Axis.normalize();
    float rad = Deg*0.01745329251;
    float sina = sin(rad);
    float cosa = cos(rad);
    float cosb = 1.0f - cosa;
    Vec3<T> v = *this;
    x = v.x*(Axis.x*Axis.x*cosb + cosa)        + v.y*(Axis.x*Axis.y*cosb - Axis.z*sina) + v.z*(Axis.x*Axis.z*cosb + Axis.y*sina);
    y = v.x*(Axis.y*Axis.x*cosb + Axis.z*sina) + v.y*(Axis.y*Axis.y*cosb + cosa)        + v.z*(Axis.y*Axis.z*cosb - Axis.x*sina);
    z = v.x*(Axis.z*Axis.x*cosb - Axis.y*sina) + v.y*(Axis.z*Axis.y*cosb + Axis.x*sina) + v.z*(Axis.z*Axis.z*cosb + cosa);
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateX(const float Deg){
    T vy = y;
    T vz = z;
    //x = vx;
    y = static_cast<T>(cos(Deg*0.01745329251f))*vy - static_cast<T>(sin(Deg*0.01745329251f))*vz;
    z = static_cast<T>(sin(Deg*0.01745329251f))*vy + static_cast<T>(cos(Deg*0.01745329251f))*vz;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateY(const float Deg){
    T vx = x;
    T vz = z;
    x = static_cast<T>(cos(Deg*0.01745329251f))*vx + static_cast<T>(sin(Deg*0.01745329251f))*vz;
    //y = vy;
    z = static_cast<T>(-sin(Deg*0.01745329251f))*vx + static_cast<T>(cos(Deg*0.01745329251f))*vz;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateZ(const float Deg){
    T vx = x;
    T vy = y;
    x = static_cast<T>(cos(Deg*0.01745329251f))*vx - static_cast<T>(sin(Deg*0.01745329251f))*vy;
    y = static_cast<T>(sin(Deg*0.01745329251f))*vx + static_cast<T>(cos(Deg*0.01745329251f))*vy;
    //z = vz;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateXRad(const float Rad){
    T vy = y;
    T vz = z;
    //x = vx;
    y = static_cast<T>(cos(Rad))*vy - static_cast<T>(sin(Rad))*vz;
    z = static_cast<T>(sin(Rad))*vy + static_cast<T>(cos(Rad))*vz;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateYRad(const float Rad){
    T vx = x;
    T vz = z;
    x = static_cast<T>(cos(Rad))*vx + static_cast<T>(sin(Rad))*vz;
    //y = vy;
    z = static_cast<T>(-sin(Rad))*vx + static_cast<T>(cos(Rad))*vz;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateZRad(const float Rad){
    T vx = x;
    T vy = y;
    x = static_cast<T>(cos(Rad))*vx - static_cast<T>(sin(Rad))*vy;
    y = static_cast<T>(sin(Rad))*vx + static_cast<T>(cos(Rad))*vy;
    //z = vz;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::RotateByQuaternion(const ffw::Quat<T>& Q){
    /*float oldX = x;
    float oldY = y;
    float oldZ = z;
    x = (1.0f - 2.0f*Q.y*Q.y - 2.0f*Q.z*Q.z)*oldX +     (2.0f*Q.x*Q.y - 2.0f*Q.z*Q.w)   *oldY +    (2.0f*Q.x*Q.z + 2.0f*Q.y*Q.w)    *oldZ;
    y =    (2.0f*Q.x*Q.y + 2.0f*Q.z*Q.w)    *oldX + (1.0f - 2.0f*Q.x*Q.x - 2.0f*Q.z*Q.z)*oldY +    (2.0f*Q.y*Q.z - 2.0f*Q.x*Q.w)    *oldZ;
    y =    (2.0f*Q.x*Q.z - 2.0f*Q.y*Q.w)    *oldX +    (2.0f*Q.y*Q.z + 2.0f*Q.x*Q.w)    *oldY + (1.0f - 2.0f*Q.x*Q.x - 2.0f*Q.y*Q.y)*oldZ;
    return *this;*/
    /*ofVec3f uv, uuv;
    ofVec3f qvec(_v.x, _v.y, _v.z);
    uv = qvec.getCrossed(v);
    uuv = qvec.getCrossed(uv);
    uv *= (2.0f * _v.w);
    uuv *= 2.0f;
    return v + uv + uuv;*/
    ffw::Vec3f qvc;
    qvc.x = Q.y*z - Q.z*y;
    qvc.y = Q.z*x - Q.x*z;
    qvc.z = Q.x*y - Q.y*x;
    ffw::Vec3f qvcc;
    qvcc.x = Q.y*qvc.z - Q.z*qvc.y;
    qvcc.y = Q.z*qvc.x - Q.x*qvc.z;
    qvcc.z = Q.x*qvc.y - Q.y*qvc.x;
    qvc *= (2.0f * Q.w);
    qvcc *= 2.0f;
    *this += qvc + qvcc;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::Normalize(){
    float l = sqrtf(x*x + y*y + z*z);
    if( l > 0 ) {
        x = x/l;
        y = y/l;
        z = z/l;
    }
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec3<T>& ffw::Vec3<T>::Scale(const T Val){
    x = x*Val;
    y = y*Val;
    z = z*Val;
    return *this;
}
//==============================================================================
template <class T>
inline float ffw::Vec3<T>::Length() const{
    return sqrtf(x*x + y*y + z*z);
}
//==============================================================================
template <class T>
inline T ffw::Vec3<T>::LengthSqrd() const{
    return (x*x + y*y + z*z);
}
//==============================================================================
template <class T>
template <class S>
inline ffw::Vec3<T>::operator ffw::Vec3<S>() const {
    return ffw::Vec3<S>((S)x, (S)y, (S)z);
}
