#include "transformation_interface.hpp"

transformation_interface::transformation_interface()
    : matrix4x4<double>() {
    this->reset_matrix();
}

void transformation_interface::reset_matrix() {
    *(reinterpret_cast<matrix4x4<double>*>(this)) = {
        1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
}
