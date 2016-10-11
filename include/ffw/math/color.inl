/* This file is part of FineFramework project */
//==============================================================================
inline ffw::Color::Color(){
    r = 1.0f;
    g = 1.0f;
    b = 1.0f;
    a = 1.0f;
}
//==============================================================================
inline ffw::Color::Color(float R, float G, float B, float A){
    r = R;
    g = G;
    b = B;
    a = A;
}
//==============================================================================
inline ffw::Color::Color(float R, float G, float B){
    r = R;
    g = G;
    b = B;
    a = 1.0f;
}
//==============================================================================
inline ffw::Color::Color(float Grey){
    r = Grey;
    g = Grey;
    b = Grey;
    a = 1.0f;
}
//==============================================================================
inline void ffw::Color::Set(float R, float G, float B, float A){
    r = R;
    g = G;
    b = B;
    a = A;
}
//==============================================================================
inline void ffw::Color::Set(float R, float G, float B){
    r = R;
    g = G;
    b = B;
    a = 1.0f;
}
//==============================================================================
inline void ffw::Color::Set(float Grey){
    r = Grey;
    g = Grey;
    b = Grey;
    a = 1.0f;
}
//==============================================================================
inline ffw::Color& ffw::Color::operator =  (const Color &Col){
    r = Col.r;
    g = Col.g;
    b = Col.b;
    a = Col.a;
    return *this;
}
//==============================================================================
inline ffw::Color  ffw::Color::operator +  (const Color &Col) const{
    return ffw::Color(r + Col.r, g + Col.g, b + Col.b, a + Col.a);
}
//==============================================================================
inline ffw::Color& ffw::Color::operator += (const Color &Col){
    r += Col.r;
    g += Col.g;
    b += Col.b;
    a += Col.a;
    return *this;
}
//==============================================================================
inline ffw::Color  ffw::Color::operator -  (const Color &Col) const{
    return ffw::Color(r - Col.r, g - Col.g, b - Col.b, a - Col.a);
}
//==============================================================================
inline ffw::Color& ffw::Color::operator -= (const Color &Col){
    r -= Col.r;
    g -= Col.g;
    b -= Col.b;
    a -= Col.a;
    return *this;
}
//==============================================================================
inline ffw::Color& ffw::Color::Clamp(){
    if(r > 1.0f)r = 1.0f;
    if(r < 0.0f)r = 0.0f;
    if(g > 1.0f)g = 1.0f;
    if(g < 0.0f)g = 0.0f;
    if(b > 1.0f)b = 1.0f;
    if(b < 0.0f)b = 0.0f;
    if(a > 1.0f)a = 1.0f;
    if(a < 0.0f)a = 0.0f;
    return *this;
}
//==============================================================================
inline ffw::Color& ffw::Color::Normalize(){
    float l = sqrt(r*r + g*g + b*b);
    r /= l;
    g /= l;
    b /= l;
    if(a > 1.0f)a = 1.0f;
    return *this;
}
//==============================================================================
inline ffw::Color ffw::Rgb(unsigned long Hex){
	return ffw::Color(
		((Hex & 0xFF0000) >> 16) / 255.0f,
		((Hex & 0x00FF00) >> 8) / 255.0f,
		(Hex & 0x0000FF) / 255.0f,
		1.0f
	);
}
//==============================================================================
inline ffw::Color ffw::Rgb(unsigned char Red, unsigned char Green, unsigned char Blue){
	return ffw::Color(
		Red / 255.0f,
		Green / 255.0f,
		Blue / 255.0f,
		1.0f
	);
}
//==============================================================================
inline ffw::Color ffw::Rgba(unsigned long Hex){
	return ffw::Color(
		((Hex & 0xFF000000) >> 24) / 255.0f,
		((Hex & 0x00FF0000) >> 16) / 255.0f,
		((Hex & 0x0000FF00) >> 8) / 255.0f,
		(Hex & 0x000000FF) / 255.0f
	);
}
//==============================================================================
inline ffw::Color ffw::Rgba(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha){
	return ffw::Color(
		Red / 255.0f,
		Green / 255.0f,
		Blue / 255.0f,
		Alpha / 255.0f
	);
}
