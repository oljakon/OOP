#ifndef DRAW_MANAGER_HPP
#define DRAW_MANAGER_HPP

#include <QGraphicsScene>

#include "scene/scene.hpp"
#include "primitives/matrix4x4.hpp"
#include "gui/drawer.hpp"

class draw_manager {
    public:
        draw_manager() = default;
        draw_manager(draw_manager&) = delete;
        draw_manager(const draw_manager&) = delete;
        ~draw_manager() = default;

        void draw(scene& sc, base_drawer& dr, camera* obj) {
            for (vector<scene_object*>::iterator iter = sc.object.scene_objects.begin();
                 iter != sc.object.scene_objects.end(); ++iter) {

                if ((*iter)->visible()) {
                    Model* m = reinterpret_cast<Model*>(*iter);
                    matrix4x4<double> mtx = obj->get_view_matrix();

                    for (size_t i = 0; i < m->lines.size(); ++i) {
                        point3d<double> p1 = mtx * m->lines.at(i).get_first();
                        point3d<double> p2 = mtx * m->lines.at(i).get_second();
                        dr(p1, p2);
                    }
                }
            }
        }
};

#endif // DRAW_MANAGER_HPP
