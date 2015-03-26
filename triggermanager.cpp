#include "triggermanager.h"
#include <iostream>
#include <QDir>
#include <QFile>
#include <QtGlobal>

TriggerManager::~TriggerManager()
{

}

void TriggerManager::Init()
{
    this->_trigger_list.clear();
    QDir dir(_dir_path);
    QFileInfoList file_list = dir.entryInfoList();
    for(QFileInfoList::iterator iter = file_list.begin(); iter != file_list.end(); iter++)
    {
        if( (*iter).isFile() &&
          ((*iter).fileName().contains(this->_name_keyword) || this->_name_keyword == "." ))
        {
            Trigger *p_trigger = new Trigger((*iter).absoluteFilePath(), (*iter).fileName());
            this->_trigger_list.push_back(p_trigger);
        }
    }
}

std::vector<QString> TriggerManager::TriggerNames() const
{
    std::vector<QString> names;
    for(std::vector<Trigger*>::const_iterator iter = this->_trigger_list.begin(); 
	iter != this->_trigger_list.end(); 
	iter++)
    {
        Trigger* ptrigger = *iter;
        names.push_back(ptrigger->Name());

    }
    return names;
}

void TriggerManager::Set(const QString &name, int value)
{
    //limit value
    if(value < 0)
    {
        value = 0;
    } else if(value > 100)
    {
        value = 100;
    }

    for(std::vector<Trigger*>::iterator iter = this->_trigger_list.begin(); iter != this->_trigger_list.end(); iter++)
    {
        Trigger* ptrigger = *iter;
        if(ptrigger->Name() == name)
        {
            ptrigger->Set(value);
        }
    }
    Q_ASSERT(false);
}


int TriggerManager::Get(const QString &name)
{
   // std::cout << name.toStdString();
    for(std::vector<Trigger*>::iterator iter = this->_trigger_list.begin(); iter != this->_trigger_list.end(); iter++)
    {
        Trigger* ptrigger = *iter;
      //  std::cout << ptrigger->Name().toStdString();
        if(ptrigger->Name() == name)
        {
            return ptrigger->Get();
        }
    }
    Q_ASSERT(false);
}

