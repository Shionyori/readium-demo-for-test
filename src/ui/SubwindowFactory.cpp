#include "SubwindowFactory.h"
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

QWidget* SubwindowFactory::createUI()
{
    QDialog* subwindow = new QDialog();
    subwindow->resize(400, 300);
    subwindow->setWindowTitle("Subwindow");

    // 添加一个标签
    QLabel* label = new QLabel("This is a subwindow.", subwindow);
    QVBoxLayout* layout = new QVBoxLayout(subwindow);
    layout->addWidget(label);

    return subwindow;
}