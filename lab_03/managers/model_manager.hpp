#ifndef MODEL_MANAGER_HPP
#define MODEL_MANAGER_HPP

#include "scene/scene.hpp"
#include "transformations/base_transformations.hpp"

class model_manager {
    public:
        model_manager() = default;
        model_manager(model_manager&) = delete;
        model_manager(const model_manager&) = delete;
        ~model_manager() = default;

        void transform(scene& sc, base_transformations& tr, ssize_t ind) {
            if (ind == -1) {
                sc.transform(tr);

            } else {
                tr.transform(sc.get_model(ind));
            }
        }
};

#endif // MODEL_MANAGER_HPP
