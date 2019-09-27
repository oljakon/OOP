#include "elevator.h"

Elevator::Elevator(QObject *parent) : QObject(parent)
{
    QObject::connect(&elevator_cabin, SIGNAL(passed_floor(int, motion)),
                     &control, SLOT(passed_current_floor(int, motion)));
    QObject::connect(&elevator_cabin, SIGNAL(floor_achieved(int, motion)),
                     &control, SLOT(passed_target_floor(int,motion)));
    QObject::connect(&control, SIGNAL(new_target(int)),
                     &elevator_cabin, SLOT(change_to_got_target(int)));
}

QWidget *Elevator::GetWidget()
{
    return &control;
}
