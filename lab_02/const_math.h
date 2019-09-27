#ifndef const_math_h
#define const_math_h

#include "base_iterator.h"
#include "const_iterator.h"

using namespace iterator_core;

template<typename ValueType>
const ValueType& const_iterator<ValueType>::operator *() const
{
    return *(this->ptr);
}

template<typename ValueType>
const ValueType* const_iterator<ValueType>::operator ->() const
{
    return this->ptr;
}

template<typename ValueType>
const_iterator<ValueType>::const_iterator(const const_iterator<ValueType>& iter)
: base_iterator<ValueType>(iter.ptr) {}

template<typename ValueType>
const_iterator<ValueType>::const_iterator(ValueType* ptr)
: base_iterator<ValueType>(ptr) {}

#endif /* const_math_h */
