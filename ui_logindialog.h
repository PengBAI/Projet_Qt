/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *loginButton;
    QPushButton *annulerButton;
    QLabel *userlabel;
    QLabel *pwdlabel;
    QLineEdit *userlineEdit;
    QLineEdit *pwdlineEdit;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(371, 192);
        loginButton = new QPushButton(LoginDialog);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(80, 130, 75, 23));
        annulerButton = new QPushButton(LoginDialog);
        annulerButton->setObjectName(QStringLiteral("annulerButton"));
        annulerButton->setGeometry(QRect(210, 130, 75, 23));
        userlabel = new QLabel(LoginDialog);
        userlabel->setObjectName(QStringLiteral("userlabel"));
        userlabel->setGeometry(QRect(80, 40, 61, 16));
        pwdlabel = new QLabel(LoginDialog);
        pwdlabel->setObjectName(QStringLiteral("pwdlabel"));
        pwdlabel->setGeometry(QRect(80, 80, 71, 16));
        userlineEdit = new QLineEdit(LoginDialog);
        userlineEdit->setObjectName(QStringLiteral("userlineEdit"));
        userlineEdit->setGeometry(QRect(160, 40, 131, 20));
        pwdlineEdit = new QLineEdit(LoginDialog);
        pwdlineEdit->setObjectName(QStringLiteral("pwdlineEdit"));
        pwdlineEdit->setGeometry(QRect(160, 80, 131, 20));

        retranslateUi(LoginDialog);
        QObject::connect(annulerButton, SIGNAL(clicked()), LoginDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", 0));
        loginButton->setText(QApplication::translate("LoginDialog", "Connecte", 0));
        annulerButton->setText(QApplication::translate("LoginDialog", "Annuler", 0));
        userlabel->setText(QApplication::translate("LoginDialog", "Identifiant", 0));
        pwdlabel->setText(QApplication::translate("LoginDialog", "Mot de passe", 0));
        userlineEdit->setText(QApplication::translate("LoginDialog", "val", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
