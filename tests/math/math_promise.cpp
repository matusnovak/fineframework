#include <ffw/math/promise.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <thread>

TEST_CASE("Resolve promise and get status") {
    ffw::Promise<int> p;

    REQUIRE(p.isFinished() == false);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == false);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::WAITING);

    p.resolve(123);

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == true);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::RESOLVED);
    REQUIRE(p.getResult() == 123);

    p.resolve(456);

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == true);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::RESOLVED);
    REQUIRE(p.getResult() == 456);
}

TEST_CASE("Reject promise and get status") {
    ffw::Promise<int> p;

    REQUIRE(p.isFinished() == false);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == false);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::WAITING);

    try {
        throw std::runtime_error("Something went wrong runtime error!");
    } catch(...) {
        p.reject(std::current_exception());
    }

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == true);
    REQUIRE(p.isResolved() == false);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::REJECTED);
    
    REQUIRE_THROWS_AS(p.getResult(), std::runtime_error);

    try {
        throw std::invalid_argument("Something went wrong invalid argument!");
    } catch(...) {
        p.reject(std::current_exception());
    }

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == true);
    REQUIRE(p.isResolved() == false);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::REJECTED);
    
    REQUIRE_THROWS_AS(p.getResult(), std::invalid_argument);
}

TEST_CASE("Resolve promise and call child") {
    static bool called = false;
    static int calledResult = 0;
    ffw::Promise<int> p;

    p.thenOrFail([&](int i) -> int {
        called = true;
        calledResult = i;
        return 42; /////
    }, [&](const std::exception_ptr& e){
        
    });

    REQUIRE(called == false);

    p.resolve(123);

    REQUIRE(called == true);
    REQUIRE(calledResult == 123);

    p.resolve(456);

    REQUIRE(called == true);
    REQUIRE(calledResult == 456);
}

TEST_CASE("Reject promise and call child") {
    static bool called = false;
    static bool exception = false;
    static std::string exceptionMsg;

    ffw::Promise<int> p;

    p.then([&](int i) -> int {
        called = true;
        return 42; /////
    });

    p.fail([&](const std::exception_ptr& eptr){
        try {
            std::rethrow_exception(eptr);
        } catch (std::exception& e) {
            exception = true;
            exceptionMsg = e.what();
        }
    });

    REQUIRE(called == false);

    try {
        throw std::invalid_argument("Something went wrong!");
    } catch (...) {
        p.reject(std::current_exception());
    }

    REQUIRE(called == false);
    REQUIRE(exception == true);
    REQUIRE(exceptionMsg == "Something went wrong!");

    try {
        throw std::invalid_argument("Hello World!");
    } catch (...) {
        p.reject(std::current_exception());
    }

    REQUIRE(called == false);
    REQUIRE(exception == true);
    REQUIRE(exceptionMsg == "Hello World!");
}

TEST_CASE("Resolve promise within its body") {
    ffw::Promise<int> p([&](ffw::Promise<int>& promise){
        promise.resolve(42);
    });

    REQUIRE(p.isFinished() == false);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == false);

    p.call();

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == true);
    REQUIRE(p.getResult() == 42);
}

TEST_CASE("Reject promise within its body by throw") {
    ffw::Promise<int> p([&](ffw::Promise<int>& promise){
        throw std::invalid_argument("Hello World!");
    });

    REQUIRE(p.isFinished() == false);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == false);

    p.call();

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == true);
    REQUIRE(p.isResolved() == false);
    REQUIRE_THROWS_AS(p.getResult(), std::invalid_argument);
}

TEST_CASE("Reject promise within its body") {
    ffw::Promise<int> p([&](ffw::Promise<int>& promise){
        try {
            throw std::invalid_argument("Hello World!");
        } catch (...) {
            promise.reject(std::current_exception());
        }
    });

    REQUIRE(p.isFinished() == false);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == false);

    p.call();

    REQUIRE(p.isFinished() == true);
    REQUIRE(p.isRejected() == true);
    REQUIRE(p.isResolved() == false);
    REQUIRE_THROWS_AS(p.getResult(), std::invalid_argument);
}

