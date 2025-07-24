#include <QApplication>
#include "ui/CreateMainWindowCommand.h"
#include "model/Model.h"
#include "controller/Controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建UI
    CreateMainWindowCommand command;
    QWidget* mainWindow = command.execute();

    // 创建MVC部分
    Model model;
    Controller controller(&model, mainWindow);

    // 显示主窗口
    mainWindow->show();

    return app.exec();
}
