#include "CloseDelegate.h"

void CloseDelegate::closeWindow(QWidget* window) {
    emit windowClosed(window);
}