#ifndef CREATESUBWINDOWCOMMAND_H
#define CREATESUBWINDOWCOMMAND_H

#include "IUICommand.h"
#include "SubwindowFactory.h"

class CreateSubwindowCommand : public IUICommand
{
public:
    QWidget* execute() override;
};

#endif // CREATESUBWINDOWCOMMAND_H