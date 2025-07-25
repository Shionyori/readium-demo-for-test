#include "CloseButton.h"

CloseButton::CloseButton(CloseDelegate* delegate)
    : closeDelegate(delegate) 
{
    button = new QPushButton("Close");
    connect(button, &QPushButton::clicked, this, &CloseButton::execute);
}

QWidget* CloseButton::widget() {
    return button;
}

void CloseButton::execute() {
    if (closeDelegate) {
        closeDelegate->closeWindow(button->parentWidget());
    }
}
