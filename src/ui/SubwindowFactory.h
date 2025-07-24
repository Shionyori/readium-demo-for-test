#ifndef SUBWINDOWFACTORY_H
#define SUBWINDOWFACTORY_H

#include "IUIFactory.h"
#include <QWidget>

class SubwindowFactory : public IUIFactory
{
public:
    QWidget* createUI() override;
};

#endif // SUBWINDOWFACTORY_H