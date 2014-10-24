#include "modeleplanning.h"
#include "gestionbdd.h"

ModelePlanning::ModelePlanning()
{
}

ModelePlanning::~ModelePlanning(){

}

QStandardItemModel * ModelePlanning::creatpPlanModel(QMap <int, QVector <Client> > *mpPlan){
    QMap <int, QVector <Client> >::iterator it_mpPlan;
    QVector <Client>::iterator it_mpClient;
    QStandardItemModel * planModel=new QStandardItemModel();
    planModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Type Ress.")<<QStringLiteral("Nom Ress.")
                                         <<QStringLiteral("8h00")<<QStringLiteral("8h15")<<QStringLiteral("8h30")
                                         <<QStringLiteral("8h45")<<QStringLiteral("9h00")<<QStringLiteral("9h15")
                                         <<QStringLiteral("9h30")<<QStringLiteral("9h45")<<QStringLiteral("10h00")
                                         <<QStringLiteral("10h15")<<QStringLiteral("10h30")<<QStringLiteral("10h45")
                                         <<QStringLiteral("11h00"));
    int row=0;
    for(it_mpPlan=mpPlan->begin();it_mpPlan!=mpPlan->end();it_mpPlan++){
        int idRessource = it_mpPlan.key();
        QStandardItem *nomRessource=new QStandardItem(GestionBDD::ChercheNomRessouce(idRessource));
        QStandardItem *typeRessource=new QStandardItem(GestionBDD::ChercheTypeRessouce(idRessource));
        //qDebug()<<it_mpPlan.key();
        /* inserer les informations sur ressouce */
        planModel->setItem(row,0,typeRessource);
        planModel->setItem(row,1,nomRessource);
        int col=1;
        for(it_mpClient=(*it_mpPlan).begin();it_mpClient!=(*it_mpPlan).end();it_mpClient++){
            col++;
            /* inserer les clients */
            QStandardItem *nomClient=new QStandardItem(it_mpClient->getNom());
            planModel->setItem(row,col,nomClient);
            //qDebug()<<it_mpClient->getNom();
        }
        row++;
    }
    return planModel;
}
