#include "Controller.h"
#include <QMessageBox>
#include "../ui/CreateSubwindowCommand.h"

Controller::Controller(Model* model, QWidget* view, QObject* parent)
    : QObject(parent), model(model), view(view), exitButton(nullptr), openSubwindowButton(nullptr), subwindow(nullptr)
{
    // 找到按钮
    exitButton = view->findChild<QPushButton*>("ExitButton");
    openSubwindowButton = view->findChild<QPushButton*>("OpenSubwindowButton");

    // 连接信号和槽
    connectSignalsAndSlots();
}

void Controller::connectSignalsAndSlots()
{
    // 按钮1的点击事件：退出程序
    if (exitButton) {
        connect(exitButton, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(view, "Exit", "Exiting the application...");
            view->close();
        });
    }

    // 按钮2的点击事件：打开子窗口
    if (openSubwindowButton) {
        connect(openSubwindowButton, &QPushButton::clicked, this, [this]() {
            if (!model->isSubwindowOpen()) {
                CreateSubwindowCommand command;
                subwindow = static_cast<QDialog*>(command.execute());
                subwindow->show();
                model->setSubwindowOpen(true); // 更新模型状态

                // 连接子窗口的关闭信号
                connect(subwindow, &QDialog::finished, this, [this]() {
                    model->setSubwindowOpen(false); // 更新模型状态
                });
            } else {
                QMessageBox::information(view, "Subwindow", "Subwindow is already open.");
            }
        });
    }
}