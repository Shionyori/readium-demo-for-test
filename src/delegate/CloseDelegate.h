#pragma once
#include <QObject>
#include <QWidget>

class CloseDelegate : public QObject {
    Q_OBJECT
public:
    CloseDelegate() = default;
    void closeWindow(QWidget* window);

signals:
    void windowClosed(QWidget* window);
};