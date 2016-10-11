/* This file is part of FineFramework project */
//==============================================================================
template <class T>
inline ffw::Vec4<T>::Vec4(){
    x = 0;
    y = 0;
    z = 0;
    w = 0;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>::Vec4(T X, T Y, T Z, T W){
    x = X;
    y = Y;
    z = Z;
    w = W;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>::Vec4(T Value){
    x = Value;
    y = Value;
    z = Value;
    w = Value;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>::Vec4(const Vec4<T>& V){
    x = V.x;
    y = V.y;
    z = V.z;
    w = V.w;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>::Vec4(std::initializer_list<T> List){
    if(List.size() != 4){
        x = 0;
        y = 0;
        z = 0;
        w = 0;
        return;
    }
    x = *(List.begin());
    y = *(List.begin()+1);
    z = *(List.begin()+2);
    w = *(List.begin()+3);
}
//==============================================================================
template <class T>
inline void ffw::Vec4<T>::Set(T X, T Y, T Z, T W){
    x = X;
    y = Y;
    z = Z;
    w = W;
}
//==============================================================================
template <class T>
inline void ffw::Vec4<T>::Set(T Value){
    x = Value;
    y = Value;
    z = Value;
    w = Value;
}
//==============================================================================
template <class T>
inline void ffw::Vec4<T>::Set(const Vec4<T>& V){
    x = V.x;
    y = V.y;
    z = V.z;
    w = V.w;
}
//==============================================================================
template <class T>
inline void ffw::Vec4<T>::Set(std::initializer_list<T> List){
    if(List.size() != 4)return;
    x = *(List.begin());
    y = *(List.begin()+1);
    z = *(List.begin()+2);
    w = *(List.begin()+3);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator - () const{
    return Vec4<T>(-x, -y, -z, -w);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator =  (const Vec4<T>& V){
    x = V.x;
    y = V.y;
    z = V.z;
    w = V.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator +  (const Vec4<T>& V) const{
    return Vec4<T>(x + V.x, y + V.y, z + V.z, w + V.w);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator += (const Vec4<T>& V){
    x += V.x;
    y += V.y;
    z += V.z;
    w += V.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator -  (const Vec4<T>& V) const{
    return Vec4<T>(x - V.x, y - V.y, z - V.z, w - V.w);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator -= (const Vec4<T>& V){
    x -= V.x;
    y -= V.y;
    z -= V.z;
    w -= V.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator /  (const Vec4<T>& V) const{
    return Vec4<T>(x / V.x, y / V.y, z / V.z, w / V.w);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator /= (const Vec4<T>& V){
    x /= V.x;
    y /= V.y;
    z /= V.z;
    w /= V.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator *  (const Vec4<T>& V) const{
    return Vec4<T>(x * V.x, y * V.y, z * V.z, w * V.w);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator *= (const Vec4<T>& V){
    x *= V.x;
    y *= V.y;
    z *= V.z;
    w *= V.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator =  (const T& Val){
    x = Val;
    y = Val;
    z = Val;
    w = Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator +  (const T& Val) const{
    return Vec4<T>(x + Val, y + Val, z + Val, w + Val);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator += (const T& Val){
    x += Val;
    y += Val;
    z += Val;
    w += Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator -  (const T& Val) const{
    return Vec4<T>(x - Val, y - Val, z - Val, w - Val);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator -= (const T& Val){
    x -= Val;
    y -= Val;
    z -= Val;
    w -= Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator /  (const T& Val) const{
    return Vec4<T>(x / Val, y / Val, z / Val, w / Val);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator /= (const T& Val){
    x /= Val;
    y /= Val;
    z /= Val;
    w /= Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>  ffw::Vec4<T>::operator *  (const T& Val) const{
    return Vec4<T>(x * Val, y * Val, z * Val, w * Val);
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::operator *= (const T& Val){
    x *= Val;
    y *= Val;
    z *= Val;
    w *= Val;
    return *this;
}
//==============================================================================
template <class T>
inline bool ffw::Vec4<T>::operator != (const Vec4<T>& V) const{
    return !(*this == V);
}
//==============================================================================
template <typename T>
inline bool ffw::Vec4<T>::operator == (const Vec4<T>& V) const{
    return (x == V.x && y == V.y && z == V.z && w == V.w);
}
//==============================================================================
namespace ffw {
    template <>
    inline bool ffw::Vec4<float>::operator == (const Vec4<float>& V) const{
        if(std::abs(x - V.x) > std::numeric_limits<float>::epsilon())return false;
        if(std::abs(y - V.y) > std::numeric_limits<float>::epsilon())return false;
        if(std::abs(z - V.z) > std::numeric_limits<float>::epsilon())return false;
        if(std::abs(w - V.w) > std::numeric_limits<float>::epsilon())return false;
        return true;
    }

    template <>
    inline bool ffw::Vec4<double>::operator == (const Vec4<double>& V) const{
        if(std::abs(x - V.x) > std::numeric_limits<double>::epsilon())return false;
        if(std::abs(y - V.y) > std::numeric_limits<double>::epsilon())return false;
        if(std::abs(z - V.z) > std::numeric_limits<double>::epsilon())return false;
        if(std::abs(w - V.w) > std::numeric_limits<double>::epsilon())return false;
        return true;
    }
};
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::Normalize(){
    float l = sqrtf(x*x + y*y + z*z + w*w);
    if( l > 0 ) {
        x = x/l;
        y = y/l;
        z = z/l;
        w = w/l;
    }
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec4<T>& ffw::Vec4<T>::Scale(const T Val){
    x = x*Val;
    y = y*Val;
    z = z*Val;
    w = w*Val;
    return *this;
}
//==============================================================================
template <class T>
inline float ffw::Vec4<T>::Length() const{
    return sqrtf(x*x + y*y + z*z + w*w);
}
//==============================================================================
template <class T>
inline T ffw::Vec4<T>::LengthSqrd() const{
    return (x*x + y*y + z*z + w*w);
}
//==============================================================================
template <class T>
template <class S>
inline ffw::Vec4<T>::operator ffw::Vec4<S>() const {
    return ffw::Vec4<S>((S)x, (S)y, (S)z, (S)w);
}
