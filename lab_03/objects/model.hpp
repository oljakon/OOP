#ifndef MODEL_HPP
#define MODEL_HPP

#include <string>
#include <vector>
#include "edge.h"
#include "node.h"
#include "visible_object.hpp"
#include "containers/vector/vector.hpp"
#include "containers/pair/pair.hpp"
#include "primitives/point3d.hpp"

class Model : public visible_object {
public:
    Model() = default;
    Model(const std::vector<Node> nodes, const std::vector<Edge> edges);
    Model(const Model& model);
    Model(Model&& model);
    ~Model() = default;

    Model& operator=(const Model& model);
    Model& operator=(Model&& model);

    const std::vector<Node> getNodes() const;
    const std::vector<Edge> getEdges() const;

    void addNode(const Node& node);
    void addEdge(const Edge& edge);

    void shift(const double x, const double y, const double z);
    void scale(const double x, const double y, const double z);
    void rotate(const double x, const double y, const double z);

    std::string name;
    vector<pair<point3d<double>, point3d<double>>> lines;

private:
    std::vector<Node> nodes;
    std::vector<Edge> edges;

};

#endif // MODEL_HPP
