#include "base_matrix.h"

using namespace matrix_core;

base_matrix::base_matrix()
: elements_count(0){}

base_matrix::base_matrix(size_t count)
: elements_count(count){}

base_matrix::~base_matrix()
{
    this->elements_count = 0;
}

size_t base_matrix::size() const
{
    return elements_count;
}

bool base_matrix::is_empty() const
{
    return elements_count == 0;
}
