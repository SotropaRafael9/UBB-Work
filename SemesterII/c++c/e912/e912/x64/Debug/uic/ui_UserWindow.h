/********************************************************************************
** Form generated from reading UI file 'UserWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindowClass
{
public:
    QWidget *centralWidget;
    QPushButton *addButton;
    QComboBox *categoriesBox;
    QPushButton *bidButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QListWidget *itemsList;
    QListWidget *offersList;
    QWidget *widget1;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QLineEdit *categoryEdit;
    QLabel *label_3;
    QLineEdit *priceEdit;
    QWidget *widget2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *bidEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserWindowClass)
    {
        if (UserWindowClass->objectName().isEmpty())
            UserWindowClass->setObjectName("UserWindowClass");
        UserWindowClass->resize(600, 400);
        centralWidget = new QWidget(UserWindowClass);
        centralWidget->setObjectName("centralWidget");
        addButton = new QPushButton(centralWidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(300, 230, 75, 24));
        categoriesBox = new QComboBox(centralWidget);
        categoriesBox->setObjectName("categoriesBox");
        categoriesBox->setGeometry(QRect(460, 230, 68, 22));
        bidButton = new QPushButton(centralWidget);
        bidButton->setObjectName("bidButton");
        bidButton->setGeometry(QRect(440, 290, 75, 24));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 10, 520, 194));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        itemsList = new QListWidget(widget);
        itemsList->setObjectName("itemsList");

        horizontalLayout->addWidget(itemsList);

        offersList = new QListWidget(widget);
        offersList->setObjectName("offersList");

        horizontalLayout->addWidget(offersList);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(10, 230, 209, 77));
        formLayout = new QFormLayout(widget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameEdit = new QLineEdit(widget1);
        nameEdit->setObjectName("nameEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_2 = new QLabel(widget1);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        categoryEdit = new QLineEdit(widget1);
        categoryEdit->setObjectName("categoryEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, categoryEdit);

        label_3 = new QLabel(widget1);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        priceEdit = new QLineEdit(widget1);
        priceEdit->setObjectName("priceEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, priceEdit);

        widget2 = new QWidget(centralWidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(250, 290, 164, 23));
        formLayout_2 = new QFormLayout(widget2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName("formLayout_2");
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(widget2);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        bidEdit = new QLineEdit(widget2);
        bidEdit->setObjectName("bidEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, bidEdit);

        UserWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserWindowClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        UserWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UserWindowClass);
        mainToolBar->setObjectName("mainToolBar");
        UserWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(UserWindowClass);
        statusBar->setObjectName("statusBar");
        UserWindowClass->setStatusBar(statusBar);

        retranslateUi(UserWindowClass);

        QMetaObject::connectSlotsByName(UserWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindowClass)
    {
        UserWindowClass->setWindowTitle(QCoreApplication::translate("UserWindowClass", "UserWindow", nullptr));
        addButton->setText(QCoreApplication::translate("UserWindowClass", "Add item", nullptr));
        bidButton->setText(QCoreApplication::translate("UserWindowClass", "Bid", nullptr));
        label->setText(QCoreApplication::translate("UserWindowClass", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindowClass", "Category", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindowClass", "Current price", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindowClass", "Sum", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindowClass: public Ui_UserWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
