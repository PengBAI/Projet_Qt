#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include "modeleclient.h"

namespace Ui {
class ClientDialog;
}

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDialog(QWidget *parent = 0);
    ~ClientDialog();
    ClientDialog(int idClient, QWidget *parent = 0);
    /* uniquement des chiffres pour simpliﬁer */
    void ValNumber(QLineEdit *);
    /* chaîne de caractères dont la première
     * lettre est en majuscule, le reste en minuscule */
    void ValPreMas(QLineEdit *);


private slots:

    void on_nomlineEdit_editingFinished();

    void on_prenomlineEdit_editingFinished();

    void on_villelineEdit_editingFinished();

    void on_ClientAjouterPB_clicked();

    void on_dureelineEdit_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::ClientDialog *ui;
    ModeleClient *modelclient;
};

#endif // CLIENTDIALOG_H
