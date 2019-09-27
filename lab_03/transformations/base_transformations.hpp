#ifndef TRANSFORMATIONS_HPP
#define TRANSFORMATIONS_HPP

#include "objects/scene_object.hpp"
#include "transformation_interface.hpp"
#include "containers/vector/vector.hpp"
#include "primitives/point3d.hpp"

class base_transformations {
    public:
        base_transformations() = default;
        base_transformations(base_transformations&) = delete;
        base_transformations(const base_transformations&) = delete;
        virtual ~base_transformations() = default;

        virtual void transform(scene_object*&) = 0;
};

#endif // TRANSFORMATIONS_HPP
