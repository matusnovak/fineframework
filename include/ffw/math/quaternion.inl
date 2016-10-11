/* This file is part of FineFramework project */
//==============================================================================
template <class T>
inline ffw::Quat<T>::Quat(){
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 1.0f;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>::Quat(T X, T Y, T Z, T W){
    x = X;
    y = Y;
    z = Z;
    w = W;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>::Quat(const Quat& Quat){
    x = Quat.x;
    y = Quat.y;
    z = Quat.z;
    w = Quat.w;
}
//==============================================================================
template <class T>
inline void ffw::Quat<T>::Set(T X, T Y, T Z, T W){
    x = X;
    y = Y;
    z = Z;
    w = W;
}
//==============================================================================
template <class T>
inline void ffw::Quat<T>::Set(const Quat& Quat){
    x = Quat.x;
    y = Quat.y;
    z = Quat.z;
    w = Quat.w;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::rotate(T Deg, T X, T Y, T Z){
    double angle = Deg*DEG_TO_RAD;
    double result = sin(angle/2.0);
    x = float(X * result);
    y = float(Y * result);
    z = float(Z * result);
    w = float(cos(angle/2.0));
    normalize();
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::rotateRad(T Rad, T X, T Y, T Z){
    double result = sin(Rad/2.0);
    x = float(X * result);
    y = float(Y * result);
    z = float(Z * result);
    w = float(cos(Rad/2.0));
    normalize();
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::operator - () const{
    Quat<T> result;
    result.x = -x;
    result.y = -y;
    result.z = -z;
    result.w = -w;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::operator * (const Quat& q) const{
    Quat<T> result;
    result.x = q.w*x + q.x*w + q.y*z - q.z*y;
    result.y = q.w*y - q.x*z + q.y*w + q.z*x;
    result.z = q.w*z + q.x*y - q.y*x + q.z*w;
    result.w = q.w*w - q.x*x - q.y*y - q.z*z;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::operator *= (const Quat& q){
    float rx = q.w*x + q.x*w + q.y*z - q.z*y;
    float ry = q.w*y - q.x*z + q.y*w + q.z*x;
    float rz = q.w*z + q.x*y - q.y*x + q.z*w;
    float rw = q.w*w - q.x*x - q.y*y - q.z*z;
    x = rx;
    y = ry;
    z = rz;
    w = rw;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::operator * (T Value) const{
    Quat result;
    result.x = x*Value;
    result.y = y*Value;
    result.z = z*Value;
    result.w = w*Value;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::operator *= (T Value){
    x *= Value;
    y *= Value;
    z *= Value;
    w *= Value;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::operator + (const Quat& q) const{
    Quat<T> result;
    result.x = x + q.x;
    result.y = y + q.y;
    result.z = z + q.z;
    result.w = w + q.w;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::operator += (const Quat& q){
    x += q.x;
    y += q.y;
    z += q.z;
    w += q.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::operator - (const Quat& q) const{
    Quat<T> result;
    result.x = x - q.x;
    result.y = y - q.y;
    result.z = z - q.z;
    result.w = w - q.w;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::operator -= (const Quat& q){
    x -= q.x;
    y -= q.y;
    z -= q.z;
    w -= q.w;
    return *this;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::operator / (T Value) const{
    Quat result;
    float val = 1.0f / Value;
    result.x = x*val;
    result.y = y*val;
    result.z = z*val;
    result.w = w*val;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::operator /= (T Value){
    float val = 1.0f / Value;
    x *= val;
    y *= val;
    z *= val;
    w *= val;
    return *this;
}
//==============================================================================
template <class T>
inline void ffw::Quat<T>::normalize(){
    float n = 1.0f/sqrt(x*x+y*y+z*z+w*w);
    x = x * n;
    y = y * n;
    z = z * n;
    w = w * n;
}
//==============================================================================
template <class T>
inline void ffw::Quat<T>::getEuler(T* Roll, T* Pitch, T* Yaw) const{
    // http://www.euclideanspace.com/maths/geometry/rotations/conversions/QuatToEuler/
    T test = x*y + z*w;
    double heading;
    double attitude;
    double bank;
    if (test > 0.499) { // singularity at north pole
        heading = 2.0f * atan2(x, w);
        attitude = M_PI_2;
        bank = 0;
    } else if (test < -0.499) { // singularity at south pole
        heading = -2.0f * atan2(x, w);
        attitude = - M_PI_2;
        bank = 0;
    } else {
        float sqx = x * x;
        float sqy = y * y;
        float sqz = z * z;
        heading     = atan2(2.0f * y * w - 2.0f * x * z, 1.0f - 2.0f*sqy - 2.0f*sqz);
        attitude    = asin(2*test);
        bank        = atan2(2.0f*x * w - 2.0f * y * z, 1.0f - 2.0f*sqx - 2.0f*sqz);
    }
    if(Roll  != NULL)*Roll   = T(attitude  *DEG_TO_RAD);
    if(Pitch != NULL)*Pitch  = T(heading   *DEG_TO_RAD);
    if(Yaw   != NULL)*Yaw    = T(bank      *DEG_TO_RAD);
}
//==============================================================================
template <class T>
inline float ffw::Quat<T>::Length() const {
    return sqrt(x*x + y*y + z*z + w*w);
}
//==============================================================================
template <class T>
inline float ffw::Quat<T>::LengthSqrd() const {
    return x*x + y*y + z*z + w*w;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::getConjugate() const {
    Quat result;
    result.x = -x;
    result.y = -y;
    result.z = -z;
    result.w = w;
    return result;
}
//==============================================================================
template <class T>
inline ffw::Quat<T> ffw::Quat<T>::getInversed() const {
    return getConjugate() / LengthSqrd();
}
//==============================================================================
template <class T>
inline ffw::Quat<T>& ffw::Quat<T>::inverse(){
    *this = getConjugate() / LengthSqrd();
    return *this;
}
