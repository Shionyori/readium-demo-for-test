#ifndef MAINWINDOWFACTORY_H
#define MAINWINDOWFACTORY_H

#include "IUIFactory.h"
#include <QMainWindow>

class MainWindowFactory : public IUIFactory
{
public:
    QWidget* createUI() override;
};

#endif // MAINWINDOWFACTORY_H