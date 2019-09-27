#ifndef BASE_BUILDER_HPP
#define BASE_BUILDER_HPP

#include "objects/model.hpp"

class base_builder
{
public:
    base_builder() = default;
    virtual ~base_builder() = default;

    virtual std::shared_ptr<Model> get_model() const = 0;
    virtual void build_model() = 0;
    virtual void build_node(const double x, const double y, const double z) = 0;
    virtual void build_edge(const size_t src, const size_t purp) = 0;
};

#endif // BASE_BUILDER_HPP
