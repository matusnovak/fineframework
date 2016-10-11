#include <ffw/math.h>
#include <chrono>
#include <string.h>

#ifndef FFW_TESTS
#define FFW_TESTS

namespace ffw {
	class tests {
	public:

	    class TestException : public std::exception {
        public:
          TestException(std::string const &message) : msg_(message) { }
          virtual char const *what() const noexcept { return msg_.c_str(); }

        private:
          std::string msg_;
        };

		class instance;

		static void add(instance* Test);

		class instance {
		public:
			instance(const char* CaseName, const char* TestName):caseName(CaseName),testName(TestName){
				ffw::tests::add(this);
			}

			const char* getCaseName(){ return caseName; }
			const char* getTestName(){ return testName; }

			virtual void run() = 0;

		private:
			const char* caseName;
			const char* testName;
		};

		static int run();

		template<class A, class B,
		typename std::enable_if<std::is_integral<B>::value,bool>::type>
		static void TestEqual(A a, B b, const char* file, int line, const char* astr, const char* bstr){
			if(a != b){
				/*std::string msg = "            Test Error at line: " + ffw::ValToString(line) + "\n";
				msg += "            TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "            Expected: " + ffw::ValToString(a) + " Got: " + ffw::ValToString(b);*/
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "   Expected: " + ffw::ValToString(a) + "\n";
				msg += "        Got: " + ffw::ValToString(b);
				throw TestException(msg);
			}
		}

		static void TestEqual(float a, float b, const char* file, int line, const char* astr, const char* bstr){
			if(std::abs(a - b) > 0.001){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "   Expected: " + ffw::ValToString(a) + "\n";
				msg += "        Got: " + ffw::ValToString(b);
				throw TestException(msg);
			}
		}

		static void TestEqual(std::string a, std::string b, const char* file, int line, const char* astr, const char* bstr){
			if(a != b){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "   Expected: \"" + std::string(a) + "\"\n";
				msg += "        Got: \"" + std::string(b) + "\"";
				throw TestException(msg);
			}
		}

		template<class T>
		static void TestEqual(ffw::Vec2<T> a, ffw::Vec2<T> b, const char* file, int line, const char* astr, const char* bstr){
			if(a != b){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "   Expected: \"" + ffw::ValToString(a.x, 2) + ", " + ffw::ValToString(a.y, 2) + "\"\n";
				msg += "        Got: \"" + ffw::ValToString(b.x, 2) + ", " + ffw::ValToString(b.y, 2) + "\"";
				throw TestException(msg);
			}
		}

		template<class T>
		static void TestEqual(ffw::Vec3<T> a, ffw::Vec3<T> b, const char* file, int line, const char* astr, const char* bstr){
			if(a != b){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "   Expected: \"" + ffw::ValToString(a.x, 2) + ", " + ffw::ValToString(a.y, 2) + ", " + ffw::ValToString(a.z, 2) + "\"\n";
				msg += "        Got: \"" + ffw::ValToString(b.x, 2) + ", " + ffw::ValToString(b.y, 2) + ", " + ffw::ValToString(b.z, 2) + "\"";
				throw TestException(msg);
			}
		}

		template<class T>
		static void TestEqual(ffw::Vec4<T> a, ffw::Vec4<T> b, const char* file, int line, const char* astr, const char* bstr){
			if(a != b){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_EQUAL(" + std::string(astr) + ", " + std::string(bstr) + ")\n";
				msg += "   Expected: \"" + ffw::ValToString(a.x, 2) + ", " + ffw::ValToString(a.y, 2) + ", " + ffw::ValToString(a.z, 2) + ", " + ffw::ValToString(a.w, 2) + "\"\n";
				msg += "        Got: \"" + ffw::ValToString(b.x, 2) + ", " + ffw::ValToString(b.y, 2) + ", " + ffw::ValToString(b.z, 2) + ", " + ffw::ValToString(b.w, 2) + "\"";
				throw TestException(msg);
			}
		}

		static void TestTrue(bool a, const char* file, int line, const char* astr){
			if(!a){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_TRUE(" + std::string(astr) + ")\n";
				msg += "   Expected: True\n";
				msg += "        Got: False";
				throw TestException(msg);
			}
		}

