#include <QApplication>
#include <QObject>
#include "ui/CreateMainWindowCommand.h"
#include "model/Model.h"
#include "controller/Controller.h"

#include <QVBoxLayout>
#include "delegate/CloseDelegate.h"
#include "ui/ActionFactory.h"
#include "ui/CloseButton.h"

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

    ActionFactory actionFactory;
    CloseDelegate closeDelegate;
    ActionWidget* closeButton = actionFactory.createAction(ActionFactory::Close, &closeDelegate);

    /* 创建一个新窗口用于测试另一套工厂模式 */
    QDialog* subwindow = new QDialog(mainWindow);
    subwindow->setWindowTitle("Subwindow");
    subwindow->setGeometry(100, 100, 400, 300);
    subwindow->setLayout(new QVBoxLayout);
    subwindow->layout()->addWidget(closeButton->widget());
    subwindow->show();
    
    //连接关闭信号
    QObject::connect(&closeDelegate, &CloseDelegate::windowClosed, subwindow, &QDialog::close);

    return app.exec();
}