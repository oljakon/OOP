#ifndef DIMENSIONAL_TRANSFORMATIONS_HPP
#define DIMENSIONAL_TRANSFORMATIONS_HPP

#include <cmath>

#include "transformation_interface.hpp"
#include "primitives/point3d.hpp"

namespace dimensional_transformations {

    class rotation_OX : public transformation_interface {
        public:
            rotation_OX(double);
            rotation_OX(rotation_OX&) = delete;
            rotation_OX(const rotation_OX&) = delete;
            ~rotation_OX() = default;
    };

    class rotation_OY : public transformation_interface {
        public:
            rotation_OY(double);
            rotation_OY(rotation_OY&) = delete;
            rotation_OY(const rotation_OY&) = delete;
            ~rotation_OY() = default;
    };

    class rotation_OZ : public transformation_interface {
        public:
            rotation_OZ(double);
            rotation_OZ(rotation_OZ&) = delete;
            rotation_OZ(const rotation_OZ&) = delete;
            ~rotation_OZ() = default;
    };

    class rotation : public transformation_interface {
        public:
            rotation(const point3d<double>&, double);
            rotation(rotation&) = delete;
            rotation(const rotation&) = delete;
            ~rotation() = default;
    };

    class move : public transformation_interface {
        public:
            move(const point3d<double>&);
            move(move&) = delete;
            move(const move&) = delete;
            ~move() = default;
    };

    class scale : public transformation_interface {
        public:
            scale(double);
            scale(scale&) = delete;
            scale(const scale&) = delete;
            ~scale() = default;
    };
}

#endif // DIMENSIONAL_TRANSFORMATIONS_HPP
