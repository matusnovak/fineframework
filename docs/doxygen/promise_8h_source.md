---
search: false
---

# promise.h File Reference

**[Go to the documentation of this file.](promise_8h.md)**
Source: `include/ffw/math/promise.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
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
    class PromiseInterface {
    public:
        enum class Status {
            WAITING,
            RESOLVED,
            REJECTED
        };
        PromiseInterface() = default;
        virtual ~PromiseInterface() = default;
        virtual void call() = 0;
        virtual void reject(const std::exception_ptr& e) = 0;
        template<typename E, typename... Args>
        void rejectWith(Args&&... args) {
            try {
                throw E(std::forward<Args>(args)...);
            } catch (...) {
                reject(std::current_exception());
            }
        }
    };

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

        Promise():data(new Data()) {
            data->func = nullptr;
            data->status.store(Status::WAITING);
        }

        template<typename F>
        Promise(F const& lambda):data(new Data()) {
            data->func = lambda;
            data->status.store(Status::WAITING);
        }
        Promise(Promise<T>&& other):data(nullptr) {
            swap(other);
        }
        Promise(const Promise<T>& other):data(other.data) {
        }
        ~Promise() = default;
        Promise<T>& operator = (const Promise<T>& other) {
            data = other.data;
        }
        Promise<T>& operator = (Promise<T>&& other) {
            swap(other);
            return *this;
        }
        void swap(Promise<T>& other) {
            if (this != &other) {
                std::swap(data, other.data);
            }
        }
        const std::exception_ptr& getException() const {
            return data->eptr;
        }
        template<class Q = T>
        typename std::enable_if<std::is_void<Q>::value, void>::type resolve() {
            data->rawPromise.set_value();
            data->status.store(Status::RESOLVED);
            for (auto& p : data->next) {
                p->call();
            }
        }
        template<class Q = T>
        typename std::enable_if<!std::is_void<Q>::value, void>::type resolve(PromiseValue<T>&& value) {
            data->rawPromise.set_value(value.v);
            std::swap(data->result, value);
            data->status.store(Status::RESOLVED);
            for(auto& p : data->next) {
                p->call();
            }
        }
        void reject(const std::exception_ptr& eptr) override {
            data->rawPromise.set_exception(eptr);
            data->eptr = eptr;
            data->status.store(Status::REJECTED);
            for(auto& p : data->next) {
                p->call();
            }
        }
        void call() override {
            if(data->func) {
                try {
                    data->func(*this);
                } catch (...) {
                    reject(std::current_exception());
                }
            }
        }
        template<class Q = T>
        typename std::enable_if<!std::is_void<Q>::value, Q>::type getResult() const {
            data->checkStatus();
            return data->result.v;
        }
        template<class Q = T>
        typename std::enable_if<std::is_void<Q>::value, void>::type getResult() const {
            data->checkStatus();
        }
        std::future<T> getFuture() const {
            return data->rawPromise.get_future();
        }
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
        template<typename Then, typename Fail, typename R = typename PromiseLambdaHelper<Then, T>::returnType>
        Promise<R>& thenOrFail(Then const& lambdaThen, Fail const& lambdaFail) {
            Promise<R>* ret = makePromise<typename std::decay<decltype(arg1_type_helper(&Fail::operator()))>::type, Then, decltype(lambdaFail), R>(data.get(), lambdaThen, lambdaFail);
            data->next.push_back(ret);
            if(data->status.load() != Status::WAITING) {
                ret->call();
            }
            return *ret;
        }
        bool isResolved() const {
            return data->status.load() == Status::RESOLVED;
        }
        bool isRejected() const {
            return data->status.load() == Status::REJECTED;
        }
        bool isFinished() const {
            return data->status.load() != Status::WAITING;
        }
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
```


    
  
