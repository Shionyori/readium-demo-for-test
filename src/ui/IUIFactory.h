#ifndef IUIFACTORY_H
#define IUIFACTORY_H

#include <QWidget>

class IUIFactory
{
public:
    virtual ~IUIFactory() {}
    virtual QWidget* createUI() = 0;
};

#endif // IUIFACTORY_H