/* This file is part of FineFramework project */
template <class T>
inline ffw::RingBuffer<T>::RingBuffer(){
	size = 0;
	tail.store(0);
	head.store(0);
}
template <class T>
inline ffw::RingBuffer<T>::RingBuffer(size_t Size){
	tail.store(0);
	head.store(0);
	elements.resize(Size+1);
	size = Size;
}
template <class T>
inline ffw::RingBuffer<T>::~RingBuffer(){
}
template <class T>
inline void ffw::RingBuffer<T>::Create(size_t Size){
	Reset();
	elements.resize(Size+1);
	size = Size;
}
template <class T>
inline T* ffw::RingBuffer<T>::Back(){
	size_t current = head.load();
	if(current == tail.load())return NULL;
	return &elements[current];
}
template <class T>
inline bool ffw::RingBuffer<T>::Push(const T& Item){
	size_t current = tail.load();
	size_t next = (current + 1) % (size + 1);
	if(next == head.load() || size == 0)return false;
	elements[current] = Item;
	tail.store(next);
	return true;
}
template <class T>
inline bool ffw::RingBuffer<T>::Pop(T* Item){
	size_t current = head.load();
	if(current == tail.load())return false;
	*Item = elements[current];
	head.store((current + 1) % (size + 1));
	return true;
}
template <class T>
inline size_t ffw::RingBuffer<T>::GetRange() const {
	return size;
}
template <class T>
inline size_t ffw::RingBuffer<T>::GetTail() const {
	return tail.load();
}
template <class T>
inline size_t ffw::RingBuffer<T>::GetHead() const {
	return head.load();
}
template <class T>
inline size_t ffw::RingBuffer<T>::GetSize() const {
	size_t currentTail = tail.load();
	size_t currentHead = head.load();
	if(currentTail == currentHead)return 0;
	//std::cout << "ret size head: " << currentHead << " tail: " << currentTail << std::endl;
	if(currentTail > currentHead){
        return currentTail - currentHead;
	}
	//if(tail_ > head_){
        return size - currentHead + currentTail +1;
	//}
    //return 0;
}
template <class T>
inline size_t ffw::RingBuffer<T>::Size() const {
	return GetSize();
}
template <class T>
inline bool ffw::RingBuffer<T>::IsFull() const {
	size_t next = (tail.load() + 1) % (size + 1);
	return (next == head.load());
}
template <class T>
inline bool ffw::RingBuffer<T>::IsEmpty() const {
	return (tail.load() == head.load());
}
template <class T>
inline void ffw::RingBuffer<T>::Clear(){
	elements.clear();
	tail.store(0);
	head.store(0);
}
template <class T>
inline void ffw::RingBuffer<T>::Reset(){
	tail.store(0);
	head.store(0);
}
