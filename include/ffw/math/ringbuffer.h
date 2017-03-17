/* This file is part of FineFramework project */
#ifndef FFW_RING_BUFFER
#define FFW_RING_BUFFER

namespace ffw{
	/**
	 * @ingroup math
	 */
	template<class T> class RingBuffer {
	public:
		inline RingBuffer() {
			size = 0;
			tail.store(0);
			head.store(0);
		}

		inline RingBuffer(size_t Size) {
			tail.store(0);
			head.store(0);
			elements.resize(Size + 1);
			size = Size;
		}

		inline ~RingBuffer() {
		}

		inline void create(size_t Size) {
			reset();
			elements.resize(Size + 1);
			size = Size;
		}

		inline T* back() {
			size_t current = head.load();
			if (current == tail.load())return NULL;
			return &elements[current];
		}

		inline bool push(const T& Item) {
			size_t current = tail.load();
			size_t next = (current + 1) % (size + 1);
			if (next == head.load() || size == 0)return false;
			elements[current] = Item;
			tail.store(next);
			return true;
		}

		inline bool Pop(T* Item) {
			size_t current = head.load();
			if (current == tail.load())return false;
			*Item = elements[current];
			head.store((current + 1) % (size + 1));
			return true;
		}

		inline size_t getRange() const {
			return size;
		}

		inline size_t range() const {
			return size;
		}

		inline size_t getTail() const {
			return tail.load();
		}

		inline size_t getHead() const {
			return head.load();
		}

		inline size_t getSize() const {
			size_t currentTail = tail.load();
			size_t currentHead = head.load();
			if (currentTail == currentHead)return 0;
			if (currentTail > currentHead) {
				return currentTail - currentHead;
			}
			return size - currentHead + currentTail + 1;
		}

		inline size_t Size() const {
			return getSize();
		}

		inline bool isFull() const {
			size_t next = (tail.load() + 1) % (size + 1);
			return (next == head.load());
		}

		inline bool isEmpty() const {
			return (tail.load() == head.load());
		}

		inline void clear() {
			elements.clear();
			tail.store(0);
			head.store(0);
			size = 0;
		}

		inline void reset() {
			tail.store(0);
			head.store(0);
		}
	private:
		std::atomic<size_t> head;
		std::atomic<size_t> tail;
		std::vector<T> elements;
		size_t size;
	};
};
#endif
