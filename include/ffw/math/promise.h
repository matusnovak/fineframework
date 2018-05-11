/* This file is part of FineFramework project */
#ifndef FFW_PROMISE_H
#define FFW_PROMISE_H
#include "../config.h"

#include <memory>
#include <functional>
#include <atomic>
#include <list>
#include <future>

namespace ffw {
    /**
     * @brief Promise interface class
     * @ingroup math
     */
    class PromiseInterface {
    public:
        /**
         * @brief The status of the promise
         */
        enum class Status {
            WAITING,
            RESOLVED,
            REJECTED
        };
        PromiseInterface() = default;
        virtual ~PromiseInterface() = default;
        /**
         * @brief Calls the function associated within the promise
         */
        virtual void call() = 0;
        /**
         * @brief Rejects this promise with an exception
         * @code{.cpp}
         * Promise<int> p;
         * try {
         *     throw std::runtime_error("Something went wrong");
         * } catch (...){
         *     p.reject(std::current_exception());
         * }
         * @endcode
         */
        virtual void reject(const std::exception_ptr& e) = 0;
        /**
         * @brief Rejects this promise with an exception
         * @details This method will construct an exception based on the template and
         * constructor arguments provided.
         * @code{.cpp}
         * Promise<int> p;
         * p.rejectWith<std::runtime_error>("Something went wrong");
         * @endcode
         */
        template<typename E, typename... Args>
        void rejectWith(Args&&... args) {
            try {
                throw E(std::forward<Args>(args)...);
            } catch (...) {
                reject(std::current_exception());
            }
        }
    };

    /**
     * @ingroup math
     */
    class PromiseException : public std::runtime_error {
    public:
        PromiseException(const std::string& str) :std::runtime_error(str) {

        }
    };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    template<typename R>
    struct PromiseLambdaResolver;

    template<typename E>
    struct PromiseExceptionResolver;

    template<class T>
    class Promise;

    template<typename F, typename T>
    struct PromiseLambdaHelper {
        typedef typename std::result_of<F&(T)>::type returnType;
    };

    template<typename F>
    struct PromiseLambdaHelper<F, void> {
        typedef typename std::result_of<F&()>::type returnType;
    };

    template<class V>
    class PromiseValue;

    template<class T>
    class PromiseValue {
    public:
        PromiseValue():v() {
        }
        PromiseValue(T&& value) :v(std::move(value)) {
        }
        T v;
    };

    template<>
    class PromiseValue<void> {
    public:
        PromiseValue() {
        }
    };
#endif

    /**
     * @ingroup math
     * @brief A simple promise class with chainable lambdas
     * @details This is a very simple implementation of JavaScript like Promise. 
     * This promise can accept any kind of template type, including void. Any further chain links
     * can be added by creating new Promise instances using "then" and "fail" (or "thenOrFail") methods.
     * The template type of those new chain links is defined based on the return type of the lambda
     * methods passed into "then" and "fail" methods.
     * @code{.cpp}
     * // Using lambda for the first promise is optional! 
     * // You can always resolve promise outside!
     * ffw::Promise<void> promise([](ffw::Promise<void>& self) -> void {
     *     // Do some work
     *     self.resolve();
     * });
     * 
     * ffw::Promise<float>& last = promise.then([]() {
     *     // I am the first chain block to be executed
     *     // and I will produce std::string
     *     return std::string("Hello World!");
     * }).then([](std::string str) {
     *     // I am the second block
     *     // and I must accept std::string because the previous
     *     // chain link produces std::string
     *     // But I will produce size_t
     *     return str.size();
     * }).then([](size_t len) {
     *     // I am the third block
     *     // I must accept size_t but I will cast it to int for no reason
     *     return static_cast<int>(len);
     * }).fail([](std::exception& e){
     *     // I am the fail block
     *     // I will be executed if any of the blocks above (or parent promise)
     *     // produces exception that matches my lambda argument!
     *     // However, I can't return anything! But the Promise chain link I produce
     *     // matches the one before me, so anything after me is type of integer!
     * }).then([](int val) {
     *     // I am the last final block and I must accept integer!
     *     // However, I will produce float...
     *     return float(val * val);
     * });
     * 
     * promise.call(); // Calls the promise lambda inside of it
     * std::cout << "Resolved with: " << last.getResult() << std::endl;
     * // Prints: "Resolved with: 144"
     * @endcode
     */
    template<class T>
    class Promise : public PromiseInterface {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
        struct Data {
            std::function<void(Promise<T>&)> func;
            std::list<PromiseInterface*> next;
            std::promise<T> rawPromise;
            PromiseValue<T> result;
            std::exception_ptr eptr;
            std::atomic<Status> status;

