#ifndef const_iterator_h
#define const_iterator_h

#include "base_iterator.h"

using namespace iterator_core;

template <typename ValueType>
class const_iterator : public base_iterator<ValueType>
{
public:
    const_iterator(const const_iterator<ValueType>&);
    const ValueType& operator *() const;
    const ValueType* operator ->() const;
    const_iterator(ValueType*);
};

#endif /* const_iterator_h */
