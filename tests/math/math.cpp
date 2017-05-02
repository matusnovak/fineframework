#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

float multiply(float a, float b) {
	return a * b;
}

std::string lowercase(std::string str) {
	for(auto& c : str) {
		c = tolower(c);
	}
	return str;
}

size_t sleep(size_t ms) {
	ffw::sleep(ms);
	return ms;
}

class Test {
public:
	float multiply(float a, float b) {
		return a * b * c;
	}

	std::string lowercase(std::string str) {
		for (auto& c : str) {
			c = tolower(c);
		}
		return str + extra;
	}
	
	float c; // Some extra member value
	std::string extra;
};

TEST_CASE("Run thread on global static function", "[Thread]") {
	SECTION("Multiply floats") {
		ffw::Thread<float(float, float)> thread;
		REQUIRE(thread.run(&::multiply, 5.0f, 3.0f));
		thread.join();
		REQUIRE(thread.getResult() == Approx(15.0f));
	}

	SECTION("Convert to lower case") {
		ffw::Thread<std::string(std::string)> thread;
		REQUIRE(thread.run(&::lowercase, "Hello World"));
		thread.join();
		REQUIRE(thread.getResult() == "hello world");
	}
}

TEST_CASE("Run thread on member function", "[Thread]") {
	SECTION("Multiply floats") {
		Test test;
		test.c = 2.0f;

		ffw::Thread<float(float, float)> thread;
		REQUIRE(thread.run(&Test::multiply, &test, 5.0f, 3.0f));
		thread.join();
		REQUIRE(thread.getResult() == Approx(30.0f));
	}

	SECTION("Convert to lower case") {
		Test test;
		test.extra = " extra";

		ffw::Thread<std::string(std::string)> thread;
		REQUIRE(thread.run(&Test::lowercase, &test, "Hello World"));
		thread.join();
		REQUIRE(thread.getResult() == "hello world extra");
	}
}

TEST_CASE("Run thread on sleep function", "[Thread]") {
	ffw::Thread<size_t(size_t)> thread;
	REQUIRE(thread.run(&::sleep, 1000));
	REQUIRE(thread.isRunning() == true);
	std::cout << "waiting for thread to finish..." << std::endl;
	thread.join();
	std::cout << "thread done" << std::endl;
	REQUIRE(thread.getResult() == 1000);
	REQUIRE(thread.isRunning() == false);
}

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

