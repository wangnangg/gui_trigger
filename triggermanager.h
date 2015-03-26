#ifndef TRIGGERMANAGER_H
#define TRIGGERMANAGER_H
#include <QString>
#include <vector>
#include "trigger.h"

class TriggerManager
{
public:
    TriggerManager(const QString& dir_path, const QString& name_keyword):
        _dir_path(dir_path), _name_keyword(name_keyword){}
    ~TriggerManager();

public:
    void Init();
    std::vector<QString> TriggerNames() const;
    void Set(const QString &name, int value);
    int Get(const QString &name);


private:
    QString _dir_path;
    QString _name_keyword;
    std::vector<Trigger*> _trigger_list;
};

#endif // TRIGGERMANAGER_H
