#ifndef GESTIONBDD_H
#define GESTIONBDD_H

#include "client.h"
#include <QString>
#include <QDate>

class GestionBDD
{
public:
    GestionBDD();
    static bool verifier_ident(QString ,QString );
    static void AjouterRessource(QString, QString, int);
    static void AjouterInformaticien(QString nom, QString prenom,
                                     QString login, QString mdp);
    /* ajouter les informations de client*/
    static void ajouteClient(QString nom,QString prenom,QString tel,QString adr,
                      QString ville,QString code,QString commentaire,QString divers,QString duree,
                      QString priorite,QStringList *elementsSelects,QString jour);
    static void supprimerPersonne(QString nom);
    static void supprimerClient(QString nom,QString prenom);
    /* construire un vector de client pour planifier */
    static void vectorClient(QDate date, QVector <Client> * vectClient);
    static QString ChercheNomRessouce(int id);
    static QString ChercheTypeRessouce(int id);
};

#endif // GESTIONBDD_H
