#include "CreateMainWindowCommand.h"

QWidget* CreateMainWindowCommand::execute()
{
    MainWindowFactory factory;
    return factory.createUI();
}