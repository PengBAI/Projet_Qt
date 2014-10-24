#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clientdialog.h"
#include "personneldialog.h"
#include "aproposdialog.h"
#include "gestionbdd.h"
#include <QSqlTableModel>
#include <QDate>
#include <QDebug>
#include <QMessageBox>
#include <QtAlgorithms>
#include <QtCore/qmath.h>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Compte=0;
    QAction * clientAct=new QAction(QIcon(":/client.jpg"),"ajouter client",this);
    QAction * personAct=new QAction(QIcon(":/personnel.jpg"),"ajouter personnel",this);
    QAction * assureurvieAct=new QAction(QIcon(":/personnel.jpg"),"ajouter assureur vie",this);

    ui->mainToolBar->addAction(clientAct);
    ui->mainToolBar->addAction(personAct);
    ui->mainToolBar->addAction(assureurvieAct);
    connect(clientAct, SIGNAL(triggered()), this , SLOT(on_actionClient_triggered()));
    connect(personAct, SIGNAL(triggered()), this , SLOT(on_actionPersonnel_triggered()));
    connect(assureurvieAct, SIGNAL(triggered()), this , SLOT(actionAv_triggered()));

    modelclient=new ModeleClient();
    //QItemDelegate delegateClient;
    modelressource=new ModeleRessource();
    //QItemDelegate delegateRessource;
    modelPlanning=new ModelePlanning();

    /* affichiage les personnels par TreeView */
    resItemModel=modelressource->creationResModel();
    //ui->PersonnelTreeView->setItemDelegate(&delegateRessource);
    ui->PersonnelTreeView->setModel(resItemModel);

    /* affichiage les clients*/
    QString nom=ui->nomlineEdit->text();
    QString prenom=ui->prenomlineEdit->text();
    QDate datedebut=ui->datedebutEdit->date();
    QDate datefin=ui->datefinEdit->date();
    QString id=ui->idlineEdit->text();
    clientTableModel=modelclient->rechercheClient(nom,prenom,datedebut,datefin,id);
    //ui->clientView->setItemDelegate(&delegateClient);
    ui->clientView->setModel(clientTableModel);
    /* si planificationView est vide, enregistreButton est enabled */
    //if(!ui->planificationView->verticalHeader()->count()){
    ui->enregistrePB->setEnabled(false);
    //}


}

MainWindow::~MainWindow()
{
    delete ui;
    delete modelclient;
    delete modelressource;
    delete modelPlanning;
}

void MainWindow::on_actionQuitter_triggered()
{
    this->close();
    qDebug()<<"Le nombre de requête de type delete: "<<this->getCompte();
}

void MainWindow::on_actionClient_triggered()
{
    ClientDialog * Clientdia=new ClientDialog();
    if(Clientdia->exec()==QDialog::Accepted){
        QString nom=ui->nomlineEdit->text();
        QString prenom=ui->prenomlineEdit->text();
        QDate datedebut=ui->datedebutEdit->date();
        QDate datefin=ui->datefinEdit->date();
        QString id=ui->idlineEdit->text();
        clientTableModel=modelclient->rechercheClient(nom,prenom,datedebut,datefin,id);
        ui->clientView->setModel(clientTableModel);
        ui->statusBar->showMessage("Ajout de client effectué! ");
    }
}

void MainWindow::on_actionPersonnel_triggered()
{
    PersonnelDialog * Personneldia=new PersonnelDialog();
    if(Personneldia->exec()==QDialog::Accepted){
        /* affichiage les personnels par TreeView */
        delete resItemModel;
        resItemModel=modelressource->creationResModel();
        ui->PersonnelTreeView->setModel(resItemModel);
        ui->statusBar->showMessage("Un nouveau personnel est ajouté! ");
    }

}

void MainWindow::actionAv_triggered(){
    int id=4;
    PersonnelDialog * Personneldia=new PersonnelDialog(id);
    if(Personneldia->exec()==QDialog::Accepted){
        /* affichiage les personnels par TreeView */
        delete resItemModel;
        resItemModel=modelressource->creationResModel();
        ui->PersonnelTreeView->setModel(resItemModel);
        ui->statusBar->showMessage("Un nouveau assureur vie est ajouté! ");
    }
}
/*
void MainWindow::ajoute_client_message(){
    ui->statusBar->showMessage("Ajout de client effectué! ");
}
*/
void MainWindow::on_actionA_propos_triggered()
{
    aproposDialog * Aproposdia=new aproposDialog();
    Aproposdia->show();
}

