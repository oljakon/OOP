#include "doors.h"

Doors::Doors()
{
    current_state = CLOSE;

    QObject::connect(this, SIGNAL(doors_opening()), this, SLOT(change_to_opening()));
    QObject::connect(&timer_for_open, SIGNAL(timeout()), this, SLOT(change_to_pen()));
    QObject::connect(&timer_for_close, SIGNAL(timeout()), this, SLOT(change_to_cllose()));
    QObject::connect(&timer_for_wait, SIGNAL(timeout()), this, SLOT(change_to_cllosing()));
}

void Doors::change_to_pen()
{
    if (current_state == OPENING)
    {
        current_state = OPEN;
        qDebug() << "Doors opened";
        timer_for_wait.start(TIME_DOOR_WAIT);
    }
}

void Doors::change_to_opening()
{
    if (current_state == CLOSE)
    {
        current_state = OPENING;
        qDebug() << "Doors are opening";
        timer_for_open.start(TIME_DOOR);
    }

    if (current_state == CLOSING)
    {
        current_state = OPENING;
        qDebug() << "Doors are opening";
        int time = timer_for_close.remainingTime();
        timer_for_close.stop();
        timer_for_open.start(TIME_DOOR - time);
    }
}

void Doors::change_to_cllose()
{
    if (current_state == CLOSING)
    {
        current_state = CLOSE;
        qDebug() << "Doors closed";
        emit doors_closed();
    }
}

void Doors::change_to_cllosing()
{
    if (current_state == OPEN)
    {
        current_state = CLOSING;
        qDebug() << "Doors are closing";
        timer_for_close.start(TIME_DOOR);
    }
}
