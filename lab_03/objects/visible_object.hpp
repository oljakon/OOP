#ifndef VISIBLE_OBJECT_HPP
#define VISIBLE_OBJECT_HPP

#include "scene_object.hpp"

class visible_object : public scene_object {
    public:
        explicit visible_object() = default;
        visible_object(visible_object&) = delete;
        visible_object(const visible_object&) = delete;
        virtual ~visible_object() = default;

        bool visible() override {
            return true;
        }
};

#endif // VISIBLE_OBJECT_HPP
