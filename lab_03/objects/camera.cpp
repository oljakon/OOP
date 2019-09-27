#include "camera.hpp"
#include "transformations/dimensional_transformations.hpp"

camera::camera() {
    this->right[0] = this->right[3] = 1;
    this->up[1] = this->up[3] = 1;
    this->look[2] = this->look[3] = 1;
}

camera::camera(const point3d<double>& pos, const point3d<double>& target, double yaw, double pitch, double roll) {
    this->pos = pos.to_vector4d();
    this->target = target.to_vector4d();
    this->pitch(pitch);
    this->yaw(yaw);
    this->roll(roll);
}

void camera::set_position(const point3d<double>& pos) {
    this->pos = pos.to_vector4d();
}

void camera::set_target(const point3d<double>& target) {
    this->target = target.to_vector4d();
}

void camera::rotate_up_down_sphere(double angle) {
    point3d<double> point(this->up[0], this->up[1], this->up[2]);
    matrix4x4<double> transform = dimensional_transformations::rotation(point, angle);
    this->right = transform * this->right;
    this->look = transform * this->look;
    point = point3d<double>(this->target[0], this->target[1], this->target[2]);
    matrix4x4<double> move = dimensional_transformations::move(point);
    this->pos = this->pos * (move * -1.) * transform * move;
}

void camera::rotate_right_left_sphere(double angle) {
    point3d<double> point(this->right[0], this->right[1], this->right[2]);
    matrix4x4<double> transform = dimensional_transformations::rotation(point, angle);
    this->up = transform * this->up;
    this->look = transform * this->look;
    point = point3d<double>(this->target[0], this->target[1], this->target[2]);
    matrix4x4<double> move = dimensional_transformations::move(point);
    this->pos = this->pos * (move * -1.) * transform * move;
}

void camera::yaw(double angle) {
    point3d<double> point(this->up[0], this->up[1], this->up[2]);
    matrix4x4<double> transform = dimensional_transformations::rotation(point, angle);
    this->right = transform * this->right;
    this->look = transform * this->look;
}

void camera::pitch(double angle) {
    point3d<double> point(this->right[0], this->right[1], this->right[2]);
    matrix4x4<double> transform = dimensional_transformations::rotation(point, angle);
    this->up = transform * this->up;
    this->look = transform * this->look;
}

void camera::roll(double angle) {
    point3d<double> point(this->look[0], this->look[1], this->look[2]);
    matrix4x4<double> transform = dimensional_transformations::rotation(point, angle);
    this->right = transform * this->right;
    this->up = transform * this->up;
}

matrix4x4<double> camera::get_view_matrix() {
    this->look.normalize();

    this->up = vector4d<double>::cross(this->look, this->right);
    this->up.normalize();

    this->right = vector4d<double>::cross(this->up, this->look);
    this->right.normalize();

    const double x = -vector4d<double>::scalar_product(this->right, this->pos);
    const double y = -vector4d<double>::scalar_product(this->up, this->pos);
    const double z = -vector4d<double>::scalar_product(this->look, this->pos);

    matrix4x4<double> tmp = {
        this->right[0], this->up[0], this->look[0], 0,
        this->right[1], this->up[1], this->look[1], 0,
        this->right[2], this->up[2], this->look[2], 0,
        x, y, z, 1
    };

    return tmp;
}
