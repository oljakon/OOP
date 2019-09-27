#ifndef base_iterator_math_h
#define base_iterator_math_h

#include "base_iterator.h"

using namespace iterator_core;

template<typename ValueType>
base_iterator<ValueType>::base_iterator(const base_iterator<ValueType> &iter)
{
    this->ptr = iter.ptr;
}
template<typename ValueType>
base_iterator<ValueType>::base_iterator()
{
    this->ptr = nullptr;
}

template<typename ValueType>
base_iterator<ValueType>::base_iterator(ValueType *ptr)
{
    this->ptr = ptr;
}

template<typename ValueType>
base_iterator<ValueType>::~base_iterator()
{
    this->ptr = nullptr;
}

template<typename ValueType>
base_iterator<ValueType>& base_iterator<ValueType>::operator =(const base_iterator<ValueType> &iter)
{
    if (this != &iter)
    {
        this->ptr = iter.ptr;
    }
    return *this;
}

template<typename ValueType>
base_iterator<ValueType>& base_iterator<ValueType>::operator ++()
{
    ++this->ptr;
    
    return *this;
}

template<typename ValueType>
base_iterator<ValueType> base_iterator<ValueType>::operator ++(int)
{
    base_iterator<ValueType> temp(*this);
    this->operator ++();
    
    return *this;
}

template<typename ValueType>
base_iterator<ValueType>& base_iterator<ValueType>::operator --()
{
    --this->ptr;
    
    return *this;
}

template<typename ValueType>
base_iterator<ValueType> base_iterator<ValueType>::operator --(int)
{
    base_iterator<ValueType> temp(*this);
    this->operator --();
    
    return *temp;
}


template<typename ValueType>
bool base_iterator<ValueType>::operator ==(const base_iterator<ValueType>& iter) const
{
    return this->ptr == iter.ptr;
}

template<typename ValueType>
bool base_iterator<ValueType>::operator !=(const base_iterator<ValueType>& iter) const
{
    return this->ptr != iter.ptr;
}

#endif /* base_iterator_math_h */
