/* This file is part of FineFramework project */
#ifndef FFW_THREAD
#define FFW_THREAD
#include "../config.h"
#include <math.h>
#include <functional>
#include <atomic>

#ifndef FFW_USING_STD_THREADS
#if defined(_GLIBCXX_HAS_GTHREADS) || defined(_MSC_VER)
#define FFW_USING_STD_THREADS 1
#else
#define FFW_USING_STD_THREADS 0
#endif
#endif

#if FFW_USING_STD_THREADS
#include <thread>
#else
#include <pthread.h>
#endif

namespace ffw {
	/**
	* @cond HIDDEN_SYMBOLS
	*/
	template<typename Signature>
	class Thread;
	/**
	* @endcond
	*/

	/**
	* @ingroup math
	* @brief Thread class that accepts non-void static and member functions
	* @details This thread class can accept any static or member function 
	* with variable arguments. The output of the target function is stored
	* and can begin retrieved after the thread execution. Why another thread class? 
	* Why not std::thread? The ffw::Thread uses std::thread only if the compiler allows it. 
	* Some older GCC compilers do not have access to std::thread. If the std::thread 
	* is not available, the ffw::Thread will use POSIX pthreads instead. This also 
	* applies for ffw::Mutex. Secondly, there are minor differences between pthreads 
	* and std::thread + std::mutex. The two classes: ffw::Thread and ffw::Mutex make 
	* sure that no matter which thread backend is being used, the written code and the 
	* behavior will be the same.
	* @code
	* // Some class
	* class Foo {
	*     public:
	*     float multiply(float a, float b) {
	*         // Some time intensive work...
	*         return a * b;
	*     }
	* }
	* // Our main function
	* int main(int ac, char** av){
	*     Foo foo;
	*     // Declare our thread that acceps a function
	*     // with two float arguments and returns float
	*     ffw::Thread<float(float, float)> thread;
	*     // Run function on the thread
	*     // You need to provide a function pointer, 
	*     // instance to the class, and function arguments
	*     thread.run(&Foo::multiply, &foo, 5.0f, 2.0f);
	*     // Wait for the thread to be done
	*     while(thread.isRunning()) {
	* 	      // Do something else...
	*     }
	*     thread.join();
	*     // Thread ended at this point, get the return value
	*     std::cout << "Thread executed! Return value: " << thread.getResult() << std::endl;
	* }
	* @endcode
	*/
	template<typename Ret, typename... Args>
	class Thread<Ret(Args...)> {
	public:
		Thread() {
			running.store(false);
		}
		virtual ~Thread() {
			if(isRunning())
				join();
		}
		/**
		* @brief Runs a thread on the member function
		* @param func Pointer to the member function
		* @param instance Instance to the class of the member function
		* @param args List of arguments that matches the function declaration
		*/
		template<class T>
		bool run(Ret(T::*func)(Args...), T* instance, Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, instance, std::forward<Args>(args)...);
			running.store(true);
#if FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			int err = 0;
			if ((err = pthread_create(&t, NULL, &Thread::threadFunc, this)) != 0) {
				return false;
			}
			return true;
#endif
		}
		/**
		* @brief Runs a thread on the static function
		* @param func Pointer to the static (non-member!) function
		* @param args List of arguments that matches the function declaration
		*/
		bool run(Ret(*func)(Args...), Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, std::forward<Args>(args)...);
			running.store(true);
#if FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			int err = 0;
			if((err = pthread_create(&t, NULL, &Thread::threadFunc, this)) != 0) {
				return false;
			}
			return true;
#endif
		}
		/**
		* @brief Returns the result returned by the executed function
		*/
		Ret& getResult() {
			return ret;
		}
		/**
		* @brief Returns the result returned by the executed function
		*/
		const Ret& getResult() const {
			return ret;
		}
		/**
		* @brief Waits for the thread
		*/
		void join() {
#if FFW_USING_STD_THREADS
			t.join();
#else
			pthread_join(t, NULL);
#endif
		}
		/**
		* @brief Checks if the thread is still running
		*/
		bool isRunning() const {
			return running.load();
		}
	private:
		static void* threadFunc(void* data) {
			Thread<Ret(Args...)>* ptr = (Thread<Ret(Args...)>*)(data);
			ptr->ret = ptr->target();
#if FFW_USING_STD_THREADS
			ptr->running.store(false);
			return NULL;
#else
			ptr->running.store(false);
			pthread_exit(0);
			return NULL;
#endif
		}
		std::function<Ret()> target;
