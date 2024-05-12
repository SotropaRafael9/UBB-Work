#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_resercher.h"

class resercher : public QMainWindow
{
    Q_OBJECT

public:
    resercher(QWidget *parent = nullptr);
    ~resercher();

private:
    Ui::resercherClass ui;
};
