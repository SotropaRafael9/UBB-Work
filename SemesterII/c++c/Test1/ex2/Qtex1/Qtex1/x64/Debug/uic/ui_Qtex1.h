/********************************************************************************
** Form generated from reading UI file 'Qtex1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEX1_H
#define UI_QTEX1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtex1Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Qtex1Class)
    {
        if (Qtex1Class->objectName().isEmpty())
            Qtex1Class->setObjectName("Qtex1Class");
        Qtex1Class->resize(363, 400);
        centralWidget = new QWidget(Qtex1Class);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 140, 75, 24));
        Qtex1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Qtex1Class);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 363, 22));
        Qtex1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Qtex1Class);
        mainToolBar->setObjectName("mainToolBar");
        Qtex1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Qtex1Class);
        statusBar->setObjectName("statusBar");
        Qtex1Class->setStatusBar(statusBar);

        retranslateUi(Qtex1Class);

        QMetaObject::connectSlotsByName(Qtex1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Qtex1Class)
    {
        Qtex1Class->setWindowTitle(QCoreApplication::translate("Qtex1Class", "Qtex1", nullptr));
        pushButton->setText(QCoreApplication::translate("Qtex1Class", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qtex1Class: public Ui_Qtex1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEX1_H