            void checkStatus() {
                const auto s = status.load();
                if (s == Status::REJECTED) std::rethrow_exception(eptr);
                if (s == Status::WAITING) std::future_error(std::make_error_code(std::future_errc::no_state));
            }
        };

        template<typename E, typename Then, typename Fail, typename R>
        static Promise<R>* makePromise(Data* parent, Then const& then, Fail const& fail);

        // Source of arg1_traits_impl: https://stackoverflow.com/a/8712212 by Xeo
        template<typename FPtr>
        struct arg1_traits_impl;

        template<typename R, typename C>
        struct arg1_traits_impl<R (C::*)(void)>{typedef void arg1_type;};

        template<typename R, typename C>
        struct arg1_traits_impl<R (C::*)(void) const>{typedef void arg1_type;};

        template<typename R, typename C, typename A1>
        struct arg1_traits_impl<R (C::*)(A1)>{typedef A1 arg1_type;};

        template<typename R, typename C, typename A1>
        struct arg1_traits_impl<R (C::*)(A1) const>{typedef A1 arg1_type;};

        template<typename TT>
        static typename arg1_traits_impl<TT>::arg1_type arg1_type_helper(TT);
#endif
        template<class Q = T>
        static typename std::enable_if<std::is_same<Q, void>::value, Promise<Q>>::type makeResolved() {
            Promise<T> ret;
            ret.resolve();
            return ret;
        }

        template<class Q = T>
        static typename std::enable_if<!std::is_same<Q, void>::value, Promise<Q>>::type makeResolved(PromiseValue<T>&& value) {
            Promise<T> ret;
            ret.resolve(std::move(value));
            return ret;
        }

        template<typename E, typename... Args>
        static Promise<T> makeRejected(Args&&... args) {
            Promise<T> ret;
            try {
                throw E(std::forward<Args>(args)...);
            }
            catch (...) {
                ret.reject(std::current_exception());
            }
            return ret;
        }

        /**
         * @brief Default constructor with no lambda function
         */
        Promise():data(new Data()) {
            data->func = nullptr;
            data->status.store(Status::WAITING);
        }

