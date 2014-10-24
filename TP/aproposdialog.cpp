#include "aproposdialog.h"
#include "ui_aproposdialog.h"

aproposDialog::aproposDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aproposDialog)
{
    ui->setupUi(this);
}

aproposDialog::~aproposDialog()
{
    delete ui;
}
