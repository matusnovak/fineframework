/* This file is part of FineFramework project */
#ifndef FFW_MODEL_VIEW_PROJECTION
#define FFW_MODEL_VIEW_PROJECTION
#include "../config.h"

namespace ffw {
	/**
	* @ingroup math
	*/
	template <class T>
	inline ffw::Mat4x4<T> MakeRotationMatrix(const ffw::Quat<T>& Q) {
		Mat4x4<T> m;
		m[0] = 1.0f - 2.0f * (Q.y * Q.y + Q.z * Q.z);    m[4] = 2.0f * (Q.x * Q.y + Q.z * Q.w);         m[8] = 2.0f * (Q.x * Q.z - Q.y * Q.w);
		m[1] = 2.0f * (Q.x * Q.y - Q.z * Q.w);           m[5] = 1.0f - 2.0f * (Q.x * Q.x + Q.z * Q.z);  m[9] = 2.0f * (Q.y * Q.z + Q.x * Q.w);
		m[2] = 2.0f * (Q.x * Q.z + Q.y * Q.w);           m[6] = 2.0f * (Q.y * Q.z - Q.x * Q.w);         m[10] = 1.0f - 2.0f * (Q.x * Q.x + Q.y * Q.y);
		return m;
	}
	/**
	* @ingroup math
	*/
	Mat4x4f FFW_API MakeProjectionMatrix(float FieldOfView, float Aspect, float Near, float Far);
	/**
	* @ingroup math
	*/
	Mat4x4f FFW_API MakeLookAtMatrix(const Vec3f& Eyes, const Vec3f& Target, const Vec3f& UpVector);
	/**
	* @ingroup math
	*/
	Mat4x4f FFW_API MakeFpsCameraMatrix(const Vec3f& Eyes, float Pitch, float Yaw);
};

#endif