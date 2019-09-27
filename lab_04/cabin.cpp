#include "cabin.h"

Cabin::Cabin(QObject *parent)
{
    current_state = FREE;
    current_floor = 1;
    needed_floor = 0;

    current_motion = STOPPED;
    QObject::connect(&doors, SIGNAL(doors_closed()), this, SLOT(change_to_moving()));
    QObject::connect(&timer_for_motion, SIGNAL(timeout()), this, SLOT(change_to_moving()));
    QObject::connect(this, SIGNAL(arrived_at_floor()), this, SLOT(change_to_free()));
    QObject::connect(this, SIGNAL(moving()), this, SLOT(change_to_moving()));
}

void Cabin::change_to_moving()
{
    if (current_state == MOVING || current_state == GOT_TARGET)
    {
        current_state = MOVING;
        qDebug() << "Elevator moves. Current floor: " << current_floor;
        if (current_floor == needed_floor)
        {
            emit arrived_at_floor();
        } else {
            timer_for_motion.start(TIME_MOVING_FLOOR);
            emit passed_floor(current_floor, current_motion);
            if (current_floor < needed_floor)
            {
                current_motion = UP;
                current_floor += 1;
            } else {
                current_motion = DOWN;
                current_floor -= 1;
            }
        }
    }
}

void Cabin::change_to_free()
{
    current_state = FREE;
    timer_for_motion.stop();
    emit floor_achieved(current_floor, current_motion);
    emit doors.doors_opening();
}

void Cabin::change_to_got_target(int floor)
{
    current_state = GOT_TARGET;
    needed_floor= floor;

    if (current_floor == needed_floor)
        emit arrived_at_floor();
    else
    {
        if (current_floor < needed_floor)
            current_motion = UP;
        else
            current_motion = DOWN;

        emit moving();
    }
}



