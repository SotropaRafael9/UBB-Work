#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_micro.h"

class micro : public QMainWindow
{
    Q_OBJECT

public:
    micro(QWidget *parent = nullptr);
    ~micro();

private:
    Ui::microClass ui;
};
