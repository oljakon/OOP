#include "scene.hpp"

void scene::transform(base_transformations& transformation) {
    this->object.transform(transformation);
}

void scene::add_model(scene_object* object) {
    this->object.add_model(object);
}

void scene::remove_model(size_t index) {
    this->object.remove_model(index);
}

void scene::add_camera(scene_object* object) {
    this->object.add_camera(object);
}

void scene::remove_camera(size_t index) {
    this->object.remove_camera(index);
}

scene_object*& scene::get_model(size_t index) {
    return this->object.get_model(index);
}

scene_object*& scene::get_camera(size_t index) {
    return this->object.get_camera(index);
}
