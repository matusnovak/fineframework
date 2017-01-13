/* This file is part of FineFramework project */
#ifndef FFW_MODEL_VIEW_PROJECTION
#define FFW_MODEL_VIEW_PROJECTION
#include "../config.h"

namespace ffw {
	template <class T>
	inline ffw::Mat4x4<T> MakeRotationMatrix(const ffw::Quat<T>& Q) {
		Mat4x4<T> m;
		m[0] = 1.0f - 2.0f * (Q.y * Q.y + Q.z * Q.z);    m[4] = 2.0f * (Q.x * Q.y + Q.z * Q.w);         m[8] = 2.0f * (Q.x * Q.z - Q.y * Q.w);
		m[1] = 2.0f * (Q.x * Q.y - Q.z * Q.w);           m[5] = 1.0f - 2.0f * (Q.x * Q.x + Q.z * Q.z);  m[9] = 2.0f * (Q.y * Q.z + Q.x * Q.w);
		m[2] = 2.0f * (Q.x * Q.z + Q.y * Q.w);           m[6] = 2.0f * (Q.y * Q.z - Q.x * Q.w);         m[10] = 1.0f - 2.0f * (Q.x * Q.x + Q.y * Q.y);
		return m;
	}

	inline Mat4x4f MakeProjectionMatrix(float FieldOfView, float Aspect, float Near, float Far) {
		float halfFov = FieldOfView / 2.0f;
		float tanFov = tanf(halfFov*(float)DEG_TO_RAD);
		ffw::Mat4x4f mat;
		mat.ptr[0] = 1.0f / (Aspect * tanFov);
		mat.ptr[5] = 1.0f / tanFov;
		mat.ptr[10] = (Near + Far) / (Near - Far);
		mat.ptr[11] = -1.0f;
		mat.ptr[14] = (2.0f * Far * Near) / (Near - Far);
		return mat;
	}
	
	inline Mat4x4f MakeLookAtMatrix(const Vec3f& Eyes, const Vec3f& Target, const Vec3f& UpVector) {
		Mat4x4f mat;
		Vec3f f = ffw::Normalize(Target - Eyes);
		Vec3f s = ffw::Normalize(ffw::Cross(f, UpVector));
		Vec3f u = ffw::Cross(s, f);
		mat[0] = s.x;
		mat[4] = s.y;
		mat[8] = s.z;
		mat[3] = 0.0f;
		mat[1] = u.x;
		mat[5] = u.y;
		mat[9] = u.z;
		mat[7] = 0.0f;
		mat[2] = -f.x;
		mat[6] = -f.y;
		mat[10] = -f.z;
		mat[11] = 0.0f;
		mat[12] = -ffw::Dot(s, Eyes);
		mat[13] = -ffw::Dot(u, Eyes);
		mat[14] = ffw::Dot(f, Eyes);
		mat[15] = 1.0f;
		return mat;
	}
	
	inline Mat4x4f MakeFpsCameraMatrix(const Vec3f& Eyes, float Pitch, float Yaw) {
		float cPitch = (float)cos(Pitch*DEG_TO_RAD);
		float sPitch = (float)sin(Pitch*DEG_TO_RAD);
		float cYaw = (float)cos(Yaw*DEG_TO_RAD);
		float sYaw = (float)sin(Yaw*DEG_TO_RAD);
		ffw::Mat4x4f mat;
		ffw::Vec3f s(cYaw, 0, -sYaw);
		ffw::Vec3f u(sYaw * sPitch, cPitch, cYaw * sPitch);
		ffw::Vec3f f(sYaw * cPitch, -sPitch, cPitch * cYaw);
		mat[0] = s.x;
		mat[4] = s.y;
		mat[8] = s.z;
		mat[3] = 0.0f;
		mat[1] = u.x;
		mat[5] = u.y;
		mat[9] = u.z;
		mat[7] = 0.0f;
		mat[2] = -f.x;
		mat[6] = -f.y;
		mat[10] = -f.z;
		mat[11] = 0.0f;
		mat[12] = -ffw::Dot(s, Eyes);
		mat[13] = -ffw::Dot(u, Eyes);
		mat[14] = ffw::Dot(f, Eyes);
		mat[15] = 1.0f;
		return mat;
	}
};

#endif