TEST_CASE("Resolve chaining") {
    static std::shared_ptr<int> somePtr(new int[10], std::default_delete<int[]>());
    static float resolvedFloat = 0;
    static bool resolvedBool = false;
    static std::string resolvedString;
    static int* resolvedPtr;
    
    ffw::Promise<float> p0;
    
    ffw::Promise<bool>& p1 = p0.then([&](float v) -> bool {
        resolvedFloat = v;
        return true;
    });

    ffw::Promise<std::string>& p2 = p1.then([&](bool v) -> std::string {
        resolvedBool = v;
        return std::string("Hello");
    });

    ffw::Promise<int*>& p3 = p2.then([&](std::string v) -> int* {
        resolvedString = v;
        return somePtr.get();
    });

    ffw::Promise<std::shared_ptr<int>>& p4 = p3.then([&](int* v) -> std::shared_ptr<int> {
        resolvedPtr = v;
        return somePtr;
    });

    REQUIRE(p0.isFinished() == false);
    REQUIRE(p1.isFinished() == false);
    REQUIRE(p2.isFinished() == false);
    REQUIRE(p3.isFinished() == false);
    REQUIRE(p4.isFinished() == false);

    p0.resolve(42.42f);

    REQUIRE(p0.isFinished() == true);
    REQUIRE(p1.isFinished() == true);
    REQUIRE(p2.isFinished() == true);
    REQUIRE(p3.isFinished() == true);
    REQUIRE(p4.isFinished() == true);

    REQUIRE(resolvedFloat == Approx(42.42f));
    REQUIRE(resolvedBool == true);
    REQUIRE(resolvedString == "Hello");
    REQUIRE(resolvedPtr == somePtr.get());
    REQUIRE(static_cast<std::shared_ptr<int>>(p4.getResult()) == somePtr);
}

TEST_CASE("Resolve chaining with middle fail") {
    ffw::Promise<int> p0;

    ffw::Promise<int>& p1 = p0.then([&](int v) -> int {
        return v + 1;
    });

    ffw::Promise<int>& p2 = p1.then([&](int v) -> int {
        throw std::invalid_argument("Hello World!");
    });

    ffw::Promise<int>& p3 = p2.then([&](int v) -> int {
        return v + 1;
    });

    REQUIRE(p0.isFinished() == false);
    REQUIRE(p1.isFinished() == false);
    REQUIRE(p2.isFinished() == false);
    REQUIRE(p3.isFinished() == false);

    p0.resolve(10);

    REQUIRE(p0.isFinished() == true);
    REQUIRE(p1.isFinished() == true);
    REQUIRE(p2.isFinished() == true);
    REQUIRE(p3.isFinished() == true);

    REQUIRE(p0.isResolved() == true);
    REQUIRE(p1.isResolved() == true);
    REQUIRE(p2.isResolved() == false);
    REQUIRE(p3.isResolved() == false);

    REQUIRE(p0.isRejected() == false);
    REQUIRE(p1.isRejected() == false);
    REQUIRE(p2.isRejected() == true);
    REQUIRE(p3.isRejected() == true);

    REQUIRE(p0.getResult() == 10);
    REQUIRE(p1.getResult() == 11);
    REQUIRE_THROWS_AS(p2.getResult(), std::invalid_argument);
    REQUIRE_THROWS_AS(p3.getResult(), std::invalid_argument);
}

TEST_CASE("Resolve chaining with middle fail and catch at the end") {
    static bool exception = false;
    static std::string exceptionMessage;

    ffw::Promise<int> p0;

    ffw::Promise<int>& p1 = p0.then([&](int v) -> int {
        return v + 1;
    });

    ffw::Promise<int>& p2 = p1.then([&](int v) -> int {
        throw std::invalid_argument("Hello World!");
    });

    ffw::Promise<int>& p3 = p2.then([&](int v) -> int {
        return v + 1;
    });


    ffw::Promise<int> f4 = p2.fail([&](const std::exception_ptr& eptr) -> void {
        try {
            std::rethrow_exception(eptr);
        } catch (std::invalid_argument& e) {
            exceptionMessage = e.what();
            exception = true;
        } catch (std::exception& e) {
            (void)e;
            exception = false;
        }
    });

    p0.resolve(10);

    REQUIRE(p0.isFinished() == true);
    REQUIRE(p1.isFinished() == true);
    REQUIRE(p2.isFinished() == true);
    REQUIRE(p3.isFinished() == true);
    REQUIRE(f4.isFinished() == true);

    REQUIRE(p0.isResolved() == true);
    REQUIRE(p1.isResolved() == true);
    REQUIRE(p2.isResolved() == false);
    REQUIRE(p3.isResolved() == false);
    REQUIRE(f4.isResolved() == false);

    REQUIRE(p0.isRejected() == false);
    REQUIRE(p1.isRejected() == false);
    REQUIRE(p2.isRejected() == true);
    REQUIRE(p3.isRejected() == true);
    REQUIRE(f4.isRejected() == true);

    REQUIRE(p0.getResult() == 10);
    REQUIRE(p1.getResult() == 11);
    REQUIRE_THROWS_AS(p2.getResult(), std::invalid_argument);
    REQUIRE_THROWS_AS(p3.getResult(), std::invalid_argument);

    REQUIRE(exception == true);
    REQUIRE(exceptionMessage == "Hello World!");
}

