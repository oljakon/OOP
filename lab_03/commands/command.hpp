#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "controller/controller.hpp"
#include "transformations/dimensional_transformations.hpp"
#include "transformations/model_transformations.hpp"
#include "gui/drawer.hpp"

class command {
    public:
        command() = default;
        command(command&) = delete;
        command(const command&) = delete;
        ~command() = default;

        virtual void execute(controller*&) = 0;
};

namespace commands {

    class upload_view : public command {
        public:
            upload_view(const std::string& file_name) : file_name(file_name) {}
            upload_view(upload_view&) = delete;
            upload_view(const upload_view&) = delete;
            ~upload_view() = default;

            virtual void execute(controller*& c) override {
                uploader upldr(this->file_name);
                c->upload_view(upldr);
            }

        private:
            std::string file_name;
    };

    class delete_view : public command {
        public:
            delete_view(size_t view_index) : view_index(view_index) {}
            delete_view(delete_view&) = delete;
            delete_view(const delete_view&) = delete;
            ~delete_view() = default;

            virtual void execute(controller*& c) override {
                c->delete_view(this->view_index);
            }

        private:
            size_t view_index;
    };

    class add_model : public command {
        public:
            add_model(size_t view_index) : view_index(view_index) {}
            add_model(add_model&) = delete;
            add_model(const add_model&) = delete;
            ~add_model() = default;

            virtual void execute(controller*& c) override {
                c->add_model(this->view_index);
            }

        private:
            size_t view_index;
    };

    class remove_model : public command {
        public:
            remove_model(size_t model_index) : model_index(model_index) {}
            remove_model(remove_model&) = delete;
            remove_model(const remove_model&) = delete;
            ~remove_model() = default;

            virtual void execute(controller*& c) override {
                c->remove_model(this->model_index);
            }

        private:
            size_t model_index;
    };

    class add_camera : public command {
        public:
            add_camera() = default;
            add_camera(add_camera&) = delete;
            add_camera(const add_camera&) = delete;
            ~add_camera() = default;

            virtual void execute(controller*& c) override {
                c->add_camera();
            }
    };

    class remove_camera : public command {
        public:
            remove_camera(size_t camera_index) : camera_index(camera_index) {}
            remove_camera(remove_camera&) = delete;
            remove_camera(const remove_camera&) = delete;
            ~remove_camera() = default;

            virtual void execute(controller*& c) override {
                c->remove_camera(this->camera_index);
            }

        private:
            size_t camera_index;
    };

    class move : public command {
        public:
            move(const point3d<double>& point, ssize_t model_index)
                : point(point), model_index(model_index) {}
            move(move&) = delete;
            move(const move&) = delete;
            ~move() = default;

            virtual void execute(controller*& c) override {
                dimensional_transformations::move mv(this->point);
                model_transformations transformation(mv);
                c->transform_model(transformation, this->model_index);
            }

        private:
            point3d<double> point;
            ssize_t model_index;
    };

    class rotate_model_OX : public command {
        public:
            rotate_model_OX(double angle, ssize_t model_index)
                : angle(angle), model_index(model_index) {}
            rotate_model_OX(rotate_model_OX&) = delete;
            rotate_model_OX(const rotate_model_OX&) = delete;
            ~rotate_model_OX() = default;

            virtual void execute(controller*& c) override {
                dimensional_transformations::rotation_OX rot(this->angle);
                model_transformations transformation(rot);
                c->transform_model(transformation, this->model_index);
            }

        private:
            double angle;
            ssize_t model_index;
    };

    class rotate_model_OY : public command {
        public:
            rotate_model_OY(double angle, ssize_t model_index)
                : angle(angle), model_index(model_index) {}
            rotate_model_OY(rotate_model_OY&) = delete;
            rotate_model_OY(const rotate_model_OY&) = delete;
            ~rotate_model_OY() = default;

            virtual void execute(controller*& c) override {
                dimensional_transformations::rotation_OY rot(this->angle);
                model_transformations transformation(rot);
                c->transform_model(transformation, this->model_index);
            }

        private:
            double angle;
            ssize_t model_index;
    };

    class rotate_model_OZ : public command {
        public:
            rotate_model_OZ(double angle, ssize_t model_index)
                : angle(angle), model_index(model_index) {}
            rotate_model_OZ(rotate_model_OZ&) = delete;
            rotate_model_OZ(const rotate_model_OZ&) = delete;
            ~rotate_model_OZ() = default;

            virtual void execute(controller*& c) override {
                dimensional_transformations::rotation_OZ rot(this->angle);
                model_transformations transformation(rot);
                c->transform_model(transformation, this->model_index);
            }

        private:
            double angle;
            ssize_t model_index;
    };

    class scale : public command {
        public:
            scale(double scale_factor, ssize_t model_index)
                : scale_factor(scale_factor), model_index(model_index) {}
            scale(scale&) = delete;
            scale(const scale&) = delete;
            ~scale() = default;

            virtual void execute(controller*& c) override {
                dimensional_transformations::scale scl(this->scale_factor);
                model_transformations transformation(scl);
                c->transform_model(transformation, this->model_index);
            }

        private:
            double scale_factor;
            ssize_t model_index;
    };

    class draw : public command {
        public:
            draw(drawer& dr, ssize_t camera_index)
                : dr(dr), camera_index(camera_index) {}
            draw(draw&) = delete;
            draw(const draw&) = delete;
            ~draw() = default;

            virtual void execute(controller*& c) override {
                c->draw_scene(this->dr, this->camera_index);
            }

        private:
            drawer dr;
            ssize_t camera_index;
    };

    class yaw : public command {
        public:
            yaw(double angle, size_t index) : angle(angle), index(index) {}
            yaw(yaw&) = delete;
            yaw(const yaw&) = delete;
            ~yaw() = default;

            virtual void execute(controller*& c) {
                camera_dimensional_transformations::yaw comm(this->angle);
                c->transform_camera(comm, this->index);
            }

        private:
            double angle;
            size_t index;
    };

    class pitch : public command {
        public:
            pitch(double angle, size_t index) : angle(angle), index(index) {}
            pitch(pitch&) = delete;
            pitch(const pitch&) = delete;
            ~pitch() = default;

            virtual void execute(controller*& c) {
                camera_dimensional_transformations::pitch comm(this->angle);
                c->transform_camera(comm, this->index);
            }

        private:
            double angle;
            size_t index;
    };

    class roll : public command {
        public:
            roll(double angle, size_t index) : angle(angle), index(index) {}
            roll(roll&) = delete;
            roll(const roll&) = delete;
            ~roll() = default;

            virtual void execute(controller*& c) {
                camera_dimensional_transformations::roll comm(this->angle);
                c->transform_camera(comm, this->index);
            }

        private:
            double angle;
            size_t index;
    };
}

#endif // COMMAND_HPP
