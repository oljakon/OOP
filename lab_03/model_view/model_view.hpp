#ifndef MODEL_VIEW_HPP
#define MODEL_VIEW_HPP

#include "containers/vector/vector.hpp"
#include "objects/model.hpp"
#include "exceptions/model_view_exceptions.hpp"

class model_view {
    public:
        model_view() = default;
        model_view(model_view&) = delete;
        model_view(const model_view&) = delete;
        ~model_view() = default;

        void add_view(const Model& m) {
            this->models_collection.push_back(m);
        }

        void delete_view(size_t index) {
            if (index < this->models_collection.size()) {
                this->models_collection.erase(index);

            } else {
                throw model_view_out_of_range_exception();
            }
        }

        const Model& get_model(size_t index) const {
            if (index < this->models_collection.size()) {
                return this->models_collection[index];

            } else {
                throw model_view_out_of_range_exception();
            }
        }

    private:
        vector<Model> models_collection;
};

#endif // MODEL_VIEW_HPP
