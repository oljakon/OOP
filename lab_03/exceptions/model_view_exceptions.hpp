#ifndef MODEL_VIEW_EXCEPTIONS_HPP
#define MODEL_VIEW_EXCEPTIONS_HPP

#include "base_exception.hpp"

class base_model_view_exception : public base_exception {
    public:
        explicit base_model_view_exception() = default;

        explicit base_model_view_exception(const char* message)
            : base_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "model_view::(base exception)!" : message.c_str();
        }
};

class model_view_out_of_range_exception : public base_model_view_exception {
    public:
        explicit model_view_out_of_range_exception() = default;

        explicit model_view_out_of_range_exception(const char* message)
            : base_model_view_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "model_view::(out of range)!" : message.c_str();
        }
};

#endif // MODEL_VIEW_EXCEPTIONS_HPP
