#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtdoctor.h"

class qtdoctor : public QMainWindow
{
    Q_OBJECT

public:
    qtdoctor(QWidget *parent = nullptr);
    ~qtdoctor();

private:
    Ui::qtdoctorClass ui;
};