TEST_CASE("Testing getFileInfo", "[FileInfo]") {
	{
		std::string path = "C:/Hello/World.txt";
		auto info = ffw::getFileInfo(path);
		REQUIRE("C:/Hello/" == info.dir);
		REQUIRE("World" == info.base);
		REQUIRE("txt" == info.ext);
	}

	{
		std::string path = "C:/Hello/World";
		auto info = ffw::getFileInfo(path);
		REQUIRE("C:/Hello/" == info.dir);
		REQUIRE("World" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "C:/Hello/";
		auto info = ffw::getFileInfo(path);
		REQUIRE("C:/Hello/" == info.dir);
		REQUIRE("" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "C:/Hello/.txt";
		auto info = ffw::getFileInfo(path);
		REQUIRE("C:/Hello/" == info.dir);
		REQUIRE(".txt" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "C:";
		auto info = ffw::getFileInfo(path);
		REQUIRE("C:" == info.dir);
		REQUIRE("" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "/Hello/";
		auto info = ffw::getFileInfo(path);
		REQUIRE("/Hello/" == info.dir);
		REQUIRE("" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "./Hello";
		auto info = ffw::getFileInfo(path);
		REQUIRE("./" == info.dir);
		REQUIRE("Hello" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "../../Hello/";
		auto info = ffw::getFileInfo(path);
		REQUIRE("../../Hello/" == info.dir);
		REQUIRE("" == info.base);
		REQUIRE("" == info.ext);
	}

	{
		std::string path = "image.png";
		auto info  = ffw::getFileInfo(path);
		REQUIRE("" == info.dir);
		REQUIRE("image" == info.base);
		REQUIRE("png" == info.ext);
	}

	{
		std::string path = "C:/Hello/world\\file.txt";
		auto info = ffw::getFileInfo(path);
		REQUIRE("C:/Hello/world\\" == info.dir);
		REQUIRE("file" == info.base);
		REQUIRE("txt" == info.ext);
	}
}

TEST_CASE("Testing Var", "[Var]") {
	ffw::Var var[8];

	var[0] = 123;
	var[1] = 123.4f;
	var[2] = 123.4;
	var[3] = 'A';
	var[4] = (const char*)"Abc";
	var[5] = true;
	var[6] = false;
	var[7] = std::string("Abc");

	REQUIRE(var[0].is<int>());
	REQUIRE(var[1].is<float>());
	REQUIRE(var[2].is<double>());
	REQUIRE(var[3].is<char>());
	REQUIRE(var[4].is<const char*>());
	REQUIRE(var[5].is<bool>());
	REQUIRE(var[6].is<bool>());
	REQUIRE(var[7].is<std::string>());

	// Reassign
	var[7] = 123;
	var[6] = 123.4f;
	var[5] = 123.4;
	var[4] = 'A';
	var[3] = (const char*)"Abc";
	var[2] = true;
	var[1] = false;
	var[0] = std::string("Abc");

	REQUIRE(var[0].is<std::string>());
	REQUIRE(var[1].is<bool>());
	REQUIRE(var[2].is<bool>());
	REQUIRE(var[3].is<const char*>());
	REQUIRE(var[4].is<char>());
	REQUIRE(var[5].is<double>());
	REQUIRE(var[6].is<float>());
	REQUIRE(var[7].is<int>());

	REQUIRE((std::string)var[0] == "Abc");
	REQUIRE((bool)var[1] == false);
	REQUIRE((bool)var[2] == true);
	REQUIRE(strcmp((const char*)var[3], "Abc") == 0);
	REQUIRE((char)var[4] == 'A');
	REQUIRE((double)var[5] == 123.4);
	REQUIRE((float)var[6] == 123.4f);
	REQUIRE((int)var[7] == 123);

	//REQUIRE(var[1] == false);
	//REQUIRE(var[2] == true);
	REQUIRE(var[4] == 'A');
	REQUIRE(var[5] == 123.4);
	REQUIRE(var[6] == 123.4f);
	REQUIRE(var[7] == 123);

	ffw::Var a = 42;
	ffw::Var b = a;

	REQUIRE((int)a == 42);
	REQUIRE((int)b == 42);

	REQUIRE(a == b);

	a = 41;
	REQUIRE(a != b);

	ffw::Var c = std::string("Hello");
	REQUIRE(c == std::string("Hello"));
}

TEST_CASE("Testing Var Object", "[VarObject]") {
	ffw::Object o;
	REQUIRE(o.size() == 0);

	o = { {"hello", 123} };
	REQUIRE(o.size() == 1);

	ffw::Var copy;
	REQUIRE_NOTHROW(copy = o["hello"]);
	REQUIRE(123 == (int)o["hello"]);

	o.insert({"world", 42.0f});
	REQUIRE(o.size() == 2);

	REQUIRE_NOTHROW(copy = o["world"]);
	REQUIRE(42.0f == (float)o["world"]);

	REQUIRE_NOTHROW(copy = o["error"]);
	REQUIRE_THROWS(copy = o["error"]["error"]);

	ffw::Object obj = {
		{"first", 10},
		{"second", 42.1f},
		{"third", "Hello World!"},
		{"fourth", 0x12345678UL},
		{"fifth", true},
		{"sixth", 88.99}
	};

	REQUIRE(obj.size() == 6);

	try {
		const auto& first = obj["first"];
		const auto& second = obj["second"];
		const auto& third = obj["third"];
		const auto& fourth = obj["fourth"];
		const auto& fifth = obj["fifth"];
		const auto& sixth = obj["sixth"];

		REQUIRE(first.is<int>() == true);
		REQUIRE(second.is<float>() == true);
		REQUIRE(third.is<const char*>() == true);
		REQUIRE(fourth.is<unsigned long>() == true);
		REQUIRE(fifth.is<bool>() == true);
		REQUIRE(sixth.is<double>() == true);

	} catch (std::exception& e){
		(void)e;
		std::cout << e.what() << std::endl;
		REQUIRE(false);
	}

	obj["first"].getAs<int>() = 42;

	REQUIRE((int)obj["first"] == 42);
	REQUIRE(obj["first"] == 42);
	REQUIRE(obj["first"] != 42.0f);

	obj["first"] = 55;

	REQUIRE(obj["first"] == 55);

	ffw::Object big = {
		{"first", ffw::Object{{"hello", 42},{"world", true}}
		},
		{"second", ffw::Object{{"who", "doctor"},{"world", false}}
		},
	};

	try {

		const auto& hello = big["first"]["hello"];
		REQUIRE(hello.is<int>() == true);
		REQUIRE(42 == (int)hello);

		const auto& who = big["second"]["who"];
		REQUIRE(who.is<const char*>() == true);

		std::string test = (const char*)who;

		REQUIRE(strcmp((const char*)big["second"]["who"], "doctor") == 0);
		REQUIRE(test == "doctor");

	} catch (std::exception& e){
		(void)e;
		std::cout << e.what() << std::endl;
		REQUIRE(false);
	}
}

TEST_CASE("Testing Var Array", "[VarArray]") {
	ffw::Array a;
	REQUIRE(a.size() == 0);

	a = {"hello", 123, 42.0f, true};

	REQUIRE(a.size() == 4);

	REQUIRE(a[0].is<const char*>() == true);
	REQUIRE(a[1].is<int>() == true);
	REQUIRE(a[2].is<float>() == true);
	REQUIRE(a[3].is<bool>() == true);

	REQUIRE((bool)a[3] == true);

	a[3] = false;

	REQUIRE(a[3].is<bool>() == true);

	REQUIRE((bool)a[3] == false);
}

TEST_CASE("Testing various math functions", "[Math]") {
	// lerp
	REQUIRE(ffw::lerp(0.0f, 10.0f, 0.5f) == Approx(5.0f));
	REQUIRE(ffw::lerp(-20.0, 10.0, 0.5) == Approx(-5.0));

	// dot product
	REQUIRE(ffw::dot(
		ffw::Vec2d(1.5, 0.0),
		ffw::Vec2d(1.0, 0.0))
		== Approx(3.0 / 2.0));

	REQUIRE(ffw::dot(
		ffw::Vec3d(0.0, 1.5, 0.0),
		ffw::Vec3d(1.0, 1.0, 0.0))
		== Approx(3.0 / 2.0));

	REQUIRE(ffw::dot(
		ffw::Vec4d(0.0, 1.5, 2.0, 0.0),
		ffw::Vec4d(0.0, 1.0, 0.5, 0.0))
		== Approx(5.0 / 2.0));

	// cross product
	REQUIRE(ffw::cross(
		ffw::Vec3f(2.0f, 3.0f, 4.0f),
		ffw::Vec3f(-2.0f, 0.0f, 7.0f))
		== ffw::Vec3f(21.0f, -22.0f, 6.0f));

	REQUIRE(ffw::cross(
		ffw::Vec3f(1.0f, 0.0f, 0.0f),
		ffw::Vec3f(0.0f, 1.0f, 0.0f))
		== ffw::Vec3f(0.0f, 0.0f, 1.0f));

	// distance
	REQUIRE(ffw::distance(
		ffw::Vec2f(7.0f, 4.0f),
		ffw::Vec2f(-2.0f, 5.0f))
		== Approx(9.0554f));

	REQUIRE(ffw::distance(
		ffw::Vec3f(7.0f, 4.0f, -9.0f),
		ffw::Vec3f(-2.0f, 5.0f, 1.0f))
		== Approx(13.490738f));

	REQUIRE(ffw::distance(
		ffw::Vec4f(1.0f, 7.0f, 4.0f, -9.0f),
		ffw::Vec4f(-1.0f, -2.0f, 5.0f, 1.0f))
		== Approx(13.63818f));

	// middle
	REQUIRE(ffw::middle(
		ffw::Vec2f(3.0f, 0.0f),
		ffw::Vec2f(-3.0f, 1.0f))
		== ffw::Vec2f(0.0f, 0.5f));

	REQUIRE(ffw::middle(
		ffw::Vec3f(3.0f, 0.0f, -2.0f),
		ffw::Vec3f(-3.0f, 1.0f, -5.0f))
		== ffw::Vec3f(0.0f, 0.5f, -3.5f));

	REQUIRE(ffw::middle(
		ffw::Vec4f(3.0f, 0.0f, -2.0f, 0.0f),
		ffw::Vec4f(-3.0f, 1.0f, -5.0f, 100.f))
		== ffw::Vec4f(0.0f, 0.5f, -3.5f, 50.0f));

	// normalize
	{
		auto v = ffw::Vec2f(1.0f, 2.0f).normalize();
		REQUIRE(v == ffw::normalize(ffw::Vec2f(1.0f, 2.0f)));
	}

	{
		auto v = ffw::Vec3f(-2.0f, 7.0f, 3.0f).normalize();
		REQUIRE(v == ffw::normalize(ffw::Vec3f(-2.0f, 7.0f, 3.0f)));
	}

	{
		auto v = ffw::Vec4f(-2.0f, 7.0f, 3.0f, -1.0f).normalize();
		REQUIRE(v == ffw::normalize(ffw::Vec4f(-2.0f, 7.0f, 3.0f, -1.0f)));
	}

	{
		auto v = ffw::Color(1.7f, 0.5f, 3.1f, 0.2f).normalize();
		REQUIRE(v == ffw::normalize(ffw::Color(1.7f, 0.5f, 3.1f, 0.2f)));
	}

	// angle
	REQUIRE(ffw::angle(
		ffw::Vec2f(1.0f, 0.0f),
		ffw::Vec2f(0.0f, 1.0f))
		== Approx(90.0f));

	REQUIRE(ffw::angle(
		ffw::Vec2f(0.707f, 0.707f),
		ffw::Vec2f(0.0f, 1.0f))
		== Approx(45.0f));

	REQUIRE(ffw::AngleRad(
		ffw::Vec2f(1.0f, 0.0f),
		ffw::Vec2f(0.0f, 1.0f))
		== Approx(90.0f * DEG_TO_RAD));

	REQUIRE(ffw::AngleRad(
		ffw::Vec2f(0.707f, 0.707f),
		ffw::Vec2f(0.0f, 1.0f))
		== Approx(45.0f * DEG_TO_RAD));

	REQUIRE(ffw::angle(
		ffw::Vec3f(-1.0f, 2.0f, 3.0f),
		ffw::Vec3f(4.0f, 5.0f, 6.0f))
		== Approx(43.03190f));

	REQUIRE(ffw::AngleRad(
		ffw::Vec3f(-1.0f, 2.0f, 3.0f),
		ffw::Vec3f(4.0f, 5.0f, 6.0f))
		== Approx(43.03190f * DEG_TO_RAD));

	// clamp
	REQUIRE(ffw::clamp(4.2f, 0.0f, 1.0f) == Approx(1.0f));
	REQUIRE(ffw::clamp(4.2f, -5.0f, 0.7f) == Approx(0.7f));
	REQUIRE(ffw::clamp(0.1f, -5.0f, 0.7f) == Approx(0.1f));
	REQUIRE(ffw::clamp(4.2f, -5.0f, -4.7f) == Approx(-4.7f));

	// remap
	REQUIRE(ffw::remap(100.0f, 100.0f, 1000.0f, 1.0f, 20.0f) == Approx(1.0f));
	REQUIRE(ffw::remap(50.0f, -100.0f, 100.0f, 0.0f, 10.0f) == Approx(7.5f));
	REQUIRE(ffw::remap(1500.0f, 0.0f, 1000.0f, 0.0f, 10.0f) == Approx(15.0f));
	REQUIRE(ffw::remap(100.0f, 500.0f, 1000.0f, 5.0f, 10.0f) == Approx(1.0f));

	// NextPowerOfTwo
	REQUIRE(ffw::nextPowOfTwo(2) == 2);
	REQUIRE(ffw::nextPowOfTwo(3) == 4);
	REQUIRE(ffw::nextPowOfTwo(7) == 8);
	REQUIRE(ffw::nextPowOfTwo(15) == 16);
	REQUIRE(ffw::nextPowOfTwo(4096) == 4096);

	// ByteSwap
	REQUIRE(ffw::byteSwap16(0xFFAA) == 0xAAFF);
	REQUIRE(ffw::byteSwap32(0xFFAABBCCUL) == 0xCCBBAAFFUL);
	REQUIRE(ffw::byteSwap64(0xFFAABBCC11223344ULL) == 0x44332211CCBBAAFFULL);
}

TEST_CASE("Testing string tokenizer", "[Math]") {
	{
		std::string str = "  Hello  World! This    is a  sentence...   ";
		const auto tokens = ffw::getTokens(str, " ");
		REQUIRE(tokens.size() == 6);
		REQUIRE(tokens.size() == ffw::getTokensNum(str, " "));
		REQUIRE(tokens[0] == "Hello");
		REQUIRE(tokens[1] == "World!");
		REQUIRE(tokens[2] == "This");
		REQUIRE(tokens[3] == "is");
		REQUIRE(tokens[4] == "a");
		REQUIRE(tokens[5] == "sentence...");
	}

	{
		std::string str = "  Hello  World! This    is a  sentence...   ";
		const auto tokens = ffw::getTokens(str, ' ');
		REQUIRE(tokens.size() == 6);
		REQUIRE(tokens.size() == ffw::getTokensNum(str, ' '));
		REQUIRE(tokens[0] == "Hello");
		REQUIRE(tokens[1] == "World!");
		REQUIRE(tokens[2] == "This");
		REQUIRE(tokens[3] == "is");
		REQUIRE(tokens[4] == "a");
		REQUIRE(tokens[5] == "sentence...");
	}

	{
		std::string str = " Hello  World! This is a  sentence...   ";
		const auto tokens = ffw::getTokens(str, "  ");
		REQUIRE(tokens.size() == 4);
		REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
		REQUIRE(tokens[0] == " Hello");
		REQUIRE(tokens[1] == "World! This is a");
		REQUIRE(tokens[2] == "sentence...");
		REQUIRE(tokens[3] == " ");
	}

	{
		std::string str = " Hello  World! This is a  sentence...  ";
		const auto tokens = ffw::getTokens(str, "  ");
		REQUIRE(tokens.size() == 3);
		REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
		REQUIRE(tokens[0] == " Hello");
		REQUIRE(tokens[1] == "World! This is a");
		REQUIRE(tokens[2] == "sentence...");
	}

	{
		std::string str = "        ";
		const auto tokens = ffw::getTokens(str, "  ");
		REQUIRE(tokens.size() == 0);
		REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
	}

	{
		std::string str = "         ";
		const auto tokens = ffw::getTokens(str, "  ");
		REQUIRE(tokens.size() == 1);
		REQUIRE(tokens.size() == ffw::getTokensNum(str, "  "));
		REQUIRE(tokens[0] == " ");
	}

	{
		std::string str = "DELIMHelloDELIMWorldDELIMDELIMWhat";
		const auto tokens = ffw::getTokens(str, "DELIM");
		REQUIRE(tokens.size() == 3);
		REQUIRE(tokens[0] == "Hello");
		REQUIRE(tokens[1] == "World");
		REQUIRE(tokens[2] == "What");
	}

	{
		std::string str = "DELIMDELIMDELIMDELIMDELIMDELIMDELIM";
		const auto tokens = ffw::getTokens(str, "DELIM");
		REQUIRE(tokens.size() == 0);
	}
}

TEST_CASE("Testing coverImage", "[Math]") {
	{
		ffw::Vec4i result = ffw::coverImage(1000, 1000, 1000, 500);
		REQUIRE(result.x == 0);
		REQUIRE(result.y == -250);
		REQUIRE(result.z == 1000);
		REQUIRE(result.w == 1000);
	}

	{
		ffw::Vec4i result = ffw::coverImage(1000, 1000, 500, 250);
		REQUIRE(result.x == 0);
		REQUIRE(result.y == -125);
		REQUIRE(result.z == 500);
		REQUIRE(result.w == 500);
	}

	{
		ffw::Vec4i result = ffw::coverImage(1000, 500, 1920, 1080);
		REQUIRE(result.x == -120);
		REQUIRE(result.y == 0);
		REQUIRE(result.z == 2160);
		REQUIRE(result.w == 1080);
	}

	{
		ffw::Vec4i result = ffw::coverImage(500, 1000, 1920, 1080);
		REQUIRE(result.x == 0);
		REQUIRE(result.y == -1380);
		REQUIRE(result.z == 1920);
		REQUIRE(result.w == 3840);
	}
}

TEST_CASE("Testing containImage", "[Math]") {
	{
		ffw::Vec4i result = ffw::containImage(1000, 1000, 1000, 500);
		REQUIRE(result.x == 250);
		REQUIRE(result.y == 0);
		REQUIRE(result.z == 500);
		REQUIRE(result.w == 500);
	}

	{
		ffw::Vec4i result = ffw::containImage(1000, 1000, 500, 250);
		REQUIRE(result.x == 125);
		REQUIRE(result.y == 0);
		REQUIRE(result.z == 250);
		REQUIRE(result.w == 250);
	}

	{
		ffw::Vec4i result = ffw::containImage(1000, 500, 1920, 1080);
		REQUIRE(result.x == 0);
		REQUIRE(result.y == 60);
		REQUIRE(result.z == 1920);
		REQUIRE(result.w == 960);
	}

	{
		ffw::Vec4i result = ffw::containImage(500, 1000, 1920, 1080);
		REQUIRE(result.x == 690);
		REQUIRE(result.y == 0);
		REQUIRE(result.z == 540);
		REQUIRE(result.w == 1080);
	}
}

TEST_CASE("Testing RingBuffer", "[RingBuffer]") {
	ffw::RingBuffer<int> buffer;

	REQUIRE(buffer.getSize() == 0);
	REQUIRE(buffer.back() == NULL);
	REQUIRE(buffer.range() == 0);

	buffer.create(8);

	REQUIRE(buffer.getSize() == 0);
	REQUIRE(buffer.back() == NULL);
	REQUIRE(buffer.range() == 8);

	REQUIRE(buffer.push(1) == true);
	REQUIRE(*buffer.back() == 1);
	REQUIRE(buffer.push(2) == true);
	REQUIRE(*buffer.back() == 1);
	REQUIRE(buffer.push(3) == true);
	REQUIRE(buffer.push(4) == true);
	REQUIRE(buffer.push(5) == true);
	REQUIRE(buffer.push(6) == true);
	REQUIRE(buffer.push(7) == true);
	REQUIRE(buffer.push(8) == true);
	REQUIRE(*buffer.back() == 1);
	REQUIRE(buffer.push(9) != true);
	REQUIRE(*buffer.back() == 1);

	for (int i = 1; i < 9; i++) {
		REQUIRE(*buffer.back() == i);
		int popped;
		REQUIRE(buffer.pop(&popped) == true);
		REQUIRE(popped == i);
		REQUIRE(buffer.getSize() == (8 - i));
	}

	REQUIRE(buffer.getSize() == 0);
	REQUIRE(buffer.back() == NULL);
	REQUIRE(buffer.range() == 8);


	REQUIRE(buffer.push(42) == true);
	REQUIRE(buffer.getSize() == 1);
	buffer.reset();

	REQUIRE(buffer.getSize() == 0);
	REQUIRE(buffer.back() == NULL);
	REQUIRE(buffer.range() == 8);

	buffer.clear();
	REQUIRE(buffer.getSize() == 0);
	REQUIRE(buffer.back() == NULL);
	REQUIRE(buffer.range() == 0);
}

TEST_CASE("Testing string tokenization", "[Tokenizer]") {
	{
		std::string str = "Hello World!";
		ffw::Tokenizer<char> tokenizer(str, " ");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "Hello");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "World!");
		REQUIRE(tokenizer.hasNext() == false);
		REQUIRE(tokenizer.getNext() == "");
	}

	{
		std::string str = "Hello World!";
		ffw::Tokenizer<char> tokenizer(str, "  ");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "Hello World!");
		REQUIRE(tokenizer.hasNext() == false);
		REQUIRE(tokenizer.getNext() == "");
	}

	{
		std::string str = "Hello  World!";
		ffw::Tokenizer<char> tokenizer(str, "  ");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "Hello");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "World!");
		REQUIRE(tokenizer.hasNext() == false);
		REQUIRE(tokenizer.getNext() == "");
	}

	{
		std::string str = "     Hello        World!     ";
		ffw::Tokenizer<char> tokenizer(str, " ");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "Hello");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "World!");
		REQUIRE(tokenizer.hasNext() == false);
		REQUIRE(tokenizer.getNext() == "");
	}

	{
		std::string str = "     Hello        World!   Example  ";
		ffw::Tokenizer<char> tokenizer(str, " ");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "Hello");
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.skipNext() == true);
		REQUIRE(tokenizer.hasNext() == true);
		REQUIRE(tokenizer.getNext() == "Example");
		REQUIRE(tokenizer.hasNext() == false);
		REQUIRE(tokenizer.getNext() == "");
	}
}

