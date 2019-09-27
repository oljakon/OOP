#ifndef base_iterator_h
#define base_iterator_h

#include <stdio.h>

using namespace std;

namespace iterator_core
{
    template<typename ValueType>
    class base_iterator
    {
    public:
        base_iterator();
        base_iterator(const base_iterator<ValueType>&);
        base_iterator(ValueType*);
        virtual ~base_iterator();
        base_iterator<ValueType>& operator =(const base_iterator<ValueType>&);
        base_iterator<ValueType>& operator ++();
        base_iterator<ValueType> operator ++(int);
        base_iterator<ValueType>& operator --();
        base_iterator<ValueType> operator --(int);
        operator bool() const;
        bool operator ==(const base_iterator<ValueType>&) const;
        bool operator !=(const base_iterator<ValueType>&) const;
    protected:
        unsigned int count;
        int index;
        ValueType *ptr;
    };
}

#include "base_iterator_math.h"

#endif /* base_iterator_h */
