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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserViewClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableView *starsTableView;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox;
    QPushButton *viewButton;
    QFormLayout *formLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *raLabel;
    QLineEdit *raLineEdit;
    QLabel *decLabel;
    QLineEdit *decLineEdit;
    QLabel *diameterLabel;
    QLineEdit *diameterLineEdit;
    QPushButton *addButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UserViewClass)
    {
        if (UserViewClass->objectName().isEmpty())
            UserViewClass->setObjectName("UserViewClass");
        UserViewClass->resize(565, 543);
        centralWidget = new QWidget(UserViewClass);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        starsTableView = new QTableView(centralWidget);
        starsTableView->setObjectName("starsTableView");

        verticalLayout->addWidget(starsTableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName("checkBox");

        horizontalLayout->addWidget(checkBox);

        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName("viewButton");

        horizontalLayout->addWidget(viewButton);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName("nameLabel");

        formLayout->setWidget(0, QFormLayout::LabelRole, nameLabel);

        nameLineEdit = new QLineEdit(centralWidget);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameLineEdit);

        raLabel = new QLabel(centralWidget);
        raLabel->setObjectName("raLabel");

        formLayout->setWidget(1, QFormLayout::LabelRole, raLabel);

        raLineEdit = new QLineEdit(centralWidget);
        raLineEdit->setObjectName("raLineEdit");

        formLayout->setWidget(1, QFormLayout::FieldRole, raLineEdit);

        decLabel = new QLabel(centralWidget);
        decLabel->setObjectName("decLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, decLabel);

        decLineEdit = new QLineEdit(centralWidget);
        decLineEdit->setObjectName("decLineEdit");

        formLayout->setWidget(2, QFormLayout::FieldRole, decLineEdit);

        diameterLabel = new QLabel(centralWidget);
        diameterLabel->setObjectName("diameterLabel");

        formLayout->setWidget(3, QFormLayout::LabelRole, diameterLabel);

        diameterLineEdit = new QLineEdit(centralWidget);
        diameterLineEdit->setObjectName("diameterLineEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, diameterLineEdit);


        verticalLayout->addLayout(formLayout);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        UserViewClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UserViewClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 565, 22));
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
        checkBox->setText(QCoreApplication::translate("UserViewClass", "See only the stars you are studying", nullptr));
        viewButton->setText(QCoreApplication::translate("UserViewClass", "View", nullptr));
        nameLabel->setText(QCoreApplication::translate("UserViewClass", "Name", nullptr));
        raLabel->setText(QCoreApplication::translate("UserViewClass", "Ra", nullptr));
        decLabel->setText(QCoreApplication::translate("UserViewClass", "Dec", nullptr));
        diameterLabel->setText(QCoreApplication::translate("UserViewClass", "Diameter", nullptr));
        addButton->setText(QCoreApplication::translate("UserViewClass", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserViewClass: public Ui_UserViewClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERVIEW_H