TEST_CASE("Fail and catch at the end") {
    static bool lastFailCalled = false;
    static bool failCalled = false;

    ffw::Promise<int> p0;

    ffw::Promise<int>& f = 
        p0.then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).fail([&](const std::exception_ptr& eptr) -> void {
        failCalled = true;
    });
    
    f.fail([&](const std::exception_ptr& eptr) -> void {
        lastFailCalled = true;
    });

    try {
        throw std::invalid_argument("What's up?");
    } catch (...) {
        p0.reject(std::current_exception());
    }

    REQUIRE(p0.isRejected() == true);
    REQUIRE(f.isFinished() == true);
    REQUIRE(f.isResolved() == false);
    REQUIRE(f.isRejected() == true);
    REQUIRE_THROWS_AS(f.getResult(), std::invalid_argument);
    REQUIRE(failCalled == true);
    REQUIRE(lastFailCalled == true);
}

TEST_CASE("Resolve before and execute all lambdas") {
    ffw::Promise<int> p0;

    p0.resolve(10);

    ffw::Promise<int>& last = p0.then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    });

    REQUIRE(last.isFinished() == true);
    REQUIRE(last.isResolved() == true);
    REQUIRE(last.getResult() == 15);
}

TEST_CASE("Resolve and rejections must be rejected") {
    static bool failCalled[4] = { false, false, false, false };

    ffw::Promise<int> p0;

    ffw::Promise<int>& p1 = p0.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& p2 = p1.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& p3 = p2.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& p4 = p3.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& f1 = p1.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[0] = true;
    });

    ffw::Promise<int>& f2 = p2.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[1] = true;
    });

    ffw::Promise<int>& f3 = p3.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[2] = true;
    });

    ffw::Promise<int>& f4 = p4.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[3] = true;
    });

    p0.resolve(10);
    REQUIRE(p4.getResult() == 14);

    REQUIRE(f1.isRejected() == false);
    REQUIRE(f2.isRejected() == false);
    REQUIRE(f3.isRejected() == false);
    REQUIRE(f4.isRejected() == false);

    REQUIRE(failCalled[0] == false);
    REQUIRE(failCalled[1] == false);
    REQUIRE(failCalled[2] == false);
    REQUIRE(failCalled[3] == false);
}

TEST_CASE("Reject and rejections must be resolved") {
    static bool failCalled[4] = { false, false, false, false };
    ffw::Promise<int> p0;

    ffw::Promise<int>& p1 = p0.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& p2 = p1.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& p3 = p2.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& p4 = p3.then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& f1 = p1.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[0] = true;
    });

    ffw::Promise<int>& f2 = p2.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[1] = true;
    });

    ffw::Promise<int>& f3 = p3.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[2] = true;
    });

    ffw::Promise<int>& f4 = p4.fail([&](const std::exception_ptr& e) -> void {
        (void)e;
        failCalled[3] = true;
    });

    p0.rejectWith<std::runtime_error>("Hello");

    REQUIRE_THROWS_AS(p4.getResult(), std::runtime_error);

    REQUIRE(f1.isResolved() == false);
    REQUIRE(f2.isResolved() == false);
    REQUIRE(f3.isResolved() == false);
    REQUIRE(f4.isResolved() == false);

    REQUIRE(failCalled[0] == true);
    REQUIRE(failCalled[1] == true);
    REQUIRE(failCalled[2] == true);
    REQUIRE(failCalled[3] == true);
}

