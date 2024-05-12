/********************************************************************************
** Form generated from reading UI file 'doctorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORWINDOW_H
#define UI_DOCTORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *filterPatientsCheckBox;
    QListWidget *patientsListWidget;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *nameEdit;
    QLineEdit *diagnosisEdit;
    QLineEdit *specialisationEdit;
    QLineEdit *currentDoctorEdit;
    QLineEdit *admissionDateEdit;
    QPushButton *addPatientButton;
    QVBoxLayout *verticalLayout;
    QLineEdit *oldNameEdit;
    QPushButton *updatePatientButton;

    void setupUi(QWidget *DoctorWindow)
    {
        if (DoctorWindow->objectName().isEmpty())
            DoctorWindow->setObjectName("DoctorWindow");
        DoctorWindow->resize(400, 300);
        horizontalLayout = new QHBoxLayout(DoctorWindow);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        filterPatientsCheckBox = new QCheckBox(DoctorWindow);
        filterPatientsCheckBox->setObjectName("filterPatientsCheckBox");

        verticalLayout_2->addWidget(filterPatientsCheckBox);

        patientsListWidget = new QListWidget(DoctorWindow);
        patientsListWidget->setObjectName("patientsListWidget");

        verticalLayout_2->addWidget(patientsListWidget);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        nameEdit = new QLineEdit(DoctorWindow);
        nameEdit->setObjectName("nameEdit");

        verticalLayout_3->addWidget(nameEdit);

        diagnosisEdit = new QLineEdit(DoctorWindow);
        diagnosisEdit->setObjectName("diagnosisEdit");

        verticalLayout_3->addWidget(diagnosisEdit);

        specialisationEdit = new QLineEdit(DoctorWindow);
        specialisationEdit->setObjectName("specialisationEdit");

        verticalLayout_3->addWidget(specialisationEdit);

        currentDoctorEdit = new QLineEdit(DoctorWindow);
        currentDoctorEdit->setObjectName("currentDoctorEdit");

        verticalLayout_3->addWidget(currentDoctorEdit);

        admissionDateEdit = new QLineEdit(DoctorWindow);
        admissionDateEdit->setObjectName("admissionDateEdit");

        verticalLayout_3->addWidget(admissionDateEdit);

        addPatientButton = new QPushButton(DoctorWindow);
        addPatientButton->setObjectName("addPatientButton");

        verticalLayout_3->addWidget(addPatientButton);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        oldNameEdit = new QLineEdit(DoctorWindow);
        oldNameEdit->setObjectName("oldNameEdit");

        verticalLayout->addWidget(oldNameEdit);

        updatePatientButton = new QPushButton(DoctorWindow);
        updatePatientButton->setObjectName("updatePatientButton");

        verticalLayout->addWidget(updatePatientButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(DoctorWindow);

        QMetaObject::connectSlotsByName(DoctorWindow);
    } // setupUi

    void retranslateUi(QWidget *DoctorWindow)
    {
        DoctorWindow->setWindowTitle(QCoreApplication::translate("DoctorWindow", "DoctorWindow", nullptr));
        filterPatientsCheckBox->setText(QCoreApplication::translate("DoctorWindow", "CheckBox", nullptr));
        addPatientButton->setText(QCoreApplication::translate("DoctorWindow", "PushButton", nullptr));
        updatePatientButton->setText(QCoreApplication::translate("DoctorWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorWindow: public Ui_DoctorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORWINDOW_H
