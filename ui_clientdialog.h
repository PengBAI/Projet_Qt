/********************************************************************************
** Form generated from reading UI file 'clientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTDIALOG_H
#define UI_CLIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientDialog
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *villelineEdit;
    QLabel *commentairelabel;
    QLabel *villelabel;
    QLabel *adrlabel;
    QLabel *jourlabel;
    QLabel *nomlabel;
    QLabel *dureelabel;
    QDateEdit *jourEdit;
    QComboBox *priopriteBox;
    QLabel *tellabel;
    QLabel *codelabel;
    QLabel *prenomlabel;
    QLabel *priolabel;
    QLineEdit *dureelineEdit;
    QLineEdit *codelineEdit;
    QLineEdit *adrlineEdit;
    QLineEdit *tellineEdit;
    QLineEdit *prenomlineEdit;
    QLineEdit *nomlineEdit;
    QTextEdit *commentaireEdit;
    QListView *RessourcelistView;
    QLabel *reslabel;
    QLabel *diverslabel;
    QTextEdit *diversEdit;
    QPushButton *ClientAjouterPB;
    QPushButton *ClientAnnulerPB;
    QPushButton *pushButton;

    void setupUi(QDialog *ClientDialog)
    {
        if (ClientDialog->objectName().isEmpty())
            ClientDialog->setObjectName(QStringLiteral("ClientDialog"));
        ClientDialog->resize(516, 327);
        widget = new QWidget(ClientDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 471, 241));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        villelineEdit = new QLineEdit(widget);
        villelineEdit->setObjectName(QStringLiteral("villelineEdit"));

        gridLayout->addWidget(villelineEdit, 5, 3, 1, 1);

        commentairelabel = new QLabel(widget);
        commentairelabel->setObjectName(QStringLiteral("commentairelabel"));

        gridLayout->addWidget(commentairelabel, 7, 0, 1, 1);

        villelabel = new QLabel(widget);
        villelabel->setObjectName(QStringLiteral("villelabel"));

        gridLayout->addWidget(villelabel, 5, 0, 1, 1);

        adrlabel = new QLabel(widget);
        adrlabel->setObjectName(QStringLiteral("adrlabel"));

        gridLayout->addWidget(adrlabel, 4, 0, 1, 2);

        jourlabel = new QLabel(widget);
        jourlabel->setObjectName(QStringLiteral("jourlabel"));

        gridLayout->addWidget(jourlabel, 0, 5, 1, 1);

        nomlabel = new QLabel(widget);
        nomlabel->setObjectName(QStringLiteral("nomlabel"));

        gridLayout->addWidget(nomlabel, 0, 0, 1, 1);

        dureelabel = new QLabel(widget);
        dureelabel->setObjectName(QStringLiteral("dureelabel"));

        gridLayout->addWidget(dureelabel, 2, 5, 1, 1);

        jourEdit = new QDateEdit(widget);
        jourEdit->setObjectName(QStringLiteral("jourEdit"));
        jourEdit->setCalendarPopup(true);

        gridLayout->addWidget(jourEdit, 0, 7, 1, 1);

        priopriteBox = new QComboBox(widget);
        priopriteBox->setObjectName(QStringLiteral("priopriteBox"));

        gridLayout->addWidget(priopriteBox, 3, 7, 1, 1);

        tellabel = new QLabel(widget);
        tellabel->setObjectName(QStringLiteral("tellabel"));

        gridLayout->addWidget(tellabel, 3, 0, 1, 2);

        codelabel = new QLabel(widget);
        codelabel->setObjectName(QStringLiteral("codelabel"));

        gridLayout->addWidget(codelabel, 6, 0, 1, 1);

        prenomlabel = new QLabel(widget);
        prenomlabel->setObjectName(QStringLiteral("prenomlabel"));

        gridLayout->addWidget(prenomlabel, 2, 0, 1, 2);

        priolabel = new QLabel(widget);
        priolabel->setObjectName(QStringLiteral("priolabel"));

        gridLayout->addWidget(priolabel, 3, 5, 1, 1);

        dureelineEdit = new QLineEdit(widget);
        dureelineEdit->setObjectName(QStringLiteral("dureelineEdit"));

        gridLayout->addWidget(dureelineEdit, 2, 7, 1, 1);

        codelineEdit = new QLineEdit(widget);
        codelineEdit->setObjectName(QStringLiteral("codelineEdit"));

        gridLayout->addWidget(codelineEdit, 6, 3, 1, 1);

        adrlineEdit = new QLineEdit(widget);
        adrlineEdit->setObjectName(QStringLiteral("adrlineEdit"));

        gridLayout->addWidget(adrlineEdit, 4, 3, 1, 1);

        tellineEdit = new QLineEdit(widget);
        tellineEdit->setObjectName(QStringLiteral("tellineEdit"));

        gridLayout->addWidget(tellineEdit, 3, 3, 1, 1);

        prenomlineEdit = new QLineEdit(widget);
        prenomlineEdit->setObjectName(QStringLiteral("prenomlineEdit"));

        gridLayout->addWidget(prenomlineEdit, 2, 3, 1, 1);

        nomlineEdit = new QLineEdit(widget);
        nomlineEdit->setObjectName(QStringLiteral("nomlineEdit"));

        gridLayout->addWidget(nomlineEdit, 0, 3, 1, 1);

        commentaireEdit = new QTextEdit(widget);
        commentaireEdit->setObjectName(QStringLiteral("commentaireEdit"));

        gridLayout->addWidget(commentaireEdit, 7, 3, 1, 2);

        RessourcelistView = new QListView(widget);
        RessourcelistView->setObjectName(QStringLiteral("RessourcelistView"));
        RessourcelistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RessourcelistView->setSelectionMode(QAbstractItemView::MultiSelection);

        gridLayout->addWidget(RessourcelistView, 4, 7, 1, 1);

        reslabel = new QLabel(widget);
        reslabel->setObjectName(QStringLiteral("reslabel"));

        gridLayout->addWidget(reslabel, 4, 5, 1, 1);

        diverslabel = new QLabel(widget);
        diverslabel->setObjectName(QStringLiteral("diverslabel"));

        gridLayout->addWidget(diverslabel, 5, 5, 1, 1);

        diversEdit = new QTextEdit(widget);
        diversEdit->setObjectName(QStringLiteral("diversEdit"));

        gridLayout->addWidget(diversEdit, 5, 7, 1, 1);

        ClientAjouterPB = new QPushButton(ClientDialog);
        ClientAjouterPB->setObjectName(QStringLiteral("ClientAjouterPB"));
        ClientAjouterPB->setGeometry(QRect(250, 280, 75, 23));
        ClientAnnulerPB = new QPushButton(ClientDialog);
        ClientAnnulerPB->setObjectName(QStringLiteral("ClientAnnulerPB"));
        ClientAnnulerPB->setGeometry(QRect(350, 280, 75, 23));
        pushButton = new QPushButton(ClientDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 280, 75, 23));

        retranslateUi(ClientDialog);
        QObject::connect(ClientAnnulerPB, SIGNAL(clicked()), ClientDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(ClientDialog);
    } // setupUi

    void retranslateUi(QDialog *ClientDialog)
    {
        ClientDialog->setWindowTitle(QApplication::translate("ClientDialog", "Donn\303\251es du client", 0));
        commentairelabel->setText(QApplication::translate("ClientDialog", "Commentaire", 0));
        villelabel->setText(QApplication::translate("ClientDialog", "Ville*", 0));
        adrlabel->setText(QApplication::translate("ClientDialog", "Adresse*", 0));
        jourlabel->setText(QApplication::translate("ClientDialog", "Jour*", 0));
        nomlabel->setText(QApplication::translate("ClientDialog", "Nom*", 0));
        dureelabel->setText(QApplication::translate("ClientDialog", "Dur\303\251e(mins)*", 0));
        priopriteBox->clear();
        priopriteBox->insertItems(0, QStringList()
         << QApplication::translate("ClientDialog", "1", 0)
         << QApplication::translate("ClientDialog", "2", 0)
         << QApplication::translate("ClientDialog", "3", 0)
         << QApplication::translate("ClientDialog", "4", 0)
         << QApplication::translate("ClientDialog", "5", 0)
        );
        tellabel->setText(QApplication::translate("ClientDialog", "Tel", 0));
        codelabel->setText(QApplication::translate("ClientDialog", "Code postal*", 0));
        prenomlabel->setText(QApplication::translate("ClientDialog", "Pr\303\251nom*", 0));
        priolabel->setText(QApplication::translate("ClientDialog", "Priorit\303\251*", 0));
        dureelineEdit->setText(QApplication::translate("ClientDialog", "60", 0));
        reslabel->setText(QApplication::translate("ClientDialog", "Ressource*", 0));
        diverslabel->setText(QApplication::translate("ClientDialog", "Divers", 0));
        ClientAjouterPB->setText(QApplication::translate("ClientDialog", "Ajouter", 0));
        ClientAnnulerPB->setText(QApplication::translate("ClientDialog", "Annuler", 0));
        pushButton->setText(QApplication::translate("ClientDialog", "Exporter", 0));
    } // retranslateUi

};

namespace Ui {
    class ClientDialog: public Ui_ClientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTDIALOG_H
