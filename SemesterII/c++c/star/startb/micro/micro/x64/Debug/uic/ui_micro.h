/********************************************************************************
** Form generated from reading UI file 'micro.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICRO_H
#define UI_MICRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_microClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *microClass)
    {
        if (microClass->objectName().isEmpty())
            microClass->setObjectName("microClass");
        microClass->resize(600, 400);
        menuBar = new QMenuBar(microClass);
        menuBar->setObjectName("menuBar");
        microClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(microClass);
        mainToolBar->setObjectName("mainToolBar");
        microClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(microClass);
        centralWidget->setObjectName("centralWidget");
        microClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(microClass);
        statusBar->setObjectName("statusBar");
        microClass->setStatusBar(statusBar);

        retranslateUi(microClass);

        QMetaObject::connectSlotsByName(microClass);
    } // setupUi

    void retranslateUi(QMainWindow *microClass)
    {
        microClass->setWindowTitle(QCoreApplication::translate("microClass", "micro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class microClass: public Ui_microClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICRO_H