void MainWindow::on_rechercheButton_clicked()
{
    QString nom=ui->nomlineEdit->text();
    QString prenom=ui->prenomlineEdit->text();
    QDate datedebut=ui->datedebutEdit->date();
    QDate datefin=ui->datefinEdit->date();
    QString id=ui->idlineEdit->text();
    clientTableModel=modelclient->rechercheClient(nom,prenom,datedebut,datefin,id);
    ui->clientView->setModel(clientTableModel);
    ui->statusBar->showMessage("Resultat trouvé");
}

void MainWindow::on_supBtn_clicked()
{
    this->Compte++;
    int curRow = -1;
    curRow = ui->clientView->currentIndex().row();
    //int idClient = clientTableModel->index(curRow,0).data().toInt();
    QString nom = clientTableModel->index(curRow,1).data().toString();
    QString prenom = clientTableModel->index(curRow,2).data().toString();
    if(curRow != -1){
        int ok = QMessageBox::warning(NULL,QObject::tr("Supprimer!"),
                                      QObject::tr("Vous êtes sure de supprimer ce client?"),
                                      QMessageBox::Yes,QMessageBox::No);
        if(ok == QMessageBox::Yes)
        {
            clientTableModel->removeRow(curRow);
            /* supprimer dans TClient TRdv */
            GestionBDD::supprimerClient(nom, prenom);
            ui->statusBar->showMessage("Client supprimé");
        } else {
            //si on ne supprime pas
        }
        QString nom=ui->nomlineEdit->text();
        QString prenom=ui->prenomlineEdit->text();
        QDate datedebut=ui->datedebutEdit->date();
        QDate datefin=ui->datefinEdit->date();
        QString id=ui->idlineEdit->text();
        clientTableModel=modelclient->rechercheClient(nom,prenom,datedebut,datefin,id);
        ui->clientView->setModel(clientTableModel);

    }
}

void MainWindow::on_modBtn_clicked()
{
    /* modelclient->ModClient(ui->clientView);*/
    int curRow = -1;
    curRow = ui->clientView->currentIndex().row();
    int idClient=  clientTableModel->index(curRow,0).data().toInt();

    if(curRow != -1){
        ClientDialog * Clientdia=new ClientDialog(idClient);
        if(Clientdia->exec()==QDialog::Accepted){
            // clientTableModel->submitAll();
            delete clientTableModel;
            QString nom=ui->nomlineEdit->text();
            QString prenom=ui->prenomlineEdit->text();
            QDate datedebut=ui->datedebutEdit->date();
            QDate datefin=ui->datefinEdit->date();
            QString id=ui->idlineEdit->text();

            clientTableModel=modelclient->rechercheClient(nom,prenom,datedebut,datefin,id);
            ui->clientView->setModel(clientTableModel);
            ui->statusBar->showMessage("Client modifié");
        }
    }

}

void MainWindow::ValPreMas(QLineEdit *Qline){
    if(Qline->text()!=""){
        QString textall=Qline->text();
        textall=textall.toLower();
        textall[0]=textall[0].toUpper();
        Qline->setText(textall);
    }
}

void MainWindow::on_nomlineEdit_editingFinished()
{
    ValPreMas(ui->nomlineEdit);
}

void MainWindow::on_prenomlineEdit_editingFinished()
{
    ValPreMas(ui->prenomlineEdit);
}

void MainWindow::on_modifierBtn_clicked()
{
    QString curData = ui->PersonnelTreeView->currentIndex().data().toString();
    int curParentRow=ui->PersonnelTreeView->currentIndex().parent().row();
    QStandardItem *parent = resItemModel->item(curParentRow);
    if(parent!=NULL){
        /* rappel le dialog avec modification */
        PersonnelDialog *perdialog = new PersonnelDialog(curData);
        if( perdialog->exec()&&QDialog::Accepted){
            delete resItemModel;
            resItemModel=modelressource->creationResModel();
            ui->PersonnelTreeView->setModel(resItemModel);
            ui->statusBar->showMessage("Ressource modifié");
        }
    }
}

void MainWindow::on_suppBtn_clicked()
{
    this->Compte++;
    int curParentRow=ui->PersonnelTreeView->currentIndex().parent().row();
    QStandardItem *parent = resItemModel->item(curParentRow);

    int curRow = ui->PersonnelTreeView->currentIndex().row();
    QString curData = ui->PersonnelTreeView->currentIndex().data().toString();

    if(parent!=NULL){
        int ok = QMessageBox::warning(NULL,QObject::tr("Supprimer!"),
                                      QObject::tr("Vous êtes sure de supprimer cette personne?"),
                                      QMessageBox::Yes,QMessageBox::No);
        if(ok == QMessageBox::Yes)
        {
            resItemModel->item(curParentRow)->removeRow(curRow);
            /* supprimer le personnel dans TRessource TCompte TRdv */
            GestionBDD::supprimerPersonne(curData);
            //qDebug()<<curData;
            ui->statusBar->showMessage("Ressource supprimé");
        } else {
            /* sinon à faire */
        }
    }
}

