#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPtest.h"

class OOPtest : public QMainWindow
{
    Q_OBJECT

public:
    OOPtest(QWidget *parent = nullptr);
    ~OOPtest();

private:
    Ui::OOPtestClass ui;
};
