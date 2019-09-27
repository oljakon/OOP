#include "buttons.h"

Buttons::Buttons(QWidget *parent) : QPushButton(parent)
{
    current_state = NOTPRESSED;
    floor = 0;

    QObject::connect(this, SIGNAL(clicked()), this, SLOT(button_is_pressed()));
    QObject::connect(this, SIGNAL(reset_button()), this, SLOT(button_is_unpressed()));
}

void Buttons::set_floor(int new_floor)
{
    floor = new_floor;
}

Buttons::~Buttons()
{

}

void Buttons::button_is_pressed()
{
    if (current_state == NOTPRESSED)
    {
        current_state = PRESSED;
        this->setEnabled(false);
        emit input_floor(floor);
    }
}

void Buttons::button_is_unpressed()
{
    if (current_state == PRESSED)
    {
        current_state = NOTPRESSED;
        this->setEnabled(true);
   }
}
