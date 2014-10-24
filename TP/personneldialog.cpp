#include "personneldialog.h"
#include "ui_personneldialog.h"
#include "gestionbdd.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <qDebug>


PersonnelDialog::PersonnelDialog(QWidget *parent) :
    QDialog(parent),ui(new Ui::PersonnelDialog)
{
    ui->setupUi(this);
    ui->infogroupBox->setVisible(false);
}

PersonnelDialog::PersonnelDialog(int personnelId,QWidget *parent):
    QDialog(parent),ui(new Ui::PersonnelDialog){

    ui->setupUi(this);
    ui->PerComboBox->setCurrentIndex(personnelId);
    ui->PerComboBox->setEnabled(false);
}

PersonnelDialog::PersonnelDialog(QString nom,QWidget *parent):
    QDialog(parent),ui(new Ui::PersonnelDialog)
{
    ui->setupUi(this);

    ui->nomlineEdit->setText(nom);
    ui->nomlineEdit->setReadOnly(true);
    ui->prenomlineEdit->setReadOnly(true);
    ui->infogroupBox->setVisible(false);
    ui->nomlineEdit->setEnabled(false);
    ui->prenomlineEdit->setEnabled(false);
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"Database n'est pas ouvert!";
    QSqlQuery query(mabdd);  // pour type
    /* ramplir le fenêtre */
    query.prepare("select Prenom, IdType from TRessource where Nom=:nom");
    query.bindValue(":nom",nom);
    query.exec();
    if(query.next()){
        ui->prenomlineEdit->setText(query.value(0).toString());
        ui->PerComboBox->setCurrentIndex(query.value(1).toInt()-1);
    }
    ui->PerAjouterPB->setText("Modifier");
}

PersonnelDialog::~PersonnelDialog()
{
    delete ui;
}

void PersonnelDialog::on_PerComboBox_currentIndexChanged(int index)
{
    if(index==6){
        ui->infogroupBox->setVisible(true);
    }else{
        ui->infogroupBox->setVisible(false);
    }
}

/* chaîne de caractères dont la première
 * lettre est en majuscule, le reste en minuscule */
void PersonnelDialog::ValPreMas(QLineEdit *Qline){
    if(Qline->text()!=""){
        QString textall=Qline->text();
        textall=textall.toLower();
        textall[0]=textall[0].toUpper();
        Qline->setText(textall);
    }
}

void PersonnelDialog::on_PerAjouterPB_clicked()
{

    /* supprimer dans TCompte TRessouce TRdv */
    GestionBDD::supprimerPersonne(ui->nomlineEdit->text());

    QString warningStr="Attention! ";
    if(ui->nomlineEdit->text()==""){
        warningStr.append("Nom, ");
        ui->nomlabel->setStyleSheet("QLabel { color : red; }");
    }
    if(ui->prenomlineEdit->text()==""){
        warningStr.append("Prenom, ");
        ui->prenomlabel->setStyleSheet("QLabel { color : red; }");
    }
    if(warningStr!="Attention! "){
        /* informations invalides */
        QMessageBox ms;
        ms.setWindowTitle("invalide");
        warningStr.append("sont obligatoires!");
        ms.setText(warningStr);
        ms.exec();
    }else{
        /* insert into la base de donnée */
        if(ui->PerComboBox->currentIndex()==6){
            /* le type informaticien */
            if(ui->infoLoginLineEdit->text()==""){
                warningStr.append("Login, ");
                ui->loginLabel->setStyleSheet("QLabel { color : red; }");
            }
            if(ui->infopwdLineEdit->text()==""){
                warningStr.append("Mot de passe, ");
                ui->mdpLabel->setStyleSheet("QLabel { color : red; }");
            }
            if(warningStr!="Attention! "){
                /* Mdp et Login invalides */
                QMessageBox ms;
                ms.setWindowTitle("invalide");
                warningStr.append("sont obligatoires!");
                ms.setText(warningStr);
                ms.exec();
            }else{
                GestionBDD::AjouterInformaticien(ui->nomlineEdit->text(), ui->prenomlineEdit->text(),
                                                 ui->infoLoginLineEdit->text(), ui->infopwdLineEdit->text());
                accept();
            }
        }else{
            /* les autres types */
            GestionBDD::AjouterRessource(ui->nomlineEdit->text(),
                                         ui->prenomlineEdit->text(), ui->PerComboBox->currentIndex());
            accept();
        }
    }
}

void PersonnelDialog::on_nomlineEdit_editingFinished()
{
    ValPreMas(ui->nomlineEdit);
}

void PersonnelDialog::on_prenomlineEdit_editingFinished()
{
    ValPreMas(ui->prenomlineEdit);
}

