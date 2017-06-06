#include <ffw/math.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

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