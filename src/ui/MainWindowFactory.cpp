#include "MainWindowFactory.h"
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

QWidget* MainWindowFactory::createUI()
{
    QMainWindow* mainWindow = new QMainWindow();
    mainWindow->resize(800, 600);
    mainWindow->setWindowTitle("My Application");

    // 创建一个中心部件
    QWidget* centralWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);

    // 创建两个按钮
    QPushButton* button1 = new QPushButton("Exit");
    QPushButton* button2 = new QPushButton("Open Subwindow");

    // 设置按钮的objectName，方便在控制器中找到
    button1->setObjectName("ExitButton");
    button2->setObjectName("OpenSubwindowButton");

    // 将按钮添加到布局中
    layout->addWidget(button1);
    layout->addWidget(button2);

    // 设置中心部件
    mainWindow->setCentralWidget(centralWidget);

    // 返回主窗口
    return mainWindow;
}