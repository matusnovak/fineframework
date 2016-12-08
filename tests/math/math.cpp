#include "../units.h"

TEST(Math, FileInfo){
	{
		ffw::FileInfo info = ffw::GetFileInfo("C:/Hello/World.txt");
		TEST_EQUAL("C:/Hello/", info.dirname);
		TEST_EQUAL("World", info.basename);
		TEST_EQUAL("txt", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("C:/Hello/World");
		TEST_EQUAL("C:/Hello/", info.dirname);
		TEST_EQUAL("World", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("C:/Hello/");
		TEST_EQUAL("C:/Hello/", info.dirname);
		TEST_EQUAL("", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("C:/Hello/.txt");
		TEST_EQUAL("C:/Hello/", info.dirname);
		TEST_EQUAL(".txt", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("C:");
		TEST_EQUAL("C:", info.dirname);
		TEST_EQUAL("", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("/Hello/");
		TEST_EQUAL("/Hello/", info.dirname);
		TEST_EQUAL("", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("./Hello");
		TEST_EQUAL("./", info.dirname);
		TEST_EQUAL("Hello", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("../../Hello/");
		TEST_EQUAL("../../Hello/", info.dirname);
		TEST_EQUAL("", info.basename);
		TEST_EQUAL("", info.extension);
	}

	{
		ffw::FileInfo info = ffw::GetFileInfo("image.png");
		TEST_EQUAL("", info.dirname);
		TEST_EQUAL("image", info.basename);
		TEST_EQUAL("png", info.extension);
	}
}

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

TEST(Math, Var){

	ffw::Var v;
	TEST_TRUE(v.Typeid() == typeid(std::nullptr_t));
	TEST_FALSE(v.Typeid() == typeid(int));
	TEST_TRUE(v.Empty());
	TEST_TRUE(v.Contains<std::nullptr_t>());

	ffw::Var a(123);
	TEST_TRUE(a.Typeid() == typeid(int));
	TEST_FALSE(a.Typeid() == typeid(float));
	TEST_FALSE(a.Empty());
	TEST_TRUE(a.Contains<int>());

	try {
		// Can't get float from Var initialised as int
		float test = static_cast<float>(a);

		// Must not execute!
		TEST_FAIL;
	} catch (ffw::Var::InvalidCast& e){
		(void)e;
		//std::cout << e.what() << std::endl;
		// Do nothing
	}

	try {
		int test = static_cast<int>(a);
		TEST_EQUAL(test, 123);

	} catch (ffw::Var::InvalidCast& e){
		(void)e;
		// Must not execute!
		TEST_FAIL;
	}

	ffw::Var b = 42;
	TEST_EQUAL(42, (int)b);
	TEST_FALSE(43 == (int)b);

	b = 11.22f;
	TEST_TRUE(b.Typeid() == typeid(float));
	TEST_EQUAL(11.22f, (float)b);

	b = "hello";
	TEST_TRUE(b.Typeid() == typeid(const char*));
	TEST_TRUE(strcmp("hello", (const char*)b) == 0);
	TEST_TRUE(b == "hello");
	TEST_TRUE(b == std::string("hello"));

	b = std::string("hello");
	TEST_TRUE(b.Typeid() == typeid(std::string));
	TEST_TRUE(b == "hello");
	TEST_TRUE(b == std::string("hello"));

	ffw::Var c = b;
	TEST_TRUE(c.Typeid() == typeid(std::string));
	TEST_TRUE(std::string("hello") == (std::string)c);

	TEST_TRUE(c == "hello");
	TEST_TRUE(c == (std::string)b);
	TEST_FALSE(c == 42);

	// Reference
	ffw::Var i = 99;
	int& ref = (int&)i;

	TEST_EQUAL(99, ref);

	ref = 98;

	TEST_TRUE(i == 98);

	// Simply copy
	int copy = (int)i;

	TEST_EQUAL(98, copy);

	copy = 97;

	TEST_TRUE(i == 98);

	// Reference with get as
	int& ref2 = i.GetAs<int>();

	ref2 = 42;

	TEST_TRUE(i == 42);

	//TEST_TRUE(ffw::Var(false) == false);

	ffw::Var t = false;
	TEST_TRUE(t.Typeid() == typeid(bool));

	TEST_EQUAL(false, t.Bool());

	t = true;

	TEST_EQUAL(true, t.Bool());

	t = 42;

	TEST_EQUAL(true, t.Bool());

	t = 0;

	TEST_EQUAL(false, t.Bool());
}

TEST(Math, VarObject){
	ffw::Object o;
	TEST_TRUE(o.size() == 0);

	o = {"hello", 123};
	TEST_TRUE(o.size() == 1);

	try {
		const ffw::Var& v = o["hello"];
		// Must pass without exception!

		TEST_EQUAL(123, (int)v);

	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		TEST_FAIL;
	}

	o.insert({"world", 42.0f});
	TEST_TRUE(o.size() == 2);

	try {
		const ffw::Var& v = o["world"];
		// Must pass without exception!

		TEST_EQUAL(42.0f, (float)v);

	} catch (std::exception& e){
		std::cerr << e.what() << std::endl;
		TEST_FAIL;
	}

	try {
		const ffw::Var& v = o["error"];
		// Must throw exception!

		TEST_FAIL;

	} catch (std::exception& e){
		(void)e;
	}

	ffw::Object obj = {
		{"first", 10},
		{"second", 42.1f},
		{"third", "Hello World!"},
		{"fouth", nullptr},
		{"fifth", true},
		{"sixth", 88.99}
	};

	TEST_TRUE(obj.size() == 6);

	try {
		const auto& first = obj["first"];
		const auto& second = obj["second"];
		const auto& third = obj["third"];
		const auto& fourth = obj["fourth"];
		const auto& fifth = obj["fifth"];
		const auto& sixth = obj["sixth"];

		TEST_TRUE(first.Typeid() == typeid(int));
		TEST_TRUE(second.Typeid() == typeid(float));
		TEST_TRUE(third.Typeid() == typeid(const char*));
		TEST_TRUE(fourth.Typeid() == typeid(nullptr));
		TEST_TRUE(fifth.Typeid() == typeid(bool));
		TEST_TRUE(sixth.Typeid() == typeid(double));

	} catch (std::exception& e){
		(void)e;
		std::cout << e.what() << std::endl;
		TEST_FAIL;
	}

	obj["first"].GetAs<int>() = 42;

	TEST_TRUE((int)obj["first"] == 42);
	TEST_TRUE(obj["first"] == 42);
	TEST_FALSE(obj["first"] == 42.0f);

	obj["first"] = 55;

	TEST_TRUE(obj["first"] == 55);

	ffw::Object big = {
		{"first", ffw::Object{{"hello", 42},{"world", true}}
		},
		{"second", ffw::Object{{"who", "doctor"},{"world", false}}
		},
	};

	try {

		const auto& hello = big["first"]["hello"];
		TEST_TRUE(hello.Typeid() == typeid(int));
		TEST_EQUAL(42, (int)hello);

		const auto& who = big["second"]["who"];
		TEST_TRUE(who.Typeid() == typeid(const char*));

		std::string test = (const char*)who;

		TEST_TRUE(big["second"]["who"] == "doctor");
		TEST_TRUE(who == "doctor");

	} catch (std::exception& e){
		(void)e;
		std::cout << e.what() << std::endl;
		TEST_FAIL;
	}
}

TEST(Math, VarArray){
	ffw::Array a;
	TEST_TRUE(a.size() == 0);

	a = {"hello", 123, 42.0f, true};

	TEST_TRUE(a.size() == 4);

	TEST_TRUE(a[0].Typeid() == typeid(const char*));
	TEST_TRUE(a[1].Typeid() == typeid(int));
	TEST_TRUE(a[2].Typeid() == typeid(float));
	TEST_TRUE(a[3].Typeid() == typeid(bool));

	TEST_TRUE((bool)a[3] == true);

	a[3] = false;

	TEST_TRUE(a[3].Typeid() == typeid(bool));

	TEST_TRUE((bool)a[3] == false);
}
