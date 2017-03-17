/* This file is part of FineFramework project */
#ifndef FFW_COLOR
#define FFW_COLOR
#include <math.h>
namespace ffw {
	/**
	* @ingroup math
	*/
	struct Color {
	public:
		float x;
		float y;
		float z;
		float w;
		float& r = x;
		float& g = y;
		float& b = z;
		float& a = w;
		inline Color() {
			x = 0;
			y = 0;
			z = 0;
			w = 0;
		}

		inline Color(float compx, float compy, float compz, float compw) {
			x = compx;
			y = compy;
			z = compz;
			w = compw;
		}

		inline Color(float val) {
			x = val;
			y = val;
			z = val;
			w = val;
		}

		inline Color(const Color& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
		}

		inline Color(const std::initializer_list<float>& list) {
			if (list.size() != 4) {
				x = 0;
				y = 0;
				z = 0;
				w = 0;
				return;
			}
			x = *(list.begin());
			y = *(list.begin() + 1);
			z = *(list.begin() + 2);
			w = *(list.begin() + 3);
		}

		inline void set(float compx, float compy, float compz, float compw) {
			x = compx;
			y = compy;
			z = compz;
			w = compw;
		}

		inline void set(float val) {
			x = val;
			y = val;
			z = val;
			w = val;
		}

		inline void set(const Color& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
		}

		inline void set(const std::initializer_list<float>& list) {
			if (list.size() != 4)return;
			x = *(list.begin());
			y = *(list.begin() + 1);
			z = *(list.begin() + 2);
			w = *(list.begin() + 3);
		}

		inline ffw::Color  operator - () const {
			return Color(-x, -y, -z, -w);
		}

		inline ffw::Color& operator =  (const Color& vec) {
			x = vec.x;
			y = vec.y;
			z = vec.z;
			w = vec.w;
			return *this;
		}

		inline ffw::Color  operator +  (const Color& vec) const {
			return Color(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
		}

		inline ffw::Color& operator += (const Color& vec) {
			x += vec.x;
			y += vec.y;
			z += vec.z;
			w += vec.w;
			return *this;
		}

		inline ffw::Color  operator -  (const Color& vec) const {
			return Color(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
		}

		inline ffw::Color& operator -= (const Color& vec) {
			x -= vec.x;
			y -= vec.y;
			z -= vec.z;
			w -= vec.w;
			return *this;
		}

		inline ffw::Color  operator /  (const Color& vec) const {
			return Color(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
		}

		inline ffw::Color& operator /= (const Color& vec) {
			x /= vec.x;
			y /= vec.y;
			z /= vec.z;
			w /= vec.w;
			return *this;
		}

		inline ffw::Color  operator *  (const Color& vec) const {
			return Color(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
		}

		inline ffw::Color& operator *= (const Color& vec) {
			x *= vec.x;
			y *= vec.y;
			z *= vec.z;
			w *= vec.w;
			return *this;
		}

		inline ffw::Color& operator =  (const float& val) {
			x = val;
			y = val;
			z = val;
			w = val;
			return *this;
		}

		inline ffw::Color  operator +  (const float& val) const {
			return Color(x + val, y + val, z + val, w + val);
		}

		inline ffw::Color& operator += (const float& val) {
			x += val;
			y += val;
			z += val;
			w += val;
			return *this;
		}

		inline ffw::Color  operator -  (const float& val) const {
			return Color(x - val, y - val, z - val, w - val);
		}

		inline ffw::Color& operator -= (const float& val) {
			x -= val;
			y -= val;
			z -= val;
			w -= val;
			return *this;
		}

		inline ffw::Color  operator /  (const float& val) const {
			return Color(x / val, y / val, z / val, w / val);
		}

		inline ffw::Color& operator /= (const float& val) {
			x /= val;
			y /= val;
			z /= val;
			w /= val;
			return *this;
		}

		inline ffw::Color  operator *  (const float& val) const {
			return Color(x * val, y * val, z * val, w * val);
		}

		inline ffw::Color& operator *= (const float& val) {
			x *= val;
			y *= val;
			z *= val;
			w *= val;
			return *this;
		}

		inline bool operator != (const Color& vec) const {
			return !(*this == vec);
		}

		inline bool operator == (const Color& vec) const {
			if (fabs(x - vec.x) > std::numeric_limits<float>::epsilon())return false;
			if (fabs(y - vec.y) > std::numeric_limits<float>::epsilon())return false;
			if (fabs(z - vec.z) > std::numeric_limits<float>::epsilon())return false;
			if (fabs(w - vec.w) > std::numeric_limits<float>::epsilon())return false;
			return true;
		}

		inline ffw::Color& clamp() {
			x = std::max(0.0f, std::min(x, 1.0f));
			y = std::max(0.0f, std::min(x, 1.0f));
			z = std::max(0.0f, std::min(x, 1.0f));
			w = std::max(0.0f, std::min(x, 1.0f));
			return *this;
		}

		inline ffw::Color& normalize() {
			float l = sqrtf(x*x + y*y + z*z + w*w);
			if (l > 0) {
				x = x / l;
				y = y / l;
				z = z / l;
				if (w > 1.0f)w = 1.0f;
				if (w < 0.0f)w = 0.0f;
			}
			return *this;
		}

		inline ffw::Color& scale(const float val) {
			x = x*val;
			y = y*val;
			z = z*val;
			w = w*val;
			return *this;
		}

		inline double length() const {
			return sqrt(static_cast<double>(x*x + y*y + z*z + w*w));
		}

		inline float lengthf() const {
			return sqrtf(static_cast<float>(x*x + y*y + z*z + w*w));
		}

		inline float lengthSqrd() const {
			return (x*x + y*y + z*z + w*w);
		}
	};
	/**
	* @ingroup math
	*/
	inline Color rgb(unsigned long Hex) {
		return Color(
			((Hex & 0xFF0000) >> 16) / 255.0f,
			((Hex & 0x00FF00) >> 8) / 255.0f,
			(Hex & 0x0000FF) / 255.0f,
			1.0f
		);
	}
	/**
	* @ingroup math
	*/
	inline Color rgb(unsigned char Red, unsigned char Green, unsigned char Blue) {
		return Color(
			Red / 255.0f,
			Green / 255.0f,
			Blue / 255.0f,
			1.0f
		);
	}
	/**
	* @ingroup math
	*/
	inline Color rgba(unsigned long Hex) {
		return Color(
			((Hex & 0xFF000000) >> 24) / 255.0f,
			((Hex & 0x00FF0000) >> 16) / 255.0f,
			((Hex & 0x0000FF00) >> 8) / 255.0f,
			(Hex & 0x000000FF) / 255.0f
		);
	}
	/**
	* @ingroup math
	*/
	inline Color rgba(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) {
		return Color(
			Red / 255.0f,
			Green / 255.0f,
			Blue / 255.0f,
			Alpha / 255.0f
		);
	}
};
#endif
