#include "controller.h"

Controller::~Controller()
{

}

void Controller::setValue(int value)
{
    _manager.Set(_name, value);

    QString label_text(_name);
    label_text.append(": ");
    label_text.append(QString::number(_manager.Get(_name)));
    label_text.append("%");
    _label->setText(label_text);
}

