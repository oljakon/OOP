#ifndef DOORS_H
#define DOORS_H

#include <QObject>

#include "times.h"

class Doors : public QObject
{
    Q_OBJECT
    enum doors_states
    {
        OPEN,
        OPENING,
        CLOSE,
        CLOSING
    };

public:
    Doors();

signals:
    void doors_closed();
    void doors_opening();

public slots:
    void change_to_pen();
    void change_to_cllose();

private slots:
    void change_to_opening();
    void change_to_cllosing();

private:
    doors_states current_state;

    QTimer timer_for_open;
    QTimer timer_for_close;
    QTimer timer_for_wait;
};

#endif // DOORS_H
