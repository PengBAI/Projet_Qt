#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modeleclient.h"
#include "modeleressource.h"
#include "modeleplanning.h"
#include "client.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int getCompte(){
        return Compte;
    }

private slots:
    void on_actionQuitter_triggered();

    void on_actionClient_triggered();

    void on_actionPersonnel_triggered();

    void actionAv_triggered();

    void on_actionA_propos_triggered();

    void on_rechercheButton_clicked();

    void on_supBtn_clicked();

    void on_modBtn_clicked();

    void on_nomlineEdit_editingFinished();

    void on_prenomlineEdit_editingFinished();

    void on_modifierBtn_clicked();

    void on_suppBtn_clicked();

    void on_PlanifierButton_clicked();

    void on_enregistrePB_clicked();

    //void ajoute_client_message();


private:
    int Compte;

    Ui::MainWindow *ui;
    ModeleClient *modelclient;
    ModeleRessource *modelressource;
    ModelePlanning *modelPlanning;

    QStandardItemModel *resItemModel;
    QSqlTableModel *clientTableModel;
    QStandardItemModel *planTableModel;

    void ValPreMas(QLineEdit *Qline);

};

#endif // MAINWINDOW_H