        /**
         * @brief Constructor that accepts lambda
         * @details The lambda must accept one parameter, a reference to
         * a promise, which is essentially a "this" pointer. You can use
         * the parameter to either resolve or reject the promise.
         * @code{.cpp}
         * ffw::Promise<int> p([](ffw::Promise<int>& self){
         *     self.resolve(123456);
         * }
         * p.call();
         * @endcode
         */
        template<typename F>
        Promise(F const& lambda):data(new Data()) {
            data->func = lambda;
            data->status.store(Status::WAITING);
        }
        /**
         * @brief Move constructor
         */
        Promise(Promise<T>&& other):data(nullptr) {
            swap(other);
        }
        /**
         * @brief Copy constructor
         */
        Promise(const Promise<T>& other):data(other.data) {
        }
        ~Promise() = default;
        Promise<T>& operator = (const Promise<T>& other) {
            data = other.data;
        }
        /**
         * @brief Move operator
         */
        Promise<T>& operator = (Promise<T>&& other) {
            swap(other);
            return *this;
        }
        void swap(Promise<T>& other) {
            if (this != &other) {
                std::swap(data, other.data);
            }
        }
        /**
         * @brief Returns the exception associated with this promise
         * @note This function does not throw! If the promise has not been rejected, the returned
         * value is an empty/invalid std::exception_ptr.
         */
        const std::exception_ptr& getException() const {
            return data->eptr;
        }
        /**
         * @brief Resolves the promise with a default value of type T
         * @note This function is only enabled on void types
         * @details You can resolve the promis only once! Otherwise an exception
         * std::future_error is thrown with error category of promise_already_satisfied
         * is void
         * @throws std::future_error if the promise has already been resolved
         * @code
         * ffw::Promise<void> p;
         * std::cout << "Is resolved? " << p.isResolved() << std::endl;
         * // prints: Is resolved? 0
         * 
         * p.resolve();
         * 
         * std::cout << "Is resolved? " << p.isResolved() << std::endl;
         * // prints: Is resolved? 1
         * @endcode
         */
        template<class Q = T>
        typename std::enable_if<std::is_void<Q>::value, void>::type resolve() {
            data->rawPromise.set_value();
            data->status.store(Status::RESOLVED);
            for (auto& p : data->next) {
                p->call();
            }
        }
        /**
         * @brief Resolves the promise with a value of type T
         * @details You can resolve the promis only once! Otherwise an exception
         * std::future_error is thrown with error category of promise_already_satisfied
         * @note This function is only enabled on non-void types
         * @throws std::future_error if the promise has already been resolved
         * @code
         * ffw::Promise<int> p;
         * std::cout << "Is resolved? " << p.isResolved() << std::endl;
         * // prints: Is resolved? 0
         * 
         * p.resolve(123);
         * 
         * std::cout << "Is resolved? " << p.isResolved() << std::endl;
         * // prints: Is resolved? 1
         * 
         * std::cout << "result: " << p.getResult() << std::endl;
         * // prints: result: 123
         * @endcode
         */
        template<class Q = T>
        typename std::enable_if<!std::is_void<Q>::value, void>::type resolve(PromiseValue<T>&& value) {
            data->rawPromise.set_value(value.v);
            std::swap(data->result, value);
            data->status.store(Status::RESOLVED);
            for(auto& p : data->next) {
                p->call();
            }
        }
        /**
         * @brief Rejects the promise with an exception
         * @details You can reject the promis only once! Otherwise an exception
         * std::future_error is thrown with error category of promise_already_satisfied
         * @throws std::future_error if the promise has already been rejected
         * @code{.cpp}
         * Promise<int> p;
         * try {
         *     throw std::runtime_error("Something went wrong");
         * } catch (...) {
         *     p.reject(std::current_exception());
         * }
         * @endcode
         */
        void reject(const std::exception_ptr& eptr) override {
            data->rawPromise.set_exception(eptr);
            data->eptr = eptr;
            data->status.store(Status::REJECTED);
            for(auto& p : data->next) {
                p->call();
            }
        }
        /**
         * @brief Calls the function within this promise
         * @code{.cpp}
         * ffw::Promise<int> p([](ffw::Promise<int>& self){
         *     self.resolve(123456);
         * }
         * p.call();
         * @endcode
         */
        void call() override {
            if(data->func) {
                try {
                    data->func(*this);
                } catch (...) {
                    reject(std::current_exception());
                }
            }
        }
        /**
         * @biref Returns the resul of this promise
         * @note This function is only enabled on non-void types
         * @throws std::future_error if the promise has not yet been resolved or rejected
         * @throws E if the promise has been rejected with exception of type E
         * @code{.cpp}
         * ffw::Promise<int> p;
         * p.resolve(42);
         * 
         * std::cout << "Result: " << p.getResult() << std::endl;
         * // Prints "Result: 42"
         * @endcode
         */
        template<class Q = T>
        typename std::enable_if<!std::is_void<Q>::value, Q>::type getResult() const {
            data->checkStatus();
            return data->result.v;
        }
        /**
        * @biref Returns the resul of this promise
        * @note This function is only enabled on void types
        * @throws std::future_error if the promise has not yet been resolved or rejected
        * @throws E if the promise has been rejected with exception of type E
        * @code{.cpp}
        * ffw::Promise<void> p;
        * p.resolve();
        *
        * std::cout << "Resolved? " << p.isResolved() << std::endl;
        * // Prints "Resolved? 1"
        * @endcode
        */
        template<class Q = T>
        typename std::enable_if<std::is_void<Q>::value, void>::type getResult() const {
            data->checkStatus();
        }
        /**
         * @brief Returns std::future<T>
         * @code{.cpp}
         * ffw::Promise<bool> p;
         * std::future<int> = p.then([](bool val) -> int {
         *     return val ? 123 : -1;
         * }).getFuture();
         * 
         * std::future_status status = future.wait_for(std::chrono::milliseconds(1000));
         * // Waits for one second
         * // Status is std::future_status::timeout because promise has not been resolved
         * 
         * p.resolve(true);
         * status = future.wait_for(std::chrono::milliseconds(1000));
         * // Status is now std::future_status::ready!
         * 
         * std::cout << "result: " << future.get() << std::endl;
         * // prints result: 123
         * @endcode
         */
        std::future<T> getFuture() const {
            return data->rawPromise.get_future();
        }
        /**
         * @biref Creates a new then chain link with lambda
         * @details The lambda will be executed once the parent (the instance of the method you are calling)
         * has been be resolved. The return value of lambda determines the template type of the Promise returned.
         * For example, you create a promise that performs an SQL query which returns a raw string. Your next
         * "then" chain link can have a lambda that accepts a string and produces an instance of class. You can 
         * then extend the chain even further by another "then" which accepts the instance of class and produces
         * bool or anything else.
         * @code{.cpp}
         * ffw::Promise<std::string> p;
         * 
         * ffw::Promise<int>& next = p.then([](std::string str) -> int {
         *     std::cout << "Parent promise was resolved with: " << str << std::endl;
         *     return str.size();
         * });
         * 
         * ffw::Promise<void>& last = next.then([](int val) -> void {
         *     std::cout << "Received integer of: " << val << std::endl;
         * });
         * 
         * p.resolve("Hello!");
         * // Prints: "Parent promise was resolved with: Hello!"
         * //         "Received integer of: 6"
         * 
         * // You don't need to explicitly declare the instances of promises as above
         * // You can make them more simple as below:
         * 
         * p.then([](std::string str) -> int {
         *       std::cout << "Parent promise was resolved with: " << str << std::endl;
         *     return str.size();
         * }).then([](int val) -> void {
         *     std::cout << "Received integer of: " << val << std::endl;
         * });
         * @endcode
         */
        template<typename Then, typename R = typename PromiseLambdaHelper<Then, T>::returnType>
        Promise<R>& then(Then const& lambda) {
            const auto& lambdaFail = [](const std::exception_ptr& eptr) {(void)eptr; };
            Promise<R>* ret = makePromise<const std::exception_ptr&, Then, decltype(lambdaFail), R>(data.get(), lambda, lambdaFail);
            data->next.push_back(ret);
            if(data->status.load() != Status::WAITING) {
                ret->call();
            }
            return *ret;
        }
        /**
         * @biref Creates a new fail chain link with lambda
         * @details The lambda will be executed once the parent (the instance of the method you are calling)
         * has been be rejected. 
         * @code{.cpp}
         * ffw::Promise<std::string> p;
         * 
         * ffw::Promise<std::string>& next = p.fail([](std::runtime_exception& e){
         *     std::cout << "runtime_exception has been thrown!" << std::endl;
         * });
         * 
         * ffw::Promise<std::string>& last = next.fail([](std::exception& e){
         *     std::cout << "raw exception has been thrown!" << std::endl;
         * });
         * 
         * ffw::Promise<std::string>& test = last.fail([](const std::exception_ptr& eptr){
         *     try {
         *         std::rethrow_exception(eptr);
         *     } catch (std::runtime_exception& e){
         *         std::cout << "Caught runtime_exception!" << std::endl;
         *     } catch (std::exception& e){
         *         std::cout << "Caught raw exception!" << std::endl;
         *     }
         * });
         * 
         * p.rejectWith<std::runtime_exception>("Hello!");
         * // Prints: "runtime_exception has been thrown!"
         * //         "raw exception has been thrown!"
         * //         "Caught runtime_exception!"
         * // Both first two "fail" lambdas will be called because both raw std::exception
         * // and std::runtime_error match the exception thrown.
         * // The last fail lambda will also be called because it accepts any exception in form of 
         * // std::exception_ptr
         * @endcode
         */
        template<typename Fail>
        Promise<T>& fail(Fail const& lambdaFail) {
            const auto& lambdaThen = [](T val) -> T {return val; };
            Promise<T>* ret = makePromise<typename std::decay<decltype(arg1_type_helper(&Fail::operator()))>::type, decltype(lambdaThen), Fail, T>(data.get(), lambdaThen, lambdaFail);
            data->next.push_back(ret);
            if(data->status.load() != Status::WAITING) {
                ret->call();
            }
            return *ret;
        }
        /**
         * @biref Creates a new then + fail chain link with lambda
         * @details Similarly with "then" and "fail" methods, you can combine those two and create
         * one chain link that will contain both "then" and "fail" lambdas. 
         */
        template<typename Then, typename Fail, typename R = typename PromiseLambdaHelper<Then, T>::returnType>
        Promise<R>& thenOrFail(Then const& lambdaThen, Fail const& lambdaFail) {
            Promise<R>* ret = makePromise<typename std::decay<decltype(arg1_type_helper(&Fail::operator()))>::type, Then, decltype(lambdaFail), R>(data.get(), lambdaThen, lambdaFail);
            data->next.push_back(ret);
            if(data->status.load() != Status::WAITING) {
                ret->call();
            }
            return *ret;
        }
        /**
         * @brief Returns true if the promise has been resolved
         */
        bool isResolved() const {
            return data->status.load() == Status::RESOLVED;
        }
        /**
         * @brief Returns true if the promise has been rejected
         */
        bool isRejected() const {
            return data->status.load() == Status::REJECTED;
        }
        /**
         * @brief Returns true if the promise has been either resolved or rejected
         */
        bool isFinished() const {
            return data->status.load() != Status::WAITING;
        }
        /**
         * @brief Returns the status of the promise (REJECTED, RESOLVED, or WAITING)
         */
        Status getStatus() const {
            return data->status.load();
        }
    private:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
        std::shared_ptr<Data> data;
#endif
    };

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    template<typename R>
    struct PromiseLambdaResolver {
        template<typename Then, typename S, typename std::enable_if<!std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<R>& self, const Then& lambda) {
            parent->checkStatus();
            self.resolve(lambda(parent->result.v));
        }

