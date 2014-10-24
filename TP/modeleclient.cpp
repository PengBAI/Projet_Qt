#include "modeleclient.h"
#include <QDate>
#include <QMessageBox>
#include <QObject>

ModeleClient::ModeleClient()
{

}

ModeleClient::~ModeleClient(){
    delete model;
    delete modelres;
}

/* recherche des informations de client */
QSqlTableModel * ModeleClient::rechercheClient(QString nom,QString
                                               prenom,QDate datedebut,QDate datefin,QString id){
    QString cmd="1 ";
    model=new QSqlTableModel();
    model->setTable("TClient");
    if(nom!="")
        cmd.append(QObject::tr("and Nom like '%1'").arg(nom+"%"));
    if(prenom!="")
        cmd.append(QObject::tr("and Prenom like '%1'").arg(prenom+"%"));
    if(id!="")
        cmd.append(QObject::tr("and Id='%1'").arg(id));
    cmd.append(QObject::tr("and DateRdv>='%1' and DateRdv<='%2' order by DateRdv desc").
               arg(datedebut.toString("yyyy-MM-dd")).arg(datefin.toString("yyyy-MM-dd")));

    model->setFilter(cmd);
    model->select();
    /* modification du tableview */
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(3);
    model->removeColumn(4);
    model->removeColumn(4);
    model->setHeaderData(0, Qt::Horizontal,"Id");
    model->setHeaderData(1, Qt::Horizontal,"Nom");
    model->setHeaderData(2, Qt::Horizontal,"Prenom");
    model->setHeaderData(3, Qt::Horizontal,"DateRdv");
    return model;
}

/*Afficher les noms de ressource*/
QSqlTableModel * ModeleClient::rechercheRessource(){
    modelres=new QSqlTableModel();
    modelres->setTable("TRessource");
    modelres->select();
    modelres->removeColumn(0);
    modelres->removeColumn(1);
    modelres->removeColumn(1);
    return modelres;
}
