#ifndef UPLOADER_HPP
#define UPLOADER_HPP

#include <fstream>
#include <cstring>
#include <functional>

#include "exceptions/upload_exceptions.hpp"
#include "containers/vector/vector.hpp"
#include "containers/pair/pair.hpp"
#include "objects/model.hpp"
#include "3dparty/jsmn.h"
#include "base_uploader.hpp"
#include "base_builder.hpp"

class model_uploader : public base_uploader
{
public:
    explicit model_uploader(const std::string& fileName);
    ~model_uploader() = default;

    std::shared_ptr<Model> upload_model(base_builder &bld) override;

    void open() override;
    void close() override;

private:
    std::string fileName;
    std::ifstream file;
};

#endif // UPLOADER_HPP
