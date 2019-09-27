#ifndef SCENE_HPP
#define SCENE_HPP

#include "objects/composite_object.hpp"

class scene {
    public:
        scene() = default;
        ~scene() = default;

        void transform(base_transformations&);

        void add_model(scene_object*);
        void remove_model(size_t);

        void add_camera(scene_object*);
        void remove_camera(size_t);

        scene_object*& get_model(size_t);
        scene_object*& get_camera(size_t);

        friend class model_manager;
        friend class draw_manager;
        friend class camera_manager;

    private:
        composite_object object;
};

#endif // SCENE_HPP
