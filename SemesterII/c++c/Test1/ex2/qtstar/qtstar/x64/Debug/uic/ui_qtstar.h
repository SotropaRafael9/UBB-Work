/********************************************************************************
** Form generated from reading UI file 'qtstar.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSTAR_H
#define UI_QTSTAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtstarClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtstarClass)
    {
        if (qtstarClass->objectName().isEmpty())
            qtstarClass->setObjectName("qtstarClass");
        qtstarClass->resize(600, 400);
        menuBar = new QMenuBar(qtstarClass);
        menuBar->setObjectName("menuBar");
        qtstarClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtstarClass);
        mainToolBar->setObjectName("mainToolBar");
        qtstarClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qtstarClass);
        centralWidget->setObjectName("centralWidget");
        qtstarClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qtstarClass);
        statusBar->setObjectName("statusBar");
        qtstarClass->setStatusBar(statusBar);

        retranslateUi(qtstarClass);

        QMetaObject::connectSlotsByName(qtstarClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtstarClass)
    {
        qtstarClass->setWindowTitle(QCoreApplication::translate("qtstarClass", "qtstar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtstarClass: public Ui_qtstarClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSTAR_H
