#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "invisible_object.hpp"
#include "primitives/vector4d.hpp"
#include "primitives/point3d.hpp"
#include "primitives/matrix4x4.hpp"

class camera : public invisible_object {
    public:
        camera();
        camera(const point3d<double>&, const point3d<double>&, double, double, double);
        ~camera() = default;

        void set_position(const point3d<double>&);
        void set_target(const point3d<double>&);

        matrix4x4<double> get_view_matrix();

        void rotate_up_down_sphere(double);
        void rotate_right_left_sphere(double);

        void yaw(double);
        void pitch(double);
        void roll(double);

    private:
        vector4d<double> look;
        vector4d<double> up;
        vector4d<double> right;

        vector4d<double> pos;
        vector4d<double> target;
};

#endif // CAMERA_HPP
