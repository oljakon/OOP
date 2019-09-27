#include "controller.hpp"

controller* controller::instance() {
    return new controller();
}

void controller::upload_view(base_uploader& upldr) {
    this->__model_view.add_view(this->__upload_manager.upload_model(upldr));
}

void controller::delete_view(size_t index) {
    this->__model_view.delete_view(index);
}

void controller::add_model(size_t index) {
    this->__scene.add_model(new Model(this->__model_view.get_model(index)));
}

void controller::remove_model(size_t index) {
    this->__scene.remove_model(index);
}

void controller::add_camera() {
    this->__scene.add_camera(new camera());
}

void controller::remove_camera(size_t index) {
    this->__scene.remove_camera(index);
}

void controller::transform_model(base_transformations& transformation, ssize_t index) {
    this->__model_manager.transform(this->__scene, transformation, index);
}

void controller::transform_camera(command_interface& comm, size_t index) {
    this->__camera_manager.transform(this->__scene, comm, index);
}

void controller::draw_scene(base_drawer& dr, ssize_t camera_index) {
    this->__draw_manager.draw(this->__scene, dr, reinterpret_cast<camera*>(this->__scene.get_camera(camera_index)));
}
