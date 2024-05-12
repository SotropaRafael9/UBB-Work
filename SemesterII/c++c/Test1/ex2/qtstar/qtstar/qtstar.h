#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qtstar.h"

class qtstar : public QMainWindow
{
    Q_OBJECT

public:
    qtstar(QWidget *parent = nullptr);
    ~qtstar();

private:
    Ui::qtstarClass ui;
};
