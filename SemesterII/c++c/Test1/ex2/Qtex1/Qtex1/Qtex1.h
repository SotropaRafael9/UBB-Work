#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qtex1.h"

class Qtex1 : public QMainWindow
{
    Q_OBJECT

public:
    Qtex1(QWidget *parent = nullptr);
    ~Qtex1();

private:
    Ui::Qtex1Class ui;
};
