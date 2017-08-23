/* This file is part of FineFramework project */
#ifndef FFW_MUTEX
#define FFW_MUTEX
#include "../config.h"
#include <math.h>
#include <functional>

#ifndef FFW_USING_STD_THREADS
#if defined(_GLIBCXX_HAS_GTHREADS) || defined(_MSC_VER)
#define FFW_USING_STD_THREADS 1
#else
#define FFW_USING_STD_THREADS 0
#endif
#endif

#if FFW_USING_STD_THREADS
#include <mutex>
#else
#include <pthread.h>
#endif

namespace ffw {
	/**
	 * @ingroup math
	 */
	class Mutex {
	public:
		inline Mutex() {
#if FFW_USING_STD_THREADS
#else
			pthread_mutex_init(&mut, NULL);
#endif
		}
		inline virtual ~Mutex() {
#if FFW_USING_STD_THREADS
#else
			pthread_mutex_destroy(&mut);
#endif
		}
		inline void lock() {
#if FFW_USING_STD_THREADS
			mut.lock();
#else
			pthread_mutex_lock(&mut);
#endif
		}
		inline void unlock() {
#if FFW_USING_STD_THREADS
			mut.unlock();
#else
			pthread_mutex_unlock(&mut);
#endif
		}
		inline bool tryLock() {
#if FFW_USING_STD_THREADS
			if (mut.try_lock()) {
				return true;
			}
			return false;
#else
			return (pthread_mutex_trylock(&mut) == 0);
#endif
		}
	private:
#if FFW_USING_STD_THREADS
		std::mutex mut;
#else
		pthread_mutex_t mut;
#endif
	};
};

#endif