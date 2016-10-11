#include "../units.h"

TEST(Math, Vec2){
	ffw::Vec2f v;

	TEST_EQUAL(0.0f, v.x);
	TEST_EQUAL(0.0f, v.y);

	v.Set(10.0f, 20.0f);

	TEST_EQUAL(10.0f, v.x);
	TEST_EQUAL(20.0f, v.y);

	v.Set(15.0f);

	TEST_EQUAL(15.0f, v.x);
	TEST_EQUAL(15.0f, v.y);

	v.Set({5.0f, 10.0f, 20.0f});

	TEST_EQUAL(15.0f, v.x);
	TEST_EQUAL(15.0f, v.y);

	v.Set({11.0f, 22.0f});

	TEST_EQUAL(11.0f, v.x);
	TEST_EQUAL(22.0f, v.y);

	TEST_TRUE(v == ffw::Vec2f(11.0f, 22.0f));
	TEST_FALSE(v == ffw::Vec2f(11.1f, 22.0f));

	TEST_EQUAL(24.5967477525f, v.Length());
	TEST_EQUAL(605, v.LengthSqrd());

	v.Rotate(45.0f);

	TEST_EQUAL(-7.77817459f, v.x);
	TEST_EQUAL(23.33452378f, v.y);

	v.Rotate(-45.0f);

	TEST_EQUAL(11.0f, v.x);
	TEST_EQUAL(22.0f, v.y);

	TEST_EQUAL(v, ffw::Vec2f(v));
}

TEST(Math, Vec3){
	ffw::Vec3f v;

	TEST_EQUAL(0.0f, v.x);
	TEST_EQUAL(0.0f, v.y);
	TEST_EQUAL(0.0f, v.z);

	v.Set(10.0f, 20.0f, 30.0f);

	TEST_EQUAL(10.0f, v.x);
	TEST_EQUAL(20.0f, v.y);
	TEST_EQUAL(30.0f, v.z);

	v.Set(15.0f);

	TEST_EQUAL(15.0f, v.x);
	TEST_EQUAL(15.0f, v.y);
	TEST_EQUAL(15.0f, v.z);

	v.Set({5.0f, 10.0f, 20.0f, 30.0f});

	TEST_EQUAL(15.0f, v.x);
	TEST_EQUAL(15.0f, v.y);
	TEST_EQUAL(15.0f, v.z);

	v.Set({11.0f, 22.0f, 33.0f});

	TEST_EQUAL(11.0f, v.x);
	TEST_EQUAL(22.0f, v.y);
	TEST_EQUAL(33.0f, v.z);

	TEST_TRUE(v == ffw::Vec3f(11.0f, 22.0f, 33.0f));
	TEST_FALSE(v == ffw::Vec3f(11.1f, 22.0f, 33.0f));

	TEST_EQUAL(41.1582312545f, v.Length());
	TEST_EQUAL(1694, v.LengthSqrd());

	v.Set(1.0f, 0.f, 0.0f);
	v.RotateZ(90);

	TEST_EQUAL(0.0f, v.x);
	TEST_EQUAL(1.0f, v.y);
	TEST_EQUAL(0.0f, v.z);

	v.RotateX(90);

	TEST_EQUAL(0.0f, v.x);
	TEST_EQUAL(0.0f, v.y);
	TEST_EQUAL(1.0f, v.z);

	v.RotateY(90);

	TEST_EQUAL(1.0f, v.x);
	TEST_EQUAL(0.0f, v.y);
	TEST_EQUAL(0.0f, v.z);
}

TEST(Math, Vec4){
	ffw::Vec4f v;

	TEST_EQUAL(0.0f, v.x);
	TEST_EQUAL(0.0f, v.y);
	TEST_EQUAL(0.0f, v.z);
	TEST_EQUAL(0.0f, v.w);

	v.Set(10.0f, 20.0f, 30.0f, 40.0f);

	TEST_EQUAL(10.0f, v.x);
	TEST_EQUAL(20.0f, v.y);
	TEST_EQUAL(30.0f, v.z);
	TEST_EQUAL(40.0f, v.w);

	v.Set(15.0f);

	TEST_EQUAL(15.0f, v.x);
	TEST_EQUAL(15.0f, v.y);
	TEST_EQUAL(15.0f, v.z);
	TEST_EQUAL(15.0f, v.w);

	v.Set({5.0f, 10.0f, 20.0f, 30.0f, 42.0f});

	TEST_EQUAL(15.0f, v.x);
	TEST_EQUAL(15.0f, v.y);
	TEST_EQUAL(15.0f, v.z);
	TEST_EQUAL(15.0f, v.w);

	v.Set({11.0f, 22.0f, 33.0f, 44.0f});

	TEST_EQUAL(11.0f, v.x);
	TEST_EQUAL(22.0f, v.y);
	TEST_EQUAL(33.0f, v.z);
	TEST_EQUAL(44.0f, v.w);

	TEST_TRUE(v == ffw::Vec4f(11.0f, 22.0f, 33.0f, 44.0f));
	TEST_FALSE(v == ffw::Vec4f(11.1f, 22.0f, 33.0f, 44.0f));

	TEST_EQUAL(60.2494813256f, v.Length());
	TEST_EQUAL(3630, v.LengthSqrd());

	TEST_EQUAL(v, ffw::Vec4f(11.0f, 22.0f, 33.0f, 44.0f));
}

