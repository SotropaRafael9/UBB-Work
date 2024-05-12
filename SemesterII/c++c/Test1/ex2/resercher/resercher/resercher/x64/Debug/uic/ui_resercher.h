/********************************************************************************
** Form generated from reading UI file 'resercher.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERCHER_H
#define UI_RESERCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resercherClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *resercherClass)
    {
        if (resercherClass->objectName().isEmpty())
            resercherClass->setObjectName("resercherClass");
        resercherClass->resize(600, 400);
        menuBar = new QMenuBar(resercherClass);
        menuBar->setObjectName("menuBar");
        resercherClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(resercherClass);
        mainToolBar->setObjectName("mainToolBar");
        resercherClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(resercherClass);
        centralWidget->setObjectName("centralWidget");
        resercherClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(resercherClass);
        statusBar->setObjectName("statusBar");
        resercherClass->setStatusBar(statusBar);

        retranslateUi(resercherClass);

        QMetaObject::connectSlotsByName(resercherClass);
    } // setupUi

    void retranslateUi(QMainWindow *resercherClass)
    {
        resercherClass->setWindowTitle(QCoreApplication::translate("resercherClass", "resercher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resercherClass: public Ui_resercherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERCHER_H