TEST_CASE("Testing UTF8 To WSTR", "[Unicode]") {
	// Samples taken from:
	// http://www.cl.cam.ac.uk/~mgk25/ucs/examples/quickbrown.txt

	{
		// Danish
		static const std::string str = "\x51\x75\x69\x7A\x64\x65\x6C\x74\x61\x67\x65\x72\x6E\x65\x20\x73\x70\x69\x73\x74\x65\x20\x6A\x6F\x72\x64\x62\xC3\xA6\x72\x20\x6D\x65\x64\x20\x66\x6C\xC3\xB8\x64\x65\x2C\x20\x6D\x65\x6E\x73\x20\x63\x69\x72\x6B\x75\x73\x6B\x6C\x6F\x76\x6E\x65\x6E\x20\x57\x6F\x6C\x74\x68\x65\x72\x20\x73\x70\x69\x6C\x6C\x65\x64\x65\x20\x70\xC3\xA5\x20\x78\x79\x6C\x6F\x66\x6F\x6E\x2E";
		static const std::wstring wstr = L"\x0051\x0075\x0069\x007A\x0064\x0065\x006C\x0074\x0061\x0067\x0065\x0072\x006E\x0065\x0020\x0073\x0070\x0069\x0073\x0074\x0065\x0020\x006A\x006F\x0072\x0064\x0062\x00E6\x0072\x0020\x006D\x0065\x0064\x0020\x0066\x006C\x00F8\x0064\x0065\x002C\x0020\x006D\x0065\x006E\x0073\x0020\x0063\x0069\x0072\x006B\x0075\x0073\x006B\x006C\x006F\x0076\x006E\x0065\x006E\x0020\x0057\x006F\x006C\x0074\x0068\x0065\x0072\x0020\x0073\x0070\x0069\x006C\x006C\x0065\x0064\x0065\x0020\x0070\x00E5\x0020\x0078\x0079\x006C\x006F\x0066\x006F\x006E\x002E";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// German Part 1
		static const std::string str = "\x46\x61\x6C\x73\x63\x68\x65\x73\x20\xC3\x9C\x62\x65\x6E\x20\x76\x6F\x6E\x20\x58\x79\x6C\x6F\x70\x68\x6F\x6E\x6D\x75\x73\x69\x6B\x20\x71\x75\xC3\xA4\x6C\x74\x20\x6A\x65\x64\x65\x6E\x20\x67\x72\xC3\xB6\xC3\x9F\x65\x72\x65\x6E\x20\x5A\x77\x65\x72\x67\x20";
		static const std::wstring wstr = L"\x0046\x0061\x006C\x0073\x0063\x0068\x0065\x0073\x0020\x00DC\x0062\x0065\x006E\x0020\x0076\x006F\x006E\x0020\x0058\x0079\x006C\x006F\x0070\x0068\x006F\x006E\x006D\x0075\x0073\x0069\x006B\x0020\x0071\x0075\x00E4\x006C\x0074\x0020\x006A\x0065\x0064\x0065\x006E\x0020\x0067\x0072\x00F6\x00DF\x0065\x0072\x0065\x006E\x0020\x005A\x0077\x0065\x0072\x0067\x0020";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// German Part 2
		static const std::string str = "\x5A\x77\xC3\xB6\x6C\x66\x20\x42\x6F\x78\x6B\xC3\xA4\x6D\x70\x66\x65\x72\x20\x6A\x61\x67\x74\x65\x6E\x20\x45\x76\x61\x20\x71\x75\x65\x72\x20\xC3\xBC\x62\x65\x72\x20\x64\x65\x6E\x20\x53\x79\x6C\x74\x65\x72\x20\x44\x65\x69\x63\x68";
		static const std::wstring wstr = L"\x005A\x0077\x00F6\x006C\x0066\x0020\x0042\x006F\x0078\x006B\x00E4\x006D\x0070\x0066\x0065\x0072\x0020\x006A\x0061\x0067\x0074\x0065\x006E\x0020\x0045\x0076\x0061\x0020\x0071\x0075\x0065\x0072\x0020\x00FC\x0062\x0065\x0072\x0020\x0064\x0065\x006E\x0020\x0053\x0079\x006C\x0074\x0065\x0072\x0020\x0044\x0065\x0069\x0063\x0068";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// German Part 2
		static const std::string str = "\x48\x65\x69\x7A\xC3\xB6\x6C\x72\xC3\xBC\x63\x6B\x73\x74\x6F\xC3\x9F\x61\x62\x64\xC3\xA4\x6D\x70\x66\x75\x6E\x67";
		static const std::wstring wstr = L"\x0048\x0065\x0069\x007A\x00F6\x006C\x0072\x00FC\x0063\x006B\x0073\x0074\x006F\x00DF\x0061\x0062\x0064\x00E4\x006D\x0070\x0066\x0075\x006E\x0067";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Greek Part 1
		static const std::string str = "\xCE\x93\xCE\xB1\xCE\xB6\xCE\xAD\xCE\xB5\xCF\x82\x20\xCE\xBA\xCE\xB1\xE1\xBD\xB6\x20\xCE\xBC\xCF\x85\xCF\x81\xCF\x84\xCE\xB9\xE1\xBD\xB2\xCF\x82\x20\xCE\xB4\xE1\xBD\xB2\xCE\xBD\x20\xCE\xB8\xE1\xBD\xB0\x20\xCE\xB2\xCF\x81\xE1\xBF\xB6\x20\xCF\x80\xCE\xB9\xE1\xBD\xB0\x20\xCF\x83\xCF\x84\xE1\xBD\xB8\x20\xCF\x87\xCF\x81\xCF\x85\xCF\x83\xCE\xB1\xCF\x86\xE1\xBD\xB6\x20\xCE\xBE\xCE\xAD\xCF\x86\xCF\x89\xCF\x84\xCE\xBF";
		static const std::wstring wstr = L"\x0393\x03B1\x03B6\x03AD\x03B5\x03C2\x0020\x03BA\x03B1\x1F76\x0020\x03BC\x03C5\x03C1\x03C4\x03B9\x1F72\x03C2\x0020\x03B4\x1F72\x03BD\x0020\x03B8\x1F70\x0020\x03B2\x03C1\x1FF6\x0020\x03C0\x03B9\x1F70\x0020\x03C3\x03C4\x1F78\x0020\x03C7\x03C1\x03C5\x03C3\x03B1\x03C6\x1F76\x0020\x03BE\x03AD\x03C6\x03C9\x03C4\x03BF";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Greek Part 2
		static const std::string str = "\xCE\x9E\xCE\xB5\xCF\x83\xCE\xBA\xCE\xB5\xCF\x80\xCE\xAC\xCE\xB6\xCF\x89\x20\xCF\x84\xE1\xBD\xB4\xCE\xBD\x20\xCF\x88\xCF\x85\xCF\x87\xCE\xBF\xCF\x86\xCE\xB8\xCF\x8C\xCF\x81\xCE\xB1\x20\xCE\xB2\xCE\xB4\xCE\xB5\xCE\xBB\xCF\x85\xCE\xB3\xCE\xBC\xCE\xAF\xCE\xB1";
		static const std::wstring wstr = L"\x039E\x03B5\x03C3\x03BA\x03B5\x03C0\x03AC\x03B6\x03C9\x0020\x03C4\x1F74\x03BD\x0020\x03C8\x03C5\x03C7\x03BF\x03C6\x03B8\x03CC\x03C1\x03B1\x0020\x03B2\x03B4\x03B5\x03BB\x03C5\x03B3\x03BC\x03AF\x03B1";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// English
		static const std::string str = "\x54\x68\x65\x20\x71\x75\x69\x63\x6B\x20\x62\x72\x6F\x77\x6E\x20\x66\x6F\x78\x20\x6A\x75\x6D\x70\x73\x20\x6F\x76\x65\x72\x20\x74\x68\x65\x20\x6C\x61\x7A\x79\x20\x64\x6F\x67";
		static const std::wstring wstr = L"\x0054\x0068\x0065\x0020\x0071\x0075\x0069\x0063\x006B\x0020\x0062\x0072\x006F\x0077\x006E\x0020\x0066\x006F\x0078\x0020\x006A\x0075\x006D\x0070\x0073\x0020\x006F\x0076\x0065\x0072\x0020\x0074\x0068\x0065\x0020\x006C\x0061\x007A\x0079\x0020\x0064\x006F\x0067";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Spanish
		static const std::string str = "\x45\x6C\x20\x70\x69\x6E\x67\xC3\xBC\x69\x6E\x6F\x20\x57\x65\x6E\x63\x65\x73\x6C\x61\x6F\x20\x68\x69\x7A\x6F\x20\x6B\x69\x6C\xC3\xB3\x6D\x65\x74\x72\x6F\x73\x20\x62\x61\x6A\x6F\x20\x65\x78\x68\x61\x75\x73\x74\x69\x76\x61\x20\x6C\x6C\x75\x76\x69\x61\x20\x79\x20\x66\x72\xC3\xAD\x6F\x2C\x20\x61\xC3\xB1\x6F\x72\x61\x62\x61\x20\x61\x20\x73\x75\x20\x71\x75\x65\x72\x69\x64\x6F\x20\x63\x61\x63\x68\x6F\x72\x72\x6F\x2E";
		static const std::wstring wstr = L"\x0045\x006C\x0020\x0070\x0069\x006E\x0067\x00FC\x0069\x006E\x006F\x0020\x0057\x0065\x006E\x0063\x0065\x0073\x006C\x0061\x006F\x0020\x0068\x0069\x007A\x006F\x0020\x006B\x0069\x006C\x00F3\x006D\x0065\x0074\x0072\x006F\x0073\x0020\x0062\x0061\x006A\x006F\x0020\x0065\x0078\x0068\x0061\x0075\x0073\x0074\x0069\x0076\x0061\x0020\x006C\x006C\x0075\x0076\x0069\x0061\x0020\x0079\x0020\x0066\x0072\x00ED\x006F\x002C\x0020\x0061\x00F1\x006F\x0072\x0061\x0062\x0061\x0020\x0061\x0020\x0073\x0075\x0020\x0071\x0075\x0065\x0072\x0069\x0064\x006F\x0020\x0063\x0061\x0063\x0068\x006F\x0072\x0072\x006F\x002E";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// French
		static const std::string str = "\x4C\x65\x20\x63\xC5\x93\x75\x72\x20\x64\xC3\xA9\xC3\xA7\x75\x20\x6D\x61\x69\x73\x20\x6C\x27\xC3\xA2\x6D\x65\x20\x70\x6C\x75\x74\xC3\xB4\x74\x20\x6E\x61\xC3\xAF\x76\x65\x2C\x20\x4C\x6F\x75\xC3\xBF\x73\x20\x72\xC3\xAA\x76\x61\x20\x64\x65\x20\x63\x72\x61\x70\x61\xC3\xBC\x74\x65\x72\x20\x65\x6E\x20\x63\x61\x6E\x6F\xC3\xAB\x20\x61\x75\x20\x64\x65\x6C\xC3\xA0\x20\x64\x65\x73\x20\xC3\xAE\x6C\x65\x73\x2C\x20\x70\x72\xC3\xA8\x73\x20\x64\x75\x20\x6D\xC3\xA4\x6C\x73\x74\x72\xC3\xB6\x6D\x20\x6F\xC3\xB9\x20\x62\x72\xC3\xBB\x6C\x65\x6E\x74\x20\x6C\x65\x73\x20\x6E\x6F\x76\xC3\xA6\x2E";
		static const std::wstring wstr = L"\x004C\x0065\x0020\x0063\x0153\x0075\x0072\x0020\x0064\x00E9\x00E7\x0075\x0020\x006D\x0061\x0069\x0073\x0020\x006C\x0027\x00E2\x006D\x0065\x0020\x0070\x006C\x0075\x0074\x00F4\x0074\x0020\x006E\x0061\x00EF\x0076\x0065\x002C\x0020\x004C\x006F\x0075\x00FF\x0073\x0020\x0072\x00EA\x0076\x0061\x0020\x0064\x0065\x0020\x0063\x0072\x0061\x0070\x0061\x00FC\x0074\x0065\x0072\x0020\x0065\x006E\x0020\x0063\x0061\x006E\x006F\x00EB\x0020\x0061\x0075\x0020\x0064\x0065\x006C\x00E0\x0020\x0064\x0065\x0073\x0020\x00EE\x006C\x0065\x0073\x002C\x0020\x0070\x0072\x00E8\x0073\x0020\x0064\x0075\x0020\x006D\x00E4\x006C\x0073\x0074\x0072\x00F6\x006D\x0020\x006F\x00F9\x0020\x0062\x0072\x00FB\x006C\x0065\x006E\x0074\x0020\x006C\x0065\x0073\x0020\x006E\x006F\x0076\x00E6\x002E";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Irish Galeic
		static const std::string str = "\x44\x27\x66\x68\x75\x61\x73\x63\x61\x69\x6C\x20\xC3\x8D\x6F\x73\x61\x2C\x20\xC3\x9A\x72\x6D\x68\x61\x63\x20\x6E\x61\x20\x68\xC3\x93\x69\x67\x68\x65\x20\x42\x65\x61\x6E\x6E\x61\x69\x74\x68\x65\x2C\x20\x70\xC3\xB3\x72\x20\xC3\x89\x61\x76\x61\x20\x61\x67\x75\x73\x20\xC3\x81\x64\x68\x61\x69\x6D\x68";
		static const std::wstring wstr = L"\x0044\x0027\x0066\x0068\x0075\x0061\x0073\x0063\x0061\x0069\x006C\x0020\x00CD\x006F\x0073\x0061\x002C\x0020\x00DA\x0072\x006D\x0068\x0061\x0063\x0020\x006E\x0061\x0020\x0068\x00D3\x0069\x0067\x0068\x0065\x0020\x0042\x0065\x0061\x006E\x006E\x0061\x0069\x0074\x0068\x0065\x002C\x0020\x0070\x00F3\x0072\x0020\x00C9\x0061\x0076\x0061\x0020\x0061\x0067\x0075\x0073\x0020\x00C1\x0064\x0068\x0061\x0069\x006D\x0068";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Hungarian
		static const std::string str = "\xC3\x81\x72\x76\xC3\xAD\x7A\x74\xC5\xB1\x72\xC5\x91\x20\x74\xC3\xBC\x6B\xC3\xB6\x72\x66\xC3\xBA\x72\xC3\xB3\x67\xC3\xA9\x70";
		static const std::wstring wstr = L"\x00C1\x0072\x0076\x00ED\x007A\x0074\x0171\x0072\x0151\x0020\x0074\x00FC\x006B\x00F6\x0072\x0066\x00FA\x0072\x00F3\x0067\x00E9\x0070";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Icelandic
		static const std::string str = "\x4B\xC3\xA6\x6D\x69\x20\x6E\xC3\xBD\x20\xC3\xB6\x78\x69\x20\x68\xC3\xA9\x72\x20\x79\x6B\x69\x73\x74\x20\xC3\xBE\x6A\xC3\xB3\x66\x75\x6D\x20\x6E\xC3\xBA\x20\x62\xC3\xA6\xC3\xB0\x69\x20\x76\xC3\xAD\x6C\x20\x6F\x67\x20\xC3\xA1\x64\x72\x65\x70\x61\x20\x53\xC3\xA6\x76\xC3\xB6\x72\x20\x67\x72\xC3\xA9\x74\x20\xC3\xA1\xC3\xB0\x61\x6E\x20\xC3\xBE\x76\xC3\xAD\x20\xC3\xBA\x6C\x70\x61\x6E\x20\x76\x61\x72\x20\xC3\xB3\x6E\xC3\xBD\x74";
		static const std::wstring wstr = L"\x004B\x00E6\x006D\x0069\x0020\x006E\x00FD\x0020\x00F6\x0078\x0069\x0020\x0068\x00E9\x0072\x0020\x0079\x006B\x0069\x0073\x0074\x0020\x00FE\x006A\x00F3\x0066\x0075\x006D\x0020\x006E\x00FA\x0020\x0062\x00E6\x00F0\x0069\x0020\x0076\x00ED\x006C\x0020\x006F\x0067\x0020\x00E1\x0064\x0072\x0065\x0070\x0061\x0020\x0053\x00E6\x0076\x00F6\x0072\x0020\x0067\x0072\x00E9\x0074\x0020\x00E1\x00F0\x0061\x006E\x0020\x00FE\x0076\x00ED\x0020\x00FA\x006C\x0070\x0061\x006E\x0020\x0076\x0061\x0072\x0020\x00F3\x006E\x00FD\x0074";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Japanese Hiragana
		static const std::string str = "\xE3\x81\x84\xE3\x82\x8D\xE3\x81\xAF\xE3\x81\xAB\xE3\x81\xBB\xE3\x81\xB8\xE3\x81\xA8\xE3\x81\xA1\xE3\x82\x8A\xE3\x81\xAC\xE3\x82\x8B\xE3\x82\x92\xE3\x82\x8F\xE3\x81\x8B\xE3\x82\x88\xE3\x81\x9F\xE3\x82\x8C\xE3\x81\x9D\xE3\x81\xA4\xE3\x81\xAD\xE3\x81\xAA\xE3\x82\x89\xE3\x82\x80\xE3\x81\x86\xE3\x82\x90\xE3\x81\xAE\xE3\x81\x8A\xE3\x81\x8F\xE3\x82\x84\xE3\x81\xBE\xE3\x81\x91\xE3\x81\xB5\xE3\x81\x93\xE3\x81\x88\xE3\x81\xA6\xE3\x81\x82\xE3\x81\x95\xE3\x81\x8D\xE3\x82\x86\xE3\x82\x81\xE3\x81\xBF\xE3\x81\x97\xE3\x82\x91\xE3\x81\xB2\xE3\x82\x82\xE3\x81\x9B\xE3\x81\x99";
		static const std::wstring wstr = L"\x3044\x308D\x306F\x306B\x307B\x3078\x3068\x3061\x308A\x306C\x308B\x3092\x308F\x304B\x3088\x305F\x308C\x305D\x3064\x306D\x306A\x3089\x3080\x3046\x3090\x306E\x304A\x304F\x3084\x307E\x3051\x3075\x3053\x3048\x3066\x3042\x3055\x304D\x3086\x3081\x307F\x3057\x3091\x3072\x3082\x305B\x3059";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Japanese Katakana
		static const std::string str = "\xE3\x82\xA4\xE3\x83\xAD\xE3\x83\x8F\xE3\x83\x8B\xE3\x83\x9B\xE3\x83\x98\xE3\x83\x88\x20\xE3\x83\x81\xE3\x83\xAA\xE3\x83\x8C\xE3\x83\xAB\xE3\x83\xB2\x20\xE3\x83\xAF\xE3\x82\xAB\xE3\x83\xA8\xE3\x82\xBF\xE3\x83\xAC\xE3\x82\xBD\x20\xE3\x83\x84\xE3\x83\x8D\xE3\x83\x8A\xE3\x83\xA9\xE3\x83\xA0\xE3\x82\xA6\xE3\x83\xB0\xE3\x83\x8E\xE3\x82\xAA\xE3\x82\xAF\xE3\x83\xA4\xE3\x83\x9E\x20\xE3\x82\xB1\xE3\x83\x95\xE3\x82\xB3\xE3\x82\xA8\xE3\x83\x86\x20\xE3\x82\xA2\xE3\x82\xB5\xE3\x82\xAD\xE3\x83\xA6\xE3\x83\xA1\xE3\x83\x9F\xE3\x82\xB7\x20\xE3\x83\xB1\xE3\x83\x92\xE3\x83\xA2\xE3\x82\xBB\xE3\x82\xB9\xE3\x83\xB3";
		static const std::wstring wstr = L"\x30A4\x30ED\x30CF\x30CB\x30DB\x30D8\x30C8\x0020\x30C1\x30EA\x30CC\x30EB\x30F2\x0020\x30EF\x30AB\x30E8\x30BF\x30EC\x30BD\x0020\x30C4\x30CD\x30CA\x30E9\x30E0\x30A6\x30F0\x30CE\x30AA\x30AF\x30E4\x30DE\x0020\x30B1\x30D5\x30B3\x30A8\x30C6\x0020\x30A2\x30B5\x30AD\x30E6\x30E1\x30DF\x30B7\x0020\x30F1\x30D2\x30E2\x30BB\x30B9\x30F3";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Hebrew
		static const std::string str = "\xD7\x93\xD7\x92\x20\xD7\xA1\xD7\xA7\xD7\xA8\xD7\x9F\x20\xD7\xA9\xD7\x98\x20\xD7\x91\xD7\x99\xD7\x9D\x20\xD7\x9E\xD7\x90\xD7\x95\xD7\x9B\xD7\x96\xD7\x91\x20\xD7\x95\xD7\x9C\xD7\xA4\xD7\xAA\xD7\xA2\x20\xD7\x9E\xD7\xA6\xD7\x90\x20\xD7\x9C\xD7\x95\x20\xD7\x97\xD7\x91\xD7\xA8\xD7\x94\x20\xD7\x90\xD7\x99\xD7\x9A\x20\xD7\x94\xD7\xA7\xD7\x9C\xD7\x99\xD7\x98\xD7\x94";
		static const std::wstring wstr = L"\x05D3\x05D2\x0020\x05E1\x05E7\x05E8\x05DF\x0020\x05E9\x05D8\x0020\x05D1\x05D9\x05DD\x0020\x05DE\x05D0\x05D5\x05DB\x05D6\x05D1\x0020\x05D5\x05DC\x05E4\x05EA\x05E2\x0020\x05DE\x05E6\x05D0\x0020\x05DC\x05D5\x0020\x05D7\x05D1\x05E8\x05D4\x0020\x05D0\x05D9\x05DA\x0020\x05D4\x05E7\x05DC\x05D9\x05D8\x05D4";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Polish
		static const std::string str = "\x50\x63\x68\x6E\xC4\x85\xC4\x87\x20\x77\x20\x74\xC4\x99\x20\xC5\x82\xC3\xB3\x64\xC5\xBA\x20\x6A\x65\xC5\xBC\x61\x20\x6C\x75\x62\x20\x6F\xC5\x9B\x6D\x20\x73\x6B\x72\x7A\x79\xC5\x84\x20\x66\x69\x67";
		static const std::wstring wstr = L"\x0050\x0063\x0068\x006E\x0105\x0107\x0020\x0077\x0020\x0074\x0119\x0020\x0142\x00F3\x0064\x017A\x0020\x006A\x0065\x017C\x0061\x0020\x006C\x0075\x0062\x0020\x006F\x015B\x006D\x0020\x0073\x006B\x0072\x007A\x0079\x0144\x0020\x0066\x0069\x0067";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Russian
		static const std::string str = "\xD0\x92\x20\xD1\x87\xD0\xB0\xD1\x89\xD0\xB0\xD1\x85\x20\xD1\x8E\xD0\xB3\xD0\xB0\x20\xD0\xB6\xD0\xB8\xD0\xBB\x20\xD0\xB1\xD1\x8B\x20\xD1\x86\xD0\xB8\xD1\x82\xD1\x80\xD1\x83\xD1\x81\x3F\x20\xD0\x94\xD0\xB0\x2C\x20\xD0\xBD\xD0\xBE\x20\xD1\x84\xD0\xB0\xD0\xBB\xD1\x8C\xD1\x88\xD0\xB8\xD0\xB2\xD1\x8B\xD0\xB9\x20\xD1\x8D\xD0\xBA\xD0\xB7\xD0\xB5\xD0\xBC\xD0\xBF\xD0\xBB\xD1\x8F\xD1\x80\x21\x20\xD0\xA1\xD1\x8A\xD0\xB5\xD1\x88\xD1\x8C\x20\xD0\xB6\xD0\xB5\x20\xD0\xB5\xD1\x89\xD1\x91\x20\xD1\x8D\xD1\x82\xD0\xB8\xD1\x85\x20\xD0\xBC\xD1\x8F\xD0\xB3\xD0\xBA\xD0\xB8\xD1\x85\x20\xD1\x84\xD1\x80\xD0\xB0\xD0\xBD\xD1\x86\xD1\x83\xD0\xB7\xD1\x81\xD0\xBA\xD0\xB8\xD1\x85\x20\xD0\xB1\xD1\x83\xD0\xBB\xD0\xBE\xD0\xBA\x20\xD0\xB4\xD0\xB0\x20\xD0\xB2\xD1\x8B\xD0\xBF\xD0\xB5\xD0\xB9\x20\xD1\x87\xD0\xB0\xD1\x8E";
		static const std::wstring wstr = L"\x0412\x0020\x0447\x0430\x0449\x0430\x0445\x0020\x044E\x0433\x0430\x0020\x0436\x0438\x043B\x0020\x0431\x044B\x0020\x0446\x0438\x0442\x0440\x0443\x0441\x003F\x0020\x0414\x0430\x002C\x0020\x043D\x043E\x0020\x0444\x0430\x043B\x044C\x0448\x0438\x0432\x044B\x0439\x0020\x044D\x043A\x0437\x0435\x043C\x043F\x043B\x044F\x0440\x0021\x0020\x0421\x044A\x0435\x0448\x044C\x0020\x0436\x0435\x0020\x0435\x0449\x0451\x0020\x044D\x0442\x0438\x0445\x0020\x043C\x044F\x0433\x043A\x0438\x0445\x0020\x0444\x0440\x0430\x043D\x0446\x0443\x0437\x0441\x043A\x0438\x0445\x0020\x0431\x0443\x043B\x043E\x043A\x0020\x0434\x0430\x0020\x0432\x044B\x043F\x0435\x0439\x0020\x0447\x0430\x044E";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}

	{
		// Turkish
		static const std::string str = "\x50\x69\x6A\x61\x6D\x61\x6C\xC4\xB1\x20\x68\x61\x73\x74\x61\x2C\x20\x79\x61\xC4\x9F\xC4\xB1\x7A\x20\xC5\x9F\x6F\x66\xC3\xB6\x72\x65\x20\xC3\xA7\x61\x62\x75\x63\x61\x6B\x20\x67\xC3\xBC\x76\x65\x6E\x64\x69\x2E";
		static const std::wstring wstr = L"\x0050\x0069\x006A\x0061\x006D\x0061\x006C\x0131\x0020\x0068\x0061\x0073\x0074\x0061\x002C\x0020\x0079\x0061\x011F\x0131\x007A\x0020\x015F\x006F\x0066\x00F6\x0072\x0065\x0020\x00E7\x0061\x0062\x0075\x0063\x0061\x006B\x0020\x0067\x00FC\x0076\x0065\x006E\x0064\x0069\x002E";

		REQUIRE(ffw::utf8ToWstr(str) == wstr);
		REQUIRE(ffw::wstrToUtf8(wstr) == str);
		REQUIRE(ffw::wstrToUtf8(ffw::utf8ToWstr(str)) == str);
	}
}
