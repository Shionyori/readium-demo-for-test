#pragma once
#include <QWidget>

class ActionWidget : public QObject {
    Q_OBJECT
public:
    virtual ~ActionWidget() {}
    virtual QWidget* widget() = 0;
    virtual void execute() = 0;
};