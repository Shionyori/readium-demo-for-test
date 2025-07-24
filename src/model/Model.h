#ifndef MODEL_H
#define MODEL_H

#include <QString>

class Model
{
public:
    Model() {}

    // 设置数据
    void setData(const QString& data) { this->data = data; }

    // 获取数据
    QString getData() const { return data; }

    // 设置子窗口是否打开
    void setSubwindowOpen(bool isOpen) { subwindowOpen = isOpen; }

    // 获取子窗口是否打开
    bool isSubwindowOpen() const { return subwindowOpen; }

private:
    QString data;          // 存储一些状态信息或数据
    bool subwindowOpen = false; // 存储子窗口是否打开的状态
};

#endif // MODEL_H