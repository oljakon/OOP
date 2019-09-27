#ifndef UPLOAD_MANAGER_HPP
#define UPLOAD_MANAGER_HPP

#include "upload/uploader.hpp"

class upload_manager
{
public:
    upload_manager() = default;
    ~upload_manager() = default;

    std::shared_ptr<Model> upload_model(base_uploader& upld, base_builder& bld)
    {
        upld.open();
        std::shared_ptr<Model> model(upld.upload_model(bld));
        upld.close();

        return model;
    }
};

#endif // UPLOAD_MANAGER_HPP
