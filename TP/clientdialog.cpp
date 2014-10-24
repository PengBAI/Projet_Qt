#include "clientdialog.h"
#include "ui_clientdialog.h"
#include "gestionbdd.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFileDialog>

ClientDialog::ClientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    ui->jourEdit->setMinimumDate(QDate::currentDate());
    ValNumber(ui->codelineEdit); // code postale
    ValNumber(ui->tellineEdit);  // téléphone


    modelclient=new ModeleClient();
    ui->RessourcelistView->setModel(modelclient->rechercheRessource());

}

ClientDialog::ClientDialog(int idClient, QWidget *parent):
    QDialog(parent), ui(new Ui::ClientDialog)
{
    ui->setupUi(this);

    ui->nomlineEdit->setReadOnly(true);
    ui->prenomlineEdit->setReadOnly(true);
    ValNumber(ui->codelineEdit); // code postale
    ValNumber(ui->tellineEdit);  // téléphone
    ui->nomlineEdit->setEnabled(false);
    ui->prenomlineEdit->setEnabled(false);
    //QValidator *intValider=new QIntValidator(10,5000,this);
    //ui->dureelineEdit->setValidator(intValider);
    modelclient=new ModeleClient();

    ui->RessourcelistView->setModel(modelclient->rechercheRessource());

    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"Database n'est pas ouvert!";
    QSqlQuery query(mabdd);  // pour type
    /* ramplir le fenêtre */
    query.prepare("select Nom,Prenom,Adresse,Ville,CP,Commentaire,Tel,DateRdv,DureeRdv,Priorite from TClient where Id=:id");
    query.bindValue(":id",idClient);
    query.exec();
    if(query.next()){
        ui->nomlineEdit->setText(query.value(0).toString());
        ui->prenomlineEdit->setText(query.value(1).toString());
        ui->adrlineEdit->setText(query.value(2).toString());
        ui->villelineEdit->setText(query.value(3).toString());
        ui->codelineEdit->setText(query.value(4).toString());
        ui->commentaireEdit->setText(query.value(5).toString());
        ui->tellineEdit->setText(query.value(6).toString());
        ui->jourEdit->setDate(query.value(7).toDate());
        ui->dureelineEdit->setText(query.value(8).toString());
        ui->priopriteBox->setCurrentIndex(query.value(9).toInt()-1);
    }
    ui->ClientAjouterPB->setText("Modifier");

}
ClientDialog::~ClientDialog()
{
    delete ui;
    delete modelclient;
}

/* uniquement des chiffres pour simpliﬁer */
void ClientDialog::ValNumber(QLineEdit *CEdit){
    QRegExp rx("^[0-9]*[1-9][0-9]*$");
    CEdit->setValidator(new QRegExpValidator(rx,CEdit));
}

/* chaîne de caractères dont la première
 * lettre est en majuscule, le reste en minuscule */
void ClientDialog::ValPreMas(QLineEdit *Qline){
    if(Qline->text()!=""){
        QString textall=Qline->text();
        textall=textall.toLower();
        textall[0]=textall[0].toUpper();
        Qline->setText(textall);
    }
}

void ClientDialog::on_nomlineEdit_editingFinished()
{
    ValPreMas(ui->nomlineEdit);
}

void ClientDialog::on_prenomlineEdit_editingFinished()
{
    ValPreMas(ui->prenomlineEdit);
}

void ClientDialog::on_villelineEdit_editingFinished()
{
    ValPreMas(ui->villelineEdit);
}

void ClientDialog::on_ClientAjouterPB_clicked()
{
    QString nom=ui->nomlineEdit->text();
    QString prenom=ui->prenomlineEdit->text();
    QString tel=ui->tellineEdit->text();
    QString adr=ui->adrlineEdit->text();
    QString ville=ui->villelineEdit->text();
    QString code=ui->codelineEdit->text();
    QString commentaire=ui->commentaireEdit->toPlainText();
    QString divers=ui->diversEdit->toPlainText();
    QString duree=ui->dureelineEdit->text();
    QString priorite=ui->priopriteBox->currentText();
    QString jour=ui->jourEdit->date().toString("yyyy-MM-dd");
    QModelIndexList listSelect=ui->RessourcelistView->selectionModel()->selectedIndexes();

    QString warningStr="Attention! ";
    if(nom==""){
        warningStr.append("Nom, ");
        ui->nomlabel->setStyleSheet("QLabel { color : red; }");
    }
    if(prenom==""){
        warningStr.append("Prenom, ");
        ui->prenomlabel->setStyleSheet("QLabel { color : red; }");
    }
    if(adr==""){
        warningStr.append("Adresse, ");
        ui->adrlabel->setStyleSheet("QLabel { color : red; }");
    }
    if(ville==""){
        warningStr.append("Ville, ");
        ui->villelabel->setStyleSheet("QLabel { color : red; }");
    }
    if(code==""){
        warningStr.append("Code Postal, ");
        ui->codelabel->setStyleSheet("QLabel { color : red; }");
    }
    if(duree=="" || duree.toInt()<10){
        warningStr.append("Durée RDV(il faut > 10 mins), ");
        ui->dureelabel->setStyleSheet("QLabel { color : red; }");
    }
    if(listSelect.size()==0){
        warningStr.append("Ressource, ");
        ui->reslabel->setStyleSheet("QLabel { color : red; }");
    }
    if(warningStr!="Attention! "){
        /* certains informations sont vides */
        QMessageBox ms;
        ms.setWindowTitle("invalide");
        warningStr.append("sont obligatoires!");
        ms.setText(warningStr);
        ms.exec();
    }else{
        /* supprimer client dans TClient TRdv */
        GestionBDD::supprimerClient(nom, prenom);
        /* insert */
        QStringList *elementsSelects = new QStringList();
        for(int i=0;i<listSelect.size();i++ ){
            QString elementSelect=modelclient->rechercheRessource()->data(listSelect[i],Qt::DisplayRole).toString();
            elementsSelects->append(elementSelect);
            //qDebug()<<elementSelect;
        }
        GestionBDD::ajouteClient(nom,prenom,tel,adr,ville,code,commentaire,divers,duree,priorite,elementsSelects,jour);
        accept();

    }
}

void ClientDialog::on_dureelineEdit_editingFinished()
{
    ui->dureelineEdit->setValidator(new QIntValidator(10,5000,this));
}

void ClientDialog::on_pushButton_clicked()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,tr("Enregistrer Planning"), "", tr("Textes Files (*.xml)"));

    if (!fileName.isNull())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly  | QIODevice::Text | QIODevice::Append))
        {
            QMessageBox::warning(this,"","Fichier ouvrir échec!",QMessageBox::Yes);
        }
        QTextStream in(&file);
        in<<"<TClient>"<<"\n";
        in<<"<Client Id='...'>"<<"\n";
        in<<"<Nom>...</Nom>"<<"\n";
        in<<"<Prenom>...</Prenom>"<<"\n";
        in<<"</Client>"<<"\n";
        in<<"</TClient>"<<"\n";
        file.close();
    }
}
