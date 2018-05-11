#include <ffw/math/promise.h>
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <thread>

TEST_CASE("Resolve promise and get std::future") {
    ffw::Promise<int> p;

    std::future<int> future = p.getFuture();
    REQUIRE(future.valid() == true);

    std::future_status status = future.wait_for(std::chrono::milliseconds(10));
    REQUIRE(status == std::future_status::timeout);

    p.resolve(123);

    status = future.wait_for(std::chrono::milliseconds(10));
    REQUIRE(status == std::future_status::ready);

    REQUIRE(future.valid() == true);
    REQUIRE(future.get() == 123);
}

TEST_CASE("Resolve promise second time must fail") {
    ffw::Promise<int> p;

    REQUIRE(p.isFinished() == false);
    REQUIRE(p.isRejected() == false);
    REQUIRE(p.isResolved() == false);
    REQUIRE(p.getStatus() == ffw::Promise<int>::Status::WAITING);

    p.resolve(123);

    REQUIRE_THROWS_AS(p.resolve(456), std::future_error);
}

TEST_CASE("Resolve promise chain and get std::future") {
    ffw::Promise<int> p;

    ffw::Promise<std::string> result = p.then([](int val) -> bool {
        return true;
    }).then([](bool val) -> float {
        return 123.456f;
    }).then([](float val) -> std::string {
        return "Hello World!";
    });

    std::future<std::string> future = result.getFuture();

    p.resolve(123);

    std::future_status status = future.wait_for(std::chrono::milliseconds(10));
    REQUIRE(status == std::future_status::ready);

    REQUIRE(future.valid() == true);
    REQUIRE(future.get() == "Hello World!");
}

std::thread doThreadStuffThread;
ffw::Promise<int> doThreadStuffPromise;

ffw::Promise<int> doThreadStuff(int value) {
    doThreadStuffPromise = ffw::Promise<int>([=](ffw::Promise<int>& self){
        self.resolve(int(value * value));
    });

    doThreadStuffThread = std::thread([&](){
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        doThreadStuffPromise.call();
    });

    return doThreadStuffPromise;
}

TEST_CASE("Resolve promise within thread and get std::future") {
    ffw::Promise<int> result = doThreadStuff(5);
    std::future<int> future = result.getFuture();

    doThreadStuffThread.join();

    std::future_status status = future.wait_for(std::chrono::milliseconds(10));
    REQUIRE(status == std::future_status::ready);

    REQUIRE(future.valid() == true);
    REQUIRE(future.get() == 25);
}

TEST_CASE("Resolve promise chain within thread and get std::future") {
    ffw::Promise<int> result = doThreadStuff(5);
    std::future<float> future = result.then([](int val) -> float {
        return float(val);
    }).getFuture();

    doThreadStuffThread.join();

    std::future_status status = future.wait_for(std::chrono::milliseconds(10));
    REQUIRE(status == std::future_status::ready);

    REQUIRE(future.valid() == true);
    REQUIRE(future.get() == Approx(25.0f));
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
        for(ffw::PromiseInterface* promise : promises) {
            promise->call();
            delete promise;
        }

        promises.clear();
    }

    void join() {
        thread.join();
    }

    // Not thread safe but good enough for the test
    std::vector<ffw::PromiseInterface*> promises;
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

    REQUIRE(p2.getResult() == "1764");
    REQUIRE(p3.getResult() == 1764);
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

    REQUIRE(p.getResult() == "1764");
    REQUIRE(p2.getResult() == 1764);
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
        auto p = ffw::Promise<std::string>::makeResolved(std::string("Hello World"));
        REQUIRE(p.isResolved() == true);
        REQUIRE(p.getResult() == "Hello World");
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