bool ordreDecroissant(Client &c1, Client &c2)
{
    int s1 = c1.getPriorite()*100 + c1.getRessource()->size()*10 + c1.getDureeRDV();
    int s2 = c2.getPriorite()*100 + c2.getRessource()->size()*10 + c2.getDureeRDV();
    return s1 > s2;
}

void MainWindow::on_PlanifierButton_clicked()
{
    QVector <Client> vectClient;
    QMap <int, QVector <Client> > mpPlan;


    QVector <Client>::iterator it_vectClient;
    QVector <int>::iterator it_ressource;

    /* construire un vecteur pour stocker les clients */
    GestionBDD::vectorClient(ui->planDateEdit->date(), &vectClient);
    /*  traiter ces clients par ordre décroissant de cette liste */
    qSort(vectClient.begin(), vectClient.end(), ordreDecroissant);

    for(it_vectClient=vectClient.begin();it_vectClient!=vectClient.end();it_vectClient++){
        //qDebug() << (*it_vectClient).getNom()<<"  "<< (*it_vectClient).getPrenom();
        //qDebug() <<(*it_vectClient).getRessource()->size()<<" "<<(*it_vectClient).getPriorite()<<" "<<(*it_vectClient).getDureeRDV();
        /* pour chaque client */
        int dureeTotal=(*it_vectClient).getDureeRDV();
        int nbrRessource=(*it_vectClient).getRessource()->size();
        if(nbrRessource==0){
            qDebug()<<"on_PlanifierButton_clicked() nbrRessource est 0";
        }else{
            /* Return the ceiling of the value */
            int dureeParRessource = qCeil(dureeTotal/nbrRessource);
            int nbrExamenParRessource = qCeil(dureeParRessource/15.0);
            Client client=*it_vectClient;
            /* parcourir les ressources  */
            int position = 0;
            Client clientVide;
            for(it_ressource=(*it_vectClient).getRessource()->begin();it_ressource!=(*it_vectClient).getRessource()->end();it_ressource++){
                int idRessource=*it_ressource;
                if(position!=0){
                    /* ne pas le premiere fois planifier les examens sur les ressource,
                       on remplir le examen par un client vide */
                    for(int i=0;i < position;i++){
                        mpPlan[idRessource].append(clientVide);
                    }
                }
                for(int i=0;i<nbrExamenParRessource;i++){
                    position++;
                    mpPlan[idRessource].append(client);
                }
            }
        }
        /* Après click planifierButton, on peut utiliser enregistreButton*/
        ui->enregistrePB->setEnabled(true);
    }
    /* construire planning model */
    planTableModel=modelPlanning->creatpPlanModel(&mpPlan);
    ui->planificationView->setModel(planTableModel);
    ui->statusBar->showMessage("Nouvelle planification!");
}

void MainWindow::on_enregistrePB_clicked()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this,tr("Enregistrer Planning"), "", tr("Textes Files (*.txt)"));

    if (!fileName.isNull())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly  | QIODevice::Text | QIODevice::Append))
        {
            QMessageBox::warning(this,"","Fichier ouvrir échec!",QMessageBox::Yes);
        }
        QTextStream in(&file);
        int row=planTableModel->rowCount();
        int col=planTableModel->columnCount();
        /* affichage du temps du création du planning */
        QDateTime time = QDateTime::currentDateTime();
        in<<time.toString()<<"\n"<<"\n";
        /* le jour du planning */
        in<<"Planification de RDV du jour "<<ui->planDateEdit->date().toString()<<"\n"<<"\n";
        for(int i=0; i<row; i++){
            QModelIndex index;
            index= planTableModel->index(i,0);
            /* les informations sur ressource */
            QString str = planTableModel->data(index).toString();
            in<<" ** Ressource Type: "<<str<<"   ";
            index= planTableModel->index(i,1);
            str = planTableModel->data(index).toString();
            in<<"Nom : "<<str<<"   "<<" *** Client Nom:  ";
            /* les noms du client qui a le RDV */
            for(int j=2; j<col; j++){
                if(planTableModel->item(i,j)!=NULL){
                    QModelIndex index;
                    index= planTableModel->index(i,j);
                    QString str = planTableModel->data(index).toString();
                    in<<str<<"   ";
                    //qDebug()<<str;
                }
            }
            in<<"\n";
            in<<"\n";
        }
        file.close();
    }
}
