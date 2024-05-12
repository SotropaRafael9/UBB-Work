/********************************************************************************
** Form generated from reading UI file 'UserView.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERVIEW_H
#define UI_USERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserViewClass
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QListWidget *chatWidget;
    QLineEdit *chatLine;
    QPushButton *sendButton;
    QLineEdit *descLine;
    QLineEdit *latLine;
    QLineEdit *longLine;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *addButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *latLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *longLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *scoreLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserViewClass)
    {
        if (UserViewClass->objectName().isEmpty())
            UserViewClass->setObjectName("UserViewClass");
        UserViewClass->resize(957, 400);
        centralWidget = new QWidget(UserViewClass);
        centralWidget->setObjectName("centralWidget");
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 10, 256, 192));
        chatWidget = new QListWidget(centralWidget);
        chatWidget->setObjectName("chatWidget");
        chatWidget->setGeometry(QRect(300, 10, 256, 192));
        chatLine = new QLineEdit(centralWidget);
        chatLine->setObjectName("chatLine");
        chatLine->setGeometry(QRect(440, 220, 181, 22));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(500, 250, 71, 24));
        descLine = new QLineEdit(centralWidget);
        descLine->setObjectName("descLine");
        descLine->setGeometry(QRect(150, 220, 113, 22));
        latLine = new QLineEdit(centralWidget);
        latLine->setObjectName("latLine");
        latLine->setGeometry(QRect(150, 250, 113, 22));
        longLine = new QLineEdit(centralWidget);
        longLine->setObjectName("longLine");
        longLine->setGeometry(QRect(150, 290, 113, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(280, 220, 71, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(280, 260, 49, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(280, 300, 81, 16));
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(170, 320, 75, 24));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 210, 116, 68));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        latLabel = new QLabel(layoutWidget);
        latLabel->setObjectName("latLabel");

        horizontalLayout->addWidget(latLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        longLabel = new QLabel(layoutWidget);
        longLabel->setObjectName("longLabel");

        horizontalLayout_2->addWidget(longLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        scoreLabel = new QLabel(layoutWidget);
        scoreLabel->setObjectName("scoreLabel");

        horizontalLayout_3->addWidget(scoreLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        UserViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserViewClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 957, 22));
        UserViewClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UserViewClass);
        mainToolBar->setObjectName("mainToolBar");
        UserViewClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UserViewClass);
        statusBar->setObjectName("statusBar");
        UserViewClass->setStatusBar(statusBar);

        retranslateUi(UserViewClass);

        QMetaObject::connectSlotsByName(UserViewClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserViewClass)
    {
        UserViewClass->setWindowTitle(QCoreApplication::translate("UserViewClass", "UserView", nullptr));
        sendButton->setText(QCoreApplication::translate("UserViewClass", "Send", nullptr));
        label_4->setText(QCoreApplication::translate("UserViewClass", "Description", nullptr));
        label_5->setText(QCoreApplication::translate("UserViewClass", "Latitude", nullptr));
        label_6->setText(QCoreApplication::translate("UserViewClass", "Longitude", nullptr));
        addButton->setText(QCoreApplication::translate("UserViewClass", "Add", nullptr));
        label->setText(QCoreApplication::translate("UserViewClass", "Latitude:", nullptr));
        latLabel->setText(QCoreApplication::translate("UserViewClass", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("UserViewClass", "Longitude:", nullptr));
        longLabel->setText(QCoreApplication::translate("UserViewClass", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("UserViewClass", "Score:", nullptr));
        scoreLabel->setText(QCoreApplication::translate("UserViewClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserViewClass: public Ui_UserViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERVIEW_H
