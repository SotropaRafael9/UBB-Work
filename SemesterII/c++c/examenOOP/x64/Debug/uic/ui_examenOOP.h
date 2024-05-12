/********************************************************************************
** Form generated from reading UI file 'examenOOP.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMENOOP_H
#define UI_EXAMENOOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_examenOOPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *examenOOPClass)
    {
        if (examenOOPClass->objectName().isEmpty())
            examenOOPClass->setObjectName("examenOOPClass");
        examenOOPClass->resize(600, 400);
        menuBar = new QMenuBar(examenOOPClass);
        menuBar->setObjectName("menuBar");
        examenOOPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(examenOOPClass);
        mainToolBar->setObjectName("mainToolBar");
        examenOOPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(examenOOPClass);
        centralWidget->setObjectName("centralWidget");
        examenOOPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(examenOOPClass);
        statusBar->setObjectName("statusBar");
        examenOOPClass->setStatusBar(statusBar);

        retranslateUi(examenOOPClass);

        QMetaObject::connectSlotsByName(examenOOPClass);
    } // setupUi

    void retranslateUi(QMainWindow *examenOOPClass)
    {
        examenOOPClass->setWindowTitle(QCoreApplication::translate("examenOOPClass", "examenOOP", nullptr));
    } // retranslateUi

};

namespace Ui {
    class examenOOPClass: public Ui_examenOOPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMENOOP_H
