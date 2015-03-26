#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include "triggermanager.h"
#include <QLabel>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(
            const QString& name,
            TriggerManager& manager,
            QLabel *label,
            QObject *parent = 0):
        QObject(parent),
        _manager(manager), _name(name),
        _label(label){}
    ~Controller();
private:
    TriggerManager& _manager;
    const QString _name;
    QLabel *_label;

signals:

public slots:
    void setValue(int value);
};

#endif // CONTROLLER_H
