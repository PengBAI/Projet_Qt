#ifndef MODELERESSOURCE_H
#define MODELERESSOURCE_H
#include <QStandardItemModel>
#include <QTreeView>
#include <personneldialog.h>

class ModeleRessource
{
    public:
        ModeleRessource();
        QStandardItemModel * creationResModel();
};

#endif // MODELERESSOURCE_H
