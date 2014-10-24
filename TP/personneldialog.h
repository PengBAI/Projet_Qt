#ifndef PERSONNELDIALOG_H
#define PERSONNELDIALOG_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class PersonnelDialog;
}

class PersonnelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonnelDialog(QWidget *parent = 0);

    ~PersonnelDialog();
    /* pour modifier */
    PersonnelDialog(int personnelId,QWidget *parent = 0);
    PersonnelDialog(QString nom,QWidget *parent = 0);
    /* le premier lettre est majuscule */
    void ValPreMas(QLineEdit *);

private slots:
    void on_PerComboBox_currentIndexChanged(int index);

    void on_PerAjouterPB_clicked();

    void on_nomlineEdit_editingFinished();

    void on_prenomlineEdit_editingFinished();

private:
    Ui::PersonnelDialog *ui;
};

#endif // PERSONNELDIALOG_H
