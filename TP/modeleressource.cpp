#include "modeleressource.h"
#include "gestionbdd.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <qDebug>
#include <QMessageBox>


ModeleRessource::ModeleRessource()
{

}

QStandardItemModel * ModeleRessource::creationResModel(){

    QStandardItemModel * ResTreeModel=new QStandardItemModel();
    ResTreeModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Type"));
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"Database n'est pas ouvert!";
    QSqlQuery query(mabdd);  // pour type
    QSqlQuery queryPer(mabdd);   // pour personnes

    /* type du ressource */
    QStandardItem *itemsType;
    query.prepare("select Label from TType");
    query.exec();
    int i=0;
    while(query.next()){
        i++;
        itemsType= new QStandardItem(query.value(0).toString());
        ResTreeModel->appendRow(itemsType);

        /* les personnes dans chaque type */
        queryPer.prepare("select Nom from TRessource where IdType=:idtype");
        queryPer.bindValue(":idtype",i);
        queryPer.exec();

        while(queryPer.next()){
            QStandardItem *itemsPersonnel = new QStandardItem(queryPer.value(0).toString());
            itemsType->appendRow(itemsPersonnel);
        }
    }
    return ResTreeModel;
}

