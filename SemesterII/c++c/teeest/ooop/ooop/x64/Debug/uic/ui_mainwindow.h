/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/


#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *eventList;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *descriptionLabel;
    QLineEdit *descriptionLineEdit;
    QLabel *latitudeLabel;
    QLineEdit *latitudeLineEdit;
    QLabel *longitudeLabel;
    QLineEdit *longitudeLineEdit;
    QLabel *dateLabel;
    QLineEdit *dateLineEdit;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        eventList = new QListWidget(centralwidget);
        eventList->setObjectName("eventList");

        verticalLayout_2->addWidget(eventList);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(centralwidget);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        descriptionLabel = new QLabel(centralwidget);
        descriptionLabel->setObjectName("descriptionLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, descriptionLabel);

        descriptionLineEdit = new QLineEdit(centralwidget);
        descriptionLineEdit->setObjectName("descriptionLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, descriptionLineEdit);

        latitudeLabel = new QLabel(centralwidget);
        latitudeLabel->setObjectName("latitudeLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, latitudeLabel);

        latitudeLineEdit = new QLineEdit(centralwidget);
        latitudeLineEdit->setObjectName("latitudeLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, latitudeLineEdit);

        longitudeLabel = new QLabel(centralwidget);
        longitudeLabel->setObjectName("longitudeLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, longitudeLabel);

        longitudeLineEdit = new QLineEdit(centralwidget);
        longitudeLineEdit->setObjectName("longitudeLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, longitudeLineEdit);

        dateLabel = new QLabel(centralwidget);
        dateLabel->setObjectName("dateLabel");

        formLayout->setWidget(4, QFormLayout::LabelRole, dateLabel);

        dateLineEdit = new QLineEdit(centralwidget);
        dateLineEdit->setObjectName("dateLineEdit");

        formLayout->setWidget(4, QFormLayout::FieldRole, dateLineEdit);


        horizontalLayout->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        verticalLayout->addWidget(checkBox);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "Name:", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("MainWindow", "Description:", nullptr));
        latitudeLabel->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        longitudeLabel->setText(QCoreApplication::translate("MainWindow", "Longitude:", nullptr));
        dateLabel->setText(QCoreApplication::translate("MainWindow", "Date:", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Near Events", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add Event", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

