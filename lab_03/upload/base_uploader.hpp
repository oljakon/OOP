#ifndef BASE_UPLOADER_HPP
#define BASE_UPLOADER_HPP

#include "objects/model.hpp"
#include "base_builder.hpp"

class base_uploader
{
public:
    base_uploader() = default;
    virtual ~base_uploader() = default;

    virtual std::shared_ptr<Model> upload_model(base_builder& bld) = 0;
    virtual void open() = 0;
    virtual void close() = 0;
};

#endif // BASE_UPLOADER_HPP
