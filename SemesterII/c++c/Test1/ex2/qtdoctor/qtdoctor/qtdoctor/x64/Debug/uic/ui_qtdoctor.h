/********************************************************************************
** Form generated from reading UI file 'qtdoctor.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDOCTOR_H
#define UI_QTDOCTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qtdoctorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qtdoctorClass)
    {
        if (qtdoctorClass->objectName().isEmpty())
            qtdoctorClass->setObjectName("qtdoctorClass");
        qtdoctorClass->resize(600, 400);
        menuBar = new QMenuBar(qtdoctorClass);
        menuBar->setObjectName("menuBar");
        qtdoctorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qtdoctorClass);
        mainToolBar->setObjectName("mainToolBar");
        qtdoctorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(qtdoctorClass);
        centralWidget->setObjectName("centralWidget");
        qtdoctorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(qtdoctorClass);
        statusBar->setObjectName("statusBar");
        qtdoctorClass->setStatusBar(statusBar);

        retranslateUi(qtdoctorClass);

        QMetaObject::connectSlotsByName(qtdoctorClass);
    } // setupUi

    void retranslateUi(QMainWindow *qtdoctorClass)
    {
        qtdoctorClass->setWindowTitle(QCoreApplication::translate("qtdoctorClass", "qtdoctor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qtdoctorClass: public Ui_qtdoctorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDOCTOR_H
