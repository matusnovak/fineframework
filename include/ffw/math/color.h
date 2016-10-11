/* This file is part of FineFramework project */
#ifndef FFW_COLOR
#define FFW_COLOR

namespace ffw {
	/**
	 * @ingroup math
	 */
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
	/**
	 * @ingroup math
	 */
	Color Rgb(unsigned long hex);
	/**
	 * @ingroup math
	 */
	Color Rgb(unsigned char red, unsigned char green, unsigned char blue);
	/**
	 * @ingroup math
	 */
	Color Rgba(unsigned long hex);
	/**
	 * @ingroup math
	 */
	Color Rgba(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
};
#include "Color.inl"
#endif
