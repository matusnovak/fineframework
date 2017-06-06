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

size_t delay(size_t ms) {
	// Do something for a small period of time

	// This should be Sleep or any kind of sleep function,
	// but for the purpose of the test we can use this dummy for loop.
	for (volatile size_t i = 0; i < 100000 * ms; i++) {}
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

void testMutex(ffw::Mutex* mut) {
	std::cout << "waiting for lock..." << std::endl;

	mut->lock();

	std::cout << "have lock!" << std::endl;

	// Do some work
	for (volatile size_t i = 0; i < 1000; i++) {}

	mut->unlock();

	std::cout << "unlocked!" << std::endl;
}

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
	REQUIRE(thread.run(&::delay, 1000));
	REQUIRE(thread.isRunning() == true);
	std::cout << "waiting for thread to finish..." << std::endl;
	thread.join();
	std::cout << "thread done" << std::endl;
	REQUIRE(thread.getResult() == 1000);
	REQUIRE(thread.isRunning() == false);
}

TEST_CASE("Run thread with mutex", "[Thread]") {
	ffw::Thread<void(ffw::Mutex*)> thread;
	ffw::Mutex mut;

	// Lock on this thread
	REQUIRE(mut.tryLock());

	// Run new thread which will wait for its own lock
	std::cout << "running thread..." << std::endl;
	thread.run(&testMutex, &mut);

	// Some small delay
	delay(1);

	// Thread must be still running! Still waiting for its lock
	REQUIRE(thread.isRunning());

	std::cout << "locking on main thread..." << std::endl;

	// Unlock on this thread
	mut.unlock();

	// Some small delay
	delay(100);

	// Thread must have acquired its lock by this point
	REQUIRE(thread.isRunning() == false);
	thread.join();

	// Lock on this thread, must work since the thread is dead by now
	REQUIRE(mut.tryLock());

	mut.unlock();
}