#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include "times.h"
#include "controller.h"
#include "cabin.h"

class Elevator : public QObject
{
    Q_OBJECT
public:
    explicit Elevator(QObject *parent = 0);
    QWidget* GetWidget();

signals:

public slots:

private:
    Controller control;
    Cabin elevator_cabin;
};

#endif // LIFT_H
