#ifndef CABIN_H
#define CABIN_H

#include <QObject>

#include "doors.h"
#include "times.h"

class Cabin : public QObject{
    Q_OBJECT
    enum cabin_states
    {
        MOVING,
        GOT_TARGET,
        FREE
    };

public:
    explicit Cabin(QObject *parent = 0);

signals:
    void passed_floor(int floor, motion new_motion);
    void floor_achieved(int floor, motion new_motion);

public slots:
    void change_to_moving();
    void change_to_free();
    void change_to_got_target(int floor);

private:
    int current_floor = 0;
    int needed_floor;
    motion current_motion;
    cabin_states current_state;
    Doors doors;
    QTimer timer_for_motion;

signals:
    void arrived_at_floor();
    void moving();
};

#endif // CABIN_H
