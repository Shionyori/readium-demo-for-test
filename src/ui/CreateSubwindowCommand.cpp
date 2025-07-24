#include "CreateSubwindowCommand.h"

QWidget* CreateSubwindowCommand::execute()
{
    SubwindowFactory factory;
    return factory.createUI();
}