#if FFW_USING_STD_THREADS
		std::thread t;
#else
		pthread_t t;
#endif
		std::atomic<bool> running;
		Ret ret;
	};

	/**
	* @ingroup math
	* @brief Thread class that accepts static and member void only functions
	* @details This thread class can accept any static or member function 
	* with variable arguments. The output of the target function is NOT stored
	* as this thread class accepts only void functions. To use non-void functions,
	* see ffw::Thread< Ret(Args...)> Why another thread class? 
	* Why not std::thread? The ffw::Thread uses std::thread only if the compiler allows it. 
	* Some older GCC compilers do not have access to std::thread. If the std::thread 
	* is not available, the ffw::Thread will use POSIX pthreads instead. This also 
	* applies for ffw::Mutex. Secondly, there are minor differences between pthreads 
	* and std::thread + std::mutex. The two classes: ffw::Thread and ffw::Mutex make 
	* sure that no matter which thread backend is being used, the written code and the 
	* behavior will be the same.
	* @code
	* // Some class
	* class Foo {
	*     public:
	*     void baz(int val) {
	*         // Some time intensive work...
	*         bar = val * val;
	*     }
	*     int bar;
	* }
	* // Our main function
	* int main(int ac, char** av){
	*     Foo foo;
	*     foo.bar = 10;
	*     // Declare our thread that acceps a void function
	*     ffw::Thread<void(void)> thread;
	*     // Run function on the thread
	*     // You need to provide a function pointer, 
	*     // instance to the class, and function arguments
	*     thread.run(&Foo::baz, &foo, 10);
	*     // Wait for the thread to be done
	*     while(thread.isRunning()) {
	* 	      // Do something else...
	*     }
	*     thread.join();
	*     // Thread ended at this point
	*     std::cout << "Thread executed! Result: " << foo.bar << std::endl;
	* }
	* @endcode
	*/
	template<typename... Args>
	class Thread<void(Args...)> {
	public:
		Thread() {
			running.store(false);
		}
		virtual ~Thread() {
			if(isRunning())
				join();
		}
		/**
		* @brief Runs a thread on the member function
		* @param func Pointer to the member function
		* @param instance Instance to the class of the member function
		* @param args List of arguments that matches the function declaration
		*/
		template<class T>
		bool run(void(T::*func)(Args...), T* instance, Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, instance, std::forward<Args>(args)...);
			running.store(true);
#if FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			int err = 0;
			if ((err = pthread_create(&t, NULL, &Thread::threadFunc, this)) != 0) {
				return false;
			}
			return true;
#endif
		}
		/**
		* @brief Runs a thread on the static function
		* @param func Pointer to the static (non-member!) function
		* @param args List of arguments that matches the function declaration
		*/
		bool run(void(*func)(Args...), Args&&... args) {
			if (isRunning())return false;
			target = std::bind(func, std::forward<Args>(args)...);
			running.store(true);
#if FFW_USING_STD_THREADS
			t = std::thread(&Thread::threadFunc, this);
			return true;
#else
			int err = 0;
			if ((err = pthread_create(&t, NULL, &Thread::threadFunc, this)) != 0) {
				return false;
			}
			return true;
#endif
		}
		/**
		* @brief Returns the result returned by the executed function
		* @details There is no returned value if you are using void function
		* to run a thread. 
		* @see ffw::Thread< Ret(Args...)>
		*/
		void getResult() {
			// Nothing
		}
		/**
		* @brief Returns the result returned by the executed function
		* @details There is no returned value if you are using void function
		* to run a thread.
		* @see ffw::Thread< Ret(Args...)>
		*/
		void getResult() const {
			// Nothing
		}
		/**
		* @brief Waits for the thread
		*/
		void join() {
#if FFW_USING_STD_THREADS
			t.join();
#else
			pthread_join(t, NULL);
#endif
		}
		/**
		* @brief Checks if the thread is still running
		*/
		bool isRunning() const {
			return running.load();
		}
	private:
		static void* threadFunc(void* data) {
			Thread<void(Args...)>* ptr = (Thread<void(Args...)>*)(data);
			ptr->target();
#if FFW_USING_STD_THREADS
			ptr->running.store(false);
			return NULL;
#else
			ptr->running.store(false);
			pthread_exit(0);
			return NULL;
#endif
		}
		std::function<void()> target;
#if FFW_USING_STD_THREADS
		std::thread t;
#else
		pthread_t t;
#endif
		std::atomic<bool> running;
	};
}
#endif