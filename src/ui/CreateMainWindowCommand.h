#ifndef CREATEMAINWINDOWCOMMAND_H
#define CREATEMAINWINDOWCOMMAND_H

#include "IUICommand.h"
#include "MainWindowFactory.h"

class CreateMainWindowCommand : public IUICommand
{
public:
    QWidget* execute() override;
};

#endif // CREATEMAINWINDOWCOMMAND_H