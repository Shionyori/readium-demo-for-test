#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/Model.h"
#include <QWidget>
#include <QPushButton>
#include <QDialog>
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(Model* model, QWidget* view, QObject* parent = nullptr);
    void connectSignalsAndSlots();

private:
    Model* model;
    QWidget* view;
    QPushButton* exitButton;
    QPushButton* openSubwindowButton;
    QDialog* subwindow;
};

#endif // CONTROLLER_H
