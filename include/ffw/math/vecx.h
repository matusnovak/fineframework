/* This file is part of FineFramework project */
#ifndef FFW_VEC_X
#define FFW_VEC_X
#include "../config.h"
#include <array>

namespace ffw{
	template<class T, size_t S>
	class Vec {
	public:
		Vec() {
			for(size_t i = 0; i < S; i++) {
				arr[i] = (T)0;
			}
		}

		Vec(T val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] = val;
			}
		}

		Vec(const std::initializer_list<T>& list) {
			if (S == list.size()) {
				for (size_t i = 0; i < S; i++) {
					arr[i] = *(list.begin() + i);
				}
			} else {
				for (size_t i = 0; i < S; i++) {
					arr[i] = (T)0;
				}
			}
		}

		Vec(const Vec<T, S>& other):arr(other.arr) {
		}

		Vec(Vec<T, S>&& other):arr(std::move(other.arr)) {
		}

		void set(T val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] = val;
			}
		}

		void set(const std::initializer_list<T>& list) {
			if (S == list.size()) {
				for (size_t i = 0; i < S; i++) {
					arr[i] = *(list.begin() + i);
				}
			}
		}

		void set(const Vec<T, S>& other) {
			arr = other.arr;
		}

		ffw::Vec<T, S>  operator - () const {
			auto copy = *this;
			for(size_t i = 0; i < S; i++) {
				copy.arr[i] = -arr[i];
			}
			return copy;
		}

		ffw::Vec<T, S>& operator =  (const Vec<T, S>& vec) {
			for (size_t i = 0; i < S; i++) {
				arr[i] = vec.arr[i];
			}
			return *this;
		}

		ffw::Vec<T, S>  operator +  (const Vec<T, S>& vec) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] += vec.arr[i];
			}
			return copy;
		}

		ffw::Vec<T, S>& operator += (const Vec<T, S>& vec) {
			for (size_t i = 0; i < S; i++) {
				arr[i] += vec.arr[i];
			}
			return *this;
		}

		ffw::Vec<T, S>  operator -  (const Vec<T, S>& vec) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] -= vec.arr[i];
			}
			return copy;
		}

		ffw::Vec<T, S>& operator -= (const Vec<T, S>& vec) {
			for (size_t i = 0; i < S; i++) {
				arr[i] -= vec.arr[i];
			}
			return *this;
		}

		ffw::Vec<T, S>  operator /  (const Vec<T, S>& vec) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] /= vec.arr[i];
			}
			return copy;
		}

		ffw::Vec<T, S>& operator /= (const Vec<T, S>& vec) {
			for (size_t i = 0; i < S; i++) {
				arr[i] /= vec.arr[i];
			}
			return *this;
		}

		ffw::Vec<T, S>  operator *  (const Vec<T, S>& vec) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] *= vec.arr[i];
			}
			return copy;
		}

		ffw::Vec<T, S>& operator *= (const Vec<T, S>& vec) {
			for (size_t i = 0; i < S; i++) {
				arr[i] *= vec.arr[i];
			}
			return *this;
		}

		ffw::Vec2<T>& operator =  (const T& val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] = val;
			}
			return *this;
		}

		ffw::Vec<T, S>  operator +  (const T& val) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] += val;
			}
			return copy;
		}

		ffw::Vec<T, S>& operator += (const T& val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] += val;
			}
			return *this;
		}

		ffw::Vec<T, S>  operator -  (const T& val) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] -= val;
			}
			return copy;
		}

		ffw::Vec<T, S>& operator -= (const T& val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] -= val;
			}
			return *this;
		}

		ffw::Vec<T, S>  operator /  (const T& val) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] /= val;
			}
			return copy;
		}

		ffw::Vec<T, S>& operator /= (const T& val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] /= val;
			}
			return *this;
		}

		ffw::Vec<T, S>  operator *  (const T& val) const {
			auto copy = *this;
			for (size_t i = 0; i < S; i++) {
				copy.arr[i] *= val;
			}
			return copy;
		}

		ffw::Vec<T, S>& operator *= (const T& val) {
			for (size_t i = 0; i < S; i++) {
				arr[i] *= val;
			}
			return *this;
		}

		bool operator != (const Vec<T, S>& vec) const {
			return !(*this == vec);
		}

		bool operator == (const Vec<T, S>& vec) const {
			for(size_t i = 0; i < S; i++) {
				if (arr[i] != vec.arr[i])return false;
			}
			return true;
		}

		ffw::Vec<T, S>& normalize() {
			double l = 0.0;
			for(size_t i = 0; i < S; i++) {
				l += arr[i] * arr[i];
			}
			l = sqrt(l);
			for(size_t i = 0; i < S; i++) {
				arr[i] = T(arr[i] / l);
			}
			return *this;
		}

		ffw::Vec<T, S>& scale(T factor) {
			for (size_t i = 0; i < S; i++) {
				arr[i] = arr[i] * factor;
			}
			return *this;
		}

		float lengthf() const {
			return sqrtf(lengthSqrd());
		}

		double length() const {
			return sqrt(lengthSqrd());
		}

		T lengthSqrd() const {
			T val = (T)0;
			for (size_t i = 0; i < S; i++) {
				val += arr[i] * arr[i];
			}
			return val;
		}

		T& operator [] (size_t i){
			return arr[i];
		}

		const T& operator [] (size_t i) const  {
			return arr[i];
		}

		template <class X>
		operator ffw::Vec<X, S>() const {
			Vec<X, S> copy;
			for(size_t i = 0; i < S; i++) {
				copy.arr[i] = static_cast<X>(arr[i]);
			}
			return copy;
		}

		std::array<T, S> arr;
	};
};
#endif
