#ifndef UPLOAD_EXCEPTIONS_HPP
#define UPLOAD_EXCEPTIONS_HPP

#include "base_exception.hpp"

class base_stream_exception : public base_exception {
    public:
        explicit base_stream_exception() = default;

        explicit base_stream_exception(const char* message)
            : base_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(base stream exception)!" : message.c_str();
        }
};

class OpenFileException : public base_stream_exception {
    public:
        explicit OpenFileException() = default;

        explicit OpenFileException(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(opening stream exception)!" : message.c_str();
        }
};

class ReadFileException : public base_stream_exception {
    public:
        explicit ReadFileException() = default;

        explicit ReadFileException(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(reading stream exception)!" : message.c_str();
        }
};

class CloseFileException : public base_stream_exception {
    public:
        explicit CloseFileException() = default;

        explicit CloseFileException(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(closing stream exception)!" : message.c_str();
        }
};

class NoBuildingObjectException : public base_stream_exception {
    public:
        explicit NoBuildingObjectException() = default;

        explicit NoBuildingObjectException(const char* message)
            : base_stream_exception(message) {}

        virtual const char* what() const noexcept {
            return message.empty() ? "uploader::(no building object exception)!" : message.c_str();
        }
};


#endif // UPLOAD_EXCEPTIONS_HPP