TEST_CASE("Reject before and execute all lambdas") {
    ffw::Promise<int> p0;
    static bool failCalled = false;
    static bool f0Called = false;
    static bool f1Called = false;

    p0.rejectWith<std::invalid_argument>("Hello");

    ffw::Promise<int>& last = p0.then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    }).then([&](int i) -> int {
        return i + 1;
    });

    ffw::Promise<int>& test = last.fail([&](const std::exception_ptr& eptr){
        (void)eptr;
        failCalled = true;
    });

    ffw::Promise<int>& f0 = test.fail([&](const std::exception_ptr& eptr){
        (void)eptr;
        f0Called = true;
        throw std::range_error("New exception inside of fail lambda!");
    });

    ffw::Promise<int>& f1 = f0.fail([&](const std::exception_ptr& eptr){
        (void)eptr;
        f1Called = true;
    });

    REQUIRE(last.isFinished() == true);
    REQUIRE(last.isRejected() == true);
    REQUIRE_THROWS_AS(last.getResult(), std::invalid_argument);

    REQUIRE(test.isFinished() == true);
    REQUIRE(test.isRejected() == true);
    REQUIRE(failCalled == true);

    REQUIRE(f0.isFinished() == true);
    REQUIRE(f0.isRejected() == true);
    REQUIRE(f0Called == true);

    REQUIRE(f1.isFinished() == true);
    REQUIRE(f1.isRejected() == true);
    REQUIRE(f1Called == true);
    REQUIRE_THROWS_AS(f1.getResult(), std::range_error);
}

TEST_CASE("Cascade exception") {
    static bool fail0 = false;
    static bool fail1 = false;
    static bool fail2 = false;

    ffw::Promise<int> p0;

    p0.then([](int i) -> int {
        throw std::invalid_argument("Hello World!");
    }).fail([&](const std::exception_ptr& eptr) -> void {
        fail0 = true;
        std::rethrow_exception(eptr);
    }).fail([&](const std::exception_ptr& eptr) -> void {
        fail1 = true;
        std::rethrow_exception(eptr);
    }).fail([&](const std::exception_ptr& eptr) -> void {
        fail2 = true;
        std::rethrow_exception(eptr);
    });

    p0.resolve(42);

    REQUIRE(fail0 == true);
    REQUIRE(fail1 == true);
    REQUIRE(fail2 == true);
}

TEST_CASE("Cascade exception with explicit exception") {
    static bool fail0 = false;
    static bool fail1 = false;
    static bool fail2 = false;
    static bool fail3 = false;
    static bool then4 = false;

    ffw::Promise<int> p0;

    p0.then([](int i) -> int {
        throw std::invalid_argument("Hello World!");
    }).fail([&](std::runtime_error& e) -> void {
        (void)e;
        fail0 = true;
    }).fail([&](std::logic_error& e) -> void {
        (void)e;
        fail1 = true;
    }).fail([&](std::bad_alloc& e) -> void {
        (void)e;
        fail2 = true;
    }).fail([&](std::logic_error& e) -> void {
        (void)e;
        fail3 = true;
    }).then([&](int i) -> void {
        then4 = true;
    });

    p0.resolve(42);

    REQUIRE(fail0 == false);
    REQUIRE(fail1 == true);
    REQUIRE(fail2 == false);
    REQUIRE(fail3 == true);
    REQUIRE(then4 == false);
}

TEST_CASE("Cascade exception with explicit exception resolved") {
    static bool fail0 = false;
    static bool fail1 = false;
    static bool fail2 = false;
    static bool fail3 = false;
    static bool then4 = false;
    static int result = 0;

    ffw::Promise<int> p0;

    p0.then([](int i) -> int {
        return i*i;
    }).fail([&](std::runtime_error& e) -> void {
        (void)e;
        fail0 = true;
    }).fail([&](std::logic_error& e) -> void {
        (void)e;
        fail1 = true;
    }).fail([&](std::bad_alloc& e) -> void {
        (void)e;
        fail2 = true;
    }).fail([&](std::logic_error& e) -> void {
        (void)e;
        fail3 = true;
    }).then([&](int i) -> void {
        then4 = true;
        result = i;
    });

    p0.resolve(42);

    REQUIRE(fail0 == false);
    REQUIRE(fail1 == false);
    REQUIRE(fail2 == false);
    REQUIRE(fail3 == false);
    REQUIRE(then4 == true);
    REQUIRE(result == 42 * 42);
}

TEST_CASE("Capture any exception") {
    static bool fail0 = false;
    static bool then1 = false;

    ffw::Promise<int> p0;

    p0.then([](int i) -> int {
        throw std::invalid_argument("Hello World!");
    }).fail([&](void) -> void {
        fail0 = true;
    }).then([&](int i) -> void {
        then1 = true;
    });

    p0.resolve(42);

    REQUIRE(fail0 == true);
    REQUIRE(then1 == false);
}

