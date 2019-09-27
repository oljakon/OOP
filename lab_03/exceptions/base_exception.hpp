#ifndef BASE_EXCEPTION_HPP
#define BASE_EXCEPTION_HPP

#include <exception>
#include <string>

class base_exception : public std::exception {
    protected:
        std::string message;

    public:
        explicit base_exception() = default;

        explicit base_exception(const char* message)
            : message(message) {}

        virtual const char* what() const noexcept {
            return "base_exception";
        }
};

#endif // BASE_EXCEPTION_HPP
