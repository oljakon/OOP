#include "dimensional_transformations.hpp"

dimensional_transformations::rotation_OX::rotation_OX(double x_angle)
    : transformation_interface() {
    this->reset_matrix();
    (*this)[1][1] = cos(x_angle);
    (*this)[1][2] = sin(x_angle);
    (*this)[2][1] = -sin(x_angle);
    (*this)[2][2] = cos(x_angle);
}

dimensional_transformations::rotation_OY::rotation_OY(double y_angle)
    : transformation_interface() {
    this->reset_matrix();
    (*this)[0][0] = cos(y_angle);
    (*this)[0][2] = -sin(y_angle);
    (*this)[2][0] = sin(y_angle);
    (*this)[2][2] = cos(y_angle);
}

dimensional_transformations::rotation_OZ::rotation_OZ(double y_angle)
    : transformation_interface() {
    this->reset_matrix();
    (*this)[0][0] = cos(y_angle);
    (*this)[0][1] = sin(y_angle);
    (*this)[1][0] = -sin(y_angle);
    (*this)[1][1] = cos(y_angle);
}

dimensional_transformations::rotation::rotation(const point3d<double>& offset, double angle)
    : transformation_interface() {
    this->reset_matrix();
    (*this)[0][0] = cos(angle) + (1 - cos(angle)) * offset.get_x() * offset.get_x();
    (*this)[1][0] = (1 - cos(angle)) * offset.get_x() * offset.get_y() - sin(angle) * offset.get_z();
    (*this)[2][0] = (1 - cos(angle)) * offset.get_x() * offset.get_z() + sin(angle) * offset.get_y();
    (*this)[0][1] = (1 - cos(angle)) * offset.get_y() * offset.get_x() + sin(angle) * offset.get_z();
    (*this)[1][1] = cos(angle) + (1 - cos(angle)) * offset.get_y() * offset.get_y();
    (*this)[2][1] = (1 - cos(angle)) * offset.get_y() * offset.get_z() - sin(angle) * offset.get_x();
    (*this)[0][2] = (1 - cos(angle)) * offset.get_z() * offset.get_x() - sin(angle) * offset.get_y();
    (*this)[1][2] = (1 - cos(angle)) * offset.get_z() * offset.get_y() + sin(angle) * offset.get_x();
    (*this)[2][2] = cos(angle) + (1 - cos(angle)) * offset.get_z() * offset.get_z();
}

dimensional_transformations::move::move(const point3d<double>& offset)
    : transformation_interface() {
    this->reset_matrix();
    (*this)[0][3] = offset.get_x();
    (*this)[1][3] = offset.get_y();
    (*this)[2][3] = offset.get_z();
}

dimensional_transformations::scale::scale(double scale_factor) {
    this->reset_matrix();
    (*this)[0][0] = scale_factor;
    (*this)[1][1] = scale_factor;
    (*this)[2][2] = scale_factor;
}