		static void TestFalse(bool a, const char* file, int line, const char* astr){
			if(a){
				std::string msg = "";
				msg += "      Where: " + std::string(file) + ":" + ffw::ValToString(line) + "\n";
				msg += "       What: TEST_FALSE(" + std::string(astr) + ")\n";
				msg += "   Expected: False\n";
				msg += "        Got: True";
				throw TestException(msg);
			}
		}
	};
}

#define STRINGIFY(x) #x

#define TEST_EQUAL(A, B)\
	ffw::tests::TestEqual(A, B, __FILE__, __LINE__, STRINGIFY(A), STRINGIFY(B));

#define TEST_TRUE(A)\
	ffw::tests::TestTrue(A, __FILE__, __LINE__, STRINGIFY(A));

#define TEST_FALSE(A)\
	ffw::tests::TestFalse(A, __FILE__, __LINE__, STRINGIFY(A));

#define RUN_ALL_TESTS\
	ffw::tests::run

#define TEST_GET_CLASS_NAME(case_name, test_name)\
	case_name##_##test_name##_test

#define CONCAT_IMPL( x, y ) x##y
#define MACRO_CONCAT( x, y ) CONCAT_IMPL( x, y )

#define TEST(case_name, test_name)\
	class TEST_GET_CLASS_NAME(case_name, test_name): public ffw::tests::instance {\
		public:\
		TEST_GET_CLASS_NAME(case_name, test_name)():ffw::tests::instance(#case_name, #test_name){\
		}\
		void run() override;\
	};\
	static ffw::tests::instance* MACRO_CONCAT(test_, __COUNTER__) = new TEST_GET_CLASS_NAME(case_name, test_name)();\
	void TEST_GET_CLASS_NAME(case_name, test_name)::run()

static size_t instancesSize = 0;
static ffw::tests::instance** instances = NULL;

void ffw::tests::add(instance* Test){
	if(Test == NULL)return;

	if(instancesSize == 0){
		instancesSize = 1;
		instances = new ffw::tests::instance*[instancesSize];
		instances[0] = Test;

	} else {
		ffw::tests::instance** temp = new ffw::tests::instance*[instancesSize+1];
		memcpy(temp, instances, instancesSize * sizeof(void*));
		temp[instancesSize] = Test;
		delete[] instances;
		instances = temp;
		instancesSize++;
	}
}

int ffw::tests::run(){
	//std::cout << "total: " << instancesSize << " tests!" << std::endl;
	int total = 0;

	for(size_t i = 0; i < instancesSize; i++){
		auto t1 = std::chrono::steady_clock::now();
		ffw::tests::instance* test = instances[i];

		std::cout << "[ RUNNING ] " << test->getCaseName() << " / " << test->getTestName() << std::endl;
		bool done = false;
		try {
			//std::cout << "Running: " << test->getCaseName() << " / " << test->getTestName() << std::endl;
			test->run();
			done = true;
			auto t2 = std::chrono::steady_clock::now();
			auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
			static std::string suffixes [] = {"us", "ms", "s", "min", "h"};
			int suffix = 0;
			while(time_span > 1000 && suffix < 4){
				time_span /= 1000;
				suffix++;
			}

			std::cout << "[ SUCCESS ] " << test->getCaseName() << " / " << test->getTestName() << " ( " << ffw::ValToString(time_span) << suffixes[suffix] << " )" << std::endl;
		} catch (const std::exception& e){
            total++;
			std::cerr << "[ FAILED  ] " << test->getCaseName() << " / " << test->getTestName() << std::endl;
			std::cerr << e.what() << std::endl;
        }
		//auto t2 = std::chrono::steady_clock::now();
	}

	std::cout << "[ RESULT  ] Success: " << ffw::ValToString(instancesSize - total) << " Failed: " << ffw::ValToString(total) << std::endl;

	for(size_t i = 0; i < instancesSize; i++){
		ffw::tests::instance* test = instances[i];
		delete test;
	}

	delete instances;
	instancesSize = 0;
	instances = NULL;
	return 0;
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
	int total = RUN_ALL_TESTS();
	system("pause");
	return total;
}

#endif
