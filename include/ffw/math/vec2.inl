/* This file is part of FineFramework project */
//==============================================================================
template <class T>
inline ffw::Vec2<T>::Vec2(){
    x = 0;
    y = 0;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>::Vec2(T X, T Y){
    x = X;
    y = Y;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>::Vec2(T Value){
    x = Value;
    y = Value;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>::Vec2(const Vec2<T>& V){
    x = V.x;
    y = V.y;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>::Vec2(std::initializer_list<T> List){
    if(List.size() != 2){
        x = 0;
        y = 0;
        return;
    }
    x = *(List.begin());
    y = *(List.begin()+1);
}
//==============================================================================
template <class T>
inline void ffw::Vec2<T>::Set(T X, T Y){
    x = X;
    y = Y;
}
//==============================================================================
template <class T>
inline void ffw::Vec2<T>::Set(T Value){
    x = Value;
    y = Value;
}
//==============================================================================
template <class T>
inline void ffw::Vec2<T>::Set(const Vec2<T>& V){
    x = V.x;
    y = V.y;
}
//==============================================================================
template <class T>
inline void ffw::Vec2<T>::Set(std::initializer_list<T> List){
    if(List.size() != 2)return;
    x = *(List.begin());
    y = *(List.begin()+1);
}
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator - () const{
    return Vec2<T>(-x, -y);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator =  (const Vec2<T>& V){
    x = V.x;
    y = V.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator +  (const Vec2<T>& V) const{
    return Vec2<T>(x + V.x, y + V.y);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator += (const Vec2<T>& V){
    x += V.x;
    y += V.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator -  (const Vec2<T>& V) const{
    return Vec2<T>(x - V.x, y - V.y);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator -= (const Vec2<T>& V){
    x -= V.x;
    y -= V.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator /  (const Vec2<T>& V) const{
    return Vec2<T>(x / V.x, y / V.y);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator /= (const Vec2<T>& V){
    x /= V.x;
    y /= V.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator *  (const Vec2<T>& V) const{
    return Vec2<T>(x * V.x, y * V.y);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator *= (const Vec2<T>& V){
    x *= V.x;
    y *= V.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator =  (const T& Val){
    x = Val;
    y = Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator +  (const T& Val) const{
    return Vec2<T>(x + Val, y + Val);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator += (const T& Val){
    x += Val;
    y += Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator -  (const T& Val) const{
    return Vec2<T>(x - Val, y - Val);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator -= (const T& Val){
    x -= Val;
    y -= Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator /  (const T& Val) const{
    return Vec2<T>(x / Val, y / Val);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator /= (const T& Val){
    x /= Val;
    y /= Val;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>  ffw::Vec2<T>::operator *  (const T& Val) const{
    return Vec2<T>(x * Val, y * Val);
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::operator *= (const T& Val){
    x *= Val;
    y *= Val;
    return *this;
}
//==============================================================================
template <class T>
inline bool ffw::Vec2<T>::operator != (const Vec2<T>& V) const{
    return !(*this == V);
}
//==============================================================================
template <typename T>
inline bool ffw::Vec2<T>::operator == (const Vec2<T>& V) const{
    return (x == V.x && y == V.y);
}
//==============================================================================
namespace ffw {
    template <>
    inline bool ffw::Vec2<float>::operator == (const Vec2<float>& V) const{
        if(fabs(x - V.x) > std::numeric_limits<float>::epsilon())return false;
        if(fabs(y - V.y) > std::numeric_limits<float>::epsilon())return false;
        return true;
    }

    template <>
    inline bool ffw::Vec2<double>::operator == (const Vec2<double>& V) const{
        if(fabs(x - V.x) > std::numeric_limits<double>::epsilon())return false;
        if(fabs(y - V.y) > std::numeric_limits<double>::epsilon())return false;
        return true;
    }
};
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::Rotate(const float Deg){
    Vec2<T> v = *this;
    x = static_cast<T>(cos(Deg*0.01745329251))*v.x - static_cast<T>(sin(Deg*0.01745329251))*v.y;
    y = static_cast<T>(sin(Deg*0.01745329251))*v.x + static_cast<T>(cos(Deg*0.01745329251))*v.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::RotateRad(const float Rad){
    Vec2<T> v = *this;
    x = static_cast<T>(cos(Rad))*v.x - static_cast<T>(sin(Rad))*v.y;
    y = static_cast<T>(sin(Rad))*v.x + static_cast<T>(cos(Rad))*v.y;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::Normalize(){
    float l = sqrtf(x*x + y*y);
    if( l > 0 ) {
        x = x/l;
        y = y/l;
    }
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Vec2<T>& ffw::Vec2<T>::Scale(const T Val){
    x = x*Val;
    y = y*Val;
    return *this;
}
//==============================================================================
template <class T>
inline float ffw::Vec2<T>::Length() const{
    return sqrtf(float(x*x + y*y));
}
//==============================================================================
template <class T>
inline T ffw::Vec2<T>::LengthSqrd() const{
    return (x*x + y*y);
}
//==============================================================================
template <class T>
template <class S>
inline ffw::Vec2<T>::operator ffw::Vec2<S>() const {
    return ffw::Vec2<S>((S)x, (S)y);
}
