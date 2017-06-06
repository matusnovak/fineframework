#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

TEST_CASE("Testing Vec2", "[Vec2]") {
	{
		ffw::Vec2i vec;
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
	}

	{
		ffw::Vec2i vec(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
	}

	{
		ffw::Vec2i vec(10, 20);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
	}

	{
		ffw::Vec2i vec({ 10, 20 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
	}

	{
		ffw::Vec2i vec({ 10, 20, 30 });
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
	}

	{
		ffw::Vec2i vec;
		vec.set(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
	}

	{
		ffw::Vec2i vec;
		vec.set(10, 20);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
	}

	{
		ffw::Vec2i vec;
		vec.set({ 10, 20 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
	}

	{
		ffw::Vec2i vec;
		vec.set({ 10, 20, 30 });
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
	}

	{
		ffw::Vec2i vec = { 10, 20 };
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
	}

	{
		ffw::Vec2i a(1, 5);
		ffw::Vec2i b(5, 10);
		ffw::Vec2i c = a + b;
		REQUIRE(c.x == 6);
		REQUIRE(c.y == 15);
		REQUIRE(a + b == c);
		b += a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec2i a(5, 10);
		ffw::Vec2i b(1, 5);
		ffw::Vec2i c = a - b;
		REQUIRE(c.x == 4);
		REQUIRE(c.y == 5);
		REQUIRE(a - b == c);
		a -= b;
		REQUIRE(a == c);
	}

	{
		ffw::Vec2i a(5, 10);
		ffw::Vec2i b(1, 5);
		ffw::Vec2i c = a * b;
		REQUIRE(c.x == 5);
		REQUIRE(c.y == 50);
		REQUIRE(a * b == c);
		b *= a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec2i a(6, 12);
		ffw::Vec2i b(2, 3);
		ffw::Vec2i c = a / b;
		REQUIRE(c.x == 3);
		REQUIRE(c.y == 4);
		REQUIRE(a / b == c);
		a /= b;
		REQUIRE(a == c);
	}

	REQUIRE(ffw::Vec2i(1, 2) == ffw::Vec2i(1, 2));
	REQUIRE(ffw::Vec2i(1, 2) != ffw::Vec2i(2, 2));
	REQUIRE(ffw::Vec2i(1, 2) != ffw::Vec2i(1, 1));
	REQUIRE(ffw::Vec2f(1.0f, 2.0f) == ffw::Vec2f(1.0f, 2.0f));
	REQUIRE(ffw::Vec2f(1.0f, 2.0f) != ffw::Vec2f(1.0f, 2.001f));

	{
		ffw::Vec2i a(6, 12);
		ffw::Vec2i b = -a;
		REQUIRE(b.x == -6);
		REQUIRE(b.y == -12);
		b = -b;
		REQUIRE(b == a);
	}

	{
		ffw::Vec2i vec(5, 10);
		vec.scale(3);
		REQUIRE(vec.x == 15);
		REQUIRE(vec.y == 30);
	}

	{
		ffw::Vec2f vec(3.0f, 4.0f);
		vec.normalize();
		REQUIRE(std::fabs(vec.x - 3.0f / 5.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 4.0f / 5.0f) < 0.01f);
	}

	{
		ffw::Vec2f vec(1.0f, 0.0f);
		vec.rotate(90.0f);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
	}

	{
		ffw::Vec2f vec(1.0f, 0.0f);
		vec.rotateRad(90.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
	}

	{
		ffw::Vec2f vec(1.0f, 1.0f);
		REQUIRE(std::fabs(vec.length() - sqrt(2.0)) < 0.01);
	}

	{
		ffw::Vec2i vec(1, 1);
		REQUIRE(std::fabs(vec.length() - sqrt(2.0)) < 0.01);
	}

	{
		ffw::Vec2f vec(1.0f, 1.0f);
		REQUIRE(vec.lengthSqrd() == 2.0f);
	}

	{
		ffw::Vec2i vec(1, 1);
		REQUIRE(vec.lengthSqrd() == 2);
	}
}

TEST_CASE("Testing Vec3", "[Vec3]") {
	{
		ffw::Vec3i vec;
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
	}

	{
		ffw::Vec3i vec(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
		REQUIRE(vec.z == 42);
	}

	{
		ffw::Vec3i vec(10, 20, 30);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
	}

	{
		ffw::Vec3i vec({ 10, 20, 30 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
	}

	{
		ffw::Vec3i vec({ 10, 20, 30, 40 });
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
	}

	{
		ffw::Vec3i vec;
		vec.set(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
		REQUIRE(vec.z == 42);
	}

	{
		ffw::Vec3i vec;
		vec.set(10, 20, 30);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
	}

	{
		ffw::Vec3i vec;
		vec.set({ 10, 20, 30 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
	}

	{
		ffw::Vec3i vec;
		vec.set({ 10, 20, 30, 40 });
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
	}

	{
		ffw::Vec3i vec = { 10, 20, 30 };
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
	}

	{
		ffw::Vec3i a(1, 5, 10);
		ffw::Vec3i b(5, 10, 2);
		ffw::Vec3i c = a + b;
		REQUIRE(c.x == 6);
		REQUIRE(c.y == 15);
		REQUIRE(c.z == 12);
		REQUIRE(a + b == c);
		b += a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec3i a(5, 10, 20);
		ffw::Vec3i b(1, 5, 5);
		ffw::Vec3i c = a - b;
		REQUIRE(c.x == 4);
		REQUIRE(c.y == 5);
		REQUIRE(c.z == 15);
		REQUIRE(a - b == c);
		a -= b;
		REQUIRE(a == c);
	}

	{
		ffw::Vec3i a(5, 10, 8);
		ffw::Vec3i b(1, 5, 2);
		ffw::Vec3i c = a * b;
		REQUIRE(c.x == 5);
		REQUIRE(c.y == 50);
		REQUIRE(c.z == 16);
		REQUIRE(a * b == c);
		b *= a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec3i a(6, 12, 25);
		ffw::Vec3i b(2, 3, 5);
		ffw::Vec3i c = a / b;
		REQUIRE(c.x == 3);
		REQUIRE(c.y == 4);
		REQUIRE(c.z == 5);
		REQUIRE(a / b == c);
		a /= b;
		REQUIRE(a == c);
	}

	REQUIRE(ffw::Vec3i(1, 2, 3) == ffw::Vec3i(1, 2, 3));
	REQUIRE(ffw::Vec3i(1, 2, 3) != ffw::Vec3i(2, 2, 2));
	REQUIRE(ffw::Vec3i(1, 2, 3) != ffw::Vec3i(1, 1, 1));
	REQUIRE(ffw::Vec3i(1, 2, 3) != ffw::Vec3i(3, 3, 3));
	REQUIRE(ffw::Vec3f(1.0f, 2.0f, 3.0f) == ffw::Vec3f(1.0f, 2.0f, 3.0f));
	REQUIRE(ffw::Vec3f(1.0f, 2.0f, 3.0f) != ffw::Vec3f(1.0f, 2.001f, 3.0f));

	{
		ffw::Vec3i a(6, 12, 16);
		ffw::Vec3i b = -a;
		REQUIRE(b.x == -6);
		REQUIRE(b.y == -12);
		REQUIRE(b.z == -16);
		b = -b;
		REQUIRE(b == a);
	}

	{
		ffw::Vec3i vec(5, 10, 15);
		vec.scale(3);
		REQUIRE(vec.x == 15);
		REQUIRE(vec.y == 30);
		REQUIRE(vec.z == 45);
	}

	{
		ffw::Vec3f vec(3.0f, 4.0f, 12.0f);
		vec.normalize();
		REQUIRE(std::fabs(vec.x - 3.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 4.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 12.0f / 13.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(1.0f, 0.0f, 0.0f);
		vec.rotateZ(90.0f);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(1.0f, 0.0f, 0.0f);
		vec.rotateZ(30.0f);
		REQUIRE(std::fabs(vec.x - 0.866025f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 0.5f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(1.0f, 0.0f, 0.0f);
		vec.rotateZRad(90.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(1.0f, 0.0f, 0.0f);
		vec.rotateZRad(30.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 0.866025f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 0.5f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateY(90.0f);
		REQUIRE(std::fabs(vec.x - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateY(30.0f);
		REQUIRE(std::fabs(vec.x - 0.5f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.866025f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateYRad(90.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateYRad(30.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 0.5f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 0.866025f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateX(90.0f);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - -1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 1.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateX(30.0f);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 0.366025f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 1.366025f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateXRad(90.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - -1.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 1.0f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateXRad(30.0f * DEG_TO_RAD);
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 0.366025f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 1.366025f) < 0.01f);
	}

	{
		ffw::Vec3f vec(0.0f, 1.0f, 1.0f);
		vec.rotateByAxis(30.0f, ffw::Vec3f(0.2f, 0.8f, 0.6f));
		REQUIRE(std::fabs(vec.x - 0.134128f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 0.912248f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 1.072294f) < 0.01f);
	}

	{
		ffw::Vec3f vec(1.0f, 1.0f, 1.0f);
		REQUIRE(std::fabs(vec.length() - sqrt(3.0)) < 0.01);
	}

	{
		ffw::Vec3i vec(1, 1, 1);
		REQUIRE(std::fabs(vec.length() - sqrt(3.0)) < 0.01);
	}

	{
		ffw::Vec3f vec(1.0f, 1.0f, 1.0f);
		REQUIRE(vec.lengthSqrd() == 3.0f);
	}

	{
		ffw::Vec3i vec(1, 1, 1);
		REQUIRE(vec.lengthSqrd() == 3);
	}
}


TEST_CASE("Testing Vec4", "[Vec4]") {
	{
		ffw::Vec4i vec;
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
		REQUIRE(vec.w == 0);
	}

	{
		ffw::Vec4i vec(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
		REQUIRE(vec.z == 42);
		REQUIRE(vec.w == 42);
	}

	{
		ffw::Vec4i vec(10, 20, 30, 40);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Vec4i vec({ 10, 20, 30, 40 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Vec4i vec({ 10, 20, 30, 40, 50 });
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
		REQUIRE(vec.w == 0);
	}

	{
		ffw::Vec4i vec;
		vec.set(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
		REQUIRE(vec.z == 42);
		REQUIRE(vec.w == 42);
	}

	{
		ffw::Vec4i vec;
		vec.set(10, 20, 30, 40);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Vec4i vec;
		vec.set({ 10, 20, 30, 40 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Vec4i vec(5);
		vec.set({ 10, 20, 30, 40, 50 });
		REQUIRE(vec.x == 5);
		REQUIRE(vec.y == 5);
		REQUIRE(vec.z == 5);
		REQUIRE(vec.w == 5);
	}

	{
		ffw::Vec4i vec = { 10, 20, 30, 40 };
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Vec4i a(1, 5, 10, 6);
		ffw::Vec4i b(5, 10, 2, 2);
		ffw::Vec4i c = a + b;
		REQUIRE(c.x == 6);
		REQUIRE(c.y == 15);
		REQUIRE(c.z == 12);
		REQUIRE(c.w == 8);
		REQUIRE(a + b == c);
		b += a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec4i a(5, 10, 20, 15);
		ffw::Vec4i b(1, 5, 5, 3);
		ffw::Vec4i c = a - b;
		REQUIRE(c.x == 4);
		REQUIRE(c.y == 5);
		REQUIRE(c.z == 15);
		REQUIRE(c.w == 12);
		REQUIRE(a - b == c);
		a -= b;
		REQUIRE(a == c);
	}

	{
		ffw::Vec4i a(5, 10, 8, 15);
		ffw::Vec4i b(1, 5, 2, 3);
		ffw::Vec4i c = a * b;
		REQUIRE(c.x == 5);
		REQUIRE(c.y == 50);
		REQUIRE(c.z == 16);
		REQUIRE(c.w == 45);
		REQUIRE(a * b == c);
		b *= a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec4i a(6, 12, 25, 15);
		ffw::Vec4i b(2, 3, 5, 3);
		ffw::Vec4i c = a / b;
		REQUIRE(c.x == 3);
		REQUIRE(c.y == 4);
		REQUIRE(c.z == 5);
		REQUIRE(c.w == 5);
		REQUIRE(a / b == c);
		a /= b;
		REQUIRE(a == c);
	}

	REQUIRE(ffw::Vec4i(1, 2, 3, 4) == ffw::Vec4i(1, 2, 3, 4));
	REQUIRE(ffw::Vec4i(1, 2, 3, 4) != ffw::Vec4i(2, 2, 2, 4));
	REQUIRE(ffw::Vec4i(1, 2, 3, 4) != ffw::Vec4i(1, 1, 1, 4));
	REQUIRE(ffw::Vec4i(1, 2, 3, 4) != ffw::Vec4i(3, 3, 3, 4));
	REQUIRE(ffw::Vec4f(1.0f, 2.0f, 3.0f, 4.0f) == ffw::Vec4f(1.0f, 2.0f, 3.0f, 4.0f));
	REQUIRE(ffw::Vec4f(1.0f, 2.0f, 3.0f, 4.0f) != ffw::Vec4f(1.0f, 2.001f, 3.0f, 4.0f));

	{
		ffw::Vec4i a(6, 12, 16, 15);
		ffw::Vec4i b = -a;
		REQUIRE(b.x == -6);
		REQUIRE(b.y == -12);
		REQUIRE(b.z == -16);
		REQUIRE(b.w == -15);
		b = -b;
		REQUIRE(b == a);
	}

	{
		ffw::Vec4i vec(5, 10, 15, 3);
		vec.scale(3);
		REQUIRE(vec.x == 15);
		REQUIRE(vec.y == 30);
		REQUIRE(vec.z == 45);
		REQUIRE(vec.w == 9);
	}

	{
		ffw::Vec4f vec(0.0f, 4.0f, 12.0f, 3.0f);
		vec.normalize();
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 4.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 12.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec.w - 3.0f / 13.0f) < 0.01f);
	}

	{
		ffw::Vec4f vec(1.0f, 1.0f, 1.0f, 1.0f);
		REQUIRE(std::fabs(vec.length() - sqrt(4.0)) < 0.01);
	}

	{
		ffw::Vec4i vec(1, 1, 1, 1);
		REQUIRE(std::fabs(vec.length() - sqrt(4.0)) < 0.01);
	}

	{
		ffw::Vec4f vec(1.0f, 1.0f, 1.0f, 1.0f);
		REQUIRE(vec.lengthSqrd() == 4.0f);
	}

	{
		ffw::Vec4i vec(1, 1, 1, 1);
		REQUIRE(vec.lengthSqrd() == 4);
	}
}


TEST_CASE("Testing variable Vec", "[Vec]") {
	{
		ffw::Vec<int, 4> vec;
		REQUIRE(vec[0] == 0);
		REQUIRE(vec[1] == 0);
		REQUIRE(vec[2] == 0);
		REQUIRE(vec[3] == 0);
	}

	{
		ffw::Vec<int, 4> vec(42);
		REQUIRE(vec[0] == 42);
		REQUIRE(vec[1] == 42);
		REQUIRE(vec[2] == 42);
		REQUIRE(vec[3] == 42);
	}

	{
		ffw::Vec<int, 4> vec({10, 20, 30, 40});
		REQUIRE(vec[0] == 10);
		REQUIRE(vec[1] == 20);
		REQUIRE(vec[2] == 30);
		REQUIRE(vec[3] == 40);
	}

	{
		ffw::Vec<int, 4> vec({ 10, 20, 30, 40, 50 });
		REQUIRE(vec[0] == 0);
		REQUIRE(vec[1] == 0);
		REQUIRE(vec[2] == 0);
		REQUIRE(vec[3] == 0);
	}

	{
		ffw::Vec<int, 4> vec;
		vec.set(42);
		REQUIRE(vec[0] == 42);
		REQUIRE(vec[1] == 42);
		REQUIRE(vec[2] == 42);
		REQUIRE(vec[3] == 42);
	}

	{
		ffw::Vec<int, 4> vec;
		vec.set({ 10, 20, 30, 40 });
		REQUIRE(vec[0] == 10);
		REQUIRE(vec[1] == 20);
		REQUIRE(vec[2] == 30);
		REQUIRE(vec[3] == 40);
	}

	{
		ffw::Vec<int, 4> vec = { 10, 20, 30, 40 };
		REQUIRE(vec[0] == 10);
		REQUIRE(vec[1] == 20);
		REQUIRE(vec[2] == 30);
		REQUIRE(vec[3] == 40);
	}

	{
		ffw::Vec<int, 4> a({ 1, 5, 10, 6 });
		ffw::Vec<int, 4> b({ 5, 10, 2, 2 });
		ffw::Vec<int, 4> c = a + b;
		REQUIRE(c[0] == 6);
		REQUIRE(c[1] == 15);
		REQUIRE(c[2] == 12);
		REQUIRE(c[3] == 8);
		REQUIRE(a + b == c);
		b += a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec<int, 4> a({ 5, 10, 20, 15 });
		ffw::Vec<int, 4> b({ 1, 5, 5, 3 });
		ffw::Vec<int, 4> c = a - b;
		REQUIRE(c[0] == 4);
		REQUIRE(c[1] == 5);
		REQUIRE(c[2] == 15);
		REQUIRE(c[3] == 12);
		REQUIRE(a - b == c);
		a -= b;
		REQUIRE(a == c);
	}

	{
		ffw::Vec<int, 4> a({ 5, 10, 8, 15 });
		ffw::Vec<int, 4> b({ 1, 5, 2, 3 });
		ffw::Vec<int, 4> c = a * b;
		REQUIRE(c[0] == 5);
		REQUIRE(c[1] == 50);
		REQUIRE(c[2] == 16);
		REQUIRE(c[3] == 45);
		REQUIRE(a * b == c);
		b *= a;
		REQUIRE(b == c);
	}

	{
		ffw::Vec<int, 4> a({ 6, 12, 25, 15 });
		ffw::Vec<int, 4> b({ 2, 3, 5, 3 });
		ffw::Vec<int, 4> c = a / b;
		REQUIRE(c[0] == 3);
		REQUIRE(c[1] == 4);
		REQUIRE(c[2] == 5);
		REQUIRE(c[3] == 5);
		REQUIRE(a / b == c);
		a /= b;
		REQUIRE(a == c);
	}


	auto a = ffw::Vec<int, 4>({ 1, 2, 3, 4 }); auto b = ffw::Vec<int, 4>({ 1, 2, 3, 4 });
	REQUIRE(a == b);

	auto c = ffw::Vec<int, 4>({ 1, 2, 3, 4 }); auto d = ffw::Vec<int, 4>({ 2, 2, 2, 4 });
	REQUIRE(c != d);

	auto e = ffw::Vec<int, 4>({ 1, 2, 3, 4 }); auto f = ffw::Vec<int, 4>({ 1, 1, 1, 4 });
	REQUIRE(e != f);

	auto g = ffw::Vec<int, 4>({ 1, 2, 3, 4 }); auto h = ffw::Vec<int, 4>({ 3, 3, 3, 4 });
	REQUIRE(g != h);

	auto i = ffw::Vec<float, 4>({ 1.0f, 2.0f, 3.0f, 4.0f }); auto j = ffw::Vec<float, 4>({ 1.0f, 2.0f, 3.0f, 4.0f });
	REQUIRE(i == j);

	auto k = ffw::Vec<float, 4>({ 1.0f, 2.0f, 3.0f, 4.0f }); auto l = ffw::Vec<float, 4>({ 1.0f, 2.001f, 3.0f, 4.0f });
	REQUIRE(k != l);

	{
		ffw::Vec<int, 4> a({ 6, 12, 16, 15 });
		ffw::Vec<int, 4> b = -a;
		REQUIRE(b[0] == -6);
		REQUIRE(b[1] == -12);
		REQUIRE(b[2] == -16);
		REQUIRE(b[3] == -15);
		b = -b;
		REQUIRE(b == a);
	}

	{
		ffw::Vec<int, 4> vec({ 5, 10, 15, 3 });
		vec.scale(3);
		REQUIRE(vec[0] == 15);
		REQUIRE(vec[1] == 30);
		REQUIRE(vec[2] == 45);
		REQUIRE(vec[3] == 9);
	}

	{
		ffw::Vec<float, 4> vec({ 0.0f, 4.0f, 12.0f, 3.0f });
		vec.normalize();
		REQUIRE(std::fabs(vec[0] - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec[1] - 4.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec[2] - 12.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec[3] - 3.0f / 13.0f) < 0.01f);
	}

	{
		ffw::Vec<float, 4> vec({ 1.0f, 1.0f, 1.0f, 1.0f });
		REQUIRE(vec.lengthSqrd() == Approx(4.0f));
	}

	{
		ffw::Vec<int, 4> vec({ 1, 1, 1, 1 });
		REQUIRE(vec.lengthSqrd() == 4);
	}

	{
		ffw::Vec<float, 4> vec({ 1.0f, 1.0f, 1.0f, 1.0f });
		REQUIRE(std::fabs(vec.length() - sqrt(4.0)) < 0.01);
	}

	{
		ffw::Vec<int, 4> vec({ 1, 1, 1, 1 });
		REQUIRE(std::fabs(vec.length() - sqrt(4.0)) < 0.01);
	}
}

TEST_CASE("Testing Color", "[Color]") {
	{
		ffw::Color vec;
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
		REQUIRE(vec.w == 0);
	}

	{
		ffw::Color vec(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
		REQUIRE(vec.z == 42);
		REQUIRE(vec.w == 42);
	}

	{
		ffw::Color vec(10, 20, 30, 40);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Color vec({ 10, 20, 30, 40 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Color vec({ 10, 20, 30, 40, 50 });
		REQUIRE(vec.x == 0);
		REQUIRE(vec.y == 0);
		REQUIRE(vec.z == 0);
		REQUIRE(vec.w == 0);
	}

	{
		ffw::Color vec;
		vec.set(42);
		REQUIRE(vec.x == 42);
		REQUIRE(vec.y == 42);
		REQUIRE(vec.z == 42);
		REQUIRE(vec.w == 42);
	}

	{
		ffw::Color vec;
		vec.set(10, 20, 30, 40);
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Color vec;
		vec.set({ 10, 20, 30, 40 });
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Color vec(5);
		vec.set({ 10, 20, 30, 40, 50 });
		REQUIRE(vec.x == 5);
		REQUIRE(vec.y == 5);
		REQUIRE(vec.z == 5);
		REQUIRE(vec.w == 5);
	}

	{
		ffw::Color vec = { 10, 20, 30, 40 };
		REQUIRE(vec.x == 10);
		REQUIRE(vec.y == 20);
		REQUIRE(vec.z == 30);
		REQUIRE(vec.w == 40);
	}

	{
		ffw::Color a(1, 5, 10, 6);
		ffw::Color b(5, 10, 2, 2);
		ffw::Color c = a + b;
		REQUIRE(c.x == 6);
		REQUIRE(c.y == 15);
		REQUIRE(c.z == 12);
		REQUIRE(c.w == 8);
		REQUIRE(a + b == c);
		b += a;
		REQUIRE(b == c);
	}

	{
		ffw::Color a(5, 10, 20, 15);
		ffw::Color b(1, 5, 5, 3);
		ffw::Color c = a - b;
		REQUIRE(c.x == 4);
		REQUIRE(c.y == 5);
		REQUIRE(c.z == 15);
		REQUIRE(c.w == 12);
		REQUIRE(a - b == c);
		a -= b;
		REQUIRE(a == c);
	}

	{
		ffw::Color a(5, 10, 8, 15);
		ffw::Color b(1, 5, 2, 3);
		ffw::Color c = a * b;
		REQUIRE(c.x == 5);
		REQUIRE(c.y == 50);
		REQUIRE(c.z == 16);
		REQUIRE(c.w == 45);
		REQUIRE(a * b == c);
		b *= a;
		REQUIRE(b == c);
	}

	{
		ffw::Color a(6, 12, 25, 15);
		ffw::Color b(2, 3, 5, 3);
		ffw::Color c = a / b;
		REQUIRE(c.x == 3);
		REQUIRE(c.y == 4);
		REQUIRE(c.z == 5);
		REQUIRE(c.w == 5);
		REQUIRE(a / b == c);
		a /= b;
		REQUIRE(a == c);
	}

	REQUIRE(ffw::Color(1, 2, 3, 4) == ffw::Color(1, 2, 3, 4));
	REQUIRE(ffw::Color(1, 2, 3, 4) != ffw::Color(2, 2, 2, 4));
	REQUIRE(ffw::Color(1, 2, 3, 4) != ffw::Color(1, 1, 1, 4));
	REQUIRE(ffw::Color(1, 2, 3, 4) != ffw::Color(3, 3, 3, 4));
	REQUIRE(ffw::Color(1.0f, 2.0f, 3.0f, 4.0f) == ffw::Color(1.0f, 2.0f, 3.0f, 4.0f));
	REQUIRE(ffw::Color(1.0f, 2.0f, 3.0f, 4.0f) != ffw::Color(1.0f, 2.001f, 3.0f, 4.0f));

	{
		ffw::Color a(6, 12, 16, 15);
		ffw::Color b = -a;
		REQUIRE(b.x == -6);
		REQUIRE(b.y == -12);
		REQUIRE(b.z == -16);
		REQUIRE(b.w == -15);
		b = -b;
		REQUIRE(b == a);
	}

	{
		ffw::Color vec(5, 10, 15, 3);
		vec.scale(3);
		REQUIRE(vec.x == 15);
		REQUIRE(vec.y == 30);
		REQUIRE(vec.z == 45);
		REQUIRE(vec.w == 9);
	}

	{
		ffw::Color vec(0.0f, 4.0f, 12.0f, 3.0f);
		vec.normalize();
		REQUIRE(std::fabs(vec.x - 0.0f) < 0.01f);
		REQUIRE(std::fabs(vec.y - 4.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec.z - 12.0f / 13.0f) < 0.01f);
		REQUIRE(std::fabs(vec.w - 1.0f) < 0.01f);
	}

	{
		ffw::Color vec(1.0f, 1.0f, 1.0f, 1.0f);
		REQUIRE(std::fabs(vec.length() - sqrt(4.0)) < 0.01);
	}

	{
		ffw::Color vec(1, 1, 1, 1);
		REQUIRE(std::fabs(vec.length() - sqrt(4.0)) < 0.01);
	}

	{
		ffw::Color vec(1.0f, 1.0f, 1.0f, 1.0f);
		REQUIRE(vec.lengthSqrd() == 4.0f);
	}

	{
		ffw::Color vec(1, 1, 1, 1);
		REQUIRE(vec.lengthSqrd() == 4);
	}
}