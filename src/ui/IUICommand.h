#ifndef IUICOMMAND_H
#define IUICOMMAND_H

#include <QWidget>

class IUICommand
{
public:
    virtual ~IUICommand() {}
    virtual QWidget* execute() = 0;
};

#endif // IUICOMMAND_H