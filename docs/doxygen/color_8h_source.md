---
search: false
---

# color.h File Reference

**[Go to the documentation of this file.](color_8h.md)**
Source: `include/ffw/math/color.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_COLOR
#define FFW_COLOR

#include <ostream>
#include <math.h>
#include <algorithm>
namespace ffw {
    struct Color {
    public:
        float r;
        float g;
        float b;
        float a;
        inline Color() {
            r = 0;
            g = 0;
            b = 0;
            a = 0;
        }
        inline Color(float red, float green, float blue, float alpha) {
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }
        inline Color(float val, float alpha) {
            r = val;
            g = val;
            b = val;
            a = alpha;
        }
        inline Color(const Color& vec) {
            r = vec.r;
            g = vec.g;
            b = vec.b;
            a = vec.a;
        }
        inline Color(const std::initializer_list<float>& list) {
            if (list.size() != 4) {
                r = 0;
                g = 0;
                b = 0;
                a = 0;
                return;
            }
            r = *(list.begin());
            g = *(list.begin() + 1);
            b = *(list.begin() + 2);
            a = *(list.begin() + 3);
        }
        inline void set(float red, float green, float blue, float alpha) {
            r = red;
            g = green;
            b = blue;
            a = alpha;
        }
        inline void set(float val, float alpha) {
            r = val;
            g = val;
            b = val;
            a = alpha;
        }
        inline void set(const Color& vec) {
            r = vec.r;
            g = vec.g;
            b = vec.b;
            a = vec.a;
        }
        inline void set(const std::initializer_list<float>& list) {
            if (list.size() != 4)return;
            r = *(list.begin());
            g = *(list.begin() + 1);
            b = *(list.begin() + 2);
            a = *(list.begin() + 3);
        }
        inline ffw::Color  operator - () const {
            return Color(-r, -g, -b, -a);
        }
        inline ffw::Color& operator =  (const Color& vec) {
            r = vec.r;
            g = vec.g;
            b = vec.b;
            a = vec.a;
            return *this;
        }
        inline ffw::Color  operator +  (const Color& vec) const {
            return Color(r + vec.r, g + vec.g, b + vec.b, a + vec.a);
        }
        inline ffw::Color& operator += (const Color& vec) {
            r += vec.r;
            g += vec.g;
            b += vec.b;
            a += vec.a;
            return *this;
        }
        inline ffw::Color  operator -  (const Color& vec) const {
            return Color(r - vec.r, g - vec.g, b - vec.b, a - vec.a);
        }
        inline ffw::Color& operator -= (const Color& vec) {
            r -= vec.r;
            g -= vec.g;
            b -= vec.b;
            a -= vec.a;
            return *this;
        }

        inline ffw::Color  operator /  (const Color& vec) const {
            return Color(r / vec.r, g / vec.g, b / vec.b, a / vec.a);
        }

        inline ffw::Color& operator /= (const Color& vec) {
            r /= vec.r;
            g /= vec.g;
            b /= vec.b;
            a /= vec.a;
            return *this;
        }

        inline ffw::Color  operator *  (const Color& vec) const {
            return Color(r * vec.r, g * vec.g, b * vec.b, a * vec.a);
        }

        inline ffw::Color& operator *= (const Color& vec) {
            r *= vec.r;
            g *= vec.g;
            b *= vec.b;
            a *= vec.a;
            return *this;
        }
        inline ffw::Color& operator =  (const float& val) {
            r = val;
            g = val;
            b = val;
            a = val;
            return *this;
        }
        inline ffw::Color  operator +  (const float& val) const {
            return Color(r + val, g + val, b + val, a + val);
        }
        inline ffw::Color& operator += (const float& val) {
            r += val;
            g += val;
            b += val;
            a += val;
            return *this;
        }
        inline ffw::Color  operator -  (const float& val) const {
            return Color(r - val, g - val, b - val, a - val);
        }
        inline ffw::Color& operator -= (const float& val) {
            r -= val;
            g -= val;
            b -= val;
            a -= val;
            return *this;
        }

        inline ffw::Color  operator /  (const float& val) const {
            return Color(r / val, g / val, b / val, a / val);
        }

        inline ffw::Color& operator /= (const float& val) {
            r /= val;
            g /= val;
            b /= val;
            a /= val;
            return *this;
        }

        inline ffw::Color  operator *  (const float& val) const {
            return Color(r * val, g * val, b * val, a * val);
        }

        inline ffw::Color& operator *= (const float& val) {
            r *= val;
            g *= val;
            b *= val;
            a *= val;
            return *this;
        }
        inline bool operator != (const Color& vec) const {
            return !(*this == vec);
        }
        inline bool operator == (const Color& vec) const {
            if (fabs(r - vec.r) > std::numeric_limits<float>::epsilon())return false;
            if (fabs(g - vec.g) > std::numeric_limits<float>::epsilon())return false;
            if (fabs(b - vec.b) > std::numeric_limits<float>::epsilon())return false;
            if (fabs(a - vec.a) > std::numeric_limits<float>::epsilon())return false;
            return true;
        }
        inline ffw::Color& clamp() {
            r = std::max(0.0f, std::min(r, 1.0f));
            g = std::max(0.0f, std::min(r, 1.0f));
            b = std::max(0.0f, std::min(r, 1.0f));
            a = std::max(0.0f, std::min(r, 1.0f));
            return *this;
        }
        inline ffw::Color& normalize() {
            float l = sqrtf(r*r + g*g + b*b);
            if (l > 0) {
                r = r / l;
                g = g / l;
                b = b / l;
                if (a > 1.0f)a = 1.0f;
                if (a < 0.0f)a = 0.0f;
            }
            return *this;
        }
        inline ffw::Color& scale(const float val) {
            r = r*val;
            g = g*val;
            b = b*val;
            a = a*val;
            return *this;
        }
        inline double length() const {
            return sqrt(static_cast<double>(r*r + g*g + b*b + a*a));
        }
        inline float lengthf() const {
            return sqrtf(static_cast<float>(r*r + g*g + b*b + a*a));
        }
        inline float lengthSqrd() const {
            return (r*r + g*g + b*b + a*a);
        }
        inline Color inverted() const {
            return Color(1.0f - r, 1.0f - g, 1.0f - b, a);
        }
    };
    inline Color rgb(unsigned long Hex) {
        return Color(
            ((Hex & 0xFF0000) >> 16) / 255.0f,
            ((Hex & 0x00FF00) >> 8) / 255.0f,
            (Hex & 0x0000FF) / 255.0f,
            1.0f
        );
    }
    inline Color rgb(unsigned char Red, unsigned char Green, unsigned char Blue) {
        return Color(
            Red / 255.0f,
            Green / 255.0f,
            Blue / 255.0f,
            1.0f
        );
    }
    inline Color rgba(unsigned long Hex) {
        return Color(
            ((Hex & 0xFF000000) >> 24) / 255.0f,
            ((Hex & 0x00FF0000) >> 16) / 255.0f,
            ((Hex & 0x0000FF00) >> 8) / 255.0f,
            (Hex & 0x000000FF) / 255.0f
        );
    }
    inline Color rgba(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) {
        return Color(
            Red / 255.0f,
            Green / 255.0f,
            Blue / 255.0f,
            Alpha / 255.0f
        );
    }
    inline ffw::Color normalize(const Color& col) {
        auto copy = col;
        copy.normalize();
        return copy;
    }
    inline ffw::Color clamp(const ffw::Color& color) {
        return ffw::Color(color).clamp();
    }
    inline std::ostream& operator << (std::ostream& os, const ffw::Color& color) {
        os << color.r << ", " << color.g << ", " << color.b << ", " << color.a;
        return os;
    }
};
#endif
```


    
  
