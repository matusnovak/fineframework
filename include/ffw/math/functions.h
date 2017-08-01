/* This file is part of FineFramework project */
#ifndef FFW_BASE_FUNCTIONS
#define FFW_BASE_FUNCTIONS
#include "../config.h"
#include <algorithm>

namespace ffw {
	/**
	* @ingroup math
	*/
	template <class T>
	inline T lerp(const T& a, const T& b, float w) {
		return T((1 - w)*a + w*b);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline T clamp(T Val, T Min, T Max) {
		return std::max(Min, std::min(Val, Max));
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline T radians (T val){
		return static_cast<T>(val * DEG_TO_RAD);
	}
	/**
	* @ingroup math
	*/
	template<class T>
	inline T degrees (T val){
		return static_cast<T>(val * RAD_TO_DEG);
	}
	/**
	* @ingroup math
	*/
	template<typename T>
	inline T remap(T value, T InMin, T InMax, T OutMin, T OutMax) {
		return (value - InMin)*(OutMax - OutMin) / (InMax - InMin) + OutMin;
	}
	/**
	* @ingroup math
	*/
	inline unsigned long nextPowOfTwo(unsigned long Value) {
		unsigned long P = 1;
		while (P < Value) {
			P *= 2;
		}
		return P;
	}

#ifdef FFW_WINDOWS_MSVC
	/**
	* @ingroup math
	*/
	inline unsigned short byteSwap16(unsigned short Value) {
		return _byteswap_ushort(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long byteSwap32(unsigned long Value) {
		return _byteswap_ulong(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long long byteSwap64(unsigned long long Value) {
		return _byteswap_uint64(Value);
	}
#else
	/**
	* @ingroup math
	*/
	inline unsigned short byteSwap16(unsigned short Value) {
		return __builtin_bswap16(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long byteSwap32(unsigned long Value) {
		return __builtin_bswap32(Value);
	}
	/**
	* @ingroup math
	*/
	inline unsigned long long byteSwap64(unsigned long long Value) {
		return __builtin_bswap64(Value);
	}
#endif
};
#endif
