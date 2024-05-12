#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WriterWindow.h"
#include "Domain.h"

class WriterWindow : public QMainWindow
{
    Q_OBJECT

public:
    WriterWindow(Writer w, QWidget* parent = nullptr);
    //WriterWindow(Writers,QWidget* parent = nullptr);
    ~WriterWindow();

private:
    Ui::QtWidgetsApplication1Class ui;
};
