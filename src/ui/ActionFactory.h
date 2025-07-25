#pragma once
#include "ActionWidget.h"
#include "CloseButton.h"

class ActionFactory {
public:
    enum ActionType {
        Close,
    };

    static ActionWidget* createAction(
        ActionType type, 
        CloseDelegate* delegate = nullptr) 
    {
        switch (type) {
            case Close:
                return new CloseButton(delegate);
            default:
                return nullptr;
        }
    }
};