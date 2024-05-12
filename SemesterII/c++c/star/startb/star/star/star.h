#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_star.h"

class star : public QMainWindow
{
    Q_OBJECT

public:
    star(QWidget *parent = nullptr);
    ~star();

private:
    Ui::starClass ui;
};
