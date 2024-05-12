/********************************************************************************
** Form generated from reading UI file 'actionPlatform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONPLATFORM_H
#define UI_ACTIONPLATFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_actionPlatformClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *actionPlatformClass)
    {
        if (actionPlatformClass->objectName().isEmpty())
            actionPlatformClass->setObjectName("actionPlatformClass");
        actionPlatformClass->resize(600, 400);
        menuBar = new QMenuBar(actionPlatformClass);
        menuBar->setObjectName("menuBar");
        actionPlatformClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(actionPlatformClass);
        mainToolBar->setObjectName("mainToolBar");
        actionPlatformClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(actionPlatformClass);
        centralWidget->setObjectName("centralWidget");
        actionPlatformClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(actionPlatformClass);
        statusBar->setObjectName("statusBar");
        actionPlatformClass->setStatusBar(statusBar);

        retranslateUi(actionPlatformClass);

        QMetaObject::connectSlotsByName(actionPlatformClass);
    } // setupUi

    void retranslateUi(QMainWindow *actionPlatformClass)
    {
        actionPlatformClass->setWindowTitle(QCoreApplication::translate("actionPlatformClass", "actionPlatform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class actionPlatformClass: public Ui_actionPlatformClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONPLATFORM_H
