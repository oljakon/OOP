#ifndef DRAWER_HPP
#define DRAWER_HPP

#include <QGraphicsScene>

#include "primitives/point3d.hpp"

class base_drawer {
    public:
        base_drawer() = default;
        base_drawer(base_drawer&) = delete;
        base_drawer(const base_drawer&) = delete;
        virtual ~base_drawer() = default;

        virtual void operator()(const point3d<double>&, const point3d<double>&) = 0;
};

class drawer : public base_drawer {
    public:
        drawer(QGraphicsScene*& graphics_scene) : base_drawer(), graphics_scene(graphics_scene) {}

        drawer(const drawer& other) : base_drawer() {
            this->graphics_scene = other.graphics_scene;
        }

        ~drawer() {
            this->graphics_scene = nullptr;
        }

        void operator()(const point3d<double>& p1, const point3d<double>& p2) {
            this->graphics_scene->addLine(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y());
        }

    private:
        QGraphicsScene* graphics_scene;
};

#endif // DRAWER_HPP
