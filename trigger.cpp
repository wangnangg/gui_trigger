#include "trigger.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QtGlobal>


Trigger::Trigger(const QString& path):
    _path(path),_name("noname")
{
}

Trigger::Trigger(const QString &path, const QString &name):
    _path(path), _name(name)
{
}

Trigger::~Trigger()
{

}

int Trigger::Get()
{
    this->_file.open(_path.toStdString());
    int value;
    _file >> value;

    _file.close();
    return value;
}

void Trigger::Set(int value)
{
    this->_file.open(_path.toStdString());
    _file << value << std::endl;
    _file.close();

}

const QString &Trigger::Name() const
{
    return this->_name;
}

