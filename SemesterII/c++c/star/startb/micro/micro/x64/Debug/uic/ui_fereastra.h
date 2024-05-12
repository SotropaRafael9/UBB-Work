/********************************************************************************
** Form generated from reading UI file 'fereastra.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEREASTRA_H
#define UI_FEREASTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fereastraClass
{
public:
    QWidget *centralWidget;
    QComboBox *comboBox;
    QTableView *tableView;
    QLineEdit *nameline;
    QLineEdit *specieline;
    QLineEdit *sizeline;
    QLineEdit *diseasesline;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *fereastraClass)
    {
        if (fereastraClass->objectName().isEmpty())
            fereastraClass->setObjectName("fereastraClass");
        fereastraClass->resize(524, 400);
        centralWidget = new QWidget(fereastraClass);
        centralWidget->setObjectName("centralWidget");
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(0, 210, 101, 41));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 10, 391, 192));
        nameline = new QLineEdit(centralWidget);
        nameline->setObjectName("nameline");
        nameline->setGeometry(QRect(300, 210, 113, 22));
        specieline = new QLineEdit(centralWidget);
        specieline->setObjectName("specieline");
        specieline->setGeometry(QRect(300, 240, 113, 22));
        sizeline = new QLineEdit(centralWidget);
        sizeline->setObjectName("sizeline");
        sizeline->setGeometry(QRect(300, 270, 113, 22));
        diseasesline = new QLineEdit(centralWidget);
        diseasesline->setObjectName("diseasesline");
        diseasesline->setGeometry(QRect(300, 310, 113, 22));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(440, 260, 75, 24));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 220, 49, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 250, 49, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 280, 49, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(200, 310, 49, 16));
        fereastraClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(fereastraClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 524, 22));
        fereastraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(fereastraClass);
        mainToolBar->setObjectName("mainToolBar");
        fereastraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(fereastraClass);
        statusBar->setObjectName("statusBar");
        fereastraClass->setStatusBar(statusBar);

        retranslateUi(fereastraClass);

        QMetaObject::connectSlotsByName(fereastraClass);
    } // setupUi

    void retranslateUi(QMainWindow *fereastraClass)
    {
        fereastraClass->setWindowTitle(QCoreApplication::translate("fereastraClass", "fereastra", nullptr));
        pushButton->setText(QCoreApplication::translate("fereastraClass", "add", nullptr));
        label->setText(QCoreApplication::translate("fereastraClass", "name", nullptr));
        label_2->setText(QCoreApplication::translate("fereastraClass", "specie", nullptr));
        label_3->setText(QCoreApplication::translate("fereastraClass", "size", nullptr));
        label_4->setText(QCoreApplication::translate("fereastraClass", "diseases", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fereastraClass: public Ui_fereastraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEREASTRA_H
