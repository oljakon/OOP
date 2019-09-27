#include "builder.hpp"
#include "objects/node.h"
#include "objects/edge.h"
#include "exceptions/upload_exceptions.hpp"

model_builder::model_builder() : model(nullptr) {}

std::shared_ptr<Model> model_builder::get_model() const
{
    return model;
}

void model_builder::build_model()
{
    model = std::make_shared<Model>();
}

void model_builder::build_node(const double x, const double y, const double z)
{
    if (!is_built())
        throw NoBuildingObjectException();

    Node node(x, y, z);
    this->model->addNode(node);
}

void model_builder::build_edge(const size_t src, const size_t purp)
{
    if (!is_built())
        throw NoBuildingObjectException();

    Edge edge(src, purp);
    this->model->addEdge(edge);
}

bool model_builder::is_built() const
{
    return (this->model == nullptr) ? false : true;
}
