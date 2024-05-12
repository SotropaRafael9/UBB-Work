#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_actionPlatform.h"

class actionPlatform : public QMainWindow
{
    Q_OBJECT

public:
    actionPlatform(QWidget *parent = nullptr);
    ~actionPlatform();

private:
    Ui::actionPlatformClass ui;
};
