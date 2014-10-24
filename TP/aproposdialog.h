#ifndef APROPOSDIALOG_H
#define APROPOSDIALOG_H

#include <QDialog>

namespace Ui {
class aproposDialog;
}

class aproposDialog : public QDialog
{
    Q_OBJECT

public:
    explicit aproposDialog(QWidget *parent = 0);
    ~aproposDialog();

private:
    Ui::aproposDialog *ui;
};

#endif // APROPOSDIALOG_H
