/********************************************************************************
** Form generated from reading UI file 'star.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAR_H
#define UI_STAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_starClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *starClass)
    {
        if (starClass->objectName().isEmpty())
            starClass->setObjectName("starClass");
        starClass->resize(600, 400);
        menuBar = new QMenuBar(starClass);
        menuBar->setObjectName("menuBar");
        starClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(starClass);
        mainToolBar->setObjectName("mainToolBar");
        starClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(starClass);
        centralWidget->setObjectName("centralWidget");
        starClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(starClass);
        statusBar->setObjectName("statusBar");
        starClass->setStatusBar(statusBar);

        retranslateUi(starClass);

        QMetaObject::connectSlotsByName(starClass);
    } // setupUi

    void retranslateUi(QMainWindow *starClass)
    {
        starClass->setWindowTitle(QCoreApplication::translate("starClass", "star", nullptr));
    } // retranslateUi

};

namespace Ui {
    class starClass: public Ui_starClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAR_H