TEST_CASE("Doc example") {
    static bool lastCalled = false;

    ffw::Promise<void> promise([](ffw::Promise<void>& self) -> void {
        // Do some work
        self.resolve();
    });
     
    ffw::Promise<float>& last = promise.then([]() -> std::string {
        // I am the first chain block to be executed
        // and I will produce std::string
        return std::string("Hello World!");
    }).then([](std::string str) -> size_t {
        // I am the second block
        // and I must accept std::string because the previous
        // chain link produces std::string
        // But I will produce size_t
        return str.size();
    }).then([](size_t len) -> int {
        // I am the third block
        // I must accept size_t but I will cast it to int for no reason
        return static_cast<int>(len);
    }).fail([](std::exception& e) -> void {
        // I am the fail block
        // I will be executed if any of the blocks above (or parent promise)
        // produces exception that matches my lambda argument!
        // However, I can't return anything! But the Promise chain link I produce
        // matches the one before me, so anything after me is type of integer!
    }).then([&](int val) -> float {
        lastCalled = true;
        // I am the last final block and I must accept integer!
        // However, I will also produce integer...
        return float(val * val);
    });
     
    promise.call(); // Calls the promise lambda inside of it
    REQUIRE(lastCalled == true);
    REQUIRE(last.getResult() == Approx(144.0f));
    REQUIRE_NOTHROW(promise.getResult());
}

class Worker {
public:
    Worker() {
            
    }

    template<typename T, typename F>
    ffw::Promise<T>& addTask(const F& lambda) {
        ffw::Promise<T>* promise = new ffw::Promise<T>([=](ffw::Promise<T>& self) -> void {
            self.resolve(lambda());
        });

        promises.push_back(promise);
        return *promise;
    }

    void execute() {
        thread = std::thread(&Worker::threadFunc, this);
    }

    void threadFunc() {
        for(ffw::PromiseI* promise : promises) {
            promise->call();
            delete promise;
        }

        promises.clear();
    }

    void join() {
        thread.join();
    }

    // Not thread safe but good enough for the test
    std::vector<ffw::PromiseI*> promises;
    std::thread thread;
};

TEST_CASE("Resolve via std::thread") {
    Worker worker;

    ffw::Promise<int> p1 = worker.addTask<int>([]() -> int {
        return 42 * 42;
    });

    ffw::Promise<std::string> p2 = p1.then([](int val) -> std::string {
        return std::to_string(val);
    });

    worker.execute();
    worker.join();

    ffw::Promise<int> p3 = p2.then([](std::string str) -> int {
        return std::stoi(str);
    });

    REQUIRE(p2.getResult().get() == "1764");
    REQUIRE(p3.getResult().get() == 1764);
}

ffw::Promise<std::string> doStuff(ffw::Promise<std::string>& ret, Worker* worker) {
    worker->addTask<int>([]() -> int {
        return 42 * 42;
    }).then([&](int value) -> void {
        ret.resolve(std::to_string(value));
    });

    return ret;
}

TEST_CASE("Resolve via std::thread advanced") {
    Worker worker;

    ffw::Promise<std::string> ret;

    ffw::Promise<std::string> p = doStuff(ret, &worker);

    ffw::Promise<int> p2 = p.then([](std::string value) -> int {
        return std::stoi(value);
    });

    worker.execute();
    worker.join();

    REQUIRE(p.getResult().get() == "1764");
    REQUIRE(p2.getResult().get() == 1764);
}

TEST_CASE("Resolve promise on instantination") {
    SECTION("integer type") {
        auto p = ffw::Promise<int>::makeResolved(123);
        REQUIRE(p.isResolved() == true);
        REQUIRE(p.getResult() == 123);
    }

    SECTION("void type") {
        auto p = ffw::Promise<void>::makeResolved();
        REQUIRE(p.isResolved() == true);
    }

    SECTION("string type") {
        auto p = ffw::Promise<std::string>::makeResolved("Hello World");
        REQUIRE(p.isResolved() == true);
        REQUIRE(p.getResult().get() == "Hello World");
    }
}

TEST_CASE("Reject promise on instantination") {
    SECTION("integer type") {
        auto p = ffw::Promise<int>::makeRejected<std::out_of_range>("Some error message");
        REQUIRE(p.isRejected() == true);
        REQUIRE_THROWS_AS(p.getResult(), std::out_of_range);
    }

    SECTION("void type") {
        auto p = ffw::Promise<void>::makeRejected<std::exception>();
        REQUIRE(p.isRejected() == true);
        REQUIRE_THROWS_AS(p.getResult(), std::exception);
    }

    SECTION("string type") {
        auto p = ffw::Promise<std::string>::makeRejected<std::runtime_error>("Some error message");
        REQUIRE(p.isRejected() == true);
        REQUIRE_THROWS_AS(p.getResult(), std::runtime_error);
    }
}
