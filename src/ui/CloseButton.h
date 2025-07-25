#pragma once
#include "ActionWidget.h"
#include <QPushButton>
#include "../delegate/CloseDelegate.h"

class CloseButton : public ActionWidget {
public:
    CloseButton(CloseDelegate* delegate);
    QWidget* widget() override;
    void execute() override;

private:
    QPushButton* button;
    CloseDelegate* closeDelegate;
};