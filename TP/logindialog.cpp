#include "logindialog.h"
#include "ui_logindialog.h"
#include "gestionbdd.h"
#include <QMessageBox>


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->pwdlineEdit->setEchoMode(QLineEdit::Password);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginButton_clicked()
{
    if(GestionBDD::verifier_ident(ui->userlineEdit->text(),ui->pwdlineEdit->text())){
        accept();
    }
    else{
        QMessageBox msg;
        msg.setWindowTitle("Warning");
        msg.setText("Login ou Mot de passe incorrecte! ");
        msg.exec();
        ui->pwdlineEdit->clear();
    }
}
