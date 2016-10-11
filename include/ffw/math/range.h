/* This file is part of FineFramework project */
#ifndef FFW_RANGE
#define FFW_RANGE

namespace ffw{
	/**
	 * @ingroup math
	 */
    template <class T> class RangeIterator{
    public:
        RangeIterator(T Value);
        bool operator != (const RangeIterator& Other) const;
        const T& operator*() const;
        RangeIterator& operator ++ ();
    private:
        T value;
    };
    /**
	 * @ingroup math
	 */
	template <class T> class Range{
    public:
        Range(T Min, T Max);
        Range(T Max);
        RangeIterator<T> begin();
        RangeIterator<T> end();
    private:
        T min;
        T max;
    };
};
#include "range.inl"
#endif