        template<typename Then, typename S, typename std::enable_if<std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<R>& self, const Then& lambda) {
            parent->checkStatus();
            self.resolve(lambda());
        }
    };

    template <>
    struct PromiseLambdaResolver<void> {
        template<typename Then, typename S, typename std::enable_if<!std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<void>& self, const Then& lambda) {
            parent->checkStatus();
            lambda(parent->result.v);
            self.resolve();
        }

        template<typename Then, typename S, typename std::enable_if<std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<void>& self, const Then& lambda) {
            parent->checkStatus();
            lambda();
            self.resolve();
        }
    };

    template<typename E>
    struct PromiseExceptionResolver {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            try {
                std::rethrow_exception(parent->eptr);
            }
            catch (E& e) {
                lambda(e);
            }
            catch (...) {
                // Do nothing
            }
            self.reject(std::current_exception());
        }
    };

    template<>
    struct PromiseExceptionResolver<const std::exception_ptr&> {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            lambda(parent->eptr);
            self.reject(parent->eptr);
        }
    };

    template<>
    struct PromiseExceptionResolver<std::exception_ptr> {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            lambda(parent->eptr);
            self.reject(parent->eptr);
        }
    };

    template<>
    struct PromiseExceptionResolver<void> {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            lambda();
            self.reject(parent->eptr);
        }
    };

    template<typename T>
    template<typename E, typename Then, typename Fail, typename R>
    Promise<R>* Promise<T>::makePromise(Data* parent, Then const& then, Fail const& fail) {
        return new Promise<R>([=](Promise<R>& self){
            if(parent->status.load() == Status::RESOLVED) {
                try {
                    PromiseLambdaResolver<R>::template func<Then, T>(parent, self, then);
                }
                catch (...) {
                    self.reject(std::current_exception());
                }
            }
            else if(parent->status.load() == Status::REJECTED) {
                try {
                    PromiseExceptionResolver<E>::template func<Fail, T, R>(parent, self, fail);
                } catch (...) {
                    self.reject(std::current_exception());
                }
            }
            else {
                throw PromiseException("Parent promise is not resolved");
            }
        });
    }

    template<>
    template<typename Fail>
    Promise<void>& Promise<void>::fail(Fail const& lambdaFail) {
        const auto& lambdaThen = []() -> void {return; };
        Promise<void>* ret = makePromise<typename std::decay<decltype(arg1_type_helper(&Fail::operator()))>::type, decltype(lambdaThen), Fail, void>(data.get(), lambdaThen, lambdaFail);
        data->next.push_back(ret);
        if(data->status.load() != Status::WAITING) {
            ret->call();
        }
        return *ret;
    }
#endif
}
#endif