#ifndef MODELECLIENT_H
#define MODELECLIENT_H

#include <QSqlTableModel>
#include <QTableView>

class ModeleClient
{
    private:
       QSqlTableModel * model;
       QSqlTableModel * modelres;

    public:
        ModeleClient();
        ~ModeleClient();
        /* recherche des informations de client */
        QSqlTableModel *rechercheClient(QString nom,QString
                                        prenom,QDate datedebut,QDate datefin,QString id);
        /* recherche les ressources */
        QSqlTableModel *rechercheRessource();
};

#endif // MODELECLIENT_H
