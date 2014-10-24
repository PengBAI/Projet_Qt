/********************************************************************************
** Form generated from reading UI file 'aproposdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APROPOSDIALOG_H
#define UI_APROPOSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_aproposDialog
{
public:
    QLabel *logolabel;
    QLabel *infolabel;
    QLabel *createurlabel;
    QLabel *label;

    void setupUi(QDialog *aproposDialog)
    {
        if (aproposDialog->objectName().isEmpty())
            aproposDialog->setObjectName(QStringLiteral("aproposDialog"));
        aproposDialog->resize(322, 193);
        logolabel = new QLabel(aproposDialog);
        logolabel->setObjectName(QStringLiteral("logolabel"));
        logolabel->setGeometry(QRect(60, 20, 181, 61));
        logolabel->setPixmap(QPixmap(QString::fromUtf8(":/logo.jpg")));
        infolabel = new QLabel(aproposDialog);
        infolabel->setObjectName(QStringLiteral("infolabel"));
        infolabel->setGeometry(QRect(70, 90, 141, 20));
        createurlabel = new QLabel(aproposDialog);
        createurlabel->setObjectName(QStringLiteral("createurlabel"));
        createurlabel->setGeometry(QRect(70, 110, 161, 41));
        label = new QLabel(aproposDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 160, 171, 20));

        retranslateUi(aproposDialog);

        QMetaObject::connectSlotsByName(aproposDialog);
    } // setupUi

    void retranslateUi(QDialog *aproposDialog)
    {
        aproposDialog->setWindowTitle(QApplication::translate("aproposDialog", "A propos", 0));
        logolabel->setText(QString());
        infolabel->setText(QApplication::translate("aproposDialog", "Version 1304  Qt & STL", 0));
        createurlabel->setText(QApplication::translate("aproposDialog", "Createurs:  Peng BAI, Lin SHEN", 0));
        label->setText(QApplication::translate("aproposDialog", "DI-4  Polytech Tours @2014", 0));
    } // retranslateUi

};

namespace Ui {
    class aproposDialog: public Ui_aproposDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APROPOSDIALOG_H
