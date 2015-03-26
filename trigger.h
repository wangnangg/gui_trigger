#ifndef TRIGGER_H
#define TRIGGER_H
#include <iostream>
#include <fstream>
#include <QString>


class Trigger
{
public:
    Trigger(const QString& path);
    Trigger(const QString& path, const QString& name);
    ~Trigger();
    int Get();
    void Set(int value);
    const QString& Name() const;

private:
    //no copy
    Trigger(const Trigger&);
    std::fstream _file;
    QString _path;
    QString _name;
};

#endif // TRIGGER_H
