/* This file is part of FineFramework project */
//==============================================================================
template <class T>
ffw::RangeIterator<T>::RangeIterator(T Value){
    value = Value;
}
//==============================================================================
template <class T>
bool ffw::RangeIterator<T>::operator != (const ffw::RangeIterator<T>& Other) const{
    return value != Other.value;
}
//==============================================================================
template <class T>
const T& ffw::RangeIterator<T>::operator*() const {
    return value;
}
//==============================================================================
template <class T>
ffw::RangeIterator<T>& ffw::RangeIterator<T>::operator ++ (){
    value++;
    return *this;
}
//==============================================================================
template <class T>
ffw::Range<T>::Range(T Min, T Max){
    min = Min;
    max = Max;
}
//==============================================================================
template <class T>
ffw::Range<T>::Range(T Max){
    min = 0;
    max = Max;
}
//==============================================================================
template <class T>
ffw::RangeIterator<T> ffw::Range<T>::begin(){
    return RangeIterator<T>(min);
}
//==============================================================================
template <class T>
ffw::RangeIterator<T> ffw::Range<T>::end(){
    return RangeIterator<T>(max);
}
