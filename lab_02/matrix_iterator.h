#ifndef matrix_iterator_h
#define matrix_iterator_h

#include "base_iterator.h"

using namespace iterator_core;

#include "base_iterator.h"
using namespace iterator_core;

template<typename ValueType>
class matrix_iterator : public base_iterator<ValueType>
{
public:
    matrix_iterator(const matrix_iterator<ValueType>&);
    ValueType &operator *();
    ValueType *operator ->();
    const ValueType &operator *() const;
    const ValueType *operator ->() const;
    
    matrix_iterator(ValueType *);
private:
};

#endif /* matrix_iterator_h */
