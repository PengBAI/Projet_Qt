#ifndef MODELEPLANNING_H
#define MODELEPLANNING_H

#include "client.h"
#include <QStandardItemModel>

class ModelePlanning
{
public:
    ModelePlanning();
    ~ModelePlanning();
    QStandardItemModel * creatpPlanModel(QMap <int, QVector <Client> > *mpPlan);
};

#endif // MODELEPLANNING_H
