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

namespace ffw {
    class PromiseI {
    public:
        enum class Status {
            WAITING,
            RESOLVED,
            REJECTED
        };
        PromiseI(){

        }
        virtual ~PromiseI() {

        }
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

    template<class T>
    class PromiseResult;

    template<class T>
    class PromiseResult {
    public:
        PromiseResult() {
        }
        PromiseResult(const T& result):result(result) {
        }
        PromiseResult(T&& result):result(result) {
        }
        operator T() const {
            return result;
        }
        const T& get() const {
            return result;
        }
        T& get() {
            return result;
        }
    private:
        T result;
    };

    template<>
    class PromiseResult<void> {
    public:
        PromiseResult() {
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
#endif

    template<class T>
    class Promise : public PromiseI {
    public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
        struct Data {
            std::function<void(Promise<T>&)> func;
            std::list<PromiseI*> next;
            std::exception_ptr eptr;
            PromiseResult<T> result;
            std::atomic<Status> status;

            const PromiseResult<T> &getResult() const {
                switch(status.load()) {
                    case Status::RESOLVED:
                        return result;
                    case Status::REJECTED:
                        std::rethrow_exception(eptr);
                    default:
                        throw PromiseException("Promise is not resolved");
                }
            }

            const std::exception_ptr& getException() const {
                return eptr;
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
        ~Promise() {
        }
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
            return data->getException();
        }
        void resolve() {
            resolve(PromiseResult<T>());
        }
        void resolve(const PromiseResult<T>& value) {
            data->result = value;
            data->status.store(Status::RESOLVED);
            for(auto& p : data->next) {
                p->call();
            }
        }
        void reject(const std::exception_ptr& eptr) override {
            this->data->eptr = eptr;
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
        const PromiseResult<T> &getResult() const {
            return data->getResult();
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
            self.resolve(lambda(parent->getResult()));
        }

        template<typename Then, typename S, typename std::enable_if<std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<R>& self, const Then& lambda) {
            parent->getResult();
            self.resolve(lambda());
        }
    };

    template <>
    struct PromiseLambdaResolver<void> {
        template<typename Then, typename S, typename std::enable_if<!std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<void>& self, const Then& lambda) {
            lambda(parent->getResult());
            self.resolve();
        }

        template<typename Then, typename S, typename std::enable_if<std::is_void<S>::value>::type* = nullptr>
        static void func(typename Promise<S>::Data* parent, Promise<void>& self, const Then& lambda) {
            parent->getResult();
            lambda();
            self.resolve();
        }
    };

    template<typename E>
    struct PromiseExceptionResolver {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            try {
                std::rethrow_exception(parent->getException());
            } catch (E& e) {
                lambda(e);
            } catch (...) {
                // Do nothing
            }
            self.reject(std::current_exception());
        }
    };

    template<>
    struct PromiseExceptionResolver<const std::exception_ptr&> {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            lambda(parent->getException());
            self.reject(parent->getException());
        }
    };

    template<>
    struct PromiseExceptionResolver<std::exception_ptr> {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            lambda(parent->getException());
            self.reject(parent->getException());
        }
    };

    template<>
    struct PromiseExceptionResolver<void> {
        template<typename Fail, typename T, typename R>
        static void func(typename Promise<T>::Data* parent, Promise<R>& self, const Fail& lambda) {
            lambda();
            self.reject(parent->getException());
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


    
  
