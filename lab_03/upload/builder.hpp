#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <fstream>
#include <cstring>
#include <functional>

#include "objects/model.hpp"
#include "base_builder.hpp"

class model_builder : public base_builder
{
public:
    model_builder();
    ~model_builder() = default;

    std::shared_ptr<Model> get_model() const;
    void build_model();
    void build_node(const double x, const double y, const double z);
    void build_edge(const size_t src, const size_t purp);

protected:
    bool is_built() const;

protected:
    std::shared_ptr<Model> model;
};




class Builder : public base_builder
{
protected:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<std::shared_ptr<PointConnection>> edges;

    size_t point_count = 0;

    friend class Builder;
public:
    Builder();

    void add_edge(Point *p1, Point *p2);
    std::vector<std::vector<double>> get_edges();
    std::vector<std::vector<double>> get_points_coord();
    std::vector<std::shared_ptr<Point>> &get_points();

    void set_points(std::vector<std::vector<double>> points);
    void reset_points();
};
#endif // BUILDER_HPP
