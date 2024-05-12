/********************************************************************************
** Form generated from reading UI file 'ooop.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OOOP_H
#define UI_OOOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ooopClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ooopClass)
    {
        if (ooopClass->objectName().isEmpty())
            ooopClass->setObjectName("ooopClass");
        ooopClass->resize(600, 400);
        menuBar = new QMenuBar(ooopClass);
        menuBar->setObjectName("menuBar");
        ooopClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ooopClass);
        mainToolBar->setObjectName("mainToolBar");
        ooopClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ooopClass);
        centralWidget->setObjectName("centralWidget");
        ooopClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ooopClass);
        statusBar->setObjectName("statusBar");
        ooopClass->setStatusBar(statusBar);

        retranslateUi(ooopClass);

        QMetaObject::connectSlotsByName(ooopClass);
    } // setupUi

    void retranslateUi(QMainWindow *ooopClass)
    {
        ooopClass->setWindowTitle(QCoreApplication::translate("ooopClass", "ooop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ooopClass: public Ui_ooopClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OOOP_H
