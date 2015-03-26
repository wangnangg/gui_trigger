#include <QApplication>
#include <QDir>
#include <QWidget>
#include <QVBoxLayout>
#include <QCheckBox>
#include <iostream>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include "trigger.h"
#include "triggermanager.h"
#include "controller.h"
#include <QMetaMethod>
void test_trigger()
{
    Trigger trigger("/home/wangnan/workspace/qt/tmp/1");

    std::cout << trigger.Get() << std::endl;
}

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    TriggerManager manager("/sys/kernel/debug", "aging_trigger");
    manager.Init();


    //create widgets
    QWidget *window = new QWidget;
    window->setWindowTitle("Trigger Manager");
    window->setGeometry(300, 400, 400,200);
    QVBoxLayout *layout = new QVBoxLayout;



    auto names = manager.TriggerNames();
    for(
        auto iter = names.begin();
        iter != names.end();
        iter++)
    {
        QString name = *iter;
        QLabel *label = new QLabel();

        QSlider *slider = new QSlider(Qt::Horizontal);
        slider->setMaximum(100);
        slider->setMinimum(0);

        Controller *controller = new Controller(name, manager, label);
        QObject::connect(slider, SIGNAL(valueChanged(int)), controller, SLOT(setValue(int)));

        int init_value = manager.Get(name);
        slider->setValue(init_value);
        controller->setValue(init_value);
        layout->addWidget(label);
        layout->addWidget(slider);
    }

    window->setLayout(layout);\

    window->show();
    return app.exec();

    //test_trigger();
}


