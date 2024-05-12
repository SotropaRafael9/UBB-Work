#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ooop.h"

class ooop : public QMainWindow
{
    Q_OBJECT

public:
    ooop(QWidget *parent = nullptr);
    ~ooop();

private:
    Ui::ooopClass ui;
};
