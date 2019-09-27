#ifndef SCENE_EXCEPTIONS_HPP
#define SCENE_EXCEPTIONS_HPP

#include "base_exception.hpp"

class base_scene_exception : public base_exception {
    public:
        explicit base_scene_exception() = default;

        explicit base_scene_exception(const char* message)
            : base_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "scene::(base exception)!" : message.c_str();
        }
};

class scene_out_of_range_exception : public base_scene_exception {
    public:
        explicit scene_out_of_range_exception() = default;

        explicit scene_out_of_range_exception(const char* message)
            : base_scene_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "scene::(out of range)!" : message.c_str();
        }
};

#endif // SCENE_EXCEPTIONS_HPP
