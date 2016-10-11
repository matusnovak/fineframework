/* This file is part of FineFramework project */
#ifndef FFW_RING_BUFFER
#define FFW_RING_BUFFER

namespace ffw{
	/**
	 * @ingroup math
	 */
	template<class T> class RingBuffer {
	public:
		RingBuffer();
		RingBuffer(size_t Size);
		virtual ~RingBuffer();
		T* Back();
		void Create(size_t Size);
		bool Push(const T& Item);
		bool Pop(T* Item);
		size_t GetRange() const;
		size_t GetSize() const;
		size_t Size() const;
		bool IsFull() const;
		bool IsEmpty() const;
		size_t GetTail() const;
		size_t GetHead() const;
		void Clear();
		void Reset();
	private:
		std::atomic<size_t> head;
		std::atomic<size_t> tail;
		std::vector<T> elements;
		size_t size;
	};
};
#include "ringBuffrt.inl"
#endif