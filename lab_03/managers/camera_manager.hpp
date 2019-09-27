#ifndef CAMERA_MANAGER_HPP
#define CAMERA_MANAGER_HPP

#include "scene/scene.hpp"
#include "transformations/command_interface.hpp"

class camera_manager {
    public:
        camera_manager() = default;
        camera_manager(camera_manager&) = delete;
        camera_manager(const camera_manager&) = delete;
        ~camera_manager() = default;

        void transform(scene& sc, command_interface& comm, size_t ind) {
            camera* c = reinterpret_cast<camera*>(sc.get_camera(ind));
            comm.execute(c);
        }
};

#endif // CAMERA_MANAGER_HPP
