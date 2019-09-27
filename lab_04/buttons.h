#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QObject>

class Buttons : public QPushButton
{
    Q_OBJECT
    // Button states:
    enum buttons_states
    {
        NOTPRESSED,
        PRESSED
    };

public:
    explicit Buttons(QWidget *parent = 0);
    virtual ~Buttons();
    void set_floor(int new_floor);

public slots:
    void button_is_pressed();
    void button_is_unpressed();

signals:
    void reset_button();
    void input_floor(int floor);

private:
    buttons_states current_state;
    int floor;
};

#endif // BUTTONS_H
