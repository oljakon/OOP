#ifndef COMMAND_INTERFACE_HPP
#define COMMAND_INTERFACE_HPP

#include "objects/camera.hpp"

class command_interface {
    public:
        command_interface() = default;
        command_interface(command_interface&) = delete;
        command_interface(const command_interface&) = delete;
        ~command_interface() = default;

        virtual void execute(camera*&) = 0;
};

namespace camera_dimensional_transformations {

    class yaw : public command_interface {
        public:
            yaw(double angle) : angle(angle) {}
            yaw(yaw&) = delete;
            yaw(const yaw&) = delete;
            ~yaw() = default;

            void execute(camera*& c) override {
                c->yaw(angle);
            }

        private:
            double angle;
    };

    class pitch : public command_interface {
        public:
            pitch(double angle) : angle(angle) {}
            pitch(pitch&) = delete;
            pitch(const pitch&) = delete;
            ~pitch() = default;

            void execute(camera*& c) override {
                c->pitch(angle);
            }

        private:
            double angle;
    };

    class roll : public command_interface {
        public:
            roll(double angle) : angle(angle) {}
            roll(roll&) = delete;
            roll(const roll&) = delete;
            ~roll() = default;

            void execute(camera*& c) override {
                c->roll(angle);
            }

        private:
            double angle;
    };
}

#endif // COMMAND_INTERFACE_HPP
