#include "gestionbdd.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

GestionBDD::GestionBDD()
{

}

/* pour Login verifier identifiant */
bool GestionBDD::verifier_ident(QString ident,QString pwd)
{
    /*  */
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"AjouterRessource() Database n'est pas ouvert!";
    QSqlQuery query(mabdd);

    query.prepare("select count(*) from TCompte where Login=:login and MdP=:pwd");
    query.bindValue(":login",ident);
    query.bindValue(":pwd",pwd);
    query.exec();
    if(query.next() && query.value(0)==1){
        // il existe un seul utilisateur
        return true;
    }else{
        return false;
    }

}

/* Ajouter le Ressource */
void GestionBDD::AjouterRessource(QString nom, QString prenom, int idtype)
{
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"AjouterRessource() Database n'est pas ouvert!";
    QSqlQuery query(mabdd);

    query.prepare("INSERT INTO TRessource(Nom, Prenom, IdType) "
                  "VALUES (:nom, :prenom, :idType)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":idType",idtype + 1); // comboBox Index commence par 0
    if(query.exec()==false){
        qDebug()<<"ajouter Ressources échoué!";
    }
}

void GestionBDD::AjouterInformaticien(QString nom, QString prenom,
                                      QString login, QString mdp)
{
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"AjouterInformaticien() Database n'est pas ouvert!";
    QSqlQuery query(mabdd);

    /* insert into TRessource */
    query.prepare("INSERT INTO TRessource(Nom, Prenom, IdType) "
                  "VALUES (:nom, :prenom, :idType)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":idType",7);
    if(query.exec()==false){
        qDebug()<<"ajouter Informaticien TRessource échoué!";
    }

    /* obtenir le IdRessource */
    query.prepare("SELECT Id FROM TRessource WHERE Nom = :nom AND Prenom = :prenom");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    if(query.exec()==false){
        qDebug()<<"obtenir Informaticien id échoué!";
    }
    query.next();
    int idRessouce=query.value(0).toInt();

    /* insert into TCompte */
    query.prepare("INSERT INTO TCompte(IdRessource, Login, MdP) "
                  "VALUES (:idRessource, :login, :mdp)");
    query.bindValue(":idRessource", idRessouce);
    query.bindValue(":login",login);
    query.bindValue(":mdp",mdp);
    if(query.exec()==false){
        qDebug()<<"ajouter Informaticien TRessource échoué!";
    }

}


/* ajouter clients */
void GestionBDD::ajouteClient(QString nom,QString prenom,QString tel,QString adr,
                              QString ville,QString code,QString commentaire,QString divers,QString duree,
                              QString priorite,QStringList * elementsSelects,QString jour){
    /*ajouter des informations de client*/
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"ajouteClient() Database n'est pas ouvert!";
    QSqlQuery query(mabdd);
    QString comment_divers=commentaire+divers;
    query.prepare("INSERT INTO TClient(Nom, Prenom, Adresse,Ville,CP,Commentaire,Tel,DateRdv,DureeRdv,Priorite) "
                  "VALUES (:nom, :prenom, :adr, :ville, :cp, :commentaire, :tel, :daterdv, :dureerdv, :priorite)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adr",adr);
    query.bindValue(":ville",ville);
    query.bindValue(":cp",code);
    query.bindValue(":commentaire",comment_divers);
    query.bindValue(":tel",tel);
    query.bindValue(":daterdv",jour);
    query.bindValue(":dureerdv",duree);
    query.bindValue(":priorite",priorite);
    if(query.exec()==false){
        qDebug()<<"ajouter Client échoué!";
    }

    /* obtenir le IdClient */
    query.prepare("SELECT Id FROM TClient WHERE Nom = :nom AND Prenom = :prenom");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    if(query.exec()==false){
        qDebug()<<"obtenir client id échoué!";
    }
    query.next();
    int idClient=query.value(0).toInt();

    /*obtenir le IdRessource et ajouter dans TRdv */
    QList<QString>::Iterator it;
    for(it=elementsSelects->begin();it!=elementsSelects->end();it++){
        query.prepare("SELECT Id FROM TRessource WHERE Nom = :nom");
        query.bindValue(":nom",*it);
        if(query.exec()==false){
            qDebug()<<"obtenir ressource id échoué!";
        }
        query.next();
        int idRessource=query.value(0).toInt();
        //qDebug()<<idRessource<<*it<<idClient;

        query.prepare("INSERT INTO TRdv(IdClient,IdRessource) "
                      "VALUES (:idClient, :idRessource)");
        query.bindValue(":idRessource", idRessource);
        query.bindValue(":idClient",idClient);
        if(query.exec()==false){
            qDebug()<<"ajouter Rdv échoué!";
        }
    }
}

void GestionBDD::supprimerPersonne(QString nom){
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"supprimerPersonne() Database n'est pas ouvert!";
    QSqlQuery query(mabdd);  // pour type

    /* supprimer compte d'informatien */
    query.prepare("delete from TCompte where IdRessource = (select Id from TRessource where Nom=:nom)");
    query.bindValue(":nom",nom);
    query.exec();
    /* supprimer le RDV du ce ressource */
    query.prepare("delete from TRdv where IdRessource=(select Id from TRessource where Nom=:nom)");
    query.bindValue(":nom",nom);
    query.exec();
    /* supprimer la personne */
    query.prepare("delete from TRessource where Nom=:nom");
    query.bindValue(":nom",nom);
    query.exec();

}

void GestionBDD::supprimerClient(QString nom, QString prenom){
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"supprimerClient() Database n'est pas ouvert!";
    QSqlQuery query(mabdd);  // pour type
    /* supprimer RDV du client */
    query.prepare("delete from TRdv where IdClient=(select Id from TClient where Nom=:nom and Prenom=:prenom)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.exec();
    /* supprimer client */
    query.prepare("delete from TClient where Nom=:nom and Prenom=:prenom");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.exec();
}

void GestionBDD::vectorClient(QDate date, QVector <Client> * vectClient){
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"vectorClient() Database n'est pas ouvert!";
    QSqlQuery query(mabdd); // pour client
    /* rechercher les clients */
    query.prepare("select Id, Nom, Prenom, Adresse, Ville, CP, Commentaire, Tel, DureeRDV, Priorite from TClient where DateRDV=:dateRDV");
    query.bindValue(":dateRDV",date.toString("yyyy-MM-dd"));
    query.exec();
    while (query.next()) {
        Client client;
        int idClient;
        idClient = query.value(0).toInt();
        client.setNom(query.value(1).toString());
        client.setPrenom(query.value(2).toString());
        client.setAdresse(query.value(3).toString());
        client.setVille(query.value(4).toString());
        client.setCP(query.value(5).toInt());
        client.setCommentaire(query.value(6).toString());
        client.setTel(query.value(7).toInt());
        client.setDureeRDV(query.value(8).toInt());
        client.setPriorite(query.value(9).toInt());
        /* pour ressource du RDV */
        QSqlQuery queryRes(mabdd);
        queryRes.prepare("select IdRessource from TRdv where IdClient = :idClient order by IdRessource ASC");
        queryRes.bindValue(":idClient",idClient);
        queryRes.exec();
        while(queryRes.next()){
            client.setRessource(queryRes.value(0).toInt());
            //qDebug()<<queryRes.value(0).toInt();
        }
        vectClient->append(client);
    }
}

QString GestionBDD::ChercheNomRessouce(int id){
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"ChercheNomRessouce() Database n'est pas ouvert!";
    QSqlQuery query(mabdd); // pour client
    query.prepare("select Nom from TRessource where Id=:id");
    query.bindValue(":id",id);
    query.exec();
    query.next();
    return query.value(0).toString();
}

QString GestionBDD::ChercheTypeRessouce(int id){
    QSqlDatabase mabdd=QSqlDatabase::database();
    if(!mabdd.isOpen())
        qDebug()<<"ChercheTypeRessouce() Database n'est pas ouvert!";
    QSqlQuery query(mabdd); // pour client
    query.prepare("select Label from TType where Id=(select IdType from TRessource where Id=:id)");
    query.bindValue(":id",id);
    query.exec();
    query.next();
    return query.value(0).toString();
}
