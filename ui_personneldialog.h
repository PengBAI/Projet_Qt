/********************************************************************************
** Form generated from reading UI file 'personneldialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONNELDIALOG_H
#define UI_PERSONNELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PersonnelDialog
{
public:
    QLabel *nomlabel;
    QLabel *prenomlabel;
    QLabel *typelabel;
    QComboBox *PerComboBox;
    QGroupBox *infogroupBox;
    QLabel *loginLabel;
    QLabel *mdpLabel;
    QLineEdit *infoLoginLineEdit;
    QLineEdit *infopwdLineEdit;
    QPushButton *PerAjouterPB;
    QPushButton *PerAnuPB;
    QLineEdit *nomlineEdit;
    QLineEdit *prenomlineEdit;

    void setupUi(QDialog *PersonnelDialog)
    {
        if (PersonnelDialog->objectName().isEmpty())
            PersonnelDialog->setObjectName(QStringLiteral("PersonnelDialog"));
        PersonnelDialog->resize(291, 300);
        nomlabel = new QLabel(PersonnelDialog);
        nomlabel->setObjectName(QStringLiteral("nomlabel"));
        nomlabel->setGeometry(QRect(50, 50, 46, 13));
        prenomlabel = new QLabel(PersonnelDialog);
        prenomlabel->setObjectName(QStringLiteral("prenomlabel"));
        prenomlabel->setGeometry(QRect(50, 80, 46, 13));
        typelabel = new QLabel(PersonnelDialog);
        typelabel->setObjectName(QStringLiteral("typelabel"));
        typelabel->setGeometry(QRect(50, 110, 46, 13));
        PerComboBox = new QComboBox(PersonnelDialog);
        PerComboBox->setObjectName(QStringLiteral("PerComboBox"));
        PerComboBox->setGeometry(QRect(100, 110, 131, 22));
        infogroupBox = new QGroupBox(PersonnelDialog);
        infogroupBox->setObjectName(QStringLiteral("infogroupBox"));
        infogroupBox->setEnabled(true);
        infogroupBox->setGeometry(QRect(40, 150, 211, 91));
        loginLabel = new QLabel(infogroupBox);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(10, 20, 46, 13));
        mdpLabel = new QLabel(infogroupBox);
        mdpLabel->setObjectName(QStringLiteral("mdpLabel"));
        mdpLabel->setGeometry(QRect(10, 50, 71, 16));
        infoLoginLineEdit = new QLineEdit(infogroupBox);
        infoLoginLineEdit->setObjectName(QStringLiteral("infoLoginLineEdit"));
        infoLoginLineEdit->setGeometry(QRect(52, 20, 141, 20));
        infopwdLineEdit = new QLineEdit(infogroupBox);
        infopwdLineEdit->setObjectName(QStringLiteral("infopwdLineEdit"));
        infopwdLineEdit->setGeometry(QRect(82, 50, 111, 20));
        PerAjouterPB = new QPushButton(PersonnelDialog);
        PerAjouterPB->setObjectName(QStringLiteral("PerAjouterPB"));
        PerAjouterPB->setGeometry(QRect(80, 260, 75, 23));
        PerAnuPB = new QPushButton(PersonnelDialog);
        PerAnuPB->setObjectName(QStringLiteral("PerAnuPB"));
        PerAnuPB->setGeometry(QRect(170, 260, 75, 23));
        nomlineEdit = new QLineEdit(PersonnelDialog);
        nomlineEdit->setObjectName(QStringLiteral("nomlineEdit"));
        nomlineEdit->setGeometry(QRect(100, 50, 113, 20));
        prenomlineEdit = new QLineEdit(PersonnelDialog);
        prenomlineEdit->setObjectName(QStringLiteral("prenomlineEdit"));
        prenomlineEdit->setGeometry(QRect(100, 80, 113, 20));

        retranslateUi(PersonnelDialog);
        QObject::connect(PerAnuPB, SIGNAL(clicked()), PersonnelDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(PersonnelDialog);
    } // setupUi

    void retranslateUi(QDialog *PersonnelDialog)
    {
        PersonnelDialog->setWindowTitle(QApplication::translate("PersonnelDialog", "Personnel", 0));
        nomlabel->setText(QApplication::translate("PersonnelDialog", "Nom*", 0));
        prenomlabel->setText(QApplication::translate("PersonnelDialog", "Pr\303\251nom*", 0));
        typelabel->setText(QApplication::translate("PersonnelDialog", "Type*", 0));
        PerComboBox->clear();
        PerComboBox->insertItems(0, QStringList()
         << QApplication::translate("PersonnelDialog", "Banquier type A", 0)
         << QApplication::translate("PersonnelDialog", "Banquier type B", 0)
         << QApplication::translate("PersonnelDialog", "Assureur logement", 0)
         << QApplication::translate("PersonnelDialog", "Assureur voiture", 0)
         << QApplication::translate("PersonnelDialog", "Assureur vie", 0)
         << QApplication::translate("PersonnelDialog", "Divers", 0)
         << QApplication::translate("PersonnelDialog", "Informaticien", 0)
        );
        infogroupBox->setTitle(QApplication::translate("PersonnelDialog", "Informaticien", 0));
        loginLabel->setText(QApplication::translate("PersonnelDialog", "Login*", 0));
        mdpLabel->setText(QApplication::translate("PersonnelDialog", "Mot de passe*", 0));
        PerAjouterPB->setText(QApplication::translate("PersonnelDialog", "Ajouter", 0));
        PerAnuPB->setText(QApplication::translate("PersonnelDialog", "Annuler", 0));
    } // retranslateUi

};

namespace Ui {
    class PersonnelDialog: public Ui_PersonnelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONNELDIALOG_H
