/********************************************************************************
** Form generated from reading UI file 'OOPtest.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOPTEST_H
#define UI_OOPTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OOPtestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OOPtestClass)
    {
        if (OOPtestClass->objectName().isEmpty())
            OOPtestClass->setObjectName("OOPtestClass");
        OOPtestClass->resize(600, 400);
        menuBar = new QMenuBar(OOPtestClass);
        menuBar->setObjectName("menuBar");
        OOPtestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OOPtestClass);
        mainToolBar->setObjectName("mainToolBar");
        OOPtestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(OOPtestClass);
        centralWidget->setObjectName("centralWidget");
        OOPtestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(OOPtestClass);
        statusBar->setObjectName("statusBar");
        OOPtestClass->setStatusBar(statusBar);

        retranslateUi(OOPtestClass);

        QMetaObject::connectSlotsByName(OOPtestClass);
    } // setupUi

    void retranslateUi(QMainWindow *OOPtestClass)
    {
        OOPtestClass->setWindowTitle(QCoreApplication::translate("OOPtestClass", "OOPtest", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OOPtestClass: public Ui_OOPtestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOPTEST_H
