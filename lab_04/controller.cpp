#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout;
    this->setLayout(layout);
    for (int i = FLOOR_NUMBERS; i >= 0; i--)
    {
        buttons[i] = new Buttons;
        layout->addWidget(dynamic_cast<QPushButton*>(buttons[i]));
        buttons[i]->setText(QString::number(i));
        buttons[i]->set_floor(i);
        needed_floors[i] = false;
        QObject::connect(buttons[i], SIGNAL(input_floor(int)), this, SLOT(target_new_floor(int)));
    }
}

Controller::~Controller()
{
    for (int i = 1; i < FLOOR_NUMBERS; i++)
        delete buttons[i];

    delete layout;
}

void Controller::passed_current_floor(int floor, motion new_motion)
{
    current_floor = floor;
    current_motion = new_motion;
}

void Controller::passed_target_floor(int floor, motion new_motion)
{
    if (current_state == BUSY)
    {
        qDebug() << "Stoped on floor:" << floor;
        current_floor = floor;
        current_motion = new_motion;
        needed_floors[floor] = false;
        emit buttons[floor]->reset_button();
        if (get_new_target_floor(floor))
            emit new_target(floor);
        else
            current_state = NOTHING;
    }
}

void Controller::target_new_floor(int floor)
{
    current_state = BUSY;
    needed_floors[floor] = true;
    get_new_target_floor(floor);
    emit new_target(floor);
}

bool Controller::get_new_target_floor(int &new_floor)
{
    int step = current_motion == 0 ? -1 : current_motion;
    for (int i = current_floor; i < FLOOR_NUMBERS && i >= 0; i += step)
    {
        if (needed_floors[i])
        {
            new_floor = i;
            return true;
        }
    }

    step *= -1;
    for (int i = current_floor; i < FLOOR_NUMBERS && i >= 0; i += step)
    {
        if (needed_floors[i])
        {
            new_floor = i;
            return true;
        }
    }
    return false;
}





