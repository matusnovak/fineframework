/* This file is part of FineFramework project */
#ifndef FFW_THREAD
#define FFW_THREAD
#include <math.h>
#include <functional>

#if defined(_GLIBCXX_HAS_GTHREADS) || defined(_MSC_VER)
#define FFW_USING_STD_THREADS
#endif

#ifdef FFW_USING_STD_THREADS
#include <thread>
#else
#include <pthread.h>
#endif

#if defined(__linux__) || defined(__APPLE__)
#include <unistd.h>
#define FFW_SLEEP_MS(X) usleep(X * 1000)
#else
#define FFW_SLEEP_MS(X) Sleep((DWORD)X)
#endif

namespace ffw {
	inline void sleep(size_t ms) {
		FFW_SLEEP_MS(ms);
	}

	template<typename Signature>
	class Thread;

	template<typename Ret, typename... Args>
	class Thread<Ret(Args...)> {
	public:
		Thread() {
#ifdef FFW_USING_STD_THREADS
#else
			running.store(false);
#endif
		}

		template<class T>
		bool run(Ret(T::*func)(Args...), T* instance, Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, instance, std::forward<Args>(args)...);
#ifdef FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			running.store(true);
			int err = 0;
			if (err = pthread_create(&t, NULL, &Thread::threadFunc, this)) {
				//std::cerr << "pthread_create error code: " << err << std::endl;
				return false;
			}
			return true;
#endif
		}

		bool run(Ret(*func)(Args...), Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, std::forward<Args>(args)...);
#ifdef FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			running.store(true);
			int err = 0;
			if((err = pthread_create(&t, NULL, &Thread::threadFunc, this)) != 0) {
				//std::cerr << "pthread_create error code: " << err << std::endl;
				return false;
			}
			return true;
#endif
		}

		Ret& getResult() {
			return ret;
		}

		const Ret& getResult() const {
			return ret;
		}

		void join() {
#ifdef FFW_USING_STD_THREADS
			t.join();
#else
			pthread_join(t, NULL);
#endif
		}

		bool isRunning() const {
#ifdef FFW_USING_STD_THREADS
			return t.joinable();
#else
			return running.load();
#endif
		}
	private:
		static void* threadFunc(void* data) {
			Thread<Ret(Args...)>* ptr = (Thread<Ret(Args...)>*)(data);
			ptr->ret = ptr->target();
#ifdef FFW_USING_STD_THREADS
			return NULL;
#else
			ptr->running.store(false);
			pthread_exit(0);
			return NULL;
#endif
		}
		std::function<Ret()> target;
#ifdef FFW_USING_STD_THREADS
		std::thread t;
#else
		pthread_t t;
		std::atomic<bool> running;
#endif
		Ret ret;
	};

	template<typename... Args>
	class Thread<void(Args...)> {
	public:
		Thread() {
#ifdef FFW_USING_STD_THREADS
#else
			running.store(false);
#endif
		}

		template<class T>
		bool run(void(T::*func)(Args...), T* instance, Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, instance, std::forward<Args>(args)...);
#ifdef FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			running.store(true);
			int err = 0;
			if (err = pthread_create(&t, NULL, &Thread::threadFunc, this)) {
				//std::cerr << "pthread_create error code: " << err << std::endl;
				return false;
			}
			return true;
#endif
		}

		bool run(void(*func)(Args...), Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, std::forward<Args>(args)...);
#ifdef FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			running.store(true);
			int err = 0;
			if ((err = pthread_create(&t, NULL, &Thread::threadFunc, this)) != 0) {
				//std::cerr << "pthread_create error code: " << err << std::endl;
				return false;
			}
			return true;
#endif
		}

		void getResult() {
			// Nothing
		}

		void getResult() const {
			// Nothing
		}

		void join() {
#ifdef FFW_USING_STD_THREADS
			t.join();
#else
			pthread_join(t, NULL);
#endif
		}

		bool isRunning() const {
#ifdef FFW_USING_STD_THREADS
			return t.joinable();
#else
			return running.load();
#endif
		}
	private:
		static void* threadFunc(void* data) {
			Thread<void(Args...)>* ptr = (Thread<void(Args...)>*)(data);
			ptr->target();
#ifdef FFW_USING_STD_THREADS
			return NULL;
#else
			ptr->running.store(false);
			pthread_exit(0);
			return NULL;
#endif
		}
		std::function<void()> target;
#ifdef FFW_USING_STD_THREADS
		std::thread t;
#else
		pthread_t t;
		std::atomic<bool> running;
#endif
	};
}
#endif