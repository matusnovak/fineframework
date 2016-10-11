/* This file is part of FineFramework project */
#ifndef FFW_COLOR
#define FFW_COLOR

namespace ffw {
    class Color {
	public:
        float r;
        float g;
        float b;
        float a;
        Color(float R, float G, float B, float A);
        Color(float R, float G, float B);
        Color(float Grey);
        Color();
        void Set(float R, float G, float B, float A);
        void Set(float R, float G, float B);
        void Set(float Grey);
        Color& operator =  (const Color &color);
        Color  operator +  (const Color &color) const;
        Color& operator += (const Color &color);
        Color  operator -  (const Color &color) const;
        Color& operator -= (const Color &color);
        Color& Clamp();
        Color& Normalize();
    };
	Color Rgb(unsigned long hex);
	Color Rgb(unsigned char red, unsigned char green, unsigned char blue);
	Color Rgba(unsigned long hex);
	Color Rgba(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
};
#include "Color.inl"
#endif
